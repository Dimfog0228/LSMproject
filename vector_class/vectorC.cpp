#include "vectorC.h"
#include <cmath>

vector2::vector2() { x = 0, y = 0; }; //기본 생성 위치는 (0,0)
vector2::~vector2() {};
vector2::vector2(const vector2& v0) { x = v0.x, y = v0.y; }; //복사 받아와서 값 대입
vector2::vector2(float vx, float vy) { x = vx, y = vy; }; //2차원 벡터 생성자

vector2 vector2::operator+ (vector2 const& v0) { return vector2(x + v0.x, y + v0.y); }; //
vector2 vector2::operator- (vector2 const& v0) { return vector2(x - v0.x, y - v0.y); };
vector2 vector2::operator+ (float const& fScala) { return vector2(x + fScala, y + fScala); };
vector2 vector2::operator* (float const& fScala) { return vector2(x + fScala, y + fScala); }; //연산자

vector2 vector2::operator/ (float const& fScala) {
	if (fScala != 0) {

		float fInvert = 1.0f / fScala;
		return vector2(x * fInvert, y * fInvert);
	}
};

bool vector2::operator==(vector2 const& v0) {

	if ((x - v0.x) < 0.001f) {
		if ((y - v0.y) < 0.001f) {
				return true;
		}
	}
	else return false;
};

float vector2::LengthSquared() { return x * x + y * y; };

float vector2::Length() { return (float)sqrt(LengthSquared()); }; //C++에서 sqrt 함수는 double 형식의 값을 반환

vector2 vector2::Normal() {

	float invertLength = 1.0f / Length();
	return vector2(x * invertLength, y * invertLength);

};//단위 벡터




vector3::vector3() { x = 0, y = 0, z = 0; }; //기본 생성 위치는 (0,0,0)
vector3::~vector3() {};
vector3::vector3(const vector3& v0) { x = v0.x, y = v0.y, z = v0.z; }; //복사 받아와서 값 대입
vector3::vector3(float vx, float vy, float vz) { x = vx, y = vy, z = vz; }; //3차원 벡터 생성자

vector3 vector3::operator+ (vector3 const& v0) { return vector3(x + v0.x, y + v0.y, z + v0.z); }; //
vector3 vector3::operator- (vector3 const& v0) { return vector3(x - v0.x, y - v0.y, z - v0.z); };
vector3 vector3::operator+ (float const& fScala) { return vector3(x + fScala, y + fScala, z + fScala); };
vector3 vector3::operator* (float const& fScala) { return vector3(x + fScala, y + fScala, z + fScala); }; //연산자

vector3 vector3::operator/ (float const& fScala) {
	if (fScala != 0) {
		
		float fInvert = 1.0f / fScala;
		return vector3(x * fInvert, y * fInvert, z * fInvert);
	}
};

bool vector3::operator==(vector3 const& v0) { 

	if ((x - v0.x) < 0.001f) {
		if ((y - v0.y) < 0.001f) {
			if ((z - v0.z) < 0.001f) {
				return true;
			}
		}
	}
	else return false;
};

float vector3::LengthSquared() { return x * x + y * y + z * z; };

float vector3::Length() { return (float)sqrt(LengthSquared()); }; //C++에서 sqrt 함수는 double 형식의 값을 반환

vector3 vector3::Normal() {

	float invertLength = 1.0f / Length();
	return vector3(x * invertLength, y * invertLength, z * invertLength);

};//단위 벡터





vector4::vector4() { x = 0, y = 0, z = 0, t=0; }; //기본 생성 위치는 (0,0,0)
vector4::~vector4() {};
vector4::vector4(const vector4& v0) { x = v0.x, y = v0.y, z = v0.z, t = v0.t; }; //복사 받아와서 값 대입
vector4::vector4(float vx, float vy, float vz, float vt) { x = vx, y = vy, z = vz, t = vt; }; //3차원 벡터 생성자

vector4 vector4::operator+ (vector4 const& v0) { return vector4(x + v0.x, y + v0.y, z + v0.z, t+v0.t); }; //
vector4 vector4::operator- (vector4 const& v0) { return vector4(x - v0.x, y - v0.y, z - v0.z, t+v0.t); };
vector4 vector4::operator+ (float const& fScala) { return vector4(x + fScala, y + fScala, z + fScala, t + fScala); };
vector4 vector4::operator* (float const& fScala) { return vector4(x + fScala, y + fScala, z + fScala, t + fScala); }; //연산자

vector4 vector4::operator/ (float const& fScala) {
	if (fScala != 0) {

		float fInvert = 1.0f / fScala;
		return vector4(x * fInvert, y * fInvert, z * fInvert, t * fInvert);
	}
};

bool vector4::operator==(vector4 const& v0) {

	if ((x - v0.x) < 0.001f) {
		if ((y - v0.y) < 0.001f) {
			if ((z - v0.z) < 0.001f) {
				if ((t - v0.t) < 0.001f) {
					return true;
				}
			}
		}
	}
	else return false;
};

float vector4::LengthSquared() { return x * x + y * y + z * z + t*t; };

float vector4::Length() { return (float)sqrt(LengthSquared()); }; //C++에서 sqrt 함수는 double 형식의 값을 반환

vector4 vector4::Normal() {

	float invertLength = 1.0f / Length();
	return vector4(x * invertLength, y * invertLength, z * invertLength, t * invertLength);

};//단위 벡터