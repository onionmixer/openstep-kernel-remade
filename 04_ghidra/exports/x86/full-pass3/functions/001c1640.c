/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001c1640 */

undefined4 FUN_001c1640(int param_1,undefined4 param_2,undefined4 *param_3)

{
  if (*(char *)(*(int *)(param_1 + 0x20) + 0x10) != '\0') {
    if (param_3 != (undefined4 *)0x0) {
      *param_3 = *(undefined4 *)(*(int *)(param_1 + 0x20) + 0x14);
    }
    return 0;
  }
  return 0xfffffd40;
}

