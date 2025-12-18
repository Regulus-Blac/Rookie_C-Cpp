#include "PoseEq.hpp"
#include <tuple>
    namespace adas{

        bool operator==(const Pose &lhs,const Pose &rhs)
        {
            //用tie建立一个元组进行比较，元组会按顺序并且按字典序
            return std::tie(lhs.x,lhs.y,lhs.heading) == std::tie(rhs.x,rhs.y,rhs.heading);
        }

    }