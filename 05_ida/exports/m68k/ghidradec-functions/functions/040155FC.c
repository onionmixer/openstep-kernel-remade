
void _setsockopt(void)

{
  undefined4 *puVar1;
  int iVar2;
  undefined uVar3;
  int iVar4;
  
  puVar1 = *(undefined4 **)(dword_40B57D4 + 0x24);
  iVar4 = 0;
  iVar2 = _getsock(*puVar1);
  if (iVar2 != 0) {
    if ((int)puVar1[4] < 0x71) {
      if (puVar1[3] != 0) {
        iVar4 = _m_get(1,10);
        if (iVar4 == 0) {
          *(undefined *)(dword_40B57D4 + 100) = 0x37;
          return;
        }
        uVar3 = _copyinmsg(puVar1[3],*(int *)(iVar4 + 4) + iVar4,puVar1[4]);
        *(undefined *)(dword_40B57D4 + 100) = uVar3;
        if (*(char *)(dword_40B57D4 + 100) != '\0') {
          _m_free(iVar4);
          return;
        }
        *(undefined2 *)(iVar4 + 8) = *(undefined2 *)((int)puVar1 + 0x12);
      }
      uVar3 = _sosetopt(*(undefined4 *)(iVar2 + 0x16),puVar1[1],puVar1[2],iVar4);
      *(undefined *)(dword_40B57D4 + 100) = uVar3;
    }
    else {
      *(undefined *)(dword_40B57D4 + 100) = 0x16;
    }
  }
  return;
}

