#pragma once
#include <unordered_map>
#include <string>
#include <memory>
#include "Shader.h"
#include "core/Base.h"

class ShaderBuilder
{
private:
	std::unordered_map<ShaderType, std::string> shaderSourceCodes;
	std::string resourceDirectory;
	unsigned int patchSize = 4;

	std::stringstream ParseShaderCode(const std::string& filename);
public:
	ShaderBuilder(const std::string& resourceDirectory);
	ShaderBuilder& AddShader(ShaderType type, const std::string& filename);
	ShaderBuilder& ChangePatchSize(unsigned int patchSize);

	Shader Build() const;
	Ref<Shader> BuildShared() const;
};