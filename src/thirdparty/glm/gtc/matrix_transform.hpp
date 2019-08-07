///////////////////////////////////////////////////////////////////////////////////
/// OpenGL Mathematics (glm.g-truc.net)
///
/// Copyright (c) 2005 - 2014 G-Truc Creation (www.g-truc.net)
/// Permission is hereby granted, free of charge, to any person obtaining a copy
/// of this software and associated documentation files (the "Software"), to deal
/// in the Software without restriction, including without limitation the rights
/// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
/// copies of the Software, and to permit persons to whom the Software is
/// furnished to do so, subject to the following conditions:
/// 
/// The above copyright notice and this permission notice shall be included in
/// all copies or substantial portions of the Software.
/// 
/// Restrictions:
///		By making use of the Software for military purposes, you choose to make
///		a Bunny unhappy.
/// 
/// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
/// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
/// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
/// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
/// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
/// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
/// THE SOFTWARE.
///
/// @ref gtc_matrix_transform
/// @file glm/gtc/matrix_transform.hpp
/// @date 2009-04-29 / 2011-05-16
/// @author Christophe Riccio
///
/// @see core (dependence)
/// @see gtx_transform
/// @see gtx_transform2
/// 
/// @defgroup gtc_matrix_transform GLM_GTC_matrix_transform
/// @ingroup gtc
/// 
/// @brief Defines functions that generate common transformation matrices.
/// 
/// The matrices generated by this extension use standard OpenGL fixed-function
/// conventions. For example, the lookAt function generates a transform from world
/// space into the specific eye space that the projective matrix functions 
/// (perspective, ortho, etc) are designed to expect. The OpenGL compatibility
/// specifications defines the particular layout of this eye space.
/// 
/// <glm/gtc/matrix_transform.hpp> need to be included to use these functionalities.
///////////////////////////////////////////////////////////////////////////////////

#pragma once

// Dependencies
#include "../mat4x4.hpp"
#include "../vec2.hpp"
#include "../vec3.hpp"
#include "../vec4.hpp"
#include "../gtc/constants.hpp"

#if(defined(GLM_MESSAGES) && !defined(GLM_EXT_INCLUDED))
#	pragma message("GLM: GLM_GTC_matrix_transform extension included")
#endif

namespace glm
{
	/// @addtogroup gtc_matrix_transform
	/// @{

	/// Builds a translation 4 * 4 matrix created from a vector of 3 components.
	/// 
	/// @param m Input matrix multiplied by this translation matrix.
	/// @param v Coordinates of a translation vector.
	/// @tparam T Value type used to build the matrix. Currently supported: half (not recommanded), float or double.
	/// @code
	/// #include <glm/glm.hpp>
	/// #include <glm/gtc/matrix_transform.hpp>
	/// ...
	/// glm::mat4 m = glm::translate(glm::mat4(1.0f), glm::vec3(1.0f));
	/// // m[0][0] == 1.0f, m[0][1] == 0.0f, m[0][2] == 0.0f, m[0][3] == 0.0f
	/// // m[1][0] == 0.0f, m[1][1] == 1.0f, m[1][2] == 0.0f, m[1][3] == 0.0f
	/// // m[2][0] == 0.0f, m[2][1] == 0.0f, m[2][2] == 1.0f, m[2][3] == 0.0f
	/// // m[3][0] == 1.0f, m[3][1] == 1.0f, m[3][2] == 1.0f, m[3][3] == 1.0f
	/// @endcode
	/// @see gtc_matrix_transform
	/// @see - translate(tmat4x4<T, P> const & m, T x, T y, T z)
	/// @see - translate(tvec3<T, P> const & v)
	template <typename T, precision P>
	GLM_FUNC_DECL tmat4x4<T, P> translate(
		tmat4x4<T, P> const & m,
		tvec3<T, P> const & v);
		
	/// Builds a rotation 4 * 4 matrix created from an axis vector and an angle. 
	/// 
	/// @param m Input matrix multiplied by this rotation matrix.
	/// @param angle Rotation angle expressed in radians.
	/// @param axis Rotation axis, recommanded to be normalized.
	/// @tparam T Value type used to build the matrix. Supported: half, float or double.
	/// @see gtc_matrix_transform
	/// @see - rotate(tmat4x4<T, P> const & m, T angle, T x, T y, T z) 
	/// @see - rotate(T angle, tvec3<T, P> const & v) 
	template <typename T, precision P>
	GLM_FUNC_DECL tmat4x4<T, P> rotate(
		tmat4x4<T, P> const & m,
		T angle,
		tvec3<T, P> const & axis);

