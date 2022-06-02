#include <bits/stdc++.h>

using namespace std;
double N[2];
double * nowP;

double * getpoint(double ** line, double t );

double ** getLine() {
    double ** line = new double *[2];
    for (int i = 0 ; i < 2; i++) 
        line[i] = new double [3];
    
    for (int i = 0 ; i < 2; i++) 
        for(int j = 0; j < 3; j++) 
            cin >> line[i][j];
    
    
    return line;
}

void setLine(double ** line1, double ** line2) {
    N[0] = 0;
    N[1] = 0;
    for(int i = 0; i < 3; i++) {
        N[0] += pow(line1[0][i] - line1[1][i], 2);
        N[1] += pow(line2[0][i] - line2[1][i], 2);
    }
    N[0] = sqrt(N[0]);
    N[1] = sqrt(N[1]);

}
double pointToPoint(double * point1, double * point2) {
    double len = 0;
    for(int i = 0; i < 3; i++) 
        len += pow(point1[i] - point2[i], 2);
    return len;
}
double pointToLine(double ** line, double * point, int lineNum, double t, double sz) {
    double ep = 1/1000000.0;
    
    double * thispoint = getpoint(line, t);
    double len = pointToPoint(thispoint, point);
    if(sz < 0.0000001) {
        free (thispoint);
        nowP = getpoint(line,t);
        return len;

    }
    if(len > pointToPoint(getpoint(line, t+ep),point)) {
        if (t+sz >= 1) {
            free(thispoint);
            nowP = getpoint(line,1);
            return len;
        }
        return pointToLine(line, point, lineNum, t+sz, sz/2);
    } else if(len > pointToPoint(getpoint(line, t-ep),point)) {
        if (t-sz <= 0){
            free(thispoint);
            nowP = getpoint(line,0);
            return len;
        }
        return pointToLine(line, point, lineNum, t-sz,sz/2);
    } else {
        free(thispoint);
        nowP = getpoint(line,t);
        return len;
    }
 }


double * getpoint(double ** line, double t ) {
    double * newpoint = new double [3];
    for (int i = 0; i < 3; i++) {
        newpoint[i] = (1-t) * line[0][i] + t * line[1][i];
    }
    return newpoint;
}

int main() {
    double *** lines = new double ** [2];
    lines[0] = getLine();
    lines[1] = getLine();
    setLine(lines[0],lines[1]);
    nowP = getpoint(lines[0], 0.5);
    int i = 1;
    double min = pointToLine(lines[i],nowP,i,0.5,0.25);
    while(true) {
        i = (i+1) % 2;
        //cout << nowP[0] << " " << nowP[1] << " " << nowP[2] << endl;
        double temp = pointToLine(lines[i],nowP,i,0.5,0.25);

        if ( temp  < min) {
            min = temp;
        } else {
            break;
        }
    }
    min = sqrt(min)- 0.01;
    cout << (int)ceil(min);

    

}

