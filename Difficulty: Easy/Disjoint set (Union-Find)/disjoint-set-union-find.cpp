/*Complete the functions below*/
int find(int par[], int x) {
    // add code here
    if(x == par[x])
    return par[x];
    
    return find(par , par[x]);
}

void unionSet(int par[], int x, int z) {
    // add code here.
    int x_parent = find(par , x);
    int z_parent = find(par , z);
    
    if(x_parent != z_parent){
        par[x_parent] = z_parent;
    }
}