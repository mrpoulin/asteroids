target_sources(asteroids
        PRIVATE
                "${CMAKE_CURRENT_LIST_DIR}/input_system.cc"
                "${CMAKE_CURRENT_LIST_DIR}/physics_system.cc"
                "${CMAKE_CURRENT_LIST_DIR}/rendering_system.cc"
)

#target_include_directories(asteroids PRIVATE "${CMAKE_CURRENT_LIST_DIR}")
