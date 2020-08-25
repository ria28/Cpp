// import java.util.LinkedList;

public class linkedList{

    public class Node{
        int data;
        Node next;
    }
    
    static Node head;
    Node tail;
    int size;

    public void addLast(int val)
    {
        if(size==0)
        {
            Node temp = new Node();
            temp.data = val;
            temp.next = null;
            head =tail =temp;
            size++;
        }
        else
        {
            Node temp = new Node();
            temp.data = val;
            temp.next = null;
            tail.next = temp;
            tail = temp;
            size++;
        }
    }

    public int size()
    {
        return size;
    }

    public void display()
    {
        Node temp = head;
        while(temp!=null)
        {
            System.out.print(temp.data+ " ");
            temp = temp.next;
        }
        System.out.println();
    }


// https://www.geeksforgeeks.org/given-only-a-pointer-to-a-node-to-be-deleted-in-a-singly-linked-list-how-do-you-delete-it/
    public static void deleteNode_withoutHead(Node node)
    {
        Node temp = node.next;
        node.data = temp.data;
        node.next= temp.next;
    }

    public static void main(String[] args){
        // LinkedList<Integer> ll = new LinkedList<>();
        linkedList ll = new linkedList();
        ll.addLast(1);
        ll.addLast(4);
        ll.addLast(1);
        ll.addLast(12);
        ll.addLast(10);

        System.out.println("before deletion : ");
        ll.display();
        deleteNode_withoutHead(head.next.next);
        ll.display();

    }
}



