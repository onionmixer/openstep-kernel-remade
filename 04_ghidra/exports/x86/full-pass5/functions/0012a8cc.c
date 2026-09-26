/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0012a8cc */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void _tcp_fasttimo(void)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 uVar3;
  
  uVar3 = _splnet();
  puVar2 = _tcb;
  if (_tcb != (undefined4 *)0x0) {
    for (; (undefined4 **)puVar2 != &_tcb; puVar2 = (undefined4 *)*puVar2) {
      iVar1 = puVar2[8];
      if ((iVar1 != 0) && ((*(byte *)(iVar1 + 0x1b) & 2) != 0)) {
        *(byte *)(iVar1 + 0x1b) = *(byte *)(iVar1 + 0x1b) & 0xfd | 1;
        _DAT_001eed90 = _DAT_001eed90 + 1;
        _tcp_output(iVar1);
      }
    }
  }
  _splx(uVar3);
  return;
}

