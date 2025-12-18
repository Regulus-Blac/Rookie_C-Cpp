# pragma once
#include "Executor.hpp"
#include "Direction.hpp"

namespace adas{
    class PoseHandler final{
        public:
            PoseHandler(const Pose& pose) noexcept;
            //  禁止拷贝构造和赋值
            PoseHandler(const PoseHandler& ) = delete;
            PoseHandler& operator=(const PoseHandler&) = delete;

        public:
            void Forward(void) noexcept;
            void Backward(void) noexcept;

            void TurnLeft(void) noexcept;
            void TurnRight(void) noexcept;

            void Fast(void) noexcept;               //  切换加速状态
            void Reverse(void) noexcept;

            bool IsFast(void) const noexcept;       //  记录是否处于加速状态
            bool IsReverse(void) const noexcept;    //  记录是否处于倒车状态
            
            Pose Query(void) const noexcept;

        private:
            Point point;
            const Direction* facing;
            bool fast{false};       //  是否加速
            bool reverse{false};    //  是否倒车
    };
}