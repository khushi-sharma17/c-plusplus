#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main() {

    // creation
    unordered_map<string, int> map;

    // insertion
    // 1
    pair<string, int> p = make_pair("Khushi", 1);
    map.insert(p);

    // 2
    pair<string, int> p1("Mohit", 2);
    map.insert(p1);

    // 3
    map.insert({"Priyanshi", 8});

    // 4
    map["Gunnu"] = 10;




    // searching
    cout << map["Gunnu"] << endl;
    cout << map.at("Khushi") << endl;

    cout << map["Unknown"] << endl;     // gives 0, as in this case a new entry is created for the new value
    // cout << map.at("Unknown key") << endl;      // gives error



    // size
    cout << "The size is : " << map.size() << endl << endl;
    
    
    
    // to check the presence
    cout << "Value Present or not : " << map.count("bro") << endl << endl;       // for absent = 0, and for present = 1
    
    
    // erase 
    map.erase("Priyanshi");
    cout << "The size after erase is : " << map.size() << endl << endl;


    for (auto i : map) {
        cout << i.first << " -> " << i.second << endl;
    } cout << endl;



    // iterator
    unordered_map<string, int> :: iterator it = map.begin();

    while (it != map.end()) {
        cout << it -> first << " -> " << it -> second << endl;
        it++;
    }


    return 0;
}