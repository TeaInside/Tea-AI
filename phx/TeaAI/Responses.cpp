
#include "../headers/TeaAI.h"

void TeaAI::setPattern(const char* pat) {
	this->patterns[this->patternOffset] = (char*)malloc(strlen(pat) * sizeof(char*));
	strcpy(this->patterns[this->patternOffset++], pat);
}

void TeaAI::setResponse(int offset, const char *res) {
	if (this->responseOffsetD2[offset] == 0) {
		this->responses[offset] = (char**)malloc(256 * sizeof(char*));
	}
	this->responses[offset][this->responseOffsetD2[offset]] = (char*)malloc(strlen(res) * sizeof(char*));
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


	this->setPattern(
		"/(?:^|[\\t\\s\n])(se?la?ma?t)?([\\s\\n]*)(pa?gi?)(?:[\\t\\s\\n]|$)/Usi"
	);
	this->setResponse(0, "Selamat pagi!");
	this->setResponse(0, "Selamat pagi {name}, apa kabar?");
	this->setResponse(0, "Selamat pagi juga {cname}");


	this->setPattern(
		"/(?:^|[\\t\\s\n])(se?la?ma?t|met)?(?:[\\t\\s\\n]*)(ma?l(a|e)?m)(?:[\\t\\s\\n]|$)/Usi"
	);
	this->setResponse(1, "Selamat malam!");
	this->setResponse(1, "Selamat malam {cname}, apa kabar?");
	this->setResponse(1, "Selamat malam juga {cname}");
}
