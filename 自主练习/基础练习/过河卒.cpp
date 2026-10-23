// 过河卒：棋盘上 (0,0) 有一卒，要走到 (a,b)；马在 (c,d)，
// 马本身及它能一步走到的 8 个位置都不能经过。求路径条数。
# include<iostream>
# include<vector>
using namespace std;

class position{
   public:
           int x,y;
           position(int a,int b){
                   x=a;
                   y=b;
           }
};

int main(){
   int a,b,c,d;
   cout<<"请输入终点坐标 a b 和马的位置 c d："<<endl;
   cin>>a>>b>>c>>d;

   position possolider(0,0),poshorse(c,d);

   // 标记被马控制（不能走）的格子
   vector<vector<bool> > blocked(a+1,vector<bool>(b+1,false));
   int dx[9]={0,1,2,2,1,-1,-2,-2,-1};
   int dy[9]={0,-2,-1,1,2,2,1,-1,-2};
   for(int k=0;k<9;k++){
           int x=poshorse.x+dx[k];
           int y=poshorse.y+dy[k];
           if(x>=0&&x<=a&&y>=0&&y<=b){
                   blocked[x][y]=true;
           }
   }

   // dp[i][j] 表示从起点走到 (i,j) 的路径条数
   vector<vector<long long> > dp(a+1,vector<long long>(b+1,0));
   if(!blocked[possolider.x][possolider.y]){
           dp[possolider.x][possolider.y]=1;
   }
   for(int i=0;i<=a;i++){
           for(int j=0;j<=b;j++){
                   if(blocked[i][j]){
                           continue;
                   }
                   if(i==possolider.x&&j==possolider.y){
                           continue;
                   }
                   if(i>0){
                           dp[i][j]+=dp[i-1][j];
                   }
                   if(j>0){
                           dp[i][j]+=dp[i][j-1];
                   }
           }
   }

   cout<<"从 ("<<possolider.x<<","<<possolider.y<<") 到 ("<<a<<","<<b<<") 共有 "
           <<dp[a][b]<<" 条路径"<<endl;
   return 0;
}
