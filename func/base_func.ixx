export module base_func;

import simple_vector;
import meta_funcData;
import meta_func;


export template <typename Data>
class add_func : public meta_func<Data, Data> {
    using m_funcData = meta_funcData<Data>;
    using m_func = meta_func<meta_funcData<Data>,meta_funcData<Data>>;
private:
    void add() {
        //simple_vector<m_funcData> vec = m_func::get_intPutData();
        Data* data = this->get_outPutData();
    }
public:
    // Default constructor
    add_func()
        : meta_func<Data, Data>() 
        {
        }

    // Parameterized constructor
    add_func(const char* funcName, 
                      const simple_vector<Data>& iData, 
                      const Data& oData)
        : meta_func<Data, Data>(funcName, iData, oData)
    {
    }

    // Destructor
    ~add_func() {
    }




};
