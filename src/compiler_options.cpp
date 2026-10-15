#include "compiler_options.hpp"
#include <unordered_map>

const std::vector<CompilerOption> watch_related_options = {
    CompilerOption{
        .name = "watchFile",
        .short_name = "",
        .is_tsconfig_only = false,
        .value_type = "string",
        .accepted_values = {"FixedPollingInterval", "PriorityPollingInterval",
                            "DynamicPriorityPolling", "FixedChunkSizePolling",
                            "UseFsEvents", "UseFsEventsOnParentDirectory"},
        .default_values = {"UseFsEvents"},
        .meta_info = {{"category", "Watch_and_Build_Modes"},
                      {"description",
                       "Specify_how_the_TypeScript_watch_mode_works"}},

    },
    CompilerOption{
        .name = "watchDirectory",
        .short_name = "",
        .is_tsconfig_only = false,
        .value_type = "string",
        .accepted_values = {"UseFsEvents", "FixedPollingInterval",
                            "DynamicPriorityPolling", "FixedChunkSizePolling"},
        .default_values = {"UseFsEvents"},
        .meta_info = {{"category", "Watch_and_Build_Modes"},
                      {"description",
                       "Specify_how_directories_are_watched_on_systems_that_"
                       "lack_recursive_file_watching_functionality"}},
    },
    CompilerOption{
        .name = "fallbackPolling",
        .short_name = "",
        .is_tsconfig_only = false,
        .value_type = "string",
        .accepted_values = {"FixedInterval", "PriorityInterval",
                            "DynamicPriority", "FixedChunkSize"},
        .default_values = {"PriorityInterval"},
        .meta_info = {{"category", "Watch_and_Build_Modes"},
                      {"Specify_what_approach_the_watcher_should_use_if_the_"
                       "system_runs_out_of_native_file_watchers",
                       "PriorityInterval"}},
    },
    CompilerOption{
        .name = "synchronousWatchDirectory",
        .short_name = "",
        .is_tsconfig_only = false,
        .value_type = "boolean",
        .accepted_values = {"true", "false", "null"},
        .default_values = {"false"},
        .meta_info = {{"category", "Watch_and_Build_Modes"},
                      {"description",
                       "Synchronously_call_callbacks_and_update_the_state_of_"
                       "directory_watchers_on_platforms_that_don_t_support_"
                       "recursive_watching_natively"}},
    },
    CompilerOption{
        .name = "excludeDirectories",
        .short_name = "",
        .is_tsconfig_only = false,
        .value_type = "list",
        .accepted_values = {},
        .default_values = {},
        .meta_info = {{"isFilePath", "true"},
                      {"extraValidation", "specToDiagnostic"},
                      {"allowConfigDirTemplateSubstitution", "true"},
                      {"category", "Watch_and_Build_Modes"},
                      {"description",
                       "Remove_a_list_of_directories_from_the_watch_process"}},
    },
    CompilerOption{
        .name = "excludeFiles",
        .short_name = "",
        .is_tsconfig_only = false,
        .value_type = "list",
        .accepted_values = {},
        .default_values = {},
        .meta_info =
            {{"isFilePath", "true"},
             {"extraValidation", "specToDiagnostic"},
             {"allowConfigDirTemplateSubstitution", "true"},
             {"category", "Watch_and_Build_Modes"},
             {"description",
              "Remove_a_list_of_files_from_the_watch_mode_s_processing"}},
    },

};
