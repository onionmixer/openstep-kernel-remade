/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001267c4 */

void _ip_freef(int *param_1)

{
  int *piVar1;
  int *piVar2;
  
  piVar2 = (int *)param_1[3];
  while (piVar2 != param_1) {
    piVar1 = (int *)piVar2[3];
    _ip_deq(piVar2);
    _m_freem((uint)piVar2 & 0xffffff80);
    piVar2 = piVar1;
  }
  *(int *)(*param_1 + 4) = param_1[1];
  *(int *)param_1[1] = *param_1;
  _m_free((uint)param_1 & 0xffffff80);
  return;
}

