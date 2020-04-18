import java.util.Iterator;
import java.util.function.Consumer;

public class Stack <Item>
{
    private Node first;         // 栈顶
    private int N;              // 数量
    private class Node          // 节点类
    {
        Item item;
        Node next;
    }
    
    public boolean isEmpty()
    {
        return first == null;
    }
    
    public int size()
    {
        return N;
    }
    
    public void push(Item item)
    {
        Node temp_first = first;
        first = new Node();
        first.item = item;
        first.next = temp_first;
        N++;
    }
    
    public Item pop()
    {
        if(isEmpty())       // 增加判空
            return null;
        Item tempItem = first.item;
        first = first.next;
        N--;
        return tempItem;
    }
    
    public static void main(String argv[])
    {
        Stack<Double> test = new Stack<Double>();
        test.push(12.0);
        test.push(3.3);
        test.push(2.2);
        System.out.printf("pop:%f\n",test.pop());
        System.out.printf("pop:%f\n",test.pop());
        System.out.printf("pop:%f\n",test.pop());
        System.out.printf("pop:%f",test.pop());
        /*System.out.printf("pop:%f",test.pop());
        System.out.printf("pop:%f",test.pop());*/
    }
}
