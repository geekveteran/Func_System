export module base_func;

import simple_vector;
import base_pointer;
import meta_funcData;
import meta_func;

export template <typename Data>
class add_func : public meta_func<Data, Data> {
    using add_Data = meta_funcData<Data>;
    using v_data = simple_vector<add_Data>;
private:
    void add()
    {
        simple_vector<add_Data>* vec = this->get_intPutData();
        add_Data res = *(this->get_outPutData());
        if (vec != nullptr)
        {
           for (auto it = vec->begin(); it != vec->end(); ++it)
           {
                add_Data& data = *it;
                res = res + data;
           }
        }
    }
public:
    // Default constructor
    add_func()
        : meta_func<Data, Data>() 
        {
        }

    // Parameterized constructor
    add_func(const char* funcName, 
                      const v_data& iData, 
                      const add_Data& oData)
        : meta_func<Data, Data>(funcName, iData, oData) {}
    // Destructor
    ~add_func() {
    }

    virtual void compute() override
    {
        //add();
        return;
    }


};
