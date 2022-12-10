#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// approx api requests - 1M each day

map<int,pair<int,int>> mp;

vector<string> api_list(),user_list();

void api_calls(map<int,pair<int,int>> &mp){
    for(int i=0;i<=1e6;i++){
        // getting random api calls using rand function
        int random_call = rand()%1000;
        // getting random response time for the current api call
        int random_response = rand()%1000;
        mp[random_call].first+=random_response;
        mp[random_call].second+=1;
    }
}

// get API with maximum response time
string average_responses(){
    double maxi=0;
    string api_id="";
    for(auto it:mp){
        // finding the average response time for each API
        double var = it.first/it.second*1.0;
        if(var>maxi){
            maxi=var;
            api_id = api_list[it];
        }
    }
    return api_id;
}


int main() {
    
    for(int i=0;i<100;i++)
        api_list.push_back("api"+to_string(i));
    for(int i=0;i<1000;i++)
        user_list.push_back("user"+to_string(i));
    
    
    // Call api calls
    api_calls(mp,api_list,user_list);
    
    
    
}