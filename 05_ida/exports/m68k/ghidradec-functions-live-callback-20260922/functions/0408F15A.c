
undefined4 _encontrol(int param_1,undefined4 param_2,int *param_3)

{
  sword sVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  int *piVar7;
  int iVar8;
  int iVar9;
  
  sVar1 = *(sword *)(param_1 + 8);
  iVar2 = sVar1 * 0x52c;
  iVar3 = _if_unit(param_1);
  iVar3 = *(int *)((&_eninfo)[iVar3] + 0x12);
  uVar6 = 0;
  iVar4 = _strcmp(param_2,_IFCONTROL_SETFLAGS);
  if (iVar4 == 0) {
    if (((*param_3 & 0x10000) != 0) && (((&byte_40C9139)[iVar2] & 1) == 0)) {
      _eninit(param_1);
    }
  }
  else {
    iVar4 = _strcmp(param_2,&_IFCONTROL_GETADDR);
    if (iVar4 == 0) {
      _bcopy((int)&unk_40C8F38 + iVar2,param_3,6);
    }
    else {
      iVar4 = _strcmp(param_2,_IFCONTROL_SETIPADDRESS);
      if (iVar4 == 0) {
        _bcopy(param_3,&dword_40C8F3E + sVar1 * 0x14b,4);
      }
      else {
        iVar4 = _strcmp(param_2,_IFCONTROL_ADDMULTICAST);
        if (iVar4 == 0) {
          iVar4 = *(int *)(DAT_40c9456 + iVar2 + 4);
          if ((iVar4 / 5) * 5 == iVar4) {
            uVar5 = _kalloc((iVar4 * 3 + 0xf) * 2);
            if (*(int *)(DAT_40c9456 + iVar2) == 0) {
              *(undefined4 *)(DAT_40c9456 + iVar2) = uVar5;
              if (((*(byte *)(param_1 + 0xc) & 1) == 0) && (_dma_chip == 0x139)) {
                *(undefined *)(iVar3 + 5) = 2;
              }
              *(word *)(param_1 + 0xc) = *(word *)(param_1 + 0xc) | 0x200;
            }
            else {
              iVar3 = *(int *)(DAT_40c9456 + iVar2 + 4);
              _bytecopy(*(int *)(DAT_40c9456 + iVar2),uVar5,iVar3 * 6);
              _kfree(*(undefined4 *)(DAT_40c9456 + iVar2),iVar3 * 6);
              *(undefined4 *)(DAT_40c9456 + iVar2) = uVar5;
            }
          }
          iVar3 = 0;
          if (0 < *(int *)(DAT_40c9456 + iVar2 + 4)) {
            piVar7 = *(int **)(DAT_40c9456 + iVar2);
            do {
              if ((*param_3 == *piVar7) && (*(sword *)(piVar7 + 1) == *(sword *)(param_3 + 1))) {
                return 0;
              }
              piVar7 = (int *)((int)piVar7 + 6);
              iVar3 = iVar3 + 1;
            } while (iVar3 < *(int *)(DAT_40c9456 + iVar2 + 4));
          }
          _bytecopy(param_3,*(int *)(DAT_40c9456 + iVar2) + iVar3 * 6,6);
          *(int *)(DAT_40c9456 + iVar2 + 4) = *(int *)(DAT_40c9456 + iVar2 + 4) + 1;
        }
        else {
          iVar4 = _strcmp(param_2,_IFCONTROL_RCVPROMISCUOUS);
          if (iVar4 == 0) {
            if (_dma_chip == 0x139) {
              *(undefined *)(iVar3 + 5) = 3;
            }
            else {
              sub_408DBD2(iVar3 + 5,0xa1);
            }
            *(word *)(param_1 + 0xc) = *(word *)(param_1 + 0xc) | 0x100;
          }
          else {
            iVar4 = _strcmp(param_2,_IFCONTROL_RMVMULTICAST);
            if ((iVar4 == 0) && (*(int *)(DAT_40c9456 + iVar2) != 0)) {
              iVar4 = 0;
              if (param_3 == (int *)0x0) {
                _kfree(*(int *)(DAT_40c9456 + iVar2),
                       ((*(int *)(DAT_40c9456 + iVar2 + 4) + 4) / 5) * 0x1e);
                *(undefined4 *)(DAT_40c9456 + iVar2) = 0;
                *(undefined4 *)(DAT_40c9456 + iVar2 + 4) = 0;
              }
              else {
                if (0 < *(int *)(DAT_40c9456 + iVar2 + 4)) {
                  iVar8 = 0;
loc_408F3BA:
                  if ((*param_3 != *(int *)(*(int *)(DAT_40c9456 + iVar2) + iVar8)) ||
                     (*(sword *)(*(int *)(DAT_40c9456 + iVar2) + 4 + iVar8) !=
                      *(sword *)(param_3 + 1))) goto loc_408F40E;
                  iVar9 = iVar4 * 6;
                  iVar8 = iVar9;
                  do {
                    iVar8 = iVar8 + 6;
                    _bytecopy(iVar8 + *(int *)(DAT_40c9456 + iVar2),
                              iVar9 + *(int *)(DAT_40c9456 + iVar2),6);
                    iVar9 = iVar9 + 6;
                    iVar4 = iVar4 + 1;
                  } while (iVar4 < *(int *)(DAT_40c9456 + iVar2 + 4));
                  *(int *)(DAT_40c9456 + iVar2 + 4) = *(int *)(DAT_40c9456 + iVar2 + 4) + -1;
                }
loc_408F418:
                iVar4 = *(int *)(DAT_40c9456 + iVar2 + 4);
                if (iVar4 == 0) {
                  _kfree(*(undefined4 *)(DAT_40c9456 + iVar2),0x1e);
                  *(undefined4 *)(DAT_40c9456 + iVar2) = 0;
                  if (((*(byte *)(param_1 + 0xc) & 1) == 0) && (_dma_chip == 0x139)) {
                    *(undefined *)(iVar3 + 5) = 1;
                  }
                  *(word *)(param_1 + 0xc) = *(word *)(param_1 + 0xc) & 0xfdff;
                }
                else if ((iVar4 / 5) * 5 == iVar4) {
                  iVar4 = iVar4 * 6;
                  uVar5 = _kalloc(iVar4);
                  _bytecopy(*(undefined4 *)(DAT_40c9456 + iVar2),uVar5,iVar4);
                  _kfree(*(undefined4 *)(DAT_40c9456 + iVar2),iVar4 + 0x1e);
                  *(undefined4 *)(DAT_40c9456 + iVar2) = uVar5;
                }
              }
            }
            else {
              iVar2 = _strcmp(param_2,_IFCONTROL_RCVPROMISCOFF);
              if (iVar2 == 0) {
                if (_dma_chip == 0x139) {
                  if ((*(byte *)(param_1 + 0xc) & 2) == 0) {
                    *(undefined *)(iVar3 + 5) = 1;
                  }
                  else {
                    *(undefined *)(iVar3 + 5) = 2;
                  }
                }
                else {
                  sub_408DBD2(iVar3 + 5,0xa2);
                }
                *(word *)(param_1 + 0xc) = *(word *)(param_1 + 0xc) & 0xfeff;
              }
              else {
                uVar6 = 0x16;
              }
            }
          }
        }
      }
    }
  }
  return uVar6;
loc_408F40E:
  iVar8 = iVar8 + 6;
  iVar4 = iVar4 + 1;
  if (*(int *)(DAT_40c9456 + iVar2 + 4) <= iVar4) goto loc_408F418;
  goto loc_408F3BA;
}

