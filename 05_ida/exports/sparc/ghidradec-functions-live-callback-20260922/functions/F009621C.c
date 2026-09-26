
undefined4 _swift_getversion(void)

{
  int iVar1;
  
  iVar1 = segment(0x20);
  return *(undefined4 *)(iVar1 + 0x10003018);
}

