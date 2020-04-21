public class ShellSort
{
    public static boolean less(Comparable a,Comparable b)
    {
        return a.compareTo(b) < 0;
    }
    public static void exch(Comparable a[],int x,int y)
    {
        Comparable t = a[x];
        a[x] = a[y];
        a[y] = t;
    }
    public static void sort(Comparable a[])
    {
        int Len = a.length;
        int h = 1;
        while(h < Len/3)
        {
            h = 3 * h + 1;
        }
        while(h >= 1)
        {
            for(int i = h; i < Len; i++)
            {
                for(int j = i; j >= h && less(a[j],a[j-h]); j -= h)
                {
                    exch(a,j,j-h);
                }
            }
            h = h/3;
        }
    }
    public static void main(String argv[])
    {
        Integer[] t = {5,9,4,1,2,4,8,7,3,6,9,1,2,4,0,5,4,1,2,3,5,8};
        sort(t);
        for(int i = 0; i < t.length; i++)
        {
            System.out.println(t[i]);
        }
    }
}
