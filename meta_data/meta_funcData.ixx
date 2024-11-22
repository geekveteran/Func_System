export module meta_funcData;

export template <typename Data>
class meta_funcData {
private:
	const char* m_dataName;
	Data* m_data;

public:
	explicit meta_funcData(const char* dataName, Data data)
		:m_dataName(dataName), m_data(new Data) {}

	~meta_funcData() {
		delete m_data;
	}
	
	const char* get_dataName() {
		return m_dataName;
	}

	Data get_data() {
		return *m_data;
	}
};
