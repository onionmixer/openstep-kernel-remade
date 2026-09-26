
undefined8 _installed_top_size(undefined8 *param_1,uint *param_2,int *param_3)

{
  int iVar1;
  undefined8 *puVar2;
  uint uVar3;
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
  uint *puVar6;
  undefined4 unaff_i2;
  undefined4 unaff_i3;
  int iVar7;
  undefined8 in_i4_5;
  uint uVar8;
  undefined4 unaff_fp;
  undefined4 unaff_i7;
  bool in_DECOMPILE_MODE;
  int in_CWP;
  
  if (!in_DECOMPILE_MODE) {
    *(undefined4 *)(in_CWP * 0x40 + 0x8000) = unaff_i0;
    *(undefined4 *)((in_CWP * 0x10 + 1) * 4 + 0x8000) = unaff_i1;
    *(undefined4 *)((in_CWP * 0x10 + 2) * 4 + 0x8000) = unaff_i2;
    *(undefined4 *)((in_CWP * 0x10 + 3) * 4 + 0x8000) = unaff_i3;
    *(int *)((in_CWP * 0x10 + 4) * 4 + 0x8000) = (int)((qword)in_i4_5 >> 0x20);
    *(int *)((in_CWP * 0x10 + 5) * 4 + 0x8000) = (int)in_i4_5;
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
  uVar3 = 0;
  iVar4 = 0;
  puVar6 = param_2;
  for (puVar2 = param_1; puVar2 != (undefined8 *)0x0; puVar2 = *(undefined8 **)(puVar2 + 2)) {
    uVar5 = (uint)*puVar2;
    uVar8 = (uint)puVar2[1];
    iVar1 = uVar5 + uVar8;
    iVar7 = (int)((qword)puVar2[1] >> 0x20);
    uVar5 = ((int)((qword)*puVar2 >> 0x20) + iVar7 + (uint)CARRY4(uVar5,uVar8) + -1 +
            (uint)(iVar1 != 0)) * 0x100000 | iVar1 - 1U >> 0xc;
    if ((int)uVar3 < (int)uVar5) {
      uVar3 = uVar5;
    }
    puVar6 = (uint *)(iVar7 << 0x14);
    param_1 = (undefined8 *)(uVar8 >> 0xc);
    iVar4 = iVar4 + ((uint)puVar6 | (uint)param_1);
  }
  *param_2 = uVar3;
  *param_3 = iVar4;
  return CONCAT44(puVar6,param_1);
}

