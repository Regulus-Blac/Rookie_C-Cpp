cmake_minimum_required(VERSION 3.10...3.28)

PROJECT("EXP1_ZYB")

SET(CMAKE_CXX_STANDARD 17)
SET(CMAKE_CXX_STANDARD_REQUIRED ON)
SET(CMAKE_CXX_EXTENSIONS OFF)
SET(CMAKE_CXX_FLAGS "-Wno-deprecated-declarations -Wall -Werror -Wnon-virtual-dtor -Woverloaded-virtual")
#可执行文件输出目录
SET(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)
#构建的库的输出目录
SET(LIBRARY_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin) 

# 12345678 1行新加
find_package(Threads REQUIRED)

#构建test 目标
ENABLE_TESTING()
#向当前项目添加一个子目录，并且使得 CMake 在构建过程中进入该子目录继续处理其中的 CMakeLists.txt 文件。
#这个命令通常用于管理项目中的多个模块或子项目。
ADD_SUBDIRECTORY(src)
ADD_SUBDIRECTORY(tests)

# 123456 以下均为新加
# 在添加 tests 子目录后再链接线程库到 gtest / gtest_main 以及测试可执行文件（若存在）
if(TARGET gtest)
  target_link_libraries(gtest PRIVATE Threads::Threads)
endif()
if(TARGET gtest_main)
  target_link_libraries(gtest_main PRIVATE Threads::Threads)
endif()

if(TARGET ${PROJECT_NAME}-main)
  target_link_libraries(${PROJECT_NAME}-main PRIVATE ${PROJECT_NAME} gtest_main Threads::Threads)
  ADD_TEST(NAME ${PROJECT_NAME}-main COMMAND ${PROJECT_NAME}-main)
endif()
