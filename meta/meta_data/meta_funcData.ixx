export module meta_funcData;

export template <typename Data>
class meta_funcData {
private:
	const char* m_dataName;
	Data* m_data;

public:
	explicit meta_funcData() {
		m_dataName = "None";
		m_data = new int(0);
	}


	explicit meta_funcData(const char* dataName, const Data& data)
		:m_dataName(dataName),
		 m_data(new Data (data)) {}

	~meta_funcData() {
		delete m_data;
	}
	
	const char* get_dataName() {
		return m_dataName;
	}

	Data* get_data() {
		return m_data;
	}
};
