/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001378c4 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 _svckudp_dup(uint *param_1)

{
  uint uVar1;
  int iVar2;
  uint *puVar3;
  
  __dupchecks = __dupchecks + 1;
  uVar1 = *(uint *)(*(int *)(param_1[7] + 0x30) + 4);
  puVar3 = *(uint **)(&_drhashtbl + (uVar1 & 0x1f) * 4);
  while( true ) {
    if (puVar3 == (uint *)0x0) {
      return 0;
    }
    if ((((*puVar3 == uVar1) && (puVar3[7] == *param_1)) && (puVar3[6] == param_1[1])) &&
       ((puVar3[5] == param_1[2] &&
        (iVar2 = _bcmp(puVar3 + 1,(void *)(param_1[7] + 0x10),0x10), iVar2 == 0)))) break;
    puVar3 = (uint *)puVar3[9];
  }
  __dupreqs = __dupreqs + 1;
  return 1;
}

