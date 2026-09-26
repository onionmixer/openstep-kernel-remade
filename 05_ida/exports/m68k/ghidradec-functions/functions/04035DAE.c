
int sub_4035DAE(int param_1,int param_2,int param_3,undefined4 param_4,undefined4 param_5,
               int param_6,int param_7)

{
  sword sVar1;
  int iVar2;
  bool bVar3;
  
  if ((*(int *)(param_6 + 0x30) == *(int *)(param_3 + 0x30)) &&
     (*(int *)(param_6 + 0x30) == *(int *)(param_2 + 0x30))) {
    if (*(int *)(param_2 + 0x46) == *(int *)(param_6 + 0x46)) {
      iVar2 = -1;
    }
    else {
      iVar2 = _iaccess(param_3,0x80);
      if (iVar2 == 0) {
        if (((((*(byte *)(param_3 + 0x62) & 2) == 0) ||
             (sVar1 = *(sword *)(*(int *)(_active_u + 0x1a) + 2), sVar1 == 0)) ||
            (sVar1 == *(sword *)(param_3 + 0x66))) || (sVar1 == *(sword *)(param_6 + 0x66))) {
          bVar3 = (*(word *)(param_2 + 0x62) & 0xf000) != 0x4000;
          if ((*(word *)(param_6 + 0x62) & 0xf000) == 0x4000) {
            if (bVar3) {
              return 0x15;
            }
            iVar2 = sub_4036AE4(param_6,*(undefined4 *)(param_3 + 0x46));
            if ((iVar2 == 0) || (2 < *(sword *)(param_6 + 100))) {
              return 0x42;
            }
          }
          else if (!bVar3) {
            return 0x14;
          }
          _dnlc_remove(param_3 + 0xc,param_4);
          **(undefined4 **)(param_7 + 0x10) = *(undefined4 *)(param_2 + 0x46);
          _dnlc_enter(param_3 + 0xc,param_4,param_2 + 0xc,0);
          _bwrite(*(undefined4 *)(param_7 + 0xc));
          *(undefined4 *)(param_7 + 0xc) = 0;
          if (*(char *)(dword_40B57D4 + 100) == '\0') {
            *(word *)(param_3 + 0x42) = *(word *)(param_3 + 0x42) | 0x42;
            *(sword *)(param_6 + 100) = *(sword *)(param_6 + 100) + -1;
            *(word *)(param_6 + 0x42) = *(word *)(param_6 + 0x42) | 0x40;
            if (!bVar3) {
              sVar1 = *(sword *)(param_6 + 100);
              *(sword *)(param_6 + 100) = sVar1 + -1;
              if (sVar1 != 1) {
                    /* WARNING: Subroutine does not return */
                _panic(aDirenterTarget);
              }
              _itrunc(param_6,0);
              *(sword *)(param_3 + 100) = *(sword *)(param_3 + 100) + -1;
              *(word *)(param_3 + 0x42) = *(word *)(param_3 + 0x42) | 0x40;
              if ((param_3 != param_1) && (iVar2 = sub_4035F40(param_2,param_1,param_3), iVar2 != 0)
                 ) {
                return iVar2;
              }
            }
            iVar2 = 0;
          }
          else {
            iVar2 = (int)*(char *)(dword_40B57D4 + 100);
          }
        }
        else {
          iVar2 = 1;
        }
      }
    }
  }
  else {
    iVar2 = 0x12;
  }
  return iVar2;
}
