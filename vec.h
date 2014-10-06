/* Copyright 2011 Pyarelal Knowles, under GNU GPL (see LICENCE.txt) */
/* file generated on 03/09/14 with gencode.py */

//#alltypes=("f", "float"), ("i", "int"), ("d", "double")
#pragma once
#ifndef VEC_H
#define VEC_H
#include <math.h>
#include <stdlib.h>
#include <ostream>

#define XYZ(v) (v).x, (v).y, (v).z
#define RANDVEC3FN RANDVEC3F(-1.0f, 1.0f).unit()
#define RANDVEC3F(a, b) vec3f(((b)-(a))*rand()/(float)RAND_MAX+(a), ((b)-(a))*rand()/(float)RAND_MAX+(a), ((b)-(a))*rand()/(float)RAND_MAX+(a))
#define PRINTVEC2(v) PRINTVEC2F(v)
#define PRINTVEC3(v) PRINTVEC3F(v)
#define PRINTVEC4(v) PRINTVEC4F(v)

#define PRINTVEC2I(v) printf("%s(%3i, %3i)\n", #v, (v).x, (v).y)
#define PRINTVEC2F(v) printf("%s(%.2f, %.2f)\n", #v, (v).x, (v).y)
#define PRINTVEC3I(v) printf("%s(%3i, %3i, %3i)\n", #v, (v).x, (v).y, (v).z)
#define PRINTVEC3F(v) printf("%s(%.2f, %.2f, %.2f)\n", #v, (v).x, (v).y, (v).z)
#define PRINTVEC4I(v) printf("%s(%3i, %3i, %3i, %3i)\n", #v, (v).x, (v).y, (v).z, (v).w)
#define PRINTVEC4F(v) printf("%s(%.2f, %.2f, %.2f, %.2f)\n", #v, (v).x, (v).y, (v).z, (v).w)

struct vec2f;
struct vec3f;
struct vec4f;
struct vec2i;
struct vec3i;
struct vec4i;
struct vec2d;
struct vec3d;
struct vec4d;
typedef vec2f rot2f;

struct vec2f
{
	float x, y;
	vec2f();
	explicit vec2f(float d);
	vec2f(float nx, float ny);
	vec2f(vec3f other);
	vec2f(vec4f other);
	vec2f(vec2i other);
	vec2f(vec3i other);
	vec2f(vec4i other);
	vec2f(vec2d other);
	vec2f(vec3d other);
	vec2f(vec4d other);
	const float& operator[](const int i) const;
	float& operator[](const int i);
	void operator()(float d);
	void operator()(float nx, float ny);
	vec2f operator+(const vec2f& o) const;
	void operator+=(const vec2f& o);
	vec2f operator+(float d) const;
	vec2d operator+(double d) const;
	void operator+=(float d);
	void operator+=(double d);
	vec2f operator-(const vec2f& o) const;
	void operator-=(const vec2f& o);
	vec2f operator-(float d) const;
	vec2d operator-(double d) const;
	void operator-=(float d);
	void operator-=(double d);
	vec2f operator/(const vec2f& o) const;
	void operator/=(const vec2f& o);
	vec2f operator/(float d) const;
	vec2d operator/(double d) const;
	void operator/=(float d);
	void operator/=(double d);
	vec2f operator*(const vec2f& o) const;
	void operator*=(const vec2f& o);
	vec2f operator*(float d) const;
	vec2d operator*(double d) const;
	void operator*=(float d);
	void operator*=(double d);
	bool operator==(const vec2f& other) const;
	bool operator!=(const vec2f& other) const;
	bool operator>(const vec2f& other) const;
	bool operator<(const vec2f& other) const;
	bool operator>=(const vec2f& other) const;
	bool operator<=(const vec2f& other) const;
	vec2f operator%(const vec2f& other) const;
	vec2f operator%(float d) const;
	void operator%=(const vec2f& other);
	void operator%=(float d);
	//vec2f operator-(void) const;
	float distsq(const vec2f& other) const;
	float dist(const vec2f& other) const;
	float dot(const vec2f& other) const;
	float sizesq() const;
	float size() const;
	float cmax() const;
	float cmin() const;
	vec2f tolen(float len);
	void normalize();
	vec2f unit() const;
	vec3f toVec() const;
	static vec2f fromVec(const vec3f& v);
	float cross(const vec2f& other) const;
	
	//bit ops
	
