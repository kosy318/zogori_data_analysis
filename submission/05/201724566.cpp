#include <iostream>
#include <cmath>
#include <limits>

using namespace std;

// delta is variable which can modify accuracy
double delta = 0.00001;
double midMat[3] = { 0.0, 0.0, 0.0 };

double calcDistance(double* A, double* B) {
	return pow(A[0] - B[0], 2) + pow(A[1] - B[1], 2) + pow(A[2] - B[2], 2);
}

double calcDistancebyRatio(double ratio, double* other, double* A, double* B) {
	for (int i = 0; i < 3; ++i)
		midMat[i] = (A[i] * ratio) + (B[i] * (1 - ratio));
	return calcDistance(midMat, other);
}

// "start" is 0, and "end" is 1
double dividingStation(double start, double end, double* A, double* B, double* M) {
	double mid = (start + end) / 2;
	double calc_Dist = calcDistancebyRatio(mid, M, A, B);
	double distUp = calcDistancebyRatio(mid + delta, M, A, B);
	double distDown = calcDistancebyRatio(mid - delta, M, A, B);

	if (start + delta >= end || ((calc_Dist <= distUp) && (calc_Dist <= distDown)))
		return mid;
	else if (calc_Dist > distUp)
		mid = dividingStation(mid, end, A, B, M);
	else if (calc_Dist > distDown)
		mid = dividingStation(start, mid, A, B, M);
	return mid;
}

int main()
{
    // ios_base::sync_with_stdio(false);
    // cin.tie(NULL);
    double pPoint[3], qPoint[3], rPoint[3], sPoint[3];
	double midA[3], midB[3];

	for (int i = 0; i < 3; ++i) {
		cin >> pPoint[i];
		midA[i] = pPoint[i];
	}
	for (int i = 0; i < 3; ++i)
		cin >> qPoint[i];
	for (int i = 0; i < 3; ++i) {
		cin >> rPoint[i];
		midB[i] = rPoint[i];
	}
	for (int i = 0; i < 3; ++i)
		cin >> sPoint[i];

	double lastDist = numeric_limits<double>::max();

	double shortDist = calcDistance(pPoint, rPoint);
	if (shortDist < lastDist)
		lastDist = shortDist;
	shortDist = calcDistance(pPoint, sPoint);
	if (shortDist < lastDist)
		lastDist = shortDist;
	shortDist = calcDistance(qPoint, rPoint);
	if (shortDist < lastDist)
		lastDist = shortDist;
	shortDist = calcDistance(qPoint, sPoint);
	if (shortDist < lastDist)
		lastDist = shortDist;

	double shortMid;
	while (1) {
		shortMid = dividingStation(0.0, 1.0, pPoint, qPoint, midB);
		for (int i = 0; i < 3; ++i)
			midA[i] = (pPoint[i] * shortMid) + (qPoint[i] * (1 - shortMid));
		shortMid = dividingStation(0.0, 1.0, rPoint, sPoint, midA);
		for (int i = 0; i < 3; ++i)
			midB[i] = (rPoint[i] * shortMid) + (sPoint[i] * (1 - shortMid));
		shortDist = calcDistance(midA, midB);
		if (shortDist < lastDist)
			lastDist = shortDist;
		else
			break;
	}

	double distance = sqrt(lastDist);

	// for catch distance Zero
	if (distance < 0.2)
		distance = 0;

	cout << ceil(distance);

	return 0;
}
