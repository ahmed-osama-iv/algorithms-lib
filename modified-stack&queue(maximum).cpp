#include <bits/stdc++.h>
using namespace std;

struct maxi_stack{

    stack<pair<int,int> > st;

    void push(int item){
        if(!st.empty())
            st.push({item, max(item, st.top().second)});
        else
            st.push({item, item});
    }

    void pop(){
        st.pop();
    }

    int getMax(){
        if(!st.empty())
            return st.top().second;
        return 0;
    }

    int top(){
        if(!st.empty())
            return st.top().first;
        return 0;
    }

    bool empty(){
        return st.empty();
    }

    int size(){
        return st.size();
    }
};

struct maxi_queue{

    maxi_stack in,out;

    void push(int x){
        in.push(x);
    }

    void pop(){
        if(out.empty())
            while(!in.empty())
                out.push(in.top()),in.pop();
        out.pop();
    }

    int getMax(){
        return max(in.getMax(),out.getMax());
    }

    int size(){
        return in.size()+out.size();
    }

    bool empty(){
        return !size();
    }
};

