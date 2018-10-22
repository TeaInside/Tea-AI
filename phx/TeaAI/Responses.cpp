
#include <stdlib.h>
#include <string.h>
#include "../headers/TeaAI.h"

void TeaAI::setResponse(int offset, const char *res) {
	this->responses[offset] = (char**)malloc(64 * sizeof(char*));
	this->responses[offset][this->responseOffset2[offset]] = (char*)malloc(strlen(res) * sizeof(char*));
	strcpy(this->responses[offset][this->responseOffset2[offset]++], res);
}

void TeaAI::zeroFill() {
	for (int i = 0; i < R_SIZE; ++i){
		this->responseOffset2[i] = 0;
	}
}

void TeaAI::buildResponses() {
	this->responseOffset2 = (int*)malloc(R_SIZE * sizeof(int*));
	this->responses = (char***)malloc(R_SIZE * sizeof(char*));
	this->zeroFill();
}
