
void _wait(void)

{
  undefined4 uVar1;
  undefined4 uStack_8;
  
  uVar1 = _wait1(0,0,&uStack_8,0,_wait);
  *(undefined4 *)(dword_40B57D4 + 0x60) = uStack_8;
  _unix_syscall_return(uVar1);
  return;
}

