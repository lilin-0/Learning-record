public class Queue<Item>
{
    private Node first;
    private Node last;
    private int N;
    private class Node
    {
        Item item;
        Node next;
    }
    public boolean isEmpty()
    {
        return N == 0;
    }
    public int size()
    {
        return N;
    }
    public void push(Item item)
    {
        Node oldlast = last;
        last = new Node();
        last.item = item;
        last.next = null;
        if(isEmpty())
            first = last;
        else
            oldlast.next = last;
        N++;
    }
    public Item pop()
    {
        if(isEmpty())
            return null;
        Item item = first.item;
        first = first.next;
        N--;
        return item;
    }
    public static void main(String argv[])
    {
        Queue<Integer> Q = new Queue<Integer>();
        Q.push(333);
        Q.push(444);
        System.out.println(Q.pop());
        System.out.println(Q.pop());
        System.out.println(Q.pop());
    }
}
