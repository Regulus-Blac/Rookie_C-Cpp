#pragma once
#include <string>
namespace adas{         //高级驾驶辅助系统

    enum class ExecutorType{
        NORMAL,
        SPORTS_CAR,
        BUS,
    };

    struct Pose{
        int x;
        int y;
        char heading; //方向
    };

    class Executor{
    public:
        static Executor *NewExecutor(const Pose &pose = {0 ,0,'N'}, const ExecutorType executorType = ExecutorType::NORMAL) noexcept;
    public:
        Executor(void) = default;
        virtual ~Executor(void) = default;

        //不可拷贝和赋值
        Executor(const Executor &) = delete;
        Executor &operator=(const Executor &) = delete;

    public:
    //  查询当前汽车姿态
        virtual Pose Query(void) const noexcept = 0;
        virtual void Execute(const std::string &commands) noexcept = 0;
    };
}
