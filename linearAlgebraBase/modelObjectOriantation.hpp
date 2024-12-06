#pragma once
#include "laeBase.hpp"

/// @Mohammed Sadek Guerrah //// 
/*Based Class*/
class matrix4 {
public:
    float a, b, c, d,
          e, f, g, h,
          i, j, k, l,
          m, n, o, p;

    // Default constructor (sets all components to 0)
    matrix4() : a(0), b(0), c(0), d(0),
                e(0), f(0), g(0), h(0),
                i(0), j(0), k(0), l(0),
                m(0), n(0), o(0), p(0) {}

    // Constructor for a single float (sets all components to the same value)
    matrix4(float val) : a(val), b(val), c(val), d(val),
                         e(val), f(val), g(val), h(val),
                         i(val), j(val), k(val), l(val),
                         m(val), n(val), o(val), p(val) {}
    
    ///Constructing a matrix 4x4 from 4 4Dvectors
    matrix4(ogl::vec4 vector1,ogl::vec4 vector2,ogl::vec4 vector3,ogl::vec4 vector4) : a(vector1.x), b(vector1.y), c(vector1.z), d(vector1.w),
                                                                                       e(vector2.x), f(vector2.y), g(vector2.z), h(vector2.w),
                                                                                       i(vector3.x), j(vector3.y), k(vector3.z), l(vector3.w),
                                                                                       m(vector4.x), n(vector4.y), o(vector4.z), p(vector4.w) {}
    // Fully parameterized constructor
    matrix4(float a, float b, float c, float d,
            float e, float f, float g, float h,
            float i, float j, float k, float l,
            float m, float n, float o, float p)
        : a(a), b(b), c(c), d(d),
          e(e), f(f), g(g), h(h),
          i(i), j(j), k(k), l(l),
          m(m), n(n), o(o), p(p) {}

              // Matrix addition
    matrix4 operator+(const matrix4& other) const {
        return matrix4(a + other.a, b + other.b, c + other.c, d + other.d,
                       e + other.e, f + other.f, g + other.g, h + other.h,
                       i + other.i, j + other.j, k + other.k, l + other.l,
                       m + other.m, n + other.n, o + other.o, p + other.p);
    }

    // Matrix subtraction
    matrix4 operator-(const matrix4& other) const {
        return matrix4(a - other.a, b - other.b, c - other.c, d - other.d,
                       e - other.e, f - other.f, g - other.g, h - other.h,
                       i - other.i, j - other.j, k - other.k, l - other.l,
                       m - other.m, n - other.n, o - other.o, p - other.p);
    }

    // Scalar multiplication
    matrix4 operator*(float scalar) const {
        return matrix4(a * scalar, b * scalar, c * scalar, d * scalar,
                       e * scalar, f * scalar, g * scalar, h * scalar,
                       i * scalar, j * scalar, k * scalar, l * scalar,
                       m * scalar, n * scalar, o * scalar, p * scalar);
    }

    // Matrix multiplication
    matrix4 operator*(const matrix4& other) const {
        return matrix4(
            a * other.a + b * other.e + c * other.i + d * other.m,
            a * other.b + b * other.f + c * other.j + d * other.n,
            a * other.c + b * other.g + c * other.k + d * other.o,
            a * other.d + b * other.h + c * other.l + d * other.p,

            e * other.a + f * other.e + g * other.i + h * other.m,
            e * other.b + f * other.f + g * other.j + h * other.n,
            e * other.c + f * other.g + g * other.k + h * other.o,
            e * other.d + f * other.h + g * other.l + h * other.p,

            i * other.a + j * other.e + k * other.i + l * other.m,
            i * other.b + j * other.f + k * other.j + l * other.n,
            i * other.c + j * other.g + k * other.k + l * other.o,
            i * other.d + j * other.h + k * other.l + l * other.p,

            m * other.a + n * other.e + o * other.i + p * other.m,
            m * other.b + n * other.f + o * other.j + p * other.n,
            m * other.c + n * other.g + o * other.k + p * other.o,
            m * other.d + n * other.h + o * other.l + p * other.p);
    }

    private:
           // Determinant helper function
    float determinant() const {
        return a * (f * (k * p - l * o) - g * (j * p - l * n) + h * (j * o - k * n))
             - b * (e * (k * p - l * o) - g * (i * p - l * m) + h * (i * o - k * m))
             + c * (e * (j * p - l * n) - f * (i * p - l * m) + h * (i * n - j * m))
             - d * (e * (j * o - k * n) - f * (i * o - k * m) + g * (i * n - j * m));
    }
    public:
    // Inverse function
    matrix4 inverse() const {
        float det = determinant();
        if (det == 0) {
            throw std::runtime_error("Matrix is singular and cannot be inverted.");
        }

        float inv_det = 1.0f / det;

        // Adjugate matrix (cofactor transpose)
        return matrix4(
            inv_det * (f * (k * p - l * o) - g * (j * p - l * n) + h * (j * o - k * n)),
            inv_det * -(b * (k * p - l * o) - c * (j * p - l * n) + d * (j * o - k * n)),
            inv_det * (b * (g * p - h * o) - c * (f * p - h * n) + d * (f * o - g * n)),
            inv_det * -(b * (g * l - h * k) - c * (f * l - h * j) + d * (f * k - g * j)),

            inv_det * -(e * (k * p - l * o) - g * (i * p - l * m) + h * (i * o - k * m)),
            inv_det * (a * (k * p - l * o) - c * (i * p - l * m) + d * (i * o - k * m)),
            inv_det * -(a * (g * p - h * o) - c * (e * p - h * m) + d * (e * o - g * m)),
            inv_det * (a * (g * l - h * k) - c * (e * l - h * i) + d * (e * k - g * i)),

            inv_det * (e * (j * p - l * n) - f * (i * p - l * m) + h * (i * n - j * m)),
            inv_det * -(a * (j * p - l * n) - b * (i * p - l * m) + d * (i * n - j * m)),
            inv_det * (a * (f * p - h * n) - b * (e * p - h * m) + d * (e * n - f * m)),
            inv_det * -(a * (f * l - h * j) - b * (e * l - h * i) + d * (e * j - f * i)),

            inv_det * -(e * (j * o - k * n) - f * (i * o - k * m) + g * (i * n - j * m)),
            inv_det * (a * (j * o - k * n) - b * (i * o - k * m) + c * (i * n - j * m)),
            inv_det * -(a * (f * o - g * n) - b * (e * o - g * m) + c * (e * n - f * m)),
            inv_det * (a * (f * k - g * j) - b * (e * k - g * i) + c * (e * j - f * i))
        );
    }
    // Print matrix for debugging
    void print() const {
        std::cout << a << " " << b << " " << c << " " << d << "\n"
                  << e << " " << f << " " << g << " " << h << "\n"
                  << i << " " << j << " " << k << " " << l << "\n"
                  << m << " " << n << " " << o << " " << p << "\n";
    }
};

