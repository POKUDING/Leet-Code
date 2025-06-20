class Solution {
    public int maxDistance(String s, int k) {
        int[] cnt = new int[4];
        int[] last = new int[4];
        int[] pos = new int[2];
        int rtn = 0;
        char maxNS;
        char maxWE;


        for(int i = 0; i < s.length(); ++i) {
            char c = s.charAt(i);
            switch(c) {
                case 'N':
                    ++cnt[0];
                    last[0] = i;
                    break;
                case 'S':
                    ++cnt[1];
                    last[1] = i;
                    break;
                case 'W':
                    ++cnt[2];
                    last[2] = i;
                    break;
                case 'E':
                    ++cnt[3];
                    last[3] = i;
                    break;
            }
        }

        System.out.println(cnt[0] + " " + cnt[1] + " " + cnt[2] + " " + cnt[3]);

        if(cnt[0] == cnt[1]) {
            maxNS = last[0] < last[1] ? 'N' : 'S';
        } else {
            maxNS = cnt[0] > cnt[1] ? 'N' : 'S';
        }
        if(cnt[2] == cnt[3]) {
            maxWE = last[2] < last[3] ? 'W' : 'E';
        } else {
            maxWE = cnt[2] > cnt[3] ? 'W' : 'E';
        }

        
        for(char c : s.toCharArray()) {
            switch(c) {
                case 'N':
                    if(maxNS == 'S' && k > 0) {
                        c = 'S';
                        --k;
                    }
                    break;
                case 'S':
                    if(maxNS == 'N' && k > 0) {
                        c = 'N';
                        --k;
                    }
                    break;
                case 'W':
                    if(maxWE == 'E' && k > 0) {
                        c = 'E';
                        --k;
                    }
                    break;
                case 'E':
                    if(maxWE == 'W' && k > 0) {
                        c = 'W';
                        --k;
                    }
                    break;
            }

            switch(c) {
                case 'N':
                    ++pos[1];
                    break;
                case 'S':
                    --pos[1];
                    break;
                case 'W':
                    --pos[0];
                    break;
                case 'E':
                    ++pos[0];
                    break;
            }

            rtn = Math.max(rtn, (Math.abs(pos[0]) + Math.abs(pos[1])));
            System.out.println(c + " " + pos[0] + " " + pos[1] + " " + rtn);
        }

        return rtn;
    }
}