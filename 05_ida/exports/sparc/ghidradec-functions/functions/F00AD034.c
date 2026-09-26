
/* WARNING: Removing unreachable block (ram,0xf00ad4b8) */
/* WARNING: Removing unreachable block (ram,0xf00ad490) */
/* WARNING: Removing unreachable block (ram,0xf00ad3bc) */
/* WARNING: Removing unreachable block (ram,0xf00ad394) */
/* WARNING: Removing unreachable block (ram,0xf00ad2b8) */
/* WARNING: Removing unreachable block (ram,0xf00ad290) */
/* WARNING: Removing unreachable block (ram,0xf00ad1f0) */
/* WARNING: Removing unreachable block (ram,0xf00ad1c8) */
/* WARNING: Removing unreachable block (ram,0xf00ad1dc) */
/* WARNING: Removing unreachable block (ram,0xf00ad204) */
/* WARNING: Removing unreachable block (ram,0xf00ad2a4) */
/* WARNING: Removing unreachable block (ram,0xf00ad2cc) */
/* WARNING: Removing unreachable block (ram,0xf00ad3a8) */
/* WARNING: Removing unreachable block (ram,0xf00ad3d0) */
/* WARNING: Removing unreachable block (ram,0xf00ad4a4) */
/* WARNING: Removing unreachable block (ram,0xf00ad4cc) */
/* WARNING: Removing unreachable block (ram,0xf00ad108) */

undefined8 __fp_mul(uint param_1,uint *param_2,uint *param_3,uint *param_4)

