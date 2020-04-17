option(FOSL_PHYSICS "Build FOSL::physics" ON)
if(FOSL_PHYSICS)
	# Simplification {{{
		set(CMAKE_MODULE_PATH
			"${CMAKE_MODULE_PATH}"
			"${CMAKE_CURRENT_SOURCE_DIR}/cmake/module/CMake_deployment/source")
		include(SimpleFOSLProject)
	# }}}

	project(physics # {{{
		VERSION 0.1.0.0
		LANGUAGES C CXX
	) # }}}
	add_library(physics)
	target_sources(physics # {{{
		PRIVATE
			physics.cpp
		PUBLIC
			physics.hpp
	) # }}}
	target_include_directories(${PROJECT_NAME} # {{{
	) # }}}
	target_link_libraries(physics # {{{
	) # }}}

	# Testing {{{
	if(${UPPERCASE_PROJECT_NAMESPACE}_${UPPERCASE_PROJECT_COMPONENT}_BUILD_TESTS)
# 		add_test(NAME types COMMAND ${PROJECT_BINARY_DIR}/test/unit/types/main.elf)
		add_subdirectory(test)
	endif() # }}}
	# Installation {{{
	if(FOSL_PHYSICS_INSTALL)
		install_project()
	endif() # }}}
endif()
