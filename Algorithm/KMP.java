package Algorithm;

public class KMP {

    static boolean kmp(String s1, String s2) {
        int[] p = new int[s1.length()];

        int j = 0;
        for (int i = 1; i < s1.length(); i++) {
            while (j > 0 && s1.charAt(i) != s1.charAt(j)) {
                j = p[j - 1];
            }
            if (s1.charAt(i) == s1.charAt(j)) {
                j++;
            }
            p[i] = j;
        }

        int i = 0;
        while (i < s1.length()) {
            if (s1.charAt(i) == s2.charAt(j)) {
                if (j == s2.length() - 1) {
                    return true;
                }
                i++;
                j++;
            } else {
                if (j > 0) {
                    j = p[j - 1];
                } else {
                    i++;
                }
            }
        }
        return false;
    }

    public static void main(String[] args) {
        System.out.println(kmp("abababcab", "abc"));
    }
}
