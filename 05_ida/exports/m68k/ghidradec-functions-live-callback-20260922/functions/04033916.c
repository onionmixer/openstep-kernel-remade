
uint * _realloccg(int param_1,int param_2,int param_3,uint param_4,uint param_5)

{
  int iVar1;
  uint *puVar2;
  int iVar3;
  uint *puVar4;
  int iVar5;
  uint uStack_8;
  
  iVar3 = *(int *)(param_1 + 0x4e);
  if ((((*(uint *)(iVar3 + 0x30) < param_4) || ((~*(uint *)(iVar3 + 0x4c) & param_4) != 0)) ||
      (*(uint *)(iVar3 + 0x30) < param_5)) || ((~*(uint *)(iVar3 + 0x4c) & param_5) != 0)) {
    _printf(aDev0xXBsizeDOs,(int)*(sword *)(param_1 + 0x44),*(undefined4 *)(iVar3 + 0x30),param_4,
            param_5,iVar3 + 0xd4);
                    /* WARNING: Subroutine does not return */
    _panic(aRealloccgBadSi);
  }
  if ((*(sword *)(*(int *)(_active_u + 0x1a) + 2) != 0) &&
     (iVar1 = *(int *)(iVar3 + 0xcc) + (*(int *)(iVar3 + 0xc4) << (*(uint *)(iVar3 + 0x60) & 0x3f)),
     iVar5 = (*(int *)(iVar3 + 0x3c) * *(int *)(iVar3 + 0x28)) / 100,
     iVar1 == iVar5 || iVar1 - iVar5 < 0)) {
loc_4033C44:
    _fsfull(iVar3,1);
    return (uint *)0x0;
  }
  if (param_2 == 0) {
    _printf(aDev0xXBsizeDBp,(int)*(sword *)(param_1 + 0x44),*(undefined4 *)(iVar3 + 0x30),0,
            iVar3 + 0xd4);
                    /* WARNING: Subroutine does not return */
    _panic(aRealloccgBadBp);
  }
  iVar5 = param_2 / *(int *)(iVar3 + 0xbc);
  iVar1 = _fragextend(param_1,iVar5,param_2,param_4,param_5);
  if (iVar1 == 0) {
    if (*(int *)(iVar3 + 0x24) <= param_3) {
      param_3 = 0;
    }
    if (*(int *)(iVar3 + 0x80) == 0) {
      uStack_8 = *(uint *)(iVar3 + 0x30);
      if (((*(int *)(iVar3 + 0x3c) + -2) * *(int *)(iVar3 + 0x28)) / 100 <= *(int *)(iVar3 + 0xcc))
      {
        _log(5,aSOptimizationC_0,iVar3 + 0xd4);
        *(undefined4 *)(iVar3 + 0x80) = 1;
      }
    }
    else if (*(int *)(iVar3 + 0x80) == 1) {
      uStack_8 = param_5;
      if ((4 < *(int *)(iVar3 + 0x3c)) &&
         (*(int *)(iVar3 + 0xcc) <= (*(int *)(iVar3 + 0x28) * *(int *)(iVar3 + 0x3c)) / 200)) {
        _log(5,aSOptimizationC,iVar3 + 0xd4);
        *(undefined4 *)(iVar3 + 0x80) = 0;
      }
    }
    else {
      *(undefined4 *)(iVar3 + 0x80) = 1;
      uStack_8 = param_5;
    }
    iVar1 = _hashalloc(param_1,iVar5,param_3,uStack_8,_alloccg);
    if (iVar1 < 1) goto loc_4033C44;
    puVar4 = (uint *)_bread(*(undefined4 *)(param_1 + 0x3e),
                            param_2 << (*(uint *)(iVar3 + 100) & 0x3f),param_4);
    if ((*puVar4 & 4) != 0) {
      _brelse(puVar4);
      return (uint *)0x0;
    }
    puVar2 = (uint *)_getblk(*(undefined4 *)(param_1 + 0x3e),
                             iVar1 << (*(uint *)(iVar3 + 100) & 0x3f),param_5);
    _bcopy(puVar4[8],puVar2[8],param_4);
    _bzero(param_4 + puVar2[8],param_5 - param_4);
    if ((*puVar4 & 0x200) != 0) {
      *puVar4 = *puVar4 & 0xfffffdff;
      *(int *)(_active_u + 0x196) = *(int *)(_active_u + 0x196) + -1;
    }
    _brelse(puVar4);
    _free_block(param_1,param_2,param_4);
    if ((int)param_5 < (int)uStack_8) {
      _free_block(param_1,iVar1 + ((int)param_5 >> (*(uint *)(iVar3 + 0x54) & 0x3f)),
                  uStack_8 - param_5);
    }
    iVar3 = (**(code **)(*(int *)(param_1 + 0x28) + 0x80))(param_1 + 0xc);
    *(int *)(param_1 + 0xca) = (int)(param_5 - param_4) / iVar3 + *(int *)(param_1 + 0xca);
  }
  else {
    do {
      puVar2 = (uint *)_bread(*(undefined4 *)(param_1 + 0x3e),
                              iVar1 << (*(uint *)(iVar3 + 100) & 0x3f),param_4);
      if ((*puVar2 & 4) != 0) {
        _brelse(puVar2);
        return (uint *)0x0;
      }
      iVar5 = _brealloc(puVar2,param_5);
    } while (iVar5 == 0);
    *puVar2 = *puVar2 | 2;
    _bzero(puVar2[8] + param_4,param_5 - param_4);
    iVar3 = (**(code **)(*(int *)(param_1 + 0x28) + 0x80))(param_1 + 0xc);
    *(int *)(param_1 + 0xca) = (int)(param_5 - param_4) / iVar3 + *(int *)(param_1 + 0xca);
  }
  *(word *)(param_1 + 0x42) = *(word *)(param_1 + 0x42) | 0x42;
  return puVar2;
}

