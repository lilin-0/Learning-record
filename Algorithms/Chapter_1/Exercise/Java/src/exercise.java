//import sun.lwawt.macosx.CSystemTray;

import java.util.Scanner;

public class exercise
{
    public static void main(String[] args)
    {
        //myFirstProgram();
        //exercise_113();
        exercise_119();
    }
    /* test first program and exercise */
    public static void myFirstProgram()
    {
        System.out.println("hello word");
        System.out.println((0+15) / 2);
        System.out.println(2.0e-6 * 100000000.1);
        System.out.println(true&&false || true && true);
        System.out.println((1+2.236)/2);
        System.out.println(1+2+3+4.0);
        System.out.println(4.1>=4);
        System.out.println(1+2+"3");
    }
    // exercise 1.1.3
    public static void exercise_113()
    {
        Scanner x = new Scanner(System.in);
        int a = x.nextInt();
        int b = x.nextInt();
        int c = x.nextInt();
        if(a == b && a == c)
        {
            System.out.println("equal");
        }
    }

    // exercise 1.1.5
    public static void exercise_115()
    {
        Scanner x = new Scanner(System.in);
        double a = x.nextDouble();
        if(a >= 0 && a <= 1)
            System.out.println(true);
        else
            System.out.println(false);
    }
    // exercise 1.1.6
    public static void exercise_116()
    {
        int f = 0;
        int g = 1;
        for(int i = 0; i <= 15; i++)
        {
            System.out.println(f);
            f = f + g;
            g = f - g;
        }
    }
    // 1.1.9
    public static void exercise_119()
    {
        String s = "";
        int N = 382;
        for(int n = N; n > 0; n /= 2 )
        {
            s = (n % 2) + s;
        }
        System.out.println(s);
    }
}