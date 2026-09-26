/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x00137594 */

void _svckudp_destroy(int param_1)

{
  int iVar1;
  int iVar2;
  
  iVar1 = *(int *)(param_1 + 0x30);
  iVar2 = *(int *)(iVar1 + 8);
  if (iVar2 != 0) {
    _m_freem(iVar2);
  }
  _kfree(iVar1,0x1cc);
  _kfree(*(undefined4 *)(param_1 + 0x2c),0x2260);
  _kfree(param_1,0x34);
  return;
}

