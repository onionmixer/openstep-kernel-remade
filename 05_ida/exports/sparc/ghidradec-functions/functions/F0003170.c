
/* WARNING: Possible PIC construction at 0xf000342c: Changing call to branch */
/* WARNING: Removing unreachable block (ram,0xf000342c) */
/* WARNING: Removing unreachable block (ram,0xf0003348) */
/* WARNING: Removing unreachable block (ram,0xf00031c0) */
/* WARNING: Removing unreachable block (ram,0xf000338c) */
/* WARNING: Removing unreachable block (ram,0xf0003288) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void sys_trap(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
             undefined4 param_5,undefined4 param_6)

{
  undefined4 unaff_g1;
  undefined4 unaff_g2;
  uint uVar1;
  undefined4 unaff_g3;
  undefined4 unaff_g4;
  int unaff_g5;
  undefined4 unaff_g6;
  undefined4 unaff_g7;
  undefined4 in_o7;
  uint unaff_l0;
  undefined4 unaff_l1;
  undefined4 uVar2;
  undefined4 unaff_l2;
  undefined4 uVar3;
  uint uVar4;
  undefined4 uVar5;
  uint uVar6;
  uint unaff_l4;
  uint uVar7;
  undefined4 uVar8;
  int iVar9;
  byte bVar11;
  undefined4 uVar10;
  int iVar12;
  undefined4 unaff_i0;
  undefined4 unaff_i1;
  undefined4 unaff_i2;
  undefined4 unaff_i3;
  undefined4 unaff_i4;
  undefined4 unaff_i5;
  int unaff_fp;
  undefined *puVar13;
  undefined4 unaff_i7;
  undefined4 in_Y;
  undefined in_DECOMPILE_MODE;
  int in_TL;
  int in_CWP;
  undefined auStackX_0 [92];
  
  iVar12 = _active_pcb;
  iVar9 = __nwindows + -1;
  uVar7 = 1 << ((byte)unaff_l0 & 0x1f);
  uVar4 = *(uint *)((uint)(in_TL == 1) * 0x6000 + (uint)(in_TL == 2) * 0x6004 +
                    (uint)(in_TL == 3) * 0x6008 + (uint)(in_TL == 4) * 0x600c);
  bVar11 = (byte)iVar9;
  if ((unaff_l0 & 0x40) == 0) {
    *(undefined4 *)(_active_pcb + 0x244) = unaff_g1;
    *(qword *)(iVar12 + 0x248) = CONCAT44(unaff_g2,unaff_g3);
    *(qword *)(iVar12 + 0x250) = CONCAT44(unaff_g4,unaff_g5);
    *(qword *)(iVar12 + 600) = CONCAT44(unaff_g6,unaff_g7);
    *(undefined4 *)(iVar12 + 0x240) = in_Y;
    *(qword *)(iVar12 + 0x260) = CONCAT44(unaff_i0,unaff_i1);
    *(qword *)(iVar12 + 0x268) = CONCAT44(unaff_i2,unaff_i3);
    *(qword *)(iVar12 + 0x270) = CONCAT44(unaff_i4,unaff_i5);
    *(qword *)(iVar12 + 0x278) = CONCAT44(unaff_fp,unaff_i7);
    *(uint *)(iVar12 + 0x234) = unaff_l0;
    *(undefined4 *)(iVar12 + 0x238) = unaff_l1;
    *(undefined4 *)(iVar12 + 0x23c) = unaff_l2;
    if ((unaff_l4 & 0x200) != 0) {
      _mmu_getsyncflt();
    }
    iVar12 = *(int *)(iVar12 + 0x2a0);
    *(uint *)(iVar12 + 0x5c) = unaff_l0;
    *(undefined4 *)(_active_pcb + 0x230) = 0;
    unaff_g5 = _active_pcb;
    if ((uVar7 & uVar4) != 0) {
      uVar1 = (uVar7 ^ 0xffffffff) & ~(-2 << (bVar11 & 0x1f));
loc_F00033EC:
      uVar6 = uVar4 << (bVar11 & 0x1f);
      uVar4 = uVar6 | uVar4 >> 1;
      *(uint *)(_active_pcb + 0xc) = uVar1 & ~uVar4;
      if (!(bool)in_DECOMPILE_MODE) {
        *(undefined4 *)(in_CWP * 0x40 + 0x8000) = unaff_i0;
        *(undefined4 *)((in_CWP * 0x10 + 1) * 4 + 0x8000) = unaff_i1;
        *(undefined4 *)((in_CWP * 0x10 + 2) * 4 + 0x8000) = unaff_i2;
        *(undefined4 *)((in_CWP * 0x10 + 3) * 4 + 0x8000) = unaff_i3;
        *(undefined4 *)((in_CWP * 0x10 + 4) * 4 + 0x8000) = unaff_i4;
        *(undefined4 *)((in_CWP * 0x10 + 5) * 4 + 0x8000) = unaff_i5;
        *(int *)((in_CWP * 0x10 + 6) * 4 + 0x8000) = unaff_fp;
        *(undefined4 *)((in_CWP * 0x10 + 7) * 4 + 0x8000) = unaff_i7;
        *(uint *)((in_CWP * 0x10 + 8) * 4 + 0x8000) = unaff_l0;
        *(undefined4 *)((in_CWP * 0x10 + 9) * 4 + 0x8000) = unaff_l1;
        *(uint *)((in_CWP * 0x10 + 10) * 4 + 0x8000) = uVar6;
        *(uint *)((in_CWP * 0x10 + 0xb) * 4 + 0x8000) = uVar6;
        *(uint *)((in_CWP * 0x10 + 0xc) * 4 + 0x8000) = unaff_l4;
        *(uint *)((in_CWP * 0x10 + 0xd) * 4 + 0x8000) = uVar7;
        *(int *)((in_CWP * 0x10 + 0xe) * 4 + 0x8000) = iVar9;
        *(int *)((in_CWP * 0x10 + 0xf) * 4 + 0x8000) = iVar12;
      }
      *(uint *)((uint)(in_TL == 1) * 0x6000 + (uint)(in_TL == 2) * 0x6004 +
                (uint)(in_TL == 3) * 0x6008 + (uint)(in_TL == 4) * 0x600c) = uVar4;
      if ((((uint)register0x00000038 & 7) == 0) && (register0x00000038 < &dword_F0000000)) {
        return;
      }
      return;
    }
    uVar4 = uVar4 - uVar7;
    if ((int)uVar4 < 0) {
      uVar4 = uVar4 - 1;
    }
    *(uint *)(_active_pcb + 0xc) = uVar4 & ~uVar7 & ~(-2 << (bVar11 & 0x1f));
  }
  else {
    iVar12 = unaff_fp + -0xa8;
    *(undefined4 *)(unaff_fp + -0x3c) = unaff_g1;
    *(qword *)(unaff_fp + -0x38) = CONCAT44(unaff_g2,unaff_g3);
    *(qword *)(unaff_fp + -0x30) = CONCAT44(unaff_g4,unaff_g5);
    *(qword *)(unaff_fp + -0x28) = CONCAT44(unaff_g6,unaff_g7);
    *(undefined4 *)(unaff_fp + -0x40) = in_Y;
    if (((((unaff_l4 & 0x200) != 0) && (_mmu_getsyncflt(), _do_work_arounds != 0)) &&
        ((unaff_l4 & 2) != 0)) && ((uVar1 = unaff_l4 >> 2 & 0x1c, uVar1 == 8 || (uVar1 == 0xc)))) {
      *(qword *)(unaff_fp + -0x20) = CONCAT44(unaff_i0,unaff_i1);
      *(qword *)(unaff_fp + -0x18) = CONCAT44(unaff_i2,unaff_i3);
      *(qword *)(unaff_fp + -0x10) = CONCAT44(unaff_i4,unaff_i5);
      *(qword *)(unaff_fp + -8) = CONCAT44(unaff_fp,unaff_i7);
    }
    *(int *)(unaff_fp + -8) = unaff_fp;
    *(uint *)(unaff_fp + -0x4c) = unaff_l0;
    *(undefined4 *)(unaff_fp + -0x48) = unaff_l1;
    *(undefined4 *)(unaff_fp + -0x44) = unaff_l2;
    if ((uVar7 & uVar4) != 0) {
      uVar1 = *(uint *)(_active_pcb + 0xc);
      if (uVar1 != 0) goto loc_F00033EC;
      uVar1 = uVar4 << (bVar11 & 0x1f);
      uVar4 = uVar1 | uVar4 >> 1;
      unaff_g5 = _active_pcb;
      if (!(bool)in_DECOMPILE_MODE) {
        *(undefined4 *)(in_CWP * 0x40 + 0x8000) = unaff_i0;
        *(undefined4 *)((in_CWP * 0x10 + 1) * 4 + 0x8000) = unaff_i1;
        *(undefined4 *)((in_CWP * 0x10 + 2) * 4 + 0x8000) = unaff_i2;
        *(undefined4 *)((in_CWP * 0x10 + 3) * 4 + 0x8000) = unaff_i3;
        *(undefined4 *)((in_CWP * 0x10 + 4) * 4 + 0x8000) = unaff_i4;
        *(undefined4 *)((in_CWP * 0x10 + 5) * 4 + 0x8000) = unaff_i5;
        *(int *)((in_CWP * 0x10 + 6) * 4 + 0x8000) = unaff_fp;
        *(undefined4 *)((in_CWP * 0x10 + 7) * 4 + 0x8000) = unaff_i7;
        *(uint *)((in_CWP * 0x10 + 8) * 4 + 0x8000) = unaff_l0;
        *(undefined4 *)((in_CWP * 0x10 + 9) * 4 + 0x8000) = unaff_l1;
        *(uint *)((in_CWP * 0x10 + 10) * 4 + 0x8000) = uVar1;
        *(uint *)((in_CWP * 0x10 + 0xb) * 4 + 0x8000) = uVar1;
        *(uint *)((in_CWP * 0x10 + 0xc) * 4 + 0x8000) = unaff_l4;
        *(uint *)((in_CWP * 0x10 + 0xd) * 4 + 0x8000) = uVar7;
        *(int *)((in_CWP * 0x10 + 0xe) * 4 + 0x8000) = iVar9;
        *(int *)((in_CWP * 0x10 + 0xf) * 4 + 0x8000) = iVar12;
      }
      unaff_l0 = 0;
      uVar2 = 0;
      uVar3 = 0;
      uVar5 = 0;
      unaff_l4 = 0;
      uVar8 = 0;
      uVar10 = 0;
      iVar12 = 0;
      iVar9 = in_CWP + 1;
      puVar13 = (undefined *)register0x00000038;
      *(uint *)((uint)(in_TL == 1) * 0x6000 + (uint)(in_TL == 2) * 0x6004 +
                (uint)(in_TL == 3) * 0x6008 + (uint)(in_TL == 4) * 0x600c) = uVar4;
      *(qword *)register0x00000038 = CONCAT44(unaff_l0,uVar2);
      *(qword *)((int)register0x00000038 + 8) = CONCAT44(uVar3,uVar5);
      *(qword *)((int)register0x00000038 + 0x10) = CONCAT44(unaff_l4,uVar8);
      *(qword *)((int)register0x00000038 + 0x18) = CONCAT44(uVar10,iVar12);
      *(qword *)((int)register0x00000038 + 0x20) = CONCAT44(param_1,param_2);
      *(qword *)((int)register0x00000038 + 0x28) = CONCAT44(param_3,param_4);
      *(qword *)((int)register0x00000038 + 0x30) = CONCAT44(param_5,param_6);
      *(qword *)((int)register0x00000038 + 0x38) = CONCAT44(puVar13,in_o7);
      iVar9 = iVar9 + -1;
      if (!(bool)in_DECOMPILE_MODE) {
        unaff_l0 = *(uint *)((iVar9 * 0x10 + 8) * 4 + 0x8000);
        unaff_l4 = *(uint *)((iVar9 * 0x10 + 0xc) * 4 + 0x8000);
        iVar12 = *(int *)((iVar9 * 0x10 + 0xe) * 4 + 0x8000);
      }
    }
  }
  if ((unaff_l4 & 0x100) != 0) {
    return;
  }
  if (unaff_l4 == 0x80) {
    return;
  }
  if (unaff_l4 == 0x90) {
    return;
  }
  if ((unaff_l4 & 0x200) != 0) {
    fault();
    return;
  }
  if (unaff_l4 == 8) {
    return;
  }
  if (unaff_l4 == 4) {
    return;
  }
  if (unaff_l4 == 0x83) {
    _flush_user_windows();
    *(int *)(unaff_g5 + 0x238) = *(int *)(unaff_g5 + 0x23c);
    *(int *)(unaff_g5 + 0x23c) = *(int *)(unaff_g5 + 0x23c) + 4;
    sys_rtt();
    return;
  }
  if ((unaff_l0 & 0x40) == 0) {
    iVar12 = _active_pcb + 0x234;
  }
  else {
    iVar12 = iVar12 + 0x5c;
  }
  _trap(unaff_l4,iVar12,0,0,0);
  sys_rtt();
  return;
}
