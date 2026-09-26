
int sub_403643A(int param_1,int *param_2,int *param_3)

{
  int iVar1;
  sword sVar2;
  word wVar3;
  undefined4 uVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  
  iVar7 = 0;
  if (param_3 != (int *)0x0) {
    iVar1 = *param_3;
    if (iVar1 == 2) {
      uVar4 = _dirpref(*(undefined4 *)(param_1 + 0x4e));
    }
    else {
      uVar4 = *(undefined4 *)(param_1 + 0x46);
    }
    wVar3 = *(word *)(param_3 + 1) | (word)*(undefined4 *)(_vttoif_tab + iVar1 * 4);
    iVar5 = _ialloc(param_1,uVar4,
                    CONCAT22((sword)((uint)*(undefined4 *)(_vttoif_tab + iVar1 * 4) >> 0x10),wVar3))
    ;
    if (iVar5 == 0) {
      iVar7 = (int)*(char *)(dword_40B57D4 + 100);
    }
    else {
      *(word *)(iVar5 + 0x42) = *(word *)(iVar5 + 0x42) | 0x46;
      *(word *)(iVar5 + 0x62) = wVar3;
      if ((iVar1 - 3U < 2) || (iVar1 == 9)) {
        sVar2 = *(sword *)(param_3 + 0xd);
        *(int *)(iVar5 + 0x8a) = (int)sVar2;
        *(sword *)(iVar5 + 0x38) = sVar2;
      }
      *(int *)(iVar5 + 0x34) = iVar1;
      if (iVar1 == 2) {
        *(undefined2 *)(iVar5 + 100) = 2;
      }
      else {
        *(undefined2 *)(iVar5 + 100) = 1;
      }
      if (*(sword *)(*(int *)(iVar5 + 0x30) + 0x124) == 0) {
        *(undefined2 *)(iVar5 + 0x66) = *(undefined2 *)(*(int *)(_active_u + 0x1a) + 2);
        *(undefined2 *)(iVar5 + 0x68) = *(undefined2 *)(param_1 + 0x68);
      }
      else {
        *(undefined2 *)(iVar5 + 0xe2) = *(undefined2 *)(param_1 + 0xe2);
        *(undefined2 *)(iVar5 + 0xe4) = *(undefined2 *)(param_1 + 0xe4);
        *(undefined2 *)(iVar5 + 0x66) = *(undefined2 *)(*(int *)(iVar5 + 0x30) + 0x124);
        *(undefined2 *)(iVar5 + 0x68) = _nogroup;
      }
      if (((*(byte *)(iVar5 + 0x62) & 4) != 0) &&
         (iVar6 = _groupmember((int)*(sword *)(iVar5 + 0x68)), iVar6 == 0)) {
        *(word *)(iVar5 + 0x62) = *(word *)(iVar5 + 0x62) & 0xfbff;
      }
      _iupdat(iVar5,1);
      if (iVar1 == 2) {
        iVar7 = sub_40365BA(iVar5,param_1);
      }
      if (iVar7 == 0) {
        wVar3 = *(word *)(iVar5 + 0x42);
        *(word *)(iVar5 + 0x42) = wVar3 & 0xfffe;
        if ((wVar3 & 0x10) != 0) {
          *(word *)(iVar5 + 0x42) = wVar3 & 0xffee;
          _wakeup(iVar5);
        }
        *param_2 = iVar5;
      }
      else {
        *(undefined2 *)(iVar5 + 100) = 0;
        *(word *)(iVar5 + 0x42) = *(word *)(iVar5 + 0x42) | 0x40;
        _iput(iVar5);
      }
    }
    return iVar7;
  }
                    /* WARNING: Subroutine does not return */
  _panic(aDirmakeinodeNo);
}

