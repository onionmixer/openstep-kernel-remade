
undefined4 _fd_get_label(int param_1)

{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  undefined auStack_62 [94];
  
  iVar3 = 0;
  if (*(int *)(param_1 + 0x176) == 0) {
    uVar1 = 5;
  }
  else {
    uVar5 = (*(uint *)(param_1 + 0x186) + 0x1c47) / *(uint *)(param_1 + 0x186);
    iVar4 = 0;
    do {
      iVar2 = _fd_live_rw(param_1,iVar3,uVar5,*(undefined4 *)(param_1 + 0x14),1,auStack_62);
      if ((iVar2 == 0) && (iVar2 = _sdchecklabel(*(undefined4 *)(param_1 + 0x14),iVar3), iVar2 != 0)
         ) {
        *(uint *)(param_1 + 0x176) = *(uint *)(param_1 + 0x176) | 2;
        return 0;
      }
      iVar3 = uVar5 + iVar3;
      iVar4 = iVar4 + 1;
    } while (iVar4 < 4);
    *(uint *)(param_1 + 0x176) = *(uint *)(param_1 + 0x176) & 0xfffffffd;
    uVar1 = 1;
  }
  return uVar1;
}