	//swivel operators
	vec2f yx() const;
	
	friend std::ostream& operator<<(std::ostream &out, const vec2f &v);
};

std::ostream& operator<<(std::ostream &out, const vec2f &v);

vec2f operator-(vec2f v);
vec2f operator/(float n, vec2f v);
vec2d operator/(double n, vec2f v);
vec2f vmin(vec2f a, vec2f b);
vec2f vmax(vec2f a, vec2f b);
vec2f vmin(vec2f a, float b);
vec2f vmax(vec2f a, float b);
vec2f vmin(float a, vec2f b);
vec2f vmax(float a, vec2f b);
struct vec3f
{
	float x, y, z;
	vec3f();
	explicit vec3f(float d);
	vec3f(float nx, float ny, float nz);
	vec3f(vec2f other);
	vec3f(vec4f other);
	vec3f(vec2i other);
	vec3f(vec3i other);
	vec3f(vec4i other);
	vec3f(vec2d other);
	vec3f(vec3d other);
	vec3f(vec4d other);
	vec3f(vec2d other, float nz);
	const float& operator[](const int i) const;
	float& operator[](const int i);
	void operator()(float d);
	void operator()(float nx, float ny, float nz);
	vec3f operator+(const vec3f& o) const;
	void operator+=(const vec3f& o);
	vec3f operator+(float d) const;
	vec3d operator+(double d) const;
	void operator+=(float d);
	void operator+=(double d);
	vec3f operator-(const vec3f& o) const;
	void operator-=(const vec3f& o);
	vec3f operator-(float d) const;
	vec3d operator-(double d) const;
	void operator-=(float d);
	void operator-=(double d);
	vec3f operator/(const vec3f& o) const;
	void operator/=(const vec3f& o);
	vec3f operator/(float d) const;
	vec3d operator/(double d) const;
	void operator/=(float d);
	void operator/=(double d);
	vec3f operator*(const vec3f& o) const;
	void operator*=(const vec3f& o);
	vec3f operator*(float d) const;
	vec3d operator*(double d) const;
	void operator*=(float d);
	void operator*=(double d);
	bool operator==(const vec3f& other) const;
	bool operator!=(const vec3f& other) const;
	bool operator>(const vec3f& other) const;
	bool operator<(const vec3f& other) const;
	bool operator>=(const vec3f& other) const;
	bool operator<=(const vec3f& other) const;
	vec3f operator%(const vec3f& other) const;
	vec3f operator%(float d) const;
	void operator%=(const vec3f& other);
	void operator%=(float d);
	//vec3f operator-(void) const;
	float distsq(const vec3f& other) const;
	float dist(const vec3f& other) const;
	float dot(const vec3f& other) const;
	float sizesq() const;
	float size() const;
	float cmax() const;
	float cmin() const;
	vec3f tolen(float len);
	void normalize();
	vec3f unit() const;
	vec3f cross(const vec3f& other) const;
	
	//bit ops
	
	//swivel operators
	vec2f xy() const;
	vec2f xz() const;
	vec2f yx() const;
	vec2f yz() const;
	vec2f zx() const;
	vec2f zy() const;
	vec3f xzy() const;
	vec3f yxz() const;
	vec3f yzx() const;
	vec3f zxy() const;
	vec3f zyx() const;
	
	friend std::ostream& operator<<(std::ostream &out, const vec3f &v);
};

std::ostream& operator<<(std::ostream &out, const vec3f &v);

