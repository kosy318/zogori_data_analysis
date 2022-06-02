#include <iostream>
#include <array>
#include <cmath>
#include <cstdint>
#include <algorithm>


using Point3D = std::array<long double, 3>;

constexpr long double delta = 1.0L/std::pow(2.0L, 16.0L);

class CPoint3D : public Point3D {

	public:

		const CPoint3D operator + (const CPoint3D& opponent) const {
			CPoint3D ret = *this;

			for(size_t i=0; i<this->size(); i++)
				ret[i] += opponent[i];

			return ret;
		}

		const CPoint3D operator - (const CPoint3D& opponent) const {
			CPoint3D ret = *this;

			for(size_t i=0; i<this->size(); i++)
				ret[i] -= opponent[i];

			return ret;
		}

		const long double operator * (const CPoint3D& opponent) const {
			CPoint3D x = *this;
			long double ret = 0.0;

			for(size_t i=0; i<this->size(); i++)
				ret += x[i] * opponent[i];

			return ret;
		}

		const CPoint3D operator * (const long double x) const {
			CPoint3D ret = *this;

			for(size_t i=0; i<this->size(); i++)
				ret[i] =ret[i] * x;

			return ret;
		}

		const long double get_distance(const CPoint3D& opponent) {
			CPoint3D x = *this;
			long double ret = 0.0;

			for(size_t i=0; i<x.size(); i++) {
				ret += pow(x[i]-opponent[i], 2.0L);
			}

			return sqrt(ret);
		}
};

int main(void) {

	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	std::array<CPoint3D, 4> coordinates;

	for(auto &c : coordinates)
		for(auto &t : c)
			std::cin >> t;

	auto A = coordinates[0];
	auto B = coordinates[1];
	auto C = coordinates[2];
	auto D = coordinates[3];

	auto r = C - A;
	auto u = B - A;
	auto v = D - C;

	auto ru = r * u;
	auto rv = r * v;
	auto uu = u * u;
	auto uv = u * v;
	auto vv = v * v;

	auto divisor = uu * vv - uv * uv;

	long double s, t;

	if(divisor < delta*uu*vv) {
		s = ru/uu;
		t = 0.0L;
	} else {
		s = (ru*vv - rv*uv)/divisor;
		t = (ru*uv - rv*uu)/divisor;
	}
	
	s = std::max(std::min(s, 1.0L), 0.0L);
	t = std::max(std::min(t, 1.0L), 0.0L);
		
	auto S = (t*uv + ru)/uu;
	auto T = (s*uv - rv)/vv;

	S = std::max(std::min(S, 1.0L), 0.0L);
	T = std::max(std::min(T, 1.0L), 0.0L);

	auto p = A + u*S;
	auto q = C + v*T;

	std::cout << static_cast<int32_t>(std::ceil(p.get_distance(q)));
}
