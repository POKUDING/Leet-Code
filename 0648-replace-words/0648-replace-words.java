class Solution {
    public String replaceWords(List<String> dictionary, String sentence) {
        StringBuilder sb = new StringBuilder();
        String[] splits = sentence.split(" ");
        for(int i = 0; i < splits.length; ++i) {
            for(String dict : dictionary)
                if(splits[i].startsWith(dict)) {
                    splits[i] = dict;
                }
        }
        sb.append(splits[0]);
        for(int i = 1; i < splits.length; ++i) {
            sb.append(" ");
            sb.append(splits[i]);
        }
        return sb.toString();
    }
}