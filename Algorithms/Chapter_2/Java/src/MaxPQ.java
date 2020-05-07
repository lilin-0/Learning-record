public class MaxPQ<Key extends Comparable<Key>>
{
    private Key[] pq;       //完全二叉树
    private int N = 0;      //队列长度
    private int MaxLen = 0;

    public MaxPQ(int maxN)
    {
        pq = (Key[]) new Comparable[maxN + 1];
        MaxLen = maxN;
    }

    public boolean isEmpty()
    {
        return N == 0;
    }

    public int size()
    {
        return N;
    }

    public void insert(Key k)
    {
        pq[++N] = k;    //插入到最后一个位置
        swim(N);        //将插入的元素上浮
    }

    public Key pop()
    {
        Key temp = pq[1];      //先取出值
        exch(1,N--);        //将最后一个元素放到根位置
        sink(1);           //下沉
        return temp;
    }

    private boolean less(int i, int j)
    {
        return pq[i].compareTo(pq[j]) < 0;
    }
    private void exch(int i, int j)
    {
        Key t = pq[i];
        pq[i] = pq[j];
        pq[j] = t;
    }

    private void swim(int k)        //上浮
    {
        while(k > 1 && less(k/2,k))
        {
            exch(k/2,k);
            k = k/2;
        }
    }
    private void sink(int k)        //下沉
    {
        //两个子节点分别为2*k,2*k+1
        while(2*k <= N)
        {
            int child = 2*k;
            if(child+1 <= N && less(child,child+1))     //不越界的情况下，取两个子节点较大的一个
                child++;
            if(!less(k,child))      //将要下沉的值不小于最大的子节点
                break;
            /* 完成下沉，并且记录下沉之后的位置，用于下次循环继续判断下沉 */
            exch(k,child);
            k = child;
        }
    }

    public static void main(String[] argv)
    {
        MaxPQ<Integer> pq = new MaxPQ<Integer>(10);
        pq.insert(3);
        pq.insert(3);
        pq.insert(6);
        pq.insert(9);
        pq.insert(5);
        pq.insert(8);
        for(int i = 0; i < 6; i++)
            System.out.println("pop---" + pq.pop());
    }
}
