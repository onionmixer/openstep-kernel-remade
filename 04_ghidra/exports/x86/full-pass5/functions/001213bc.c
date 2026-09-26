/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001213bc */

void _raw_detach(int *param_1)

{
  int iVar1;
  
  iVar1 = param_1[2];
  if (param_1[0xe] != 0) {
    _rtfree(param_1[0xe]);
  }
  *(undefined4 *)(iVar1 + 8) = 0;
  _sofree(iVar1);
  *(int *)(*param_1 + 4) = param_1[1];
  *(int *)param_1[1] = *param_1;
  if (param_1[0xd] != 0) {
    _m_freem(param_1[0xd] & 0xffffff80);
  }
  if (_ip_mrouter == iVar1) {
    _ip_mrouter_done();
  }
  if ((short)param_1[0xb] == 2) {
    _ip_freemoptions(param_1[0x14]);
  }
  _m_freem((uint)param_1 & 0xffffff80);
  return;
}

