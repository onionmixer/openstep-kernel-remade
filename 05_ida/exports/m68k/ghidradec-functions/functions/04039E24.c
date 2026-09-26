
void _sbupdate(int param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  
  iVar1 = *(int *)(*(int *)(param_1 + 10) + 0x20);
  iVar2 = (**(code **)(*(int *)(*(int *)(param_1 + 6) + 0x1c) + 0x80))(*(int *)(param_1 + 6));
  if (-1 < iVar2) {
    iVar2 = _getblk(*(undefined4 *)(param_1 + 6),0x2000 / iVar2,*(undefined4 *)(iVar1 + 0x68));
    _bcopy(iVar1,*(undefined4 *)(iVar2 + 0x20),*(undefined4 *)(iVar1 + 0x68));
    *(undefined4 *)(*(int *)(iVar2 + 0x20) + 0x8c) = 0;
    *(undefined4 *)(*(int *)(iVar2 + 0x20) + 0x88) = 0;
    *(undefined4 *)(*(int *)(iVar2 + 0x20) + 0x94) = 0;
    *(undefined4 *)(*(int *)(iVar2 + 0x20) + 0x90) = 0;
    *(undefined *)(*(int *)(iVar2 + 0x20) + 0xd3) = 0;
    _bwrite(iVar2);
    iVar6 = (*(int *)(iVar1 + 0x34) + *(int *)(iVar1 + 0x9c) + -1) / *(int *)(iVar1 + 0x34);
    iVar2 = *(int *)(iVar1 + 0x2d8);
    iVar5 = 0;
    if (0 < iVar6) {
      do {
        iVar4 = *(int *)(iVar1 + 0x30);
        if (iVar6 < *(int *)(iVar1 + 0x38) + iVar5) {
          iVar4 = *(int *)(iVar1 + 0x34) * (iVar6 - iVar5);
        }
        iVar3 = _getblk(*(undefined4 *)(param_1 + 6),
                        iVar5 + *(int *)(iVar1 + 0x98) << (*(uint *)(iVar1 + 100) & 0x3f),iVar4);
        _bcopy(iVar2,*(undefined4 *)(iVar3 + 0x20),iVar4);
        iVar2 = iVar4 + iVar2;
        _bwrite(iVar3);
        iVar5 = *(int *)(iVar1 + 0x38) + iVar5;
      } while (iVar5 < iVar6);
    }
  }
  return;
}
