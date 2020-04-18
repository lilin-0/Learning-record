import   java.util.Scanner;

public class UF
{
    private int[] id;
    private int[] sz;
    private int count;
    public UF(int n)
    {
        id = new int[n];
        sz = new int[n];
        for(int i = 0; i < n; i++)
        {
            id[i] = i;
            sz[i] = 0;
        }
        count = n;
    }
    public int getCount()
    {
        return count;
    }
    public int find(int x)
    {
        while(id[x] != x)
            x = id[x];
        return x;
    }
    public void union(int a,int b)
    {
        int a_root = find(a);
        int b_root = find(b);
        if(a_root == b_root)
            return;
        /* 加权，均摊成本，压缩路径 */
        if(sz[a_root] < sz[b_root])
            id[b_root] = a_root;
        else
            id[a_root] = b_root;
    }
    public static void main(String argv[])
    {
        UF test = new UF(10);
        Scanner sc = new Scanner(System.in);
        int N = 11;
        for(int i = 0; i < N; i++)
        {
            int a,b;
            a = sc.nextInt();
            b = sc.nextInt();
            test.union(a,b);
        }
        for(int i = 0; i < 10; i++)
        {
            System.out.println(test.find(i));
        }
    }
}
