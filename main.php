<?php

require __DIR__."/bootstrap/init.php";

$in = "";

$st = new TeaAI\TeaAI("chat");
$st->setInput($in);

$input = "bsk hari ap";
printf("Input: %s\n", $input);
printf("\nResponse: \n%s\n", $st->run());
