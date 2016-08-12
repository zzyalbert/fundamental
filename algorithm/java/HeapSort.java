class HeapSort{
    
    public static void adjust(int[] arr, int begin, int end){
        int big_child = begin*2+1;
        if (big_child > end)
            return;
        if (big_child+1<=end && arr[big_child+1]>arr[big_child])
            big_child++;
        if (arr[begin]<arr[big_child]){
            int tmp = arr[begin];
            arr[begin] = arr[big_child];
            arr[big_child] = tmp;
            adjust(arr, big_child, end);
        }
    }
    
    public static void sort(int[] arr){
        if (null == arr || arr.length<=1)
            return;
        int begin = 0;
        int end = arr.length-1;
        for (int i= (end-1)/2; i>=begin; i--)
            adjust(arr, i, end);
        for (int i=end;i>begin;i--){
            int tmp = arr[i];
            arr[i] = arr[begin];
            arr[begin] = tmp;
            adjust(arr, begin, i-1);
        }
    }

    public static void print(int[] a){
        for (int i=0; i<a.length;i++)
            System.out.print(a[i]+" ");
        System.out.println();
    }

    public static void main(String[] args){
        int[] a = {3,2,2,2,4,12,23,44,12,56};
        print(a);
        HeapSort.sort(a);
        print(a);
    }
}
