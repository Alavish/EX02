//Anthony Christopher




//   1.)


/* Robustness Formula 

n parameters



Formula: 6 * n + 1 

if n = 1 (7)
if n = 2 (13)
if n = 3 (19)

*/



// 2.)

#include <iostream>
#include <vector> //for structure testing approach
#include<bits/stdc++.h> //for INT_MAX
#include <ctime>
#include <cstdlib>

enum isTriangle{Equilateral, Right, Isosceles,Scalene, NotATriangle};


isTriangle whatType(int s1, int s2, int s3) {
 

    if (s1 == s2 && s2 == s3) {
        
    if (s1 <= 0 and s2 <= 0 and s3 <= 0) 
    
        return NotATriangle; // Triangles cannot be 0 sides
        
        else return Equilateral; // all sides equal
        
  } else if (s1 == s2 || s1 == s3 || s2 == s3) 
        return Isosceles;
        
    else if (s1 * s1 + s2 * s2 == s3 * s3 || s2 * s2 + s3 * s3 == s1 * s1 || s3 * s3 + s1 * s1 == s2 * s2) 
        return Right; // formula for right triangle

    else if (s1 + s2 == s3 or s2 + s3 == s1 or s3 + s1 == s2) 
    return NotATriangle;
    
    
    else if (s2 + s3 < s1) 
    return NotATriangle;
    
}









//For structure testing approach
class triangleSides {
public:
    int a,b,c;

    triangleSides(int _a, int _b, int _c) : a(_a), b(_b), c(_c) {}
};







//For structure testing approach
class triangleSideTest {
public:
    triangleSides sides;
    bool expectedResult;

    triangleSideTest(triangleSides _sides, bool _exp) : sides(_sides), expectedResult(_exp){}
};



int main() {
    
    using namespace std;
    
    isTriangle t = whatType(3,3,3);
    
    switch (t)
    {
    case Scalene: cout << " Your Triangle Is Scalene! " << endl;
        break;
    case Isosceles: cout << " Your Triangle Is An Isosceles! " << endl;
        break;
    case Equilateral: cout << " Your Triangle Is An Equilateral! " << endl;
        break;
    case NotATriangle: cout << " Your Triangle Is not A Triangle! " << endl;
    
    }

}



// 3.)



/*
In the IsTriangle function you want to classify the type of triangle, 
Scalene,Isosceles,Right etc. to utilize boundary testing you need to 
make boundarys for equilateral triangles. Equilateral if a == b && b == c 
then its a equilateral if its a==b || b == c || or a == c then it could be a Isosceles
these are considered boundaries for a right triangle the boundaries are formed from
the pythagorean theorem. if a*a + b*b = c*c then its a right triangle and some other boundaries
that are the same version of that formula reversed. Then if these boundaries are all
not true for the triangle then it would not be considered a triangle.
For an example if the boundaries for all these sides(a,b,c) was [1,5] then
have a the input of 0,0,0 would output NotATriangle because it doenst honor the boundaries.



//4.)

Boundaries:
[0-100] " " [+,-,*,/] " " [0-100] " "[/,*] " " [0-5] .

General:
<10,+,60,/,3>
<2,+,50,*,2>
<5,+,35,/,5>

Robust:
<100,+,10,*,6>
<10,-,-1,/,-1>
<100,+,101,*, -1>


Worst Case:
<-1,%,101,&,-1>
<101,@,-1,^,6>
<-1,!,101,$,6>




