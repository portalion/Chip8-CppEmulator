project (graphicEngine)

add_library (${PROJECT_NAME}
	"src/renderer/Shader.cpp"
	"src/renderer/IndexBuffer.cpp"
	"src/renderer/ShaderBuilder.cpp"
	"src/renderer/VertexArray.cpp"
	"src/renderer/VertexBuffer.cpp"
	"src/managers/ShaderManager.h" 
	"src/managers/ShaderManager.cpp" 
	"src/utils/GlCall.cpp"
	"src/utils/Initialization.cpp" 
	"src/core/Base.h"   
	"src/core/BaseApp.h"
	"src/core/BaseApp.cpp"
	"src/core/Window.h"
	"src/core/Window.cpp" )

set_property(TARGET ${PROJECT_NAME} PROPERTY CXX_STANDARD 20)

target_include_directories (${PROJECT_NAME} 
PUBLIC
	${PROJECT_SOURCE_DIR}/src
	${CMAKE_SOURCE_DIR}/external/glfw/include
	${CMAKE_SOURCE_DIR}/external/glew/include
	${CMAKE_SOURCE_DIR}/external/glm
	${CMAKE_SOURCE_DIR}/external/imgui

)

target_link_libraries(${PROJECT_NAME} 
	glfw 
	libglew_static
	glm
	imgui
)

add_custom_target(copy_resources ALL
	COMMAND ${CMAKE_COMMAND} -E copy_directory
	${PROJECT_SOURCE_DIR}/Resources
	${PROJECT_BINARY_DIR}/Resources
	COMMENT "Copying resources into binary directory")

add_dependencies(${PROJECT_NAME} copy_resources)