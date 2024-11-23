export module meta_func;



export template <typename Data>
class meta_func {
private:
	const char* m_funcName;
	Data m_data;

public:
	explicit meta_func(const char* dataName, const Data& data)
		:m_funcName(dataName), m_data(data) {}

	~meta_func() {
	}
	
	const char* get_dataName() {
		return m_funcName;
	}

	const Data& get_data() {
		return m_data;
	}
};