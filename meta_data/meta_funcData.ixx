export module meta_funcData;

export template <typename Data>
class meta_funcData {
private:
	const char* m_dataName;
	Data m_data;

public:
	explicit meta_funcData(const char* dataName, const Data& data)
		:m_dataName(dataName), m_data(data) {}

	~meta_funcData() {
	}
	
	const char* get_dataName() {
		return m_dataName;
	}

	const Data& get_data() {
		return m_data;
	}
};
