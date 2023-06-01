#pragma once
template <class T>

class MyUniquePtr
{
private:
    T * ptr_ = nullptr;
public:
    MyUniquePtr() : ptr_(nullptr){}
    MyUniquePtr(T * ptr) : ptr_(ptr){}
    MyUniquePtr(const MyUniquePtr & ) = delete; // deleted copy ctor
    MyUniquePtr(MyUniquePtr &&); // todo move ctor
    MyUniquePtr& operator=(const MyUniquePtr &) = delete; // deleted copy assignment 
    MyUniquePtr& operator=(MyUniquePtr &&); // todo Move assignment operator
    T* operator->()
    {
        return ptr_;
    }
    T& operator*()
    {
        return *(ptr_);
    }
    T* get() const
    {
        return ptr_;
    }
    T* release(); // todo return pointer to release object method
    void reset()
    {
        if(ptr_ != nullptr)
        {
            delete ptr_;
            ptr_ = nullptr;
        }
    }
    ~MyUniquePtr()
    {
        if(ptr_ != nullptr)
        {
            delete ptr_;
        }
    }
};
