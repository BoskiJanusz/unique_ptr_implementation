template <class T>

class MyUniquePtr
{
private:
    T * ptr_ = nullptr;
public:
    MyUniquePtr(); // todo default ctor
    MyUniquePtr(T * ptr); // todo ctor with ptr
    MyUniquePtr(const MyUniquePtr & ) = delete; // deleted copy ctor
    MyUniquePtr(MyUniquePtr &&); // todo move ctor
    MyUniquePtr& operator=(const MyUniquePtr &) = delete; // deleted copy assignment 
    MyUniquePtr& operator=(MyUniquePtr &&); // todo Move assignment operator
    T* operator->(); // todo arrow operator
    T& operator*(); // todo dereference operator
    T* get(); // todo return pointer to managed object method
    T* release(); // todo return pointer to release object method
    void reset(); // todo reset pointer method
    ~MyUniquePtr() // destructor
};