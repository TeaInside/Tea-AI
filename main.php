<?php

require __DIR__."/bootstrap/init.php";

$input = "J4m b3r4p4 s3k4r4ng ?";
$st = new TeaAI\TeaAI("chat");
$st->setInput($input);
printf("Input: %s\n", $input);
printf("\nResponse: \n%s\n", $st->run());
