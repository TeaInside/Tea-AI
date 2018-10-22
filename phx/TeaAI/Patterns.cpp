
#include <stdlib.h>
#include <string.h>
#include "../headers/TeaAI.h"

void TeaAI::setPattern(const char *pattern) {
	this->patterns[this->patternOffset] = (char*)malloc(strlen(pattern));
	strcpy(this->patterns[this->patternOffset++], pattern);
}

void TeaAI::buildPattern() {

	this->patterns = (char**)malloc(R_SIZE * sizeof(char*));

	this->setPattern("/malam/Usi");
	this->setResponse(0, "Selamat malam");
	this->setResponse(0, "Selamat malam pak");
	
	this->setPattern("/pagi/Usi");
	this->setResponse(1, "Selamat pagi");
}
