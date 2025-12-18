#pragma once

#include<functional>
#include<list>
#include<unordered_map>
#include"Command.hpp"

namespace adas{
    using Cmder = std::function<ActionGroup(const PoseHandler& poseHandler,const CmderOrchestrator& orchestrator)>;
    using CmderList = std::list<Cmder>;
    
    class CmderFactory final{
    public:
        CmderFactory(void) = default;
        ~CmderFactory(void) = default;
        //  删除构造和赋值
        CmderFactory(const CmderFactory&) = delete;
        CmderFactory& operator=(const CmderFactory&) = delete;

    public:
        CmderList GetCmders(const std::string& commands) const noexcept;

    private:
        //string_view表示该类型不会为数据分配存储空间，而且该数据类型只能用来读
        std::string ParseCommandString(std::string_view commands)const noexcept;
        void ReplaceAll(std::string &inout, std::string_view what, std::string_view with) const noexcept;

    private:
        const std::unordered_map<char, Cmder> cmderMap {
            {'M', MoveCommand()},
            {'L', TurnLeftCommand()},
            {'R', TurnRightCommand()},
            {'F', FastCommand()},
            {'B', ReverseCommand()},
            {'Z', TurnRoundCommand()},
        };
    };
}