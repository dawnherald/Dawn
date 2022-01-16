 public class Solution
{
    public int LengthOfLongestSubstring(string s) {
        int i = 0;
        int j = 0;
        int maxLength = 0;
        char[] cs = s.ToCharArray();
        int n = s.Length;
        HashSet<char> cSet = new HashSet<char>();
        while (i < n && j < n)
        {
            if (!cSet.Contains(cs[j]))
            {
                cSet.Add(cs[j]);
                j++;
                maxLength = Math.Max(maxLength, j - i);
            }
            else
            {
                cSet.Remove(cs[i]);
                i++;
            }
        }
        return maxLength;
    }

}
