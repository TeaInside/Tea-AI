<?php

if (!file_exists("/tmp/phpcpp")) {
	$commands = [
		"wget https://api.github.com/repos/CopernicaMarketingSoftware/PHP-CPP/tarball/v2.1.2 -O /tmp/phpcpp",
		"cd /tmp && tar -xf phpcpp && cd *PHP* && make -j 5 && sudo make install -j 5",
		"cd ~/repo && composer install -n --prefer-dist -vvv"
	];
	$proc = proc_open($cmd, $desc, $pipes);
	
}
