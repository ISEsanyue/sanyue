class Solution {
    public String longestPalindrome(String s) {     
       StringBuffer ans = new StringBuffer();
       int max = 0;
       for (int i = 0; i < s.length(); i++) {
            StringBuffer sBuffer = new StringBuffer();
            for (int j = i; j < s.length(); j++) {
                char ch = s.charAt(j);
                sBuffer.append(ch);
                StringBuffer rev = new StringBuffer(sBuffer.toString());
                rev.reverse();
                if (sBuffer.toString().equals(rev.toString())) {
                    if (max < sBuffer.length()) {
                        ans.replace(0, sBuffer.length(), sBuffer.toString());
                        max = sBuffer.length();
                    }
                }
            }
       } 
       return ans.toString();
    }
}