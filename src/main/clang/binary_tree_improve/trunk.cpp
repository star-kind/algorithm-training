#include "../../head/clang_enhance.h"

void trunk_execute() {
    biTrNode *tree;
    queue<biTrNode *> que;
    string str = "NULL,A,L%A,B,L%A,C,R%B,D,R%C,E,L%C,F,R%D,G,L%F,H,L%NULL,NULL,NULL";
    char *identification = "%";
    char *identification2 = ",";

    vector<string> vec_str = separate(str, identification);
    vector<vector<string>> vtr_dual;

    vector<string> ve_tmp;
    for (auto iter = vec_str.cbegin(); iter != vec_str.cend(); ++iter) {
        ve_tmp.clear();
        string s = (*iter);

        ve_tmp = separate(s, identification2);
        vtr_dual.push_back(ve_tmp);
    }

    for (auto item = vtr_dual.cbegin(); item != vtr_dual.cend(); ++item) {
        for (int i = 0; i < (*item).size(); ++i) {
            cout << (*item)[i] << "  ";
        }
    }
    cout << "\n" << "--------------------------------------------" << "\n";

    que = generate_root(tree, que, vtr_dual[0]);
    cout << "trace00==" << que.back()->data << "\n";

    que = create_tree_nodes(que, vtr_dual[1]);
    cout << "trace01==" << que.back()->data << "\n";

    que = create_tree_nodes(que, vtr_dual[2]);
    cout << "trace02==" << que.back()->data << "\n";

    //TODO Here Beginning
    que = create_tree_nodes(que, vtr_dual[3]);
    cout << "trace03==" << que.back()->data << "\n";

}
