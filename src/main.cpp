import simple_vector;
import meta_funcData;
import meta_func;
import func_dataBase;

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
    const char* funcName = "func";
    using BaseFunc = meta_func<meta_funcData<int>, meta_funcData<int>>;
    BaseFunc func(funcName, data_vec, data);
    func.get_dataName();
    func.get_outPutData();
    simple_vector <BaseFunc> s_vec;
    func_dataBase<BaseFunc> db;
    std::cout << db.get_funcDBName();
    return 0;

}

