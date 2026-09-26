
uint _accept(void)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  char cVar6;
  char cVar7;
  char cVar8;
  char cVar9;
  byte bVar10;
  int iStack_8;
  
  puVar1 = *(undefined4 **)(dword_40B57D4 + 0x24);
  if (puVar1[1] != 0) {
    uVar3 = _copyinmsg(puVar1[2],&iStack_8,4);
    *(char *)(dword_40B57D4 + 100) = (char)uVar3;
    if (*(char *)(dword_40B57D4 + 100) != '\0') {
      return uVar3;
    }
    iVar4 = _useracc(puVar1[1],iStack_8,0);
    if (iVar4 == 0) {
      *(undefined *)(dword_40B57D4 + 100) = 0xe;
      return 0;
    }
  }
  iVar4 = _getsock(*puVar1);
  if (iVar4 == 0) {
    return 0;
  }
  cVar6 = '\0';
  iVar4 = *(int *)(iVar4 + 0x16);
  if ((*(byte *)(iVar4 + 3) & 2) == 0) {
    *(undefined *)(dword_40B57D4 + 100) = 0x16;
    return 0;
  }
  if ((*(byte *)(iVar4 + 6) & 1) == 0) {
    if (*(sword *)(iVar4 + 0x1e) == 0) {
      if (*(sword *)(iVar4 + 0x50) != 0) goto loc_4014B70;
      while ((*(byte *)(iVar4 + 7) & 0x20) == 0) {
        _sleep(iVar4 + 0x4e,0x1a);
        if ((*(sword *)(iVar4 + 0x1e) != 0) || (*(sword *)(iVar4 + 0x50) != 0)) goto loc_4014B6A;
      }
      *(undefined2 *)(iVar4 + 0x50) = 0x35;
    }
  }
  else if (*(sword *)(iVar4 + 0x1e) == 0) {
    *(undefined *)(dword_40B57D4 + 100) = 0x23;
    return 0;
  }
loc_4014B6A:
  if (*(sword *)(iVar4 + 0x50) == 0) {
    iVar5 = _falloc();
    if (iVar5 == 0) {
      *(undefined4 *)(*(int *)(_active_u + 0x146) + *(int *)(dword_40B57D4 + 0x5c) * 4) = 0;
      return (uint)(byte)(cVar6 << 4 | 4);
    }
    uVar2 = *(undefined4 *)(iVar4 + 0x1a);
    iVar4 = _soqremque(uVar2,1);
    if (iVar4 != 0) {
      *(undefined2 *)(iVar5 + 0xc) = 2;
      *(undefined4 *)(iVar5 + 8) = 3;
      *(undefined **)(iVar5 + 0x12) = _socketops;
      *(undefined4 *)(iVar5 + 0x16) = uVar2;
      *(int *)(*(int *)(_active_u + 0x146) + *(int *)(dword_40B57D4 + 0x5c) * 4) = iVar5;
      uVar3 = _m_get(1,8);
      _soaccept(uVar2,uVar3);
      if (puVar1[1] != 0) {
        if (*(sword *)(uVar3 + 8) < iStack_8) {
          iStack_8 = (int)*(sword *)(uVar3 + 8);
        }
        cVar6 = CARRY4(*(uint *)(uVar3 + 4),uVar3);
        _copyoutmsg(*(uint *)(uVar3 + 4) + uVar3,puVar1[1],iStack_8);
        _copyoutmsg(&iStack_8,puVar1[2],4);
      }
      cVar7 = (int)uVar3 < 0;
      cVar8 = uVar3 == 0;
      cVar9 = '\0';
      bVar10 = 0;
      _m_freem(uVar3);
      return (uint)(byte)(cVar6 << 4 | cVar7 << 3 | cVar8 << 2 | cVar9 << 1 | bVar10);
    }
                    /* WARNING: Subroutine does not return */
    _panic(&aAccept);
  }
loc_4014B70:
  *(undefined *)(dword_40B57D4 + 100) = *(undefined *)(iVar4 + 0x51);
  *(undefined2 *)(iVar4 + 0x50) = 0;
  return (uint)(byte)(cVar6 << 4 | 4);
}

