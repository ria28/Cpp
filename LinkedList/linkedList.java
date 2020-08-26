// import java.util.LinkedList;

public class linkedList{

    public class Node{
        int data;
        Node next;
    }
    
    Node head;
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

    
// https://www.geeksforgeeks.org/nth-node-from-the-end-of-a-linked-list/
    public int Nth_node_end(int k)
    {
        // without using size we'll use TWO POINTERS

        Node s=head;
        Node f = head; // slow and fast
        for(int i =0; i<k-1;i++)
            f = f.next;
        
        while(f.next!=null)
        {
            s=s.next;
            f=f.next;
        }
        
        return s.data;
    }

// https://www.geeksforgeeks.org/detect-and-remove-loop-in-a-linked-list/
//FLOYD's algo===============
    public void remove_loop(Node loop_start)
    {
        Node f = loop_start;
        while(true)
        {
            f=f.next;
            if(f.next==loop_start)
                break;
        }
        f.next.next =null;    
    }
    public void detectLoop_remove()
    {
        Node s = head;
        Node f = head;

        while(s!=null && f!=null && f.next!=null)
        {
            s=s.next;
            f=f.next.next;
            if(s==f)
            {
                System.out.println(s.data);
                remove_loop(s); 
                break;               
            }
        }

    }

// https://www.geeksforgeeks.org/write-a-function-to-get-the-intersection-point-of-two-linked-lists/
    public static int intersection(linkedList ll_1 , linkedList ll_2, int size_differ)
    {
        Node head_1= ll_1.head;
        Node head_2 = ll_2.head;

        // System.out.print(head_1.data +" "+ head_2.data);

        for(int i =0; i<size_differ;i++)
            head_1 = head_1.next;
            System.out.print(head_1.data);

        while(head_1.next!=null && head_2.next!=null)
        {
            // System.out.print(head_1.data +" "+ head_2.data);
            if(head_1.data == head_2.data)
                return head_1.data;

            head_1 =head_1.next;
            head_2 = head_2.next;
        }
        return -1;
               
    }
    public static void main(String[] args){
        // LinkedList<Integer> ll = new LinkedList<>();
        linkedList ll = new linkedList();
        ll.addLast(1);
        ll.addLast(4);
        ll.addLast(1);
        ll.addLast(12);
        ll.addLast(10);

        // System.out.println("before deletion : ");
        // ll.display();
        // System.out.println("after deletion : ");
        // deleteNode_withoutHead(head.next.next);
        // ll.display();
        // System.out.println(ll.Nth_node_end(3));

        //loop
        linkedList ll2 =new linkedList();
        ll2.addLast(1);
        ll2.addLast(2);
        ll2.addLast(3);
        ll2.addLast(4);
        ll2.addLast(5);

        // head.next.next.next.next.next =head.next;
        // 1 -> 2 ->3
        //      |   |
        //      5<- 4
        // ll2.detectLoop_remove();
        // ll2.display();

        //Intersection point
        linkedList ll_1= new linkedList();
        ll_1.addLast(3);
        ll_1.addLast(6);
        ll_1.addLast(9);
        ll_1.addLast(15);
        ll_1.addLast(30);

        linkedList ll_2= new linkedList();
        ll_2.addLast(10);
        ll_2.addLast(15);
        ll_2.addLast(30);
     
        int size_differ = (ll_1.size() - ll_2.size());
        System.out.println(intersection(ll_1, ll_2, size_differ));
        
        




    }
}



