#pragma once

#include <unordered_map>
#include <string>

#include <glm/glm.hpp>

#include <math/vector3.h>

namespace wase::rendering
{
	enum ShaderType
	{
		SHADER,
		PROGRAM
	};

	class Shader
	{
	public:
		Shader(const char* vertexPath, const char* fragmentPath);

		/**
		 * Bind the shader
		 */
		void bind() const;

		/**
		 * Unbind the shader
		 */
		void unbind() const;
		
		/**
		 * Set an integer uniform
		 *
		 * @param name: the name of the uniform
		 * @param value: the value of the uniform
		 */
		void setInt(const char* name, int value) const;

		/**
		 * Set a float uniform
		 *
		 * @param name: the name of the uniform
		 * @param value: the value of the uniform
		 */
		void setFloat(const char* name, float value) const;

		/**
		 * Set a vec2 uniform
		 *
		 * @param name: the name of the uniform
		 * @param value: the value of the uniform
		 */
		void setVec2(const char* name, const wase::math::Vector3& value) const;

		/**
		 * Set a vec2 uniform
		 *
		 * @param name: the name of the uniform
		 * @param x: the x value of the uniform
		 * @param y: the y value of the uniform
		 */
		void setVec2(const char* name, float x, float y) const;

		/**
		 * Set a vec3 uniform
		 *
		 * @param name: the name of the uniform
		 * @param value: the value of the uniform
		 */
		void setVec3(const char* name, const wase::math::Vector3& value) const;

		/**
		 * Set a vec3 uniform
		 *
		 * @param name: the name of the uniform
		 * @param x: the x value of the uniform
		 * @param y: the y value of the uniform
		 * @param z: the z value of the uniform
		 */
		void setVec3(const char* name, float x, float y, float z) const;

		/**
		 * Set a mat2 uniform
		 *
		 * @param name: the name of the uniform
		 * @param mat: the value of the uniform
		 */
		void setMat2(const char* name, const glm::mat2& mat) const;

		/**
		 * Set a mat3 uniform
		 *
		 * @param name: the name of the uniform
		 * @param mat: the value of the uniform
		 */
		void setMat3(const char* name, const glm::mat3& mat) const;

		/**
		 * Set a mat4 uniform
		 *
		 * @param name: the name of the uniform
		 * @param mat: the value of the uniform
		 */
		void setMat4(const char* name, const glm::mat4& mat) const;

	private:
		/**
		 * Get the location of a uniform
		 * 
		 * @param name: the name of the uniform
		 * @return the location of the uniform
		 */
		int getUniformLocation(const std::string& name) const;

		/**
		 * Compile a shader
		 *
		 * @param shaderID: the ID of the shader
		 * @param shaderType: the type of shader
		 */
		void parseShader(const unsigned int shaderID, const ShaderType shaderType) const;

		unsigned int m_ID;
		mutable std::unordered_map<std::string, int> m_UniformLocations;
	};
}