
int _thread_user_state(int param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  iVar1 = *(int *)(param_1 + 0x24);
  if (*(int *)(iVar1 + 0x4c) == 0) {
    iVar3 = 0x138;
    if (_cpu_type != '\0') {
      iVar3 = 0x244;
    }
    iVar2 = _kalloc(iVar3);
    *(int *)(iVar1 + 0x4c) = iVar2;
    iVar3 = iVar2 + -0x48 + iVar3;
    *(int *)(iVar1 + 0x48) = iVar3;
    _bzero(iVar3,0x48);
  }
  else {
    iVar3 = *(int *)(iVar1 + 0x48);
  }
  return iVar3;
}
