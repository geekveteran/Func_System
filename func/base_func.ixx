export module base_func;

import simple_vector;
import meta_funcData;
import meta_func;

export template <typename inPutData, typename outPutData>
class add_func : public meta_func<inPutData, outPutData> {
private:
    void add() {
    }
public:
    // Default constructor
    add_func()
        : meta_func<inPutData, outPutData>() 
        {
            add();
        }

    // Parameterized constructor
    add_func(const char* funcName, 
                      const simple_vector<inPutData>& iData, 
                      const outPutData& oData)
        : meta_func<inPutData, outPutData>(funcName, iData, oData)
    {
            add();
    }

    // Destructor
    ~add_func() {
    }




};
