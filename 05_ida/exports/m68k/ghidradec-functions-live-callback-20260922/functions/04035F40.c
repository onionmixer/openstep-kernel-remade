
int sub_4035F40(int param_1,int param_2,int param_3)

{
  word wVar1;
  int iVar2;
  int iVar3;
  int iStack_8;
  
  iVar3 = 0;
  while ((*(word *)(param_1 + 0x42) & 1) != 0) {
    *(word *)(param_1 + 0x42) = *(word *)(param_1 + 0x42) | 0x10;
    _sleep(param_1,10);
  }
  wVar1 = *(word *)(param_1 + 0x42);
  *(word *)(param_1 + 0x42) = wVar1 | 1;
  if ((*(sword *)(param_1 + 100) == 0) || (*(uint *)(param_1 + 0x6e) < 0x18)) {
    *(word *)(param_1 + 0x42) = wVar1 & 0xfffe;
    if ((wVar1 & 0x10) != 0) {
      *(word *)(param_1 + 0x42) = wVar1 & 0xffee;
      _wakeup(param_1);
    }
loc_403616A:
    iVar3 = 0;
  }
  else {
    iVar2 = _blkatoff(param_1,0,&iStack_8);
    if (iVar2 == 0) {
      iVar3 = (int)*(char *)(dword_40B57D4 + 100);
    }
    else if (*(int *)(iStack_8 + 0xc) != *(int *)(param_3 + 0x46)) {
      if ((*(sword *)(iStack_8 + 0x12) == 2) && (*(sword *)(iStack_8 + 0x14) == 0x2e2e)) {
        *(sword *)(param_3 + 100) = *(sword *)(param_3 + 100) + 1;
        *(word *)(param_3 + 0x42) = *(word *)(param_3 + 0x42) | 0x40;
        _iupdat(param_3,1);
        _dnlc_remove(param_1 + 0xc,&asc_40A6712);
        *(undefined4 *)(iStack_8 + 0xc) = *(undefined4 *)(param_3 + 0x46);
        _dnlc_enter(param_1 + 0xc,&asc_40A6712,param_3 + 0xc,0);
        _bwrite(iVar2);
        iVar2 = 0;
        if (*(char *)(dword_40B57D4 + 100) == '\0') {
          wVar1 = *(word *)(param_1 + 0x42);
          *(word *)(param_1 + 0x42) = wVar1 & 0xfffe;
          if ((wVar1 & 0x10) != 0) {
            *(word *)(param_1 + 0x42) = wVar1 & 0xffee;
            _wakeup(param_1);
          }
          if (param_2 != 0) {
            wVar1 = *(word *)(param_3 + 0x42);
            *(word *)(param_3 + 0x42) = wVar1 & 0xfffe;
            if ((wVar1 & 0x10) != 0) {
              *(word *)(param_3 + 0x42) = wVar1 & 0xffee;
              _wakeup(param_3);
            }
            while ((*(word *)(param_2 + 0x42) & 1) != 0) {
              *(word *)(param_2 + 0x42) = *(word *)(param_2 + 0x42) | 0x10;
              _sleep(param_2,10);
            }
            *(word *)(param_2 + 0x42) = *(word *)(param_2 + 0x42) | 1;
            if (*(sword *)(param_2 + 100) != 0) {
              *(sword *)(param_2 + 100) = *(sword *)(param_2 + 100) + -1;
              *(word *)(param_2 + 0x42) = *(word *)(param_2 + 0x42) | 0x40;
              _iupdat(param_2,1);
            }
            wVar1 = *(word *)(param_2 + 0x42);
            *(word *)(param_2 + 0x42) = wVar1 & 0xfffe;
            if ((wVar1 & 0x10) != 0) {
              *(word *)(param_2 + 0x42) = wVar1 & 0xffee;
              _wakeup(param_2);
            }
            while ((*(word *)(param_3 + 0x42) & 1) != 0) {
              *(word *)(param_3 + 0x42) = *(word *)(param_3 + 0x42) | 0x10;
              _sleep(param_3,10);
            }
            *(word *)(param_3 + 0x42) = *(word *)(param_3 + 0x42) | 1;
          }
          goto loc_403616A;
        }
        iVar3 = (int)*(char *)(dword_40B57D4 + 100);
      }
      else {
        sub_4036AAC(param_1,aMangledEntry,0);
        iVar3 = 0x16;
      }
    }
    if (iVar2 != 0) {
      _brelse(iVar2);
    }
    wVar1 = *(word *)(param_1 + 0x42);
    *(word *)(param_1 + 0x42) = wVar1 & 0xfffe;
    if ((wVar1 & 0x10) != 0) {
      *(word *)(param_1 + 0x42) = wVar1 & 0xffee;
      _wakeup(param_1);
    }
  }
  return iVar3;
}