	/// Builds a scale 4 * 4 matrix created from 3 scalars. 
	/// 
	/// @param m Input matrix multiplied by this scale matrix.
	/// @param v Ratio of scaling for each axis.
	/// @tparam T Value type used to build the matrix. Currently supported: half (not recommanded), float or double.
	/// @see gtc_matrix_transform
	/// @see - scale(tmat4x4<T, P> const & m, T x, T y, T z)
	/// @see - scale(tvec3<T, P> const & v)
	template <typename T, precision P>
	GLM_FUNC_DECL tmat4x4<T, P> scale(
		tmat4x4<T, P> const & m,
		tvec3<T, P> const & v);

	/// Creates a matrix for an orthographic parallel viewing volume.
	/// 
	/// @param left 
	/// @param right 
	/// @param bottom 
	/// @param top 
	/// @param zNear 
	/// @param zFar 
	/// @tparam T Value type used to build the matrix. Currently supported: half (not recommanded), float or double.
	/// @see gtc_matrix_transform
	/// @see - glm::ortho(T const & left, T const & right, T const & bottom, T const & top)
	template <typename T>
	GLM_FUNC_DECL tmat4x4<T, defaultp> ortho(
		T left,
		T right,
		T bottom,
		T top,
		T zNear,
		T zFar);

	/// Creates a matrix for projecting two-dimensional coordinates onto the screen.
	/// 
	/// @param left 
	/// @param right 
	/// @param bottom 
	/// @param top 
	/// @tparam T Value type used to build the matrix. Currently supported: half (not recommanded), float or double.
	/// @see gtc_matrix_transform
	/// @see - glm::ortho(T const & left, T const & right, T const & bottom, T const & top, T const & zNear, T const & zFar)
	template <typename T>
	GLM_FUNC_DECL tmat4x4<T, defaultp> ortho(
		T left,
		T right,
		T bottom,
		T top);

	/// Creates a frustum matrix.
	/// 
	/// @param left 
	/// @param right 
	/// @param bottom 
	/// @param top 
	/// @param near 
	/// @param far 
	/// @tparam T Value type used to build the matrix. Currently supported: half (not recommanded), float or double.
	/// @see gtc_matrix_transform
	template <typename T>
	GLM_FUNC_DECL tmat4x4<T, defaultp> frustum(
		T left,
		T right,
		T bottom,
		T top,
		T near,
		T far);

	/// Creates a matrix for a symetric perspective-view frustum.
	/// 
	/// @param fovy Specifies the field of view angle, in degrees, in the y direction. Expressed in radians.
	/// @param aspect Specifies the aspect ratio that determines the field of view in the x direction. The aspect ratio is the ratio of x (width) to y (height).
	/// @param near Specifies the distance from the viewer to the near clipping plane (always positive).
	/// @param far Specifies the distance from the viewer to the far clipping plane (always positive).
	/// @tparam T Value type used to build the matrix. Currently supported: half (not recommanded), float or double.
	/// @see gtc_matrix_transform
	template <typename T>
	GLM_FUNC_DECL tmat4x4<T, defaultp> perspective(
		T fovy,
		T aspect,
		T near,
		T far);

	/// Builds a perspective projection matrix based on a field of view.
	/// 
	/// @param fov Expressed in radians.
	/// @param width 
	/// @param height 
	/// @param near Specifies the distance from the viewer to the near clipping plane (always positive).
	/// @param far Specifies the distance from the viewer to the far clipping plane (always positive).
	/// @tparam T Value type used to build the matrix. Currently supported: half (not recommanded), float or double.
	/// @see gtc_matrix_transform
	template <typename T>
	GLM_FUNC_DECL tmat4x4<T, defaultp> perspectiveFov(
		T fov,
		T width,
		T height,
		T near,
		T far);

	/// Creates a matrix for a symmetric perspective-view frustum with far plane at infinite.
	/// 
	/// @param fovy Specifies the field of view angle, in degrees, in the y direction. Expressed in radians.
	/// @param aspect Specifies the aspect ratio that determines the field of view in the x direction. The aspect ratio is the ratio of x (width) to y (height).
	/// @param near Specifies the distance from the viewer to the near clipping plane (always positive).
	/// @tparam T Value type used to build the matrix. Currently supported: half (not recommanded), float or double.
	/// @see gtc_matrix_transform
	template <typename T>
	GLM_FUNC_DECL tmat4x4<T, defaultp> infinitePerspective(
		T fovy, T aspect, T near);

