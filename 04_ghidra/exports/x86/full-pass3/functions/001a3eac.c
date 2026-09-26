/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001a3eac */

undefined4 FUN_001a3eac(uint param_1,undefined4 *param_2)

{
  undefined4 *puVar1;
  
  puVar1 = DAT_001e867c;
  if (DAT_001e8678 < param_1) {
    return 0xfffffd40;
  }
  while( true ) {
    if ((undefined4 **)puVar1 == &DAT_001e867c) {
      return 0xfffffd29;
    }
    if (puVar1[1] == param_1) break;
    puVar1 = (undefined4 *)puVar1[5];
  }
  *param_2 = puVar1;
  return 0;
}

