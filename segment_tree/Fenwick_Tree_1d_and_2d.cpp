struct FenwickTree{
  int n ;
  vector<int>bit;
  FenwickTree(vector<int>&a){
    n = size(a);
    bit.assign(n+1,0);
    for(int i=0;i<n;i++)
    upd(i,a[i]);
  }
  void upd(int i ,int x){
    for(i++;i<n;i+=(i&(-i)))
    bit[i]+=x;
  }
  int sum(int i){
    int s;
    for(i++;i>0;i-=(i&(-i)))
    s+=bit[i];
    return s;
  }

  int query(int l,int r){
    return sum(r)-sum(l-1);
  }
};

struct FenwickTree2D{
  int n,m ;
  vector<vector<int>>bit;
  FenwickTree(vector<int>&a){
    n = size(a);
    m = size(a[0])
    bit.assign(n+1,vector<int>(m+1));
    for(int i=0;i<n;i++)
      for(int j=0;j<m;j++)
        upd(i,a[i]);
  }
  void upd(int r,int c,int x){
    for(int i =r+1;i<=n;i+=(i&(-i)))
      for(int j =c+1;j<=m;j+=(j&(-j)))
        bit[i][j]+=x;
  }
  int sum(int r,int c){
    int s=0;
    for(int i =r+1;i>0;i-=(i&(-i)))
      for(int j =c+1;j>0;j-=(j&(-j)))
        s+=bit[i][j];
    return s;
  }

  int query(int r1,int c1,int r2,int c2){
    return sum(r2,c2)-sum(r1-1,c2)-sum(r2,c1-1)+sum(r1-1,c1-1);
  }
};
