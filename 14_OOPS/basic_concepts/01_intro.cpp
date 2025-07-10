// Class - user defined datatype
// Object - entity
// --> states/properties
// --> behaviour
// --> instance of class , an example or case

#include <iostream>
// #include "00_Hero.cpp"
// Accessing the class from another file
using namespace std;


class Hero {
    // properties\ Data members
    private:
    // char name[100];
    int health;

    public:
    char level;

    void print() {
        cout << level << endl;
    }

    int getHealth() {           // Getter
        return health;
    }

    char getLevel() {            // Getter, to fetch values
        return level;
    }

    void setHealth(int h, char name) {     // Setter, you can also set conditions over here
        if(name == 'A') {
            health = h;
        }
    }

    void setLevel(char ch) {      // Setter
        level = ch;
    }
};


int main() {

    // Creation of object
    Hero Khushi;
    cout << "Size of Khushi is : " << sizeof(Khushi) << endl;

    // cout << "size of : " << sizeof(Khushi) << endl;
    // why is it showing 108 as the answer. // 105
    // --> bcoz of padding and greeding alignment  (HW)
    // Empty class size is always 1 byte

    // garbage value will be set to it as we have not set the value.
    cout << "Khushi's Health is : " << Khushi.getHealth() << endl;    

    char name = 'A';
    Khushi.setHealth(70, name);       // Using setter
    // Khushi.health = 70;
    // Khushi.level = 'A';   

    cout << "Khushi's Health is : " << Khushi.getHealth() << endl;          
    // cout << "Level is : " << Khushi.level << endl;

    return 0;
}

// Access Modifiers
// --> public
// --> private
// --> protected


// Getter and setter are used when some parameters are privately marked.
// By default, the acces modifier of the class is private and that of struct is public.