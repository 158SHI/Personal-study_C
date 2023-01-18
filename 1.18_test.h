#pragma once

#include <iostream>
#include <string>

using namespace std;

class BpSolution
{
public:

	int BF(string str, string sub);
};

class KmpSolution
{
public:

	int KMP(string str, string sub);
	void getNext(int*& next, string sub);
};