<?php

require __DIR__."/bootstrap/init.php";

$input = "kemarin tgl brp?";
$st = new TeaAI\TeaAI("chat");
$st->setInput($input);
printf("Input: %s\n", $input);
printf("\nResponse: \n%s\n", $st->run());
