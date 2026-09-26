/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001cdf30 */

undefined4 * FUN_001cdf30(int param_1)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  
  puVar1 = (undefined4 *)0x0;
  for (puVar2 = *(undefined4 **)(param_1 + 0x1c); puVar2 != (undefined4 *)0x0;
      puVar2 = (undefined4 *)*puVar2) {
    puVar1 = puVar2;
  }
  return puVar1;
}

