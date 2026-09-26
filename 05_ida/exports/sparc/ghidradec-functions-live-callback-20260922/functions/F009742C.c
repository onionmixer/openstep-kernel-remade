
undefined4 _p4m35_get_sysctl(void)

{
  int iVar1;
  
  iVar1 = segment(0x20);
  return *(undefined4 *)(iVar1 + 0x79f00000);
}

