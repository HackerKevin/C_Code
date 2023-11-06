#include <iostream>
#include <string>
#include <vector>

// 抽象向量类模板
template <typename T>
class AbstractVector {
public:
    AbstractVector(int size) : size_(size) {}

    virtual T operation(const AbstractVector<T>& other) const = 0;

protected:
    int size_;
};

// 派生向量类模板
template <typename T>
class DerivedVector : public AbstractVector<T> {
public:
    DerivedVector(int size) : AbstractVector<T>(size) {
        data_.resize(size);
    }

    T operation(const AbstractVector<T>& other) const override {
        const DerivedVector<T>& derivedOther = dynamic_cast<const DerivedVector<T>&>(other);
        if (this->size_ != derivedOther.size_) {
            throw std::runtime_error("矢量大小不匹配。");
        }

        T result = 0;
        for (int i = 0; i < this->size_; ++i) {
            result += this->data_[i] * derivedOther.data_[i];
        }
        return result;
    }

    void setElement(int index, T value) {
        if (index < 0 || index >= this->size_) {
            throw std::out_of_range("索引超出范围。");
        }
        data_[index] = value;
    }

private:
    std::vector<T> data_;
};

// 派生字符串类
class DerivedString : public AbstractVector<char> {
public:
    DerivedString(const std::string& str) : AbstractVector<char>(str.length()), str_(str) {}

    char operation(const AbstractVector<char>& other) const override {
        const DerivedString& derivedOther = dynamic_cast<const DerivedString&>(other);
        if (this->size_ != derivedOther.size_) {
            throw std::runtime_error("字符串长度不匹配。");
        }

        // 字符串连接操作
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

    // 测试动态多态性(联合测试)
    AbstractVector<int>* intVectorPtr = &intVector1;
    std::cout << "intVector1和intVector2的运算: " << intVector1.operation(intVector2) << std::endl;

    AbstractVector<char>* strPtr = &str1;
    std::cout << "str1和str2的操作： " << static_cast<char>(str1.operation(str2)) << std::endl;


    // 验证向量大小不匹配时的异常处理
    try {
        DerivedVector<int> intVector3(3);
        intVector3.setElement(0, 1);
        intVector3.setElement(1, 2);
        intVector3.setElement(2, 3);

        DerivedVector<int> intVector4(2);
        intVector4.setElement(0, 4);
        intVector4.setElement(1, 5);

        // 以下这行代码应该抛出异常
        int result = intVector3.operation(intVector4);
        std::cout << "intVector3和intVector4的运算: " << result << std::endl;
    }
    catch (const std::runtime_error& e) {
        std::cout << "捕获到异常: " << e.what() << std::endl;
    }



    // 更多异常情况测试
    try {
        DerivedVector<int> intVector5(3);
        intVector5.setElement(0, 1);
        intVector5.setElement(1, 2);
        intVector5.setElement(2, 3);

        DerivedVector<int> intVector6(3);
        intVector6.setElement(0, 4);
        intVector6.setElement(1, 5);

        // 以下这行代码应该抛出异常
        int result = intVector5.operation(intVector6);
        std::cout << "intVector5和intVector6的运算: " << result << std::endl;
    }
    catch (const std::runtime_error& e) {
        std::cout << "捕获到异常: " << e.what() << std::endl;
    }


    return 0;
}

