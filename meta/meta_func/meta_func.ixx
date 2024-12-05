export module meta_func;

import simple_vector;
import meta_funcData;
import base_pointer;

export template <typename intPutData, typename outPutData>
class meta_func {
    using iData = meta_funcData<intPutData>;
    using oData = meta_funcData<outPutData>;
    using v_iData = simple_vector<iData>;
    using i_dataPt = unique_pointer<iData>;
    using v_iDataPt = unique_pointer<simple_vector<iData>>;
    using o_dataPt = unique_pointer<oData>;
    const char* funcName = "meta_func_name";
private:
    const char* m_funcName;
    v_iDataPt m_inPutData; // Assuming simple_vector is user-defined
    o_dataPt m_outPutData;

public:
    // Default constructor
    meta_func()
        : m_funcName(funcName),
          m_inPutData(),
          m_outPutData() {}

    // Parameterized constructor
    meta_func(const char* funcName, v_iData& inDataVec, oData& outData)
        : m_funcName(funcName),
          m_inPutData(unique_pointer<v_iData>(&inDataVec)),
          m_outPutData(unique_pointer<oData>(&outData)) {}

    // Destructor
    virtual ~meta_func() {
    }

    // Accessor for function name
    virtual const char* get_dataName() const {
        return m_funcName;
    }

    // Accessor for input data
    virtual v_iData& get_intPutData()  {
        return *(m_inPutData.release());
    }

    // Accessor for output data
    virtual oData& get_outPutData()  {
        return *(m_outPutData.release());
    }

    virtual void compute() {}
};


