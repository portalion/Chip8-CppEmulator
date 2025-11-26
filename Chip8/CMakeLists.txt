project (Chip8)

add_executable(${PROJECT_NAME}
	"src/chip8-Emulator.cpp"
	 )

set_property(TARGET ${PROJECT_NAME} PROPERTY CXX_STANDARD 20)

target_link_libraries (${PROJECT_NAME} 
	graphicEngine 
)
