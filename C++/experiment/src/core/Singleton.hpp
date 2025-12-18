#pragma once
namespace adas{
    //  泛型支持
    template <typename T>
    class Singleton final{
    public:
    //  静态方式获取静态实例,只有第一次调用才会被创建
        static T& Instance(void) noexcept
        {
            static T instance;
            return instance;
        }
    //  不允许构造
        Singleton(const Singleton&) = delete;
        Singleton& operator=(const Singleton&) = delete;

    private:
        Singleton(void) = default;
        ~Singleton(void) = default;
    };
}