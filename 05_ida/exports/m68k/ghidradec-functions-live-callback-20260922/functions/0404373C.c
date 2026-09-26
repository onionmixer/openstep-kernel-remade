
int _ipc_splay_traverse_start(int param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  
  iVar4 = *(int *)(param_1 + 4);
  if (iVar4 != 0) {
    sub_40431D2(iVar4,param_1 + 8,*(undefined4 *)(param_1 + 0xc),param_1 + 0x10,
                *(undefined4 *)(param_1 + 0x14));
    iVar1 = *(int *)(iVar4 + 0x18);
    iVar2 = iVar4;
    iVar3 = 0;
    while (iVar4 = iVar2, iVar1 != 0) {
      iVar2 = *(int *)(iVar4 + 0x18);
      *(int *)(iVar4 + 0x18) = iVar3;
      iVar1 = *(int *)(iVar2 + 0x18);
      iVar3 = iVar4;
    }
    *(int *)(param_1 + 8) = iVar4;
    *(int *)(param_1 + 0x10) = iVar3;
  }
  return iVar4;
}

