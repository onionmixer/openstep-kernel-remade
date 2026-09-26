
undefined4 _get_sfsr(void)

{
  int iVar1;
  
  iVar1 = segment(4);
  return *(undefined4 *)(iVar1 + 0x300);
}
