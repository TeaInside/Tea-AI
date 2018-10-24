
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

bool TeaAI::iRange(int start, int end) {
	return this->h >= start && this->h <= end;
}

void TeaAI::buildResponses() {

	this->h = atoi(Php::call("date", "H"));
	this->patterns = (char**)malloc(R_SIZE * sizeof(char*));
	this->responses = (char***)malloc(R_SIZE * sizeof(char*));
	this->responseOffsetD2 = (int*)malloc(R_SIZE * sizeof(int*));
	this->zeroFill();

	this->setPattern(
		"/(?:^|[\\t\\s\n])(se?la?ma?t|met|mat)(?:[\\t\\s\\n]*)(pa?gi?)(?:[\\t\\s\\n]|$)/Usi"
	);
	if (this->iRange(0, 11)) {
		this->setResponse(0, "Selamat pagi!");
		this->setResponse(0, "Selamat pagi {name}, apa kabar?");
		this->setResponse(0, "Selamat pagi juga {cname}");
	} else if (this->iRange(12, 14)) {
		this->setResponse(0, "Ini sudah siang {cname}");
		this->setResponse(0, "Selamat siang, selamat beraktifitas!");
		this->setResponse(0, "Selamat siang!");
	} else if (this->iRange(15, 18)) {
		this->setResponse(0, "Ini sudah sudah sore {cname}");
		this->setResponse(0, "Selamat sore!");
		this->setResponse(0, "Sore {cname}");
	} else {
		this->setResponse(0, "Ini sudah sudah malam {cname}");
		this->setResponse(0, "Selamat malam, selamat beristirahat");
		this->setResponse(0, "Malam {cname}");
	}

	this->setPattern(
		"/(?:^|[\\t\\s\n])(se?la?ma?t|met|mat)(?:[\\t\\s\\n]*)(siang)(?:[\\t\\s\\n]|$)/Usi"
	);
	if (this->iRange(0, 10)) {
		this->setResponse(1, "Ini masih pagi {cname}");
		this->setResponse(1, "Selamat pagi!");
		this->setResponse(1, "Pagi {cname}");
	} else if (this->iRange(11, 14)) {
		this->setResponse(1, "Selamat siang!");
		this->setResponse(1, "Selamat siang {name}, apa kabar?");
		this->setResponse(1, "Selamat siang juga {cname}");
	} else if (this->iRange(15, 18)){
		this->setResponse(1, "Ini sudah sore {cname}");
		this->setResponse(1, "Selamat sore!");
		this->setResponse(1, "Sore {cname}");
	} else {
		this->setResponse(1, "Ini sudah malam {cname}");
		this->setResponse(1, "Selamat malam!");
		this->setResponse(1, "Malam {cname}");
	}

	this->setPattern(
		"/(?:^|[\\t\\s\n])(se?la?ma?t|met|mat)(?:[\\t\\s\\n]*)(sore)(?:[\\t\\s\\n]|$)/Usi"
	);
	if (this->iRange(0, 10)) {
		this->setResponse(2, "Ini masih pagi {cname}");
		this->setResponse(2, "Selamat pagi!");
		this->setResponse(2, "Pagi {cname}");
	} else if (this->iRange(11, 14)) {
		this->setResponse(2, "Ini masih siang {cname}");
		this->setResponse(2, "Selamat siang, selamat beraktifitas!");
		this->setResponse(2, "Selamat siang!");
	} else if (this->iRange(15, 18)){
		this->setResponse(2, "Selamat sore!");
		this->setResponse(2, "Selamat sore {name}, apa kabar?");
		this->setResponse(2, "Selamat sore juga {cname}");
	} else {
		this->setResponse(2, "Ini sudah malam {cname}");
		this->setResponse(2, "Selamat malam!");
		this->setResponse(2, "Malam {cname}");
	}

	this->setPattern(
		"/(?:^|[\\t\\s\n])(se?la?ma?t|met|mat)(?:[\\t\\s\\n]*)(ma?l(a|e)?m)(?:[\\t\\s\\n]|$)/Usi"
	);
	if (this->iRange(0, 10)) {
		this->setResponse(3, "Ini sudah pagi {cname}");
		this->setResponse(3, "Selamat pagi!");
		this->setResponse(3, "Pagi {cname}");
	} else if (this->iRange(11, 14)) {
		this->setResponse(3, "Ini masih siang {cname}");
		this->setResponse(3, "Selamat siang, selamat beraktifitas!");
		this->setResponse(3, "Selamat siang!");
	} else if (this->iRange(15, 18)){
		this->setResponse(3, "Ini masih sore {cname}");
		this->setResponse(3, "Selamat sore!");
		this->setResponse(3, "Sore {cname}");
	} else {
		this->setResponse(3, "Selamat malam!");
		this->setResponse(3, "Selamat malam {cname}, apa kabar?");
		this->setResponse(3, "Selamat malam juga {cname}");	
	}
}
