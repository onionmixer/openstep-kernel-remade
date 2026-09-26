
void _getsockname(void)

{
  undefined4 *puVar1;
  int iVar2;
  undefined uVar4;
  int iVar3;
  int iStack_8;
  
  puVar1 = *(undefined4 **)(dword_40B57D4 + 0x24);
  iVar2 = _getsock(*puVar1);
  if (iVar2 != 0) {
    uVar4 = _copyinmsg(puVar1[2],&iStack_8,4);
    *(undefined *)(dword_40B57D4 + 100) = uVar4;
    if (*(char *)(dword_40B57D4 + 100) == '\0') {
      iVar2 = *(int *)(iVar2 + 0x16);
      iVar3 = _m_getclr(1,8);
      if (iVar3 == 0) {
        *(undefined *)(dword_40B57D4 + 100) = 0x37;
      }
      else {
        uVar4 = (**(code **)(*(int *)(iVar2 + 0xc) + 0x1a))(iVar2,0xf,0,iVar3,0);
        *(undefined *)(dword_40B57D4 + 100) = uVar4;
        if (*(char *)(dword_40B57D4 + 100) == '\0') {
          if (*(sword *)(iVar3 + 8) < iStack_8) {
            iStack_8 = (int)*(sword *)(iVar3 + 8);
          }
          uVar4 = _copyoutmsg(*(int *)(iVar3 + 4) + iVar3,puVar1[1],iStack_8);
          *(undefined *)(dword_40B57D4 + 100) = uVar4;
          if (*(char *)(dword_40B57D4 + 100) == '\0') {
            uVar4 = _copyoutmsg(&iStack_8,puVar1[2],4);
            *(undefined *)(dword_40B57D4 + 100) = uVar4;
          }
        }
        _m_freem(iVar3);
      }
    }
  }
  return;
}

