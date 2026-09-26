
uint * _breada(undefined4 param_1,undefined4 param_2,undefined4 param_3,int param_4,
              undefined4 param_5)

{
  int iVar1;
  uint *puVar2;
  uint *puVar3;
  
  dword_40B6B54 = dword_40B6B54 + 1;
  puVar3 = (uint *)0x0;
  iVar1 = _incore(param_1,param_2);
  if (iVar1 == 0) {
    puVar3 = (uint *)_getblk(param_1,param_2,param_3);
    if ((*puVar3 & 2) == 0) {
      *puVar3 = *puVar3 | 1;
      if ((int)puVar3[6] < (int)puVar3[5]) {
                    /* WARNING: Subroutine does not return */
        _panic(&aBreada);
      }
      (**(code **)(*(int *)(puVar3[0x10] + 0x1c) + 0x54))(puVar3);
      *(int *)(_active_u + 0x192) = *(int *)(_active_u + 0x192) + 1;
    }
    else {
      dword_40B6B58 = dword_40B6B58 + 1;
    }
  }
  if ((param_4 != 0) && (iVar1 = _incore(param_1,param_4), iVar1 == 0)) {
    puVar2 = (uint *)_getblk(param_1,param_4,param_5);
    if ((*puVar2 & 2) == 0) {
      *puVar2 = *puVar2 | 0x101;
      if ((int)puVar2[6] < (int)puVar2[5]) {
                    /* WARNING: Subroutine does not return */
        _panic(aBreadrabp);
      }
      (**(code **)(*(int *)(puVar2[0x10] + 0x1c) + 0x54))(puVar2);
      *(int *)(_active_u + 0x192) = *(int *)(_active_u + 0x192) + 1;
    }
    else {
      _brelse(puVar2);
      dword_40B6B5C = dword_40B6B5C + 1;
    }
  }
  if (puVar3 == (uint *)0x0) {
    puVar3 = (uint *)_bread(param_1,param_2,param_3);
  }
  else {
    _biowait(puVar3);
  }
  return puVar3;
}
