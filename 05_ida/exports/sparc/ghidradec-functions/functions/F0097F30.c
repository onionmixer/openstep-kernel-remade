
/* WARNING: Removing unreachable block (ram,0xf0097fb0) */
/* WARNING: Removing unreachable block (ram,0xf0097f50) */

undefined8 _copyoutstr(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  undefined *puVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  int *piVar6;
  int iVar7;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
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
  *(undefined4 *)((int)register0x00000038 + 0x44) = param_1;
  *(undefined4 *)((int)register0x00000038 + 0x48) = param_2;
  *(undefined4 *)((int)register0x00000038 + 0x4c) = param_3;
  *(undefined4 *)((int)register0x00000038 + 0x50) = param_4;
  *(undefined4 *)((int)register0x00000038 + -0x18) = param_3;
  *(undefined4 *)((int)register0x00000038 + -0x1c) = param_2;
  *(undefined4 *)((int)register0x00000038 + -0x28) = 0;
  puVar1 = (undefined *)((int)register0x00000038 + -0x10);
  _setjmp();
  if (puVar1 == (undefined *)0x0) {
    *(undefined **)(_active_threads + 0x74) = (undefined *)((int)register0x00000038 + -0x10);
    uVar5 = *(uint *)((int)register0x00000038 + -0x18);
    while( true ) {
      uVar4 = _page_size - (*(uint *)((int)register0x00000038 + 0x48) & _page_size - 1U);
      *(uint *)((int)register0x00000038 + -0x14) = uVar5;
      if (uVar4 < uVar5) {
        *(uint *)((int)register0x00000038 + -0x14) = uVar4;
      }
      iVar2 = *(int *)((int)register0x00000038 + 0x44);
      _lbcopytoz(iVar2,*(uint *)((int)register0x00000038 + 0x48),
                 *(undefined4 *)((int)register0x00000038 + -0x14));
      iVar3 = *(int *)((int)register0x00000038 + -0x18);
      iVar7 = *(int *)((int)register0x00000038 + 0x48);
      *(int *)((int)register0x00000038 + -0x20) = iVar2;
      *(int *)((int)register0x00000038 + -0x18) = iVar3 - iVar2;
      *(int *)((int)register0x00000038 + 0x44) = *(int *)((int)register0x00000038 + 0x44) + iVar2;
      *(int *)((int)register0x00000038 + 0x48) = iVar7 + iVar2;
      if ((iVar2 != *(int *)((int)register0x00000038 + -0x14)) || (iVar3 - iVar2 == 0)) break;
      uVar5 = *(uint *)((int)register0x00000038 + -0x18);
    }
    *(undefined *)(iVar7 + iVar2) = 0;
    *(int *)((int)register0x00000038 + 0x48) = *(int *)((int)register0x00000038 + 0x48) + 1;
    *(undefined4 *)(_active_threads + 0x74) = 0;
  }
  else {
    *(undefined4 *)((int)register0x00000038 + -0x28) = 0xe;
  }
  piVar6 = *(int **)((int)register0x00000038 + 0x50);
  if (*(int *)((int)register0x00000038 + -0x18) == 0) {
    *(undefined4 *)((int)register0x00000038 + -0x28) = 2;
    piVar6 = *(int **)((int)register0x00000038 + 0x50);
  }
  if (piVar6 != (int *)0x0) {
    *piVar6 = *(int *)((int)register0x00000038 + 0x48) - *(int *)((int)register0x00000038 + -0x1c);
  }
  return CONCAT44(param_2,*(undefined4 *)((int)register0x00000038 + -0x28));
}
