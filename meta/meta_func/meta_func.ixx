export module meta_func;

import simple_vector;
import meta_funcData;


export template <typename intPutData, typename outPutData>
class meta_func {
    using iData = meta_funcData<intPutData>;
    using oData = meta_funcData<outPutData>;
private:
    const char* m_funcName;
    simple_vector<iData>* m_inPutData; // Assuming simple_vector is user-defined
    oData* m_outPutData;

public:
    // Default constructor
    meta_func()
        : m_funcName("noneFunc"),
          m_inPutData(nullptr),
          m_outPutData(nullptr) {}

    // Parameterized constructor
    meta_func(const char* funcName, const simple_vector<iData>& inData, const oData& outData)
        : m_funcName(funcName),
          m_inPutData(new simple_vector<iData>(inData)),
          m_outPutData(new oData(outData)) {}

    // Destructor
    virtual ~meta_func() {
        if (m_inPutData)
        {
            delete m_inPutData;
        }
        if (m_outPutData)
        {
            delete m_outPutData;
        }
    }

    // Accessor for function name
    virtual const char* get_dataName() const {
        return m_funcName;
    }

    // Accessor for input data
    virtual simple_vector<iData>* get_intPutData() const {
        return m_inPutData;
    }

    // Accessor for output data
    virtual oData* get_outPutData() const {
        return m_outPutData;
    }

    virtual void compute() {}
};


