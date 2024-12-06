#pragma once
#include <iostream>
#include <vector>
#include <math.h>
#include <array>
#include <stdexcept>

#define PI 3.14159265359 //for this header

/// @Mohammed Sadek Guerrah //// 
///LINEAR ALGEBRA OPERATION FUNCTION + MATRIX OPERATIONS ///
namespace constants {
   /// its better to use "using namespace constants " in your .cpp ///
   const float pi = 3.14159265359;
   const float two_PI = 3.14159265359*2.0f; /// for hemisphere Distribution || or for cosWeightedDistribution 
   const float Tau = two_PI;
   const float e = 2.71828182846;
   const float PythagorasConst = 1.4142135623;
   const float TheodorusConst = 1.7320508075;
   const float gPhi = 1.6180339887; //Golden Ratio//
   const float gTheta = 2.39996; //Golden Angel//
   const float eulerConst = 0.5772156649;
   const float Omega = 0.5671432904;
   const float p = 1.32471;
}

namespace basic {
  float radians(float Degree) {
    return Degree * (PI/180.0f); 
}
}

namespace lao {

    float ilength(std::vector<int> invec) {
        ///Calculate the length of a integer based vector 
      return sqrt((invec[0]*invec[0]) + (invec[1]*invec[1]) + (invec[2]*invec[2]) + (invec[3] * invec[3]));
    }
    float length(std::vector<float> invec) {
        ///Calculate the length of a float based vector
      return sqrt((invec[0]*invec[0]) + (invec[1]*invec[1]) + (invec[2]*invec[2]) + (invec[3] * invec[3]));
    }

    float idot(std::vector<int> invec1 ,std::vector<int> invec2) {
        ///Calculate the dot-product of a integer based vector
      return ((invec1[0]*invec2[0]) + (invec1[1]*invec2[1]) + (invec1[2]*invec2[2]) + (invec1[3] * invec2[3]));
    } 
    float dot(std::vector<float> invec1 ,std::vector<float> invec2) {
        ///Calculate the dot-product of a float based vector
      return ((invec1[0]*invec2[0]) + (invec1[1]*invec2[1]) + (invec1[2]*invec2[2]) + (invec1[3] * invec2[3]));
    } 

    std::vector<float> normalize(std::vector<float> invec) { 
        ///Normalize a float based vector "for v is a vector ; v = v/||v||"  
        return std::vector<float> {invec[0]/length(invec),invec[1]/length(invec),invec[2]/length(invec),invec[3]/length(invec)};
    }
    std::vector<float> inormalize(std::vector<int> invec) {   
         ///Normalize a integer based vector "for v is a vector ; v = v/||v||"  
        return std::vector<float> {invec[0]/ilength(invec),invec[1]/ilength(invec),invec[2]/ilength(invec),invec[3]/ilength(invec)};
    }
    std::vector<float> scale(std::vector<float> invec , float scale) {
        ///Multipling a float based vector by a scaler
      return std::vector<float> {invec[0]*scale ,invec[1]*scale,invec[2]*scale,invec[3]*scale };
    }
        std::vector<int> intscale(std::vector<int> invec , int scale) {
        ///Multipling a integer based vector by a scaler
      return std::vector<int> {invec[0]*scale ,invec[1]*scale,invec[2]*scale,invec[3]*scale };
    }

    std::vector<float> cross(const std::vector<double>& vec1, const std::vector<double>& vec2) {
    if (vec1.size() != 3 || vec2.size() != 3) {
        throw std::invalid_argument("Incorrect Operation ! one of the vectors is not a 3D vector, make sure that both vectors are 3D vectors ");
        
    }

    // Compute the cross product
    std::vector<float> result(3);
    result[0] = vec1[1] * vec2[2] - vec1[2] * vec2[1];
    result[1] = vec1[2] * vec2[0] - vec1[0] * vec2[2];
    result[2] = vec1[0] * vec2[1] - vec1[1] * vec2[0];

    return result;
}

}
namespace basicVectorOperations {

    //use | using namespace basicVectorOperations; in your main cpp for saving writing //
   std::vector<float> mull(std::vector<float> invec1 ,std::vector<float> invec2) {
    return std::vector<float> {invec1[0]*invec2[0],invec1[1]*invec2[1],invec1[2]*invec2[2],invec1[3]*invec2[3]};
   }
    std::vector<int> mull(std::vector<int> invec1 ,std::vector<int> invec2) {
    return std::vector<int> {invec1[0]*invec2[0],invec1[1]*invec2[1],invec1[2]*invec2[2],invec1[3]*invec2[3]};
   }

