export module meta_func;

import simple_vector;
import meta_funcData;


export template <typename intPutData, typename outPutData>
class meta_func {
private:
	const char* m_funcName;
	simple_vector<intPutData>* m_inPutData;
	outPutData* m_outPutData;

public:
	explicit meta_func(const char* funcName, const simple_vector<intPutData>& iData,
	const outPutData& oData)
		:m_funcName(funcName),
		 m_inPutData(new simple_vector<intPutData>(iData)),
		 m_outPutData(new outPutData(oData)) {}

	// Destructor
    virtual ~meta_func() {
        delete m_inPutData;
        delete m_outPutData;
    }

	virtual const char* get_dataName() {
		return m_funcName;
	}

	virtual const simple_vector<intPutData>* get_intPutData() {
		return m_inPutData;
	}

	virtual outPutData* get_outPutData() {
		return m_outPutData;
	}
};