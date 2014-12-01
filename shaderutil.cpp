/* Copyright 2011 Pyarelal Knowles, under GNU LGPL (see LICENCE.txt) */

#include "prec.h"

#include "shaderutil.h"

#include "camera.h"
#include "matrix.h"
#include "util.h"

#include "shader.h"

#include <GL/glew.h>

const char* getFormatString(GLenum format)
{
	switch (format)
	{
	case GL_RED: return "GL_RED";
	case GL_LUMINANCE: return "GL_LUMINANCE";
	case GL_DEPTH_COMPONENT: return "GL_DEPTH_COMPONENT";
	case GL_DEPTH_COMPONENT16: return "GL_DEPTH_COMPONENT16";
	case GL_LUMINANCE_ALPHA: return "GL_LUMINANCE_ALPHA";
	case GL_BGR: return "GL_BGR";
	case GL_RGB: return "GL_RGB";
	case GL_DEPTH_COMPONENT24: return "GL_DEPTH_COMPONENT24";
	case GL_BGRA: return "GL_BGRA";
	case GL_RGBA: return "GL_RGBA";
	case GL_RGBA8: return "GL_RGBA8";
	case GL_DEPTH_COMPONENT32: return "GL_DEPTH_COMPONENT32";
	case GL_DEPTH_COMPONENT32F: return "GL_DEPTH_COMPONENT32F";
	case GL_DEPTH24_STENCIL8: return "GL_DEPTH24_STENCIL8";
	case GL_R32F: return "GL_R32F";
	case GL_R32I: return "GL_R32I";
	case GL_R32UI: return "GL_R32UI";
	case GL_RG32F: return "GL_RG32F";
	case GL_RG32I: return "GL_RG32I";
	case GL_RG32UI: return "GL_RG32UI";
	case GL_RGB32F: return "GL_RGB32F";
	case GL_RGB32I: return "GL_RGB32I";
	case GL_RGB32UI: return "GL_RGB32UI";
	case GL_RGBA32F: return "GL_RGBA32F";
	case GL_RGBA32I: return "GL_RGBA32I";
	case GL_RGBA32UI: return "GL_RGBA32UI";
	default: return "unknown_tex_fmt";
	}
}

GLenum defaultFormat(int cpp)
{
	switch (cpp)
	{
	case 1:
		return GL_RED;
	case 2:
		return GL_LUMINANCE_ALPHA;
	case 3:
		return GL_RGB;
	case 4:
		return GL_RGBA;
	default:
		return GL_RGBA;
	}
}

int bytesPerPixel(GLenum format)
{
	//FIXME: use something like glGetTexLevelParameterfv

	switch (format)
	{
	case GL_RED:
	case GL_LUMINANCE:
	case GL_DEPTH_COMPONENT:
		return 1;
	case GL_DEPTH_COMPONENT16:
	case GL_LUMINANCE_ALPHA:
		return 2;
	case GL_BGR:
	case GL_RGB:
	case GL_DEPTH_COMPONENT24:
		return 3;
	case GL_BGRA:
	case GL_RGBA:
	case GL_RGBA8:
	case GL_DEPTH_COMPONENT32:
	case GL_DEPTH_COMPONENT32F:
	case GL_DEPTH24_STENCIL8:
		return 4;
	case GL_R32F:
	case GL_R32I:
	case GL_R32UI:
		return 4;
	case GL_RGBA16F:
	case GL_RGBA16I:
	case GL_RGBA16UI:
	case GL_RG32F:
	case GL_RG32I:
	case GL_RG32UI:
		return 8;
	case GL_RGB32F:
	case GL_RGB32I:
	case GL_RGB32UI:
		return 12;
	case GL_RGBA32F:
	case GL_RGBA32I:
	case GL_RGBA32UI:
		return 16;
	default:
		printf("Unknown format in shaderutil.cpp:bytesPerPixel()\n");
		return 4;
	}
}

