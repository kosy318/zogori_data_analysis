#include <stdio.h>
#include <vector>

struct str{
    double x0;
    double y0;
    double z0;
}O1,O2;
int dist(str A, str B)
{
    return (A.x0-B.x0)*(A.x0-B.x0)+(A.y0-B.y0)*(A.y0-B.y0)+(A.z0-B.z0)*(A.z0-B.z0);
}

str getMedian(std::vector<str> &V)
{
    double r=0,g=0,b=0;
    for(int i=0;i<V.size();i++) r += V[i].x0, g += V[i].y0, b += V[i].z0;
    r /= V.size(), g /= V.size(), b /= V.size();
    return {r,g,b};
}

double getScore(std::vector<str> &V)
{
    double r=0,g=0,b=0;
    for(int i=0;i<V.size();i++) r += V[i].x0, g += V[i].y0, b += V[i].z0;
    r /= V.size(), g /= V.size(), b /= V.size();

    double s = 0;
    for(int i=0;i<V.size();i++) s += (V[i].x0-r)*(V[i].x0-r);
    for(int i=0;i<V.size();i++) s += (V[i].y0-g)*(V[i].y0-g);
    for(int i=0;i<V.size();i++) s += (V[i].z0-b)*(V[i].z0-b);
    return s;
}

std::vector<str> x,V1,V2;
int main()
{
    int a,b;
    scanf("%d%d",&a,&b);
    for(int i=1;i<=a;i++)
    {
        int c,d,e;
        scanf("%d%d%d",&c,&d,&e);
        x.push_back({c,d,e});
    };
    if(a<=b)
    {
        printf("%.6lf",0);
        return 0;
    }
    else if(b==1)
    {
        printf("%.6lf",getScore(x));
        return 0;
    }
    else
    {
        double ans = 1234567890;
        for(int i=0;i<a;i++)
        {
            for(int j=i+1;j<a;j++)
            {
                O1 = x[i], O2 = x[j];
                int count = 50;
                while(count--)
                {
                    V1.clear();
                    V2.clear();
                    for(int k=0;k<a;k++)
                    {
                        if(dist(O1,x[k])<dist(O2,x[k])) V1.push_back(x[k]);
                        else V2.push_back(x[k]);
                    }
                    double s = getScore(V1)+getScore(V2);
                    ans = ans<s?ans:s;

                    O1 = getMedian(V1);
                    O2 = getMedian(V2);
                }
            }
        }
        printf("%.6lf",ans);
    }
}
