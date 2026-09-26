
undefined4 _sigsetmask(void)

{
  int iVar1;
  undefined4 *puVar2;
  uint uVar3;
  
  puVar2 = (undefined4 *)(dword_40B57D4 + 0x24);
  iVar1 = *_active_u;
  *(undefined4 *)(dword_40B57D4 + 0x5c) = *(undefined4 *)(iVar1 + 0x1c);
  if ((*(byte *)(*_active_u + 0x16) & 0x40) == 0) {
    uVar3 = *(uint *)*puVar2 & 0xfffafeff;
  }
  else {
    uVar3 = *(uint *)*puVar2 & 0xfffefeff;
  }
  *(uint *)(iVar1 + 0x1c) = uVar3;
  return CONCAT22((sword)(uVar3 >> 0x10),(word)(byte)(((int)uVar3 < 0) << 3 | (uVar3 == 0) << 2));
}

