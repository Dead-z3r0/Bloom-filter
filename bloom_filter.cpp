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
    public :
        bloom_filter(int size_bft, int hash_count){
            this->size_bft=size_bft;
            this->hash_count=hash_count;
            bft.resize(size_bft,0); // initializing the bloom filter bit vector with 0
        }

        void add(string &inpt){
            for(int i=0;i<hash_count;i++){
                int hash_value=hash_of_i(inpt,i); // this call will return the hash value of the input string for the given seed value
                bft[hash_value]=1; //set the hash value index in the bloom filter bit vector to 1
            }
            return;
        }


        bool taken(string &inpt){
            for(int i=0;i<hash_count;i++){
                int hash_value=hash_of_i(inpt,i); //return the hash value of the input string for the given seed value
                if(!bft[hash_value]){ //if any hash value index is 0 it implies that the input string is DEF NOT PRESENT in the bloom filter
                    return false;
                }
            }
            return true; //The string is either PRESENT or FALSE POSITIVE in the bloom filter
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