
/* WARNING: Removing unreachable block (ram,0xf00abce8) */
/* WARNING: Removing unreachable block (ram,0xf00abc30) */
/* WARNING: Removing unreachable block (ram,0xf00abc08) */
/* WARNING: Removing unreachable block (ram,0xf00abb64) */
/* WARNING: Removing unreachable block (ram,0xf00abb3c) */
/* WARNING: Removing unreachable block (ram,0xf00abb08) */
/* WARNING: Removing unreachable block (ram,0xf00aba70) */
/* WARNING: Removing unreachable block (ram,0xf00aba48) */
/* WARNING: Removing unreachable block (ram,0xf00ab9a8) */
/* WARNING: Removing unreachable block (ram,0xf00ab980) */
/* WARNING: Removing unreachable block (ram,0xf00ab94c) */
/* WARNING: Removing unreachable block (ram,0xf00ab8fc) */
/* WARNING: Removing unreachable block (ram,0xf00ab96c) */
/* WARNING: Removing unreachable block (ram,0xf00ab994) */
/* WARNING: Removing unreachable block (ram,0xf00aba28) */
/* WARNING: Removing unreachable block (ram,0xf00aba5c) */
/* WARNING: Removing unreachable block (ram,0xf00aba84) */
/* WARNING: Removing unreachable block (ram,0xf00abb28) */
/* WARNING: Removing unreachable block (ram,0xf00abb50) */
/* WARNING: Removing unreachable block (ram,0xf00abbe8) */
/* WARNING: Removing unreachable block (ram,0xf00abc1c) */
/* WARNING: Removing unreachable block (ram,0xf00abc44) */
/* WARNING: Removing unreachable block (ram,0xf00ab884) */
/* WARNING: Removing unreachable block (ram,0xf00ab8bc) */
/* WARNING: Heritage AFTER dead removal. Example location: o1 : 0xf00ab8fc */
/* WARNING: Restarted to delay deadcode elimination for space: register */

uint __fp_div(uint *param_1,uint *param_2)

