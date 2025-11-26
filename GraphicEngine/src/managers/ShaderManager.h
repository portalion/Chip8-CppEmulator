#pragma once
#include "renderer/Shader.h"
#include "core/Base.h"
#include <unordered_map>
#include <string>
#include <memory>

enum class AvailableShaders
{
	Default = 0,
};

class ShaderBuilder;

class ShaderManager
{
private:
	ShaderManager();

	std::unordered_map<AvailableShaders, Ref<Shader>> shaders;

	Ref<Shader> AssignShader(AvailableShaders name, const ShaderBuilder& builder);
public:
	~ShaderManager() = default;
	ShaderManager(ShaderManager& other) = delete;
	void operator=(const ShaderManager&) = delete;

	static ShaderManager& GetInstance();

	Ref<Shader> GetShader(AvailableShaders name);
};