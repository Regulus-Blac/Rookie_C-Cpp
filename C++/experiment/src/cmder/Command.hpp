#pragma once

#include "../core/PoseHandler.hpp"
#include "CmderOrchestrator.hpp"
#include <functional>

namespace adas{

    class MoveCommand final
    {
    public:
        ActionGroup operator()(const PoseHandler& poseHandler,const CmderOrchestrator& orchestrator) const noexcept
        {
            return orchestrator.Move(poseHandler);
        }
    };

    class TurnLeftCommand final
    {
    public:
        ActionGroup operator()(const PoseHandler& poseHandler,const CmderOrchestrator& orchestrator) const noexcept
        {
            return orchestrator.TurnLeft(poseHandler);
        }
    };   
             
    class TurnRightCommand final
    {
    public:
        ActionGroup operator()(const PoseHandler& poseHandler,const CmderOrchestrator& orchestrator) const noexcept
        {
            return orchestrator.TurnRight(poseHandler);
        }
    };   

    class FastCommand final
    {
    public:
        ActionGroup operator()(const PoseHandler& poseHandler,const CmderOrchestrator& orchestrator) const noexcept
        {
            ActionGroup actionGroup;
            // 每次收到 F 都切换加速状态（toggle），因此始终推入操作由 PoseHandler 处理开/关
            actionGroup.PushAction(ActionType::BE_FAST_ACTION);
            return actionGroup;
        }
    };    

    class ReverseCommand final
    {
    public:
        ActionGroup operator()(const PoseHandler& poseHandler,const CmderOrchestrator& orchestrator) const noexcept
        {
            ActionGroup actionGroup;
            // 每次收到 B 都切换倒车状态（toggle），因此始终推入操作由 PoseHandler 处理开/关
            actionGroup.PushAction(ActionType::BE_REVERSE_ACTION);
            return actionGroup;
        }
    };

    class TurnRoundCommand final
    {
    public:
        ActionGroup operator()(const PoseHandler& poseHandler,const CmderOrchestrator& orchestrator) const noexcept
        {
            return orchestrator.TurnRound(poseHandler);
            // //  倒车状态下不执行任何操作
            // if (poseHandler.IsReverse()) {
            //     return ActionGroup();
            // }
            // else{
            //     if (poseHandler.IsFast()) {
            //         return ActionGroup({
            //             ActionType::FORWARD_1_STEP_ACTION,
            //             ActionType::TURNLEFT_ACTION,
            //             ActionType::FORWARD_1_STEP_ACTION,
            //             ActionType::TURNLEFT_ACTION
            //         });
            //     }else{
            //         return ActionGroup({
            //             ActionType::TURNLEFT_ACTION,
            //             ActionType::FORWARD_1_STEP_ACTION,
            //             ActionType::TURNLEFT_ACTION
            //         });
            //     }
            // }
        }
    };

}