/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001b3298 */

int FUN_001b3298(int param_1,undefined4 param_2,uint param_3)

{
  _objc_msgSend(*(undefined4 *)(param_1 + 0x110),PTR_s_lock_001f9220);
  if (*(char *)(param_1 + 0x1d2) != '\0') {
    *(uint *)(*(int *)(param_1 + 0x168) + 0xc) =
         *(uint *)(*(int *)(param_1 + 0x168) + 0xc) & 0xff80ff80 | param_3 & 0x7f007f;
  }
  _objc_msgSend(*(undefined4 *)(param_1 + 0x110),PTR_s_unlock_001f9474);
  return param_1;
}

