// STEP 7 - Vertex color defined by model space normal.
// Copyright (c) 2015-23 by Carlos Martinho

#version 330 core

uniform mat4 ModelMatrix;


uniform Camera {
	mat4 ViewMatrix;
	mat4 ProjectionMatrix;	
};

in vec3 inPosition;
in vec3 inNormal;
uniform vec3 inColor;
out vec3 exNormal;
out vec3 exColor;

void main(void)
{
	exNormal = inNormal;
	exColor = inColor;

	vec4 mcPosition = vec4(inPosition, 1.0);
	gl_Position = ProjectionMatrix * ViewMatrix * ModelMatrix * mcPosition;
}
