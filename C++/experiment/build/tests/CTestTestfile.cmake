# CMake generated Testfile for 
# Source directory: D:/Study/C/C++/C++SOC/experiment/exp1/EXP1_ZYB/tests
# Build directory: D:/Study/C/C++/C++SOC/experiment/exp1/EXP1_ZYB/build/tests
# 
# This file includes the relevant testing commands required for 
# testing this directory and lists subdirectories to be tested as well.
add_test([=[EXP1_ZYB-main]=] "D:/Study/C/C++/C++SOC/experiment/exp1/EXP1_ZYB/bin/EXP1_ZYB-main.exe")
set_tests_properties([=[EXP1_ZYB-main]=] PROPERTIES  _BACKTRACE_TRIPLES "D:/Study/C/C++/C++SOC/experiment/exp1/EXP1_ZYB/tests/CMakeLists.txt;24;ADD_TEST;D:/Study/C/C++/C++SOC/experiment/exp1/EXP1_ZYB/tests/CMakeLists.txt;0;")
subdirs("googletest")
