
/* WARNING: Removing unreachable block (ram,0xf00a5c88) */
/* WARNING: Removing unreachable block (ram,0xf00a5cdc) */
/* WARNING: Removing unreachable block (ram,0xf00a5c44) */

undefined8 _flush_user_windows_to_stack(int param_1,undefined4 param_2)

{
  int iVar1;
  int iVar2;
  int iVar3;
  undefined4 unaff_l0;
  int iVar4;
  undefined4 unaff_l1;
  int iVar5;
  int iVar6;
  undefined4 unaff_l3;
  int iVar7;
  undefined4 unaff_l4;
  int iVar8;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  int iVar9;
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
  iVar7 = *(int *)(_active_threads + 0x28);
  _flush_user_windows();
  iVar8 = *(int *)(iVar7 + 0x230);
  if (0 < iVar8) {
    param_1 = iVar8 * 0x40 + -0x30;
    iVar9 = iVar8 * 4 + iVar7;
    while( true ) {
      iVar8 = iVar8 + -1;
      if ((*(uint *)(iVar9 + 0x20c) & 7) == 0) {
        iVar1 = iVar7 + param_1;
        _copyout(iVar1,*(uint *)(iVar9 + 0x20c),0x40);
        if ((iVar1 == 0) &&
           (iVar1 = *(int *)(iVar7 + 0x230) + -1, *(int *)(iVar7 + 0x230) = iVar1, iVar8 < iVar1)) {
          iVar6 = iVar8 * 0x40 + 0x10;
          iVar5 = iVar8 * 0x40 + 0x50;
          iVar4 = iVar8 * 4 + iVar7;
          iVar1 = iVar8;
          do {
            iVar2 = iVar7 + iVar5;
            iVar3 = iVar7 + iVar6;
            iVar6 = iVar6 + 0x40;
            iVar5 = iVar5 + 0x40;
            iVar1 = iVar1 + 1;
            *(undefined4 *)(iVar4 + 0x210) = *(undefined4 *)(iVar4 + 0x214);
            _bcopy(iVar2,iVar3,0x40);
            iVar4 = iVar4 + 4;
          } while (iVar1 < *(int *)(iVar7 + 0x230));
        }
      }
      if (iVar8 < 1) break;
      param_1 = param_1 + -0x40;
      iVar9 = iVar9 + -4;
    }
  }
  return CONCAT44(param_2,param_1);
}

