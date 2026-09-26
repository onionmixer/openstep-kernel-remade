
int sub_4036B74(int param_1,int param_2)

{
  int iVar1;
  word wVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  undefined *puVar6;
  int iStack_8;
  
  iVar5 = 0;
  while ((byte_40AF2D6 & 1) != 0) {
    byte_40AF2D6 = byte_40AF2D6 | 2;
    _sleep(&byte_40AF2D6,10);
  }
  byte_40AF2D6 = 1;
  iVar4 = param_2;
  if (*(int *)(param_2 + 0x46) == *(int *)(param_1 + 0x46)) {
    iVar5 = 0x16;
  }
  else if (*(int *)(param_2 + 0x46) != 2) {
    do {
      iVar3 = 0;
      if ((((*(word *)(iVar4 + 0x62) & 0xf000) != 0x4000) || (*(sword *)(iVar4 + 100) == 0)) ||
         (*(uint *)(iVar4 + 0x6e) < 0x18)) {
        puVar6 = aBadSizeUnlinke;
loc_4036C34:
        sub_4036AAC(iVar4,puVar6,0);
        iVar5 = 0x14;
        goto loc_4036CC0;
      }
      iVar3 = _blkatoff(iVar4,0,&iStack_8);
      if (iVar3 == 0) break;
      if ((*(sword *)(iStack_8 + 0x12) != 2) || (*(sword *)(iStack_8 + 0x14) != 0x2e2e)) {
        puVar6 = aMangledEntry;
        goto loc_4036C34;
      }
      iVar1 = *(int *)(iStack_8 + 0xc);
      if (iVar1 == *(int *)(param_1 + 0x46)) {
        iVar5 = 0x16;
        goto loc_4036CC0;
      }
      if (iVar1 == 2) goto loc_4036CC0;
      _brelse(iVar3);
      iVar3 = 0;
      if (param_2 == iVar4) {
        wVar2 = *(word *)(param_2 + 0x42);
        *(word *)(param_2 + 0x42) = wVar2 & 0xfffe;
        if ((wVar2 & 0x10) != 0) {
          *(word *)(param_2 + 0x42) = wVar2 & 0xffee;
          _wakeup(param_2);
        }
      }
      else {
        _iput(iVar4);
      }
      iVar4 = _iget((int)*(sword *)(iVar4 + 0x44),*(undefined4 *)(iVar4 + 0x4e),iVar1);
    } while (iVar4 != 0);
    iVar5 = (int)*(char *)(dword_40B57D4 + 100);
loc_4036CC0:
    if (iVar3 != 0) {
      _brelse(iVar3);
    }
  }
  if ((byte_40AF2D6 & 2) != 0) {
    _wakeup(&byte_40AF2D6);
  }
  byte_40AF2D6 = 0;
  if ((iVar4 != 0) && (param_2 != iVar4)) {
    _iput(iVar4);
    while ((*(word *)(param_2 + 0x42) & 1) != 0) {
      *(word *)(param_2 + 0x42) = *(word *)(param_2 + 0x42) | 0x10;
      _sleep(param_2,10);
    }
    *(word *)(param_2 + 0x42) = *(word *)(param_2 + 0x42) | 1;
    if ((iVar5 == 0) && (*(sword *)(param_2 + 100) == 0)) {
      iVar5 = 2;
    }
  }
  return iVar5;
}
