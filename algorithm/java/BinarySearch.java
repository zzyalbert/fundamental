public class BinarySearch {
    public static int search(int[] arr, int value){
        if (null == arr || arr.length <=0)
            return -1;
        int i=0;
        int j=arr.length-1;
        while (i<=j){
            int mid = (j-i)/2+i;
            if (arr[mid]>value)
                j = mid-1;
            else if (arr[mid]<value)
                i = mid+1;
            else
                return mid;
        }
        return -1;
    }

    public static void main(String[] args){
        int[] a = {2,4,5,8,11,23,55,61};
        for (int one:a)
            System.out.print(one+" ");
        System.out.println();
        int value = 11;
        System.out.println("'"+value+"' at index "+BinarySearch.search(a,value));
    }

}
