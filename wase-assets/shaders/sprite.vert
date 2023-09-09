#version 330 core

layout (location = 0) in vec2 a_Pos;
layout (location = 1) in vec2 a_TexCoords;

uniform mat4 u_ViewProjection;
uniform mat4 u_Model;

out vec2 v_TexCoords;

void main()
{
    gl_Position = u_ViewProjection * u_Model * vec4(a_Pos.xy, 0.0, 1.0);
	v_TexCoords = a_TexCoords;
}