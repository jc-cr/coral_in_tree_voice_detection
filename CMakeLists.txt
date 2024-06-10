
add_executable_m7(coral_in_tree_voice_detection
    src/blink_serial.cc
)

target_link_libraries(coral_in_tree_voice_detection
    libs_base-m7_freertos
)
