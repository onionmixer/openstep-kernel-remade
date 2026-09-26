/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0011867c */

void _unp_detach(int *param_1)

{
  if (param_1[1] != 0) {
    *(undefined4 *)(param_1[1] + 0x20) = 0;
    _vn_rele(param_1[1]);
    param_1[1] = 0;
  }
  if (param_1[3] != 0) {
    _unp_disconnect(param_1);
  }
  while (param_1[4] != 0) {
    _unp_drop(param_1[4],0x36);
  }
  _soisdisconnected(*param_1);
  *(undefined4 *)(*param_1 + 8) = 0;
  _m_freem(param_1[6]);
  _kfree(param_1,0x24);
  if (_unp_rights != 0) {
    _unp_gc();
  }
  return;
}

