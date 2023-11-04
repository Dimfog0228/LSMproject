#pragma once
struct float2 {
	union
	{
		float v2[2];
		struct { float x, y; };
	};
};

struct float3 {
	union {
		float v3[3];
		struct { float x, y, z; };
	};
};

struct float4 {
	union {
		float v4[4];
		struct { float x, y, z,t; };
	};
};;


class vector2 :public float2 {
public:
	vector2(); 
	~vector2();
	vector2(const vector2& v0);
	vector2(float vx, float vy); //2차원 벡터 생성자

	vector2 operator+ (vector2 const& v0);
	vector2 operator- (vector2 const& v0);
	bool operator==(vector2 const& v0);
	vector2 operator* (float const& fScala);
	vector2 operator/ (float const& fScala);
	vector2 operator+ (float const& fScala); //연산자

	float LengthSquared();
	float Length();
	vector2 Normal();
};

class vector3 :public float3 {
	vector3();
	~vector3();
	vector3(const vector3& v0);
	vector3(float vx, float vy, float vz); //3차원 벡터 생성자

	vector3 operator+ (vector3 const& v0);
	vector3 operator- (vector3 const& v0);
	vector3 operator* (float const& fScala);
	vector3 operator/ (float const& fScala);
	vector3 operator+ (float const& fScala); //연산자
	bool operator==(vector3 const& v0);

	float LengthSquared();
	float Length();
	vector3 Normal();
};

class vector4 :public float4 {
	vector4();
	~vector4();
	vector4(const vector4& v0);
	vector4(float vx, float vy, float vz,float vt); //4차원 벡터 생성자

	vector4 operator+ (vector4 const& v0);
	vector4 operator- (vector4 const& v0);
	bool operator==(vector4 const& v0);
	vector4 operator* (float const& fScala);
	vector4 operator/ (float const& fScala);
	vector4 operator+ (float const& fScala); //연산자

	float LengthSquared();
	float Length();
	vector4 Normal();
};
