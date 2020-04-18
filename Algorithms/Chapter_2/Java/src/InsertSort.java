public class InsertSort
{
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

    public static void sort(Comparable[] a)
    {
        // 从1开始
        for(int i = 1; i < a.length; i++)
        {
            for(int j = i; j > 0; j--)
            {
                if(less(a[j],a[j-1]))
                {
                    exch(a,j,j-1);
                }
                else
                    break;
            }
        }
    }
    public static void main(String[] args)
    {
        Integer[] t = {5,9,8,6,5,8,3,2,1,5,4,6,7,0,3};

        sort(t);
        for(int i = 0; i < t.length; i++)
        {
            System.out.println(t[i]);
        }
    }
}