int channelsPerPixel(GLenum format)
{
	switch (format)
	{
	case GL_RED:
	case GL_R16F:
	case GL_R16I:
	case GL_R16UI:
	case GL_R32F:
	case GL_R32I:
	case GL_R32UI:
	case GL_LUMINANCE:
	case GL_DEPTH_COMPONENT:
	case GL_DEPTH_COMPONENT16:
	case GL_DEPTH_COMPONENT24:
	case GL_DEPTH_COMPONENT32:
		return 1;
	case GL_LUMINANCE_ALPHA:
	case GL_RG:
	case GL_RG8:
	case GL_RG16F:
	case GL_RG16I:
	case GL_RG16UI:
	case GL_RG32F:
	case GL_RG32I:
	case GL_RG32UI:
		return 2;
	case GL_BGR:
	case GL_RGB:
	case GL_RGB16F:
	case GL_RGB16I:
	case GL_RGB16UI:
	case GL_RGB32F:
	case GL_RGB32I:
	case GL_RGB32UI:
		return 3;
	case GL_BGRA:
	case GL_RGBA:
	case GL_RGBA8:
	case GL_RGBA16F:
	case GL_RGBA16I:
	case GL_RGBA16UI:
	case GL_RGBA32F:
	case GL_RGBA32I:
	case GL_RGBA32UI:
		return 4;
	case GL_DEPTH24_STENCIL8: //???
		return 4;
	default:
		printf("Unknown format in shaderutil.cpp:channelsPerPixel()\n");
		return 4;
	}
}

GLenum getTextureBaseType(GLenum format)
{
	switch (format)
	{
	case GL_RED:
	case GL_RG:
	case GL_RGB:
	case GL_RGBA:
	case GL_R8:
	case GL_RG8:
	case GL_RGB8:
	case GL_RGBA8:
	case GL_R8UI:
	case GL_RG8UI:
	case GL_RGB8UI:
	case GL_RGBA8UI:
		return GL_UNSIGNED_BYTE;
	case GL_R8I:
	case GL_RG8I:
	case GL_RGB8I:
	case GL_RGBA8I:
		return GL_BYTE;
	case GL_R16:
	case GL_RG16:
	case GL_RGB16:
	case GL_RGBA16:
	case GL_R16UI:
	case GL_RG16UI:
	case GL_RGB16UI:
	case GL_RGBA16UI:
		return GL_UNSIGNED_SHORT;
	case GL_R16I:
	case GL_RG16I:
	case GL_RGB16I:
	case GL_RGBA16I:
		return GL_SHORT;
	case GL_R16F:
	case GL_RG16F:
	case GL_RGB16F:
	case GL_RGBA16F:
		return GL_HALF_FLOAT; //FIXME: is this right??
	case GL_R32F:
	case GL_RG32F:
	case GL_RGB32F:
	case GL_RGBA32F:
		return GL_FLOAT;
	case GL_R32I:
	case GL_RG32I:
	case GL_RGB32I:
	case GL_RGBA32I:
		return GL_INT;
	case GL_R32UI:
	case GL_RG32UI:
	case GL_RGB32UI:
	case GL_RGBA32UI:
		return GL_UNSIGNED_INT;
	default:
		return 0;
	}
}

