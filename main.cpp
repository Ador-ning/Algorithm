#include <iostream>
#include <vector>
#include <string>
#include "Base.h"
#include "./Base/BinaryTree.h"

using namespace Algorithm;


void removeIgnore(std::string &s) {
	if (s.size() == 0)
		return;
	for (int i = 0; i < s.size();) {
		// upper to lower
		if (s[i] >= 'A' && s[i] <= 'Z') {
			s[i] -= 'A' - 'a';
			++i;
		} else if (s[i] >= 'a' && s[i] <= 'z') {
			++i;
			continue;
		} else {
			// remove
			s.erase(i, 1);
		}
	}
}

void test_RemoveIgnore() {
	std::string s("A man, a plan, a canal: Panama");
	std::string s1("race a car");
	removeIgnore(s);
	removeIgnore(s1);
	std::cout << s << std::endl;
	std::cout << s1 << std::endl;
}

int main(int argc, const char *argv[]) {
	std::cout << "main test: " << std::endl;

	Algorithm::test_stringTorTreeNode();
}