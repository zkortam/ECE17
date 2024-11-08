#include "strings.h"
using namespace std;

string replaceSubstring(string string1, string string2, string string3) {

    if (string2.empty()) {
        return string1;
    }

    size_t pos = 0;
    while ((pos = string1.find(string2, pos)) != string::npos) {
        string1.replace(pos, string2.length(), string3);
        pos += string3.length();
    }
    return string1;
}
