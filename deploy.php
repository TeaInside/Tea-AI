<?php

$ch = curl_init("https://webhook.teainside.org/circleci/tea-ai.php");
curl_setopt_array($ch, 
	[
		CURLOPT_POST => true,
		CURLOPT_POSTFIELDS => "",
		CURLOPT_RETURNTRANSFER => true,
		CURLOPT_SSL_VERIFYPEER => false,
		CURLOPT_SSL_VERIFYHOST => false
	]
);
print curl_exec($ch);
curl_close($ch);