GLenum getUniformBaseType(GLenum format)
{
	switch (format)
	{
	case GL_BOOL:
	case GL_BOOL_VEC2:
	case GL_BOOL_VEC3:
	case GL_BOOL_VEC4:
		return GL_BOOL;
	case GL_DOUBLE:
	case GL_DOUBLE_VEC2:
	case GL_DOUBLE_VEC3:
	case GL_DOUBLE_VEC4:
	case GL_DOUBLE_MAT2:
	case GL_DOUBLE_MAT3:
	case GL_DOUBLE_MAT4:
	case GL_DOUBLE_MAT2x3:
	case GL_DOUBLE_MAT2x4:
	case GL_DOUBLE_MAT3x2:
	case GL_DOUBLE_MAT3x4:
	case GL_DOUBLE_MAT4x2:
	case GL_DOUBLE_MAT4x3:
		return GL_DOUBLE;
	case GL_FLOAT:
	case GL_FLOAT_VEC2:
	case GL_FLOAT_VEC3:
	case GL_FLOAT_VEC4:
	case GL_FLOAT_MAT2:
	case GL_FLOAT_MAT3:
	case GL_FLOAT_MAT4:
	case GL_FLOAT_MAT2x3:
	case GL_FLOAT_MAT2x4:
	case GL_FLOAT_MAT3x2:
	case GL_FLOAT_MAT3x4:
	case GL_FLOAT_MAT4x2:
	case GL_FLOAT_MAT4x3:
	case GL_SAMPLER_1D:
	case GL_SAMPLER_2D:
	case GL_SAMPLER_3D:
	case GL_SAMPLER_CUBE:
	case GL_SAMPLER_1D_SHADOW:
	case GL_SAMPLER_2D_SHADOW:
	case GL_SAMPLER_1D_ARRAY:
	case GL_SAMPLER_2D_ARRAY:
	case GL_SAMPLER_1D_ARRAY_SHADOW:
	case GL_SAMPLER_2D_ARRAY_SHADOW:
	case GL_SAMPLER_2D_MULTISAMPLE:
	case GL_SAMPLER_2D_MULTISAMPLE_ARRAY:
	case GL_SAMPLER_CUBE_SHADOW:
	case GL_SAMPLER_BUFFER:
	case GL_SAMPLER_2D_RECT:
	case GL_SAMPLER_2D_RECT_SHADOW:
	case GL_IMAGE_1D:
	case GL_IMAGE_BUFFER:
	case GL_IMAGE_2D:
	case GL_IMAGE_3D:
	case GL_IMAGE_2D_RECT:
	case GL_IMAGE_CUBE:
	case GL_IMAGE_1D_ARRAY:
	case GL_IMAGE_2D_ARRAY:
	case GL_IMAGE_2D_MULTISAMPLE:
	case GL_IMAGE_2D_MULTISAMPLE_ARRAY:
		return GL_FLOAT;
	case GL_INT:
	case GL_INT_VEC2:
	case GL_INT_VEC3:
	case GL_INT_VEC4:
	case GL_INT_SAMPLER_1D:
	case GL_INT_SAMPLER_2D:
	case GL_INT_SAMPLER_3D:
	case GL_INT_SAMPLER_CUBE:
	case GL_INT_SAMPLER_1D_ARRAY:
	case GL_INT_SAMPLER_2D_ARRAY:
	case GL_INT_SAMPLER_2D_MULTISAMPLE:
	case GL_INT_SAMPLER_2D_MULTISAMPLE_ARRAY:
	case GL_INT_SAMPLER_BUFFER:
	case GL_INT_SAMPLER_2D_RECT:
	case GL_INT_IMAGE_1D:
	case GL_INT_IMAGE_2D:
	case GL_INT_IMAGE_3D:
	case GL_INT_IMAGE_2D_RECT:
	case GL_INT_IMAGE_CUBE:
	case GL_INT_IMAGE_BUFFER:
	case GL_INT_IMAGE_1D_ARRAY:
	case GL_INT_IMAGE_2D_ARRAY:
	case GL_INT_IMAGE_2D_MULTISAMPLE:
	case GL_INT_IMAGE_2D_MULTISAMPLE_ARRAY:
		return GL_INT;
	case GL_UNSIGNED_INT:
	case GL_UNSIGNED_INT_VEC2:
	case GL_UNSIGNED_INT_VEC3:
	case GL_UNSIGNED_INT_VEC4:
	case GL_UNSIGNED_INT_SAMPLER_1D:
	case GL_UNSIGNED_INT_SAMPLER_2D:
	case GL_UNSIGNED_INT_SAMPLER_3D:
	case GL_UNSIGNED_INT_SAMPLER_CUBE:
	case GL_UNSIGNED_INT_SAMPLER_1D_ARRAY:
	case GL_UNSIGNED_INT_SAMPLER_2D_ARRAY:
	case GL_UNSIGNED_INT_SAMPLER_2D_MULTISAMPLE:
	case GL_UNSIGNED_INT_SAMPLER_2D_MULTISAMPLE_ARRAY:
	case GL_UNSIGNED_INT_SAMPLER_BUFFER:
	case GL_UNSIGNED_INT_SAMPLER_2D_RECT:
	case GL_UNSIGNED_INT_IMAGE_1D:
	case GL_UNSIGNED_INT_IMAGE_2D:
	case GL_UNSIGNED_INT_IMAGE_3D:
	case GL_UNSIGNED_INT_IMAGE_2D_RECT:
	case GL_UNSIGNED_INT_IMAGE_CUBE:
	case GL_UNSIGNED_INT_IMAGE_BUFFER:
	case GL_UNSIGNED_INT_IMAGE_1D_ARRAY:
	case GL_UNSIGNED_INT_IMAGE_2D_ARRAY:
	case GL_UNSIGNED_INT_IMAGE_2D_MULTISAMPLE:
	case GL_UNSIGNED_INT_IMAGE_2D_MULTISAMPLE_ARRAY:
	case GL_UNSIGNED_INT_ATOMIC_COUNTER:
		return GL_UNSIGNED_INT;
	default:
		return 0;
	}
}