   std::vector<float> add(std::vector<float> invec1 ,std::vector<float> invec2) {
    return std::vector<float> {invec1[0]+invec2[0],invec1[1]+invec2[1],invec1[2]+invec2[2],invec1[3]+invec2[3]};
   }
    std::vector<int> add(std::vector<int> invec1 ,std::vector<int> invec2) {
    return std::vector<int> {invec1[0]+invec2[0],invec1[1]+invec2[1],invec1[2]+invec2[2],invec1[3]+invec2[3]};
   }   
   
   std::vector<float> sub(std::vector<float> invec1 ,std::vector<float> invec2) {
    return std::vector<float> {invec1[0]-invec2[0],invec1[1]-invec2[1],invec1[2]-invec2[2],invec1[3]-invec2[3]};
   }
    std::vector<int> sub(std::vector<int> invec1 ,std::vector<int> invec2) {
    return std::vector<int> {invec1[0]-invec2[0],invec1[1]-invec2[1],invec1[2]-invec2[2],invec1[3]-invec2[3]};
   }  

      std::vector<float> divide(std::vector<float> invec1 ,std::vector<float> invec2) {
    return std::vector<float> {invec1[0]/invec2[0],invec1[1]/invec2[1],invec1[2]/invec2[2],invec1[3]/invec2[3]};
   }
    std::vector<float> divide(std::vector<int> invec1 ,std::vector<int> invec2) {
    return std::vector<float> {float(invec1[0])/float(invec2[0]),float(invec1[1])/float(invec2[1]),float(invec1[2])/float(invec2[2]),float(invec1[3])/float(invec2[3])};
   }
}

namespace ogl {

    class vec2 {
    public: float x,y; 
    float r = x , g = y; 
    
      vec2() { x = y = 0.0f;}
      vec2(float val) {x = y = val; }  
      vec2(float x,float y) : x(x) , y(y) {} 

    /*Swizzling*/ 
    vec2 xx() const { return vec2(x, x); }
    vec2 xy() const { return vec2(x, y); }
    vec2 yx() const { return vec2(y, x); }
    vec2 yy() const { return vec2(y, y); }  
    
        vec2& operator+=(const vec2& other) {
        x += other.x;
        y += other.y;
        return *this;
        }
        vec2& operator-=(const vec2& other) {
        x -= other.x;
        y -= other.y;
        return *this;
        }
        vec2& operator*=(const vec2& other) {
        x *= other.x;
        y *= other.y;
        return *this;
        }
        vec2& operator/=(const vec2& other) {
        x /= other.x;
        y /= other.y;
        return *this;
        }
        vec2& operator*=(float scalar) {
        x *= scalar;
        y *= scalar;
        return *this;
    }
        vec2& operator/=(float scalar) {
        x /= scalar;
        y /= scalar;
        return *this;
    }
    /*general Vector operation*/
      vec2 operator+(const vec2& other) const { return vec2(x + other.x, y + other.y); }
      vec2 operator-(const vec2& other) const { return vec2(x - other.x, y - other.y); }
      vec2 operator*(const vec2& other) const { return vec2(x * other.x, y * other.y); }
      vec2 operator/(const vec2& other) const { return vec2(x / other.x, y / other.y); }
      vec2 operator*(float scalar) const { return vec2(x * scalar, y * scalar); }
      vec2 operator/(float scalar) const { return vec2(x / scalar, y / scalar); } 

      float length() {
         return sqrt((x*x)+(y*y));
      }
      vec2 normalize() {return vec2(x/length(),y/length());} 

      float dot(vec2& invec) {
        return ((x*invec.x) + (y*invec.y));}
      vec2 cross(vec2 v2) { 
        std::cout << "invalid Operation cross X works only with 3D vectors obj.xyz" << std::endl;
        return vec2(0,0);
      }  
     }; 

    class vec3 {
    public: float x,y,z; 
     float r = x , g = y , b = z; 

    vec3() {x=y=z=0.0f;}
    vec3(float val) {x=y=z=val;}  
    vec3(float x,float y, float zs) : x(x) , y(y) , z(z) {} 

