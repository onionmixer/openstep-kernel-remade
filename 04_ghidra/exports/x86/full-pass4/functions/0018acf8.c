/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0018acf8 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0018acf8(void)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  
  iVar1 = _getlastaddr();
  iVar2 = 0;
  if (0 < _DAT_00011154) {
    iVar4 = 0;
    do {
      iVar1 = iVar1 + *(int *)(iVar4 + 0x1116c);
      iVar4 = iVar4 + 8;
      iVar2 = iVar2 + 1;
    } while (iVar2 < _DAT_00011154);
  }
  iVar2 = _extmem;
  if (DAT_001e760c != 0) {
    iVar2 = DAT_001e760c;
  }
  _mem_size = iVar2 << 10;
  uVar3 = ~_page_mask;
  DAT_001e7610 = _DAT_00011138 + _page_mask & uVar3;
  DAT_001e7614 = _cnvmem << 10 & uVar3;
  DAT_001e7604 = _page_mask + iVar1 & uVar3;
  DAT_001e7608 = iVar2 << 10 & uVar3;
  return;
}

