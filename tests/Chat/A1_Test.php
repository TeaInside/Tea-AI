<?php

namespace Tests\Chat;

use PHPUnit\Framework\TestCase;

require __DIR__."/../init.php";

class A1_Test extends TestCase
{
	/**
	 * @return void
	 */
	public function testFrameworkMatcher(): void
	{
		$strLs = [
			"Saya pakai laravel pak",
			"Laravel is the best",
			"Pakai laravel aja",
			"Pokoknya laravel"
		];

		foreach ($strLs as $str) {
			$this->frameworkAssert(_ex($str));
		}
	}


	/**
	 * @return void
	 */
	public function testTanyaHari(): void
	{
		$strLs = [
			"Sekarang hari apa?",
			"hari apa sekarang?",
			"Hai sayang, sekarang hari apa sih?",
			
			"skrng hari apa?",
			"hri apa skrng?",
			"skrng hri apaan seh?",
			"ini hri apaan?",
			"hri apaan skrng",
			"skrng hri apa"
		];

		foreach ($strLs as $str) {		
			$this->hariAssert(_ex($str));
		}
	}

	/**
	 * @return void
	 */
	public function testTanyaBulan(): void
	{
		$strLs = [
			"Sekarang bulan apa?",
			"Bulan apa sekarang?",
			"Hai sayang, sekarang bulan apa sih?",
			
			"skrng bulan apa?",
			"bln apa skrng?",
			"skrng bln apaan seh?",
			"ini bln apaan?",
			"bln apaan skrng",
			"skrng bl apa"
		];

		foreach ($strLs as $str) {		
			$this->bulanAssert(_ex($str));
		}
	}

	/**
	 * @return void
	 */
	private function frameworkAssert(string $res): void
	{
		$this->assertTrue(((bool)preg_match("/framework/Uusi", $res)));
	}

	/**
	 * @param string $res
	 */
	private function hariAssert(string $res): void
	{
		$this->assertTrue(((bool)preg_match("/Sekarang hari/Uusi", $res)));
	}

	/**
	 * @param string $res
	 */
	private function bulanAssert(string $res): void
	{
		$this->assertTrue(((bool)preg_match("/Sekarang bulan /Uusi", $res)));
	}
}