   /*Swizzling*/  
    vec3 xxx() const { return vec3(x,x,x); }
    vec3 xyx() const { return vec3(x,y,x); }
    vec3 xxz() const { return vec3(x,x,z); }
    vec3 xzx() const { return vec3(x,z,x); }    
    vec3 xzy() const { return vec3(x,z,y); }
    vec3 xzz() const { return vec3(x,z,z); }
    vec3 xyy() const { return vec3(x,y,y); }
    vec3 yyy() const { return vec3(y,y,y); }
    vec3 yxx() const { return vec3(y,x,x); }
    vec3 yyx() const { return vec3(y,y,x); }
    vec3 yxz() const { return vec3(y,x,z); }
    vec3 yzx() const { return vec3(y,z,x); }    
    vec3 yzy() const { return vec3(y,z,y); }
    vec3 yzz() const { return vec3(y,z,z); }
    vec3 zzz() const { return vec3(z,z,z); }
    vec3 zxx() const { return vec3(z,x,x); }
    vec3 zyx() const { return vec3(z,y,x); }
    vec3 zyz() const { return vec3(z,y,z); }
    vec3 zxz() const { return vec3(z,x,z); }
    vec3 zzx() const { return vec3(z,z,x); }    
    vec3 zzy() const { return vec3(z,z,y); }
    vec3 zyy() const { return vec3(z,y,y); }
    
    /*general Vector operation*/
        vec3& operator+=(const vec3& other) {
        x += other.x;
        y += other.y;
        z += other.z;
        return *this;
        }
        vec3& operator-=(const vec3& other) {
        x -= other.x;
        y -= other.y;
        z -= other.z;
        return *this;
        }
        vec3& operator*=(const vec3& other) {
        x *= other.x;
        y *= other.y;
        z *= other.z;        
        return *this;
        }
        vec3& operator/=(const vec3& other) {
        x /= other.x;
        y /= other.y;
        z /= other.z; 
        return *this;
        }
        vec3& operator*=(float scalar) {
        x *= scalar;
        y *= scalar;
        z *= scalar;         
        return *this;
    }
        vec3& operator/=(float scalar) {
        x /= scalar;
        y /= scalar;
        z /= scalar;         
        return *this;
    }

      vec3 operator+(const vec3& other) const { return vec3(x + other.x, y + other.y,z + other.z); }
      vec3 operator-(const vec3& other) const { return vec3(x - other.x, y - other.y,z - other.z); }
      vec3 operator*(const vec3& other) const { return vec3(x * other.x, y * other.y,z * other.z); }
      vec3 operator/(const vec3& other) const { return vec3(x / other.x, y / other.y,z / other.z); }

      vec3 operator+(float scalar) const { return vec3(x + scalar, y + scalar , z + scalar); }
      vec3 operator-(float scalar) const { return vec3(x - scalar, y - scalar , z - scalar); } 
      vec3 operator*(float scalar) const { return vec3(x * scalar, y * scalar , z * scalar); }
      vec3 operator/(float scalar) const { return vec3(x / scalar, y / scalar , z / scalar); }  
          // Scalar multiplication (vec3 * float)
       vec3 operator*(float scalar)  {
        return vec3(x * scalar, y * scalar, z * scalar);
    }

            float length() {
         return sqrt((x*x)+(y*y)+(z*z)); }
         vec3 normalize() {
             return vec3(x/length(),y/length(),z/length());} 
               float dot(vec3& invec3) {
        return ((x*invec3.x) + (y*invec3.y) + (z*invec3.z)); 
      }
      vec3 cross(vec3& v2) {

        vec3 product(0.0f,0.0f,0.0f);
        product.x =(y*v2.z) - (z*v2.y);
        product.y =(z*v2.x) - (x*v2.z);
        product.z =(x*v2.y) - (y*v2.x);
        return product;
      }

    };
    class vec4 {
    public: float x,y,z,w;  
         float r = x , g = y , b = z , a = w;
    vec4() {x=y=z=w=0.0f;}
    vec4(float val) {x=y=z=w=val;}      
    vec4(float x,float y, float z,float w) : x(x) , y(y) , z(z) , w(w) {} 

