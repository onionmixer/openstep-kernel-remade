
/* WARNING: Removing unreachable block (ram,0xf0006f04) */
/* WARNING: Removing unreachable block (ram,0xf0006ed8) */

undefined8 sub_F0006E98(uint param_1,uint param_2,uint param_3,uint param_4)

{
  bool bVar1;
  uint uVar2;
  undefined4 unaff_l0;
  uint uVar3;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  uint uVar4;
  undefined4 unaff_l4;
  int iVar5;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  undefined4 unaff_i1;
  uint uVar6;
  undefined4 unaff_i2;
  undefined4 unaff_i3;
  undefined4 unaff_i4;
  undefined4 unaff_i5;
  undefined4 unaff_fp;
  undefined4 unaff_i7;
  bool bVar7;
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
  uVar4 = param_3 ^ param_2;
  if (((int)(param_3 | param_2) < 0) &&
     ((-1 < (int)param_3 || (param_3 = -param_3, (int)param_2 < 0)))) {
    bVar7 = param_1 != 0;
    param_1 = -param_1;
    param_2 = -(uint)bVar7 - param_2;
  }
  if (param_2 < param_3) {
    uVar6 = 0;
    param_4 = param_2;
  }
  else {
    udiv(param_2,param_3);
    uVar6 = param_2;
    if ((int)param_4 < 0) {
      param_4 = param_4 + param_3;
    }
  }
  if (param_4 == 0) {
    udiv(param_1,param_3);
    uVar3 = param_1;
  }
  else {
    uVar3 = 0;
    bVar7 = CARRY4(param_1,param_1);
    iVar5 = 0x20;
    while( true ) {
      param_1 = param_1 * 2;
      uVar2 = param_4 * 2;
      bVar1 = CARRY4(param_4,param_4);
      param_4 = param_4 * 2 + (uint)bVar7;
      uVar3 = uVar3 * 2;
      if ((bVar1 || CARRY4(uVar2,(uint)bVar7)) || (param_3 <= param_4)) {
        param_4 = param_4 - param_3;
        uVar3 = uVar3 + 1;
      }
      if (iVar5 < 2) break;
      bVar7 = CARRY4(param_1,param_1);
      iVar5 = iVar5 + -1;
    }
  }
  if ((int)uVar4 < 0) {
    bVar7 = uVar3 != 0;
    uVar3 = -uVar3;
    uVar6 = -(uint)bVar7 - uVar6;
  }
  return CONCAT44(uVar6,uVar3);
}

