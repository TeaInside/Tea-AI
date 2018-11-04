<?php


$descriptorspec = [
   0 => ["pipe", "w"], // STDIN
   1 => ["file", "php://stdout", "w"], // STDOUT
   2 => ["file", "php://stderr", "w"]  // STDERR
];

$commands = [
	[
		(!file_exists("/tmp/phpcpp")),
		"wget https://api.github.com/repos/CopernicaMarketingSoftware/PHP-CPP/tarball/v2.1.2 -O /tmp/phpcpp"
	],
	[
		true,
		"cd /tmp && tar -xf phpcpp && cd *PHP* && make -j 5 && sudo make install -j 5"
	],
	[
		true,
		"cd ~/repo && composer install -n --prefer-dist -vvv"
	],
];


foreach($commands as $command) {
	if ($command[0]) {
		$proc = proc_open($command[1], $descriptorspec, $pipes);
		fclose($pipes[0]);
		proc_close($proc);
	}
}
