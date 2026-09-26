
/* WARNING: Removing unreachable block (ram,0xf00ab454) */
/* WARNING: Removing unreachable block (ram,0xf00ab42c) */
/* WARNING: Removing unreachable block (ram,0xf00ab3b4) */
/* WARNING: Removing unreachable block (ram,0xf00ab388) */
/* WARNING: Removing unreachable block (ram,0xf00ab500) */
/* WARNING: Removing unreachable block (ram,0xf00ab4d8) */
/* WARNING: Removing unreachable block (ram,0xf00ab480) */
/* WARNING: Removing unreachable block (ram,0xf00ab46c) */
/* WARNING: Removing unreachable block (ram,0xf00ab4c4) */
/* WARNING: Removing unreachable block (ram,0xf00ab4ec) */
/* WARNING: Removing unreachable block (ram,0xf00ab370) */
/* WARNING: Removing unreachable block (ram,0xf00ab3a0) */
/* WARNING: Removing unreachable block (ram,0xf00ab418) */
/* WARNING: Removing unreachable block (ram,0xf00ab440) */
/* WARNING: Removing unreachable block (ram,0xf00ab59c) */
/* WARNING: Removing unreachable block (ram,0xf00ab2d4) */

undefined8 sub_F00AB218(uint param_1,uint *param_2,uint *param_3,uint *param_4)

{
  uint uVar1;
  uint *puVar2;
  uint *puVar3;
  uint *puVar4;
  uint *puVar5;
  uint *puVar6;
  undefined4 unaff_l0;
  uint uVar7;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  uint *puVar8;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  undefined4 unaff_i1;
  uint *puVar9;
  uint *puVar10;
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
  if ((int)param_2[1] < (int)param_3[1]) {
    uVar1 = *param_3;
    puVar10 = param_3;
  }
  else {
    uVar1 = *param_2;
    puVar10 = param_2;
    param_2 = param_3;
  }
  *param_4 = uVar1;
  param_4[1] = puVar10[1];
  param_4[2] = puVar10[2];
  param_4[3] = puVar10[3];
  param_4[4] = puVar10[4];
  param_4[5] = puVar10[5];
  param_4[6] = puVar10[6];
  uVar1 = param_4[1];
  param_4[7] = puVar10[7];
  param_4[8] = puVar10[8];
  if (uVar1 == 2) {
    if (param_2[1] == 2) {
      _fpu_error_nan(param_1,param_4);
      param_4[1] = 4;
    }
  }
  else {
    if (uVar1 < 3) {
      if (uVar1 == 0) {
        *param_4 = (uint)(*(int *)(param_1 + 4) == 3);
        goto locret_F00AB5A4;
      }
      uVar1 = param_2[1];
    }
    else if (uVar1 < 6) {
      if (3 < uVar1) goto locret_F00AB5A4;
      uVar1 = param_2[1];
    }
    else {
      uVar1 = param_2[1];
    }
    if (uVar1 != 0) {
      if ((int)puVar10[2] < (int)param_2[2]) {
        uVar1 = param_2[1];
        puVar9 = param_2;
      }
      else {
        uVar1 = puVar10[1];
        puVar9 = puVar10;
        puVar10 = param_2;
      }
      param_4[1] = uVar1;
      *param_4 = *puVar9;
      param_4[2] = puVar9[2];
      param_4[7] = 0;
      param_4[8] = 0;
      puVar8 = param_4 + 3;
      if (puVar9[2] == puVar10[2]) {
        puVar2 = param_4 + 6;
        puVar5 = puVar2;
        _fpu_sub3wc(puVar2,puVar9[6],puVar10[6],0);
        puVar3 = param_4 + 5;
        puVar6 = puVar3;
        _fpu_sub3wc(puVar3,puVar9[5],puVar10[5],puVar5);
        puVar4 = param_4 + 4;
        puVar5 = puVar4;
        _fpu_sub3wc(puVar4,puVar9[4],puVar10[4],puVar6);
        _fpu_sub3wc(puVar8,puVar9[3],puVar10[3],puVar5);
        if (((param_4[3] == 0 && param_4[4] == 0) && param_4[5] == 0) && param_4[6] == 0) {
          *param_4 = (uint)(*(int *)(param_1 + 4) == 3);
          param_4[1] = 0;
          puVar10 = puVar9;
          goto locret_F00AB5A4;
        }
        if (0x1ffff < param_4[3]) {
          *param_4 = *puVar10;
          _fpu_neg2wc(puVar2,param_4[6],0);
          _fpu_neg2wc(puVar3,param_4[5],puVar2);
          _fpu_neg2wc(puVar4,param_4[4],puVar3);
          _fpu_neg2wc(puVar8,param_4[3],puVar4);
        }
      }
      else {
        _fpu_rightshift(puVar10,(param_4[2] - puVar10[2]) + -1);
        param_1 = puVar10[7];
        uVar7 = puVar10[8];
        _fpu_rightshift(puVar10,1);
        uVar1 = puVar10[7];
        if (uVar7 != 0) {
          param_1 = (uint)(param_1 == 0);
        }
        if ((param_1 | uVar7) != 0) {
          uVar1 = (uint)(uVar1 == 0);
        }
        puVar5 = param_4 + 6;
        _fpu_sub3wc(puVar5,puVar9[6],puVar10[6],(uVar1 != 0 || param_1 != 0) || uVar7 != 0);
        puVar6 = param_4 + 5;
        _fpu_sub3wc(puVar6,puVar9[5],puVar10[5],puVar5);
        puVar5 = param_4 + 4;
        _fpu_sub3wc(puVar5,puVar9[4],puVar10[4],puVar6);
        _fpu_sub3wc(puVar8,puVar9[3],puVar10[3],puVar5);
        if (0xffff < param_4[3]) {
          param_4[8] = param_1 | uVar7;
          param_4[7] = uVar1;
          puVar10 = puVar9;
          goto locret_F00AB5A4;
        }
        param_4[8] = uVar7;
        param_4[7] = param_1;
        param_4[3] = param_4[3] << 1 | param_4[4] >> 0x1f;
        param_4[4] = param_4[4] << 1 | param_4[5] >> 0x1f;
        param_4[5] = param_4[5] << 1 | param_4[6] >> 0x1f;
        param_4[6] = param_4[6] << 1 | uVar1;
        param_4[2] = param_4[2] - 1;
        puVar10 = puVar9;
        if (0xffff < param_4[3]) goto locret_F00AB5A4;
      }
      _fpu_normalize(param_4);
      puVar10 = puVar9;
    }
  }
locret_F00AB5A4:
  return CONCAT44(puVar10,param_1);
}
