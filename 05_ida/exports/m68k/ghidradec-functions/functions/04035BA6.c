
int sub_4035BA6(int param_1,char *param_2,uint param_3,int *param_4,int *param_5)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  int iVar5;
  uint uVar6;
  uint uVar7;
  int *piVar8;
  int iVar9;
  uint uStack_8;
  
  iVar5 = 0;
  iVar9 = 0;
  uVar4 = 0;
  iVar2 = (param_3 + 4 & 0xfffffffc) + 8;
  uVar6 = *(int *)(param_1 + 0x6e) + 0x3ffU & 0xfffffc00;
  uStack_8 = 0;
  uVar3 = 0;
  if (uVar6 != 0) {
    do {
      if ((uVar3 & ~*(uint *)(*(int *)(param_1 + 0x4e) + 0x48)) == 0) {
        if (iVar9 != 0) {
          _brelse(iVar9);
        }
        iVar9 = _blkatoff(param_1,uVar3,0);
        if (iVar9 == 0) goto loc_4035D3A;
        uVar4 = 0;
      }
      if ((*param_4 == 0) && ((uVar4 & 0x3ff) == 0)) {
        param_4[1] = -1;
        iVar5 = 0;
      }
      piVar8 = (int *)(uVar4 + *(int *)(iVar9 + 0x20));
      if ((*(sword *)(piVar8 + 1) == 0) ||
         (iVar1 = sub_4036A22(param_1,piVar8,uVar4,uVar3), iVar1 != 0)) {
        uVar7 = 0x400 - (uVar4 & 0x3ff);
      }
      else {
        if (*param_4 != 2) {
          uVar7 = (uint)*(word *)(piVar8 + 1);
          if (*piVar8 != 0) {
            uVar7 = (uVar7 - 8) - (*(word *)((int)piVar8 + 6) + 4 & 0xfffffffc);
          }
          if (0 < (int)uVar7) {
            if ((int)uVar7 < iVar2) {
              if (*param_4 == 0) {
                iVar5 = uVar7 + iVar5;
                if (param_4[1] == -1) {
                  param_4[1] = uVar3;
                }
                if (iVar2 <= iVar5) {
                  *param_4 = 1;
                  uVar7 = (uVar3 + *(word *)(piVar8 + 1)) - param_4[1];
                  goto loc_4035CCC;
                }
              }
            }
            else {
              *param_4 = 2;
              param_4[1] = uVar3;
              uVar7 = (uint)*(word *)(piVar8 + 1);
loc_4035CCC:
              param_4[2] = uVar7;
            }
          }
        }
        if ((((*piVar8 != 0) && (*(word *)((int)piVar8 + 6) == param_3)) &&
            (*param_2 == *(char *)(piVar8 + 2))) &&
           (iVar1 = _bcmp(param_2,piVar8 + 2,param_3), iVar1 == 0)) {
          *(uint *)(param_1 + 0x4a) = uVar3;
          if (*piVar8 == *(int *)(param_1 + 0x46)) {
            *param_5 = param_1;
            *(sword *)(param_1 + 0x12) = *(sword *)(param_1 + 0x12) + 1;
          }
          else {
            iVar2 = _iget((int)*(sword *)(param_1 + 0x44),*(undefined4 *)(param_1 + 0x4e),*piVar8);
            *param_5 = iVar2;
            if (iVar2 == 0) {
              _brelse(iVar9);
loc_4035D3A:
              return (int)*(char *)(dword_40B57D4 + 100);
            }
          }
          *param_4 = 3;
          param_4[1] = uVar3;
          param_4[2] = uVar3 - uStack_8;
          param_4[3] = iVar9;
          param_4[4] = (int)piVar8;
          return 0;
        }
        uVar7 = (uint)*(word *)(piVar8 + 1);
        uStack_8 = uVar3;
      }
      uVar3 = uVar7 + uVar3;
      uVar4 = uVar7 + uVar4;
    } while (uVar3 < uVar6);
  }
  if (iVar9 != 0) {
    _brelse(iVar9);
  }
  if (*param_4 == 0) {
    param_4[1] = uVar6;
    param_4[2] = 0x400;
  }
  *param_5 = 0;
  return 0;
}
