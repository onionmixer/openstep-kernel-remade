/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x00137944 */

void FUN_00137944(uint *param_1)

{
  uint *puVar1;
  uint *puVar2;
  
  puVar1 = (uint *)0x0;
  puVar2 = *(uint **)(&_drhashtbl + (*param_1 & 0x1f) * 4);
  while( true ) {
    if (puVar2 == (uint *)0x0) {
      return;
    }
    if (puVar2 == param_1) break;
    puVar1 = puVar2;
    puVar2 = (uint *)puVar2[9];
  }
  if (puVar1 == (uint *)0x0) {
    *(uint *)(&_drhashtbl + (*puVar2 & 0x1f) * 4) = puVar2[9];
    return;
  }
  puVar1[9] = puVar2[9];
  return;
}

