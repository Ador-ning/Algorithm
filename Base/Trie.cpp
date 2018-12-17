//
// Created by ning on 2018/12/17.
//
#include <iostream>
#include "Trie.h"

void test_trie() {
	Trie *t = new Trie();
	t->insert("apple");
	std::cout << t->search("apple") << " " << t->search("app")
	          << " " << t->startsWith("app");
	t->insert("app");
	std::cout << " " << t->search("app");
}