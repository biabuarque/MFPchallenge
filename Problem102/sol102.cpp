#include <iostream>
using namespace std;

int main(){
    int total, x1, y1, x2, y2, x3, y3;
    char c;
    while (true) {
        // making sure algorithm stops when there is no more input
        if (!(cin >> x1)){
            break;
        }

        cin >> y1 >> c;
        cin >> x2 >> c;
        cin >> y2 >> c;
        cin >> x3 >> c;
        cin >> y3 >> c;
        // the area of the original triangle, by shoelace formula (https://en.wikipedia.org/wiki/Shoelace_formula)
        // if we calculate the area of the three triangles formed by 2 vertices and (0,0) using shoelace formula, we obtain:
        int og = abs(x1*y2 + x2*y3 + x3*y1 - x2*y1 - x3*y2 - x1*y3);
        // area of the three triangles formed by 2 vertices and (0,0), simplifying the shoelace formula
        int a1 = abs(x1*y2 - x2*y1);
        int a2 = abs(x2*y3 - x3*y2);
        int a3 = abs(x3*y1 - x1*y3);

        // if the sum of the areas of the three triangles is equal to the area of the original triangle, then the point is inside the triangle
        if (og == (a1 + a2 + a3)){
            total++;
        }
    }
    cout << total;
    return 0;
}