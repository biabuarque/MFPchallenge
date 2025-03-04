#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>

using namespace std;

// Calculates the area of a triangle by its cartesian coordinates by the use of [shoelace formula](https://en.wikipedia.org/wiki/Shoelace_formula)
int shoelace(int x1, int y1, int x2, int y2, int x3, int y3) {
    return abs(x1 * y2 + x2 * y3 + x3 * y1 - x2 * y1 - x3 * y2 - x1 * y3);
}

int main() {
    int total = 0;
    int x1, y1, x2, y2, x3, y3;
    char comma;
    ifstream infile("Problem102\\triangles.txt");
    if (!infile) {
        cerr << "Unable to open file";
        return 1;
    }
    cin.rdbuf(infile.rdbuf());

    while (true) {
        // making sure algorithm stops when there is no more input
        if (!(cin >> x1 >> comma >> y1 >> comma >> x2 >> comma >> y2 >> comma >> x3 >> comma >> y3)) {
            break;
        }

        // Calculates the area of the original triangle
        int og = shoelace(x1, y1, x2, y2, x3, y3);
        // Calculates the area of the three triangles formed by the origin and two vertices of the original triangle
        int a1 = shoelace(0, 0, x1, y1, x2, y2);
        int a2 = shoelace(0, 0, x2, y2, x3, y3);
        int a3 = shoelace(0, 0, x3, y3, x1, y1);

        // if the sum of the areas of the three triangles is equal to the area of the original triangle, then (0,0) is inside the triangle
        if (og == (a1 + a2 + a3)) {
            total++;
        }
    }

    cout << total;
    return 0;
}