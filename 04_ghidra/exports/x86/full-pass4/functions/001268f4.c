/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001268f4 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void _ip_drain(void)

{
  int *piVar1;
  int *piVar2;
  int *piVar3;
  
  piVar2 = _ipq;
  while ((int **)piVar2 != &_ipq) {
    _DAT_001eaacc = _DAT_001eaacc + 1;
    piVar3 = (int *)piVar2[3];
    _ipq = piVar2;
    while (piVar3 != piVar2) {
      piVar1 = (int *)piVar3[3];
      _ip_deq(piVar3);
      _m_freem((uint)piVar3 & 0xffffff80);
      piVar3 = piVar1;
    }
    *(int *)(*piVar2 + 4) = piVar2[1];
    *(int *)piVar2[1] = *piVar2;
    _m_free((uint)piVar2 & 0xffffff80);
    piVar2 = _ipq;
  }
  _ipq = piVar2;
  return;
}

