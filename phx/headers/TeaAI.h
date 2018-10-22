
#ifndef __TEA_AI_H
#define __TEA_AI_H 1

#define R_SIZE 512

#include <cstdio>
#include <vector>
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
	std::string getResponse();
private:
	int patternOffset = 0;
	int responseOffset = 0;
	int *responseOffset2;
	char **patterns;
	char ***responses;

	void zeroFill();
	void buildPattern();
	void buildResponses();
	void setPattern(const char*);
	void setResponse(int offset, const char *res);
};

#endif