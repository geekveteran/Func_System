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
    const char* funName = "func";
    using BaseFunc = meta_func<meta_funcData<int>, meta_funcData<int>>;
    BaseFunc abb;
    BaseFunc* func = new BaseFunc(funName, data_vec, data);
    const char* base_name = "base";
    simple_vector<int> inputData;
    int outputData = 42;
    BaseFunc dc(base_name, data_vec, data);
    func->get_dataName();
    func->get_outPutData();
// Assuming simple_vector<int> is available and can be constructed like this:

// Create an instance of derived_meta_func with specific values
    BaseFunc* bfunc = new BaseFunc(funName, data_vec, data);
    std::cout<< bfunc->get_dataName()<< std::endl;
    std::cout<< bfunc->get_intPutData() << std::endl;
    using app = add_func<meta_funcData<int>, meta_funcData<int>>;
    app* int_func = new app (base_name, data_vec, data);
    std::cout<< int_func->get_dataName() << std::endl;
    func_dataBase<BaseFunc> db;
    std::cout << db.get_funcDBName();
    return 0;

}

