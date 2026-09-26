/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001c0aa0 */

int FUN_001c0aa0(int param_1)

{
  undefined4 *puVar1;
  
  puVar1 = (undefined4 *)_IOMalloc(4);
  *(undefined4 **)(param_1 + 0x118) = puVar1;
  *puVar1 = 1;
  return param_1;
}