vec3f operator-(vec3f v);
vec3f operator/(float n, vec3f v);
vec3d operator/(double n, vec3f v);
vec3f vmin(vec3f a, vec3f b);
vec3f vmax(vec3f a, vec3f b);
vec3f vmin(vec3f a, float b);
vec3f vmax(vec3f a, float b);
vec3f vmin(float a, vec3f b);
vec3f vmax(float a, vec3f b);
struct vec4f
{
	float x, y, z, w;
	vec4f();
	explicit vec4f(float d);
	vec4f(float nx, float ny, float nz, float nw);
	vec4f(vec2f other);
	vec4f(vec3f other);
	vec4f(vec2i other);
	vec4f(vec3i other);
	vec4f(vec4i other);
	vec4f(vec2d other);
	vec4f(vec3d other);
	vec4f(vec4d other);
	vec4f(vec2d other, float nz, float nw);
	vec4f(vec3d other, float nw);
	const float& operator[](const int i) const;
	float& operator[](const int i);
	void operator()(float d);
	void operator()(float nx, float ny, float nz, float nw);
	vec4f operator+(const vec4f& o) const;
	void operator+=(const vec4f& o);
	vec4f operator+(float d) const;
	vec4d operator+(double d) const;
	void operator+=(float d);
	void operator+=(double d);
	vec4f operator-(const vec4f& o) const;
	void operator-=(const vec4f& o);
	vec4f operator-(float d) const;
	vec4d operator-(double d) const;
	void operator-=(float d);
	void operator-=(double d);
	vec4f operator/(const vec4f& o) const;
	void operator/=(const vec4f& o);
	vec4f operator/(float d) const;
	vec4d operator/(double d) const;
	void operator/=(float d);
	void operator/=(double d);
	vec4f operator*(const vec4f& o) const;
	void operator*=(const vec4f& o);
	vec4f operator*(float d) const;
	vec4d operator*(double d) const;
	void operator*=(float d);
	void operator*=(double d);
	bool operator==(const vec4f& other) const;
	bool operator!=(const vec4f& other) const;
	bool operator>(const vec4f& other) const;
	bool operator<(const vec4f& other) const;
	bool operator>=(const vec4f& other) const;
	bool operator<=(const vec4f& other) const;
	vec4f operator%(const vec4f& other) const;
	vec4f operator%(float d) const;
	void operator%=(const vec4f& other);
	void operator%=(float d);
	//vec4f operator-(void) const;
	float distsq(const vec4f& other) const;
	float dist(const vec4f& other) const;
	float dot(const vec4f& other) const;
	float sizesq() const;
	float size() const;
	float cmax() const;
	float cmin() const;
	vec4f tolen(float len);
	void normalize();
	vec4f unit() const;
	
	//bit ops
	
	//swivel operators
	vec2f xy() const;
	vec2f xz() const;
	vec2f xw() const;
	vec2f yx() const;
	vec2f yz() const;
	vec2f yw() const;
	vec2f zx() const;
	vec2f zy() const;
	vec2f zw() const;
	vec2f wx() const;
	vec2f wy() const;
	vec2f wz() const;
	vec3f xyz() const;
	vec3f xyw() const;
	vec3f xzy() const;
	vec3f xzw() const;
	vec3f xwy() const;
	vec3f xwz() const;
	vec3f yxz() const;
	vec3f yxw() const;
	vec3f yzx() const;
	vec3f yzw() const;
	vec3f ywx() const;
	vec3f ywz() const;
	vec3f zxy() const;
	vec3f zxw() const;
	vec3f zyx() const;
	vec3f zyw() const;
	vec3f zwx() const;
	vec3f zwy() const;
	vec3f wxy() const;
	vec3f wxz() const;
	vec3f wyx() const;
	vec3f wyz() const;
	vec3f wzx() const;
	vec3f wzy() const;
	vec4f xywz() const;
	vec4f xzyw() const;
	vec4f xzwy() const;
	vec4f xwyz() const;
	vec4f xwzy() const;
	vec4f yxzw() const;
	vec4f yxwz() const;
	vec4f yzxw() const;
	vec4f yzwx() const;
	vec4f ywxz() const;
	vec4f ywzx() const;
	vec4f zxyw() const;
	vec4f zxwy() const;
	vec4f zyxw() const;
	vec4f zywx() const;
	vec4f zwxy() const;
	vec4f zwyx() const;
	vec4f wxyz() const;
	vec4f wxzy() const;
	vec4f wyxz() const;
	vec4f wyzx() const;
	vec4f wzxy() const;
	vec4f wzyx() const;
	
	friend std::ostream& operator<<(std::ostream &out, const vec4f &v);
};

std::ostream& operator<<(std::ostream &out, const vec4f &v);

