import java.util.*;
public class Main{
    public static void main(String []args) {
        Scanner input = new Scanner(System.in);
		String str1 = input.nextLine();
        String str2 = input.nextLine();
        char[] str3 = new String[str1.length() + str2.length() + 6];
        for (int i = 1; i < str3.length(); i += 2) {
            str3[i] = '-';
            str3[i + 1] = '>';
        }
        int length = (str1.length() < str2.length()) ? str1.length() : str2.length();
        for (int i = 0; i < length; i += 2) {
            int j = i * 2;
            if ((int)str1[i] <= (int)str2[i]) {
                str3[j] = str1[i];
                str3[j + 3] = str2[i];
            } else {
                str3[j] = str2[i];
                str3[j + 3] = str1[i];
            }
        }
        if (str1.length() != str2.length()) {
        	System.arraycopy(str1.length() > str2.length() ? str1 : str2, length, str3, length * 2, (str1.length() > str2.length() ? str1.length() : str2.length()) - length);    
        }
        char last[] = new String[4];
        last = "NULL";
        System.arraycopy(last, 0, str3, str3.length() - 4, 4);
        System.out.println(str3);
    }
}