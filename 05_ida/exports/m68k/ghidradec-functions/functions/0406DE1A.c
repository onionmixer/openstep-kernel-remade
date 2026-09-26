
undefined4 _fd_write_label(int param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  undefined4 uVar5;
  undefined auStack_62 [94];
  
  uVar5 = 0;
  iVar2 = 0;
  if (*(uint *)(param_1 + 0x176) == 0) {
    uVar5 = 5;
  }
  else {
    uVar4 = (*(uint *)(param_1 + 0x186) + 0x1c47) / *(uint *)(param_1 + 0x186);
    *(uint *)(param_1 + 0x176) = *(uint *)(param_1 + 0x176) | 2;
    _fd_setbratio(param_1);
    iVar3 = 0;
    do {
      *(int *)(*(int *)(param_1 + 0x14) + 4) = iVar2;
      iVar1 = _fd_live_rw(param_1,iVar2,uVar4,*(undefined4 *)(param_1 + 0x14),0,auStack_62);
      if (iVar1 != 0) {
        uVar5 = 1;
      }
      iVar2 = uVar4 + iVar2;
      iVar3 = iVar3 + 1;
    } while (iVar3 < 4);
  }
  return uVar5;
}