vec4f operator-(vec4f v);
vec4f operator/(float n, vec4f v);
vec4d operator/(double n, vec4f v);
vec4f vmin(vec4f a, vec4f b);
vec4f vmax(vec4f a, vec4f b);
vec4f vmin(vec4f a, float b);
vec4f vmax(vec4f a, float b);
vec4f vmin(float a, vec4f b);
vec4f vmax(float a, vec4f b);
struct vec2i
{
	int x, y;
	vec2i();
	explicit vec2i(int d);
	vec2i(int nx, int ny);
	vec2i(vec2f other);
	vec2i(vec3f other);
	vec2i(vec4f other);
	vec2i(vec3i other);
	vec2i(vec4i other);
	vec2i(vec2d other);
	vec2i(vec3d other);
	vec2i(vec4d other);
	const int& operator[](const int i) const;
	int& operator[](const int i);
	void operator()(int d);
	void operator()(int nx, int ny);
	vec2i operator+(const vec2i& o) const;
	void operator+=(const vec2i& o);
	vec2i operator+(int d) const;
	vec2f operator+(float d) const;
	vec2d operator+(double d) const;
	void operator+=(int d);
	void operator+=(float d);
	void operator+=(double d);
	vec2i operator-(const vec2i& o) const;
	void operator-=(const vec2i& o);
	vec2i operator-(int d) const;
	vec2f operator-(float d) const;
	vec2d operator-(double d) const;
	void operator-=(int d);
	void operator-=(float d);
	void operator-=(double d);
	vec2i operator/(const vec2i& o) const;
	void operator/=(const vec2i& o);
	vec2i operator/(int d) const;
	vec2f operator/(float d) const;
	vec2d operator/(double d) const;
	void operator/=(int d);
	void operator/=(float d);
	void operator/=(double d);
	vec2i operator*(const vec2i& o) const;
	void operator*=(const vec2i& o);
	vec2i operator*(int d) const;
	vec2f operator*(float d) const;
	vec2d operator*(double d) const;
	void operator*=(int d);
	void operator*=(float d);
	void operator*=(double d);
	bool operator==(const vec2i& other) const;
	bool operator!=(const vec2i& other) const;
	bool operator>(const vec2i& other) const;
	bool operator<(const vec2i& other) const;
	bool operator>=(const vec2i& other) const;
	bool operator<=(const vec2i& other) const;
	vec2i operator%(const vec2i& other) const;
	vec2i operator%(int d) const;
	void operator%=(const vec2i& other);
	void operator%=(int d);
	//vec2i operator-(void) const;
	int distsq(const vec2i& other) const;
	int dist(const vec2i& other) const;
	int dot(const vec2i& other) const;
	int sizesq() const;
	int size() const;
	int cmax() const;
	int cmin() const;
	vec2i tolen(int len);
	void normalize();
	vec2i unit() const;
	int cross(const vec2i& other) const;
	
	//bit ops
	vec2i operator<<(int n) const;
	vec2i& operator<<=(int n);
	vec2i operator>>(int n) const;
	vec2i& operator>>=(int n);
	
	//swivel operators
	vec2i yx() const;
	
	friend std::ostream& operator<<(std::ostream &out, const vec2i &v);
};

std::ostream& operator<<(std::ostream &out, const vec2i &v);

vec2i operator-(vec2i v);
vec2i operator/(int n, vec2i v);
vec2f operator/(float n, vec2i v);
vec2d operator/(double n, vec2i v);
vec2i vmin(vec2i a, vec2i b);
vec2i vmax(vec2i a, vec2i b);
vec2i vmin(vec2i a, int b);
vec2i vmax(vec2i a, int b);
vec2i vmin(int a, vec2i b);
vec2i vmax(int a, vec2i b);
struct vec3i
{
	int x, y, z;
	vec3i();
	explicit vec3i(int d);
	vec3i(int nx, int ny, int nz);
	vec3i(vec2f other);
	vec3i(vec3f other);
	vec3i(vec4f other);
	vec3i(vec2i other);
	vec3i(vec4i other);
	vec3i(vec2d other);
	vec3i(vec3d other);
	vec3i(vec4d other);
	vec3i(vec2d other, int nz);
	const int& operator[](const int i) const;
	int& operator[](const int i);
	void operator()(int d);
	void operator()(int nx, int ny, int nz);
	vec3i operator+(const vec3i& o) const;
	void operator+=(const vec3i& o);
	vec3i operator+(int d) const;
	vec3f operator+(float d) const;
	vec3d operator+(double d) const;
	void operator+=(int d);
	void operator+=(float d);
	void operator+=(double d);
	vec3i operator-(const vec3i& o) const;
	void operator-=(const vec3i& o);
	vec3i operator-(int d) const;
	vec3f operator-(float d) const;
	vec3d operator-(double d) const;
	void operator-=(int d);
	void operator-=(float d);
	void operator-=(double d);
	vec3i operator/(const vec3i& o) const;
	void operator/=(const vec3i& o);
	vec3i operator/(int d) const;
	vec3f operator/(float d) const;
	vec3d operator/(double d) const;
	void operator/=(int d);
	void operator/=(float d);
	void operator/=(double d);
	vec3i operator*(const vec3i& o) const;
	void operator*=(const vec3i& o);
	vec3i operator*(int d) const;
	vec3f operator*(float d) const;
	vec3d operator*(double d) const;
	void operator*=(int d);
	void operator*=(float d);
	void operator*=(double d);
	bool operator==(const vec3i& other) const;
	bool operator!=(const vec3i& other) const;
	bool operator>(const vec3i& other) const;
	bool operator<(const vec3i& other) const;
	bool operator>=(const vec3i& other) const;
	bool operator<=(const vec3i& other) const;
	vec3i operator%(const vec3i& other) const;
	vec3i operator%(int d) const;
	void operator%=(const vec3i& other);
	void operator%=(int d);
	//vec3i operator-(void) const;
	int distsq(const vec3i& other) const;
	int dist(const vec3i& other) const;
	int dot(const vec3i& other) const;
	int sizesq() const;
	int size() const;
	int cmax() const;
	int cmin() const;
	vec3i tolen(int len);
	void normalize();
	vec3i unit() const;
	vec3i cross(const vec3i& other) const;
	
