
/* WARNING: Type propagation algorithm not settling */

int _dirremove(int param_1,char *param_2,int param_3,int param_4)

{
  sword *psVar1;
  sword sVar2;
  word wVar3;
  int iVar4;
  int iVar5;
  int aiStack_1c [2];
  undefined2 uStack_12;
  undefined2 uStack_10;
  undefined2 uStack_e;
  int iStack_c;
  undefined4 *puStack_8;
  
  iVar4 = _strlen(param_2);
  if (iVar4 == 0) {
                    /* WARNING: Subroutine does not return */
    _panic(aDirremove);
  }
  if (*param_2 == '.') {
    if (iVar4 == 1) {
      return 0x16;
    }
    if ((iVar4 == 2) && (param_2[1] == '.')) {
      return 0x42;
    }
  }
  aiStack_1c[0] = 0;
  iStack_c = 0;
  while ((*(word *)(param_1 + 0x42) & 1) != 0) {
    *(word *)(param_1 + 0x42) = *(word *)(param_1 + 0x42) | 0x10;
    _sleep(param_1,10);
  }
  *(word *)(param_1 + 0x42) = *(word *)(param_1 + 0x42) | 1;
  if ((*(word *)(param_1 + 0x62) & 0xf000) == 0x4000) {
    iVar5 = _iaccess(param_1,0xc0);
    if (iVar5 == 0) {
      aiStack_1c[1] = 2;
      iVar5 = sub_4035BA6(param_1,param_2,iVar4,aiStack_1c + 1,aiStack_1c);
      if (iVar5 == 0) {
        if ((aiStack_1c[0] == 0) || ((param_3 != 0 && (aiStack_1c[0] != param_3)))) {
          iVar5 = 2;
        }
        else if (((((*(byte *)(param_1 + 0x62) & 2) == 0) ||
                  (sVar2 = *(sword *)(*(int *)(_active_u + 0x1a) + 2), sVar2 == 0)) ||
                 (sVar2 == *(sword *)(param_1 + 0x66))) ||
                (sVar2 == *(sword *)(aiStack_1c[0] + 0x66))) {
          if (*(int *)(aiStack_1c[0] + 0x18) == 0) {
            if (((param_4 == 0) || ((*(word *)(aiStack_1c[0] + 0x62) & 0xf000) != 0x4000)) ||
               ((*(sword *)(aiStack_1c[0] + 100) == 2 &&
                (iVar4 = sub_4036AE4(aiStack_1c[0],*(undefined4 *)(param_1 + 0x46)), iVar4 != 0))))
            {
              _dnlc_remove(param_1 + 0xc,param_2);
              if ((CONCAT22(uStack_12,uStack_10) & 0x3ffffff) >> 0x10 == 0) {
                *puStack_8 = 0;
              }
              else {
                psVar1 = (sword *)((int)puStack_8 + (4 - CONCAT22(uStack_10,uStack_e)));
                *psVar1 = *(sword *)(puStack_8 + 1) + *psVar1;
              }
              _bwrite(iStack_c);
              iStack_c = 0;
              *(word *)(param_1 + 0x42) = *(word *)(param_1 + 0x42) | 0x42;
              *(word *)(aiStack_1c[0] + 0x42) = *(word *)(aiStack_1c[0] + 0x42) | 0x40;
              if (*(char *)(dword_40B57D4 + 100) == '\0') {
                if (0 < *(sword *)(aiStack_1c[0] + 100)) {
                  if ((param_4 == 0) || ((*(word *)(aiStack_1c[0] + 0x62) & 0xf000) != 0x4000)) {
                    *(sword *)(aiStack_1c[0] + 100) = *(sword *)(aiStack_1c[0] + 100) + -1;
                  }
                  else {
                    *(sword *)(aiStack_1c[0] + 100) = *(sword *)(aiStack_1c[0] + 100) + -2;
                    *(sword *)(param_1 + 100) = *(sword *)(param_1 + 100) + -1;
                    _dnlc_remove(aiStack_1c[0] + 0xc,&asc_40A6047);
                    _dnlc_remove(aiStack_1c[0] + 0xc,&asc_40A6712);
                    _itrunc(aiStack_1c[0],0);
                  }
                }
              }
              else {
                iVar5 = (int)*(char *)(dword_40B57D4 + 100);
              }
            }
            else {
              iVar5 = 0x42;
            }
          }
          else {
            iVar5 = 0x10;
          }
        }
        else {
          iVar5 = 1;
        }
      }
    }
  }
  else {
    iVar5 = 0x14;
  }
  if ((aiStack_1c[0] != 0) && (_iput(aiStack_1c[0]), *(sword *)(aiStack_1c[0] + 100) == 0)) {
    _vnode_uncache(aiStack_1c[0] + 0xc);
  }
  if (iStack_c != 0) {
    _brelse(iStack_c);
  }
  wVar3 = *(word *)(param_1 + 0x42);
  *(word *)(param_1 + 0x42) = wVar3 & 0xfffe;
  if ((wVar3 & 0x10) != 0) {
    *(word *)(param_1 + 0x42) = wVar3 & 0xffee;
    _wakeup(param_1);
  }
  return iVar5;
}
