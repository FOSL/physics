include(SimpleFOSLProjectTest)

find_package(FOSL
	COMPONENTS
		physics
	REQUIRED
)

project(unsorted)

add_executable(unsorted)
target_sources(unsorted
	PRIVATE
		${PROJECT_SOURCE_DIR}/main.cpp
)
target_link_libraries(unsorted
	PRIVATE
		FOSL::physics
)