	//bit ops
	vec3i operator<<(int n) const;
	vec3i& operator<<=(int n);
	vec3i operator>>(int n) const;
	vec3i& operator>>=(int n);
	
	//swivel operators
	vec2i xy() const;
	vec2i xz() const;
	vec2i yx() const;
	vec2i yz() const;
	vec2i zx() const;
	vec2i zy() const;
	vec3i xzy() const;
	vec3i yxz() const;
	vec3i yzx() const;
	vec3i zxy() const;
	vec3i zyx() const;
	
	friend std::ostream& operator<<(std::ostream &out, const vec3i &v);
};

std::ostream& operator<<(std::ostream &out, const vec3i &v);

vec3i operator-(vec3i v);
vec3i operator/(int n, vec3i v);
vec3f operator/(float n, vec3i v);
vec3d operator/(double n, vec3i v);
vec3i vmin(vec3i a, vec3i b);
vec3i vmax(vec3i a, vec3i b);
vec3i vmin(vec3i a, int b);
vec3i vmax(vec3i a, int b);
vec3i vmin(int a, vec3i b);
vec3i vmax(int a, vec3i b);
struct vec4i
{
	int x, y, z, w;
	vec4i();
	explicit vec4i(int d);
	vec4i(int nx, int ny, int nz, int nw);
	vec4i(vec2f other);
	vec4i(vec3f other);
	vec4i(vec4f other);
	vec4i(vec2i other);
	vec4i(vec3i other);
	vec4i(vec2d other);
	vec4i(vec3d other);
	vec4i(vec4d other);
	vec4i(vec2d other, int nz, int nw);
	vec4i(vec3d other, int nw);
	const int& operator[](const int i) const;
	int& operator[](const int i);
	void operator()(int d);
	void operator()(int nx, int ny, int nz, int nw);
	vec4i operator+(const vec4i& o) const;
	void operator+=(const vec4i& o);
	vec4i operator+(int d) const;
	vec4f operator+(float d) const;
	vec4d operator+(double d) const;
	void operator+=(int d);
	void operator+=(float d);
	void operator+=(double d);
	vec4i operator-(const vec4i& o) const;
	void operator-=(const vec4i& o);
	vec4i operator-(int d) const;
	vec4f operator-(float d) const;
	vec4d operator-(double d) const;
	void operator-=(int d);
	void operator-=(float d);
	void operator-=(double d);
	vec4i operator/(const vec4i& o) const;
	void operator/=(const vec4i& o);
	vec4i operator/(int d) const;
	vec4f operator/(float d) const;
	vec4d operator/(double d) const;
	void operator/=(int d);
	void operator/=(float d);
	void operator/=(double d);
	vec4i operator*(const vec4i& o) const;
	void operator*=(const vec4i& o);
	vec4i operator*(int d) const;
	vec4f operator*(float d) const;
	vec4d operator*(double d) const;
	void operator*=(int d);
	void operator*=(float d);
	void operator*=(double d);
	bool operator==(const vec4i& other) const;
	bool operator!=(const vec4i& other) const;
	bool operator>(const vec4i& other) const;
	bool operator<(const vec4i& other) const;
	bool operator>=(const vec4i& other) const;
	bool operator<=(const vec4i& other) const;
	vec4i operator%(const vec4i& other) const;
	vec4i operator%(int d) const;
	void operator%=(const vec4i& other);
	void operator%=(int d);
	//vec4i operator-(void) const;
	int distsq(const vec4i& other) const;
	int dist(const vec4i& other) const;
	int dot(const vec4i& other) const;
	int sizesq() const;
	int size() const;
	int cmax() const;
	int cmin() const;
	vec4i tolen(int len);
	void normalize();
	vec4i unit() const;
	
