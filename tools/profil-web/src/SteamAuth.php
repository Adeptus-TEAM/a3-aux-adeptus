<?php
/**
 * Connexion "Se connecter avec Steam" (OpenID 2.0).
 * Ne demande pas de clé API Steam : on récupère seulement le SteamID64 du joueur,
 * après avoir fait vérifier la réponse par Steam lui-même.
 */

declare(strict_types=1);

final class SteamAuth
{
    private const ENDPOINT = 'https://steamcommunity.com/openid/login';

    /** URL vers laquelle rediriger le joueur pour qu'il se connecte sur Steam. */
    public static function loginUrl(string $returnTo): string
    {
        $parts = parse_url($returnTo);
        $realm = $parts['scheme'] . '://' . $parts['host'] . (isset($parts['port']) ? ':' . $parts['port'] : '');

        return self::ENDPOINT . '?' . http_build_query([
            'openid.ns'         => 'http://specs.openid.net/auth/2.0',
            'openid.mode'       => 'checkid_setup',
            'openid.return_to'  => $returnTo,
            'openid.realm'      => $realm,
            'openid.identity'   => 'http://specs.openid.net/auth/2.0/identifier_select',
            'openid.claimed_id' => 'http://specs.openid.net/auth/2.0/identifier_select',
        ]);
    }

    /**
     * Vérifie le retour de Steam et renvoie le SteamID64, ou null si la connexion est invalide.
     *
     * @param array<string, string> $query $_GET (PHP remplace les "." des clés par des "_")
     */
    public static function validate(array $query, string $expectedReturnTo): ?string
    {
        if (($query['openid_mode'] ?? '') !== 'id_res') {
            return null;
        }
        // La réponse doit être destinée à notre page, et venir de Steam
        if (($query['openid_return_to'] ?? '') !== $expectedReturnTo
            || ($query['openid_op_endpoint'] ?? '') !== self::ENDPOINT) {
            return null;
        }
        if (!preg_match('#^https://steamcommunity\.com/openid/id/(\d{17})$#', $query['openid_claimed_id'] ?? '', $m)) {
            return null;
        }

        // On renvoie tous les champs signés à Steam pour qu'il confirme la signature
        $params = ['openid.mode' => 'check_authentication'];
        foreach (explode(',', $query['openid_signed'] ?? '') as $field) {
            $key = 'openid_' . str_replace('.', '_', $field);
            if (!isset($query[$key])) {
                return null;
            }
            $params['openid.' . $field] = $query[$key];
        }
        $params['openid.assoc_handle'] = $query['openid_assoc_handle'] ?? '';
        $params['openid.signed'] = $query['openid_signed'] ?? '';
        $params['openid.sig'] = $query['openid_sig'] ?? '';
        $params['openid.ns'] = 'http://specs.openid.net/auth/2.0';

        $response = Http::post(self::ENDPOINT, http_build_query($params));
        if ($response === null || !preg_match('/^is_valid\s*:\s*true$/m', $response)) {
            return null;
        }

        return $m[1];
    }
}

/** Petites requêtes HTTP sans dépendance (cURL si disponible, sinon flux PHP). */
final class Http
{
    public static function post(string $url, string $body): ?string
    {
        $res = self::request('POST', $url, $body, ['Content-Type: application/x-www-form-urlencoded']);
        return $res['body'] ?? null;
    }

    /**
     * @param string[] $headers
     * @return array{status:int, body:string}|null
     */
    private static function request(string $method, string $url, ?string $body, array $headers): ?array
    {
        if (function_exists('curl_init')) {
            $ch = curl_init($url);
            curl_setopt_array($ch, [
                CURLOPT_RETURNTRANSFER => true,
                CURLOPT_TIMEOUT        => 8,
                CURLOPT_HTTPHEADER     => $headers,
                CURLOPT_CUSTOMREQUEST  => $method,
            ]);
            if ($body !== null) {
                curl_setopt($ch, CURLOPT_POSTFIELDS, $body);
            }
            $out = curl_exec($ch);
            $status = (int) curl_getinfo($ch, CURLINFO_RESPONSE_CODE);
            return $out === false ? null : ['status' => $status, 'body' => (string) $out];
        }

        $ctx = stream_context_create(['http' => [
            'method'        => $method,
            'header'        => implode("\r\n", $headers),
            'content'       => $body ?? '',
            'timeout'       => 8,
            'ignore_errors' => true,
        ]]);
        $out = @file_get_contents($url, false, $ctx);
        if ($out === false) {
            return null;
        }
        $status = 0;
        if (preg_match('#^HTTP/\S+\s+(\d{3})#', $http_response_header[0] ?? '', $m)) {
            $status = (int) $m[1];
        }
        return ['status' => $status, 'body' => $out];
    }
}
