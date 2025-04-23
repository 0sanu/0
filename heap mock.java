/*Implement the Heap/Shell sort algorithm implemented in Java demonstrating heap/shell
data structure with modularity of programming language */

import java.util.*;

class HEAP
{
    public static void heapsort(int arr[])
    {
        int n = arr.length;
        for(int i=n/2-1; i>=0; i--)
        {
            heapify(arr,n,i);
        }
        for(int i=n-1; i>0; i--)
        {
            swap(arr,0,i);
            heapify(arr,i,0);
        }
    }

    public static void heapify(int arr[], int n, int i)
    {
        while(true)
        {
            int largest = i;
            int left = 2 * i + 1;
            int right = 2 * i + 2;

            if(left < n && arr[left] > arr[largest])
            {
                largest = left;
            }
            if(right < n && arr[right] > arr[largest])
            {
                largest = right;
            }
            if(largest == i)
            {
                break;
            }

            swap(arr,i,largest);
            i = largest;
        }
    }

    public static void swap(int arr[], int i, int j)
    {
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }

    public static void display(int arr[])
    {
        for(int num: arr)
        {
            System.out.print(num + " ");
        }
    }

    public static void main(String[] args)
    {
        int[] arr = null;
        Scanner sc = new Scanner(System.in);
        boolean temp = true;
        while(temp == true )
        {
            System.out.println("\n*****************MENU****************\n");
            System.out.println("1. Enter elements");
            System.out.println("2. Display elements");
            System.out.println("3. Sort using Heap Sort (Non-Recursive)");
            System.out.println("4. Exit");
            System.out.print("Enter your choice: ");
            int ch = sc.nextInt();
            switch (ch)
            {
                case 1:
                    System.out.println("\nEnter the number of element: ");
                    int n = sc.nextInt();
                    arr = new int[n];
                    System.out.println("\nEnter all elements: ");
                    for(int i=0; i<n; i++)
                    {
                        arr[i] = sc.nextInt();
                    }
                    break;
    
                case 2:
                    System.out.print("\nOrignal element: ");
                    display(arr);
                    System.out.println();
                    break;
    
                case 3:
                    System.out.print("\nOrignal element: ");
                    display(arr);
                    System.out.println();
                    heapsort(arr);
                    System.out.print("\nElement afther heap sort: ");
                    display(arr);
                    System.out.println();
                    break;
                
                case 4:
                    temp = false;
                    System.out.println("\n!! THANK YOU !!\n");
                    break;
            
                default:
                    System.out.println("\n!! INVALID CHOICE !!");
                    break;
            }
        }
    }
}
