class QuickSort{
    
    public static int partition(int[] arr, int begin, int end){
        int mid = begin;
        for (int i = begin+1; i<=end; i++){
            if ( arr[begin] >= arr[i]){
                mid++;
                int tmp = arr[mid];
                arr[mid] = arr[i];
                arr[i] = tmp;
            }
        }

        int tmp = arr[begin];
        arr[begin] = arr[mid];
        arr[mid] = tmp;
        return mid;
    }
    
    public static void sort(int[] arr, int begin, int end){
        if (null == arr || begin < 0 || begin >=end)
            return;
        int mid = partition(arr,begin, end);
        sort(arr,0, mid-1);
        sort(arr,mid+1, end);
    }

    public static void print(int[] a){
        for (int i=0; i<a.length;i++)
            System.out.print(a[i]+" ");
        System.out.println();
    }

    public static void main(String[] args){
        int[] a = {3,2,2,2,4,12,23,44,12,56};
        print(a);
        QuickSort.sort(a,0,a.length-1);
        print(a);
    }
}
