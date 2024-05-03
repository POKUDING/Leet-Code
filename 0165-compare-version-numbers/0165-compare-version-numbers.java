class Solution {
    public int compareVersion(String version1, String version2) {
        String[] st1 = version1.split("\\.");
        String[] st2 = version2.split("\\.");
        for(int i = 0; i < Math.max(st1.length, st2.length); ++i) {
            // System.out.println(st1[i]);
            int ver1 = i < st1.length ? Integer.parseInt(st1[i]) : 0;
            int ver2 = i < st2.length ? Integer.parseInt(st2[i]) : 0;
            if(ver1 == ver2)
                continue;
            return ver1 < ver2 ? -1 : 1;
        }
        return 0;
    }
}