bool isTextureTypeLayered(GLenum type)
{
	switch (type)
	{
	case GL_TEXTURE_3D:
	case GL_TEXTURE_1D_ARRAY:
	case GL_TEXTURE_2D_ARRAY:
	case GL_TEXTURE_CUBE_MAP_ARRAY:
	case GL_TEXTURE_CUBE_MAP:
	case GL_TEXTURE_2D_MULTISAMPLE_ARRAY:
		return true;
	
	case GL_TEXTURE_1D:
	case GL_TEXTURE_2D:
	case GL_TEXTURE_RECTANGLE:
	case GL_TEXTURE_BUFFER:
	case GL_TEXTURE_2D_MULTISAMPLE:
	default:
		return false;
	}
}

bool matchImageUnitFormat(GLenum imageFormat, GLenum uniformFormat, GLint size)
{
	if (size != 1)
		return false;
	GLenum texBase = getTextureBaseType(imageFormat);
	if (texBase == 0 || texBase != getUniformBaseType(uniformFormat))
		return false;
	return true;
}

bool loadGlewExtensions()
{
	#ifdef WIN32
	//load fbo extension
	glGenFramebuffersEXT = (PFNGLGENFRAMEBUFFERSEXTPROC)wglGetProcAddress("glGenFramebuffersEXT");
	glBindFramebufferEXT = (PFNGLBINDFRAMEBUFFEREXTPROC)wglGetProcAddress("glBindFramebufferEXT");
	glFramebufferTexture2DEXT = (PFNGLFRAMEBUFFERTEXTURE2DEXTPROC)wglGetProcAddress("glFramebufferTexture2DEXT");
	glFramebufferRenderbufferEXT = (PFNGLFRAMEBUFFERRENDERBUFFEREXTPROC)wglGetProcAddress("glFramebufferRenderbufferEXT");
	glCheckFramebufferStatusEXT	= (PFNGLCHECKFRAMEBUFFERSTATUSEXTPROC)wglGetProcAddress("glCheckFramebufferStatusEXT");
	glDeleteFramebuffersEXT = (PFNGLDELETEFRAMEBUFFERSEXTPROC)wglGetProcAddress("glDeleteFramebuffersEXT");
	glGetFramebufferAttachmentParameterivEXT = (PFNGLGETFRAMEBUFFERATTACHMENTPARAMETERIVEXTPROC)wglGetProcAddress("glGetFramebufferAttachmentParameterivEXT");

	//load rb extension
	glGenRenderbuffersEXT = (PFNGLGENRENDERBUFFERSEXTPROC)wglGetProcAddress("glGenRenderbuffersEXT");
	glDeleteRenderbuffersEXT = (PFNGLDELETERENDERBUFFERSEXTPROC)wglGetProcAddress("glDeleteRenderbuffersEXT");
	glBindRenderbufferEXT = (PFNGLBINDRENDERBUFFEREXTPROC)wglGetProcAddress("glBindRenderbufferEXT");
	glRenderbufferStorageEXT = (PFNGLRENDERBUFFERSTORAGEEXTPROC)wglGetProcAddress("glRenderbufferStorageEXT");
	glGetRenderbufferParameterivEXT = (PFNGLGETRENDERBUFFERPARAMETERIVEXTPROC)wglGetProcAddress("glGetRenderbufferParameterivEXT");
	glIsRenderbufferEXT = (PFNGLISRENDERBUFFEREXTPROC)wglGetProcAddress("glIsRenderbufferEXT");

	//load image texture extensions
	glBindImageTextureEXT = (PFNGLBINDIMAGETEXTUREEXTPROC)wglGetProcAddress("glBindImageTextureEXT");
	#endif
	
	return true;
}

void _setActiveTexture(int i, const char* name, GLuint tex, GLuint target, int line)
{
	GLint program = 0;
	glGetIntegerv(GL_CURRENT_PROGRAM, &program);
	if (program == 0)
	{
		//printf("Error on line %i: no program active when setting texture\n", line);
		return;
	}
	glActiveTexture(GL_TEXTURE0 + i);
	glBindTexture(target, tex);
	GLuint location = glGetUniformLocation(program, name);
	//printf("%s i=%i t=%i l=%i\n", name, i, tex, location);
	if (location != (GLuint)-1)
		glUniform1i(location, i);
	//else
	//	printf("Error: no uniform found - %s\n", name);
	glActiveTexture(GL_TEXTURE0);
}

