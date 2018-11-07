
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
	void setName(std::string fullname, std::string nickname);
private:
	int h;
	char **patterns;
	std::string lang;
	char ***responses;
	char *responseResult;
	int patternOffset = 0;
	int *responseOffsetD2;
	std::string fullname;
	std::string nickname;

	void zeroFill();
	void buildResponses();
	bool iRange(int, int);
	std::string getDay(int);
	std::string phpDate(const char*, int);
	void setPattern(const char*);
	void setResponse(int, const char*);
};

#endif