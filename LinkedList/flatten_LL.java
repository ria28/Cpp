public class flatten_LL
{
    class Node  
    {  
        int data;  
        Node right, down;  
        Node(int data)  
        {  
            this.data = data;  
            right = null;  
            down = null;  
        }  
    }

    class pair 
    { 
        int val; 
        Node head; 
          
        pair(Node head,int val) 
        { 
            this.val = val; 
            this.head = head; 
        } 
    } 

    public static Node push(Node head_ref, int data)  
    { 
        // head_ref is like tail here
        Node new_node = new Node(data);   
        new_node.down = head_ref;  
        head_ref = new_node;        //   <-------  
        return head_ref;  
    }

    public static void printList(Node h)  
    {  
        while (h != null) 
        {  
            System.out.print(h.data + " ");  
            h = h.down;  
        }  
    } 

    public static Node flatten(Node root)  
    {  
        Node ptr = root;  
        Node h = null;  
      
        // Min Heap in java 
        PriorityQueue<pair> pq = new PriorityQueue<pair>( 
                                 new pairComp()); 
      
        // Push the head nodes of each  
        // downward linked list  
        while (ptr != null) 
        {  
            pq.add(new pair(ptr, ptr.data));  
            ptr = ptr.right;  
        }  

        while (!pq.isEmpty()) 
        {  
              
            // Pop out 
            Node temp = pq.poll().head;  

            if (temp.down != null)  
            {  
                pq.add(new pair(temp.down, 
                                temp.down.data));  
            }  
      
            // new linked list to be returned  
            if (h == null) 
            {  
                h = temp;  
                ptr = temp;  
            }  
            else
            {  
                ptr.down = temp;  
                ptr = temp;  
            }  
        }  
        return h;  
    }  

    public static void main(String args[])  
    {  
        Node head = null;  
          
        head = push(head, 30);  
        head = push(head, 8);  
        head = push(head, 7);  
        head = push(head, 5);  
      
        head.right = push(head.right, 20);  
        head.right = push(head.right, 10);  
      
        head.right.right = push(head.right.right, 50);  
        head.right.right = push(head.right.right, 22);  
        head.right.right = push(head.right.right, 19);  
      
        head.right.right.right = push( 
                                 head.right.right.right, 45);  
        head.right.right.right = push( 
                                 head.right.right.right, 40);  
        head.right.right.right = push( 
                                 head.right.right.right, 35);  
        head.right.right.right = push( 
                                 head.right.right.right, 20);  
      
        // Flatten the list  
        head = flatten(head);  
      
        printList(head);  
    }  
     

}