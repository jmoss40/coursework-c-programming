// I provided the calcArea function to calculate the area of the shape.

#include <stdio.h>
#include <math.h>
#include <string.h>

typedef enum {Rectangle, Circle} ShapeType ;
#define PI 3.1415

typedef struct {
    ShapeType st;
    union {
        struct circle {
            float radius;
        } c;
        struct rectangle {
            float sideA;
            float sideB;
        } rec;
    };
} Shape;

float calcArea(Shape s);

int main() {
     Shape shape1, shape2, shape3;
     shape1.st = Rectangle;
     shape1.rec.sideA = 10.0;
     shape1.rec.sideB = 2.0;

     shape2.st = Rectangle;
     shape2.rec.sideA = 5.0;
     shape2.rec.sideB = 15.0;

     shape3.st = Circle;
     shape3.c.radius = 1.0;

     printf("Area of shape1 is %f\n", calcArea(shape1));
     printf("Area of shape2 is %f\n", calcArea(shape2));
     printf("Area of shape3 is %f\n", calcArea(shape3));
     return 0;
}


//area of a circle: pi*(r^2)
float calcArea(Shape s){
    if(s.st == Circle){
	return pow(s.c.radius, 2) * PI;
    }
    return s.rec.sideA * s.rec.sideB;
}
