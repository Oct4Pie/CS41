#include <cstring>
#include <iostream>
using namespace std;

char* substr(char* str, int start, int end) {
    char* sub = (char*)calloc(128, sizeof(char));

    int index = 0;
    for (int i = start; i < end; i++) {
        sub[index++] = str[i];
    }
    return sub;
}

int count(char* str, char c) {
    int count = 0;
    for (int i = 0; i < strlen(str); i++) {
        if (str[i] == c)
            ++count;
    }
    return count;
}

char** split(char* str) {
    static char* splitted[64];
    int index = -1;
    int j = 0;
    int i = 0;
    for (i = 0; i < strlen(str); i++) {
        if (str[i] == ' ') {
            splitted[j] = substr(str, index + 1, i);
            index = i;
            ++j;
        }
    }
    splitted[j] = substr(str, index + 1, i);

    return splitted;
}

int main() {
    char sentence[128];
    cout << "please enter a sentence: ";
    cin.getline(sentence, 128);
    char** str_arr = split(sentence);
    double nums[10];
    for (int i = 0; i < count(sentence, ' ') + 1; i++) {
        if (atof(str_arr[i])) {
            cout << atof(str_arr[i]) * 2 << endl;
            continue;
        }
        cout << str_arr[i] << endl;
    }
    return 0;
}