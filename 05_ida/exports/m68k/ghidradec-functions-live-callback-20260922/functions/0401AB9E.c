
void __utime(void)

{
  undefined4 *puVar1;
  int iVar2;
  undefined uVar4;
  int iVar3;
  undefined4 uStack_4e;
  undefined4 uStack_4a;
  undefined4 uStack_46;
  undefined4 uStack_42;
  undefined auStack_3e [28];
  undefined4 uStack_22;
  undefined4 uStack_1e;
  undefined4 uStack_1a;
  undefined4 uStack_16;
  
  puVar1 = *(undefined4 **)(dword_40B57D4 + 0x24);
  iVar2 = _get_posix_proc((int)*(sword *)(*_active_u + 0x30));
  _getthetime(&uStack_46);
  _vattr_null(auStack_3e);
  if (((*(byte *)(*_active_u + 0x16) & 0x40) == 0) || (puVar1[1] != 0)) {
    uVar4 = _copyinmsg(puVar1[1],&uStack_4e,8);
    *(undefined *)(dword_40B57D4 + 100) = uVar4;
    if (*(char *)(dword_40B57D4 + 100) != '\0') {
      return;
    }
    uStack_22 = uStack_4e;
    uStack_1a = uStack_4a;
    uStack_16 = 0;
  }
  else {
    uStack_1a = uStack_46;
    uStack_22 = uStack_46;
    uStack_16 = uStack_42;
    *(byte *)(iVar2 + 0x16) = *(byte *)(iVar2 + 0x16) | 0x80;
  }
  uStack_1e = uStack_16;
  iVar3 = _namesetattr(*puVar1,1,auStack_3e);
  *(byte *)(iVar2 + 0x16) = *(byte *)(iVar2 + 0x16) & 0x7f;
  if ((((*(byte *)(*_active_u + 0x16) & 0x40) != 0) && (iVar3 == 1)) && (puVar1[1] == 0)) {
    iVar3 = 0xd;
  }
  *(char *)(dword_40B57D4 + 100) = (char)iVar3;
  return;
}

