#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>

using namespace std;

void ReplacePatternWithAsterisksRecursive(char* str, int i, bool& foundPattern) {
    
    if (str[i] == '\0' || str[i + 1] == '\0' || str[i - 1] == '\0') {
        return;
    }

   
    if (i > 0 && str[i + 1] != '\0' && str[i - 1] == 'n' && str[i + 1] == 'o' && isalpha(str[i])) {
        str[i - 1] = '*';
        str[i] = '*';

       
        int shiftIndex = i + 1;
        while (str[shiftIndex] != '\0') {
            str[shiftIndex - 1] = str[shiftIndex + 1];
            shiftIndex++;
        }

        foundPattern = true;

        
        ReplacePatternWithAsterisksRecursive(str, i + 1, foundPattern);
    }
    else {
        
        ReplacePatternWithAsterisksRecursive(str, i + 1, foundPattern);
    }
}

char* ReplacePatternWithAsterisks(char* str, bool& foundPattern) {
    foundPattern = false;

    
    ReplacePatternWithAsterisksRecursive(str, 1, foundPattern);

    return str;
}

int main() {
    char str[101];
    cout << "Enter string:" << endl;
    cin.getline(str, 100);

    bool foundPattern;
    ReplacePatternWithAsterisks(str, foundPattern);

    if (foundPattern) {
        cout << "letter between n and o: yes" << endl;
    }
    else {
        cout << "letter between n and o: no" << endl;
    }

    cout << "Modified string: " << str << endl;

    return 0;
}
