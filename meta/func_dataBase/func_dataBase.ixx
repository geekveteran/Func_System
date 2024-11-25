export module func_dataBase;

import simple_vector;

export template <typename Func>
class func_dataBase {
private:
	const char* m_funcDBName;
	simple_vector<Func>* m_funcVec;

public:
	explicit func_dataBase() {
		m_funcDBName = "NoneDB";
		m_funcVec = nullptr;
	}

	explicit func_dataBase(const char* dbName, const simple_vector<Func>& funcVec)
		:m_funcDBName(dbName),
		 m_funcVec(new simple_vector<Func> (funcVec)) {}

	~func_dataBase() {
		delete m_funcVec;
	}
	
	const char* get_funcDBName() {
		return m_funcDBName;
	}

};
