target_sources(asteroids
        PRIVATE
                "${CMAKE_CURRENT_LIST_DIR}/sdl_keyboard.cc"
                "${CMAKE_CURRENT_LIST_DIR}/context.cc"
)

#target_include_directories(asteroids PRIVATE "${CMAKE_CURRENT_LIST_DIR}")
