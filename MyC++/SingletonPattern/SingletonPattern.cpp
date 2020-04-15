#include <iostream>
#include <memory>
#include <mutex>

using namespace std;

class Singleton{
public:
    typedef std::shared_ptr<Singleton> Ptr;
    ~Singleton()
    {
        cout<<"destructor called" << endl;
    }
    Singleton(Singleton&) = delete;
    Singleton operator = (const Singleton) = delete;

    static Ptr get_instance()
    {
        // double checked lock
        if(m_instance_ptr == nullptr)
        {
            std::lock_guard<std::mutex> lk(m_mutex);
            if(m_instance_ptr == nullptr)
            {
                m_instance_ptr = std::shared_ptr<Singleton> (new Singleton);
            }
        }
        return m_instance_ptr;
    }
private:
    Singleton()
    {
        std::cout<<"constructor called"<<endl;
    }

    static Ptr m_instance_ptr;
    static std::mutex m_mutex;

};

Singleton::Ptr Singleton::m_instance_ptr = nullptr;
std::mutex Singleton::m_mutex;

int main()
{
    Singleton::Ptr instance = Singleton::get_instance();
    Singleton::Ptr instance2 = Singleton::get_instance();

    return 0;
}