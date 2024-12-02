import simple_vector;
import meta_funcData;
import meta_func;
import func_dataBase;
import base_func;

#include <iostream>

int main() {
    // // Allocate memory for an integer
    // int* ptr = (int*)malloc(sizeof(int)); // Explicit cast required in C++
    // if (ptr == nullptr) {
    //     std::cerr << "Memory allocation failed!" << std::endl;
    //     return 1;
    // }

    // // Assign a value
    // *ptr = 42;
    // std::cout << "Value: " << *ptr << std::endl;

    // // Free the allocated memory
    // free(ptr);

    //  simple_vector<int> vec_int;
    //  vec_int.push_back(10);
    //  vec_int.push_back(20);
    //  vec_int.push_back(30);
    //  std::cout << "Integer vector size: " << vec_int.getSize() << std::endl;
    //  std::cout << "Element at index 1: " << vec_int[1] << std::endl;
    //  // Example with strings
    //  simple_vector<std::string> vec_str;
    //  vec_str.push_back("Hello");
    //  vec_str.push_back("World");
    //  std::cout << "String vector size: " << vec_str.getSize() << std::endl;
    //  std::cout << "Element at index 0: " << vec_str[0] << std::endl;

    simple_vector<meta_funcData<int>> data_vec;
    int num = 32;
    meta_funcData<int> data("int",num);
    int oNum = 64;
    meta_funcData<int> m_data("int", oNum);
    int* a = data.get_data();
    //data_vec.push_back(meta_funcData<int>("int",32));
    //const char* funName = "func";
    //using BaseFunc = meta_func<int, int>;
    //BaseFunc abb;
    //std::cout<< abb.get_dataName();
    // using addFunc = add_func<int>;
    // addFunc *add_Func = new addFunc (funName, data_vec, m_data);
    // add_Func->compute();
    // std::cout<< add_Func->get_dataName();
    // delete add_Func;
    return 0;

}

