
void _cinit(void)

{
  int iVar1;
  int iVar2;
  uint *puVar3;
  uint *puVar4;
  
  iVar2 = _nclist * 0x40;
  iVar1 = _cfree + -0x40;
  puVar4 = (uint *)(_cfree + 0x3fU & 0xffffffc0);
  while (puVar3 = puVar4, puVar3 < (uint)(iVar1 + iVar2)) {
    *puVar3 = (uint)_cfreelist;
    _cfreecount = _cfreecount + 0x34;
    _cfreelist = puVar3;
    puVar4 = puVar3 + 0x10;
  }
  return;
}

