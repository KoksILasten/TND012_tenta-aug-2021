//=======================================================
// TND012, exam: Exercise 1
// Name: Magnus Kling
// Personal number: *********
// LiU-id: Magkl572
//=======================================================
// Write your name, personal number, and LiU-id

#include <iostream>
#include <cmath> //sqrt()
#include <ctime> //srand(), rand()
#include <vector> //vector<>

struct Point {
	int x = 0;
	int y = 0;
};

bool validate_rad_n_length(int A);

int read_radius();

int read_length();

int read_n(int length);

Point generate_point(int length);

std::vector<Point> group_points(int length, int n);

bool inside_circle(int X, int Y, int radius);

void display(std::vector<Point>& pos, int radius);

int main() {

	srand(time(NULL));

	int radius = read_radius();
	int length = read_length();
	int num_times = read_n(length);

	std::vector<Point> pos = group_points(length, num_times);

	display(pos, radius);
}

bool validate_rad_n_length(int A) {
	bool validate_input = (A >= 5);
	if (!validate_input) {
		std::cout << "\nInvalid input! Try again.\n";
	}

	return validate_input; // checks if input from radius or length is equal or greater than 5.
}

int read_radius() {
	int radius = 0;
	do {
		std::cout << "Radius: ";
		std::cin >> radius;

	} while (!validate_rad_n_length(radius));

	return radius;
}

int read_length() {
	int length = 0;
	do {
		std::cout << "length: ";
		std::cin >> length;

	} while (!validate_rad_n_length(length));

	return length;
}

int read_n(int length) {
	int max_n = (2 * length + 1) * (2 * length + 1);
	int n = 0;
	bool val = false;

	do {
		std::cout << "Number of points: ";
		std::cin >> n;

		val = (n < 0 || n > max_n);
		if (val) {
			std::cout << "\nInvalid input! Try again.\n";
		}
	} while (val);

	return n; // reads n and validates input
}

Point generate_point(int length) {
	Point P;
	P.x = rand() % (2 * length + 1) - length;
	P.y = rand() % (2 * length + 1) - length;

	return P; //generates random numbers
}


std::vector<Point> group_points(int length, int n) {
	std::vector<Point> V;
	Point P = generate_point(length);

	for (int i = 0; i < n; i++) {

		bool found = false;
		for (int e = 0; e < V.size(); e++) {  // linear search
			if (V[e].x == P.x && V[e].y == P.y) {
				found = true;
				--i; // removes one i so you get the amount of points you asked for
			}
		}

		if (!found) { //pushback if it is not a duplicate
			V.push_back(P);
		}

		P = generate_point(length);
	}
	return V; //groups x and y into one vector while checking that there are not duplicates!
}

bool inside_circle(int X, int Y, int radius) {

	if (sqrt(X * X + Y * Y) < radius) { //square root of X^2 + Y^2 
		return true;
	}

	return false; //Checks in the point is inside the circle or not
}

void display(std::vector<Point>& pos, int radius) {

	for (int i = 0; i < pos.size(); i++) {
		std::cout << "(" << pos[i].x << ", " << pos[i].y << ")";
		bool is_inside = inside_circle(pos[i].x, pos[i].y, radius);

		if (is_inside) {
			std::cout << " in the circle";
		}
		else {
			std::cout << " not in the circle";
		}
		std::cout << std::endl;
	}
}