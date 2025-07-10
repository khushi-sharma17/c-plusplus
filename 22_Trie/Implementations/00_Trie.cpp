#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// Trie uses space in a more utilized way than hashmaps
class TrieNode {
public :
    char data;
    TrieNode* children[26];
    bool isTerminal;        // A boolean flag that indicates whether this node represents the end of a valid word.

    TrieNode(char ch) {
        data = ch;
        for (int i=0 ; i<26 ; i++) {
            children[i] = NULL;
        }
        isTerminal = false;
    }
}; 




class Trie {
public :

    TrieNode* root;

    Trie() {
        root = new TrieNode('\0');
    }


    void insertUtil(TrieNode* root, string word) {
        // base case
        if (word.length() == 0) {
            root -> isTerminal = true;
            return;
        }

        // Assumption, word will be in small letters
        int index = word[0] - 'a';

        TrieNode* child;

        // Word Present case
        if (root -> children[index] != NULL) {
            child = root -> children[index];
        }
        // absent case
        else {
            child = new TrieNode(word[0]);
            root -> children[index] = child;
        }

        // Recursion
        insertUtil(child, word.substr(1));
    }


    void insertWord(string word) {
        insertUtil(root, word);
    }






    bool searchUtil(TrieNode* root, string word) {
        // base case
        if (word.length() == 0) {
            return root -> isTerminal;
        }

        int index = word[0] - 'a';

        TrieNode* child;

        if (root -> children[index] != NULL) {
            child = root -> children[index];
        } else {
            return false;
        }

        // Recursion
        return searchUtil(child, word.substr(1));
    }


    bool searchWord(string word) {
        return searchUtil(root, word);
    }





    bool removeUtil(TrieNode* root, string word) {
        // base case
        if (word.length() == 0) {
            root -> isTerminal = false;

            // if no children, delete this node
            for (int i=0; i<26 ; i++) {
                if (root -> children[i] != NULL) {
                    return false;       // cannot delete, some child exists
                }
            }
            return true;        // no child and not terminal, safe to delete
        }

        int index = word[0] - 'a';

        TrieNode* child = root -> children[index];

        if (child == NULL) return false;    // word doesn't exist in the trie, nothing to remove


        bool shouldDeleteChild = removeUtil(child, word.substr(1));


        if (shouldDeleteChild) {
            delete child;
            root -> children[index] = NULL;

            // If this node still marks the end of another word, we cannot delete it.
            if (root -> isTerminal) return false;

            for (int i=0 ; i<26; i++) {
                if (root -> children[i] != NULL) {
                    return false;
                }
            }

            // If no child is remaining and it's not terminal → current node is also deletable
            return true; 
        }

        return false;       // We didn’t delete the child or ourselves → some part of the Trie still depends on us.
    }

 
    // remove word logic
    bool removeWord(string word) {
        return removeUtil(root, word);
    }




    bool prefixUtil(TrieNode* root, string word) {
        // base case
        if (word.length() == 0) {
            return true;
        }

        int index = word[0] - 'a';

        TrieNode* child;

        if (root -> children[index] != NULL) {
            child = root -> children[index];
        } else {
            return false;
        }

        // Recursion
        return prefixUtil(child, word.substr(1));
    }


    bool isPrefix(string word) {
        return prefixUtil(root, word);
    }
};





int main() {

    Trie *t = new Trie();
    t -> insertWord("abcd");
    t -> insertWord("tim");
    t -> insertWord("arm");

    cout << "Present or not : " << t -> searchWord("abcd") << endl;

    return 0;
}