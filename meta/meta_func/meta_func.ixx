export module meta_func;

import simple_vector;
import meta_funcData;
import base_pointer;

export template <typename intPutData, typename outPutData>
class meta_func {
    using iData = meta_funcData<intPutData>;
    using oData = meta_funcData<outPutData>;
    using i_dataPt = unique_pointer<iData>;
    using v_iDataPt = unique_pointer<simple_vector<iData>>;
    using o_dataPt = unique_pointer<oData>;
private:
    const char* m_funcName;
    v_iDataPt m_inPutData; // Assuming simple_vector is user-defined
    o_dataPt m_outPutData;

public:
    // Default constructor
    meta_func()
        : m_funcName("noneFunc"),
          m_inPutData(),
          m_outPutData() {}

    // Parameterized constructor
    meta_func(const char* funcName, const v_iDataPt& inDataVec, const o_dataPt& outData)
        : m_funcName(funcName),
          m_inPutData(inDataVec),
          m_outPutData(outData) {}

    // Destructor
    virtual ~meta_func() {
    }

    // Accessor for function name
    virtual const char* get_dataName() const {
        return m_funcName;
    }

    // Accessor for input data
    virtual v_iDataPt get_intPutData() const {
        return m_inPutData;
    }

    // Accessor for output data
    virtual o_dataPt get_outPutData() const {
        return m_outPutData;
    }

    virtual void compute() {}
};


