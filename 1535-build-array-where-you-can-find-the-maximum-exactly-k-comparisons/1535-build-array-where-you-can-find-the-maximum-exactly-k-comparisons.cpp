class Solution {
public:
    int mod=1e9+7;
    int solve(int ind,vector<int>&nums,int n,int k,int cur_max,vector<vector<vector<int>>>&dp){
        if(ind==n){
         if(k==0)return 1;
         else return 0;
        }
        if(dp[ind][k][cur_max]!=-1)return dp[ind][k][cur_max];
        int res=0;
        for(int i=0;i<nums.size();i++){
            if(k>0 and nums[i]>cur_max){
                res=(res%mod+solve(ind+1,nums,n,k-1,nums[i],dp)%mod)%mod;
            }else if(k==0 and nums[i]>cur_max){
                continue;
            }
            else{
                res=(res%mod+solve(ind+1,nums,n,k,cur_max,dp)%mod)%mod;
            }
        }
        return dp[ind][k][cur_max]=res%mod;
    }
    int numOfArrays(int n, int m, int k) {
        if(k>m)return 0;
        vector<int>nums;
        for(int i=1;i<=m;i++){
            nums.push_back(i);
        }
        vector<int>ans(n,0);
        vector<vector<vector<int>>>dp(n+5,vector<vector<int>>(k+5,vector<int>(m+5,-1)));
        return solve(0,nums,n,k,0,dp);
    }
};