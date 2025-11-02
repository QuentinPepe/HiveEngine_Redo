#include <comb/precomp.h>
#include <comb/combmodule.h>
#include <comb/log.h>

namespace comb
{
    void CombModule::DoConfigure(hive::ModuleContext& context)
    {
        // Comb depends only on Hive (core)
        // No additional dependencies needed

        hive::LogInfo(LogCombRoot, "Comb module configured");
    }

    void CombModule::DoInitialize()
    {
        hive::LogInfo(LogCombRoot, "Comb module initialized");

        // TODO: Initialize allocators
        // - Setup global allocator
        // - Create allocator hierarchy (frame, ECS, asset allocators)
    }

    void CombModule::DoShutdown()
    {
        hive::LogInfo(LogCombRoot, "Comb module shutdown");

        // TODO: Cleanup allocators
        // - Report memory leaks if tracking enabled
        // - Destroy allocator hierarchy
        // - Free system memory
    }
}
