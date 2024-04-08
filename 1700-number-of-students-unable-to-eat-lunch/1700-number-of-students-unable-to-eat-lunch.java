class Solution {
    public int countStudents(int[] students, int[] sandwiches) {
        ArrayList<Integer> arr = new ArrayList<Integer>();
        int sandIdx = 0;
    
        for(int student : students)
            arr.add(student);
        while (arr.size() != 0) {
            // System.out.println(arr);
            if(!arr.contains(sandwiches[sandIdx]))
                return arr.size();
            if(sandwiches[sandIdx] != arr.get(0))
                arr.add(arr.get(0));
            else
                ++sandIdx;
            arr.remove(0);
        }  
        return 0;
    }
}