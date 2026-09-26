
void _wait4(void)

{
  undefined4 *puVar1;
  int iVar2;
  undefined auStack_50 [4];
  undefined auStack_4c [72];
  
  puVar1 = *(undefined4 **)(dword_40B57D4 + 0x24);
  iVar2 = _wait1(puVar1[2],auStack_4c,auStack_50,*puVar1,_wait4);
  if (iVar2 != 0) {
    _unix_syscall_return(iVar2);
  }
  if (puVar1[3] != 0) {
    iVar2 = _copyoutmsg(auStack_4c,puVar1[3],0x48);
  }
  if (puVar1[1] != 0) {
    iVar2 = _copyoutmsg(auStack_50,puVar1[1],4);
  }
  _unix_syscall_return(iVar2);
  return;
}
