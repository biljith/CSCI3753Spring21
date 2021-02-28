char arr[10];
int index=0;

int push(char c)
{
    int i=0;
    if(index >= sizeof(arr))
    {
        printf("\n No storage\n");
        return -1;
    }
    arr[index] = c;
    index++;
    return index;
}