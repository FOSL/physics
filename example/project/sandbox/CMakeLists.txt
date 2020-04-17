project(sandbox)

set(PROJECT_SOURCE_DIR ${PROJECT_SOURCE_DIR}/source)

add_executable(sandbox.elf)
target_sources(sandbox.elf
	PRIVATE
		${PROJECT_SOURCE_DIR}/main.cpp
)
target_include_directories(sandbox.elf
	PRIVATE
		${PROJECT_SOURCE_DIR}
)
target_link_libraries(sandbox.elf
	PRIVATE
		FOSL::physics
)
