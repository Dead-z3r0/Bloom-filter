#include<bits/stdc++.h>
#include<chrono>


using namespace std;
using namespace chrono;

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
    int size_bft,hash_count;
    cout<<" Please enter the size of bit vector of bloom filter : ";
    cin>>size_bft;
    cout<<" Please enter the number of hash functions : ";
    cin>>hash_count;
    bloom_filter bf(size_bft,hash_count);
    int query;
    cout<<" Please enter the number of queries : ";
    cin>>query;
    while(query--){
        string type,inpt;
        cout<<"insert or check : ";
        cin>>type;
        // whether to add or check the string in the bloom filter
        if(type=="insert"){
            cout<<" Please enter the string to insert : ";
            cin>>inpt;
            bf.add(inpt);
        }
        else if(type=="check"){
            cout<<" Please enter the string to check : ";
            cin>>inpt;
            if(bf.taken(inpt)){
                cout<<" The string is either PRESENT or FALSE POSITIVE in the bloom filter"<<endl;
            }
            else{
                cout<<" The string is DEF NOT PRESENT in the bloom filter"<<endl;
            }

        }
        else{
            cout<<" Invalid query type, enter either 'insert' or 'check'"<<endl;
            query++; // to repeat the query if invalid type is entered
        }
    }
    return;
}

int main(){
    auto start1 = high_resolution_clock::now();
    solve();
    auto stop1 = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop1 - start1);
    cerr << "Time: " << duration.count() / 1000 << " ms" << endl;
}