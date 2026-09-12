cmake_minimum_required(VERSION 3.10.0)
project(JobScheduler VERSION 0.1.0 LANGUAGES C CXX)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS TRUE)
set(CMAKE_CXX_EXTENSIONS OFF)

file(GLOB source_files "src/*.cpp")

add_library(job_scheduler STATIC ${source_files})

target_include_directories(job_scheduler
    PUBLIC
    include
)

set_target_properties(job_scheduler PROPERTIES POSITION_INDEPENDENT_CODE ON)
target_compile_features(job_scheduler PUBLIC cxx_std_23)

add_subdirectory(tests)