
/* WARNING: Removing unreachable block (ram,0xf00ac244) */
/* WARNING: Removing unreachable block (ram,0xf00ac21c) */
/* WARNING: Removing unreachable block (ram,0xf00ac1f4) */
/* WARNING: Removing unreachable block (ram,0xf00ac1cc) */
/* WARNING: Removing unreachable block (ram,0xf00ac194) */
/* WARNING: Removing unreachable block (ram,0xf00ac0cc) */
/* WARNING: Removing unreachable block (ram,0xf00ac0a4) */
/* WARNING: Removing unreachable block (ram,0xf00ac07c) */
/* WARNING: Removing unreachable block (ram,0xf00abfac) */
/* WARNING: Removing unreachable block (ram,0xf00abf84) */
/* WARNING: Removing unreachable block (ram,0xf00abf4c) */
/* WARNING: Removing unreachable block (ram,0xf00abf70) */
/* WARNING: Removing unreachable block (ram,0xf00abf98) */
/* WARNING: Removing unreachable block (ram,0xf00ac058) */
/* WARNING: Removing unreachable block (ram,0xf00ac090) */
/* WARNING: Removing unreachable block (ram,0xf00ac0b8) */
/* WARNING: Removing unreachable block (ram,0xf00ac0e0) */
/* WARNING: Removing unreachable block (ram,0xf00ac1b8) */
/* WARNING: Removing unreachable block (ram,0xf00ac1e0) */
/* WARNING: Removing unreachable block (ram,0xf00ac208) */
/* WARNING: Removing unreachable block (ram,0xf00ac230) */
/* WARNING: Removing unreachable block (ram,0xf00ac2f8) */
/* WARNING: Removing unreachable block (ram,0xf00abdb4) */

undefined8 __fp_sqrt(uint *param_1,int *param_2,int *param_3)

