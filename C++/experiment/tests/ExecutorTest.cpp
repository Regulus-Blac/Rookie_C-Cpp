#include <gtest/gtest.h>
#include <memory>
// #include <tuple>
#include "Executor.hpp"
#include "PoseEq.hpp"

namespace adas{
// TEST是一个宏
// 测试套件名+测试名
// 智能指针：自动内存管理，避免泄漏
//0.基础测试
    //0.1
    TEST(ExecutorTest, should_return_init_pose_when_whitout_command){
        //given
        std::unique_ptr<Executor> executor(Executor::NewExecutor({0, 0, 'E'}));
        // when
        // then
        const Pose target({0, 0, 'E'});
        ASSERT_EQ(target, executor->Query());
    }
    //0.2
    TEST (ExecutorTest, should_return_default_pose_when_without_init_and_command){
        // given
        std::unique_ptr<Executor> executor(Executor::NewExecutor());//没有初始姿势
        // when
        // then
        const Pose target({0, 0, 'N'});
        ASSERT_EQ(target, executor->Query());
    }
//1.移动指令
//1.1
    TEST (ExecutorTest, should_return_x_p1us_1_given_comand_is_M_and_facing_is_E){
    // given
    std::unique_ptr<Executor> executor(Executor::NewExecutor({0, 0, 'E'}) ); //
    // when 
    executor->Execute("M");
    // then
    const Pose target ({1,0,'E'});
    ASSERT_EQ(target, executor->Query());
    }

//1.2
    TEST (ExecutorTest, should_return_x_minus_1_given_comand_is_M_and_facing_is_W){
    // given
    std::unique_ptr<Executor> executor(Executor::NewExecutor({0, 0, 'W'}) ); //
    // when 
    executor->Execute("M");
    // then
    const Pose target ({-1,0,'W'});
    ASSERT_EQ(target, executor->Query());
    }

//1.3
    TEST (ExecutorTest, should_return_y_plus_1_given_command_is_M_and_facing_is_N){
    // given
    std::unique_ptr<Executor> executor(Executor::NewExecutor({0, 0, 'N'}) ); //
    // when 
    executor->Execute("M");
    // then
    const Pose target ({0,1,'N'});
    ASSERT_EQ(target, executor->Query());
    }

//1.4
    TEST (ExecutorTest, should_return_y_minus_1_given_command_is_M_and_facing_is_S){
    // given
    std::unique_ptr<Executor> executor(Executor::NewExecutor({0, 0, 'S'}) ); //
    // when 
    executor->Execute("M");
    // then
    const Pose target ({0,-1,'S'});
    ASSERT_EQ(target, executor->Query());
    }

//2.左转指令
//2.1
    TEST (ExecutorTest,should_return_facing_N_given_command_is_L_and_facing_is_E){
    // given
    std::unique_ptr<Executor> executor(Executor::NewExecutor({0, 0, 'E'}) ); //
    // when 
    executor->Execute("L");
    // then
    const Pose target ({0,0,'N'});
    ASSERT_EQ(target, executor->Query());
    }

//2.2
    TEST (ExecutorTest, should_return_facing_W_given_command_is_L_and_facing_is_N){
    // given
    std::unique_ptr<Executor> executor(Executor::NewExecutor({0, 0, 'N'}) ); //
    // when 
    executor->Execute("L");
    // then
    const Pose target ({0,0,'W'});
    ASSERT_EQ(target, executor->Query());
    }

//2.3
    TEST (ExecutorTest,should_return_facing_S_given_command_is_L_and_facing_is_W){
    // given
    std::unique_ptr<Executor> executor(Executor::NewExecutor({0, 0, 'W'}) ); //
    // when 
    executor->Execute("L");
    // then
    const Pose target ({0,0,'S'});
    ASSERT_EQ(target, executor->Query());
    }

//2.4
    TEST (ExecutorTest, should_return_facing_E_given_command_is_L_and_facing_is_S){
    // given
    std::unique_ptr<Executor> executor(Executor::NewExecutor({0, 0, 'S'}) ); //
    // when 
    executor->Execute("L");
    // then
    const Pose target ({0,0,'E'});
    ASSERT_EQ(target, executor->Query());
    }

//3.右转指令
//3.1
    TEST (ExecutorTest, should_return_facing_S_given_command_is_R_and_facing_is_E){
    // given
    std::unique_ptr<Executor> executor(Executor::NewExecutor({0, 0, 'E'}) ); //
    // when 
    executor->Execute("R");
    // then
    const Pose target ({0,0,'S'});
    ASSERT_EQ(target, executor->Query());
    }

//3.2
    TEST (ExecutorTest, should_return_facing_W_given_command_is_R_and_facing_is_S){
    // given
    std::unique_ptr<Executor> executor(Executor::NewExecutor({0, 0, 'S'}) ); //
    // when 
    executor->Execute("R");
    // then
    const Pose target ({0,0,'W'});
    ASSERT_EQ(target, executor->Query());
    }

//3.3
    TEST (ExecutorTest, should_return_facing_N_given_command_is_R_and_facing_is_W){
    // given
    std::unique_ptr<Executor> executor(Executor::NewExecutor({0, 0, 'W'}) ); //
    // when 
    executor->Execute("R");
    // then
    const Pose target ({0,0,'N'});
    ASSERT_EQ(target, executor->Query());
    }
    
//3.4
    TEST (ExecutorTest, should_return_facing_E_given_command_is_R_and_facing_is_N){
    // given
    std::unique_ptr<Executor> executor(Executor::NewExecutor({0, 0, 'N'}) ); //
    // when 
    executor->Execute("R");
    // then
    const Pose target ({0,0,'E'});
    ASSERT_EQ(target, executor->Query());
    }

}