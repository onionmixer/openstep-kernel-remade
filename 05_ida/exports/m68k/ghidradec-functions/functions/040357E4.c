
/* WARNING: Type propagation algorithm not settling */

int _direnter(int param_1,char *param_2,int param_3,int param_4,int param_5,undefined4 param_6,
             int *param_7)

{
  word wVar1;
  sword sVar2;
  char cVar3;
  int *piVar4;
  int *piVar5;
  int iVar6;
  int iVar7;
  char *pcVar8;
  int aiStack_1c [4];
  int iStack_c;
  
  piVar5 = param_7;
  iVar7 = 0;
  cVar3 = *param_2;
  pcVar8 = param_2;
  while (cVar3 != '\0') {
    if (*pcVar8 == '/') {
      return 0xd;
    }
    pcVar8 = pcVar8 + 1;
    iVar7 = iVar7 + 1;
    cVar3 = *pcVar8;
  }
  if (iVar7 == 0) {
                    /* WARNING: Subroutine does not return */
    _panic(aDirenter);
  }
  if ((*param_2 != '.') || ((iVar7 != 1 && ((iVar7 != 2 || (param_2[1] != '.')))))) {
    aiStack_1c[1] = 0;
    iStack_c = 0;
    if (param_3 != 0) {
      while ((*(byte *)(param_5 + 0x43) & 1) != 0) {
        *(word *)(param_5 + 0x42) = *(word *)(param_5 + 0x42) | 0x10;
        _sleep(param_5,10);
      }
      wVar1 = *(word *)(param_5 + 0x42);
      *(word *)(param_5 + 0x42) = wVar1 | 1;
      sVar2 = *(sword *)(param_5 + 100);
      if (sVar2 == 0) {
        *(word *)(param_5 + 0x42) = wVar1 & 0xfffe;
        if ((wVar1 & 0x10) != 0) {
          *(word *)(param_5 + 0x42) = wVar1 & 0xffee;
          _wakeup(param_5);
        }
        return 2;
      }
      if (sVar2 == 0x7fff) {
        *(word *)(param_5 + 0x42) = wVar1 & 0xfffe;
        if ((wVar1 & 0x10) != 0) {
          *(word *)(param_5 + 0x42) = wVar1 & 0xffee;
          _wakeup(param_5);
        }
        return 0x1f;
      }
      *(sword *)(param_5 + 100) = sVar2 + 1;
      *(word *)(param_5 + 0x42) = *(word *)(param_5 + 0x42) | 0x40;
      _iupdat(param_5,1);
      wVar1 = *(word *)(param_5 + 0x42);
      *(word *)(param_5 + 0x42) = wVar1 & 0xfffe;
      if ((wVar1 & 0x10) != 0) {
        *(word *)(param_5 + 0x42) = wVar1 & 0xffee;
        _wakeup(param_5);
      }
    }
    while ((*(word *)(param_1 + 0x42) & 1) != 0) {
      *(word *)(param_1 + 0x42) = *(word *)(param_1 + 0x42) | 0x10;
      _sleep(param_1,10);
    }
    *(word *)(param_1 + 0x42) = *(word *)(param_1 + 0x42) | 1;
    if ((*(word *)(param_1 + 0x62) & 0xf000) == 0x4000) {
      if (*(sword *)(param_1 + 100) == 0) {
        iVar6 = 2;
      }
      else {
        iVar6 = _iaccess(param_1,0x40);
        if ((iVar6 == 0) &&
           ((((param_3 != 2 || ((*(word *)(param_5 + 0x62) & 0xf000) != 0x4000)) ||
             (param_1 == param_4)) ||
            ((iVar6 = _iaccess(param_5,0x80), iVar6 == 0 &&
             (iVar6 = sub_4036B74(param_5,param_1), iVar6 == 0)))))) {
          piVar4 = aiStack_1c + 1;
          iVar6 = sub_4035BA6(param_1,param_2,iVar7,piVar4,aiStack_1c);
          if (iVar6 == 0) {
            if (aiStack_1c[0] == 0) {
              iVar6 = _iaccess(param_1,0x80);
              if ((iVar6 == 0) &&
                 ((param_3 != 0 || (iVar6 = sub_403643A(param_1,&param_5,param_6), iVar6 == 0)))) {
                iVar6 = _diraddentry(param_1,param_2,iVar7,piVar4,param_5,param_4);
                if (iVar6 == 0) {
                  if (piVar5 == (int *)0x0) {
                    if (param_3 == 0) {
                      _irele(param_5);
                    }
                  }
                  else {
                    while ((*(byte *)(param_5 + 0x43) & 1) != 0) {
                      *(word *)(param_5 + 0x42) = *(word *)(param_5 + 0x42) | 0x10;
                      _sleep(param_5,10);
                    }
                    *(word *)(param_5 + 0x42) = *(word *)(param_5 + 0x42) | 1;
                    *piVar5 = param_5;
                  }
                }
                else if (param_3 == 0) {
                  if ((*(word *)(param_5 + 0x62) & 0xf000) == 0x4000) {
                    *(sword *)(param_1 + 100) = *(sword *)(param_1 + 100) + -1;
                  }
                  *(undefined2 *)(param_5 + 100) = 0;
                  *(word *)(param_5 + 0x42) = *(word *)(param_5 + 0x42) | 0x40;
                  _irele(param_5);
                  param_5 = 0;
                }
              }
            }
            else if (param_3 == 1) {
              _iput(aiStack_1c[0]);
              iVar6 = 0x11;
            }
            else if (param_3 == 0) {
              if (piVar5 == (int *)0x0) {
                _iput(aiStack_1c[0]);
              }
              else {
                *piVar5 = aiStack_1c[0];
                iVar6 = 0x11;
              }
            }
            else if (param_3 == 2) {
              iVar6 = sub_4035DAE(param_4,param_5,param_1,param_2,iVar7,aiStack_1c[0],piVar4);
              _iput(aiStack_1c[0]);
              if (*(sword *)(aiStack_1c[0] + 100) == 0) {
                _vnode_uncache(aiStack_1c[0] + 0xc);
              }
            }
          }
        }
      }
    }
    else {
      iVar6 = 0x14;
    }
    if (iStack_c != 0) {
      _brelse(iStack_c);
    }
    if ((iVar6 != 0) && (param_3 != 0)) {
      *(sword *)(param_5 + 100) = *(sword *)(param_5 + 100) + -1;
      *(word *)(param_5 + 0x42) = *(word *)(param_5 + 0x42) | 0x40;
    }
    wVar1 = *(word *)(param_1 + 0x42);
    *(word *)(param_1 + 0x42) = wVar1 & 0xfffe;
    if ((wVar1 & 0x10) != 0) {
      *(word *)(param_1 + 0x42) = wVar1 & 0xffee;
      _wakeup(param_1);
    }
    return iVar6;
  }
  if (param_3 == 2) {
    return 0x42;
  }
  if ((param_7 != (int *)0x0) && (iVar7 = _dirlook(param_1,param_2,param_7), iVar7 != 0)) {
    return iVar7;
  }
  return 0x11;
}
