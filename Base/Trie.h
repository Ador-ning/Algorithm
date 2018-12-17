//
// Created by ning on 2018/12/17.
//

#ifndef ALGORITHM_TRIE_H
#define ALGORITHM_TRIE_H

#include <string>
#include <vector>

#define SIZE 26 // 字符表大小

class TrieNode {
public:
	bool isWord;
	int node; // 子节点个数
	std::vector<TrieNode *> child;

	TrieNode() : isWord(false),node(0), child(SIZE, nullptr) {}
};

template<int Size>
class Trie {
public:
	Trie() { root = new TrieNode(); }

	void insert(std::string word) {
		int len = word.size();
		TrieNode *p = root;
		for (int i = 0; i < len; ++i) {
			if (p->child[word[i] - 'a'] == nullptr) {
				p->child[word[i] - 'a'] = new TrieNode();
				p->node++;
			}
			p = p->child[word[i] - 'a'];
		}
		p->isWord = true;
	}

	bool search(std::string word) {
		TrieNode *p = find(word);
		return p != nullptr && p->isWord;
	}

	TrieNode *find(std::string key) {
		int len = key.size();
		TrieNode *p = root;
		for (int i = 0; i < len && p != nullptr; ++i)
			p = p->child[key[i] - 'a'];
		return p;
	}

	bool startsWith(std::string prefix) {
		TrieNode *p = find(prefix);
		return p != nullptr;
	}

private:
	TrieNode *root; // 根节点
};

#endif //ALGORITHM_TRIE_H
