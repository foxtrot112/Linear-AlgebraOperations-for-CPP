/////////////////////////////////////////
///USED FOR DEBUGING AND TESTING ONLY !!!////
///DON'T BOTHER LOOKING AT "main.cpp"
///ONlY for testing
/////////////////////////////
//بِسْمِ ٱللَّٰهِ ٱلرَّحْمَٰنِ ٱلرَّحِيمِ
//////////////////////////////


#include <iostream>

#include "linearAlgebraBase/laeMatrix.hpp"
#include "linearAlgebraBase/modelObjectOriantation.hpp"
#include "linearAlgebraBase/laeBase.hpp"

int width = 1920;
int height = 1080;

  int mousex =20;
  int mousey = -1;

    using namespace matrixgl ;
 
    namespace camera1PropertyTest {

    float fov = 60.0f;
    float speed = 1.1f;
    float farClip = 100.0f;
    float nearClip = 0.001;
      ogl::vec3 position = ogl::vec3(0,0,-3);

   }   
   
   using namespace ogl;
int main() {
     
     ogl::vec4 contri = ogl::vec4(width,height,mousex,mousey);
   
    camera cam1;
      cam1 = camera(contri,camera1PropertyTest::position,camera1PropertyTest::speed,camera1PropertyTest::fov,camera1PropertyTest::farClip,camera1PropertyTest::nearClip);

      matrix4 vmm = cam1.m_projectModelMatrix;
      
       vec4 testt;
     //  testt.w = 4.0f;
      std::cout << testt.w; 
      ///Simple Print()
    return 0;
}
