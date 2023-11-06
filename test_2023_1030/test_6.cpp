#include <iostream>
#include <string>
#include <vector>

// ����������ģ��
template <typename T>
class AbstractVector {
public:
    AbstractVector(int size) : size_(size) {}

    virtual T operation(const AbstractVector<T>& other) const = 0;

protected:
    int size_;
};

// ����������ģ��
template <typename T>
class DerivedVector : public AbstractVector<T> {
public:
    DerivedVector(int size) : AbstractVector<T>(size) {
        data_.resize(size);
    }

    T operation(const AbstractVector<T>& other) const override {
        const DerivedVector<T>& derivedOther = dynamic_cast<const DerivedVector<T>&>(other);
        if (this->size_ != derivedOther.size_) {
            throw std::runtime_error("ʸ����С��ƥ�䡣");
        }

        T result = 0;
        for (int i = 0; i < this->size_; ++i) {
            result += this->data_[i] * derivedOther.data_[i];
        }
        return result;
    }

    void setElement(int index, T value) {
        if (index < 0 || index >= this->size_) {
            throw std::out_of_range("����������Χ��");
        }
        data_[index] = value;
    }

private:
    std::vector<T> data_;
};

// �����ַ�����
class DerivedString : public AbstractVector<char> {
public:
    DerivedString(const std::string& str) : AbstractVector<char>(str.length()), str_(str) {}

    char operation(const AbstractVector<char>& other) const override {
        const DerivedString& derivedOther = dynamic_cast<const DerivedString&>(other);
        if (this->size_ != derivedOther.size_) {
            throw std::runtime_error("�ַ������Ȳ�ƥ�䡣");
        }

        // �ַ������Ӳ���
        return (str_ + derivedOther.str_).c_str()[0];
    }

private:
    std::string str_;
};

int main() {
    DerivedVector<int> intVector1(3);
    intVector1.setElement(0, 1);
    intVector1.setElement(1, 2);
    intVector1.setElement(2, 3);

    DerivedVector<int> intVector2(3);
    intVector2.setElement(0, 4);
    intVector2.setElement(1, 5);
    intVector2.setElement(2, 6);

    DerivedString str1("Hello");
    DerivedString str2("World");

    // ���Զ�̬��̬��(���ϲ���)
    AbstractVector<int>* intVectorPtr = &intVector1;
    std::cout << "intVector1��intVector2������: " << intVector1.operation(intVector2) << std::endl;

    AbstractVector<char>* strPtr = &str1;
    std::cout << "str1��str2�Ĳ����� " << static_cast<char>(str1.operation(str2)) << std::endl;


    // ��֤������С��ƥ��ʱ���쳣����
    try {
        DerivedVector<int> intVector3(3);
        intVector3.setElement(0, 1);
        intVector3.setElement(1, 2);
        intVector3.setElement(2, 3);

        DerivedVector<int> intVector4(2);
        intVector4.setElement(0, 4);
        intVector4.setElement(1, 5);

        // �������д���Ӧ���׳��쳣
        int result = intVector3.operation(intVector4);
        std::cout << "intVector3��intVector4������: " << result << std::endl;
    }
    catch (const std::runtime_error& e) {
        std::cout << "�����쳣: " << e.what() << std::endl;
    }



    // �����쳣�������
    try {
        DerivedVector<int> intVector5(3);
        intVector5.setElement(0, 1);
        intVector5.setElement(1, 2);
        intVector5.setElement(2, 3);

        DerivedVector<int> intVector6(3);
        intVector6.setElement(0, 4);
        intVector6.setElement(1, 5);

        // �������д���Ӧ���׳��쳣
        int result = intVector5.operation(intVector6);
        std::cout << "intVector5��intVector6������: " << result << std::endl;
    }
    catch (const std::runtime_error& e) {
        std::cout << "�����쳣: " << e.what() << std::endl;
    }


    return 0;
}

