// import java.util.LinkedList;
import java.util.HashSet;

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

    public void addFirst(int val)
    {
        Node temp = new Node();
        temp.data = val;
        if(size==0)
        {
            head = temp;
            temp.next=null;
        }
        else
        {
            temp.next = head;
            head = temp;
        }
        size++;
    }

    public int getFirst()
    {
        if(size==0)
            return -1;
        else
            return head.data;
    }

    public void removeFirst()
    {
        head = head.next;
        size--;
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

// Remove Duplicate elements==============================================
// https://www.geeksforgeeks.org/remove-duplicates-from-an-unsorted-linked-list/
    public Node mid_node(Node head,Node tail)
    {
        Node s =head;
        Node f =head;
        while(f!=tail && f.next!=tail)
        {
            f= f.next.next;
            s=s.next;
        }
        return s;
    }

    public linkedList merge2sorted_arr(linkedList ll_1, linkedList ll_2)
    {
        linkedList res = new linkedList();
        Node one = ll_1.head;
        Node two = ll_2.head;

        while(one!=null && two!=null)
        {
            if(one.data<two.data)
            {
                res.addLast(one.data);
                one = one.next;
            }
            else
            {
                res.addLast(two.data);
                two = two.next;
            }
        }

        while(one!=null)
        {
            res.addLast(one.data);
            one = one.next;
        }

        while(two!=null)
        {
            res.addLast(two.data);
            two = two.next;
        }

        return res;
    }

    public linkedList merge_sort(Node head, Node tail)
    {
        if(head == tail)
        {
            linkedList base = new linkedList();
            base.addLast(head.data);
            return base;
        }
        
        Node mid = mid_node(head,tail);
        linkedList fsh = merge_sort(head, mid);
        linkedList ssh = merge_sort(mid.next,tail);

        linkedList res = merge2sorted_arr(fsh,ssh);
        return res;
    }

    public void remove_duplicates(linkedList ll)
    {
        linkedList res = new linkedList();
        while(ll.size()>0)
        {
            int val = ll.getFirst();
            ll.removeFirst();

            if(res.size()==0 || res.tail.data !=val)
                res.addLast(val);            
        }

        ll.head = res.head;
        ll.tail= res.tail;
        ll.size = res.size;

        ll.display();
    }

    // remove duplicates using hashmap

    public void remove_duplicates_2(linkedList ll)
    {
        HashSet<Integer> hs = new HashSet<>();
        Node curr_node = ll.head;
        Node prev =null;
        
        while(curr_node!=null)
        {
            int val = curr_node.data;
            if(hs.contains(val))
                prev.next = curr_node.next;
            else
            {
                hs.add(val);
                prev =curr_node;
            }
            curr_node= curr_node.next;
        }

        ll.display();
    }

    public void repeated_ele_1(linkedList ll)
    {
        linkedList ll_sorted  = merge_sort(ll.head,ll.tail);
        remove_duplicates(ll_sorted);

        remove_duplicates_2(ll);
    }



    // Delete nodes which have a greater value on right side============================
    public void delete_lesser_nodes()
    {
        Node curr_node = this.head;
        while(curr_node!=null)
        {
            if(curr_node.data < curr_node.next.data)
                deleteNode_withoutHead(curr_node);

            curr_node=curr_node.next;
        }
    }

    // SEGREGATE ODD EVEN
    // https://www.geeksforgeeks.org/segregate-even-and-odd-elements-in-a-linked-list/

    public boolean check_even(int data)
    {
        return (data%2==0)?true:false;
    }
    public void segregate_01()
    {
        Node start = this.head;
        Node end = this.tail;

        linkedList odd =new linkedList();
        linkedList even = new linkedList();

        while(start!=null)
        {
            if(check_even(start.data))
                even.addLast(start.data);
            else
                odd.addLast(start.data);
            start=start.next;
        }

        this.head = even.head;
        even.tail.next=odd.head;
    }


// https://www.geeksforgeeks.org/sum-of-two-linked-lists/
    // ADDITION OF LINKED LISTS
    // pv = place value
    public static int add_ll(Node one , int pv1, Node two, int pv2,linkedList res)
    {
        if(one ==null && two == null)
            return 0;
        
        int sum =0;

        if(pv1>pv2)
        {
            int oc = add_ll(one.next,pv1-1,two, pv2,res);
            sum = one.data +oc;   //old carry

        }
        else if(pv2>pv1)
        {
            int oc = add_ll(one,pv1,two.next, pv2-1,res);
            sum = two.data +oc;
        }
        else
        {
            int oc = add_ll(one.next, pv1-1,two.next,pv2-1,res);
            sum = one.data +two.data + oc;
        }

        int new_sum = sum % 10;
        int new_carry= sum / 10;
        res.addFirst(new_sum);
        return new_carry;
    }

// https://www.geeksforgeeks.org/find-a-triplet-from-three-linked-lists-with-sum-equal-to-a-given-number/
    public static void three_ll_sum(Node one, Node two, Node three , int target, int sum)
    {
        sum = one.data+two.data+three.data;
        if(sum == target)
        {
            System.out.println("["+ one.data +", "+two.data +" " + three.data +"]");
            return ;
        }
        
        if(sum > target)
            return;
        else
        {
            if(three.next!=null)
                three_ll_sum(one,two,three.next,target,sum);
            if(two.next!=null)
                three_ll_sum(one,two.next,three,target,sum);
            if(one.next !=null)
                three_ll_sum(one.next,two,three,target,sum);
            
        }
    }

    // segregate 0, 1,2
    public void segregate_012(linkedList ll)
    {
        Node curr_node = ll.head;
        Node cn = ll.head;
        int cnt_0=0, cnt_1=0,cnt_2 =0;
        while(curr_node!=null)
        {
            if(curr_node.data ==0)
                cnt_0++;
            else if(curr_node.data ==1)
                cnt_1++;
            else
                cnt_2++;
            curr_node = curr_node.next;
        }
        // System.out.println(cnt_2);
        while(cnt_0!=0)
        {
            cn.data=0;
            cn=cn.next;
            cnt_0--;
        }
        while(cnt_1!=0)
        {
            cn.data=1;
            cn=cn.next;
            cnt_1--;
        }
        while(cnt_2!=0)
        {
            cn.data=2;
            cn=cn.next;
            cnt_2--;
        }
        ll.display();
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
        // deleteNode_withoutHead(ll.head.next.next);
        // ll.display();
        // System.out.println(ll.Nth_node_end(3));

        //loop===================================================
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

        //Intersection point======================================
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
        // System.out.println(intersection(ll_1, ll_2, size_differ));


        // remove repeated elements ===============================================
        linkedList ll_rep= new linkedList();
        ll_rep.addLast(12);
        ll_rep.addLast(11);
        ll_rep.addLast(12);
        ll_rep.addLast(21);
        ll_rep.addLast(41);
        ll_rep.addLast(43);
        ll_rep.addLast(21);

        // ll_rep.repeated_ele_1(ll_rep);

        // steps (ologn)
        // 1. Sort -> merge_sort() -> middle , merge2sorted_arr()
        // 2. Remove duplicates from sorted array on ologn


        linkedList ll_3 = new linkedList();
        ll_3.addLast(12);
        ll_3.addLast(15);
        ll_3.addLast(10);
        ll_3.addLast(11);
        ll_3.addLast(5);
        ll_3.addLast(6);
        ll_3.addLast(2);
        ll_3.addLast(3);

        // ll_3.delete_lesser_nodes();
        // ll_3.display();

        // ll.segregate_01();
        // ll.display();

        linkedList res =new linkedList();
        // int oc = add_ll(ll.head,ll.size,ll2.head,ll2.size,res);
        // res.display();


    // triplet sum============================================================
        linkedList triplet_1 = new linkedList();
        linkedList triplet_2 = new linkedList();
        linkedList triplet_3 = new linkedList();
        triplet_1.addLast(12);
        triplet_1.addLast(6);
        triplet_1.addLast(29);

        triplet_2.addLast(23);
        triplet_2.addLast(5);
        triplet_2.addLast(8);

        triplet_3.addLast(90);
        triplet_3.addLast(20);
        triplet_3.addLast(59);      
        
        int target = 101;

        // three_ll_sum(triplet_1.merge_sort(triplet_1.head,triplet_1.tail).head,
        // triplet_2.merge_sort(triplet_2.head,triplet_2.tail).head, 
        // triplet_3.merge_sort(triplet_3.head,triplet_3.tail).head,target,0);


        linkedList ll4 = new linkedList();
        // 2  1  2  1  1  2  0  1  0
        ll4.addLast(2);
        ll4.addLast(1);
        ll4.addLast(2);
        ll4.addLast(1);
        ll4.addLast(1);
        ll4.addLast(2);
        ll4.addLast(0);
        ll4.addLast(1);
        ll4.addLast(0);
        ll4.segregate_012(ll4);


    }
}



