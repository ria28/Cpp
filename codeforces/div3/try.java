import java.util.*; 
class try_{ 
  
    public static void main(String args[]) 
  
    { 
        int n;
        Scanner sc=new Scanner(System.in);  
        n=sc.nextInt();  
        int[] ar = new int[n];    
        for(int i=0; i<n; i++)  
        {  
        //reading array elements from the user   
        ar[i]=sc.nextInt();  
        }  
        HashMap<Integer,Integer> hm = new HashMap<Integer,Integer>(); 
        for (int i = 0; i < ar.length; i++) { 
            hm.put(ar[i], i); 
        } 
        // Using hm.keySet() to print output reduces time complexity. - Lokesh 
        System.out.println(hm.keySet()); 
  
    } 
  
} 