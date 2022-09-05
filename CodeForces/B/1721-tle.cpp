#include<iostream>
#include<cmath>
#include<vector>

using namespace std;
int dist(int ax, int ay, int bx, int by){
	return abs(ax-bx)+abs(ay-by); 
}

int getDist(int n, int m, int sx, int sy, int d, vector<vector<int> > &v, int r, int c){
	int minDist = INT_MAX;
	if(dist(r,c,sx,sy)<=d){
		return INT_MAX;
	}

	if(c!=0)
		minDist = min(minDist,v[r][c-1]);	
	if(r!=0)
		minDist = min(minDist,v[r-1][c]);

	if (minDist == INT_MAX)
		return minDist;	
	return minDist+1;
}

int main(){
	int t; cin >> t;
	while(t--){
		int n, m, sx, sy, d;
		cin >> n >> m >> sx >> sy >> d;

		// fixing 0 offset
		sx--; sy--;	
		
		vector<vector<int> > v(n, vector<int>(m,0)); // v[n][m] grid
	
		for(int r=0; r<n; r++){
			for(int c=0; c<m; c++){
				if(r==0&&c==0)
					continue;
				v[r][c] = getDist(n,m,sx,sy,d,v,r,c);
			}
		}

		if(v[n-1][m-1]==INT_MAX){
			cout << "-1" << endl;
		}	
		else{
			cout << v[n-1][m-1] << endl;
		}
	}

	return 0;	
}