	//bit ops
	vec4i operator<<(int n) const;
	vec4i& operator<<=(int n);
	vec4i operator>>(int n) const;
	vec4i& operator>>=(int n);
	
	//swivel operators
	vec2i xy() const;
	vec2i xz() const;
	vec2i xw() const;
	vec2i yx() const;
	vec2i yz() const;
	vec2i yw() const;
	vec2i zx() const;
	vec2i zy() const;
	vec2i zw() const;
	vec2i wx() const;
	vec2i wy() const;
	vec2i wz() const;
	vec3i xyz() const;
	vec3i xyw() const;
	vec3i xzy() const;
	vec3i xzw() const;
	vec3i xwy() const;
	vec3i xwz() const;
	vec3i yxz() const;
	vec3i yxw() const;
	vec3i yzx() const;
	vec3i yzw() const;
	vec3i ywx() const;
	vec3i ywz() const;
	vec3i zxy() const;
	vec3i zxw() const;
	vec3i zyx() const;
	vec3i zyw() const;
	vec3i zwx() const;
	vec3i zwy() const;
	vec3i wxy() const;
	vec3i wxz() const;
	vec3i wyx() const;
	vec3i wyz() const;
	vec3i wzx() const;
	vec3i wzy() const;
	vec4i xywz() const;
	vec4i xzyw() const;
	vec4i xzwy() const;
	vec4i xwyz() const;
	vec4i xwzy() const;
	vec4i yxzw() const;
	vec4i yxwz() const;
	vec4i yzxw() const;
	vec4i yzwx() const;
	vec4i ywxz() const;
	vec4i ywzx() const;
	vec4i zxyw() const;
	vec4i zxwy() const;
	vec4i zyxw() const;
	vec4i zywx() const;
	vec4i zwxy() const;
	vec4i zwyx() const;
	vec4i wxyz() const;
	vec4i wxzy() const;
	vec4i wyxz() const;
	vec4i wyzx() const;
	vec4i wzxy() const;
	vec4i wzyx() const;
	
	friend std::ostream& operator<<(std::ostream &out, const vec4i &v);
};

std::ostream& operator<<(std::ostream &out, const vec4i &v);

vec4i operator-(vec4i v);
vec4i operator/(int n, vec4i v);
vec4f operator/(float n, vec4i v);
vec4d operator/(double n, vec4i v);
vec4i vmin(vec4i a, vec4i b);
vec4i vmax(vec4i a, vec4i b);
vec4i vmin(vec4i a, int b);
vec4i vmax(vec4i a, int b);
vec4i vmin(int a, vec4i b);
vec4i vmax(int a, vec4i b);
struct vec2d
{
	double x, y;
	vec2d();
	explicit vec2d(double d);
	vec2d(double nx, double ny);
	vec2d(vec2f other);
	vec2d(vec3f other);
	vec2d(vec4f other);
	vec2d(vec2i other);
	vec2d(vec3i other);
	vec2d(vec4i other);
	vec2d(vec3d other);
	vec2d(vec4d other);
	const double& operator[](const int i) const;
	double& operator[](const int i);
	void operator()(double d);
	void operator()(double nx, double ny);
	vec2d operator+(const vec2d& o) const;
	void operator+=(const vec2d& o);
	vec2d operator+(double d) const;
	void operator+=(double d);
	vec2d operator-(const vec2d& o) const;
	void operator-=(const vec2d& o);
	vec2d operator-(double d) const;
	void operator-=(double d);
	vec2d operator/(const vec2d& o) const;
	void operator/=(const vec2d& o);
	vec2d operator/(double d) const;
	void operator/=(double d);
	vec2d operator*(const vec2d& o) const;
	void operator*=(const vec2d& o);
	vec2d operator*(double d) const;
	void operator*=(double d);
	bool operator==(const vec2d& other) const;
	bool operator!=(const vec2d& other) const;
	bool operator>(const vec2d& other) const;
	bool operator<(const vec2d& other) const;
	bool operator>=(const vec2d& other) const;
	bool operator<=(const vec2d& other) const;
	vec2d operator%(const vec2d& other) const;
	vec2d operator%(double d) const;
	void operator%=(const vec2d& other);
	void operator%=(double d);
	//vec2d operator-(void) const;
	double distsq(const vec2d& other) const;
	double dist(const vec2d& other) const;
	double dot(const vec2d& other) const;
	double sizesq() const;
	double size() const;
	double cmax() const;
	double cmin() const;
	vec2d tolen(double len);
	void normalize();
	vec2d unit() const;
	double cross(const vec2d& other) const;
	
