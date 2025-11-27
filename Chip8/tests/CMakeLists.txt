if (BUILD_TESTING)
	enable_testing()
	add_executable(Chip8-tests
		"exampleTest.cpp"
	)

	target_link_libraries(Chip8-tests
		PRIVATE
		GTest::gmock_main
		Chip8
	)

	target_include_directories(Chip8-tests
		PRIVATE ${PROJECT_SOURCE_DIR}/src
	)

	include(GoogleTest)
	gtest_discover_tests(Chip8-tests)
endif()
