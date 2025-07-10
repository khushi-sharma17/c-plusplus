#include <iostream>
#include <bits/stdc++.h>
using namespace std;


class TrieNode {
public :
    char data;
    TrieNode* children[26];
    int childCount;
    bool isTerminal;

    TrieNode(char ch) {
        data = ch;

        for (int i=0 ; i<26 ; i++) {
            children[i] = NULL;
        }

        childCount = 0;
        isTerminal = false;
    }
}; 



class Trie {
public :

    TrieNode* root;

    Trie(char ch) {
        root = new TrieNode(ch);
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
            root -> childCount++;
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






string longestCommonPrefix(vector<string> arr) {

    int n = arr[0].length();

    string ans = "";
    
    // for traversing all characters of first string
    for (int i=0 ; i < n ; i++) {
        char ch = arr[0][i];

        bool match = true;

        // for comparing character with rest of the string
        for (int j=1; j < arr.size() ; j++) {

            // not match
            if (arr[j].size() <= i || ch != arr[j][i]) {
                match = false;
                break;
            }
        }

        if (!match) break;
        else ans.push_back(ch);
    }

    return ans;
}




// using trie
string longestCommonPrefixUsingTrie(vector<string> arr) {

    Trie* t = new Trie('\0');

    int n = arr.size();

    // insert all the string into trie
    for (int i=0 ; i<n ; i++) {
        t -> insertWord(arr[i]);
    }

    
    string first = arr[0];
    TrieNode* root = t -> root;
    string ans = "";



    for(int i=0 ; i<first.length() ; i++) {
        char ch = first[i];

        if (root -> childCount == 1) {
            ans.push_back(ch);
            int index = ch - 'a';
            root = root -> children[index];
        }

        else {
            break;
        }

        if (root -> isTerminal) break;

    }

    return ans;
}



int main() {


    Trie *t = new Trie('\0');

    vector<string> arr = {
        "abcde",
        "abced",
        "abc",
        "abcgty",
        "abcewsa"
    };

    string lcp = longestCommonPrefixUsingTrie(arr);
    cout << "The largest common prefix is : " << lcp << endl;

    return 0;
}