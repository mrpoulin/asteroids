target_sources(asteroids
	PRIVATE
		"${CMAKE_CURRENT_LIST_DIR}/component.cc"
		"${CMAKE_CURRENT_LIST_DIR}/screen_position_component.cc"
		"${CMAKE_CURRENT_LIST_DIR}/sprite_component.cc"
		"${CMAKE_CURRENT_LIST_DIR}/bounding_box_component.cc"
)

#target_include_directories(asteroids PRIVATE "${CMAKE_CURRENT_LIST_DIR}")
