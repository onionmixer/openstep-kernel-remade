
/* WARNING: Removing unreachable block (ram,0xf004bc68) */
/* WARNING: Removing unreachable block (ram,0xf004bc24) */
/* WARNING: Removing unreachable block (ram,0xf004bad0) */
/* WARNING: Removing unreachable block (ram,0xf004bb2c) */
/* WARNING: Removing unreachable block (ram,0xf004bc54) */
/* WARNING: Removing unreachable block (ram,0xf004bccc) */
/* WARNING: Removing unreachable block (ram,0xf004bac0) */

undefined8 sub_F004BA68(int param_1,char *param_2,uint param_3,int *param_4,int *param_5)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  char *pcVar4;
  undefined4 unaff_l0;
  int *piVar5;
  undefined4 unaff_l1;
  uint uVar6;
  uint uVar7;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  int iVar8;
  undefined4 unaff_l5;
  int iVar9;
  undefined4 unaff_l6;
  int iVar10;
  undefined4 unaff_l7;
  uint uVar11;
  undefined4 unaff_i0;
  undefined4 unaff_i1;
  undefined4 unaff_i2;
  undefined4 unaff_i3;
  undefined4 unaff_i4;
  undefined4 unaff_i5;
  uint uVar12;
  undefined4 unaff_fp;
  undefined4 unaff_i7;
  bool in_DECOMPILE_MODE;
  int in_CWP;
  
  if (!in_DECOMPILE_MODE) {
    *(undefined4 *)(in_CWP * 0x40 + 0x8000) = unaff_i0;
    *(undefined4 *)((in_CWP * 0x10 + 1) * 4 + 0x8000) = unaff_i1;
    *(undefined4 *)((in_CWP * 0x10 + 2) * 4 + 0x8000) = unaff_i2;
    *(undefined4 *)((in_CWP * 0x10 + 3) * 4 + 0x8000) = unaff_i3;
    *(undefined4 *)((in_CWP * 0x10 + 4) * 4 + 0x8000) = unaff_i4;
    *(undefined4 *)((in_CWP * 0x10 + 5) * 4 + 0x8000) = unaff_i5;
    *(undefined4 *)((in_CWP * 0x10 + 6) * 4 + 0x8000) = unaff_fp;
    *(undefined4 *)((in_CWP * 0x10 + 7) * 4 + 0x8000) = unaff_i7;
    *(undefined4 *)((in_CWP * 0x10 + 8) * 4 + 0x8000) = unaff_l0;
    *(undefined4 *)((in_CWP * 0x10 + 9) * 4 + 0x8000) = unaff_l1;
    *(undefined4 *)((in_CWP * 0x10 + 10) * 4 + 0x8000) = unaff_l3;
    *(undefined4 *)((in_CWP * 0x10 + 0xb) * 4 + 0x8000) = unaff_l3;
    *(undefined4 *)((in_CWP * 0x10 + 0xc) * 4 + 0x8000) = unaff_l4;
    *(undefined4 *)((in_CWP * 0x10 + 0xd) * 4 + 0x8000) = unaff_l5;
    *(undefined4 *)((in_CWP * 0x10 + 0xe) * 4 + 0x8000) = unaff_l6;
    *(undefined4 *)((in_CWP * 0x10 + 0xf) * 4 + 0x8000) = unaff_l7;
  }
  iVar9 = 0;
  iVar8 = 0;
  uVar7 = 0;
  uVar12 = 0;
  uVar6 = 0;
  uVar11 = *(int *)(param_1 + 0x70) + 0x3ffU & 0xfffffc00;
  iVar10 = (param_3 + 4 & 0xfffffffc) + 8;
  if (uVar11 != 0) {
    do {
      if ((uVar6 & ~*(uint *)(*(int *)(param_1 + 0x50) + 0x48)) == 0) {
        if (iVar8 != 0) {
          _brelse(iVar8);
        }
        iVar8 = param_1;
        _blkatoff(param_1,uVar6,0);
        uVar7 = 0;
        if (iVar8 != 0) {
          iVar1 = *param_4;
          goto loc_F004BAE8;
        }
loc_F004BC70:
        iVar8 = (int)*(char *)(dword_F0133DDC + 0x38);
        goto locret_F004BCF8;
      }
      iVar1 = *param_4;
loc_F004BAE8:
      if (iVar1 == 0) {
        if ((uVar7 & 0x3ff) == 0) {
          param_4[1] = -1;
          iVar9 = 0;
          iVar1 = *(int *)(iVar8 + 0x20);
        }
        else {
          iVar1 = *(int *)(iVar8 + 0x20);
        }
      }
      else {
        iVar1 = *(int *)(iVar8 + 0x20);
      }
      piVar5 = (int *)(iVar1 + uVar7);
      if ((*(sword *)(piVar5 + 1) == 0) ||
         (iVar2 = param_1, sub_F004CCF8(param_1,piVar5,uVar7,uVar6), iVar2 != 0)) {
        uVar3 = 0x400 - (uVar7 & 0x3ff);
      }
      else {
        if (*param_4 == 2) {
          iVar1 = *piVar5;
        }
        else {
          uVar3 = (uint)*(word *)(piVar5 + 1);
          if (*(int *)(iVar1 + uVar7) != 0) {
            uVar3 = (uVar3 - 8) - (*(word *)((int)piVar5 + 6) + 4 & 0xfffffffc);
          }
          if (0 < (int)uVar3) {
            if ((int)uVar3 < iVar10) {
              if (*param_4 != 0) {
                iVar1 = *piVar5;
                goto loc_F004BBEC;
              }
              iVar9 = iVar9 + uVar3;
              if (param_4[1] == -1) {
                param_4[1] = uVar6;
              }
              if (iVar9 < iVar10) goto loc_F004BBE8;
              *param_4 = 1;
              uVar3 = (uVar6 + *(word *)(piVar5 + 1)) - param_4[1];
            }
            else {
              *param_4 = 2;
              param_4[1] = uVar6;
              uVar3 = (uint)*(word *)(piVar5 + 1);
            }
            param_4[2] = uVar3;
          }
loc_F004BBE8:
          iVar1 = *piVar5;
        }
loc_F004BBEC:
        if (iVar1 == 0) {
          uVar3 = (uint)*(word *)(piVar5 + 1);
          uVar12 = uVar6;
        }
        else if (*(word *)((int)piVar5 + 6) == param_3) {
          if (*param_2 == *(char *)(piVar5 + 2)) {
            pcVar4 = param_2;
            _bcmp(param_2,piVar5 + 2,param_3);
            if (pcVar4 == (char *)0x0) {
              *(uint *)(param_1 + 0x4c) = uVar6;
              if (*(int *)(param_1 + 0x48) == *piVar5) {
                *param_5 = param_1;
                *(sword *)(param_1 + 0x12) = *(sword *)(param_1 + 0x12) + 1;
              }
              else {
                iVar9 = (int)*(sword *)(param_1 + 0x46);
                _iget(iVar9,*(undefined4 *)(param_1 + 0x50));
                *param_5 = iVar9;
                if (iVar9 == 0) {
                  _brelse(iVar8);
                  goto loc_F004BC70;
                }
              }
              *param_4 = 3;
              param_4[1] = uVar6;
              param_4[2] = uVar6 - uVar12;
              param_4[3] = iVar8;
              param_4[4] = (int)piVar5;
              goto loc_F004BCF4;
            }
            uVar3 = (uint)*(word *)(piVar5 + 1);
            uVar12 = uVar6;
          }
          else {
            uVar3 = (uint)*(word *)(piVar5 + 1);
            uVar12 = uVar6;
          }
        }
        else {
          uVar3 = (uint)*(word *)(piVar5 + 1);
          uVar12 = uVar6;
        }
      }
      uVar6 = uVar6 + uVar3;
      uVar7 = uVar7 + uVar3;
    } while (uVar6 < uVar11);
  }
  if (iVar8 == 0) {
    iVar8 = *param_4;
  }
  else {
    _brelse(iVar8);
    iVar8 = *param_4;
  }
  if (iVar8 == 0) {
    param_4[1] = uVar11;
    param_4[2] = 0x400;
    *param_5 = 0;
  }
  else {
    *param_5 = 0;
  }
loc_F004BCF4:
  iVar8 = 0;
locret_F004BCF8:
  return CONCAT44(param_2,iVar8);
}
