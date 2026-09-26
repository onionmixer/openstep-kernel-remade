
/* WARNING: Removing unreachable block (ram,0xf004c4e8) */
/* WARNING: Removing unreachable block (ram,0xf004c424) */
/* WARNING: Removing unreachable block (ram,0xf004c374) */
/* WARNING: Removing unreachable block (ram,0xf004c3a0) */
/* WARNING: Removing unreachable block (ram,0xf004c52c) */
/* WARNING: Removing unreachable block (ram,0xf004c45c) */
/* WARNING: Removing unreachable block (ram,0xf004c354) */

undefined8 sub_F004C32C(uint param_1,uint *param_2)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  undefined4 unaff_l0;
  uint uVar5;
  int *piVar6;
  int *piVar7;
  undefined4 unaff_l1;
  sword sVar8;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  int iVar9;
  undefined4 unaff_i1;
  undefined4 unaff_i2;
  undefined4 unaff_i3;
  undefined4 unaff_i4;
  undefined4 unaff_i5;
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
  uVar5 = param_2[1] + param_2[2];
  if (*param_2 == 0) {
    if ((param_2[1] & 0x3ff) != 0) {
      _panic(aDirprepareentr);
    }
    if (*(int *)(*(int *)(param_1 + 0x50) + 0x34) < 0x400) {
      _panic(aDirblksizFsize);
      iVar4 = *(int *)(param_1 + 0x50);
    }
    else {
      iVar4 = *(int *)(param_1 + 0x50);
    }
    uVar1 = param_1;
    _bmap(param_1,param_2[1] >> ((byte)*(undefined4 *)(iVar4 + 0x50) & 0x1f),0,
          (param_2[1] & ~*(uint *)(iVar4 + 0x48)) + 0x400,0);
    if (((int)uVar1 < 1) || (*(char *)(dword_F0133DDC + 0x38) != '\0')) {
      iVar4 = 0x1c;
      if (*(char *)(dword_F0133DDC + 0x38) != 0) {
        iVar4 = (int)*(char *)(dword_F0133DDC + 0x38);
      }
      goto locret_F004C53C;
    }
    *(uint *)(param_1 + 0x70) = uVar5;
    *(word *)(param_1 + 0x44) = *(word *)(param_1 + 0x44) | 0x42;
  }
  else if (*(uint *)(param_1 + 0x70) < uVar5) {
    *(uint *)(param_1 + 0x70) = uVar5 + 0x3ff & 0xfffffc00;
    *(word *)(param_1 + 0x44) = *(word *)(param_1 + 0x44) | 0x42;
  }
  _blkatoff(param_1,param_2[1],param_2 + 4);
  param_2[3] = param_1;
  if (param_1 == 0) {
    iVar4 = (int)*(char *)(dword_F0133DDC + 0x38);
  }
  else {
    piVar6 = (int *)param_2[4];
    if (*param_2 == 0) {
      _bzero(piVar6,0x400);
      *(undefined2 *)(piVar6 + 1) = 0x400;
    }
    else if (*param_2 < 3) {
      uVar5 = (uint)*(word *)(piVar6 + 1);
      iVar9 = (*(word *)((int)piVar6 + 6) + 4 & 0xfffffffc) + 8;
      iVar4 = uVar5 - iVar9;
      sVar8 = (sword)iVar4;
      piVar7 = piVar6;
      if ((int)uVar5 < (int)param_2[2]) {
        iVar2 = *piVar6;
        while( true ) {
          iVar3 = (int)piVar6 + uVar5;
          if (iVar2 == 0) {
            iVar4 = iVar4 + iVar9;
          }
          else {
            *(sword *)(piVar7 + 1) = (sword)iVar9;
            piVar7 = (int *)((int)piVar7 + iVar9);
          }
          iVar9 = (*(word *)(iVar3 + 6) + 4 & 0xfffffffc) + 8;
          iVar4 = iVar4 + ((uint)*(word *)(iVar3 + 4) - iVar9);
          sVar8 = (sword)iVar4;
          uVar5 = uVar5 + *(word *)(iVar3 + 4);
          _bcopy(iVar3,piVar7,iVar9);
          if ((int)param_2[2] <= (int)uVar5) break;
          iVar2 = *piVar7;
        }
      }
      piVar6 = piVar7;
      if (*piVar6 == 0) {
        *(sword *)(piVar6 + 1) = sVar8 + (sword)iVar9;
      }
      else {
        *(sword *)(piVar6 + 1) = (sword)iVar9;
        piVar6 = (int *)((int)piVar6 + iVar9);
        *(sword *)(piVar6 + 1) = sVar8;
      }
    }
    else {
      _panic(aDirprepareentr_0);
    }
    param_2[4] = (uint)piVar6;
    iVar4 = 0;
  }
locret_F004C53C:
  return CONCAT44(param_2,iVar4);
}

