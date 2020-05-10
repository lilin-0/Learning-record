public class HeapSort
{
    private static void sink(int[] a,int k,int Max)
    {
        while(k * 2 <= Max)
        {
            int iChild = k * 2;
            if(iChild+1 <= Max && a[iChild] < a[iChild+1])
                iChild++;
            if(a[k] > a[iChild])     // 不需要下沉
                break;
            exch(a,k,iChild);
            k = iChild;
        }
    }

    private static void exch(int[] a, int i, int j)
    {
        int T = a[i];
        a[i] = a[j];
        a[j] = T;
    }
    private static void sort(int[] a)
    {
        int arr[] = new int[a.length + 1];          //从下标1位置拷贝一份新的数组
        for(int i = 1; i < arr.length; i++)
            arr[i] = a[i-1];

        int N = arr.length - 1;
        for(int i = N/2; i >= 1; i--)
            sink(arr, i, N);
        while(N > 1)
        {
            exch(arr,1,N--);
            sink(arr,1,N);
        }

        /* 排好序之后，再放入原数组 */
        for(int i = 0; i < a.length; i++)
            a[i] = arr[i+1];
    }
    public static void main(String[] argv)
    {
        int[] arr = {5,1,4,8,6,0,1,3,6,4};
        sort(arr);
        for(int i = 0; i < arr.length; i++)
            System.out.print(arr[i] + " ");
        System.out.println();
    }
}
