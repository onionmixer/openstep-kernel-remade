/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x00103030 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void _cinit(void)

{
  int iVar1;
  uint *puVar2;
  uint *puVar3;
  int iVar4;
  
  iVar4 = _nclist * 0x40;
  iVar1 = _cfree + -0x40;
  puVar3 = (uint *)(_cfree + 0x3fU & 0xffffffc0);
  while (puVar2 = puVar3, puVar2 < (uint)(iVar1 + iVar4)) {
    *puVar2 = (uint)_cfreelist;
    __cfreecount = __cfreecount + 0x34;
    _cfreelist = puVar2;
    puVar3 = puVar2 + 0x10;
  }
  return;
}

