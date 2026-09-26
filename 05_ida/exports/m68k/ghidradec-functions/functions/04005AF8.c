
void _wait3(void)

{
  int iVar1;
  int iVar2;
  undefined auStack_4c [72];
  
  iVar1 = *(int *)(*(int *)(dword_40B57D4 + 0x24) + 8);
  iVar2 = _wait1(*(undefined4 *)(*(int *)(dword_40B57D4 + 0x24) + 4),auStack_4c,dword_40B57D4 + 0x60
                 ,0,_wait3);
  if (iVar2 != 0) {
    _unix_syscall_return(iVar2);
  }
  if (iVar1 != 0) {
    iVar2 = _copyoutmsg(auStack_4c,iVar1,0x48);
  }
  _unix_syscall_return(iVar2);
  return;
}
