/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x00126854 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void _ip_slowtimo(void)

{
  int *piVar1;
  int *piVar2;
  int *piVar3;
  undefined4 uVar4;
  undefined4 *puVar5;
  
  uVar4 = _splnet();
  puVar5 = _ipq;
  if (_ipq != (undefined4 *)0x0) {
    while ((undefined4 **)puVar5 != &_ipq) {
      *(char *)(puVar5 + 2) = *(char *)(puVar5 + 2) + -1;
      puVar5 = (undefined4 *)*puVar5;
      if (*(char *)(puVar5[1] + 8) == '\0') {
        _DAT_001eaad0 = _DAT_001eaad0 + 1;
        piVar1 = (int *)puVar5[1];
        piVar3 = (int *)piVar1[3];
        while (piVar3 != piVar1) {
          piVar2 = (int *)piVar3[3];
          _ip_deq(piVar3);
          _m_freem((uint)piVar3 & 0xffffff80);
          piVar3 = piVar2;
        }
        *(int *)(*piVar1 + 4) = piVar1[1];
        *(int *)piVar1[1] = *piVar1;
        _m_free((uint)piVar1 & 0xffffff80);
      }
    }
  }
  _splx(uVar4);
  return;
}

