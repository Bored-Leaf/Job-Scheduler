#include <print>

#include "job_scheduler.hpp"

namespace job_scheduler {
    JobHandle submit(std::function<void()>& work) {
        Job job{.m_job = work};
        JobHandle jobHandle{};
        
        job.m_job();
        jobHandle.m_jobFinished = true;

        return jobHandle;
    }

    void sayHello() {
        std::println("Hello from job scheduer!");
    }
}