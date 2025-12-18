#pragma once
#include "Executor.hpp"
#include "cmder/CmderOrchestrator.hpp"
#include "core/PoseHandler.hpp"
#include <memory>

namespace adas{

    class ExecutorImpl final: public Executor{
    public:
        //  构造和析构函数
        explicit ExecutorImpl(const Pose& pose,CmderOrchestrator* orchestrator) noexcept;
        ~ExecutorImpl() noexcept = default;

        //  不能拷贝和赋值
        ExecutorImpl(const ExecutorImpl &) = delete;
        ExecutorImpl & operator=(const ExecutorImpl &) = delete;

    public:
    //  查询姿态
        Pose Query(void) const noexcept override;
    //  执行指令（字符串表示）    
        void Execute(const std::string &commands) noexcept override;

    private:
        PoseHandler poseHandler;    //  用于状态管理
        std::unique_ptr<CmderOrchestrator> orchestrator; //  指令编排者
    };

}