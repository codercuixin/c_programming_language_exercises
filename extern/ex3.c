//
// Created by cuixin on 2019/12/24.
//
extern int var; // undefined reference to `var'
//上面只是对var的声明，本质上，var没有被分配任何内存。
//而下面var = 10想将一个不存在的变量改成10
int main(void){
    var = 10;
    return 0;
}
