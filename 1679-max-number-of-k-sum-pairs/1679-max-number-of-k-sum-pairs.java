class Solution {
    public int maxOperations(int[] nums, int k) {
        //사전검증로직
        if(nums.length < 2 || k < 1) return 0;
        int count = 0;

        Map<Integer, Integer> map = new HashMap<>(); //배열에 있는 각 숫자의 빈도를 저장할 해시맵 생성
        for(int i = 0; i < nums.length; i++) {
            int temp = k - nums[i];

            if(map.containsKey(temp)) { //containsKey(temp) 메서드는 맵에 temp라는 키가 포함되어 있는지 확인하는 메서드이다.
                count++;

                if(map.get(temp) == 1) { //temp 키의 값이 1이면 //개수를 말하는 건가?
                    map.remove(temp); //temp 키를 맵에서 제거
                } else { //temp 키의 값이 1이 아니면
                    map.put(temp, map.get(temp) - 1); //temp 키의 값을 1 감소
                }
            }else { //temp 키가 맵에 존재하지 않으면
                map.put(nums[i], map.getOrDefault(nums[i], 0) + 1); //nums[i] 키의 값을 1 증가시키거나, 없으면 1로 초기화
            }
        }
       return count;
    }
}