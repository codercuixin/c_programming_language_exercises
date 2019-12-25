//
// Created by cuixin on 2019/12/25.
//

struct NODE{
    bool is_leaf;
    union{
        struct {
            struct NODE *right;
            struct NODE *left;
        }internal;
        double data;
        //data和internal事实上只会存在一个，
    }info;
};