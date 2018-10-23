
#ifndef __TEA_AI_H
#define __TEA_AI_H 1

#define R_SIZE 512

#include <cstdio>
#include <vector>
#include <thread>
#include <stdlib.h>
#include <iostream>
#include <phpcpp.h>
#include <string.h>

Php::Value tea_ai_chat(Php::Parameters &p);

class TeaAI
{
public: 
	TeaAI();
	~TeaAI();
	bool check(Php::Value);
	std::string getResponseResult();
private:

	char **patterns;
	char ***responses;
	int patternOffset = 0;
	int *responseOffsetD2;
	char *responseResult;

	void zeroFill();
	void buildResponses();
	void setPattern(const char*);
	void setResponse(int offset, const char *res);
};

#endif