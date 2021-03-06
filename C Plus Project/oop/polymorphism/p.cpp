/*
The word polymorphism means having many forms . 
Typically , polymorphism occurs  when there is a hierarchy
of classes and they are related by inheritance.

C++ polymorphism means that a call to a member function will
cause a different funtion to be executed depending on
the type of object that invokes the funtion.	
*/

#include <iostream> 
using namespace std;
 
class Shape {
   protected:
      int width, height;
   public:
      Shape( int a=0, int b=0)
      {
         width = a;
         height = b;
      }
      int area()
      {
         cout << "Parent class area :" <<endl;
         return 0;
      }
};
class Rectangle: public Shape{
   public:
      Rectangle( int a=0, int b=0):Shape(a, b) { }
      int area ()
      { 
         cout << "Rectangle class area :" <<endl;
         return (width * height); 
      }
};
class Triangle: public Shape{
   public:
      Triangle( int a=0, int b=0):Shape(a, b) { }
      int area ()
      { 
         cout << "Triangle class area :" <<endl;
         return (width * height / 2); 
      }
};
// Main function for the program
int main( )
{
   Shape *shape;
   Rectangle rec(10,7);
   Triangle  tri(10,5);

   // store the address of Rectangle
   shape = &rec;
   // call rectangle area.
   ((Rectangle*)shape)->area();

   // store the address of Triangle
   shape = &tri;
   // call triangle area.
   ((triangle*)shape)->area();
   
   return 0;
}
/*
The reason for the incorrect output is that 
the call of the function area() is being set once by 
the compiler as the version defined in the base class. 
This is called static resolution of the function call, 
or static linkage - the function call is fixed before the program 
is executed. This is also sometimes called early binding 
because the area() function is set during the compilation of 
the program.

*/