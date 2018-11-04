<?php

$ch = curl_init("https://www.teainside.org/tea-ai-deploy.php");
curl_setopt_array($ch, 
	[
		CURLOPT_RETURNTRANSFER => true,
		CURLOPT_SSL_VERIFYPEER => false,
		CURLOPT_SSL_VERIFYHOST => false
	]
);
print curl_exec($ch);
curl_close($ch);