{
  uint uVar1;
  uint uVar2;
  undefined *puVar3;
  undefined *puVar4;
  undefined4 unaff_l0;
  uint *puVar5;
  undefined4 unaff_l1;
  uint uVar6;
  undefined4 unaff_l3;
  uint uVar7;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  uint uVar8;
  undefined4 unaff_i1;
  uint *puVar9;
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
  if ((int)param_2[1] < (int)param_3[1]) {
    uVar1 = *param_3;
    puVar9 = param_3;
  }
  else {
    uVar1 = *param_2;
    puVar9 = param_2;
    param_2 = param_3;
  }
  *param_4 = uVar1;
  param_4[1] = puVar9[1];
  param_4[2] = puVar9[2];
  param_4[3] = puVar9[3];
  param_4[4] = puVar9[4];
  param_4[5] = puVar9[5];
  param_4[6] = puVar9[6];
  param_4[7] = puVar9[7];
  param_4[8] = puVar9[8];
  if ((int)param_4[1] < 4) {
    *param_4 = *puVar9 ^ *param_2;
  }
  switch(puVar9[1]) {
  case :
  case :
  case :
    goto locret_F00AD5A8;
  case :
    if (param_2[1] == 0) {
      param_4[1] = 0;
      goto locret_F00AD5A8;
    }
    *(undefined4 *)((int)register0x00000038 + -0xc) = 0;
    break;
  case :
    if (param_2[1] == 0) {
      _fpu_error_nan(param_1,param_4);
      param_4[1] = 4;
    }
    goto locret_F00AD5A8;
  :
    *(undefined4 *)((int)register0x00000038 + -0xc) = 0;
  }
  *(undefined4 *)((int)register0x00000038 + -0x10) = 0;
  *(undefined4 *)((int)register0x00000038 + -0x14) = 0;
  *(undefined4 *)((int)register0x00000038 + -0x18) = 0;
  uVar1 = 0;
  uVar7 = param_2[6];
  uVar6 = 0;
  puVar5 = puVar9 + 3;
  if (uVar7 != 0) {
    uVar8 = 1;
    uVar2 = *(uint *)((int)register0x00000038 + -0xc);
    while( true ) {
      uVar6 = uVar6 | uVar1;
      uVar1 = uVar2 & 1;
      uVar2 = *(uint *)((int)register0x00000038 + -0x10) << 0x1f | uVar2 >> 1;
      *(uint *)((int)register0x00000038 + -0xc) = uVar2;
      *(uint *)((int)register0x00000038 + -0x10) =
           *(uint *)((int)register0x00000038 + -0x14) << 0x1f |
           *(uint *)((int)register0x00000038 + -0x10) >> 1;
      *(uint *)((int)register0x00000038 + -0x14) =
           *(uint *)((int)register0x00000038 + -0x18) << 0x1f |
           *(uint *)((int)register0x00000038 + -0x14) >> 1;
      *(uint *)((int)register0x00000038 + -0x18) = *(uint *)((int)register0x00000038 + -0x18) >> 1;
      if ((uVar8 & uVar7) != 0) {
        puVar3 = (undefined *)((int)register0x00000038 + -0xc);
        _fpu_add3wc(puVar3,uVar2,puVar9[6],0);
        puVar4 = (undefined *)((int)register0x00000038 + -0x10);
        _fpu_add3wc(puVar4,*(undefined4 *)((int)register0x00000038 + -0x10),puVar9[5],puVar3);
        puVar3 = (undefined *)((int)register0x00000038 + -0x14);
        _fpu_add3wc(puVar3,*(undefined4 *)((int)register0x00000038 + -0x14),puVar9[4],puVar4);
        _fpu_add3wc((undefined *)((int)register0x00000038 + -0x18),
                    *(undefined4 *)((int)register0x00000038 + -0x18),*puVar5,puVar3);
      }
      uVar8 = uVar8 * 2;
      if (uVar8 == 0) break;
      uVar2 = *(uint *)((int)register0x00000038 + -0xc);
    }
  }
  uVar8 = param_2[5];
  uVar7 = 1;
  if (uVar8 == 0) {
    uVar6 = uVar6 | uVar1 | *(uint *)((int)register0x00000038 + -0xc) & 0x7fffffff;
    uVar1 = *(uint *)((int)register0x00000038 + -0xc) >> 0x1f;
    *(undefined4 *)((int)register0x00000038 + -0xc) =
         *(undefined4 *)((int)register0x00000038 + -0x10);
    *(undefined4 *)((int)register0x00000038 + -0x10) =
         *(undefined4 *)((int)register0x00000038 + -0x14);
    *(undefined4 *)((int)register0x00000038 + -0x14) =
         *(undefined4 *)((int)register0x00000038 + -0x18);
    *(undefined4 *)((int)register0x00000038 + -0x18) = 0;
    uVar7 = param_2[4];
  }
  else {
    uVar2 = *(uint *)((int)register0x00000038 + -0xc);
    do {
      uVar6 = uVar6 | uVar1;
      uVar1 = uVar2 & 1;
      uVar2 = *(uint *)((int)register0x00000038 + -0x10) << 0x1f | uVar2 >> 1;
      *(uint *)((int)register0x00000038 + -0xc) = uVar2;
      *(uint *)((int)register0x00000038 + -0x10) =
           *(uint *)((int)register0x00000038 + -0x14) << 0x1f |
           *(uint *)((int)register0x00000038 + -0x10) >> 1;
      *(uint *)((int)register0x00000038 + -0x14) =
           *(uint *)((int)register0x00000038 + -0x18) << 0x1f |
           *(uint *)((int)register0x00000038 + -0x14) >> 1;
      *(uint *)((int)register0x00000038 + -0x18) = *(uint *)((int)register0x00000038 + -0x18) >> 1;
      if ((uVar7 & uVar8) != 0) {
        puVar3 = (undefined *)((int)register0x00000038 + -0xc);
        _fpu_add3wc(puVar3,uVar2,puVar9[6],0);
        puVar4 = (undefined *)((int)register0x00000038 + -0x10);
        _fpu_add3wc(puVar4,*(undefined4 *)((int)register0x00000038 + -0x10),puVar9[5],puVar3);
        puVar3 = (undefined *)((int)register0x00000038 + -0x14);
        _fpu_add3wc(puVar3,*(undefined4 *)((int)register0x00000038 + -0x14),puVar9[4],puVar4);
        _fpu_add3wc((undefined *)((int)register0x00000038 + -0x18),
                    *(undefined4 *)((int)register0x00000038 + -0x18),*puVar5,puVar3);
      }
      uVar7 = uVar7 * 2;
      uVar2 = *(uint *)((int)register0x00000038 + -0xc);
    } while (uVar7 != 0);
    uVar7 = param_2[4];
  }
  uVar8 = 1;
  if (uVar7 == 0) {
    uVar6 = uVar6 | uVar1 | *(uint *)((int)register0x00000038 + -0xc) & 0x7fffffff;
    uVar1 = *(uint *)((int)register0x00000038 + -0xc) >> 0x1f;
    *(undefined4 *)((int)register0x00000038 + -0xc) =
         *(undefined4 *)((int)register0x00000038 + -0x10);
    *(undefined4 *)((int)register0x00000038 + -0x10) =
         *(undefined4 *)((int)register0x00000038 + -0x14);
    *(undefined4 *)((int)register0x00000038 + -0x14) =
         *(undefined4 *)((int)register0x00000038 + -0x18);
    *(undefined4 *)((int)register0x00000038 + -0x18) = 0;
    uVar7 = param_2[3];
  }
  else {
    uVar2 = *(uint *)((int)register0x00000038 + -0xc);
    do {
      uVar6 = uVar6 | uVar1;
      uVar1 = uVar2 & 1;
      uVar2 = *(uint *)((int)register0x00000038 + -0x10) << 0x1f | uVar2 >> 1;
      *(uint *)((int)register0x00000038 + -0xc) = uVar2;
      *(uint *)((int)register0x00000038 + -0x10) =
           *(uint *)((int)register0x00000038 + -0x14) << 0x1f |
           *(uint *)((int)register0x00000038 + -0x10) >> 1;
      *(uint *)((int)register0x00000038 + -0x14) =
           *(uint *)((int)register0x00000038 + -0x18) << 0x1f |
           *(uint *)((int)register0x00000038 + -0x14) >> 1;
      *(uint *)((int)register0x00000038 + -0x18) = *(uint *)((int)register0x00000038 + -0x18) >> 1;
      if ((uVar8 & uVar7) != 0) {
        puVar3 = (undefined *)((int)register0x00000038 + -0xc);
        _fpu_add3wc(puVar3,uVar2,puVar9[6],0);
        puVar4 = (undefined *)((int)register0x00000038 + -0x10);
        _fpu_add3wc(puVar4,*(undefined4 *)((int)register0x00000038 + -0x10),puVar9[5],puVar3);
        puVar3 = (undefined *)((int)register0x00000038 + -0x14);
        _fpu_add3wc(puVar3,*(undefined4 *)((int)register0x00000038 + -0x14),puVar9[4],puVar4);
        _fpu_add3wc((undefined *)((int)register0x00000038 + -0x18),
                    *(undefined4 *)((int)register0x00000038 + -0x18),*puVar5,puVar3);
      }
      uVar8 = uVar8 * 2;
      uVar2 = *(uint *)((int)register0x00000038 + -0xc);
    } while (uVar8 != 0);
    uVar7 = param_2[3];
  }
  param_1 = 1;
  uVar8 = *(uint *)((int)register0x00000038 + -0xc);
  do {
    uVar6 = uVar6 | uVar1;
    uVar1 = uVar8 & 1;
    uVar8 = *(uint *)((int)register0x00000038 + -0x10) << 0x1f | uVar8 >> 1;
    *(uint *)((int)register0x00000038 + -0xc) = uVar8;
    *(uint *)((int)register0x00000038 + -0x10) =
         *(uint *)((int)register0x00000038 + -0x14) << 0x1f |
         *(uint *)((int)register0x00000038 + -0x10) >> 1;
    *(uint *)((int)register0x00000038 + -0x14) =
         *(uint *)((int)register0x00000038 + -0x18) << 0x1f |
         *(uint *)((int)register0x00000038 + -0x14) >> 1;
    *(uint *)((int)register0x00000038 + -0x18) = *(uint *)((int)register0x00000038 + -0x18) >> 1;
    if ((param_1 & uVar7) != 0) {
      puVar3 = (undefined *)((int)register0x00000038 + -0xc);
      _fpu_add3wc(puVar3,uVar8,puVar9[6],0);
      puVar4 = (undefined *)((int)register0x00000038 + -0x10);
      _fpu_add3wc(puVar4,*(undefined4 *)((int)register0x00000038 + -0x10),puVar9[5],puVar3);
      puVar3 = (undefined *)((int)register0x00000038 + -0x14);
      _fpu_add3wc(puVar3,*(undefined4 *)((int)register0x00000038 + -0x14),puVar9[4],puVar4);
      _fpu_add3wc((undefined *)((int)register0x00000038 + -0x18),
                  *(undefined4 *)((int)register0x00000038 + -0x18),*puVar5,puVar3);
    }
    param_1 = param_1 * 2;
    uVar8 = *(uint *)((int)register0x00000038 + -0xc);
  } while (param_1 < uVar7 || param_1 - uVar7 == 0);
  if (*(uint *)((int)register0x00000038 + -0x18) < 0x20000) {
    param_4[2] = puVar9[2] + param_2[2];
    param_4[8] = uVar6;
    param_4[7] = uVar1;
    param_4[6] = *(uint *)((int)register0x00000038 + -0xc);
    param_4[5] = *(uint *)((int)register0x00000038 + -0x10);
    param_4[4] = *(uint *)((int)register0x00000038 + -0x14);
    uVar1 = *(uint *)((int)register0x00000038 + -0x18);
  }
  else {
    param_4[2] = puVar9[2] + param_2[2] + 1;
    param_4[8] = uVar6 | uVar1;
    param_4[7] = *(uint *)((int)register0x00000038 + -0xc) & 1;
    param_4[6] = *(int *)((int)register0x00000038 + -0x10) << 0x1f |
                 *(uint *)((int)register0x00000038 + -0xc) >> 1;
    param_4[5] = *(int *)((int)register0x00000038 + -0x14) << 0x1f |
                 *(uint *)((int)register0x00000038 + -0x10) >> 1;
    param_4[4] = *(int *)((int)register0x00000038 + -0x18) << 0x1f |
                 *(uint *)((int)register0x00000038 + -0x14) >> 1;
    uVar1 = *(uint *)((int)register0x00000038 + -0x18) >> 1;
  }
  param_4[3] = uVar1;
locret_F00AD5A8:
  return CONCAT44(puVar9,param_1);
}
