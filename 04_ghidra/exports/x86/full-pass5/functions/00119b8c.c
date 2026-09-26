/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x00119b8c */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

uint * _bread(undefined4 param_1,undefined4 param_2,int param_3)

{
  uint *puVar1;
  
  __bstats = __bstats + 1;
  if (param_3 == 0) {
                    /* WARNING: Subroutine does not return */
    _panic(s_bread__size_0_001db554);
  }
  puVar1 = (uint *)_getblk(param_1,param_2,param_3);
  if ((*puVar1 & 2) == 0) {
    *puVar1 = *puVar1 | 1;
    if ((int)puVar1[6] < (int)puVar1[5]) {
                    /* WARNING: Subroutine does not return */
      _panic(s_bread_001db562);
    }
    (**(code **)(*(int *)(puVar1[0x10] + 0x1c) + 0x54))(puVar1);
    *(int *)(_active_u + 0x19c) = *(int *)(_active_u + 0x19c) + 1;
    _biowait(puVar1);
  }
  else {
    _DAT_001e99c4 = _DAT_001e99c4 + 1;
  }
  return puVar1;
}

