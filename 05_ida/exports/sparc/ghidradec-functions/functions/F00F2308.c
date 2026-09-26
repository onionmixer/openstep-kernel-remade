
/* WARNING: Removing unreachable block (ram,0xf00f2360) */

undefined8 sub_F00F2308(int param_1,undefined4 param_2)

{
  int iVar1;
  uint uVar2;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  uint uVar3;
  undefined4 unaff_l3;
  int iVar4;
  undefined4 unaff_l4;
  uint uVar5;
  undefined4 unaff_l5;
  int iVar6;
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
  iVar6 = *(int *)(param_1 + 4);
  uVar3 = 0;
  while (uVar3 < *(uint *)(param_1 + 8)) {
    iVar1 = *(int *)(iVar6 + uVar3 * 0x10 + 0xc);
    if (iVar1 == 0) {
      uVar3 = uVar3 + 1;
    }
    else {
      uVar2 = (uint)*(word *)(iVar1 + 8);
      uVar5 = uVar2 + *(word *)(iVar1 + 10);
      if (uVar2 < uVar5) {
        iVar4 = iVar6 + uVar3 * 0x10;
        iVar1 = *(int *)(iVar4 + 0xc);
        while( true ) {
          sub_F00F223C(*(undefined4 *)(uVar2 * 4 + iVar1 + 0xc),
                       *(undefined4 *)(iVar6 + uVar3 * 0x10));
          uVar2 = uVar2 + 1;
          if (uVar5 <= uVar2) break;
          iVar1 = *(int *)(iVar4 + 0xc);
        }
        uVar3 = uVar3 + 1;
      }
      else {
        uVar3 = uVar3 + 1;
      }
    }
  }
  return CONCAT44(param_2,param_1);
}
