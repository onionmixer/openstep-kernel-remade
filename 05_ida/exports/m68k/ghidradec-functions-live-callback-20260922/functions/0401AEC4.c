
void _umask(void)

{
  int *piVar1;
  
  piVar1 = (int *)(dword_40B57D4 + 0x24);
  *(int *)(dword_40B57D4 + 0x5c) = (int)*(sword *)(_active_u + 0x164);
  *(word *)(_active_u + 0x164) = *(word *)(*piVar1 + 2) & 0xfff;
  return;
}

