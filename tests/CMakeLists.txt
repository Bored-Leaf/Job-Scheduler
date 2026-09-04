
add_executable(job_scheduler_tests main.cpp)

if (CMAKE_SYSTEM_NAME STREQUAL "Linux")
    target_compile_options(job_scheduler_tests PRIVATE -stdlib=libc++)
    target_link_options(job_scheduler_tests PRIVATE -stdlib=libc++ -lc++abi)
endif()

target_link_libraries(job_scheduler_tests PRIVATE job_scheduler)