#include <functional>

// TODO: doxygen Don't forget to document thread safety stuff
/**
 * @brief Provides a job scheduler skeleton
 *
 * @details This namespace contains a custom built job scheduler and its relevant objects. 
 * For now though its just a skeleton and so it just takes a job and works on it immediately 
 * guarenteeing to not block or yield at any point so is guarenteed to be thread safe.
 *
 * ### Basic Usage example
 * @code 
 *
 * job_scheduler::JobScheduler jobScheduler{};
 * JobHandle jobHandle = jobScheduler.submit([]() { std::println("a job"); });
 * ...
 * jobScheduler.waitFor(jobHandle);
 *
 * @endcode 
 */
namespace job_scheduler {
/**
    * @internal
    * @brief Represents a job.
    */
    struct Job {
        std::function<void()>& m_job;
    };

    /**
    * @internal
    * @brief Represents public accessable metadata about a job.
    *
    * @note Has no way to connect to specific @ref Job in its current implementation.
    */
    struct JobHandle {  
        uint32_t id;
    };
    
    /**
    * @brief A job scheduler skeleton with no real threading or async capabilities.
    * @details Currently serves as a public API for a job scheduler to prevent heavy rework
    * when implemenitng a fully fledged job scheduler in the future when profiling justifies
    * it.
    *
    * Ideally when the fully fledged job scheduler is working with threading and aync it should
    * just work with minimal to no rework/tweaks to the callers end.
    *
    * @todo Implement a fully working job scheduler with thread pools/async once
    * profiling justifies it in any project.
    */
    class JobScheduler {
    public:
        /**
        * @brief Takes a job calls it and returns a @ref JobHandle.
        * @details Creates a @ref Job and @ref JobHandle, calls the job's work and returns
        * its corresponding job handle.
        *
        * @param job The callback of work.
        * @return The JobHandle of the created Job.
        */
        JobHandle submit(std::function<void()>& work);

        /**
         * @brief No-op function, returns immediately.
         * @details As the job is called immediately in @ref submit() it returns immediately without
         * any blocking or yielding.
         * @note Is always guarenteed to not block/yield.
         *
         * @todo Block/Yield once profiling demands a fully implement job scheduler.
         * 
         * @param handle JobHandle of a job to query.
         */
        void waitFor(JobHandle handle);
    };
}