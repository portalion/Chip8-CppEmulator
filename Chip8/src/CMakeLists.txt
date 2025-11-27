add_library(${PROJECT_NAME} 
	 "Chip8-Emulator.cpp"
	 "Chip8-Emulator.h"
)
set_property(TARGET ${PROJECT_NAME} PROPERTY CXX_STANDARD 20)

add_executable(${PROJECT_NAME}-Runtime
	 "main.cpp")

target_link_libraries (${PROJECT_NAME} 
	 graphicEngine 
)