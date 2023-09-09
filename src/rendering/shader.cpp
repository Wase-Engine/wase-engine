#include <GL/glew.h>
#include <glm/gtc/type_ptr.hpp>

#include <rendering/shader.h>
#include <debugging/log.h>
#include <io/reading.h>

namespace wase::rendering
{
	Shader::Shader(const char* vertexPath, const char* fragmentPath)
	{
		std::string vertexCode = wase::io::readFile(vertexPath);
		std::string fragmentCode = wase::io::readFile(fragmentPath);

		const char* vertexShaderCode = vertexCode.c_str();
		const char* fragmentShaderCode = fragmentCode.c_str();

		unsigned int vertex, fragment;

		// Vertex shader compilation
		vertex = glCreateShader(GL_VERTEX_SHADER);

		glShaderSource(vertex, 1, &vertexShaderCode, NULL);
		glCompileShader(vertex);

		parseShader(vertex, ShaderType::SHADER);

		// Fragment shader compilation
		fragment = glCreateShader(GL_FRAGMENT_SHADER);

		glShaderSource(fragment, 1, &fragmentShaderCode, NULL);
		glCompileShader(fragment);

		parseShader(fragment, ShaderType::SHADER);

		// Shader program linking
		m_ID = glCreateProgram();

		glAttachShader(m_ID, vertex);
		glAttachShader(m_ID, fragment);
		glLinkProgram(m_ID);

		parseShader(m_ID, ShaderType::PROGRAM);

		glDeleteShader(vertex);
		glDeleteShader(fragment);
	}

	void Shader::bind() const
	{
		glUseProgram(m_ID);
	}

	void Shader::unbind()
	{
		glUseProgram(0);
	}

	void Shader::setInt(const char* name, int value) const
	{
		glUniform1i(getUniformLocation(name), value);
	}

	void Shader::setFloat(const char* name, float value) const
	{
		glUniform1f(getUniformLocation(name), value);
	}

	void Shader::setVec2(const char* name, const wase::math::Vector3& value) const
	{
		glUniform2f(getUniformLocation(name), value.x, value.y);
	}

	void Shader::setVec2(const char* name, float x, float y) const
	{
		glUniform2f(getUniformLocation(name), x, y);
	}

	void Shader::setVec3(const char* name, const wase::math::Vector3& value) const
	{
		glUniform3f(getUniformLocation(name), value.x, value.y, value.z);
	}

	void Shader::setVec3(const char* name, float x, float y, float z) const
	{
		glUniform3f(getUniformLocation(name), x, y, z);
	}

	void Shader::setMat2(const char* name, const glm::mat2& mat) const
	{
		glUniformMatrix2fv(getUniformLocation(name), 1, false, glm::value_ptr(mat));
	}

	void Shader::setMat3(const char* name, const glm::mat3& mat) const
	{
		glUniformMatrix3fv(getUniformLocation(name), 1, false, glm::value_ptr(mat));
	}

	void Shader::setMat4(const char* name, const glm::mat4& mat) const
	{
		glUniformMatrix4fv(getUniformLocation(name), 1, false, glm::value_ptr(mat));
	}

	int Shader::getUniformLocation(const std::string& name) const
	{
		if (m_UniformLocations.count(name))
			return m_UniformLocations[name];

		const int location = glGetUniformLocation(m_ID, name.c_str());

		m_UniformLocations[name] = location;

		return location;
	}

	void Shader::parseShader(const unsigned int shaderID, const ShaderType shaderType) const
	{
		int success;
		char infolog[1024];

		if (shaderType == ShaderType::SHADER)
			glGetShaderiv(shaderID, GL_COMPILE_STATUS, &success);
		else if (shaderType == ShaderType::PROGRAM)
			glGetShaderiv(shaderID, GL_LINK_STATUS, &success);

		if (!success)
		{
			if (shaderType == ShaderType::SHADER)
			{
				glGetShaderInfoLog(shaderID, 1024, NULL, infolog);
				WASE_CORE_WARN("Shader compilation failed");
			}
			else if (shaderType == ShaderType::PROGRAM)
			{
				glGetProgramInfoLog(shaderID, 1024, NULL, infolog);
				WASE_CORE_WARN("Failed to link shader program");
			}

			WASE_CORE_WARN(infolog);
		}
	}
}