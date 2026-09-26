
void _connect(void)

{
  undefined4 *puVar1;
  int iVar2;
  undefined uVar4;
  int iVar3;
  undefined4 uStack_8;
  
  puVar1 = *(undefined4 **)(dword_40B57D4 + 0x24);
  iVar2 = _getsock(*puVar1);
  if (iVar2 == 0) {
    return;
  }
  iVar2 = *(int *)(iVar2 + 0x16);
  if ((*(word *)(iVar2 + 6) & 0x104) == 0x104) {
    *(undefined *)(dword_40B57D4 + 100) = 0x25;
    return;
  }
  uVar4 = _sockargs(&uStack_8,puVar1[1],puVar1[2],8);
  *(undefined *)(dword_40B57D4 + 100) = uVar4;
  if (*(char *)(dword_40B57D4 + 100) != '\0') {
    return;
  }
  uVar4 = _soconnect(iVar2,uStack_8);
  *(undefined *)(dword_40B57D4 + 100) = uVar4;
  if (*(char *)(dword_40B57D4 + 100) == '\0') {
    if ((*(word *)(iVar2 + 6) & 0x104) == 0x104) {
      *(undefined *)(dword_40B57D4 + 100) = 0x24;
      goto loc_4014DBC;
    }
    iVar3 = _setjmp(dword_40B57D4 + 0x28);
    if (iVar3 == 0) {
      while (((*(byte *)(iVar2 + 7) & 4) != 0 && (*(sword *)(iVar2 + 0x50) == 0))) {
        _sleep(iVar2 + 0x4e,0x1a);
      }
      *(undefined *)(dword_40B57D4 + 100) = *(undefined *)(iVar2 + 0x51);
      *(undefined2 *)(iVar2 + 0x50) = 0;
    }
    else if (*(char *)(dword_40B57D4 + 100) == '\0') {
      *(undefined *)(dword_40B57D4 + 100) = 4;
    }
  }
  *(word *)(iVar2 + 6) = *(word *)(iVar2 + 6) & 0xfffb;
loc_4014DBC:
  _m_freem(uStack_8);
  return;
}

