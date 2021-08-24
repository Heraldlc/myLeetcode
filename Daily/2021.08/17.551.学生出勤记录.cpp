class Solution {
    public boolean checkRecord(String s) {
        //a<2 L不能超3
        return s.indexOf("A") == s.lastIndexOf("A") && !s.contains("LLL");
    }
}