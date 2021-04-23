#include<bits/stdc++.h>
using namespace std;

char mat[11][11];
bool seen[11][11];
pair<int,int> parent[11][11];
int sx,sy,px,py;
bool found;

int step=1;
void dfs(int x,int y,int xp,int yp){
	
	if(mat[x][y]=='#'||seen[x][y]||found)
		return;
	seen[x][y]=true;
	parent[x][y]=make_pair(xp,yp);
	
	if(x==px&&y==py){
		found=true;
		return;
	}
		
	if(y+1<=10){
		dfs(x,y+1,x,y);
	}
		
	if(y-1>0){
		dfs(x,y-1,x,y);
	}
	
	if(x-1>0){
		dfs(x-1,y,x,y);
	}
		
	if(x+1<=10){
		dfs(x+1,y,x,y);	
	}
			
}

void show(){
	system("cls");
	cout<<" ";
	for(int i=1;i<=20;i++){
		cout<<"-";
	}
	cout<<endl;
	for(int i=1;i<=10;i++){
		cout<<"|";
		for(int j=1;j<=10;j++){
			cout<<" "<<mat[i][j];
		}
		cout<<"|"<<endl;
	}
	cout<<" ";
	for(int i=1;i<=20;i++){
		cout<<"-";
	}
}

void star(){
	if(!found){
		cout<<"There's no way!";
		return;
	}
		
	int x=parent[px][py].first;
	int y=parent[px][py].second;
	
	while(!(x==sx&&y==sy)){
		mat[x][y]='*';
		int tx=x;
		int ty=y;
		x=parent[x][y].first;
		y=parent[tx][ty].second;
		show() ; 
	}
}

void init(){
	srand(time(NULL)) ; 
	int x;
	for(int i=1;i<=10;i++){
		for(int j=1;j<=10;j++){
			x=rand()%2;	
			if(x){
				mat[i][j]='#';
			}
			else
				mat[i][j]=' ';
		}
	}
	
	for(int i=1;i<=10;i++){
		for(int j=1;j<=10;j++){
			if(mat[i][j]=='#'){
				x=rand()%2;	
				if(x){
					mat[i][j]='#';
				}
				else
					mat[i][j]=' ';
			}
			
		}
	}
	
}

int main(){
	init();
	
	sx=rand()%10+1;
	sy=rand()%10+1;
	px=rand()%10+1;
	py=rand()%10+1;
	
	while(sx==px&&sy==py){
		px=rand()%10+1;
		py=rand()%10+1;	
	}
	mat[sx][sy]='S';
	mat[px][py]='P';
	
	dfs(sx,sy,-1,-1);
	
	star();
	show();
}

