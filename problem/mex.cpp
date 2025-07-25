// non_zero_segments = count of non-zero elements - count of (consecutive non-zero pairs)

//nice logic
int n;
        long long k;
        cin>>n>>k;
        vector<long long>a(n+1),S(n+1);
        for(int i=1;i<=n;i++){
            cin>>a[i];
            S[i]=S[i-1]+(a[i]<=k?1:-1);
        }
        vector<long long>pre(n+1),mn(n+2),mx(n+2);
        pre[0]=S[0];
        for(int i=1;i<=n;i++) pre[i]=min(pre[i-1],S[i]);
        mn[n]=1e18; mx[n]=-1e18;
        for(int i=n-1;i>=1;i--){
            mn[i]=min(S[i],mn[i+1]);
            mx[i]=max(S[i],mx[i+1]);
        }
        bool ok=0;
        for(int l=1;l<=n-2&&!ok;l++){
            if(S[l]>=0){
                if(mx[l+1]>=S[l]||mn[l+1]<=S[n]) ok=1;
            }
        }
        for(int r=2;r<=n-1&&!ok;r++){
            if(S[r]<=S[n]&&pre[r-1]<=S[r]) ok=1;
        }
        cout<<(ok?"YES":"NO")<<"\n";
    }
    return 0;