#pragma once

/// @Mohammed Sadek Guerrah //// 

#include <iostream>
//#include "laeBase.hpp"

namespace matrixgl {

    class mat2
    {
      private:
        float a , b ,
              c , d ;
     
           const static int space = 2 ;
           float data[space][space];

      public:
        mat2() {
        for (int i = 0; i < space; ++i)
            for (int j = 0; j < space; ++j)
                data[i][j] = 0.0f; // Initialize with zeros
    }

        mat2(float a, float b , float  c , float d): a(a),b(b),c(c),d(d) {
                               data[0][0] = a; data[0][1] = b;
                               data[1][0] = c; data[1][1] = d;
        }

               float* operator[](size_t i) {
        if (i >= 2)
            throw std::out_of_range("Row index out of range");
        return data[i];
      }
         const float* operator[](size_t i) const {
        if (i >= 2)
            throw std::out_of_range("Row index out of range");
        return data[i];
    }
  };

    class mat3 {

private:
    const static int space = 3;
    float data[space][space]; // 2D array for 3x3 matrix
    float a,b,c,d,e,f,g,h,i; 
public:
    mat3() {
        for (int i = 0; i < space; ++i)
            for (int j = 0; j < space; ++j)
                data[i][j] = 0.0f; // Initialize with zeros
    }
    mat3(float a, float b, float c,
         float d, float e, float f,
         float g, float h, float i) {
        data[0][0] = a; data[0][1] = b; data[0][2] = c;
        data[1][0] = d; data[1][1] = e; data[1][2] = f;
        data[2][0] = g; data[2][1] = h; data[2][2] = i;
    }
    float* operator[](size_t i) {
        if (i >= space)
            throw std::out_of_range("Row index out of range");
        return data[i];
    }
    const float* operator[](size_t i) const {
        if (i >= space)
            throw std::out_of_range("Row index out of range");
        return data[i];
    }
  };
}  
