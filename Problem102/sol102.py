def shoelace(x1, y1, x2, y2, x3, y3):
    '''
    Calculates the area of a triangle by its cartesian coordinates by the use of [shoelace formula](https://en.wikipedia.org/wiki/Shoelace_formula)
    '''
    return abs(x1 * y2 + x2 * y3 + x3 * y1 - x2 * y1 - x3 * y2 - x1 * y3)

def main():
    file_path = 'Problem102\\triangles.txt'
    total = 0

    with open(file_path, 'r') as file:
        for line in file:
            x1, y1, x2, y2, x3, y3 = map(int, line.split(','))

            # Calculates the area of the original triangle
            og = shoelace(x1, y1, x2, y2, x3, y3)
            # Calculates the area of the three triangles formed by (0,0) and two vertices of the original triangle
            a1 = shoelace(0, 0, x1, y1, x2, y2)
            a2 = shoelace(0, 0, x2, y2, x3, y3)
            a3 = shoelace(0, 0, x3, y3, x1, y1)

            # If the sum of the areas of the three triangles is equal to the area of the original triangle, then (0,0) is inside the triangle
            if og == (a1 + a2 + a3):
                total += 1

    print(total)

if __name__ == "__main__":
    main()