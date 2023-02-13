#include "Camera.h"
#include "inputhandler.h"

using namespace linalg;

void Camera::MoveTo(const vec3f& position) noexcept
{
	m_position = position;
}

void Camera::Move(const vec3f& direction) noexcept
{
	m_position += direction;
}

void Camera::moveForward(const float& v, float& dt)
{
	vec4f fwdView = { 0, 0, -1, 0 };
	mat4f rotationmatrix = mat4f::rotation(0, m_yaw, m_pitch);
	mat4f pos = mat4f::translation(m_position);
	mat4f viewtoworld = pos * rotationmatrix;
	vec4f fwdWorld = viewtoworld * fwdView;
	m_position += fwdWorld.xyz() * v * dt;
}

void Camera::moveBackward(const float& v, float& dt)
{
	vec4f bwdView = { 0, 0, 1, 0 };
	mat4f rotationmatrix = mat4f::rotation(0, m_yaw, m_pitch);
	mat4f pos = mat4f::translation(m_position);
	mat4f viewtoworld = pos * rotationmatrix;
	vec4f bwdWorld = viewtoworld * bwdView;
	m_position += bwdWorld.xyz() * v * dt;
}

void Camera::moveLeft(const float& v, float& dt)
{
	vec4f leftView = { -1, 0, 0, 0 };
	mat4f rotationmatrix = mat4f::rotation(0, m_yaw, m_pitch);
	mat4f pos = mat4f::translation(m_position);
	mat4f viewtoworld = pos * rotationmatrix;
	vec4f leftWorld = viewtoworld * leftView;
	m_position += leftWorld.xyz() * v * dt;
}

void Camera::moveRight(const float& v, float& dt)
{
	vec4f rightView = { 1, 0, 0, 0 };
	mat4f rotationmatrix = mat4f::rotation(0, m_yaw, m_pitch);
	mat4f pos = mat4f::translation(m_position);
	mat4f viewtoworld = pos * rotationmatrix;
	vec4f rightWorld = viewtoworld * rightView;
	m_position += rightWorld.xyz() * v * dt;
}

mat4f Camera::WorldToViewMatrix() const noexcept
{
	// Assuming a camera's position and rotation is defined by matrices T(p) and R,
	// the View-to-World transform is T(p)*R (for a first-person style camera).
	//
	// World-to-View then is the inverse of T(p)*R;
	//		inverse(T(p)*R) = inverse(R)*inverse(T(p)) = transpose(R)*T(-p)
	// Since now there is no rotation, this matrix is simply T(-p)

	mat4f rotationmatrix = mat4f::rotation(0, m_yaw, m_pitch);
	rotationmatrix.transpose();

	return rotationmatrix * mat4f::translation(-m_position);
}

mat4f Camera::ProjectionMatrix() const noexcept
{
	return mat4f::projection(m_vertical_fov, m_aspect_ratio, m_near_plane, m_far_plane);
}