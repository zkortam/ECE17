#include <iostream>
#include <string>
#include "strings.h"
using namespace std;

int main() {

    string str1 = "the cat looks silly in the hat";
    string str2 = "the"; 
    string str3 = "that"; 

    string new_string = replaceSubstring(str1, str2, str3);

    cout << new_string << endl; 

}
