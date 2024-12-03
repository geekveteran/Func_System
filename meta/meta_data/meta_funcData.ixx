export module meta_funcData;

import base_pointer;

export template <typename Data>
class meta_funcData {
	using u_dataPt = unique_pointer<Data>;
private:
	const char* m_dataName;
	u_dataPt m_data;

public:
	explicit meta_funcData() {
		m_dataName = "None";
		m_data = u_dataPt(); 
	}

	explicit meta_funcData(const char* dataName, const Data& data)
	{
		m_dataName = dataName;
		Data * dataPointer = new Data(data);
		m_data = u_dataPt(dataPointer);
	}

	~meta_funcData() {
	}
	
	const char* get_dataName() const{
		return m_dataName;
	}

	u_dataPt& get_data()  {
		return m_data;
	}
	
	// Overload + Operator
	meta_funcData operator+(const meta_funcData& other) const {
		// Combine the dataName and add the values of m_data
		const char* newName = "Combined"; // Simplified naming logic
		u_dataPt combinedData = (m_data ? *m_data : Data()) +
			(other.m_data ? *other.m_data : Data());
		return meta_funcData(newName, combinedData);
	}

    void* operator new(size_t size) {
        // Custom memory allocation logic (for example, using operator new directly)
        void* ptr = ::operator new(size);  // Use global new
        return ptr;
    }

	void operator delete(void* ptr) {
		if (!ptr)
		{
        ::operator delete(ptr);  // Use global delete
		}
    }

	    void* operator new[](size_t size) {
        void* ptr = ::operator new[](size);
        return ptr;
    }

	    void operator delete[](void* ptr) {
        ::operator delete[](ptr);
    }	
};
