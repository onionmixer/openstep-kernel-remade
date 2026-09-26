
/* WARNING: Removing unreachable block (ram,0xf00ab1dc) */
/* WARNING: Removing unreachable block (ram,0xf00ab1b4) */
/* WARNING: Removing unreachable block (ram,0xf00ab1a0) */
/* WARNING: Removing unreachable block (ram,0xf00ab1c8) */
/* WARNING: Removing unreachable block (ram,0xf00ab1fc) */
/* WARNING: Removing unreachable block (ram,0xf00ab17c) */

undefined8
sub_F00AB068(undefined4 param_1,undefined4 *param_2,undefined4 *param_3,undefined4 *param_4)

{
  uint uVar1;
  undefined4 uVar2;
  int iVar3;
  undefined4 *puVar4;
  undefined4 *puVar5;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  undefined4 unaff_i1;
  undefined4 *puVar6;
  undefined4 *puVar7;
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
    uVar1 = param_3[1];
    puVar6 = param_3;
  }
  else {
    uVar1 = param_2[1];
    puVar6 = param_2;
    param_2 = param_3;
  }
  puVar7 = puVar6;
  if (uVar1 == 2) {
    uVar2 = *puVar6;
  }
  else if (uVar1 < 3) {
    if (uVar1 == 0) {
      uVar2 = *puVar6;
    }
    else {
      iVar3 = param_2[1];
loc_F00AB0CC:
      if (iVar3 != 0) {
        if ((int)puVar6[2] < (int)param_2[2]) {
          uVar2 = param_2[1];
          puVar7 = param_2;
        }
        else {
          uVar2 = puVar6[1];
          puVar6 = param_2;
        }
        param_4[1] = uVar2;
        *param_4 = *puVar7;
        param_4[2] = puVar7[2];
        param_4[8] = 0;
        param_4[7] = 0;
        if (puVar7[2] == puVar6[2]) {
          uVar2 = puVar7[6];
        }
        else {
          _fpu_rightshift(puVar6,param_4[2] - puVar6[2]);
          param_4[7] = puVar6[7];
          param_4[8] = puVar6[8];
          uVar2 = puVar7[6];
        }
        puVar4 = param_4 + 6;
        _fpu_add3wc(puVar4,uVar2,puVar6[6],0);
        puVar5 = param_4 + 5;
        _fpu_add3wc(puVar5,puVar7[5],puVar6[5],puVar4);
        puVar4 = param_4 + 4;
        _fpu_add3wc(puVar4,puVar7[4],puVar6[4],puVar5);
        _fpu_add3wc(param_4 + 3,puVar7[3],puVar6[3],puVar4);
        if (0x1ffff < (uint)param_4[3]) {
          _fpu_rightshift(param_4,1);
          param_4[2] = param_4[2] + 1;
        }
        goto locret_F00AB210;
      }
      uVar2 = *puVar6;
    }
  }
  else {
    if ((5 < uVar1) || (uVar1 < 4)) {
      iVar3 = param_2[1];
      goto loc_F00AB0CC;
    }
    uVar2 = *puVar6;
  }
  *param_4 = uVar2;
  param_4[1] = puVar6[1];
  param_4[2] = puVar6[2];
  param_4[3] = puVar6[3];
  param_4[4] = puVar6[4];
  param_4[5] = puVar6[5];
  param_4[6] = puVar6[6];
  param_4[7] = puVar6[7];
  param_4[8] = puVar6[8];
locret_F00AB210:
  return CONCAT44(puVar7,param_1);
}