	/// Creates a matrix for a symmetric perspective-view frustum with far plane at infinite for graphics hardware that doesn't support depth clamping.
	/// 
	/// @param fovy Specifies the field of view angle, in degrees, in the y direction. Expressed in radians.
	/// @param aspect Specifies the aspect ratio that determines the field of view in the x direction. The aspect ratio is the ratio of x (width) to y (height).
	/// @param near Specifies the distance from the viewer to the near clipping plane (always positive).
	/// @tparam T Value type used to build the matrix. Currently supported: half (not recommanded), float or double.
	/// @see gtc_matrix_transform
	template <typename T>
	GLM_FUNC_DECL tmat4x4<T, defaultp> tweakedInfinitePerspective(
		T fovy, T aspect, T near);

	/// Creates a matrix for a symmetric perspective-view frustum with far plane at infinite for graphics hardware that doesn't support depth clamping.
	/// 
	/// @param fovy Specifies the field of view angle, in degrees, in the y direction. Expressed in radians.
	/// @param aspect Specifies the aspect ratio that determines the field of view in the x direction. The aspect ratio is the ratio of x (width) to y (height).
	/// @param near Specifies the distance from the viewer to the near clipping plane (always positive).
	/// @param ep 
	/// @tparam T Value type used to build the matrix. Currently supported: half (not recommanded), float or double.
	/// @see gtc_matrix_transform
	template <typename T>
	GLM_FUNC_DECL tmat4x4<T, defaultp> tweakedInfinitePerspective(
		T fovy, T aspect, T near, T ep);

	/// Map the specified object coordinates (obj.x, obj.y, obj.z) into window coordinates.
	/// 
	/// @param obj Specify the object coordinates.
	/// @param model Specifies the current modelview matrix
	/// @param proj Specifies the current projection matrix
	/// @param viewport Specifies the current viewport
	/// @return Return the computed window coordinates.
	/// @tparam T Native type used for the computation. Currently supported: half (not recommanded), float or double.
	/// @tparam U Currently supported: Floating-point types and integer types.
	/// @see gtc_matrix_transform
	template <typename T, typename U, precision P>
	GLM_FUNC_DECL tvec3<T, P> project(
		tvec3<T, P> const & obj,
		tmat4x4<T, P> const & model,
		tmat4x4<T, P> const & proj,
		tvec4<U, P> const & viewport);

	/// Map the specified window coordinates (win.x, win.y, win.z) into object coordinates.
	///
	/// @param win Specify the window coordinates to be mapped.
	/// @param model Specifies the modelview matrix
	/// @param proj Specifies the projection matrix
	/// @param viewport Specifies the viewport
	/// @return Returns the computed object coordinates.
	/// @tparam T Native type used for the computation. Currently supported: half (not recommanded), float or double.
	/// @tparam U Currently supported: Floating-point types and integer types.
	/// @see gtc_matrix_transform
	template <typename T, typename U, precision P>
	GLM_FUNC_DECL tvec3<T, P> unProject(
		tvec3<T, P> const & win,
		tmat4x4<T, P> const & model,
		tmat4x4<T, P> const & proj,
		tvec4<U, P> const & viewport);

	/// Define a picking region
	///
	/// @param center
	/// @param delta
	/// @param viewport
	/// @tparam T Native type used for the computation. Currently supported: half (not recommanded), float or double.
	/// @tparam U Currently supported: Floating-point types and integer types.
	/// @see gtc_matrix_transform
	template <typename T, precision P, typename U>
	GLM_FUNC_DECL tmat4x4<T, P> pickMatrix(
		tvec2<T, P> const & center,
		tvec2<T, P> const & delta,
		tvec4<U, P> const & viewport);

	/// Build a look at view matrix.
	///
	/// @param eye Position of the camera
	/// @param center Position where the camera is looking at
	/// @param up Normalized up vector, how the camera is oriented. Typically (0, 0, 1)
	/// @see gtc_matrix_transform
	/// @see - frustum(T const & left, T const & right, T const & bottom, T const & top, T const & nearVal, T const & farVal) frustum(T const & left, T const & right, T const & bottom, T const & top, T const & nearVal, T const & farVal)
	template <typename T, precision P>
	GLM_FUNC_DECL tmat4x4<T, P> lookAt(
		tvec3<T, P> const & eye,
		tvec3<T, P> const & center,
		tvec3<T, P> const & up);

	/// @}
}//namespace glm

#include "matrix_transform.inl"
