<?php

require __DIR__."/bootstrap/init.php";

$input = "selamat pagi";
$st = new TeaAI\TeaAI("chat");
$st->setInput($input);
printf("Input: %s\n", $input);
printf("\nResponse:\n");
var_dump($st->run());
