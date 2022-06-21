#include <bits/stdc++.h>
#define L long long

using namespace std;

bool chk[1111][55];
L a[1111][55];
L top[55];
L n;
L seq[55];//1->x?
L invseq[55];//x->1?
L seqT[55];
L invseqT[55];

map<pair<L,L>,pair<L,L> >mp;

int main()
{
	scanf("%lld",&n);
	L i,j;
	for(i=1;i<n;i++)
	{
		while(1)
		{
			L x;
			scanf("%lld",&x);
			if(x==0) break;
			a[x][i]=1;
		}
	}
	while(1)
	{
		bool chd=false;
		for(i=1;i<=n;i++)
		{
			seq[i]=i;
			invseq[i]=i;
		}
		mp.clear();
		for(i=1;i<=1000;i++)
		{
			for(j=1;j<n;j++)
			{
				if(!a[i][j]||chk[i][j]) continue;
					L ba=invseq[j],bb=invseq[j+1];
				if(ba>bb) swap(ba,bb);
				if(mp.find(make_pair(ba,bb))!=mp.end())
				{
					chk[mp[make_pair(ba,bb)].first][mp[make_pair(ba,bb)].second]=1;
					chk[i][j]=1;
					mp.erase(make_pair(ba,bb));
					chd=true;
					goto out;
				}
				else
				{	
					mp[make_pair(ba,bb)]=make_pair(i,j);
				}
				swap(seq[ba],seq[bb]);
				swap(invseq[j],invseq[j+1]);
			}
		}
		out:
		if(!chd)  break;
	}
	vector<L>ans1,ans2;
	for(i=1;i<n;i++)
	{
		L cnt=0;
		for(j=1;j<=1000;j++)
		{
			if(a[j][i])
				cnt++;
			if(a[j][i]&&!chk[j][i])
			{
				ans1.push_back(i);
				ans2.push_back(cnt);
			}
		}
	}
	for(i=1;i<=n;i++)
	{
		seqT[i]=i;
		invseqT[i]=i;
	}
	for(i=1;i<=1000;i++)
	{
		for(j=1;j<n;j++)
		{
			if(!a[i][j]||chk[i][j]) continue;
			L ba=invseqT[j],bb=invseqT[j+1];
			swap(invseqT[j],invseqT[j+1]);
			swap(seqT[ba],seqT[bb]);
		}
	}
	/*for(i=1 ; i<=n ; i++)
	{
		cout<<invseq[i]<<" ";
	}
	cout<<"\n";
	for(i=1 ; i<=n ; i++)
	{
		cout<<invseqT[i]<<" ";
	}
	cout<<"\n";*/
	printf("%d\n",(int)ans1.size());
	for(i=0;i<ans1.size();i++)
	{
		printf("%lld %lld\n",ans1[i],ans2[i]);
	}
	
}
