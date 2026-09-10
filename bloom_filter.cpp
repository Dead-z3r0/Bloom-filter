#include<bits/stdc++.h>
#include<chrono>

using namespace std;

class bloom_filter{
    private:
        int size_bft;
        int hash_count;
        vector<bool>bft;

        // creating hash function for each seed value
        // this function value will change according to the seed value and the input string
        int hash_of_i(string &inpt,int seed){
            int hash_value=0;
            for(int i=0;i<inpt.size();i++){
                hash_value=(hash_value*seed+(int)(inpt[i]))%size_bft;
            }
            return hash_value%size_bft;
        }
};

void solve(){

    return;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    auto start1 = high_resolution_clock::now();
    solve();
    auto stop1 = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop1 - start1);
    cerr << "Time: " << duration.count() / 1000 << " ms" << endl;
}