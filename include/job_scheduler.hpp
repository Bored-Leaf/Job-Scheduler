#include <functional>

// TODO: doxygen Don't forget to document thread safety stuff    
/**
 * @brief A job scheduler skeleton with no real async capabilities
 * @details Currently serves as a public API for a job scheduler to prevent heavy rework
 * when implemenitng a fully fledged job scheduler in the future when profiling justifies
 * it.
 */
namespace job_scheduler {
    /**
     * @internal
     * @brief Represents a job
     */
    struct Job {
        std::function<void()>& m_job;
    };

    /**
     * @internal
     * @brief Represents a job handle and its state
     */
    struct JobHandle {
        bool    m_jobFinished{false};
    };

    struct Batch {
    
    };

    /**
     * @brief Takes a job, calls it and returns a @ref JobHandle.
     * @details Creates a @ref Job and @ref JobHandle and calls the job's work
     * @note @ref JobHandle.m_jobFinished is guarenteed to be true.
     *
     * @param job The callback of work
     * @return a JobHandle.
     */
    JobHandle submit(std::function<void()>& work);

    void submit(Job job, Batch& batch);
    void waitFor(JobHandle handle);
    void waitFor(Batch& batch);

    void sayHello();
}