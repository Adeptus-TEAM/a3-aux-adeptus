<?php
declare(strict_types=1);
require __DIR__ . '/../src/bootstrap.php';

startSession();
$_SESSION = [];
session_destroy();
header('Location: index.php');
exit;
