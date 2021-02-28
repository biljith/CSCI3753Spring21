int temp;

void swap(int *y, int *z)  
{
   int local;
   local = temp;
   temp = *y;
   *y = *z;
   *z = temp;
   temp = local;
}