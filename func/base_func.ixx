export module base_func;

import simple_vector;
import meta_funcData;
import meta_func;

#include <cstring>
#include <utility>

template <typename intPutData, typename outPutData>
class derived_meta_func : public meta_func<intPutData, outPutData> {
private:
    char* m_extraInfo; // Additional data as a C-string

public:
    // Default constructor
    derived_meta_func()
        : meta_func<intPutData, outPutData>(), m_extraInfo(nullptr) {}

    // Parameterized constructor
    derived_meta_func(const char* funcName, 
                      const simple_vector<intPutData>& iData, 
                      const outPutData& oData, 
                      const char* extraInfo)
        : meta_func<intPutData, outPutData>(funcName, iData, oData),
          m_extraInfo(new char[strlen(extraInfo) + 1]) {
        strcpy(m_extraInfo, extraInfo);
    }

    // Copy constructor
    derived_meta_func(const derived_meta_func& other)
        : meta_func<intPutData, outPutData>(other),
          m_extraInfo(new char[strlen(other.m_extraInfo) + 1]) {
        strcpy(m_extraInfo, other.m_extraInfo);
    }

    // Move constructor
    derived_meta_func(derived_meta_func&& other) noexcept
        : meta_func<intPutData, outPutData>(std::move(other)),
          m_extraInfo(other.m_extraInfo) {
        other.m_extraInfo = nullptr;
    }

    // Destructor
    ~derived_meta_func() {
        delete[] m_extraInfo;
    }

    // Copy assignment operator
    derived_meta_func& operator=(const derived_meta_func& other) {
        if (this != &other) {
            meta_func<intPutData, outPutData>::operator=(other);
            delete[] m_extraInfo;
            m_extraInfo = new char[strlen(other.m_extraInfo) + 1];
            strcpy(m_extraInfo, other.m_extraInfo);
        }
        return *this;
    }

    // Move assignment operator
    derived_meta_func& operator=(derived_meta_func&& other) noexcept {
        if (this != &other) {
            meta_func<intPutData, outPutData>::operator=(std::move(other));
            delete[] m_extraInfo;
            m_extraInfo = other.m_extraInfo;
            other.m_extraInfo = nullptr;
        }
        return *this;
    }

    // Accessor for extra info
    const char* get_extraInfo() const {
        return m_extraInfo;
    }

    // Mutator for extra info
    void set_extraInfo(const char* extraInfo) {
        delete[] m_extraInfo;
        m_extraInfo = new char[strlen(extraInfo) + 1];
        strcpy(m_extraInfo, extraInfo);
    }

    // New functionality: Perform a computation with input data
    outPutData computeResult() const {
        const simple_vector<intPutData>* inputData = this->get_intPutData();
        outPutData* result = this->get_outPutData();

        if (inputData && result) {
            outPutData computedResult = *result;

            // Example: Add all elements in inputData to computedResult
            for (int i = 0; i < inputData->size(); ++i) {
                computedResult += static_cast<outPutData>((*inputData)[i]);
            }
            return computedResult;
        }
        throw "Invalid input or output data for computation.";
    }

    // Override get_dataName to append derived info
    const char* get_dataName() const override {
        static char buffer[256];
        snprintf(buffer, sizeof(buffer), "%s (Derived)", meta_func<intPutData, outPutData>::get_dataName());
        return buffer;
    }
};