	//bit ops
	
	//swivel operators
	vec2d yx() const;
	
	friend std::ostream& operator<<(std::ostream &out, const vec2d &v);
};

std::ostream& operator<<(std::ostream &out, const vec2d &v);

vec2d operator-(vec2d v);
vec2d operator/(double n, vec2d v);
vec2d vmin(vec2d a, vec2d b);
vec2d vmax(vec2d a, vec2d b);
vec2d vmin(vec2d a, double b);
vec2d vmax(vec2d a, double b);
vec2d vmin(double a, vec2d b);
vec2d vmax(double a, vec2d b);
struct vec3d
{
	double x, y, z;
	vec3d();
	explicit vec3d(double d);
	vec3d(double nx, double ny, double nz);
	vec3d(vec2f other);
	vec3d(vec3f other);
	vec3d(vec4f other);
	vec3d(vec2i other);
	vec3d(vec3i other);
	vec3d(vec4i other);
	vec3d(vec2d other);
	vec3d(vec4d other);
	vec3d(vec2d other, double nz);
	const double& operator[](const int i) const;
	double& operator[](const int i);
	void operator()(double d);
	void operator()(double nx, double ny, double nz);
	vec3d operator+(const vec3d& o) const;
	void operator+=(const vec3d& o);
	vec3d operator+(double d) const;
	void operator+=(double d);
	vec3d operator-(const vec3d& o) const;
	void operator-=(const vec3d& o);
	vec3d operator-(double d) const;
	void operator-=(double d);
	vec3d operator/(const vec3d& o) const;
	void operator/=(const vec3d& o);
	vec3d operator/(double d) const;
	void operator/=(double d);
	vec3d operator*(const vec3d& o) const;
	void operator*=(const vec3d& o);
	vec3d operator*(double d) const;
	void operator*=(double d);
	bool operator==(const vec3d& other) const;
	bool operator!=(const vec3d& other) const;
	bool operator>(const vec3d& other) const;
	bool operator<(const vec3d& other) const;
	bool operator>=(const vec3d& other) const;
	bool operator<=(const vec3d& other) const;
	vec3d operator%(const vec3d& other) const;
	vec3d operator%(double d) const;
	void operator%=(const vec3d& other);
	void operator%=(double d);
	//vec3d operator-(void) const;
	double distsq(const vec3d& other) const;
	double dist(const vec3d& other) const;
	double dot(const vec3d& other) const;
	double sizesq() const;
	double size() const;
	double cmax() const;
	double cmin() const;
	vec3d tolen(double len);
	void normalize();
	vec3d unit() const;
	vec3d cross(const vec3d& other) const;
	
	//bit ops
	
	//swivel operators
	vec2d xy() const;
	vec2d xz() const;
	vec2d yx() const;
	vec2d yz() const;
	vec2d zx() const;
	vec2d zy() const;
	vec3d xzy() const;
	vec3d yxz() const;
	vec3d yzx() const;
	vec3d zxy() const;
	vec3d zyx() const;
	
	friend std::ostream& operator<<(std::ostream &out, const vec3d &v);
};

std::ostream& operator<<(std::ostream &out, const vec3d &v);

