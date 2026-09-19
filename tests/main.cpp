// TODO: Use Google tests when threading and async is implemented

#include <print>
#include "job_scheduler.hpp"

void print() {
    std::println("Test 1 >> function pointer");
}

int main(){
    job_scheduler::JobScheduler jobScheduler{};
    
    jobScheduler.submit(print);
    jobScheduler.submit([]() { std::println("Test 2 >> lambda function"); });

    int i{5};
    jobScheduler.submit([i]() { std::println("Test 3 >> Capture: i should be 5: i = {}", i); });

    jobScheduler.submit([&i]() { i++; });
    std::println("Test 4 >> Reference capture: i should be 6, i = {}", i);
}
