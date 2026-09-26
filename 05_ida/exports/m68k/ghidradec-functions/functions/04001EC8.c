
undefined8 trap4(void)

{
  int iVar1;
  undefined4 in_D0;
  undefined4 in_D1;
  undefined4 uStack_40;
  undefined4 uStack_3c;
  
  iVar1 = _stack_pointers;
  dword_40B5658 = dword_40B5658 + 1;
  *(undefined4 **)(_stack_pointers + -4) = &uStack_40;
  *(undefined4 *)(iVar1 + -8) = 0x4001eee;
  uStack_40 = in_D0;
  uStack_3c = in_D1;
  _unix_syscall();
  return CONCAT44(uStack_40,uStack_3c);
}
