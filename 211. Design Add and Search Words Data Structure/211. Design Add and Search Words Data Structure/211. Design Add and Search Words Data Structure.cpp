// 211. Design Add and Search Words Data Structure.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <queue>
using namespace std;

struct TrieNode {
public:
    char val;
    bool flag = false;
    unordered_map<char, TrieNode*> children;
    explicit TrieNode(const char _val) : val(_val), children(unordered_map<char, TrieNode*> {}) {}
    TrieNode(char _val, unordered_map<char, TrieNode*>& _children) : val(_val), children(_children) {}
};

class Trie {
public:
    Trie() {
        root_ = new TrieNode(' ');
    }

    void insert(const string& word) {
        auto root = root_;
        for (auto c : word) {
            if (root->children.count(c) == 0) {
                root->children.insert({ c, new TrieNode{c} });
            }
            root = root->children[c];
        }
        root->flag = true;
    }

    bool search(const string& word) {
        auto root = root_;
        for (char c : word) {
            if (root->children.count(c) == 0) {
                return false;
            }
            root = root->children[c];
        }
        return root->flag;
    }

    bool startsWith(const string& prefix) {
        auto root = root_;
        for (char c : prefix) {
            if (root->children.count(c) == 0) {
                return false;
            }
            root = root->children[c];
        }
        return true;
    }

    TrieNode* getRoot()
    {
        return root_;
    }

private:
    TrieNode* root_;
};


class WordDictionary {
public:
    WordDictionary() {
        trie = new Trie;
    }

    void addWord(string word) {
        trie->insert(word);
    }

    bool search(string word) {
        queue<TrieNode*> que;
        auto root = trie->getRoot();
        que.push(root);
        int len = word.size();
        int index = 0;
        bool flag = false;
        while (!que.empty() && index < len) {
            int sz = que.size();
            for (int i = 0; i < sz; i++) {
                auto& children = que.front()->children;
                que.pop();
                if (word[index] != '.') {
                    auto iter = children.find(word[index]);
                    if (iter != children.end()) {
                        if (index == len - 1 && iter->second->flag) {
                            flag = true;
                            break;
                        }
                        que.push(iter->second);
                        
                    }
                    else {
                        break;
                    }
                }
                else {
                    bool f = false;
                    for (auto& e : children) {
                        f = f || e.second->flag;
                        que.push(e.second);
                    }
                    if (index == len - 1 && f) {
                        flag = true;
                        break;
                    }
                }

            }
            index++;
            if (flag) {
                break;
            }
        }
        return flag;
    }
private:
    Trie* trie;
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */

int main()
{
    std::cout << "Hello World!\n";
    WordDictionary wd;
    wd.addWord("runner");
    wd.addWord("runs");
    cout << wd.search("....e.");
}

// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门使用技巧: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件
