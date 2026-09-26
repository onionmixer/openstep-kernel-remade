
void _nfs_getfh(void)

{
  uint uVar1;
  uint *puVar2;
  bool bVar3;
  int iVar4;
  undefined uVar5;
  undefined4 uStack_30;
  int iStack_2c;
  int iStack_28;
  undefined auStack_24 [32];
  
  puVar2 = *(uint **)(dword_40B57D4 + 0x24);
  bVar3 = false;
  iVar4 = _suser();
  if (iVar4 == 0) {
    *(undefined *)(dword_40B57D4 + 100) = 1;
    return;
  }
  uVar1 = *puVar2;
  if (uVar1 < 0x100) {
    bVar3 = true;
    iVar4 = _getf(uVar1);
    if ((iVar4 == 0) || (*(undefined **)(iVar4 + 0x12) != _vnodefops)) {
      *(undefined *)(dword_40B57D4 + 100) = 0x16;
      return;
    }
    iStack_2c = *(int *)(iVar4 + 0x16);
    iStack_28 = 0;
  }
  else {
    uVar5 = _lookupname(uVar1,0,1,&iStack_28,&iStack_2c);
    *(undefined *)(dword_40B57D4 + 100) = uVar5;
    if (*(char *)(dword_40B57D4 + 100) == '\x11') {
      uVar5 = _lookupname(*puVar2,0,1,0,&iStack_2c);
      *(undefined *)(dword_40B57D4 + 100) = uVar5;
      iStack_28 = 0;
    }
    if (*(char *)(dword_40B57D4 + 100) != '\0') {
      return;
    }
    if (iStack_2c == 0) {
      if (iStack_28 != 0) {
        _vn_rele(iStack_28);
      }
      *(undefined *)(dword_40B57D4 + 100) = 2;
    }
    if (*(char *)(dword_40B57D4 + 100) != '\0') {
      return;
    }
  }
  iVar4 = _findexivp(&uStack_30,iStack_28,iStack_2c);
  if (iVar4 == 0) {
    iVar4 = _makefh(auStack_24,iStack_2c,uStack_30);
    if (iVar4 == 0) {
      iVar4 = _copyoutmsg(auStack_24,puVar2[1],0x20);
    }
  }
  if ((!bVar3) && (_vn_rele(iStack_2c), iStack_28 != 0)) {
    _vn_rele(iStack_28);
  }
  *(char *)(dword_40B57D4 + 100) = (char)iVar4;
  return;
}
