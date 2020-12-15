cmake_minimum_required(VERSION 3.15.3)
project(PrisonerDilemma)

set(CMAKE_CXX_STANDARD 14)

add_executable(PrisonerDilemma main.cpp factory.h strategy.h
        all-defect.cpp all-defect.h table.h random.cpp random.h poor-trusting-fool.cpp
        poor-trusting-fool.h tough-tit-for-tat.cpp tough-tit-for-tat.h mode.cpp mode.h
        soft-tit-for-tat.cpp soft-tit-for-tat.h change-choice.cpp change-choice.h forgive-revenge.cpp
        forgive-revenge.h detailed_mode.cpp detailed_mode.h fast_mode.cpp fast_mode.h tournament_mode.cpp
        tournament_mode.h tests.cpp gamer.h gameplay_creator.cpp gameplay_creator.h)

ADD_SUBDIRECTORY (googletest)
include_directories(googletest/googletest/include)

target_link_libraries(PrisonerDilemma gtest gtest_main)