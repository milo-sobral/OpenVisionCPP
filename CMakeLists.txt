cmake_minimum_required(VERSION 3.0.0)
project(OpenVisionCPP VERSION 0.1.0)

add_executable(OpenVisionCPP src/main.cpp)

target_include_directories(OpenVisionCPP PUBLIC
                           src/include
                           )

