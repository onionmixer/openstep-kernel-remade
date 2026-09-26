
/* WARNING: Removing unreachable block (ram,0xf00782d8) */

undefined8 _zone_free_space_add(undefined *param_1,int param_2,uint *param_3,int param_4)

{
  uint *puVar1;
  uint uVar2;
  int iVar3;
  undefined4 unaff_l0;
  uint *puVar4;
  uint uVar5;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  undefined4 unaff_i1;
  undefined4 unaff_i2;
  uint *puVar6;
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
  if (param_1 == (undefined *)0x0) {
    param_1 = __zone_default_space;
  }
  puVar1 = *(uint **)(param_1 + 8);
  puVar6 = (uint *)(param_1 + 8);
  while (((puVar4 = puVar1, puVar4 != (uint *)0x0 && (puVar4 < param_3)) &&
         ((uint *)((int)puVar4 + puVar4[1]) != param_3))) {
    puVar6 = puVar4;
    puVar1 = (uint *)*puVar4;
  }
  if ((puVar4 == (uint *)0x0) || ((uint *)((int)puVar4 + puVar4[1]) < param_3)) {
    if (0xf < (uint)(param_4 - param_2)) {
      if (puVar4 != (uint *)0x0) {
        puVar6 = puVar4;
      }
      uVar5 = (int)param_3 + param_2;
      *(int *)(uVar5 + 4) = param_4 - param_2;
      uVar2 = *puVar6;
      *(uint *)((int)param_3 + param_2) = uVar2;
      if (uVar2 != 0) {
        *(uint *)(uVar2 + 8) = uVar5;
      }
      *(uint **)(uVar5 + 8) = puVar6;
      *puVar6 = uVar5;
      *(int *)(param_1 + 0xc) = *(int *)(param_1 + 0xc) + 1;
      uVar2 = *(uint *)(uVar5 + 4) >> ((byte)*(undefined4 *)(param_1 + 0x10) & 0x1f);
      if ((int)*(uint *)(param_1 + 0x18) < (int)uVar2) {
        uVar2 = *(uint *)(param_1 + 0x18);
      }
      iVar3 = *(int *)(param_1 + 0x14) + uVar2 * 0x10;
      uVar2 = *(uint *)(iVar3 + -0x10);
      if ((uVar2 == 0) || (uVar5 < uVar2)) {
        *(uint *)(iVar3 + -0x10) = uVar5;
      }
    }
  }
  else if ((uint *)((int)puVar4 + puVar4[1]) == param_3) {
    sub_F0077B04(param_1,puVar4);
    uVar5 = (int)puVar4 + param_2;
    *(uint *)(uVar5 + 4) = (puVar4[1] + param_4) - param_2;
    uVar2 = *puVar4;
    *(uint *)((int)puVar4 + param_2) = uVar2;
    if (uVar2 != 0) {
      *(uint *)(uVar2 + 8) = uVar5;
    }
    *(uint **)(uVar5 + 8) = puVar6;
    *puVar6 = uVar5;
    uVar2 = *(uint *)(uVar5 + 4) >> ((byte)*(undefined4 *)(param_1 + 0x10) & 0x1f);
    if ((int)*(uint *)(param_1 + 0x18) < (int)uVar2) {
      uVar2 = *(uint *)(param_1 + 0x18);
    }
    iVar3 = *(int *)(param_1 + 0x14) + uVar2 * 0x10;
    uVar2 = *(uint *)(iVar3 + -0x10);
    param_3 = puVar4;
    if ((uVar2 == 0) || (uVar5 < uVar2)) {
      *(uint *)(iVar3 + -0x10) = uVar5;
    }
  }
  return CONCAT44(param_2,param_3);
}

