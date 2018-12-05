//
// Created by ning on 2018/5/26.
//

#ifndef INTERVIEW_CPP_STRINGUTILS_H
#define INTERVIEW_CPP_STRINGUTILS_H

#include <stdio.h>
#include <iostream>

namespace Algorithm {
	void Reverse(char *pBegin, char *pEnd);

	void removeIgnore(std::string &s);

	void test_RemoveIgnore();

	char *ReverseSentence(char *pData);

	void Permutation(char *pStr, char *pBegin);

	void Permutation(char *pStr);

	std::string reverseWords(std::string &s);

	void Test(char *pStr);

	void test_main();
}


#endif //INTERVIEW_CPP_STRINGUTILS_H
