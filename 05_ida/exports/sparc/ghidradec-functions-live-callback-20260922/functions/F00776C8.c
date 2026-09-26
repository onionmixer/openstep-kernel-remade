
/* WARNING: Removing unreachable block (ram,0xf0077878) */
/* WARNING: Removing unreachable block (ram,0xf00778b0) */
/* WARNING: Removing unreachable block (ram,0xf0077708) */
/* WARNING: Removing unreachable block (ram,0xf00776e4) */
/* WARNING: Removing unreachable block (ram,0xf00777b8) */
/* WARNING: Removing unreachable block (ram,0xf007785c) */
/* WARNING: Removing unreachable block (ram,0xf0077890) */
/* WARNING: Removing unreachable block (ram,0xf00776cc) */

undefined8 sub_F00776C8(undefined4 param_1,uint param_2)

{
  bool bVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  undefined4 *puVar5;
  uint uVar6;
  int *piVar7;
  int iVar8;
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
  uVar2 = 1;
  uVar6 = param_2;
  _clock_value();
  *(undefined **)((int)register0x00000038 + -0xc) = (undefined *)((int)register0x00000038 + -0x10);
  *(undefined **)((int)register0x00000038 + -0x10) = (undefined *)((int)register0x00000038 + -0x10);
  uVar3 = uVar2;
  _splusclock();
  do {
    do {
    } while (dword_F0130F20 != 0);
    puVar5 = &dword_F0130F20;
    _simple_lock_try();
  } while (puVar5 == (undefined4 *)0x0);
  if ((int **)dword_F0130F34 != &dword_F0130F34) {
    uVar4 = dword_F0130F34[6];
    while (piVar7 = dword_F0130F34, uVar4 <= uVar2) {
      if (uVar4 == uVar2) {
        if (uVar6 < (uint)dword_F0130F34[7]) break;
        iVar8 = *dword_F0130F34;
      }
      else {
        iVar8 = *dword_F0130F34;
      }
      *(int *)(iVar8 + 4) = dword_F0130F34[1];
      *(int *)piVar7[1] = *piVar7;
      piVar7[8] = 0;
      *piVar7 = (int)((int)register0x00000038 + -0x10);
      puVar5 = *(undefined4 **)((int)register0x00000038 + -0xc);
      piVar7[1] = (int)puVar5;
      *puVar5 = piVar7;
      *(int **)((int)register0x00000038 + -0xc) = piVar7;
      if ((int **)dword_F0130F34 == &dword_F0130F34) break;
      uVar4 = dword_F0130F34[6];
    }
  }
  if ((int **)dword_F0130F34 != &dword_F0130F34) {
    sub_F007673C(dword_F0130F34);
  }
  piVar7 = *(int **)((int)register0x00000038 + -0x10);
  while( true ) {
    if (piVar7 == (int *)((int)register0x00000038 + -0x10)) {
      piVar7 = (int *)0x0;
    }
    else {
      *(int **)(*piVar7 + 4) = (int *)((int)register0x00000038 + -0x10);
      *(int *)((int)register0x00000038 + -0x10) = *piVar7;
    }
    if (piVar7 == (int *)0x0) break;
    *piVar7 = (int)&dword_F0130F2C;
    piVar7[1] = (int)DAT_f0130f30;
    *DAT_f0130f30 = (int)piVar7;
    iVar8 = dword_F0130F3C + 1;
    DAT_f0130f30 = piVar7;
    dword_F0130F3C = iVar8;
    piVar7[8] = 1;
    dword_F0130F20 = 0;
    bVar1 = dword_F0130F44 < dword_F0130F40 + iVar8;
    _thread_wakeup_prim(&dword_F0130F3C,1,0);
    if (bVar1) {
      _thread_wakeup_prim(&dword_F0130F44,1,0);
    }
    do {
      do {
      } while (dword_F0130F20 != 0);
      puVar5 = &dword_F0130F20;
      _simple_lock_try();
      piVar7 = *(int **)((int)register0x00000038 + -0x10);
    } while (puVar5 == (undefined4 *)0x0);
  }
  dword_F0130F20 = 0;
  _splx(uVar3,1);
  return CONCAT44(param_2,param_1);
}

