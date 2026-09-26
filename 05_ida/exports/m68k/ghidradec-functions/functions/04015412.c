
void _recvit(undefined4 param_1,int *param_2,undefined4 param_3,undefined4 param_4,
            undefined4 param_5)

{
  int iVar1;
  int iVar2;
  undefined uVar3;
  int iVar4;
  int *piVar5;
  undefined4 *puVar6;
  int iStack_26;
  int iStack_22;
  int iStack_1e;
  int iStack_1a;
  int iStack_16;
  undefined4 uStack_12;
  undefined4 uStack_e;
  int iStack_8;
  
  iVar1 = _getsock(param_1);
  if (iVar1 != 0) {
    iStack_1a = param_2[2];
    iStack_16 = param_2[3];
    uStack_e = 0;
    uStack_12 = 0;
    iStack_8 = 0;
    puVar6 = (undefined4 *)param_2[2];
    iVar4 = 0;
    if (0 < param_2[3]) {
      piVar5 = puVar6 + 1;
      do {
        iVar2 = *piVar5;
        if (iVar2 < 0) {
          *(undefined *)(dword_40B57D4 + 100) = 0x16;
          return;
        }
        if (iVar2 != 0) {
          iVar2 = _useracc(*puVar6,iVar2,0);
          if (iVar2 == 0) {
            *(undefined *)(dword_40B57D4 + 100) = 0xe;
            return;
          }
          iStack_8 = *piVar5 + iStack_8;
        }
        iVar4 = iVar4 + 1;
        piVar5 = piVar5 + 2;
        puVar6 = puVar6 + 2;
      } while (iVar4 < param_2[3]);
    }
    iStack_26 = iStack_8;
    uVar3 = _soreceive(*(undefined4 *)(iVar1 + 0x16),&iStack_1e,&iStack_1a,param_3,&iStack_22);
    *(undefined *)(dword_40B57D4 + 100) = uVar3;
    *(int *)(dword_40B57D4 + 0x5c) = iStack_26 - iStack_8;
    if (*param_2 != 0) {
      iStack_26 = param_2[1];
      if ((iStack_26 < 1) || (iStack_1e == 0)) {
        iStack_26 = 0;
      }
      else {
        if (*(sword *)(iStack_1e + 8) < iStack_26) {
          iStack_26 = (int)*(sword *)(iStack_1e + 8);
        }
        _copyoutmsg(*(int *)(iStack_1e + 4) + iStack_1e,*param_2,iStack_26);
      }
      _copyoutmsg(&iStack_26,param_4,4);
    }
    if (param_2[4] != 0) {
      iStack_26 = param_2[5];
      if ((iStack_26 < 1) || (iStack_22 == 0)) {
        iStack_26 = 0;
      }
      else {
        if (*(sword *)(iStack_22 + 8) < iStack_26) {
          iStack_26 = (int)*(sword *)(iStack_22 + 8);
        }
        _copyoutmsg(*(int *)(iStack_22 + 4) + iStack_22,param_2[4],iStack_26);
      }
      _copyoutmsg(&iStack_26,param_5,4);
    }
    if (iStack_22 != 0) {
      _m_freem(iStack_22);
    }
    if (iStack_1e != 0) {
      _m_freem(iStack_1e);
    }
  }
  return;
}