{
  undefined4 extraout_o0;
  undefined4 extraout_o0_00;
  undefined4 extraout_o0_01;
  undefined4 extraout_o0_02;
  qword in_o0_1;
  uint *puVar3;
  undefined4 uVar4;
  qword qVar1;
  sqword sVar2;
  undefined4 unaff_l0;
  uint *puVar5;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  uint uVar6;
  undefined4 unaff_i1;
  int iVar7;
  undefined4 unaff_i2;
  undefined *puVar8;
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
  uVar6 = (uint)(in_o0_1 >> 0x20);
  puVar3 = (uint *)in_o0_1;
  *param_2 = *puVar3;
  param_2[1] = puVar3[1];
  param_2[2] = puVar3[2];
  param_2[3] = puVar3[3];
  param_2[4] = puVar3[4];
  param_2[5] = puVar3[5];
  param_2[6] = puVar3[6];
  param_2[7] = puVar3[7];
  param_2[8] = puVar3[8];
  if (((int)param_1[1] < 4) && ((int)puVar3[1] < 4)) {
    *param_2 = *puVar3 ^ *param_1;
    switch(puVar3[1]) {
    case :
    case :
      if (puVar3[1] != param_1[1]) {
        return uVar6;
      }
      _fpu_error_nan();
      param_2[1] = 4;
      return uVar6;
    case :
      if (param_1[1] == 0) {
        _fpu_set_exception(uVar6);
        param_2[1] = 2;
        return uVar6;
      }
      if (param_1[1] == 2) {
        param_2[1] = 0;
        return uVar6;
      }
      break;
    :
    }
    puVar5 = param_1 + 3;
    *(uint *)((int)register0x00000038 + -0x18) = uVar6;
    *(uint *)((int)register0x00000038 + -0x14) = puVar3[4];
    *(uint *)((int)register0x00000038 + -0x10) = puVar3[5];
    *(uint *)((int)register0x00000038 + -0xc) = puVar3[6];
    _fpu_cmpli((undefined *)((int)register0x00000038 + -0x18),puVar3,4);
    param_2[2] = uVar6;
    uVar6 = 0;
    puVar8 = (undefined *)((int)register0x00000038 + -0x18);
    do {
      uVar6 = uVar6 * 2;
      uVar4 = (undefined4)in_o0_1;
      _fpu_cmpli(puVar8,uVar4,4);
      extraout_o0 = (undefined4)(in_o0_1 >> 0x20);
      if (-1 < (sqword)in_o0_1) {
        uVar6 = uVar6 + 1;
        _fpu_sub3wc((undefined *)((int)register0x00000038 + -0xc),uVar4,param_1[6],0);
        _fpu_sub3wc((undefined *)((int)register0x00000038 + -0x10),uVar4,param_1[5],extraout_o0);
        _fpu_sub3wc((undefined *)((int)register0x00000038 + -0x14),uVar4,param_1[4],extraout_o0);
        _fpu_sub3wc(puVar8,uVar4,*puVar5,extraout_o0);
      }
      qVar1 = CONCAT44(*(int *)((int)register0x00000038 + -0x14),
                       *(int *)((int)register0x00000038 + -0x18) << 1) & 0x80000000ffffffff;
      *(uint *)((int)register0x00000038 + -0x18) = (uint)qVar1 | (uint)(qVar1 >> 0x3f);
      *(uint *)((int)register0x00000038 + -0x14) =
           *(int *)((int)register0x00000038 + -0x14) << 1 |
           *(uint *)((int)register0x00000038 + -0x10) >> 0x1f;
      in_o0_1 = CONCAT44(*(undefined4 *)((int)register0x00000038 + -0xc),
                         *(undefined4 *)((int)register0x00000038 + -0xc)) & 0x80000000ffffffff;
      *(uint *)((int)register0x00000038 + -0x10) =
           *(uint *)((int)register0x00000038 + -0x10) << 1 | (uint)(in_o0_1 >> 0x3f);
      *(int *)((int)register0x00000038 + -0xc) = (int)in_o0_1 << 1;
    } while (uVar6 < 0x10000);
    param_2[3] = uVar6;
    uVar6 = 0;
    iVar7 = 0x1f;
    do {
      uVar6 = uVar6 * 2;
      uVar4 = (undefined4)in_o0_1;
      _fpu_cmpli(puVar8,uVar4,4);
      extraout_o0_00 = (undefined4)(in_o0_1 >> 0x20);
      if (-1 < (sqword)in_o0_1) {
        uVar6 = uVar6 + 1;
        _fpu_sub3wc((undefined *)((int)register0x00000038 + -0xc),uVar4,param_1[6],0);
        _fpu_sub3wc((undefined *)((int)register0x00000038 + -0x10),uVar4,param_1[5],extraout_o0_00);
        _fpu_sub3wc((undefined *)((int)register0x00000038 + -0x14),uVar4,param_1[4],extraout_o0_00);
        _fpu_sub3wc(puVar8,uVar4,*puVar5,extraout_o0_00);
      }
      iVar7 = iVar7 + -1;
      qVar1 = CONCAT44(*(int *)((int)register0x00000038 + -0x14),
                       *(int *)((int)register0x00000038 + -0x18) << 1) & 0x80000000ffffffff;
      *(uint *)((int)register0x00000038 + -0x18) = (uint)qVar1 | (uint)(qVar1 >> 0x3f);
      *(uint *)((int)register0x00000038 + -0x14) =
           *(int *)((int)register0x00000038 + -0x14) << 1 |
           *(uint *)((int)register0x00000038 + -0x10) >> 0x1f;
      in_o0_1 = CONCAT44(*(undefined4 *)((int)register0x00000038 + -0xc),
                         *(undefined4 *)((int)register0x00000038 + -0xc)) & 0x80000000ffffffff;
      *(uint *)((int)register0x00000038 + -0x10) =
           *(uint *)((int)register0x00000038 + -0x10) << 1 | (uint)(in_o0_1 >> 0x3f);
      *(int *)((int)register0x00000038 + -0xc) = (int)in_o0_1 << 1;
    } while (iVar7 != -1);
    param_2[4] = uVar6;
    uVar6 = 0;
    iVar7 = 0x1f;
    do {
      uVar6 = uVar6 * 2;
      uVar4 = (undefined4)in_o0_1;
      _fpu_cmpli(puVar8,uVar4,4);
      extraout_o0_01 = (undefined4)(in_o0_1 >> 0x20);
      if (-1 < (sqword)in_o0_1) {
        uVar6 = uVar6 + 1;
        _fpu_sub3wc((undefined *)((int)register0x00000038 + -0xc),uVar4,param_1[6],0);
        _fpu_sub3wc((undefined *)((int)register0x00000038 + -0x10),uVar4,param_1[5],extraout_o0_01);
        _fpu_sub3wc((undefined *)((int)register0x00000038 + -0x14),uVar4,param_1[4],extraout_o0_01);
        _fpu_sub3wc(puVar8,uVar4,*puVar5,extraout_o0_01);
      }
      iVar7 = iVar7 + -1;
      qVar1 = CONCAT44(*(int *)((int)register0x00000038 + -0x14),
                       *(int *)((int)register0x00000038 + -0x18) << 1) & 0x80000000ffffffff;
      *(uint *)((int)register0x00000038 + -0x18) = (uint)qVar1 | (uint)(qVar1 >> 0x3f);
      *(uint *)((int)register0x00000038 + -0x14) =
           *(int *)((int)register0x00000038 + -0x14) << 1 |
           *(uint *)((int)register0x00000038 + -0x10) >> 0x1f;
      in_o0_1 = CONCAT44(*(undefined4 *)((int)register0x00000038 + -0xc),
                         *(undefined4 *)((int)register0x00000038 + -0xc)) & 0x80000000ffffffff;
      *(uint *)((int)register0x00000038 + -0x10) =
           *(uint *)((int)register0x00000038 + -0x10) << 1 | (uint)(in_o0_1 >> 0x3f);
      *(int *)((int)register0x00000038 + -0xc) = (int)in_o0_1 << 1;
    } while (iVar7 != -1);
    param_2[5] = uVar6;
    uVar6 = 0;
    iVar7 = 0x1f;
    do {
      uVar6 = uVar6 * 2;
      uVar4 = (undefined4)in_o0_1;
      _fpu_cmpli(puVar8,uVar4,4);
      extraout_o0_02 = (undefined4)(in_o0_1 >> 0x20);
      if (-1 < (sqword)in_o0_1) {
        uVar6 = uVar6 + 1;
        _fpu_sub3wc((undefined *)((int)register0x00000038 + -0xc),uVar4,param_1[6],0);
        _fpu_sub3wc((undefined *)((int)register0x00000038 + -0x10),uVar4,param_1[5],extraout_o0_02);
        _fpu_sub3wc((undefined *)((int)register0x00000038 + -0x14),uVar4,param_1[4],extraout_o0_02);
        _fpu_sub3wc(puVar8,uVar4,*puVar5,extraout_o0_02);
      }
      iVar7 = iVar7 + -1;
      qVar1 = CONCAT44(*(int *)((int)register0x00000038 + -0x14),
                       *(int *)((int)register0x00000038 + -0x18) << 1) & 0x80000000ffffffff;
      *(uint *)((int)register0x00000038 + -0x18) = (uint)qVar1 | (uint)(qVar1 >> 0x3f);
      *(uint *)((int)register0x00000038 + -0x14) =
           *(int *)((int)register0x00000038 + -0x14) << 1 |
           *(uint *)((int)register0x00000038 + -0x10) >> 0x1f;
      in_o0_1 = CONCAT44(*(undefined4 *)((int)register0x00000038 + -0xc),
                         *(undefined4 *)((int)register0x00000038 + -0xc)) & 0x80000000ffffffff;
      *(uint *)((int)register0x00000038 + -0x10) =
           *(uint *)((int)register0x00000038 + -0x10) << 1 | (uint)(in_o0_1 >> 0x3f);
      *(int *)((int)register0x00000038 + -0xc) = (int)in_o0_1 << 1;
    } while (iVar7 != -1);
    param_2[6] = uVar6;
    sVar2 = *(sqword *)((int)register0x00000038 + -0x18);
    uVar6 = 1;
    if ((((int)((qword)sVar2 >> 0x20) == 0 && (int)sVar2 == 0) &&
        *(int *)((int)register0x00000038 + -0x10) == 0) &&
        *(int *)((int)register0x00000038 + -0xc) == 0) {
      param_2[7] = 0;
      param_2[8] = 0;
    }
    else {
      param_2[8] = 1;
      _fpu_cmpli(puVar8,(int)sVar2,4);
      if (-1 < sVar2) {
        param_2[7] = 1;
      }
    }
  }
  else if ((int)puVar3[1] < (int)param_1[1]) {
    *param_2 = *param_1;
    param_2[1] = param_1[1];
    param_2[2] = param_1[2];
    param_2[3] = param_1[3];
    param_2[4] = param_1[4];
    param_2[5] = param_1[5];
    param_2[6] = param_1[6];
    param_2[7] = param_1[7];
    param_2[8] = param_1[8];
  }
  return uVar6;
}

