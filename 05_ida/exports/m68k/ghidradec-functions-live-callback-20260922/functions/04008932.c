
void _sigvec(void)

{
  int iVar1;
  int *piVar2;
  uint uVar3;
  undefined uVar4;
  int iStack_10;
  undefined4 uStack_c;
  uint uStack_8;
  
  piVar2 = *(int **)(dword_40B57D4 + 0x24);
  iVar1 = *piVar2;
  if (((iVar1 - 1U < 0x1f) && (iVar1 != 9)) && (iVar1 != 0x11)) {
    if (piVar2[2] != 0) {
      iStack_10 = *(int *)((int)_active_u + iVar1 * 4 + 0x2a);
      uStack_c = *(undefined4 *)((int)_active_u + iVar1 * 4 + 0xae);
      uVar3 = 1 << (iVar1 - 1U & 0x3f);
      uStack_8 = (uint)((uVar3 & *(uint *)((int)_active_u + 0x132)) != 0);
      if ((uVar3 & *(uint *)((int)_active_u + 0x136)) != 0) {
        uStack_8 = uStack_8 | 2;
      }
      uVar4 = _copyoutmsg(&iStack_10,piVar2[2],0xc);
      *(undefined *)(dword_40B57D4 + 100) = uVar4;
      if (*(char *)(dword_40B57D4 + 100) != '\0') {
        return;
      }
    }
    if (piVar2[1] != 0) {
      uVar4 = _copyinmsg(piVar2[1],&iStack_10,0xc);
      *(undefined *)(dword_40B57D4 + 100) = uVar4;
      if (*(char *)(dword_40B57D4 + 100) == '\0') {
        if (((iVar1 == 0x13) && (iStack_10 == 1)) && ((*(byte *)(*_active_u + 0x16) & 0x40) == 0)) {
          *(undefined *)(dword_40B57D4 + 100) = 0x16;
        }
        else {
          _setsigvec(iVar1,&iStack_10);
        }
      }
    }
  }
  else {
    *(undefined *)(dword_40B57D4 + 100) = 0x16;
  }
  return;
}

