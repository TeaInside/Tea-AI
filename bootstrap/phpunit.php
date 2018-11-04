<?php

require __DIR__."/../config/init.php";
date_default_timezone_set(DEFAULT_TIMEZONE);

define("cmd", "php -d \"extension=".__DIR__."/../teaai.so\" ".__DIR__."/../bin/TeaAI.php chat --stdin-input --stdout-output");

function _ex(string $stdin): string
{
	$stdin = escapeshellarg($stdin);	
	$cmd = shell_exec("echo {$stdin} | ".cmd);
	return is_string($cmd) ? trim($cmd) : "";
}
