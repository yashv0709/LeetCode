class Solution {
    struct N {
        char l, r;
        int len, best, pre, suf;
    };

    vector<N> st;
    string s;

    N merge(N a, N b) {
        N c;
        c.len = a.len + b.len;
        c.l = a.l; c.r = b.r;
        c.pre = a.pre;
        c.suf = b.suf;
        c.best = max(a.best, b.best);

        if (a.r == b.l) {
            c.best = max(c.best, a.suf + b.pre);
            if (a.pre == a.len) c.pre += b.pre;
            if (b.suf == b.len) c.suf += a.suf;
        }
        return c;
    }

    void build(int p,int l,int r) {
        if(l==r) {
            st[p]={s[l],s[l],1,1,1,1};
            return;
        }
        int m=(l+r)/2;
        build(p*2,l,m);
        build(p*2+1,m+1,r);
        st[p]=merge(st[p*2],st[p*2+1]);
    }

    void update(int p,int l,int r,int x) {
        if(l==r) {
            st[p]={s[x],s[x],1,1,1,1};
            return;
        }
        int m=(l+r)/2;
        if(x<=m) update(p*2,l,m,x);
        else update(p*2+1,m+1,r,x);
        st[p]=merge(st[p*2],st[p*2+1]);
    }

public:
    vector<int> longestRepeating(string str, string qc, vector<int>& qi) {
        s=str;
        int n=s.size();

        st.resize(4*n);
        build(1,0,n-1);

        vector<int> ans;

        for(int i=0;i<qi.size();i++) {
            s[qi[i]]=qc[i];
            update(1,0,n-1,qi[i]);
            ans.push_back(st[1].best);
        }

        return ans;
    }
};