#include<bits/stdc++.h>
using namespace std;

const double eps = 1e-9;

inline bool is_between(double check, double a, double b) {
	if (a < b) return(a  < check && check < b );
	else return (b  < check && check < a );
}

struct Point {
	double x, y;

	Point() : Point(0, 0) {}
	Point(double x, double y) : x(x), y(y) {}
	bool operator==(const Point& rhs) const {
		return x == rhs.x && y == rhs.y;
	}

	Point operator+(const Point& rhs) const {
		return Point{ x + rhs.x, y + rhs.y };
	}

	Point operator-(const Point& rhs) const {
		return Point({ x - rhs.x, y - rhs.y });
	}

	Point operator*(double t)const {
		return Point{ x * t, y * t };
	}
};

inline double inner(const Point& p1, const Point& p2) {
	return p1.x * p2.x + p1.y * p2.y;
}
inline double outer(const Point& a, const Point& b) {
	return a.x * b.y - a.y * b.x;
}

inline int ccw(const Point& a, const Point& b, const Point& c) {
	return outer(b - a, c - a);
}


vector<Point> convex(vector <Point>& dat) {
	// Return when the vertex below 3, 
	if (dat.size() <= 3) return dat;

	vector<Point> upper, lower;
	sort(dat.begin(), dat.end(), [](const Point& a, const Point& b) {
		return (a.x == b.x) ? a.y < b.y : a.x < b.x;
		});

	for (const auto& p : dat) {
		while (upper.size() >= 2 && ccw(*++upper.rbegin(), *upper.rbegin(), p) >= 0) {
			upper.pop_back();
		}

		while (lower.size() >= 2 && ccw(*++lower.rbegin(), *lower.rbegin(), p) <= 0) {
			lower.pop_back();
		}

		upper.emplace_back(p);
		lower.emplace_back(p);
	}

	upper.insert(upper.end(), ++lower.rbegin(), --lower.rend());
	return upper;

}

inline double dist(const Point& l1, const Point& l2, const Point& point, bool segment = false) {
	Point dir = Point(l2 - l1);
	double c1 = inner(point - l1, dir);
	double c2 = inner(dir, dir);
	return sqrt(inner(l1 + dir * (c1 / c2) - point, l1 + dir * (c1 / c2) - point));
}
vector<Point> input;
vector<Point> c_point;
int n;
double x, y;
double ans = 10e20;
int cnt=1;
int main() {
	scanf("%d", &n);
	while (n != 0) {
		while (input.size() != 0) input.pop_back();
		while (c_point.size() != 0) c_point.pop_back();
		ans = 10e30;

		for (int i = 0; i < n; i++) {
			scanf("%lf %lf", &x, &y);
			input.push_back(Point(x, y));
		}

		c_point = convex(input);
		for (int j = 0; j < c_point.size(); j++) {
			int ssize = c_point.size();
			double maxSegDist = 0;
			for (int k = 0; k < c_point.size(); k++) {
				if (k == j|| k == ((j + 1) % ssize)) continue;
				maxSegDist = max(maxSegDist, dist(c_point[j] , c_point[(j + 1) %ssize], c_point[k]));
				//printf("[DEBUG] dist : %lf\n", dist(c_point[j], c_point[j + 1], c_point[k]));
			}
			ans = min(ans, maxSegDist);
		}


		//output 
		printf("Case %d: %.2lf\n", cnt, ceil(ans*100)/100);
		scanf("%d", &n);
		cnt++;
	}
	
	
	return 0;
}