    ///Swizzling for 4D vector will be soon implimented 
        /* Swizzling */
    vec4 xxxx() const { return vec4(x, x, x, x); }
    vec4 xxxy() const { return vec4(x, x, x, y); }
    vec4 xxxz() const { return vec4(x, x, x, z); }
    vec4 xxxw() const { return vec4(x, x, x, w); }
    vec4 xxyx() const { return vec4(x, x, y, x); }
    vec4 xxyy() const { return vec4(x, x, y, y); }
    vec4 xxyz() const { return vec4(x, x, y, z); }
    vec4 xxyw() const { return vec4(x, x, y, w); }
    vec4 xxzx() const { return vec4(x, x, z, x); }
    vec4 xxzy() const { return vec4(x, x, z, y); }
    vec4 xxzz() const { return vec4(x, x, z, z); }
    vec4 xxzw() const { return vec4(x, x, z, w); }
    vec4 xxwx() const { return vec4(x, x, w, x); }
    vec4 xxwy() const { return vec4(x, x, w, y); }
    vec4 xxwz() const { return vec4(x, x, w, z); }
    vec4 xxww() const { return vec4(x, x, w, w); }
    vec4 xyxx() const { return vec4(x, y, x, x); }
    vec4 xyxy() const { return vec4(x, y, x, y); }
    vec4 xyxz() const { return vec4(x, y, x, z); }
    vec4 xyxw() const { return vec4(x, y, x, w); }
    vec4 xyyx() const { return vec4(x, y, y, x); }
    vec4 xyyy() const { return vec4(x, y, y, y); }
    vec4 xyyz() const { return vec4(x, y, y, z); }
    vec4 xyyw() const { return vec4(x, y, y, w); }
    vec4 xyzx() const { return vec4(x, y, z, x); }
    vec4 xyzy() const { return vec4(x, y, z, y); }
    vec4 xyzz() const { return vec4(x, y, z, z); }
    vec4 xyzw() const { return vec4(x, y, z, w); }
    vec4 xywx() const { return vec4(x, y, w, x); }
    vec4 xywy() const { return vec4(x, y, w, y); }
    vec4 xywz() const { return vec4(x, y, w, z); }
    vec4 xyww() const { return vec4(x, y, w, w); }

        /*general Vector operation*/
        vec4& operator+=(const vec4& other) {
        x += other.x;
        y += other.y;
        z += other.z;
        w += other.w;
        return *this;
        }
        vec4& operator-=(const vec4& other) {
        x -= other.x;
        y -= other.y;
        z -= other.z;
        w -= other.w;
        return *this;
        }
        vec4& operator*=(const vec4& other) {
        x *= other.x;
        y *= other.y;
        z *= other.z;
        w *= other.w;

        return *this;
        }
        vec4& operator/=(const vec4& other) {
        x /= other.x;
        y /= other.y;
        z /= other.z;
        w /= other.w; 
        return *this;
        }
        vec4& operator*=(float scalar) {
        x *= scalar;
        y *= scalar;
        z *= scalar;
        w *= scalar;         
        return *this;
    }
        vec4& operator/=(float scalar) {
        x /= scalar;
        y /= scalar;
        z /= scalar;
        w /= scalar;         
        return *this;
    }

      vec4 operator+(const vec4& other) const { return vec4(x + other.x, y + other.y, z + other.z, w + other.w); }
      vec4 operator-(const vec4& other) const { return vec4(x - other.x, y - other.y, z - other.z ,w - other.w); }
      vec4 operator*(const vec4& other) const { return vec4(x * other.x, y * other.y, z * other.z,w * other.w); }
      vec4 operator/(const vec4& other) const { return vec4(x / other.x, y / other.y, z / other.z , w / other.w); }
      
      vec4 operator*(float scalar) const { return vec4(x * scalar, y * scalar , z * scalar,w * scalar); }
      vec4 operator/(float scalar) const { return vec4(x / scalar, y / scalar , z / scalar,w / scalar); } 

        float length() {
         return sqrt((x*x)+(y*y)+(z*z)+(w*w));}
         vec4 normalize() {return vec4(x/length(),y/length(), z/length(), w/length());} 
        float dot(vec4& invec) {
        return ((x*invec.x) + (y*invec.y) + (z*invec.z) + (z*invec.z));
      }
             vec4 cross(vec4 v2) { 
        std::cout << "invalid Operation cross X works only with 3D vectors obj.xyz" << std::endl;
        return vec4(0,0,0,0);
      }    
    };
        vec3 cross(vec3& v1 , vec3& v2) {        
        vec3 product(0.0f,0.0f,0.0f);
        product.x =(v1.y*v2.z) - (v1.z*v2.y);
        product.y =(v1.z*v2.x) - (v1.x*v2.z);
        product.z =(v1.x*v2.y) - (v1.y*v2.x);

        return product;
      }
}
