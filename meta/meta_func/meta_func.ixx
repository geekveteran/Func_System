export module meta_func;

import simple_vector;
import meta_funcData;


export template <typename intPutData, typename outPutData>
class meta_func {
private:
    const char* m_funcName;
    simple_vector<intPutData>* m_inPutData; // Assuming simple_vector is user-defined
    outPutData* m_outPutData;

public:
    // Default constructor
    meta_func()
        : m_funcName("noneFunc"),
          m_inPutData(nullptr),
          m_outPutData(nullptr) {}

    // Parameterized constructor
    meta_func(const char* funcName, const simple_vector<intPutData>& iData, const outPutData& oData)
        : m_funcName(funcName),
          m_inPutData(new simple_vector<intPutData>(iData)),
          m_outPutData(new outPutData(oData)) {}

    // Destructor
    virtual ~meta_func() {
        delete m_inPutData;
        delete m_outPutData;
    }

    // Accessor for function name
    virtual const char* get_dataName() const {
        return m_funcName;
    }

    // Accessor for input data
    virtual const simple_vector<intPutData>* get_intPutData() const {
        return m_inPutData;
    }

    // Accessor for output data
    virtual outPutData* get_outPutData() const {
        return m_outPutData;
    }
};


