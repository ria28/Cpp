public class Multilevel_ll
{
    public class Node
    {
        int data;
        Node next;
        Node child;
    }
    Node head;
    Node tail;
    int size;

    public Node add_right(int arr[], int s)
    {
        Node head =null;
        
        for(int i =0; i<s;i++)
        {
            Node temp =new Node();
            if(head==null)
            {
                temp.data = arr[i];
                temp.next=null;
                head = temp;
                tail = temp;
                size++;   
            }
            else
            {
                temp.data = arr[i];
                temp.next = null;
                tail.next = temp;
                tail =temp;
                size++;
                // System.out.println(head.data);
            }
            temp.next = temp.child = null; 
        }
        
        return head;
    }
    void display(Node node) { 
        while (node != null) { 
            System.out.print(node.data + " "); 
            node = node.next; 
        } 
        System.out.println(""); 
    }

    public Node flatten_createList()
    {
        int arr1[] = new int[]{10, 5, 12, 7, 11}; 
        int arr2[] = new int[]{4, 20, 13}; 
        int arr3[] = new int[]{17, 6}; 
        int arr4[] = new int[]{9, 8}; 
        int arr5[] = new int[]{19, 15}; 
        int arr6[] = new int[]{2}; 
        int arr7[] = new int[]{16}; 
        int arr8[] = new int[]{3};

        Node head1 = add_right(arr1, arr1.length); 
        Node head2 = add_right(arr2, arr2.length); 
        Node head3 = add_right(arr3, arr3.length); 
        Node head4 = add_right(arr4, arr4.length); 
        Node head5 = add_right(arr5, arr5.length); 
        Node head6 = add_right(arr6, arr6.length); 
        Node head7 = add_right(arr7, arr7.length); 
        Node head8 = add_right(arr8, arr8.length);

        // System.out.println(head1.next.data);
    
        head1.child = head2; 
        head1.next.next.next.child = head3; 
        head3.child = head4; 
        head4.child = head5; 
        head2.next.child = head6; 
        head2.next.next.child = head7; 
        head7.child = head8;
        // System.out.println(head1.data);
        return head1;
    }

    public void flattenList(Node head)
    {
        Node tail = head;
        while(tail.next!=null)
            tail = tail.next;
        
        // System.out.println(curr_node.data);

        while(head!=null)
        {
            if(head.child!=null)
            {
                tail.next = head.child;
                tail = head.child;        
            }
            while(tail.next!=null)
            {
                tail = tail.next;
            }

            head = head.next;
        }
    }

    public static void main(String[] args)
    {
        Multilevel_ll ll = new Multilevel_ll(); 
        ll.flatten_createList();
        Node head1 = ll.flatten_createList();
        ll.flattenList(head1);
        ll.display(head1); 
    }


    
}