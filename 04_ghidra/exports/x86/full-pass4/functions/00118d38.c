/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x00118d38 */

void _unp_discard(int param_1)

{
  *(short *)(param_1 + 0x10) = *(short *)(param_1 + 0x10) + -1;
  _unp_rights = _unp_rights + -1;
  _closef(param_1);
  return;
}

