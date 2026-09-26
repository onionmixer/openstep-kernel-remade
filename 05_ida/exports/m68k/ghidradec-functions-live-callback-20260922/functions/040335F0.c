
int _alloc(int param_1,int param_2,uint param_3)

{
  int iVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  
  iVar3 = *(int *)(param_1 + 0x4e);
  if ((*(uint *)(iVar3 + 0x30) < param_3) || ((param_3 & ~*(uint *)(iVar3 + 0x4c)) != 0)) {
    _printf(aDev0xXBsizeDSi,(int)*(sword *)(param_1 + 0x44),*(uint *)(iVar3 + 0x30),param_3,
            iVar3 + 0xd4);
                    /* WARNING: Subroutine does not return */
    _panic(aAllocBadSize);
  }
  if (((param_3 != *(uint *)(iVar3 + 0x30)) || (*(int *)(iVar3 + 0xc4) != 0)) &&
     ((*(sword *)(*(int *)(_active_u + 0x1a) + 2) == 0 ||
      (iVar1 = *(int *)(iVar3 + 0xcc) + (*(int *)(iVar3 + 0xc4) << (*(uint *)(iVar3 + 0x60) & 0x3f))
      , iVar2 = (*(int *)(iVar3 + 0x3c) * *(int *)(iVar3 + 0x28)) / 100,
      iVar1 != iVar2 && -1 < iVar1 - iVar2)))) {
    if (*(int *)(iVar3 + 0x24) <= param_2) {
      param_2 = 0;
    }
    if (param_2 == 0) {
      uVar4 = *(uint *)(param_1 + 0x46) / *(uint *)(iVar3 + 0xb8);
    }
    else {
      uVar4 = param_2 / *(int *)(iVar3 + 0xbc);
    }
    iVar1 = _hashalloc(param_1,uVar4,param_2,param_3,_alloccg);
    if (0 < iVar1) {
      iVar2 = (**(code **)(*(int *)(param_1 + 0x28) + 0x80))(param_1 + 0xc);
      *(int *)(param_1 + 0xca) = (int)param_3 / iVar2 + *(int *)(param_1 + 0xca);
      *(word *)(param_1 + 0x42) = *(word *)(param_1 + 0x42) | 0x42;
      iVar3 = _getblk(*(undefined4 *)(param_1 + 0x3e),iVar1 << (*(uint *)(iVar3 + 100) & 0x3f),
                      param_3);
      _blkclr(*(undefined4 *)(iVar3 + 0x20),*(undefined4 *)(iVar3 + 0x14));
      *(undefined4 *)(iVar3 + 0x28) = 0;
      return iVar3;
    }
  }
  _fsfull(iVar3,1);
  return 0;
}

