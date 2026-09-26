/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001b2554 */

void FUN_001b2554(int param_1)

{
  _objc_msgSend(param_1,PTR_s_changeCursor__001f998c,*(int *)(*(int *)(param_1 + 0x168) + 0x1c) + 1)
  ;
  *(uint *)(param_1 + 0x1ec) = *(uint *)(param_1 + 0x1e4) + *(uint *)(param_1 + 0x1f8);
  *(uint *)(param_1 + 0x1f0) =
       *(int *)(param_1 + 0x1e8) + *(int *)(param_1 + 0x1fc) +
       (uint)CARRY4(*(uint *)(param_1 + 0x1e4),*(uint *)(param_1 + 0x1f8));
  return;
}