{
  int *piVar1;
  undefined *puVar2;
  int *piVar3;
  int *piVar4;
  undefined *puVar5;
  uint uVar6;
  uint uVar7;
  undefined4 unaff_l0;
  int iVar8;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  undefined4 unaff_i1;
  undefined4 unaff_i2;
  undefined4 unaff_i3;
  undefined4 unaff_i4;
  undefined4 unaff_i5;
  undefined4 unaff_fp;
  undefined4 unaff_i7;
  bool in_DECOMPILE_MODE;
  int in_CWP;
  undefined auStackX_0 [92];
  
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
  *param_3 = *param_2;
  param_3[1] = param_2[1];
  param_3[2] = param_2[2];
  param_3[3] = param_2[3];
  param_3[4] = param_2[4];
  param_3[5] = param_2[5];
  param_3[6] = param_2[6];
  param_3[7] = param_2[7];
  param_3[8] = param_2[8];
  switch(param_2[1]) {
  case :
  case :
  case :
    goto locret_F00AC310;
  case :
    if (*param_2 == 1) goto loc_F00ABDB4;
    uVar6 = param_2[2];
    break;
  case :
    if (*param_2 != 1) goto locret_F00AC310;
loc_F00ABDB4:
    _fpu_error_nan(param_1,param_3);
    param_3[1] = 4;
    goto locret_F00AC310;
  :
    uVar6 = param_2[2];
  }
  param_1 = (uint *)(param_2 + 3);
  if ((uVar6 & 1) == 0) {
    param_3[2] = (int)uVar6 / 2;
  }
  else {
    param_3[2] = (int)(uVar6 - 1) / 2;
    param_2[3] = param_2[3] << 1 | (uint)param_2[4] >> 0x1f;
    param_2[4] = param_2[4] << 1 | (uint)param_2[5] >> 0x1f;
    param_2[5] = param_2[5] << 1 | (uint)param_2[6] >> 0x1f;
    param_2[6] = param_2[6] << 1;
  }
  *(undefined4 *)((int)register0x00000038 + -0xc) = 0;
  *(undefined4 *)((int)register0x00000038 + -0x10) = 0;
  *(undefined4 *)((int)register0x00000038 + -0x14) = 0;
  *(undefined4 *)((int)register0x00000038 + -0x18) = 0;
  *(undefined4 *)((int)register0x00000038 + -0x1c) = 0;
  *(undefined4 *)((int)register0x00000038 + -0x20) = 0;
  *(undefined4 *)((int)register0x00000038 + -0x24) = 0;
  *(undefined4 *)((int)register0x00000038 + -0x28) = 0;
  iVar8 = 0;
  uVar6 = 0x10000;
  do {
    uVar7 = *(int *)((int)register0x00000038 + -0x28) + uVar6;
    *(uint *)((int)register0x00000038 + -0x18) = uVar7;
    if (uVar7 <= *param_1) {
      *(uint *)((int)register0x00000038 + -0x28) = uVar7 + uVar6;
      iVar8 = iVar8 + uVar6;
      *param_1 = *param_1 - uVar7;
    }
    uVar6 = uVar6 >> 1;
    *param_1 = *param_1 << 1 | (uint)param_2[4] >> 0x1f;
    param_2[4] = param_2[4] << 1 | (uint)param_2[5] >> 0x1f;
    param_2[5] = param_2[5] << 1 | (uint)param_2[6] >> 0x1f;
    param_2[6] = param_2[6] << 1;
  } while (uVar6 != 0);
  param_3[3] = iVar8;
  iVar8 = 0;
  uVar6 = 0x80000000;
  do {
    puVar2 = (undefined *)((int)register0x00000038 + -0x18);
    *(uint *)((int)register0x00000038 + -0x14) = *(int *)((int)register0x00000038 + -0x24) + uVar6;
    *(undefined4 *)((int)register0x00000038 + -0x18) =
         *(undefined4 *)((int)register0x00000038 + -0x28);
    _fpu_cmpli(puVar2,param_1,2);
    if ((int)puVar2 < 1) {
      puVar2 = (undefined *)((int)register0x00000038 + -0x24);
      iVar8 = iVar8 + uVar6;
      _fpu_add3wc(puVar2,*(undefined4 *)((int)register0x00000038 + -0x14),uVar6,0);
      _fpu_add3wc((undefined *)((int)register0x00000038 + -0x28),
                  *(undefined4 *)((int)register0x00000038 + -0x18),0,puVar2);
      piVar3 = param_2 + 4;
      _fpu_sub3wc(piVar3,param_2[4],*(undefined4 *)((int)register0x00000038 + -0x14),0);
      _fpu_sub3wc(param_1,*param_1,*(undefined4 *)((int)register0x00000038 + -0x18),piVar3);
      uVar7 = *param_1;
    }
    else {
      uVar7 = *param_1;
    }
    uVar6 = uVar6 >> 1;
    *param_1 = uVar7 << 1 | (uint)param_2[4] >> 0x1f;
    param_2[4] = param_2[4] << 1 | (uint)param_2[5] >> 0x1f;
    param_2[5] = param_2[5] << 1 | (uint)param_2[6] >> 0x1f;
    param_2[6] = param_2[6] << 1;
  } while (uVar6 != 0);
  param_3[4] = iVar8;
  iVar8 = 0;
  uVar6 = 0x80000000;
  do {
    puVar2 = (undefined *)((int)register0x00000038 + -0x18);
    *(uint *)((int)register0x00000038 + -0x10) = *(int *)((int)register0x00000038 + -0x20) + uVar6;
    *(undefined4 *)((int)register0x00000038 + -0x14) =
         *(undefined4 *)((int)register0x00000038 + -0x24);
    *(undefined4 *)((int)register0x00000038 + -0x18) =
         *(undefined4 *)((int)register0x00000038 + -0x28);
    _fpu_cmpli(puVar2,param_1,3);
    if ((int)puVar2 < 1) {
      puVar2 = (undefined *)((int)register0x00000038 + -0x20);
      iVar8 = iVar8 + uVar6;
      _fpu_add3wc(puVar2,*(undefined4 *)((int)register0x00000038 + -0x10),uVar6,0);
      puVar5 = (undefined *)((int)register0x00000038 + -0x24);
      _fpu_add3wc(puVar5,*(undefined4 *)((int)register0x00000038 + -0x14),0,puVar2);
      _fpu_add3wc((undefined *)((int)register0x00000038 + -0x28),
                  *(undefined4 *)((int)register0x00000038 + -0x18),0,puVar5);
      piVar3 = param_2 + 5;
      _fpu_sub3wc(piVar3,param_2[5],*(undefined4 *)((int)register0x00000038 + -0x10),0);
      piVar4 = param_2 + 4;
      _fpu_sub3wc(piVar4,param_2[4],*(undefined4 *)((int)register0x00000038 + -0x14),piVar3);
      _fpu_sub3wc(param_1,*param_1,*(undefined4 *)((int)register0x00000038 + -0x18),piVar4);
      uVar7 = *param_1;
    }
    else {
      uVar7 = *param_1;
    }
    uVar6 = uVar6 >> 1;
    *param_1 = uVar7 << 1 | (uint)param_2[4] >> 0x1f;
    param_2[4] = param_2[4] << 1 | (uint)param_2[5] >> 0x1f;
    param_2[5] = param_2[5] << 1 | (uint)param_2[6] >> 0x1f;
    param_2[6] = param_2[6] << 1;
  } while (uVar6 != 0);
  param_3[5] = iVar8;
  iVar8 = 0;
  uVar6 = 0x80000000;
  do {
    puVar2 = (undefined *)((int)register0x00000038 + -0x18);
    *(uint *)((int)register0x00000038 + -0xc) = *(int *)((int)register0x00000038 + -0x1c) + uVar6;
    *(undefined4 *)((int)register0x00000038 + -0x10) =
         *(undefined4 *)((int)register0x00000038 + -0x20);
    *(undefined4 *)((int)register0x00000038 + -0x14) =
         *(undefined4 *)((int)register0x00000038 + -0x24);
    *(undefined4 *)((int)register0x00000038 + -0x18) =
         *(undefined4 *)((int)register0x00000038 + -0x28);
    _fpu_cmpli(puVar2,param_1,4);
    if ((int)puVar2 < 1) {
      puVar2 = (undefined *)((int)register0x00000038 + -0x1c);
      iVar8 = iVar8 + uVar6;
      _fpu_add3wc(puVar2,*(undefined4 *)((int)register0x00000038 + -0xc),uVar6,0);
      puVar5 = (undefined *)((int)register0x00000038 + -0x20);
      _fpu_add3wc(puVar5,*(undefined4 *)((int)register0x00000038 + -0x10),0,puVar2);
      puVar2 = (undefined *)((int)register0x00000038 + -0x24);
      _fpu_add3wc(puVar2,*(undefined4 *)((int)register0x00000038 + -0x14),0,puVar5);
      _fpu_add3wc((undefined *)((int)register0x00000038 + -0x28),
                  *(undefined4 *)((int)register0x00000038 + -0x18),0,puVar2);
      piVar3 = param_2 + 6;
      _fpu_sub3wc(piVar3,param_2[6],*(undefined4 *)((int)register0x00000038 + -0xc),0);
      piVar4 = param_2 + 5;
      _fpu_sub3wc(piVar4,param_2[5],*(undefined4 *)((int)register0x00000038 + -0x10),piVar3);
      piVar3 = param_2 + 4;
      _fpu_sub3wc(piVar3,param_2[4],*(undefined4 *)((int)register0x00000038 + -0x14),piVar4);
      _fpu_sub3wc(param_1,*param_1,*(undefined4 *)((int)register0x00000038 + -0x18),piVar3);
      uVar7 = *param_1;
    }
    else {
      uVar7 = *param_1;
    }
    uVar6 = uVar6 >> 1;
    *param_1 = uVar7 << 1 | (uint)param_2[4] >> 0x1f;
    param_2[4] = param_2[4] << 1 | (uint)param_2[5] >> 0x1f;
    param_2[5] = param_2[5] << 1 | (uint)param_2[6] >> 0x1f;
    param_2[6] = param_2[6] << 1;
  } while (uVar6 != 0);
  param_3[6] = iVar8;
  piVar3 = param_2 + 4;
  piVar4 = param_2 + 5;
  piVar1 = param_2 + 6;
  param_2 = (int *)0x0;
  if (((*param_1 == 0 && *piVar3 == 0) && *piVar4 == 0) && *piVar1 == 0) {
    param_3[7] = 0;
    param_3[8] = 0;
  }
  else {
    param_3[8] = 1;
    puVar2 = (undefined *)((int)register0x00000038 + -0x28);
    _fpu_cmpli(puVar2,param_1,4);
    if ((int)puVar2 < 0) {
      param_3[7] = 1;
    }
    else {
      param_3[7] = 0;
    }
  }
locret_F00AC310:
  return CONCAT44(param_2,param_1);
}

