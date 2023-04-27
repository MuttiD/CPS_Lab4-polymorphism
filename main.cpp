#include "mbed.h"
#include "MMA7660.h"
#include <cmath>
#include <cstdio>

#define PI 3.141592654

class Shape {
public:

    enum shape_is{square, triangle, circle};
    //constructor
        // Square has four even sides, then one variable is required
        Shape(int a) {
            _a = a;
            shape_type = square;
        }
        
        // The Isosceles Triangle has base and height variables
        // Circle has only one variable (radius), then using second variable as nil 
        Shape(int a, int b) {
            _a = a;
            _b = b;
            if(_b == 0)
                shape_type = circle;
            else
                shape_type = triangle;
        }

        // calculating area
        float area() {
            if(shape_type == circle)
                return (PI * _a * _a);
            if(shape_type == triangle)
                return ((_a * _b) * 0.5);
            if(shape_type == square)
                return (_a * _a);
        }

        // calculating perimeter
        float perimeter() {
            if(shape_type == circle)
                return (2 * PI * _a);
            if(shape_type == triangle)
                return ((2 * _a) + _b);
            if(shape_type == square)
                return (4 * _a);
        }

        // defining the shapes
        void print_shape() {
            if(shape_type == circle)
                printf("Shape is a circle. ");
            if(shape_type == triangle)
                printf("Shape is an Isosceles triangle. ");                   
            if(shape_type == square)
                printf("Shape is a square. ");
        };

private:
    int _a;
    int _b;
    shape_is shape_type;
};


int main() {
    //input of values
    Shape square(8);
    Shape triangle(4,2);
    Shape circle(4, 0);

    // print the values of area and perimeter of the shapes on the Terminal
    square.print_shape();
        printf("Area of Square is %f . \r\n", square.area());
        printf("Perimeter of Square is %f \r\n", square.perimeter());
    triangle.print_shape();
        printf("Area of triangle is %f . \r\n", triangle.area());
        printf("Perimeter of Triangle is %f \r\n", triangle.perimeter());
    circle.print_shape();
        printf("Area of circle is %f . \r\n", circle.area());
        printf("Perimeter of Circle is %f \r\n", circle.perimeter());
}
