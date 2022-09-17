#include "../../head/clang_enhance.h"

vector<string> separate(string &str_parameter, char *identification) {
    char *tmp_char;
    vector<string> vec;

    if (str_parameter == "") {
        cout << "blank string" << "\n";
        exit(1);
    }

    const char *cs = str_parameter.c_str();
    int length = strlen(cs);

    char *str_char = new char[length];

    strcpy(str_char, cs);

    tmp_char = strtok(str_char, identification);

    while (tmp_char != NULL) {
        string s = string(tmp_char);

        vec.push_back(s);

        tmp_char = strtok(NULL, identification);
    }

    delete[] str_char;

    return vec;
}