void genCubePerspective(mat44 modelviewProjection[6], float n, float f)
{
	Camera c;
	c.setDistance(n, f);
	c.setPerspective(pi*0.5f);
	c.regenProjection();
	
	mat44 flipx = mat44::scale(-1.0f, -1.0f, 1.0f);
	mat44 flipy = mat44::scale(1.0f, -1.0f, -1.0f);
	c.setRotation(vec2f(0.0f, -pi*0.5f)); c.regenCamera(); modelviewProjection[0] = c.getProjection() * flipx * c.getInverse();
	c.setRotation(vec2f(0.0f, pi*0.5f)); c.regenCamera(); modelviewProjection[1] = c.getProjection() * flipx * c.getInverse();
	c.setRotation(vec2f(-pi*0.5f, 0.0f)); c.regenCamera(); modelviewProjection[2] = c.getProjection() * flipy * c.getInverse();
	c.setRotation(vec2f(pi*0.5f, 0.0f)); c.regenCamera(); modelviewProjection[3] = c.getProjection() * flipy * c.getInverse();
	c.setRotation(vec2f(0.0f, pi)); c.regenCamera(); modelviewProjection[4] = c.getProjection() * flipx * c.getInverse();
	c.setRotation(vec2f(0.0f, 0.0f)); c.regenCamera(); modelviewProjection[5] = c.getProjection() * flipx * c.getInverse();
}

void genCubeDirections(mat44 modelview[6])
{
	Camera c;
	mat44 flipx = mat44::scale(-1.0f, -1.0f, 1.0f);
	mat44 flipy = mat44::scale(1.0f, -1.0f, -1.0f);
	c.setRotation(vec2f(0.0f, -pi*0.5f)); c.regenCamera(); modelview[0] = flipx * c.getInverse();
	c.setRotation(vec2f(0.0f, pi*0.5f)); c.regenCamera(); modelview[1] = flipx * c.getInverse();
	c.setRotation(vec2f(-pi*0.5f, 0.0f)); c.regenCamera(); modelview[2] = flipy * c.getInverse();
	c.setRotation(vec2f(pi*0.5f, 0.0f)); c.regenCamera(); modelview[3] = flipy * c.getInverse();
	c.setRotation(vec2f(0.0f, pi)); c.regenCamera(); modelview[4] = flipx * c.getInverse();
	c.setRotation(vec2f(0.0f, 0.0f)); c.regenCamera(); modelview[5] = flipx * c.getInverse();
}

