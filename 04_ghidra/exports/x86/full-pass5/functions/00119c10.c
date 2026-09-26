/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x00119c10 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

uint * _breada(undefined4 param_1,undefined4 param_2,int param_3,int param_4,undefined4 param_5)

{
  int iVar1;
  uint *puVar2;
  uint *puVar3;
  
  _DAT_001e99c8 = _DAT_001e99c8 + 1;
  puVar3 = (uint *)0x0;
  iVar1 = _incore(param_1,param_2);
  if (iVar1 == 0) {
    puVar3 = (uint *)_getblk(param_1,param_2,param_3);
    if ((*puVar3 & 2) == 0) {
      *puVar3 = *puVar3 | 1;
      if ((int)puVar3[6] < (int)puVar3[5]) {
                    /* WARNING: Subroutine does not return */
        _panic(s_breada_001db568);
      }
      (**(code **)(*(int *)(puVar3[0x10] + 0x1c) + 0x54))(puVar3);
      *(int *)(_active_u + 0x19c) = *(int *)(_active_u + 0x19c) + 1;
    }
    else {
      _DAT_001e99cc = _DAT_001e99cc + 1;
    }
  }
  if ((param_4 != 0) && (iVar1 = _incore(param_1,param_4), iVar1 == 0)) {
    puVar2 = (uint *)_getblk(param_1,param_4,param_5);
    if ((*puVar2 & 2) == 0) {
      *puVar2 = *puVar2 | 0x101;
      if ((int)puVar2[6] < (int)puVar2[5]) {
                    /* WARNING: Subroutine does not return */
        _panic(s_breadrabp_001db56f);
      }
      (**(code **)(*(int *)(puVar2[0x10] + 0x1c) + 0x54))(puVar2);
      *(int *)(_active_u + 0x19c) = *(int *)(_active_u + 0x19c) + 1;
    }
    else {
      _brelse(puVar2);
      _DAT_001e99d0 = _DAT_001e99d0 + 1;
    }
  }
  if (puVar3 == (uint *)0x0) {
    __bstats = __bstats + 1;
    if (param_3 == 0) {
                    /* WARNING: Subroutine does not return */
      _panic(s_bread__size_0_001db554);
    }
    puVar3 = (uint *)_getblk(param_1,param_2,param_3);
    if ((*puVar3 & 2) == 0) {
      *puVar3 = *puVar3 | 1;
      if ((int)puVar3[6] < (int)puVar3[5]) {
                    /* WARNING: Subroutine does not return */
        _panic(s_bread_001db562);
      }
      (**(code **)(*(int *)(puVar3[0x10] + 0x1c) + 0x54))(puVar3);
      *(int *)(_active_u + 0x19c) = *(int *)(_active_u + 0x19c) + 1;
      _biowait(puVar3);
    }
    else {
      _DAT_001e99c4 = _DAT_001e99c4 + 1;
    }
  }
  else {
    _biowait(puVar3);
  }
  return puVar3;
}

