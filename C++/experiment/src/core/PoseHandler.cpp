#include "PoseHandler.hpp"

namespace adas{

    PoseHandler::PoseHandler(const Pose& pose) noexcept : point(pose.x, pose.y), facing(&Direction::GetDirection(pose.heading)){}  

    void PoseHandler::Forward() noexcept
    {
        point += facing->Move(); 
    }

    void PoseHandler::Backward() noexcept
    {
        point -= facing->Move();
    }

    void PoseHandler::TurnLeft() noexcept
    {
        facing = &(facing->LeftOne());
    }

    void PoseHandler::TurnRight() noexcept
    {
        facing = &(facing->RightOne());
    }  

    void PoseHandler::Fast(void) noexcept
    {
        fast = !fast;
    }   
    
    void PoseHandler::Reverse(void) noexcept
    {
        reverse = !reverse;
    }
    
    bool PoseHandler::IsFast(void) const noexcept
    {
        return fast;
    }

    bool PoseHandler::IsReverse(void) const noexcept
    {
        return reverse;
    }

    Pose PoseHandler::Query(void) const noexcept{
        return {point.GetX(), point.GetY(), facing->GetHeading()};
    }
}