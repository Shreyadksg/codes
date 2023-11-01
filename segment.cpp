void build(int lo,int hi,int idx,int arr[],int seg[]){
    if(lo==hi){
        seg[idx]=arr[lo];
        return ;
    }
    
    int mid=(lo+hi)/2;
    build(lo,mid,2*idx+1,arr,seg);
    build(mid+1,hi,2*idx+2,arr,seg);
    seg[idx]=seg[2*idx+1]+seg[2*idx+2];
    return ;
}

int query(int l,int r,int lo,int hi,int seg[],int idx){
    //complete overlap
    if(lo>=l&&r>=hi) return seg[idx];
    if(l>hi||lo>r) return 0;
    
    int mid=(lo+hi)/2;
    int left=query(l,r,lo,mid,seg,2*idx+1);
    int right=query(l,r,mid+1,hi,seg,2*idx+2);
    return left+right;
}

void update(int i,int val,int idx,int lo,int hi,int seg[]){
    if(lo==hi) {
        seg[idx]=val;
        return;
    }
    int mid=(lo+hi)/2;
    
    if(i>=lo&&i<=mid) update(i,val,2*idx+1,lo,mid,seg);
    else update(i,val,2*idx+2,mid+1,hi,seg);
    seg[idx]=seg[2*idx+1]+seg[2*idx+2];
}
