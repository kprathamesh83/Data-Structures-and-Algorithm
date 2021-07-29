// HashMap sorting wrt values with comparator
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Comparator;
import java.util.Map.Entry;
import java.util.*;

public class Random{
 
   static public void nothing(int[] arr, int n){
      
        HashMap<Integer, Integer> hm = new HashMap<>();
        for(int i=0;i<n;i++){
            if(hm.containsKey(arr[i])) {
                int a = hm.get(arr[i]);
                hm.replace(arr[i], a, a+1);
            }
            else hm.put(arr[i], 1);
        }
        
        // Collection<Integer> set = hm.values();  // return collection of all values
        // set.forEach(a-> {
        //     System.out.println(a);
        // });
        
        Set<Entry<Integer, Integer>> set = hm.entrySet();  // entrySet() return Set of hashMap 
        List<Entry<Integer, Integer>> ll = new ArrayList<>(set); 
         
    
         // Using Comparator 
         Collections.sort(ll, new Comparator<Entry<Integer, Integer>>(){

            @Override
            public int compare(Entry<Integer, Integer> o1, Entry<Integer, Integer> o2) {
                if(o1.getValue().equals(o2.getValue())) return o1.getKey().compareTo(o2.getKey());
                return o1.getValue().compareTo(o2.getValue());
            }
             
         });
       
         // Using Lambdas
       //  Collections.sort(ll, (o1, o2) -> o1.getValue.compareTo(o2.getValue));  
         
         System.out.println(ll.size());
         int a = ll.get(ll.size()-1).getKey();
         int c = 0;
         int b = ll.get(ll.size()-1).getValue();
        for(int i=ll.size()-2;i>=0;i--){
              if(ll.get(i).getValue() != b){
                    c = ll.get(i).getKey();
                    break; 
              } 
        }
        System.out.println(c+a);

        
    }

    public static void main(String[] args){
        int[] arr = {7, 7, 1, 1, 8,8,8, 2, 4,9,9,10};
         nothing(arr, arr.length);
    }
}
