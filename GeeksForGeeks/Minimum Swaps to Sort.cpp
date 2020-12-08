int minSwaps(int a[], int n){
    pair<int, int> t[n];
    for(int i=0;i<n;i++){
        t[i].first = a[i];
        t[i].second = i;
    }
    sort(t, t+n);
    bool v[n] = {false};
    int ans = 0;
    for(int i=0;i<n; i++){
        if(v[i] || t[i].second == i)
            continue;
        int cycle = 0;
        int j = i;
        while(!v[j]){
            v[j] = true;
            j = t[j].second;
            cycle++;
        }
        if(cycle)
            ans+=(cycle-1);
    }
    return ans;
}
