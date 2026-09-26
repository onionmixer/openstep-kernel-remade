/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x00196ba0 */

undefined4 FUN_00196ba0(int param_1)

{
  undefined4 *puVar1;
  
  puVar1 = *(undefined4 **)(param_1 + 0x110);
  if (puVar1 != (undefined4 *)0x0) {
    (*(code *)*puVar1)(puVar1);
    *(undefined4 *)(param_1 + 0x110) = 0;
  }
  *(undefined4 *)(param_1 + 0x114) = 4;
  return 0;
}

