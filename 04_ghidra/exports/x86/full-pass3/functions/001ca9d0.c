/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001ca9d0 */

void __threadFreeExceptionStack(int param_1)

{
  undefined4 *puVar1;
  
  puVar1 = &DAT_001e551c;
  do {
    if (puVar1[4] == param_1) break;
    puVar1 = (undefined4 *)puVar1[5];
  } while (puVar1 != (undefined4 *)0x0);
  if (puVar1 != (undefined4 *)0x0) {
    *puVar1 = 0;
    puVar1[3] = 0;
    puVar1[4] = 0;
  }
  return;
}

