<?php

namespace Tests\Chat;

use PHPUnit\Framework\TestCase;

require __DIR__."/../init.php";

class A1_Test extends TestCase
{
	/**
	 * @return void
	 */
	public function testSambutan(): void
	{
		$h = (int)date("H");
		$r = _ex("Selamat pagi");
		
		if (in_array($h, range(0, 11))) {
			$this->assertTrue(
				in_array($r, 
					[
						"Selamat pagi!",
						"Selamat pagi User, apa kabar?",
						"Selamat pagi juga "
					]
				)
			);
			return;
		} else if (in_array($h, range(12, 14))) {
			$this->assertTrue(
				in_array($r, 
					[
						"Ini sudah siang User",
						"Selamat siang, selamat beraktifitas!",
						"Selamat siang!"
					]
				)
			);
		} else if (in_array($h, range(15, 18))) {
			$this->assertTrue(
				in_array($r,
					[
						"Ini sudah sore User",
						"Selamat sore!",
						"Sore User"
					]
				)
			);
		} else {
			$this->assertTrue(
				in_array($r, 
					[
						"Ini sudah malam User",
						"Selamat malam, selamat beristirahat",
						"Malam User"
					]
				)
			);
		}
	}
}
