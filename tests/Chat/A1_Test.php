<?php

namespace Tests\Chat;

use PHPUnit\Framework\TestCase;

require __DIR__."/../init.php";

class A1_Test extends TestCase
{
	/**
	 * @return void
	 */
	public function testTanyaBulan(): void
	{
		$strLs = [
			"Sekarang bulan apa?",
			"Bulan apa sekarang?",
			"Hai sayang, sekarang bulan apa sih?"
		];

		foreach ($strLs as $str) {			
			$this->bulanAssert(_ex($str));
		}
	}

	/**
	 * @param string $res
	 */
	private function bulanAssert(string $res): void
	{
		$this->assertTrue(((bool)preg_match("/Sekarang bulan /Uusi", $res)));
	}
}
