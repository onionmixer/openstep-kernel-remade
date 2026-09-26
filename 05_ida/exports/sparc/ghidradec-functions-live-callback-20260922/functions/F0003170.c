
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
  undefined (*pauVar1) [676];
  undefined4 unaff_g1;
  undefined4 unaff_g2;
  uint uVar2;
  undefined4 unaff_g3;
  undefined4 unaff_g4;
  undefined (*unaff_g5) [676];
  undefined4 unaff_g6;
  undefined4 unaff_g7;
  undefined *puVar3;
  undefined4 in_o7;
  uint unaff_l0;
  undefined4 unaff_l1;
  undefined4 uVar4;
  undefined4 unaff_l2;
  undefined4 uVar5;
  uint uVar6;
  undefined4 uVar7;
  uint uVar8;
  uint unaff_l4;
  uint uVar9;
  undefined4 uVar10;
  int iVar11;
  byte bVar13;
  undefined4 uVar12;
  int iVar14;
  undefined4 unaff_i0;
  undefined4 unaff_i1;
  undefined4 unaff_i2;
  undefined4 unaff_i3;
  undefined4 unaff_i4;
  undefined4 unaff_i5;
  int unaff_fp;
  undefined4 unaff_i7;
  undefined4 in_Y;
  undefined in_DECOMPILE_MODE;
  int in_TL;
  int in_CWP;
  undefined auStackX_0 [92];
  
  pauVar1 = _active_pcb;
  iVar11 = __nwindows + -1;
  uVar9 = 1 << ((byte)unaff_l0 & 0x1f);
  uVar6 = *(uint *)((uint)(in_TL == 1) * 0x6000 + (uint)(in_TL == 2) * 0x6004 +
                    (uint)(in_TL == 3) * 0x6008 + (uint)(in_TL == 4) * 0x600c);
  bVar13 = (byte)iVar11;
  if ((unaff_l0 & 0x40) == 0) {
    *(undefined4 *)(*_active_pcb + 0x244) = unaff_g1;
    *(qword *)(*pauVar1 + 0x248) = CONCAT44(unaff_g2,unaff_g3);
    *(qword *)(*pauVar1 + 0x250) = CONCAT44(unaff_g4,unaff_g5);
    *(qword *)(*pauVar1 + 600) = CONCAT44(unaff_g6,unaff_g7);
    *(undefined4 *)(*pauVar1 + 0x240) = in_Y;
    *(qword *)(*pauVar1 + 0x260) = CONCAT44(unaff_i0,unaff_i1);
    *(qword *)(*pauVar1 + 0x268) = CONCAT44(unaff_i2,unaff_i3);
    *(qword *)(*pauVar1 + 0x270) = CONCAT44(unaff_i4,unaff_i5);
    *(qword *)(*pauVar1 + 0x278) = CONCAT44(unaff_fp,unaff_i7);
    *(uint *)(*pauVar1 + 0x234) = unaff_l0;
    *(undefined4 *)(*pauVar1 + 0x238) = unaff_l1;
    *(undefined4 *)(*pauVar1 + 0x23c) = unaff_l2;
    if ((unaff_l4 & 0x200) != 0) {
      _mmu_getsyncflt();
    }
    iVar14 = *(int *)(*pauVar1 + 0x2a0);
    *(uint *)(iVar14 + 0x5c) = unaff_l0;
    *(undefined4 *)(*_active_pcb + 0x230) = 0;
    unaff_g5 = _active_pcb;
    if ((uVar9 & uVar6) != 0) {
      uVar2 = (uVar9 ^ 0xffffffff) & ~(-2 << (bVar13 & 0x1f));
loc_F00033EC:
      uVar8 = uVar6 << (bVar13 & 0x1f);
      uVar6 = uVar8 | uVar6 >> 1;
      *(uint *)(*_active_pcb + 0xc) = uVar2 & ~uVar6;
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
        *(uint *)((in_CWP * 0x10 + 10) * 4 + 0x8000) = uVar8;
        *(uint *)((in_CWP * 0x10 + 0xb) * 4 + 0x8000) = uVar8;
        *(uint *)((in_CWP * 0x10 + 0xc) * 4 + 0x8000) = unaff_l4;
        *(uint *)((in_CWP * 0x10 + 0xd) * 4 + 0x8000) = uVar9;
        *(int *)((in_CWP * 0x10 + 0xe) * 4 + 0x8000) = iVar11;
        *(int *)((in_CWP * 0x10 + 0xf) * 4 + 0x8000) = iVar14;
      }
      *(uint *)((uint)(in_TL == 1) * 0x6000 + (uint)(in_TL == 2) * 0x6004 +
                (uint)(in_TL == 3) * 0x6008 + (uint)(in_TL == 4) * 0x600c) = uVar6;
      if ((((uint)register0x00000038 & 7) == 0) && (register0x00000038 < &dword_F0000000)) {
        return;
      }
      return;
    }
    uVar6 = uVar6 - uVar9;
    if ((int)uVar6 < 0) {
      uVar6 = uVar6 - 1;
    }
    *(uint *)(*_active_pcb + 0xc) = uVar6 & ~uVar9 & ~(-2 << (bVar13 & 0x1f));
  }
  else {
    iVar14 = unaff_fp + -0xa8;
    *(undefined4 *)(unaff_fp + -0x3c) = unaff_g1;
    *(qword *)(unaff_fp + -0x38) = CONCAT44(unaff_g2,unaff_g3);
    *(qword *)(unaff_fp + -0x30) = CONCAT44(unaff_g4,unaff_g5);
    *(qword *)(unaff_fp + -0x28) = CONCAT44(unaff_g6,unaff_g7);
    *(undefined4 *)(unaff_fp + -0x40) = in_Y;
    if (((((unaff_l4 & 0x200) != 0) && (_mmu_getsyncflt(), _do_work_arounds != 0)) &&
        ((unaff_l4 & 2) != 0)) && ((uVar2 = unaff_l4 >> 2 & 0x1c, uVar2 == 8 || (uVar2 == 0xc)))) {
      *(qword *)(unaff_fp + -0x20) = CONCAT44(unaff_i0,unaff_i1);
      *(qword *)(unaff_fp + -0x18) = CONCAT44(unaff_i2,unaff_i3);
      *(qword *)(unaff_fp + -0x10) = CONCAT44(unaff_i4,unaff_i5);
      *(qword *)(unaff_fp + -8) = CONCAT44(unaff_fp,unaff_i7);
    }
    *(int *)(unaff_fp + -8) = unaff_fp;
    *(uint *)(unaff_fp + -0x4c) = unaff_l0;
    *(undefined4 *)(unaff_fp + -0x48) = unaff_l1;
    *(undefined4 *)(unaff_fp + -0x44) = unaff_l2;
    if ((uVar9 & uVar6) != 0) {
      uVar2 = *(uint *)(*_active_pcb + 0xc);
      if (uVar2 != 0) goto loc_F00033EC;
      uVar2 = uVar6 << (bVar13 & 0x1f);
      uVar6 = uVar2 | uVar6 >> 1;
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
        *(uint *)((in_CWP * 0x10 + 10) * 4 + 0x8000) = uVar2;
        *(uint *)((in_CWP * 0x10 + 0xb) * 4 + 0x8000) = uVar2;
        *(uint *)((in_CWP * 0x10 + 0xc) * 4 + 0x8000) = unaff_l4;
        *(uint *)((in_CWP * 0x10 + 0xd) * 4 + 0x8000) = uVar9;
        *(int *)((in_CWP * 0x10 + 0xe) * 4 + 0x8000) = iVar11;
        *(int *)((in_CWP * 0x10 + 0xf) * 4 + 0x8000) = iVar14;
      }
      unaff_l0 = 0;
      uVar4 = 0;
      uVar5 = 0;
      uVar7 = 0;
      unaff_l4 = 0;
      uVar10 = 0;
      uVar12 = 0;
      iVar14 = 0;
      iVar11 = in_CWP + 1;
      puVar3 = (undefined *)register0x00000038;
      *(uint *)((uint)(in_TL == 1) * 0x6000 + (uint)(in_TL == 2) * 0x6004 +
                (uint)(in_TL == 3) * 0x6008 + (uint)(in_TL == 4) * 0x600c) = uVar6;
      *(qword *)register0x00000038 = CONCAT44(unaff_l0,uVar4);
      *(qword *)((int)register0x00000038 + 8) = CONCAT44(uVar5,uVar7);
      *(qword *)((int)register0x00000038 + 0x10) = CONCAT44(unaff_l4,uVar10);
      *(qword *)((int)register0x00000038 + 0x18) = CONCAT44(uVar12,iVar14);
      *(qword *)((int)register0x00000038 + 0x20) = CONCAT44(param_1,param_2);
      *(qword *)((int)register0x00000038 + 0x28) = CONCAT44(param_3,param_4);
      *(qword *)((int)register0x00000038 + 0x30) = CONCAT44(param_5,param_6);
      *(qword *)((int)register0x00000038 + 0x38) = CONCAT44(puVar3,in_o7);
      iVar11 = iVar11 + -1;
      if (!(bool)in_DECOMPILE_MODE) {
        unaff_l0 = *(uint *)((iVar11 * 0x10 + 8) * 4 + 0x8000);
        unaff_l4 = *(uint *)((iVar11 * 0x10 + 0xc) * 4 + 0x8000);
        iVar14 = *(int *)((iVar11 * 0x10 + 0xe) * 4 + 0x8000);
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
    *(int *)(*unaff_g5 + 0x238) = *(int *)(*unaff_g5 + 0x23c);
    *(int *)(*unaff_g5 + 0x23c) = *(int *)(*unaff_g5 + 0x23c) + 4;
    sys_rtt();
    return;
  }
  if ((unaff_l0 & 0x40) == 0) {
    puVar3 = *_active_pcb + 0x234;
  }
  else {
    puVar3 = (undefined *)(iVar14 + 0x5c);
  }
  _trap(unaff_l4,puVar3,0,0,0);
  sys_rtt();
  return;
}

