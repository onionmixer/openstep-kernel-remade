
void _utimes(void)

{
  undefined4 *puVar1;
  undefined uVar2;
  undefined auStack_4e [28];
  undefined4 uStack_32;
  undefined4 uStack_2e;
  undefined4 uStack_2a;
  undefined4 uStack_26;
  undefined4 uStack_14;
  undefined4 uStack_10;
  undefined4 uStack_c;
  undefined4 uStack_8;
  
  puVar1 = *(undefined4 **)(dword_40B57D4 + 0x24);
  uVar2 = _copyinmsg(puVar1[1],&uStack_14,0x10);
  *(undefined *)(dword_40B57D4 + 100) = uVar2;
  if (*(char *)(dword_40B57D4 + 100) == '\0') {
    _vattr_null(auStack_4e);
    uStack_32 = uStack_14;
    uStack_2e = uStack_10;
    uStack_2a = uStack_c;
    uStack_26 = uStack_8;
    uVar2 = _namesetattr(*puVar1,1,auStack_4e);
    *(undefined *)(dword_40B57D4 + 100) = uVar2;
  }
  return;
}

