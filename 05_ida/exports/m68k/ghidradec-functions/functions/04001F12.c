
void trap6(void)

{
  undefined4 in_D0;
  
  *(undefined4 *)(*(int *)(_active_threads + 0x24) + 0x50) = in_D0;
  return;
}