namespace ogl { 

  vec3 getDirection(vec2& changeMposition) {
      vec3 Direction = vec3(0,0,0);
         changeMposition += vec2(0,-0.5);

   Direction.x = cos(changeMposition.x) * cos(changeMposition.y);
   Direction.y = sin(changeMposition.y);
   Direction.z = sin(changeMposition.x) * cos(changeMposition.y); 
   return Direction.normalize();
  }   

  matrix4 lookAt(vec3& Direction ,vec3& center,vec3& up) {

    matrix4 product =  matrix4(0.0f);

      vec3 x = vec3(0.0f,0.0f,0.0f);
      vec3 y = vec3(0.0f,0.0f,0.0f);
      vec3 z = vec3(0.0f,0.0f,0.0f);

        z = Direction - center;
          z.normalize();
          y = up;
          x = y.cross(z);
        y = z.cross(x);
        x.normalize();
        y.normalize();

        product.a = x.x; product.b = y.x ; product.c = z.x;
        product.e = x.y; product.f = y.y ; product.g = z.y;
        product.i = x.z; product.j = y.z ; product.k = z.z;
        product.m = -x.dot(Direction); product.n = -y.dot(Direction); product.o = -z.dot(Direction);
  
        product.p = 1.0f;

    return product;
  }

  matrix4 prespective(vec2& resolution, float& fov, float& farClip , float& nearClip) {

      float aspect_ratio = resolution.x / resolution.y;
        
      float e = 1.0f/(tan(basic::radians(fov)/2.0f));
      float a = e * (1.0f/aspect_ratio); 
         float c = -(farClip+nearClip)/(farClip-nearClip);
         float d = -(2.0f * farClip * nearClip)/(farClip-nearClip);

    return matrix4(a,0,0,0,
                   0,e,0,0,
                   0,0,c,d,
                   0,0,-1,0);
  }
}

/*Common*/
class obj {};
class texture {};
class model {};
class camera {

private:
    ogl::vec4 mmContribution = ogl::vec4(0,0,0,0); //For modelMouse ?
    ogl::vec3 up = ogl::vec3(0.0,1.0,0.0);
    float nearClip, farClip;
    float m_CameraSpeed;

       ogl::vec2 changeInMousePosition = ogl::vec2(0,0);

public:
    matrix4 m_viewModelMatrix = matrix4(0.0f);
    matrix4 m_InverseViewModelMatrix = matrix4(0.0f);
    matrix4 m_projectModelMatrix = matrix4(0.0f);
    matrix4 m_InverseProjectModelMatrix = matrix4(0.0f);
      
      ogl::vec3 Direction = ogl::vec3(0,0,0);
      ogl::vec3 position = ogl::vec3(0.0,0.0,0.0);
        float FOV , focalLength ; 
          
         camera() {}

         camera(ogl::vec4 mmContribution ,ogl::vec3 position,float CameraSpeed, float FOV , float farClip , float nearClip): position(position),m_CameraSpeed(CameraSpeed), FOV(FOV) {

             ogl::vec2 resolutionContribution = ogl::vec2(mmContribution.z,mmContribution.w);
             ogl::vec2 mousePosition = ogl::vec2(mmContribution.x,mmContribution.y);
             ogl::vec3 Direction = ogl::vec3(0.0,0.0,0.0);
             //Contribution --> Direction VV
                    
                    mousePosition /= resolutionContribution;
                    mousePosition = mousePosition*2.0f - ogl::vec2(1.0f,1.0f);
                  
                    mousePosition.x = mousePosition.x - resolutionContribution.x/2.0f;
                    mousePosition.y = -mousePosition.y - resolutionContribution.y/2.0f;
                      float pitch = mousePosition.y*CameraSpeed;
                      float yaw = mousePosition.x*CameraSpeed;

                    changeInMousePosition = ogl::vec2(yaw,pitch);    
                  Direction = ogl::getDirection(changeInMousePosition);      
              
             m_projectModelMatrix = ogl::prespective(resolutionContribution,FOV,farClip,nearClip);
             m_InverseProjectModelMatrix = m_projectModelMatrix.inverse();             
             m_viewModelMatrix = ogl::lookAt(Direction , position , up);
             m_InverseViewModelMatrix = m_viewModelMatrix.inverse(); 
         }
                       
};