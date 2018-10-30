#pragma once
#include <vector>

template<typename T>
class Template_vector {
public:
    Template_vector();
    Template_vector(int dim_);
    Template_vector(const std::vector<T> &nums);

    // void ; тут будет норма

    void print() const;

    ~Template_vector() = default;


private:
    std::vector<T> vector_s;
    int dim;
};

template<typename T>
Template_vector<T>::Template_vector() : vector_s() { dim = 0; }

template<typename T>
Template_vector<T>::Template_vector(int dim_){
    vector_s.assign(dim_, (T)0);
    dim = dim_;
}

template<typename T>
Template_vector<T>::Template_vector(const std::vector<T> &nums) : vector_s(nums){
    dim = nums.size();
}

template<typename T>
void Template_vector<T>::print() const{
    std::cout << "[ ";
    for (T a : vector_s)
        std::cout << a << " ";
    std::cout << "]";
}