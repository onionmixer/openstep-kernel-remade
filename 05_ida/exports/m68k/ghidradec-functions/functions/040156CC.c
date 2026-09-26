
void _getsockopt(void)

{
  undefined4 *puVar1;
  int iVar2;
  undefined uVar3;
  int iStack_c;
  int iStack_8;
  
  puVar1 = *(undefined4 **)(dword_40B57D4 + 0x24);
  iStack_c = 0;
  iVar2 = _getsock(*puVar1);
  if (iVar2 != 0) {
    if (puVar1[3] == 0) {
      iStack_8 = 0;
    }
    else {
      uVar3 = _copyinmsg(puVar1[4],&iStack_8,4);
      *(undefined *)(dword_40B57D4 + 100) = uVar3;
      if (*(char *)(dword_40B57D4 + 100) != '\0') {
        return;
      }
    }
    uVar3 = _sogetopt(*(undefined4 *)(iVar2 + 0x16),puVar1[1],puVar1[2],&iStack_c);
    *(undefined *)(dword_40B57D4 + 100) = uVar3;
    if (((*(char *)(dword_40B57D4 + 100) == '\0') && (puVar1[3] != 0)) && (iStack_8 != 0)) {
      if (iStack_c == 0) {
        return;
      }
      if (*(sword *)(iStack_c + 8) < iStack_8) {
        iStack_8 = (int)*(sword *)(iStack_c + 8);
      }
      uVar3 = _copyoutmsg(*(int *)(iStack_c + 4) + iStack_c,puVar1[3],iStack_8);
      *(undefined *)(dword_40B57D4 + 100) = uVar3;
      if (*(char *)(dword_40B57D4 + 100) == '\0') {
        uVar3 = _copyoutmsg(&iStack_8,puVar1[4],4);
        *(undefined *)(dword_40B57D4 + 100) = uVar3;
      }
    }
    if (iStack_c != 0) {
      _m_free(iStack_c);
    }
  }
  return;
}

