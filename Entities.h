//#pragma once
#ifndef _H_Entities_H_
#define _H_Entities_H_

#include <GL/freeglut.h>
#include <glm.hpp>
#include "Mesh.h"
#include "Texture.h"

//-------------------------------------------------------------------------

class Entity 
{
public:
  Entity() : modelMat(1.0) { };
  virtual ~Entity() { delete mesh; };

  virtual void render(glm::dmat4 const& modelViewMat);
  
protected:
  Texture texture;
  Mesh* mesh = nullptr;
  glm::dmat4 modelMat;
  virtual void draw();
  virtual void setMvM(glm::dmat4 const& modelViewMat);
};

//-------------------------------------------------------------------------

class EjesRGB : public Entity 
{
public:
  EjesRGB(GLdouble l);
  ~EjesRGB() { };
  virtual void draw();
};

//-------------------------------------------------------------------------

class Triangle : public Entity
{
public:
	Triangle(GLdouble l);
	~Triangle() { };
	virtual void draw();
};

class TriangleRGB : public Entity
{
public:
	TriangleRGB(GLdouble l);
	~TriangleRGB() { };
	virtual void draw();
};

class TriPyramid : public Entity
{
public:
	TriPyramid(GLdouble l, GLdouble h);
	~TriPyramid() { };
	virtual void draw();
};

class ContCubo : public Entity
{
public:
	ContCubo(GLdouble l);
	~ContCubo() { };
	virtual void draw();
};

class Diabolo : public Entity
{
public:
	Diabolo(GLdouble l, GLdouble h);
	~Diabolo() { };
	virtual void draw();
	virtual void render(glm::dmat4 const& modelViewMat);
	virtual void rotateZ();
private:
	GLdouble rotationZ;
	GLdouble side;
	GLdouble height;
};

class Cubo : public Entity
{
public:
	Cubo(GLdouble w, GLdouble h);
	~Cubo() { };
	virtual void draw();
	virtual void render(glm::dmat4 const& modelViewMat);
	Mesh* cubeMesh = nullptr;

private:
	GLdouble w;
	GLdouble h;
};

class Dragon : public Entity
{
public:
	Dragon(GLuint numVert);
	~Dragon() { };
	virtual void draw();
};

class Poliespiral : public Entity
{
public:
	Poliespiral(GLdouble verIniX, GLdouble verIniY, GLdouble angIni, GLdouble incrAng, GLdouble ladoIni, GLdouble incrLado, GLuint numVert);
	~Poliespiral() { };
	virtual void draw();
};

class Rectangulo : public Entity
{
public:
	Rectangulo(GLdouble w, GLdouble h);
	~Rectangulo() { };
	virtual void draw();
};

class RectanguloTex : public Entity
{
public:
	RectanguloTex(GLdouble w, GLdouble h, GLuint x, GLuint y);
	~RectanguloTex() { };
	virtual void draw();
};


class CuboTex : public Entity
{
public:
	CuboTex(GLdouble w, GLdouble h, GLuint x, GLuint y, GLdouble xt, GLdouble yt, GLdouble zt);
	CuboTex() { };
	virtual void draw();
	virtual void render(glm::dmat4 const& modelViewMat);
	Mesh* contCuboMesh = nullptr;

private:
	Texture intTex;
	GLdouble w;
	GLdouble h;
	GLdouble translateX;
	GLdouble translateY;
	GLdouble translateZ;
};

class TriPyramidTex : public Entity
{
public:
	TriPyramidTex(GLdouble w, GLdouble h);
	TriPyramidTex() { };
	virtual void draw();
};


class DiaboloTex : public Entity
{
public:
	DiaboloTex(GLdouble l, GLdouble h, GLdouble xt, GLdouble yt, GLdouble zt);
	~DiaboloTex() { };
	virtual void draw();
	virtual void render(glm::dmat4 const& modelViewMat);
	virtual void rotateZ();
private:
	GLdouble rotationZ;
	GLdouble translateX;
	GLdouble translateY;
	GLdouble translateZ;
	GLdouble radius;
	GLdouble height;
};

class Suelo : public Entity
{
public:
	Suelo(GLdouble w, GLdouble h, GLuint x, GLuint y);
	virtual void render(glm::dmat4 const& modelViewMat);
	~Suelo() { };
	virtual void draw();
private:
	GLdouble scaleX;
	GLdouble scaleY;
};


class GlassPot : public Entity
{
public:
	GlassPot(GLdouble w, GLdouble h, GLuint x, GLuint y, GLdouble xt, GLdouble yt, GLdouble zt);
	GlassPot() { };
	virtual void draw();
	virtual void render(glm::dmat4 const& modelViewMat);
private:
	GLdouble w;
	GLdouble h;
	GLdouble translateX;
	GLdouble translateY;
	GLdouble translateZ;
};

class Grass : public Entity
{
public:
	Grass(GLdouble w, GLdouble h, GLuint x, GLuint y, GLdouble xt, GLdouble yt, GLdouble zt);
	virtual void render(glm::dmat4 const& modelViewMat);
	~Grass() { };
	virtual void draw();
private:
	GLdouble translateX;
	GLdouble translateY;
	GLdouble translateZ;
};

#endif //_H_Entities_H_