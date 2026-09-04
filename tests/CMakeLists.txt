
add_executable(Job_Scheduler_Tests main.cpp)

if (CMAKE_SYSTEM_NAME STREQUAL "Linux")
    target_compile_options(Job_Scheduler_Tests PRIVATE -stdlib=libc++)
    target_link_options(Job_Scheduler_Tests PRIVATE -stdlib=libc++ -lc++abi)
endif()

target_link_libraries(Job_Scheduler_Tests PRIVATE Job_Scheduler)