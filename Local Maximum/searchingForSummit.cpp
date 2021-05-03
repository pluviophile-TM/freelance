    #include <bits/stdc++.h>
     
    using namespace std;
     
    const int MAXN = 100010;
    const int INF=100*1000+100; 
    int n;
    int a[MAXN];
     
    int query(int x)
    {
    	if (1 <= x && x <= n)
    	{
    		printf("? %d\n", x-1);
    		fflush(stdout);
    		scanf("%d", &a[x]);
    	}
    }
     
    int main()
    {
    	scanf("%d", &n);
    	a[0] = a[n + 1] = -INF;
    	int L = 1, R = n;
    	while (L < R)
    	{
    		int m = (L + R) / 2;
    		query(m);
    		query(m + 1);
    		if (a[m] > a[m + 1])
    			R = m;
    		else
    			L = m + 1;
    	}
    	printf("! %d\n", L-1);
    	fflush(stdout);
    	return 0;
    }
