
undefined8
-[KernBusRangeResource findFreeRangeWithSize:alignment:]
          (int param_1,undefined4 param_2,int param_3,int param_4)

{
  undefined4 *puVar1;
  int iVar2;
  undefined4 uVar3;
  int iVar4;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  undefined4 unaff_i1;
  uint uVar5;
  undefined4 unaff_i2;
  uint uVar6;
  undefined4 unaff_i3;
  undefined4 unaff_i4;
  undefined4 unaff_i5;
  int *piVar7;
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
  *(undefined4 *)((int)register0x00000038 + -0x14) = 0;
  *(undefined4 *)((int)register0x00000038 + -0x18) = 0;
  uVar5 = *(uint *)(param_1 + 8);
  piVar7 = (int *)(param_1 + 0x18);
  puVar1 = *(undefined4 **)((int)register0x00000038 + 0x40);
  uVar6 = uVar5 + param_3;
  if (uVar5 < *(uint *)(param_1 + 0xc)) {
    do {
      while (iVar4 = *piVar7, iVar4 != 0) {
        if (uVar6 <= *(uint *)(iVar4 + 0xc)) {
          *(uint *)((int)register0x00000038 + -0x18) = uVar5;
          goto loc_F008D274;
        }
        iVar2 = *(int *)((int)register0x00000038 + -0x14);
        if (uVar5 < *(uint *)(iVar4 + 0x10)) goto loc_F008D294;
        piVar7 = (int *)(iVar4 + 4);
      }
      *(uint *)((int)register0x00000038 + -0x18) = uVar5;
loc_F008D274:
      *(uint *)((int)register0x00000038 + -0x14) = uVar6 - uVar5;
      iVar2 = *(int *)((int)register0x00000038 + -0x14);
loc_F008D294:
      uVar3 = *(undefined4 *)((int)register0x00000038 + -0x18);
      if (iVar2 != 0) goto loc_F008D2B8;
      uVar5 = uVar5 + param_4;
      uVar6 = uVar6 + param_4;
    } while (uVar5 < *(uint *)(param_1 + 0xc));
  }
  uVar3 = *(undefined4 *)((int)register0x00000038 + -0x18);
loc_F008D2B8:
  *puVar1 = uVar3;
  puVar1[1] = *(undefined4 *)((int)register0x00000038 + -0x14);
  return CONCAT44(uVar5,puVar1);
}

