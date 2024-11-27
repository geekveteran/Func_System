import simple_vector;
import meta_funcData;
import meta_func;
import func_dataBase;
import base_func;

#include <iostream>

int main() {
    simple_vector<int> vec_int;
    vec_int.push_back(10);
    vec_int.push_back(20);
    vec_int.push_back(30);
    std::cout << "Integer vector size: " << vec_int.getSize() << std::endl;
    std::cout << "Element at index 1: " << vec_int[1] << std::endl;
    // Example with strings
    simple_vector<std::string> vec_str;
    vec_str.push_back("Hello");
    vec_str.push_back("World");
    std::cout << "String vector size: " << vec_str.getSize() << std::endl;
    std::cout << "Element at index 0: " << vec_str[0] << std::endl;

    int num = 32;
    meta_funcData<int> data("int",num);
    int* a = data.get_data();
    simple_vector<meta_funcData<int>> data_vec;
    data_vec.push_back(data);
    const char* funName = "func";
    using BaseFunc = meta_func<int, int>;
    BaseFunc abb;
    std::cout<< abb.get_dataName();
    using addFunc = add_func<int>;
    addFunc* add_Func = new addFunc (funName, data_vec, data);
    add_Func->compute();
    return 0;

}

