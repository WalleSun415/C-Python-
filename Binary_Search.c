int Binary_Search (int *a, int n, int key)
{
    int mid, low, high;
    low = 1;
    hign = n;
    while (low <= high)
    {
        mid = (low + high)/2;
        if (key<a[mid] )
            high = mid-1;  //由于中位元素不等于key，所以将最高下标调整到中位下标小一位
        else if (key>a[mid])
            low = mid+1;  //由于key大于中位元素，所以将最低下标调整为中位下标大一位
        else
            return mid;
    }
    return 0;
}
