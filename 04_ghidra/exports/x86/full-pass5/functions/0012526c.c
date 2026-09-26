/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0012526c */

void _in_pcbdetach(int *param_1)

{
  int iVar1;
  
  iVar1 = param_1[7];
  *(undefined4 *)(iVar1 + 8) = 0;
  _sofree(iVar1);
  if (param_1[0xe] != 0) {
    _m_free(param_1[0xe]);
  }
  if (param_1[9] != 0) {
    _rtfree(param_1[9]);
  }
  _ip_freemoptions(param_1[0xf]);
  *(int *)(*param_1 + 4) = param_1[1];
  *(int *)param_1[1] = *param_1;
  _kfree(param_1,0x40);
  return;
}

