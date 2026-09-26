
int _ialloc(int param_1,uint param_2,undefined4 param_3)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  
  iVar1 = *(int *)(param_1 + 0x4e);
  if (((*(sword *)(*(int *)(_active_u + 0x1a) + 2) == 0) ||
      (*(int *)(iVar1 + 0x94) < *(int *)(iVar1 + 200))) && (*(int *)(iVar1 + 200) != 0)) {
    uVar2 = *(uint *)(iVar1 + 0xb8) * *(int *)(iVar1 + 0x2c);
    if (uVar2 < param_2 || uVar2 - param_2 == 0) {
      param_2 = 0;
    }
    iVar3 = _hashalloc(param_1,param_2 / *(uint *)(iVar1 + 0xb8),param_2,param_3,_ialloccg);
    if (iVar3 != 0) {
      iVar4 = _iget((int)*(sword *)(param_1 + 0x44),*(undefined4 *)(param_1 + 0x4e),iVar3);
      if (iVar4 == 0) {
        _ifree(param_1,iVar3,0);
        return 0;
      }
      if (*(sword *)(iVar4 + 0x62) != 0) {
        _printf(aMode0OInumDFsS,*(sword *)(iVar4 + 0x62),*(undefined4 *)(iVar4 + 0x46),iVar1 + 0xd4)
        ;
                    /* WARNING: Subroutine does not return */
        _panic(aIallocDupAlloc);
      }
      if (*(int *)(iVar4 + 0xca) != 0) {
        _printf(aFreeInodeSDHad,iVar1 + 0xd4,iVar3,*(int *)(iVar4 + 0xca));
        *(undefined4 *)(iVar4 + 0xca) = 0;
      }
      *(undefined4 *)(iVar4 + 0xc6) = 0;
      return iVar4;
    }
  }
  _fsfull(iVar1,2);
  return 0;
}

