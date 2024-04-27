class Solution {
    public int findRotateSteps(String ring, String key) {
        int[] dp = new int[ring.length()];
        for(int i = 0; i < dp.length; ++i)
            dp[i] = i;
        key = ring.charAt(0) + key;
        System.out.println(key);
        for(int i = 1; i < key.length(); ++i){
            for(int j = 0; j < ring.length(); ++j) {
                if(ring.charAt(j) == key.charAt(i)) {
                    int currStep = Integer.MAX_VALUE;
                    for(int k = 0; k < ring.length(); ++k) {
                        if(ring.charAt(k) == key.charAt(i - 1)) {
                            // for(int l = 0; l < dp.length; ++l)
                            //     System.out.print(dp[l] + " ");
                            // System.out.println();

                            // System.out.println(dp[k] + Math.min(Math.abs(j - k), ring.length() - Math.abs(j - k)) + 1);
                            currStep = Math.min(currStep, dp[k] + Math.min(Math.abs(j - k), ring.length() - Math.abs(j - k)) + 1);
                            // for(int l = 0; l < dp.length; ++l)
                                // System.out.print(dp[l] + " ");
                            // System.out.println();
                        }
                    }
                    dp[j] = currStep;
                }
            }
        }
        int ans = Integer.MAX_VALUE;
        for(int ansIdx = 0; ansIdx < dp.length; ++ansIdx) {
            if(ring.charAt(ansIdx) == key.charAt(key.length() - 1))
                ans = Math.min(ans, dp[ansIdx]);
        }
                            // for(int l = 0; l < dp.length; ++l)
                            //     System.out.print(dp[l] + " ");
                            // System.out.println();
        return ans;
    }
}