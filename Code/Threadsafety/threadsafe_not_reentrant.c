thread_local int tmp;
int add10(int a) {
  tmp = a;
  return tmp + 10;
}