void drawSSQuad(vec2i size)
{
	drawSSQuad(size.x, size.y, 1);
}
void drawSSQuad(vec3i size)
{
	drawSSQuad(size.x, size.y, size.z);
}
void drawSSQuad(int w, int h, int layers)
{
	static bool hasInit = false;
	static GLuint quadVBO = 0;
	static Camera camera;
	static mat44 cubeInvDirs[6];

	if (w < 0 || h < 0)
	{
		int vp[4];
		glGetIntegerv(GL_VIEWPORT, vp);
		if (w < 0) w = vp[2];
		if (h < 0) h = vp[3];
	}

	static const float verts[] = {
		-1.0, -1.0, 0.0,
		3.0, -1.0, 0.0,
		-1.0, 3.0, 0.0,
		};
	glPushAttrib(GL_VIEWPORT_BIT);
	glViewport(0, 0, w, h);
	
	if (!hasInit)
	{
		hasInit = true;
		glGenBuffers(1, &quadVBO);
		glBindBuffer(GL_ARRAY_BUFFER, quadVBO);
		glBufferData(GL_ARRAY_BUFFER, sizeof(verts), verts, GL_STATIC_DRAW);
		camera.setOrthographic(1.0);
		camera.setDistance(-1.0, 1.0);
		camera.regen();

		genCubeDirections(cubeInvDirs);
		for (int i = 0; i < 6; ++i)
			cubeInvDirs[i] = cubeInvDirs[i].inverse();
	}
	else
	{
		glBindBuffer(GL_ARRAY_BUFFER, quadVBO);
	}

	//get attribs and draw verts
	GLint program = 0;
	glGetIntegerv(GL_CURRENT_PROGRAM, &program);
	
	//printf("quad %ix%i %s\n", w, h, Shader::get(program)->name().c_str());
	
	GLuint vertLoc = glGetAttribLocation(program, "osVert");
	GLuint pjLoc = glGetUniformLocation(program, "projectionMat");
	GLuint mvLoc = glGetUniformLocation(program, "modelviewMat");
	GLuint dirsLoc = glGetUniformLocation(program, "inverseCubeMats");
	if (pjLoc != (GLuint)-1)
		glUniformMatrix4fv(pjLoc, 1, GL_FALSE, camera.getProjection().m);
	if (mvLoc != (GLuint)-1)
		glUniformMatrix4fv(mvLoc, 1, GL_FALSE, camera.getInverse().m);
	if (dirsLoc != (GLuint)-1)
		glUniformMatrix4fv(dirsLoc, 6, GL_FALSE, (GLfloat*)cubeInvDirs);
	if (vertLoc == (GLuint)-1)
	{
		vertLoc = 0;
		if (Shader::globalCompileError == 0)
			printf("Error: no osVert in shader %i\n", program);
	}
	glVertexAttribPointer(vertLoc, 3, GL_FLOAT, GL_FALSE, 0, 0);
	glEnableVertexAttribArray(vertLoc);

	if (layers > 1)
		glDrawArraysInstanced(GL_TRIANGLES, 0, 3, layers);
	else
		glDrawArrays(GL_TRIANGLES, 0, 3);

	glDisableVertexAttribArray(vertLoc);
	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glPopAttrib();
}
void drawCube()
{
	static bool hasInit = false;
	static GLuint cubeVBO[2] = {0, 0};
	static Camera camera;

	static const float verts[] = {
		-1.0, -1.0, -0.0,
		 1.0, -1.0, -0.0,
		 1.0, -1.0,  0.0,
		-1.0, -1.0,  0.0,
		-1.0,  1.0, -0.0,
		 1.0,  1.0, -0.0,
		 1.0,  1.0,  0.0,
		-1.0,  1.0,  0.0,
		};
	static const unsigned int indices[] = {
		0, 2, 1, 0, 3, 2, //bottom
		1, 5, 5, 1, 4, 0, //back
		2, 6, 5, 2, 5, 1, //right
		3, 7, 6, 3, 6, 2, //front
		0, 4, 7, 0, 7, 3, //left
		4, 5, 6, 4, 6, 7 //top
		};

	if (!hasInit)
	{
		hasInit = true;
		glGenBuffers(2, cubeVBO);
		glBindBuffer(GL_ARRAY_BUFFER, cubeVBO[0]);
		glBufferData(GL_ARRAY_BUFFER, sizeof(verts), verts, GL_STATIC_DRAW);
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, cubeVBO[1]);
		glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);
		camera.setOrthographic(1.0);
		camera.setDistance(-1.0, 1.0);
		camera.regen();
	}
	else
	{
		glBindBuffer(GL_ARRAY_BUFFER, cubeVBO[0]);
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, cubeVBO[1]);
	}

	//get attribs and draw verts
	GLint program = 0;
	glGetIntegerv(GL_CURRENT_PROGRAM, &program);
	GLuint vertLoc = glGetAttribLocation(program, "osVert");
	GLuint pjLoc = glGetUniformLocation(program, "projectionMat");
	GLuint mvLoc = glGetUniformLocation(program, "modelviewMat");
	if (pjLoc != (GLuint)-1)
		glUniformMatrix4fv(pjLoc, 1, GL_FALSE, camera.getProjection().m);
	if (mvLoc != (GLuint)-1)
		glUniformMatrix4fv(mvLoc, 1, GL_FALSE, camera.getInverse().m);
	if (vertLoc == (GLuint)-1)
	{
		vertLoc = 0;
		printf("Warning: No osVert in shader for drawSSQuad()\n");
	}
	glVertexAttribPointer(vertLoc, 3, GL_FLOAT, GL_FALSE, 0, 0);
	glEnableVertexAttribArray(vertLoc);
	glDrawElements(GL_TRIANGLES, 36, GL_UNSIGNED_INT, 0);

	glDisableVertexAttribArray(vertLoc);
	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
}