vec3d operator-(vec3d v);
vec3d operator/(double n, vec3d v);
vec3d vmin(vec3d a, vec3d b);
vec3d vmax(vec3d a, vec3d b);
vec3d vmin(vec3d a, double b);
vec3d vmax(vec3d a, double b);
vec3d vmin(double a, vec3d b);
vec3d vmax(double a, vec3d b);
struct vec4d
{
	double x, y, z, w;
	vec4d();
	explicit vec4d(double d);
	vec4d(double nx, double ny, double nz, double nw);
	vec4d(vec2f other);
	vec4d(vec3f other);
	vec4d(vec4f other);
	vec4d(vec2i other);
	vec4d(vec3i other);
	vec4d(vec4i other);
	vec4d(vec2d other);
	vec4d(vec3d other);
	vec4d(vec2d other, double nz, double nw);
	vec4d(vec3d other, double nw);
	const double& operator[](const int i) const;
	double& operator[](const int i);
	void operator()(double d);
	void operator()(double nx, double ny, double nz, double nw);
	vec4d operator+(const vec4d& o) const;
	void operator+=(const vec4d& o);
	vec4d operator+(double d) const;
	void operator+=(double d);
	vec4d operator-(const vec4d& o) const;
	void operator-=(const vec4d& o);
	vec4d operator-(double d) const;
	void operator-=(double d);
	vec4d operator/(const vec4d& o) const;
	void operator/=(const vec4d& o);
	vec4d operator/(double d) const;
	void operator/=(double d);
	vec4d operator*(const vec4d& o) const;
	void operator*=(const vec4d& o);
	vec4d operator*(double d) const;
	void operator*=(double d);
	bool operator==(const vec4d& other) const;
	bool operator!=(const vec4d& other) const;
	bool operator>(const vec4d& other) const;
	bool operator<(const vec4d& other) const;
	bool operator>=(const vec4d& other) const;
	bool operator<=(const vec4d& other) const;
	vec4d operator%(const vec4d& other) const;
	vec4d operator%(double d) const;
	void operator%=(const vec4d& other);
	void operator%=(double d);
	//vec4d operator-(void) const;
	double distsq(const vec4d& other) const;
	double dist(const vec4d& other) const;
	double dot(const vec4d& other) const;
	double sizesq() const;
	double size() const;
	double cmax() const;
	double cmin() const;
	vec4d tolen(double len);
	void normalize();
	vec4d unit() const;
	
	//bit ops
	
	//swivel operators
	vec2d xy() const;
	vec2d xz() const;
	vec2d xw() const;
	vec2d yx() const;
	vec2d yz() const;
	vec2d yw() const;
	vec2d zx() const;
	vec2d zy() const;
	vec2d zw() const;
	vec2d wx() const;
	vec2d wy() const;
	vec2d wz() const;
	vec3d xyz() const;
	vec3d xyw() const;
	vec3d xzy() const;
	vec3d xzw() const;
	vec3d xwy() const;
	vec3d xwz() const;
	vec3d yxz() const;
	vec3d yxw() const;
	vec3d yzx() const;
	vec3d yzw() const;
	vec3d ywx() const;
	vec3d ywz() const;
	vec3d zxy() const;
	vec3d zxw() const;
	vec3d zyx() const;
	vec3d zyw() const;
	vec3d zwx() const;
	vec3d zwy() const;
	vec3d wxy() const;
	vec3d wxz() const;
	vec3d wyx() const;
	vec3d wyz() const;
	vec3d wzx() const;
	vec3d wzy() const;
	vec4d xywz() const;
	vec4d xzyw() const;
	vec4d xzwy() const;
	vec4d xwyz() const;
	vec4d xwzy() const;
	vec4d yxzw() const;
	vec4d yxwz() const;
	vec4d yzxw() const;
	vec4d yzwx() const;
	vec4d ywxz() const;
	vec4d ywzx() const;
	vec4d zxyw() const;
	vec4d zxwy() const;
	vec4d zyxw() const;
	vec4d zywx() const;
	vec4d zwxy() const;
	vec4d zwyx() const;
	vec4d wxyz() const;
	vec4d wxzy() const;
	vec4d wyxz() const;
	vec4d wyzx() const;
	vec4d wzxy() const;
	vec4d wzyx() const;
	
	friend std::ostream& operator<<(std::ostream &out, const vec4d &v);
};

std::ostream& operator<<(std::ostream &out, const vec4d &v);

vec4d operator-(vec4d v);
vec4d operator/(double n, vec4d v);
vec4d vmin(vec4d a, vec4d b);
vec4d vmax(vec4d a, vec4d b);
vec4d vmin(vec4d a, double b);
vec4d vmax(vec4d a, double b);
vec4d vmin(double a, vec4d b);
vec4d vmax(double a, vec4d b);

#endif

