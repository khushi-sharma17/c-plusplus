#include <iostream>
#include <bits/stdc++.h>
using namespace std;


class TrieNode {
    public :
    char data;
    TrieNode* children[26];
    bool isTerminal;

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



    void printSuggestions(TrieNode* curr, vector<string> &temp, string prefix) {
        if (curr -> isTerminal) {
            temp.push_back(prefix);
        }

        for (char ch = 'a' ; ch <= 'z' ; ch++) {
            TrieNode* next = curr -> children[ch - 'a'];

            if (next != NULL) {
                prefix.push_back(ch);
                printSuggestions(next, temp, prefix);
                prefix.pop_back();
            }
        }
    }




    vector<vector<string>> getSuggestions(string str) {

        TrieNode* prev = root;
        vector<vector<string>> output;
        string prefix = "";

        for (int i=0 ; i<str.length() ; i++) {
            char lastCharacter = str[i];

            prefix.push_back(lastCharacter);

            // check for last character
            TrieNode* curr = prev -> children[lastCharacter - 'a'];

            // if not found
            if (!curr) {
                // If no match is found for current prefix
                while (i < str.length()) {
                    output.push_back({"0"});
                    i++;
                }
                
                break;
            } 

            vector<string> temp;
            printSuggestions(curr, temp, prefix);

            output.push_back(temp);
            temp.clear();
            prev = curr;
        }

        return output;
    }

};





vector<vector<string>> displayContacts(int n, string contact[], string s) {
    
    // creation of trie
    Trie *t = new Trie();

    // insert all contact in trie
    set<string> uniqueContacts(contact, contact + n);
    for (auto &str : uniqueContacts) {
        t->insertWord(str);
    }

    return t -> getSuggestions(s);
}



int main() {

    string queryStr;
    getline(cin, queryStr);

    string contacts[] = {"khushi", "khushisharma", "khu"};

    vector<vector<string>> output = displayContacts(3, contacts, queryStr);

    for (vector<string> i : output) {
        for (string j : i) {
            cout << j << " ";
        }
    }

    return 0;
}


// TC = O(n*m*m)
// SC = O(m*n)