public class SelectSort
{
    public static void sort(Comparable[] a)
    {
        for(int i = 0; i < a.length; i++)
        {
            int min = i;
            for(int j = i + 1; j < a.length; j++)
            {
                if(less(a[j], a[min]))
                {
                    min = j;
                }
            }
            exch(a,i,min);
        }
    }
    public static boolean less(Comparable a, Comparable b)
    {
        return a.compareTo(b) < 0;
    }
    public static void exch(Comparable[] a, int i, int j)
    {
        Comparable t = a[i];
        a[i] = a[j];
        a[j] = t;
    }
    public static void main(String[] args)
    {
        Integer[] t = new Integer[10];
        for(int i = 0; i < 10; i++)
            t[i] = 10 - i;
        sort(t);
        for(int i = 0; i < t.length; i++)
        {
            System.out.println(t[i]);
        }
    }
}
