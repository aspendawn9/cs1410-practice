// CS1410 - Assignment 03
#include <iostream>
#include <iomanip>  
using namespace std;

//TODO 1: ShapeKind Enumeration goes here
enum class ShapeKind{
    Circle, Square, Rectangle
};

//TODO 2: Shape Structure goes here
struct Shape{
    ShapeKind kind;
    double length;
    double width;
};

// Function prototypes and definitions
//TODO 3: area() definition goes here
double area(Shape s){
    if (s.kind == ShapeKind::Circle){
        return (s.length/2)*(s.length/2)*3.14159;
    }else{
        return s.length * s.width;
    }

}



//TODO 4: perimeter() definition goes here
double perimeter(Shape s){
    if (s.kind == ShapeKind::Circle){
        return s.length * 3.14159;
    }else{
        return (2 * s.length) + (2 * s.width);
    }
}


//TODO 5: nameOf() definition goes here
string nameOf(Shape s){
    if(s.kind == ShapeKind::Circle){
        return "Circle";
    }else if(s.kind == ShapeKind::Rectangle){
        return "Rectangle";
    }else{
        return "Square";
    }

}


//TODO 6: promptAndReadInputFor() definition goes here
void promptAndReadInputFor(Shape& s){
    if (s.kind == ShapeKind::Circle){
        double clen;
        cout << "Enter the diameter of a circle: " << endl;
        cin >> s.length;
        s.width = s.length;
    }else if(s.kind == ShapeKind::Rectangle){
        double rlen;
        double rwidth;
        cout << "Enter the length of the rectangle: " << endl;
        cin >> s.length;
        cout << "Enter the width of the rectangle: " << endl;
        cin >> s.width;
        if (s.length == s.width){
            s.kind = ShapeKind::Square;
        }
    }else if (s.kind == ShapeKind::Square){
        cout << "Enter the length of the square: " << endl;
        cin >> s.length;
        s.width = s.length;
    }

}

// The main function
int main() {
  // Shape objects
  Shape circle = { ShapeKind::Circle, 0, 0 };
  //TODO 7: define two more shape objects: a square and and a rectangle 
  Shape square ={ShapeKind::Square,0.0,0.0};
  Shape rectangle ={ShapeKind::Rectangle,0.0,0.0};


  //TODO 8: Call the promptAndReadInputFor() function on each of the above three shapes
  promptAndReadInputFor(circle);
  promptAndReadInputFor(square);
  promptAndReadInputFor(rectangle);

  

  //TODO 9: Print a out a report of these shapes in a table-like format
 cout << "Shape" << setw(8) << "Width" << setw(16) << "Perimeter" << setw(8) << "Area" << endl;
 cout << nameOf(circle) << setw(6) << circle.width << setw(14) << perimeter(circle) << setw(14) << area(circle) << endl;
 cout << nameOf(square) << setw(6) << square.width << setw(10) << perimeter(square) << setw(14) << area(square) << endl;
 cout << nameOf(rectangle) << setw(3) << rectangle.width << setw(12) << perimeter(rectangle) << setw(12) << area(rectangle) << endl;


  return 0;
}
