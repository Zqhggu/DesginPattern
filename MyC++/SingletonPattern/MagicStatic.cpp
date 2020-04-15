//   最推荐的懒汉式单例
//  使用局部静态变量   magic static

#include <iostream>
class Singleton
{
private:
    Singleton()
    {
        std::cout<<"constructor called"<<std::endl;
    }

public:
    ~Singleton()
    {
        std::cout<<"destructor called"<<std::endl;
    }
    Singleton(const Singleton&)=delete;
    Singleton& operator=(const Singleton)=delete;
    static Singleton get_instance()
    {
        static Singleton instance;
        return instance;
    } 
int main(void)
{
    Singleton& instance_1=Singleton::get_instance();
    Singleton& instance_2=Singleton::get_instance();
    return 0;
}
};