////////////////////////////////////////////////////////////////////////////////
//
// Textures (small example for 2D textures)
//
// Copyright (c)2022-23 by Carlos Martinho
//
////////////////////////////////////////////////////////////////////////////////

#ifndef MGL_TEXTURE_HPP
#define MGL_TEXTURE_HPP

#include <iostream>
#include <string>

#include "mglSampler.hpp"
#include "mglShader.hpp"

namespace mgl {

	class Texture;
	class Texture2D;
	struct TextureInfo;

	//////////////////////////////////////////////////////////////////////// TEXTURE

	class Texture {
	protected:


	public:
		GLuint id;
		int texWidth;
		int texHeight;

		Texture();
		~Texture();
		virtual void bind() = 0;
		virtual void unbind() = 0;
	};

	//////////////////////////////////////////////////////////////////// TextureInfo

	struct TextureInfo {
		GLenum unit;                // GL_TEXTUREi
		GLuint index;               // sampler index in shader
		std::string uniform;        // uniform name in shader
		Texture* texture = nullptr; // Texture (engine object)
		Sampler* sampler = nullptr; // Sampler (engine object)

		TextureInfo(GLenum textureunit, GLuint index, const std::string& uniform,
			Texture* texture, Sampler* sampler);
		void updateShader(ShaderProgram* shader);
	};

	/////////////////////////////////////////////////////////////////////// TEXTURES

	class Texture2D : public Texture {
	public:
		void bind() override;
		void unbind() override;
		void load(const std::string& filename);
		void PerlinNoise2D();
	};

	////////////////////////////////////////////////////////////////////////////////
} // namespace mgl

#endif /* MGL_TEXTURE_HPP */
