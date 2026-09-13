#include "job_scheduler.hpp"

namespace job_scheduler {
    JobHandle JobScheduler::submit(std::function<void()>& work) {
        JobHandle jobHandle{.id = 0};
        Job job{.m_job = work};
        job.m_job();

        return jobHandle;
    }

    void JobScheduler::waitFor(JobHandle jobHandle) {
        return;
    }
}