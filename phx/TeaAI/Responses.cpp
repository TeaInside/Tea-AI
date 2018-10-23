
#include "../headers/TeaAI.h"

void TeaAI::setPattern(const char* pat) {
	this->patterns[this->patternOffset] = (char*)malloc(strlen(pat) * sizeof(char*));
	strcpy(this->patterns[this->patternOffset++], pat);
}

void TeaAI::setResponse(int offset, const char *res) {
	if (this->responseOffsetD2[offset] == 0) {
		this->responses[offset] = (char**)malloc(256 * sizeof(char*));
	}
	this->responses[offset][this->responseOffsetD2[offset]] = (char*)malloc(256 * sizeof(char*));
	strcpy(this->responses[offset][this->responseOffsetD2[offset]++], res);
}

void TeaAI::zeroFill() {
	for (int i = 0; i < R_SIZE; ++i) {
		this->responseOffsetD2[i] = 0;
	}
}

void TeaAI::buildResponses() {
	this->patterns = (char**)malloc(R_SIZE * sizeof(char*));
	this->responses = (char***)malloc(R_SIZE * sizeof(char*));
	this->responseOffsetD2 = (int*)malloc(R_SIZE * sizeof(int*));
	this->zeroFill();

	this->setPattern("/malam/Usi");
	this->setResponse(0, "Selamat malam");
	this->setResponse(0, "Selamat malam dunia");

	this->setPattern("/pagi/Usi");
	this->setResponse(1, "Selamat pagi");
	this->setResponse(1, "Selamat pagi dunia");
}
