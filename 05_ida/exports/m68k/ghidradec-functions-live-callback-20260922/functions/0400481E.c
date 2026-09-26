
void _expand_fdlist(int param_1,int param_2)

{
  int iVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  
  if (*(int *)(param_1 + 0x152) <= param_2) {
    iVar2 = param_2 + 1;
    iVar3 = iVar2 * 4;
    uVar4 = _kalloc(iVar3);
    uVar5 = _kalloc(iVar2);
    iVar1 = *(int *)(param_1 + 0x152);
    if (param_2 < iVar1) {
      _kfree(uVar4,iVar3);
      _kfree(uVar5,iVar2);
    }
    else {
      _bzero(uVar4,iVar3);
      _bzero(uVar5,iVar2);
      if (iVar1 != 0) {
        _bcopy(*(undefined4 *)(param_1 + 0x146),uVar4,iVar1 << 2);
        _bcopy(*(undefined4 *)(param_1 + 0x14a),uVar5,iVar1);
        _kfree(*(undefined4 *)(param_1 + 0x146),iVar1 << 2);
        _kfree(*(undefined4 *)(param_1 + 0x14a),iVar1);
      }
      *(undefined4 *)(param_1 + 0x146) = uVar4;
      *(undefined4 *)(param_1 + 0x14a) = uVar5;
      *(int *)(param_1 + 0x152) = iVar2;
    }
  }
  return;
}

