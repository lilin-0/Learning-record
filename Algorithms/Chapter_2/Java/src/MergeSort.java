public class MergeSort
{
    public static void merge(Comparable inArr[], int ibegin, int imid, int iend)
    {
        Comparable temp[] = new Comparable[inArr.length];

        for(int i = 0; i < inArr.length; i++)
            temp[i] = inArr[i];
        int i = ibegin;
        int j = imid + 1;
        for(int k = ibegin; k <= iend; k++)
        {
            if(i > imid)
                inArr[k] = temp[j++];
            else if(j > iend)
                inArr[k] = temp[i++];
            else if(less(temp[i],temp[j]))
                inArr[k] = temp[i++];
            else
                inArr[k] = temp[j++];
        }
    }
    public static boolean less(Comparable a, Comparable b)
    {
        return a.compareTo(b) < 0;
    }
    public static void sort(Comparable inArr[], int ibegin, int iend)
    {
        if(iend <= ibegin)
            return;
        int imid = ibegin + (iend - ibegin) / 2;
        sort(inArr,ibegin,imid);
        sort(inArr,imid + 1, iend);
        merge(inArr,ibegin,imid,iend);
    }
    public static void main(String argv[])
    {
        Integer[] t = {5,9,4,1,2,4,8,7,3,6,9,1,2,4,0,5,4,1,2,3,5,8};
        sort(t,0, t.length - 1);
        for(int i = 0; i < t.length; i++)
        {
            System.out.print(t[i] + " ");
        }
        System.out.println();
    }
}
