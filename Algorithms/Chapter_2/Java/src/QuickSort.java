public class QuickSort
{
    public static void sort(Comparable[] a)
    {
        sort(a,0,a.length-1);
    }
    private static void sort(Comparable[] a, int ibegin, int iend)
    {
        if(ibegin >= iend)
            return;
        int j = partition(a, ibegin, iend);
        sort(a,ibegin,j-1);
        sort(a,j+1,iend);
    }
    private static int partition(Comparable[] a, int ibegin, int iend)
    {
        int i = ibegin, j = iend + 1;
        Comparable v = a[i];        //取第一个做切分
        while(true)
        {
            while(less(a[++i], v))
            {
                if(i == iend)
                    break;
            }
            while(less(v, a[--j]))
            {
                if(j == ibegin)
                    break;
            }
            if(i >= j)
                break;
            exch(a, i, j);
        }
        exch(a, ibegin, j);     //将切分数放入合理位置
        return j;
    }
    private static boolean less(Comparable a, Comparable b)
    {
        return a.compareTo(b) < 0;
    }
    private static void exch(Comparable[] a, int i, int j)
    {
        Comparable T = a[i];
        a[i] = a[j];
        a[j] = T;
    }
    public static void main(String[] argv)
    {
        //Integer[] t  = {5,6,8,1,2,6,8,1,2,3};
        Integer[] t = new Integer[10];
        for(int i = 0; i < 10; i++)
            t[i] = 10 - i;
        sort(t);
        for(int i = 0; i < t.length; i++)
        {
            System.out.print(t[i] + " ");
        }
        System.out.println();
    }
}
