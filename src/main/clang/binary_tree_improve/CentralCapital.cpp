#include "../../head/clang_enhance.h"

vector<vector<std::string>>
conversion2vector(char *identification2, vector<vector<string>> vtr_dual, vector<string> vec_str) {
    vector<string> ve_tmp;
    for (auto iter = vec_str.cbegin(); iter != vec_str.cend(); ++iter) {
        ve_tmp.clear();
        string s = (*iter);

        ve_tmp = separate(s, identification2);
        vtr_dual.push_back(ve_tmp);
    }

    return vtr_dual;
}

void centralCapital() {
    biTrNode *tree;
    queue<biTrNode *> que;
    string str = "NULL,A,L%A,B,L%A,C,R%B,D,R%C,E,L%C,F,R%D,G,L%F,H,L%NULL,NULL,NULL";
    char *identification = "%";
    char *identification2 = ",";

    vector<string> vec_str = separate(str, identification);
    vector<vector<string>> vtr_dual;

    vtr_dual = conversion2vector(identification2, vtr_dual, vec_str);

    for (auto item = vtr_dual.cbegin(); item != vtr_dual.cend(); ++item) {
        for (int i = 0; i < (*item).size(); ++i) {
            cout << (*item)[i] << "  ";
        }
    }
    cout << "\n" << "--------------------------------------------" << "\n";

}
