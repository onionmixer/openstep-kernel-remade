
/* WARNING: Removing unreachable block (ram,0xf0053368) */
/* WARNING: Removing unreachable block (ram,0xf0053320) */
/* WARNING: Removing unreachable block (ram,0xf0053394) */
/* WARNING: Removing unreachable block (ram,0xf0053344) */

undefined8 sub_F00532EC(uint *param_1,undefined4 param_2)

{
  uint uVar1;
  uint uVar2;
  word wVar3;
  undefined4 unaff_l0;
  uint uVar4;
  undefined4 unaff_l1;
  undefined4 uVar5;
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
  bool bVar6;
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
  uVar1 = param_1[0x10];
  (**(code **)(*(int *)(uVar1 + 0x1c) + 0x80))();
  bVar6 = (*param_1 & 1) == 0;
  if (bVar6) {
    uVar2 = param_1[9];
    uVar5 = *(undefined4 *)(param_1[0x10] + 0x30);
    uVar4 = param_1[8];
    .umul(uVar2,uVar1);
  }
  else {
    uVar2 = param_1[9];
    uVar5 = *(undefined4 *)(param_1[0x10] + 0x30);
    uVar4 = param_1[8];
    .umul(uVar2,uVar1);
  }
  wVar3 = (word)bVar6;
  _rdwri(wVar3,uVar5,uVar4,param_1[5],uVar2,1,(undefined *)((int)register0x00000038 + -0xc));
  *(word *)(param_1 + 7) = wVar3;
  param_1[10] = *(uint *)((int)register0x00000038 + -0xc);
  if (*(sword *)(param_1 + 7) != 0) {
    *param_1 = *param_1 | 4;
  }
  _biodone(param_1);
  return CONCAT44(param_2,param_1);
}
