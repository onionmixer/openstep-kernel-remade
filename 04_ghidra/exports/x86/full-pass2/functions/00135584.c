/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x00135584 */

void _clntkudp_freecred(int param_1)

{
  int iVar1;
  
  iVar1 = *(int *)(param_1 + 8);
  _crfree(*(undefined4 *)(iVar1 + 0x74));
  *(undefined4 *)(iVar1 + 0x74) = 0xefefefef;
  return;
}

