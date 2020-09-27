// Definition for singly-linked list.
class ListNode {
  int val;
  ListNode next;

  ListNode() {
  }

  ListNode(int val) {
    this.val = val;
  }

  ListNode(int val, ListNode next) {
    this.val = val;
    this.next = next;
  }
}

class try1 {

  public static ListNode addLast(int val, ListNode res) {
    ListNode temp = new ListNode();
    temp.val = val;
    temp.next = null;

    if (res == null) {
      res = temp;
    } else {
      while (res.next != null)
        res = res.next;
      res.next = temp;
    }
    return res;
  }

  public  static ListNode midNode(ListNode head) {
    
    if(head.next == null)
      return head;
    ListNode s = head, f = head;
    while (f.next != null && f.next.next != null) {
      s = s.next;
      f = f.next.next;
    }
    return s;
  }

  public static ListNode merge2sortedList(ListNode l1, ListNode l2) {
    ListNode one = l1;
    ListNode two = l2;

    
    ListNode res = new ListNode();
    ListNode dummy = new ListNode(0);
    dummy =res;

    while (one != null && two != null) {
      if (one.val < two.val) {
        res = addLast(one.val, res);
        one = one.next;
      } else {
        res = addLast(two.val, res);
        two = two.next;
      }
    }

    while (one != null) {
      res = addLast(one.val, res);
      one = one.next;
    }
    while (one != null) {
      res = addLast(two.val, res);
      two = two.next;
    }

    return dummy.next;
  }

  public static ListNode mergeSort(ListNode head) {
    if(head==null || head.next == null){
      return head;
    }
    // if (head == tail) {
    //   ListNode br = new ListNode();
    //   br = addLast(head.val, br);
    //   return br;
    // }

    ListNode mid = midNode(head);
    ListNode nextMid = mid.next;
    mid.next = null;
    ListNode fsh = mergeSort(head);
    ListNode ssh = mergeSort(nextMid);

    ListNode cl = merge2sortedList(fsh, ssh);
    return cl;
    
  }

  public static void sortList(ListNode head) {
    ListNode tail = head;
    while (tail.next != null)
      tail = tail.next;
    ListNode res = mergeSort(head);
    while(res != null){
      System.out.println(res.val);
      res = res.next;
    }
  }

  public static void main(String[] args) {
    ListNode head = new ListNode(4);
    // ListNode dummy = new ListNode(0);
    // dummy.next = head;
    head.next = new ListNode(1);
    head.next.next = new ListNode(3);
    head.next.next.next = new ListNode(2);

    sortList(head);


    // head.next = new ListNode(5);
    // head.next.next = new ListNode(6);
    // head.next.next.next = new ListNode(7);

    // ListNode head2 = new ListNode(1);
    // head2.next = new ListNode(5);
    // head2.next.next = new ListNode(6);
    // head2.next.next.next = new ListNode(7);

    // ListNode res =merge2sortedList(head, head2);
    
    // while(res != null){
    //   System.out.println(res.val);
    //   res = res.next;
    // }



  }
}