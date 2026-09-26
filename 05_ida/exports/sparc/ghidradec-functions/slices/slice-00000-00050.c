/* GHIDRADEC_FUNCTION index=0 start=0xf0003000 */

void _zeros(void)

{
  code *pcVar1;
  
                    /* WARNING: Does not return */
  pcVar1 = (code *)IllegalInstructionTrap(0);
  (*pcVar1)();
}
/* GHIDRADEC_FUNCTION index=1 start=0xf0003020 */

void _trapinfo(void)

{
  code *pcVar1;
  
                    /* WARNING: Does not return */
  pcVar1 = (code *)IllegalInstructionTrap(0);
  (*pcVar1)();
}
/* GHIDRADEC_FUNCTION index=2 start=0xf0003030 */

void _romp(void)

{
  code *pcVar1;
  
                    /* WARNING: Does not return */
  pcVar1 = (code *)IllegalInstructionTrap(0);
  (*pcVar1)();
}
/* GHIDRADEC_FUNCTION index=3 start=0xf0003034 */

void _dvec(void)

{
  code *pcVar1;
  
                    /* WARNING: Does not return */
  pcVar1 = (code *)IllegalInstructionTrap(0);
  (*pcVar1)();
}
/* GHIDRADEC_FUNCTION index=4 start=0xf0003038 */

void _bootops(void)

{
  code *pcVar1;
  
                    /* WARNING: Does not return */
  pcVar1 = (code *)IllegalInstructionTrap(0);
  (*pcVar1)();
}
/* GHIDRADEC_FUNCTION index=5 start=0xf000303c */

void _nwindows(void)

{
  code *pcVar1;
  
                    /* WARNING: Does not return */
  pcVar1 = (code *)IllegalInstructionTrap(8);
  (*pcVar1)();
}
/* GHIDRADEC_FUNCTION index=6 start=0xf0003040 */

/* WARNING: This function may have set the stack pointer */
/* WARNING: Removing unreachable block (ram,0xf000312c) */
/* WARNING: Removing unreachable block (ram,0xf0003118) */
/* WARNING: Removing unreachable block (ram,0xf0003134) */
/* WARNING: Removing unreachable block (ram,0xf0003110) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void entry(undefined4 param_1,undefined4 param_2)

{
  undefined4 *puVar1;
  uint uVar2;
  code *pcVar3;
  undefined8 in_o2_3;
  undefined8 uVar4;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  uint uVar5;
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
  undefined in_DECOMPILE_MODE;
  int in_TL;
  int in_CWP;
  
  __bootops = (undefined4)((qword)in_o2_3 >> 0x20);
  *(undefined4 *)
   ((uint)(in_TL == 1) * 0x6000 + (uint)(in_TL == 2) * 0x6004 + (uint)(in_TL == 3) * 0x6008 +
   (uint)(in_TL == 4) * 0x600c) = 2;
  pcVar3 = _start;
  DAT_f0002008 = 0x81c4e170a8102000;
  __start = 0xa1480000273c000c;
                    /* WARNING: Read-only address (ram,0xf0002008) is written */
  *(undefined4 *)
   ((uint)(in_TL == 1) * 0x6000 + (uint)(in_TL == 2) * 0x6004 + (uint)(in_TL == 3) * 0x6008 +
   (uint)(in_TL == 4) * 0x600c) = 0;
  if (!(bool)in_DECOMPILE_MODE) {
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
  uVar5 = 0;
  uVar2 = *(uint *)((uint)(in_TL == 1) * 0x7000 + (uint)(in_TL == 2) * 0x7004 +
                    (uint)(in_TL == 3) * 0x7008 + (uint)(in_TL == 4) * 0x700c) & 0x1f;
  if (!(bool)in_DECOMPILE_MODE) {
    uVar5 = *(uint *)((in_CWP * 0x10 + 0xc) * 4 + 0x8000);
  }
  *(undefined4 *)
   ((uint)(in_TL == 1) * 0x6000 + (uint)(in_TL == 2) * 0x6004 + (uint)(in_TL == 3) * 0x6008 +
   (uint)(in_TL == 4) * 0x600c) = 2;
  __nwindows = uVar2 + 1;
  uVar5 = uVar5 & 0xfffff000;
  _mon_clock14_vec._0_8_ = *(undefined8 *)(uVar5 + 0x1e0);
  _mon_clock14_vec._8_8_ = *(undefined8 *)(uVar5 + 0x1e8);
  uRamf00051c8 = *(undefined8 *)(uVar5 + 0xff0);
  uVar4 = *(undefined8 *)(uVar5 + 0xff8);
                    /* WARNING: Read-only address (ram,0xf00051d0) is written */
  __romp = param_1;
  __dvec = param_2;
  uRamf00051d0 = uVar4;
  *(undefined8 *)(pcVar3 + 0xff0) = uRamf00051c8;
  *(undefined8 *)(pcVar3 + 0xff8) = uVar4;
  *(code **)((uint)(in_TL == 1) * 0x7000 + (uint)(in_TL == 2) * 0x7004 + (uint)(in_TL == 3) * 0x7008
            + (uint)(in_TL == 4) * 0x700c) = pcVar3;
  puVar1 = (undefined4 *)segment(4);
  _module_setup(*puVar1);
  _sparc_init();
  uRamfeff8008 = 0xffffffff;
  _setup_main();
  _start_initial_context();
  do {
                    /* WARNING: Do nothing block with infinite loop */
  } while( true );
}
/* GHIDRADEC_FUNCTION index=7 start=0xf0003144 */

/* WARNING: Removing unreachable block (ram,0xf000314c) */
/* WARNING: Removing unreachable block (ram,0xf0003144) */

void _return_with_state(void)

{
  _flush_user_windows();
  _reset_windows();
  *(undefined4 *)(*(int *)(*_active_pcb + 0x2a0) + 0x5c) = *(undefined4 *)(*_active_pcb + 0x234);
  sys_rtt();
  return;
}
/* GHIDRADEC_FUNCTION index=8 start=0xf0003170 */

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
/* GHIDRADEC_FUNCTION index=9 start=0xf0003434 */

void st_chk_flt(void)

{
  int iVar1;
  uint unaff_g1;
  uint uVar2;
  int iVar3;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  undefined4 unaff_l2;
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
  undefined auStackX_0 [92];
  
  iVar1 = _active_pcb;
  if ((unaff_g1 & 2) == 0) {
    func_0xf00032f8();
    return;
  }
  uVar2 = *(uint *)(_active_pcb + 0x230);
  *(BADSPACEBASE **)(uVar2 * 4 + _active_pcb + 0x210) = register0x00000038;
  iVar3 = uVar2 * 0x40 + iVar1;
  *(qword *)(iVar3 + 0x10) = CONCAT44(unaff_l0,unaff_l1);
  *(qword *)(iVar3 + 0x18) = CONCAT44(unaff_l2,unaff_l3);
  *(qword *)(iVar3 + 0x20) = CONCAT44(unaff_l4,unaff_l5);
  *(qword *)(iVar3 + 0x28) = CONCAT44(unaff_l6,unaff_l7);
  *(qword *)(iVar3 + 0x30) = CONCAT44(unaff_i0,unaff_i1);
  *(qword *)(iVar3 + 0x38) = CONCAT44(unaff_i2,unaff_i3);
  *(qword *)(iVar3 + 0x40) = CONCAT44(unaff_i4,unaff_i5);
  *(qword *)(iVar3 + 0x48) = CONCAT44(unaff_fp,unaff_i7);
  *(uint *)(iVar1 + 0x230) = (uVar2 & 0x3ffffff) + 1;
  func_0xf00032f8();
  return;
}
/* GHIDRADEC_FUNCTION index=10 start=0xf00034a0 */

/* WARNING: Control flow encountered unimplemented instructions */
/* WARNING: Removing unreachable block (ram,0xf00035a8) */
/* WARNING: Removing unreachable block (ram,0xf0003500) */
/* WARNING: Removing unreachable block (ram,0xf0003538) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void sys_rtt(void)

{
  byte bVar1;
  uint uVar2;
  uint uVar3;
  undefined8 uVar4;
  undefined4 uVar5;
  undefined8 uVar6;
  undefined8 uVar7;
  undefined8 in_i0_1;
  undefined8 uVar8;
  undefined8 in_i2_3;
  undefined8 uVar9;
  undefined8 in_i4_5;
  undefined8 uVar10;
  undefined8 *puVar11;
  qword in_fp_7;
  undefined8 uVar12;
  undefined in_DECOMPILE_MODE;
  int in_TL;
  int in_CWP;
  int iVar13;
  undefined auStackX_0 [92];
  
  while( true ) {
    while( true ) {
      while( true ) {
        uVar3 = *(uint *)((int)register0x00000038 + 0x5c);
        bVar1 = (byte)__nwindows;
        if ((uVar3 & 0x40) != 0) {
          uVar4 = CONCAT44(*(undefined4 *)((int)register0x00000038 + 0xa0),(int)in_fp_7);
          if (((*(uint *)((uint)(in_TL == 1) * 0x7000 + (uint)(in_TL == 2) * 0x7004 +
                          (uint)(in_TL == 3) * 0x7008 + (uint)(in_TL == 4) * 0x700c) ^ uVar3) & 0x1f
              ) == 0) {
            uVar3 = 2 << ((byte)uVar3 & 0x1f);
            uVar2 = *(uint *)((uint)(in_TL == 1) * 0x6000 + (uint)(in_TL == 2) * 0x6004 +
                              (uint)(in_TL == 3) * 0x6008 + (uint)(in_TL == 4) * 0x600c);
            if (((uVar3 | uVar3 >> (bVar1 & 0x1f)) & uVar2) != 0) {
              *(uint *)((uint)(in_TL == 1) * 0x6000 + (uint)(in_TL == 2) * 0x6004 +
                        (uint)(in_TL == 3) * 0x6008 + (uint)(in_TL == 4) * 0x600c) =
                   uVar2 << 1 | uVar2 >> (bVar1 - 1 & 0x1f);
              iVar13 = in_CWP + -1;
              puVar11 = (undefined8 *)((qword)uVar4 >> 0x20);
              uVar4 = *puVar11;
              uVar5 = (undefined4)puVar11[1];
              uVar6 = puVar11[2];
              uVar7 = puVar11[3];
              uVar8 = puVar11[4];
              uVar9 = puVar11[5];
              uVar10 = puVar11[6];
              uVar12 = puVar11[7];
              if (!(bool)in_DECOMPILE_MODE) {
                *(int *)(iVar13 * 0x40 + 0x8000) = (int)((qword)uVar8 >> 0x20);
                *(int *)((iVar13 * 0x10 + 1) * 4 + 0x8000) = (int)uVar8;
                *(int *)((iVar13 * 0x10 + 2) * 4 + 0x8000) = (int)((qword)uVar9 >> 0x20);
                *(int *)((iVar13 * 0x10 + 3) * 4 + 0x8000) = (int)uVar9;
                *(int *)((iVar13 * 0x10 + 4) * 4 + 0x8000) = (int)((qword)uVar10 >> 0x20);
                *(int *)((iVar13 * 0x10 + 5) * 4 + 0x8000) = (int)uVar10;
                *(int *)((iVar13 * 0x10 + 6) * 4 + 0x8000) = (int)((qword)uVar12 >> 0x20);
                *(int *)((iVar13 * 0x10 + 7) * 4 + 0x8000) = (int)uVar12;
                *(int *)((iVar13 * 0x10 + 8) * 4 + 0x8000) = (int)((qword)uVar4 >> 0x20);
                *(int *)((iVar13 * 0x10 + 9) * 4 + 0x8000) = (int)uVar4;
                *(undefined4 *)((iVar13 * 0x10 + 10) * 4 + 0x8000) = uVar5;
                *(undefined4 *)((iVar13 * 0x10 + 0xb) * 4 + 0x8000) = uVar5;
                *(int *)((iVar13 * 0x10 + 0xc) * 4 + 0x8000) = (int)((qword)uVar6 >> 0x20);
                *(int *)((iVar13 * 0x10 + 0xd) * 4 + 0x8000) = (int)uVar6;
                *(int *)((iVar13 * 0x10 + 0xe) * 4 + 0x8000) = (int)((qword)uVar7 >> 0x20);
                *(int *)((iVar13 * 0x10 + 0xf) * 4 + 0x8000) = (int)uVar7;
              }
            }
          }
          else {
            *(undefined8 *)((int)register0x00000038 + 0x20) = in_i0_1;
            *(undefined8 *)((int)register0x00000038 + 0x28) = in_i2_3;
            *(undefined8 *)((int)register0x00000038 + 0x30) = in_i4_5;
            *(undefined8 *)((int)register0x00000038 + 0x38) = uVar4;
            uVar3 = 4 << ((byte)uVar3 & 0x1f);
            *(uint *)((uint)(in_TL == 1) * 0x6000 + (uint)(in_TL == 2) * 0x6004 +
                      (uint)(in_TL == 3) * 0x6008 + (uint)(in_TL == 4) * 0x600c) =
                 uVar3 | uVar3 >> (bVar1 & 0x1f);
            iVar13 = in_CWP + -1;
            puVar11 = (undefined8 *)((qword)uRam00000038 >> 0x20);
            uVar4 = *puVar11;
            uVar5 = (undefined4)puVar11[1];
            uVar6 = puVar11[2];
            uVar7 = puVar11[3];
            uVar8 = puVar11[4];
            uVar9 = puVar11[5];
            uVar10 = puVar11[6];
            uVar12 = puVar11[7];
            if (!(bool)in_DECOMPILE_MODE) {
              *(int *)(iVar13 * 0x40 + 0x8000) = (int)((qword)uVar8 >> 0x20);
              *(int *)((iVar13 * 0x10 + 1) * 4 + 0x8000) = (int)uVar8;
              *(int *)((iVar13 * 0x10 + 2) * 4 + 0x8000) = (int)((qword)uVar9 >> 0x20);
              *(int *)((iVar13 * 0x10 + 3) * 4 + 0x8000) = (int)uVar9;
              *(int *)((iVar13 * 0x10 + 4) * 4 + 0x8000) = (int)((qword)uVar10 >> 0x20);
              *(int *)((iVar13 * 0x10 + 5) * 4 + 0x8000) = (int)uVar10;
              *(int *)((iVar13 * 0x10 + 6) * 4 + 0x8000) = (int)((qword)uVar12 >> 0x20);
              *(int *)((iVar13 * 0x10 + 7) * 4 + 0x8000) = (int)uVar12;
              *(int *)((iVar13 * 0x10 + 8) * 4 + 0x8000) = (int)((qword)uVar4 >> 0x20);
              *(int *)((iVar13 * 0x10 + 9) * 4 + 0x8000) = (int)uVar4;
              *(undefined4 *)((iVar13 * 0x10 + 10) * 4 + 0x8000) = uVar5;
              *(undefined4 *)((iVar13 * 0x10 + 0xb) * 4 + 0x8000) = uVar5;
              *(int *)((iVar13 * 0x10 + 0xc) * 4 + 0x8000) = (int)((qword)uVar6 >> 0x20);
              *(int *)((iVar13 * 0x10 + 0xd) * 4 + 0x8000) = (int)uVar6;
              *(int *)((iVar13 * 0x10 + 0xe) * 4 + 0x8000) = (int)((qword)uVar7 >> 0x20);
              *(int *)((iVar13 * 0x10 + 0xf) * 4 + 0x8000) = (int)uVar7;
            }
          }
                    /* WARNING: Unimplemented instruction - Truncating control flow here */
          halt_unimplemented();
        }
        if (_need_ast == 0) break;
        _check_for_ast(_active_pcb + 0x234);
      }
      if (*(int *)(_active_pcb + 0x230) == 0) break;
      _trap(5,_active_pcb + 0x234);
    }
    in_i0_1 = *(undefined8 *)(_active_pcb + 0x260);
    in_i2_3 = *(undefined8 *)(_active_pcb + 0x268);
    in_i4_5 = *(undefined8 *)(_active_pcb + 0x270);
    in_fp_7 = *(qword *)(_active_pcb + 0x278);
    if (*(int *)(_active_pcb + 0xc) != 0) break;
    uVar3 = *(uint *)((uint)(in_TL == 1) * 0x6000 + (uint)(in_TL == 2) * 0x6004 +
                      (uint)(in_TL == 3) * 0x6008 + (uint)(in_TL == 4) * 0x600c);
    iVar13 = _active_pcb;
    *(uint *)((uint)(in_TL == 1) * 0x6000 + (uint)(in_TL == 2) * 0x6004 +
              (uint)(in_TL == 3) * 0x6008 + (uint)(in_TL == 4) * 0x600c) =
         uVar3 >> (bVar1 - 1 & 0x1f) | uVar3 << 1;
    if ((in_fp_7 & 0x700000000) == 0) {
      if ((uint)(in_fp_7 >> 0x20) < 0xf0000000) {
                    /* WARNING: Could not recover jumptable at 0xf00035d8. Too many branches */
                    /* WARNING: Treating indirect jump as call */
        (*_v_mmu_sys_unf)();
        return;
      }
      func_0xf00035ec();
      return;
    }
    *(uint *)((uint)(in_TL == 1) * 0x6000 + (uint)(in_TL == 2) * 0x6004 +
              (uint)(in_TL == 3) * 0x6008 + (uint)(in_TL == 4) * 0x600c) = uVar3;
    _trap(7,iVar13 + 0x234);
  }
  return;
}
/* GHIDRADEC_FUNCTION index=11 start=0xf00035e0 */

/* WARNING: Control flow encountered unimplemented instructions */
/* WARNING: Removing unreachable block (ram,0xf000362c) */

void sr_chk_flt(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
               undefined4 param_5,undefined4 param_6)

{
  undefined *puVar1;
  uint unaff_g1;
  undefined4 uVar2;
  uint uVar3;
  undefined8 in_g2_3;
  sqword sVar4;
  undefined *puVar5;
  undefined4 in_o7;
  undefined4 unaff_l0;
  undefined4 uVar6;
  uint unaff_l1;
  undefined4 uVar7;
  undefined4 unaff_l3;
  uint uVar8;
  undefined4 uVar9;
  undefined4 unaff_l4;
  undefined4 uVar10;
  undefined4 unaff_l5;
  undefined4 uVar11;
  undefined4 unaff_l6;
  undefined4 uVar12;
  undefined4 unaff_l7;
  undefined4 uVar13;
  undefined4 unaff_i0;
  undefined4 unaff_i1;
  undefined4 uVar14;
  undefined4 unaff_i2;
  undefined4 uVar15;
  undefined4 unaff_i3;
  undefined4 uVar16;
  undefined4 unaff_i4;
  undefined4 uVar17;
  undefined4 unaff_i5;
  undefined4 uVar18;
  undefined4 unaff_fp;
  undefined *puVar19;
  undefined4 unaff_i7;
  undefined4 uVar20;
  undefined in_DECOMPILE_MODE;
  int in_TL;
  int in_CWP;
  undefined auStackX_0 [92];
  
  uVar2 = (undefined4)((qword)in_g2_3 >> 0x20);
  if ((unaff_g1 & 2) != 0) {
    *(undefined4 *)
     ((uint)(in_TL == 1) * 0x6000 + (uint)(in_TL == 2) * 0x6004 + (uint)(in_TL == 3) * 0x6008 +
     (uint)(in_TL == 4) * 0x600c) = unaff_l3;
    _trap(9,_active_pcb + 0x234,uVar2,unaff_g1,2);
    sys_rtt();
    return;
  }
  uVar8 = *(uint *)(_active_pcb + 0x294);
  if (((unaff_l1 | *(uint *)(_active_pcb + 0x23c)) & 3) != 0) {
    return;
  }
  if ((uVar8 & 1) == 0) {
                    /* WARNING: Unimplemented instruction - Truncating control flow here */
    halt_unimplemented();
  }
  uVar3 = *(uint *)((uint)(in_TL == 1) * 0x6000 + (uint)(in_TL == 2) * 0x6004 +
                    (uint)(in_TL == 3) * 0x6008 + (uint)(in_TL == 4) * 0x600c);
  *(undefined4 *)
   ((uint)(in_TL == 1) * 0x6000 + (uint)(in_TL == 2) * 0x6004 + (uint)(in_TL == 3) * 0x6008 +
   (uint)(in_TL == 4) * 0x600c) = 0;
  sVar4 = (qword)uVar3 << 0x20;
  puVar1 = (undefined *)register0x00000038;
  if (!(bool)in_DECOMPILE_MODE) {
    *(undefined4 *)(in_CWP * 0x40 + 0x8000) = unaff_i0;
    *(undefined4 *)((in_CWP * 0x10 + 1) * 4 + 0x8000) = unaff_i1;
    *(undefined4 *)((in_CWP * 0x10 + 2) * 4 + 0x8000) = unaff_i2;
    *(undefined4 *)((in_CWP * 0x10 + 3) * 4 + 0x8000) = unaff_i3;
    *(undefined4 *)((in_CWP * 0x10 + 4) * 4 + 0x8000) = unaff_i4;
    *(undefined4 *)((in_CWP * 0x10 + 5) * 4 + 0x8000) = unaff_i5;
    *(undefined4 *)((in_CWP * 0x10 + 6) * 4 + 0x8000) = unaff_fp;
    *(undefined4 *)((in_CWP * 0x10 + 7) * 4 + 0x8000) = unaff_i7;
    *(undefined4 *)((in_CWP * 0x10 + 8) * 4 + 0x8000) = unaff_l0;
    *(uint *)((in_CWP * 0x10 + 9) * 4 + 0x8000) = unaff_l1;
    *(uint *)((in_CWP * 0x10 + 10) * 4 + 0x8000) = uVar8;
    *(uint *)((in_CWP * 0x10 + 0xb) * 4 + 0x8000) = uVar8;
    *(undefined4 *)((in_CWP * 0x10 + 0xc) * 4 + 0x8000) = unaff_l4;
    *(undefined4 *)((in_CWP * 0x10 + 0xd) * 4 + 0x8000) = unaff_l5;
    *(undefined4 *)((in_CWP * 0x10 + 0xe) * 4 + 0x8000) = unaff_l6;
    *(undefined4 *)((in_CWP * 0x10 + 0xf) * 4 + 0x8000) = unaff_l7;
    puVar1 = (undefined *)register0x00000038;
  }
  while( true ) {
    uVar20 = in_o7;
    puVar19 = puVar1;
    uVar18 = param_6;
    uVar17 = param_5;
    uVar16 = param_4;
    uVar15 = param_3;
    uVar14 = param_2;
    uVar2 = param_1;
    in_CWP = in_CWP + 1;
    uVar8 = (uint)((qword)sVar4 >> 0x20);
    if ((uVar8 >> ((byte)*(undefined4 *)
                          ((uint)(in_TL == 1) * 0x7000 + (uint)(in_TL == 2) * 0x7004 +
                           (uint)(in_TL == 3) * 0x7008 + (uint)(in_TL == 4) * 0x700c) & 0x1f) & 1)
        != 0) break;
    uVar6 = 0;
    uVar7 = 0;
    uVar9 = 0;
    uVar10 = 0;
    uVar11 = 0;
    uVar12 = 0;
    uVar13 = 0;
    param_1 = 0;
    param_2 = 0;
    param_3 = 0;
    param_4 = 0;
    param_5 = 0;
    param_6 = 0;
    puVar5 = (undefined *)0x0;
    in_o7 = 0;
    puVar1 = puVar5;
    if (!(bool)in_DECOMPILE_MODE) {
      *(undefined4 *)(in_CWP * 0x40 + 0x8000) = uVar2;
      *(undefined4 *)((in_CWP * 0x10 + 1) * 4 + 0x8000) = uVar14;
      *(undefined4 *)((in_CWP * 0x10 + 2) * 4 + 0x8000) = uVar15;
      *(undefined4 *)((in_CWP * 0x10 + 3) * 4 + 0x8000) = uVar16;
      *(undefined4 *)((in_CWP * 0x10 + 4) * 4 + 0x8000) = uVar17;
      *(undefined4 *)((in_CWP * 0x10 + 5) * 4 + 0x8000) = uVar18;
      *(undefined **)((in_CWP * 0x10 + 6) * 4 + 0x8000) = puVar19;
      *(undefined4 *)((in_CWP * 0x10 + 7) * 4 + 0x8000) = uVar20;
      *(undefined4 *)((in_CWP * 0x10 + 8) * 4 + 0x8000) = uVar6;
      *(undefined4 *)((in_CWP * 0x10 + 9) * 4 + 0x8000) = uVar7;
      *(undefined4 *)((in_CWP * 0x10 + 10) * 4 + 0x8000) = uVar9;
      *(undefined4 *)((in_CWP * 0x10 + 0xb) * 4 + 0x8000) = uVar9;
      *(undefined4 *)((in_CWP * 0x10 + 0xc) * 4 + 0x8000) = uVar10;
      *(undefined4 *)((in_CWP * 0x10 + 0xd) * 4 + 0x8000) = uVar11;
      *(undefined4 *)((in_CWP * 0x10 + 0xe) * 4 + 0x8000) = uVar12;
      *(undefined4 *)((in_CWP * 0x10 + 0xf) * 4 + 0x8000) = uVar13;
      puVar1 = puVar5;
    }
  }
  *(uint *)((uint)(in_TL == 1) * 0x6000 + (uint)(in_TL == 2) * 0x6004 + (uint)(in_TL == 3) * 0x6008
           + (uint)(in_TL == 4) * 0x600c) = uVar8;
                    /* WARNING: Unimplemented instruction - Truncating control flow here */
  halt_unimplemented();
}
/* GHIDRADEC_FUNCTION index=12 start=0xf00038c4 */

/* WARNING: Removing unreachable block (ram,0xf00038e0) */

void syscall(void)

{
  _syscall(_active_pcb + 0x234);
  sys_rtt();
  return;
}
/* GHIDRADEC_FUNCTION index=13 start=0xf00038ec */

/* WARNING: Removing unreachable block (ram,0xf0003908) */

void machcall(void)

{
  _machcall(_active_pcb + 0x234);
  sys_rtt();
  return;
}
/* GHIDRADEC_FUNCTION index=14 start=0xf0003914 */

/* WARNING: Removing unreachable block (ram,0xf00039b0) */

void fault(void)

{
  uint unaff_g6;
  
  if ((unaff_g6 >> 2 & 7) == 0) {
    return;
  }
  _trap();
  sys_rtt();
  return;
}
/* GHIDRADEC_FUNCTION index=15 start=0xf00039bc */

/* WARNING: Removing unreachable block (ram,0xf0003a94) */
/* WARNING: Removing unreachable block (ram,0xf00039f0) */

void interrupt(void)

{
  uint unaff_l4;
  uint uVar1;
  int iVar2;
  
  uVar1 = unaff_l4 & 0xf;
  iVar2 = uVar1 * 4;
  if (uVar1 == 0xf) {
    _set_intmask(0x80000000,0);
  }
  uVar1 = 0x10000 << (sbyte)uVar1;
  if ((uRamfeff4000 & uVar1) == 0) {
    uVar1 = uVar1 >> 0x10;
    if ((uRamfeff4000 & uVar1) == 0) {
      sys_rtt();
      return;
    }
  }
  else {
    iVar2 = iVar2 + 0x40;
  }
  if ((uVar1 & 0xffff8000) != 0) {
    uRamfeff4004 = uVar1;
  }
  (**(code **)(_int_vector + iVar2))();
  _flush_writebuffers_to();
  sys_rtt();
  return;
}
/* GHIDRADEC_FUNCTION index=16 start=0xf0004e70 */

/* WARNING: Removing unreachable block (ram,0xf0004e8c) */

void level10(void)

{
  undefined4 *unaff_l6;
  
  _clk_intr = _clk_intr + 1;
  _sparc_hardclock(unaff_l6[1],*unaff_l6);
  func_0xf0003a94();
  return;
}
/* GHIDRADEC_FUNCTION index=17 start=0xf0004e98 */

undefined8
_flush_windows(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
              undefined4 param_5,undefined4 param_6)

{
  undefined *puVar1;
  undefined *puVar2;
  undefined *puVar3;
  undefined4 in_o7;
  undefined4 unaff_l0;
  undefined4 uVar4;
  undefined4 unaff_l1;
  undefined4 uVar5;
  undefined4 unaff_l3;
  undefined4 uVar6;
  undefined4 unaff_l4;
  undefined4 uVar7;
  undefined4 unaff_l5;
  undefined4 uVar8;
  undefined4 unaff_l6;
  undefined4 uVar9;
  undefined4 unaff_l7;
  undefined4 uVar10;
  undefined4 unaff_i0;
  undefined4 unaff_i1;
  undefined4 uVar11;
  undefined4 unaff_i2;
  undefined4 uVar12;
  undefined4 unaff_i3;
  undefined4 uVar13;
  undefined4 unaff_i4;
  undefined4 uVar14;
  undefined4 unaff_i5;
  undefined4 uVar15;
  undefined4 unaff_fp;
  undefined4 unaff_i7;
  undefined4 uVar16;
  undefined in_DECOMPILE_MODE;
  int in_CWP;
  int iVar17;
  undefined auStackX_0 [92];
  undefined auStack_100 [64];
  undefined auStack_c0 [64];
  undefined auStack_80 [64];
  undefined auStack_40 [64];
  
  puVar2 = auStack_40;
  puVar1 = (undefined *)register0x00000038;
  if (!(bool)in_DECOMPILE_MODE) {
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
  uVar4 = 0;
  uVar5 = 0;
  uVar6 = 0;
  uVar7 = 0;
  uVar8 = 0;
  uVar9 = 0;
  uVar10 = 0;
  iVar17 = in_CWP + 1;
  puVar3 = auStack_80;
  if (!(bool)in_DECOMPILE_MODE) {
    uVar11 = param_2;
    uVar12 = param_3;
    uVar13 = param_4;
    uVar14 = param_5;
    uVar15 = param_6;
    uVar16 = in_o7;
    *(undefined4 *)(iVar17 * 0x40 + 0x8000) = param_1;
    *(undefined4 *)((iVar17 * 0x10 + 1) * 4 + 0x8000) = uVar11;
    *(undefined4 *)((iVar17 * 0x10 + 2) * 4 + 0x8000) = uVar12;
    *(undefined4 *)((iVar17 * 0x10 + 3) * 4 + 0x8000) = uVar13;
    *(undefined4 *)((iVar17 * 0x10 + 4) * 4 + 0x8000) = uVar14;
    *(undefined4 *)((iVar17 * 0x10 + 5) * 4 + 0x8000) = uVar15;
    *(undefined **)((iVar17 * 0x10 + 6) * 4 + 0x8000) = puVar1;
    *(undefined4 *)((iVar17 * 0x10 + 7) * 4 + 0x8000) = uVar16;
    *(undefined4 *)((iVar17 * 0x10 + 8) * 4 + 0x8000) = uVar4;
    *(undefined4 *)((iVar17 * 0x10 + 9) * 4 + 0x8000) = uVar5;
    *(undefined4 *)((iVar17 * 0x10 + 10) * 4 + 0x8000) = uVar6;
    *(undefined4 *)((iVar17 * 0x10 + 0xb) * 4 + 0x8000) = uVar6;
    *(undefined4 *)((iVar17 * 0x10 + 0xc) * 4 + 0x8000) = uVar7;
    *(undefined4 *)((iVar17 * 0x10 + 0xd) * 4 + 0x8000) = uVar8;
    *(undefined4 *)((iVar17 * 0x10 + 0xe) * 4 + 0x8000) = uVar9;
    *(undefined4 *)((iVar17 * 0x10 + 0xf) * 4 + 0x8000) = uVar10;
  }
  uVar4 = 0;
  uVar5 = 0;
  uVar6 = 0;
  uVar7 = 0;
  uVar8 = 0;
  uVar9 = 0;
  uVar10 = 0;
  iVar17 = iVar17 + 1;
  puVar1 = auStack_c0;
  if (!(bool)in_DECOMPILE_MODE) {
    uVar11 = param_2;
    uVar12 = param_3;
    uVar13 = param_4;
    uVar14 = param_5;
    uVar15 = param_6;
    uVar16 = in_o7;
    *(undefined4 *)(iVar17 * 0x40 + 0x8000) = param_1;
    *(undefined4 *)((iVar17 * 0x10 + 1) * 4 + 0x8000) = uVar11;
    *(undefined4 *)((iVar17 * 0x10 + 2) * 4 + 0x8000) = uVar12;
    *(undefined4 *)((iVar17 * 0x10 + 3) * 4 + 0x8000) = uVar13;
    *(undefined4 *)((iVar17 * 0x10 + 4) * 4 + 0x8000) = uVar14;
    *(undefined4 *)((iVar17 * 0x10 + 5) * 4 + 0x8000) = uVar15;
    *(undefined **)((iVar17 * 0x10 + 6) * 4 + 0x8000) = puVar2;
    *(undefined4 *)((iVar17 * 0x10 + 7) * 4 + 0x8000) = uVar16;
    *(undefined4 *)((iVar17 * 0x10 + 8) * 4 + 0x8000) = uVar4;
    *(undefined4 *)((iVar17 * 0x10 + 9) * 4 + 0x8000) = uVar5;
    *(undefined4 *)((iVar17 * 0x10 + 10) * 4 + 0x8000) = uVar6;
    *(undefined4 *)((iVar17 * 0x10 + 0xb) * 4 + 0x8000) = uVar6;
    *(undefined4 *)((iVar17 * 0x10 + 0xc) * 4 + 0x8000) = uVar7;
    *(undefined4 *)((iVar17 * 0x10 + 0xd) * 4 + 0x8000) = uVar8;
    *(undefined4 *)((iVar17 * 0x10 + 0xe) * 4 + 0x8000) = uVar9;
    *(undefined4 *)((iVar17 * 0x10 + 0xf) * 4 + 0x8000) = uVar10;
  }
  uVar4 = 0;
  uVar5 = 0;
  uVar6 = 0;
  uVar7 = 0;
  uVar8 = 0;
  uVar9 = 0;
  uVar10 = 0;
  iVar17 = iVar17 + 1;
  puVar2 = auStack_100;
  if (!(bool)in_DECOMPILE_MODE) {
    uVar11 = param_2;
    uVar12 = param_3;
    uVar13 = param_4;
    uVar14 = param_5;
    uVar15 = param_6;
    uVar16 = in_o7;
    *(undefined4 *)(iVar17 * 0x40 + 0x8000) = param_1;
    *(undefined4 *)((iVar17 * 0x10 + 1) * 4 + 0x8000) = uVar11;
    *(undefined4 *)((iVar17 * 0x10 + 2) * 4 + 0x8000) = uVar12;
    *(undefined4 *)((iVar17 * 0x10 + 3) * 4 + 0x8000) = uVar13;
    *(undefined4 *)((iVar17 * 0x10 + 4) * 4 + 0x8000) = uVar14;
    *(undefined4 *)((iVar17 * 0x10 + 5) * 4 + 0x8000) = uVar15;
    *(undefined **)((iVar17 * 0x10 + 6) * 4 + 0x8000) = puVar3;
    *(undefined4 *)((iVar17 * 0x10 + 7) * 4 + 0x8000) = uVar16;
    *(undefined4 *)((iVar17 * 0x10 + 8) * 4 + 0x8000) = uVar4;
    *(undefined4 *)((iVar17 * 0x10 + 9) * 4 + 0x8000) = uVar5;
    *(undefined4 *)((iVar17 * 0x10 + 10) * 4 + 0x8000) = uVar6;
    *(undefined4 *)((iVar17 * 0x10 + 0xb) * 4 + 0x8000) = uVar6;
    *(undefined4 *)((iVar17 * 0x10 + 0xc) * 4 + 0x8000) = uVar7;
    *(undefined4 *)((iVar17 * 0x10 + 0xd) * 4 + 0x8000) = uVar8;
    *(undefined4 *)((iVar17 * 0x10 + 0xe) * 4 + 0x8000) = uVar9;
    *(undefined4 *)((iVar17 * 0x10 + 0xf) * 4 + 0x8000) = uVar10;
  }
  uVar4 = 0;
  uVar5 = 0;
  uVar6 = 0;
  uVar7 = 0;
  uVar8 = 0;
  uVar9 = 0;
  uVar10 = 0;
  iVar17 = iVar17 + 1;
  if (!(bool)in_DECOMPILE_MODE) {
    uVar11 = param_2;
    uVar12 = param_3;
    uVar13 = param_4;
    uVar14 = param_5;
    uVar15 = param_6;
    uVar16 = in_o7;
    *(undefined4 *)(iVar17 * 0x40 + 0x8000) = param_1;
    *(undefined4 *)((iVar17 * 0x10 + 1) * 4 + 0x8000) = uVar11;
    *(undefined4 *)((iVar17 * 0x10 + 2) * 4 + 0x8000) = uVar12;
    *(undefined4 *)((iVar17 * 0x10 + 3) * 4 + 0x8000) = uVar13;
    *(undefined4 *)((iVar17 * 0x10 + 4) * 4 + 0x8000) = uVar14;
    *(undefined4 *)((iVar17 * 0x10 + 5) * 4 + 0x8000) = uVar15;
    *(undefined **)((iVar17 * 0x10 + 6) * 4 + 0x8000) = puVar1;
    *(undefined4 *)((iVar17 * 0x10 + 7) * 4 + 0x8000) = uVar16;
    *(undefined4 *)((iVar17 * 0x10 + 8) * 4 + 0x8000) = uVar4;
    *(undefined4 *)((iVar17 * 0x10 + 9) * 4 + 0x8000) = uVar5;
    *(undefined4 *)((iVar17 * 0x10 + 10) * 4 + 0x8000) = uVar6;
    *(undefined4 *)((iVar17 * 0x10 + 0xb) * 4 + 0x8000) = uVar6;
    *(undefined4 *)((iVar17 * 0x10 + 0xc) * 4 + 0x8000) = uVar7;
    *(undefined4 *)((iVar17 * 0x10 + 0xd) * 4 + 0x8000) = uVar8;
    *(undefined4 *)((iVar17 * 0x10 + 0xe) * 4 + 0x8000) = uVar9;
    *(undefined4 *)((iVar17 * 0x10 + 0xf) * 4 + 0x8000) = uVar10;
  }
  uVar4 = 0;
  uVar5 = 0;
  uVar6 = 0;
  uVar7 = 0;
  uVar8 = 0;
  uVar9 = 0;
  uVar10 = 0;
  iVar17 = iVar17 + 1;
  if (!(bool)in_DECOMPILE_MODE) {
    uVar11 = param_2;
    *(undefined4 *)(iVar17 * 0x40 + 0x8000) = param_1;
    *(undefined4 *)((iVar17 * 0x10 + 1) * 4 + 0x8000) = uVar11;
    *(undefined4 *)((iVar17 * 0x10 + 2) * 4 + 0x8000) = param_3;
    *(undefined4 *)((iVar17 * 0x10 + 3) * 4 + 0x8000) = param_4;
    *(undefined4 *)((iVar17 * 0x10 + 4) * 4 + 0x8000) = param_5;
    *(undefined4 *)((iVar17 * 0x10 + 5) * 4 + 0x8000) = param_6;
    *(undefined **)((iVar17 * 0x10 + 6) * 4 + 0x8000) = puVar2;
    *(undefined4 *)((iVar17 * 0x10 + 7) * 4 + 0x8000) = in_o7;
    *(undefined4 *)((iVar17 * 0x10 + 8) * 4 + 0x8000) = uVar4;
    *(undefined4 *)((iVar17 * 0x10 + 9) * 4 + 0x8000) = uVar5;
    *(undefined4 *)((iVar17 * 0x10 + 10) * 4 + 0x8000) = uVar6;
    *(undefined4 *)((iVar17 * 0x10 + 0xb) * 4 + 0x8000) = uVar6;
    *(undefined4 *)((iVar17 * 0x10 + 0xc) * 4 + 0x8000) = uVar7;
    *(undefined4 *)((iVar17 * 0x10 + 0xd) * 4 + 0x8000) = uVar8;
    *(undefined4 *)((iVar17 * 0x10 + 0xe) * 4 + 0x8000) = uVar9;
    *(undefined4 *)((iVar17 * 0x10 + 0xf) * 4 + 0x8000) = uVar10;
  }
  if (!(bool)in_DECOMPILE_MODE) {
    param_1 = *(undefined4 *)((iVar17 + -4) * 0x40 + 0x8000);
    param_2 = *(undefined4 *)(((iVar17 + -4) * 0x10 + 1) * 4 + 0x8000);
  }
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=18 start=0xf0004ecc */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void _reset_windows(void)

{
  int iVar1;
  int in_TL;
  
  iVar1 = (*(uint *)((uint)(in_TL == 1) * 0x7000 + (uint)(in_TL == 2) * 0x7004 +
                     (uint)(in_TL == 3) * 0x7008 + (uint)(in_TL == 4) * 0x700c) & 0x1f) + 1;
  if (iVar1 == __nwindows) {
    iVar1 = 0;
  }
  *(int *)((uint)(in_TL == 1) * 0x6000 + (uint)(in_TL == 2) * 0x6004 + (uint)(in_TL == 3) * 0x6008 +
          (uint)(in_TL == 4) * 0x600c) = 1 << ((byte)iVar1 & 0x1f);
  return;
}
/* GHIDRADEC_FUNCTION index=19 start=0xf0004efc */

undefined8
_flush_user_windows(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                   undefined4 param_5,undefined4 param_6)

{
  undefined *puVar1;
  int iVar2;
  undefined *puVar3;
  undefined4 in_o7;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  undefined4 uVar4;
  undefined4 unaff_i1;
  undefined4 uVar5;
  undefined4 unaff_i2;
  undefined4 unaff_i3;
  undefined4 unaff_i4;
  undefined4 unaff_i5;
  undefined *unaff_fp;
  undefined4 unaff_i7;
  undefined in_DECOMPILE_MODE;
  int in_CWP;
  undefined auStackX_0 [92];
  
  iVar2 = 0;
  puVar1 = (undefined *)register0x00000038;
  if (*(int *)(_active_pcb + 0xc) != 0) {
    do {
      puVar3 = puVar1;
      puVar1 = puVar3 + -0x40;
      if (!(bool)in_DECOMPILE_MODE) {
        *(undefined4 *)(in_CWP * 0x40 + 0x8000) = unaff_i0;
        *(undefined4 *)((in_CWP * 0x10 + 1) * 4 + 0x8000) = unaff_i1;
        *(undefined4 *)((in_CWP * 0x10 + 2) * 4 + 0x8000) = unaff_i2;
        *(undefined4 *)((in_CWP * 0x10 + 3) * 4 + 0x8000) = unaff_i3;
        *(undefined4 *)((in_CWP * 0x10 + 4) * 4 + 0x8000) = unaff_i4;
        *(undefined4 *)((in_CWP * 0x10 + 5) * 4 + 0x8000) = unaff_i5;
        *(undefined **)((in_CWP * 0x10 + 6) * 4 + 0x8000) = unaff_fp;
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
      unaff_l0 = 0;
      unaff_l1 = 0;
      unaff_l3 = 0;
      unaff_l4 = 0;
      unaff_l5 = 0;
      unaff_l6 = 0;
      unaff_l7 = 0;
      in_CWP = in_CWP + 1;
      iVar2 = iVar2 + 1;
      uVar4 = param_1;
      unaff_i0 = param_1;
      uVar5 = param_2;
      unaff_i1 = param_2;
      unaff_i2 = param_3;
      unaff_i3 = param_4;
      unaff_i4 = param_5;
      unaff_i5 = param_6;
      unaff_fp = puVar3;
      unaff_i7 = in_o7;
    } while (*(int *)(_active_pcb + 0xc) != 0);
    do {
      param_2 = uVar5;
      param_1 = uVar4;
      iVar2 = iVar2 + -1;
      in_CWP = in_CWP + -1;
      uVar4 = param_1;
      uVar5 = param_2;
      if (!(bool)in_DECOMPILE_MODE) {
        uVar4 = *(undefined4 *)(in_CWP * 0x40 + 0x8000);
        uVar5 = *(undefined4 *)((in_CWP * 0x10 + 1) * 4 + 0x8000);
      }
    } while (iVar2 != 0);
  }
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=20 start=0xf0004f4c */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void _trash_user_windows(void)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  int in_TL;
  
  if (*(int *)(_active_pcb + 0xc) != 0) {
    uVar1 = *(uint *)(_active_pcb + 0xc);
    *(undefined4 *)(_active_pcb + 0xc) = 0;
    iVar3 = __nwindows + -1;
    for (; uVar1 != 0; uVar1 = uVar1 & ~uVar2) {
      uVar2 = *(uint *)((uint)(in_TL == 1) * 0x6000 + (uint)(in_TL == 2) * 0x6004 +
                        (uint)(in_TL == 3) * 0x6008 + (uint)(in_TL == 4) * 0x600c);
      uVar2 = uVar2 << ((byte)iVar3 & 0x1f) | uVar2 >> 1;
      *(uint *)((uint)(in_TL == 1) * 0x6000 + (uint)(in_TL == 2) * 0x6004 +
                (uint)(in_TL == 3) * 0x6008 + (uint)(in_TL == 4) * 0x600c) = uVar2;
    }
  }
  *(undefined4 *)(_active_pcb + 0x230) = 0;
  return;
}
/* GHIDRADEC_FUNCTION index=21 start=0xf00050ec */

/* WARNING: Removing unreachable block (ram,0xf00050f0) */

undefined8 _montrap(code *param_1,undefined4 param_2)

{
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
  _flush_windows();
  (*param_1)();
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=22 start=0xf0005160 */

/* WARNING: Control flow encountered bad instruction data */

void _trap_ff_tcode(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}
/* GHIDRADEC_FUNCTION index=23 start=0xf0005170 */

/* WARNING: Control flow encountered bad instruction data */

void _trap_fe_tcode(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}
/* GHIDRADEC_FUNCTION index=24 start=0xf00051c8 */

void mon_breakpoint_vec(void)

{
  return;
}
/* GHIDRADEC_FUNCTION index=25 start=0xf00051d8 */

void _kadb_tcode(void)

{
  return;
}
/* GHIDRADEC_FUNCTION index=26 start=0xf00051e8 */

void _set_auxioreg(byte param_1,int param_2)

{
  if (param_2 == 0) {
    bRamfeff0000 = bRamfeff0000 & ~param_1;
  }
  else {
    bRamfeff0000 = bRamfeff0000 | param_1;
  }
  bRamfeff0000 = bRamfeff0000 | 0xc0;
  return;
}
/* GHIDRADEC_FUNCTION index=27 start=0xf0005238 */

undefined4 _get_mmu_entry(undefined4 *param_1)

{
  return *param_1;
}
/* GHIDRADEC_FUNCTION index=28 start=0xf0005240 */

undefined4 _get_iommu_entry(undefined4 *param_1)

{
  return *param_1;
}
/* GHIDRADEC_FUNCTION index=29 start=0xf0005248 */

undefined8 _index(char *param_1,char param_2)

{
  char cVar1;
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
  do {
    cVar1 = *param_1;
    if ((int)cVar1 == (int)param_2) goto locret_F0005270;
    param_1 = param_1 + 1;
  } while (cVar1 != 0);
  param_1 = (char *)0x0;
locret_F0005270:
  return CONCAT44((int)param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=30 start=0xf0005278 */

undefined8 _strcat(char *param_1,char *param_2)

{
  char cVar1;
  char *pcVar2;
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
  cVar1 = *param_1;
  pcVar2 = param_1;
  while (cVar1 != '\0') {
    cVar1 = pcVar2[1];
    pcVar2 = pcVar2 + 1;
  }
  cVar1 = *param_2;
  while( true ) {
    *pcVar2 = cVar1;
    param_2 = param_2 + 1;
    pcVar2 = pcVar2 + 1;
    if (cVar1 == '\0') break;
    cVar1 = *param_2;
  }
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=31 start=0xf00052c8 */

undefined8 _strrchr(char *param_1,char param_2)

{
  char cVar1;
  char *pcVar2;
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
  pcVar2 = (char *)0x0;
  do {
    cVar1 = *param_1;
    if ((int)cVar1 == (int)param_2) {
      pcVar2 = param_1;
    }
    param_1 = param_1 + 1;
  } while (cVar1 != 0);
  return CONCAT44((int)param_2,pcVar2);
}
/* GHIDRADEC_FUNCTION index=32 start=0xf00052fc */

undefined8 _strchr(char *param_1,char param_2)

{
  char cVar1;
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
  do {
    cVar1 = *param_1;
    if ((int)cVar1 == (int)param_2) goto locret_F0005324;
    param_1 = param_1 + 1;
  } while (cVar1 != 0);
  param_1 = (char *)0x0;
locret_F0005324:
  return CONCAT44((int)param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=33 start=0xf000532c */

undefined8 __negdi2(int param_1,int param_2)

{
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
  return CONCAT44(-param_2,-(uint)(-param_2 != 0) - param_1);
}
/* GHIDRADEC_FUNCTION index=34 start=0xf0005354 */

undefined8 __lshldi3(uint param_1,uint param_2,int param_3)

{
  byte bVar1;
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
  uint uVar2;
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
  uVar2 = param_2;
  if (param_3 != 0) {
    uVar2 = param_2 << ((byte)param_3 & 0x1f);
    bVar1 = (byte)(0x20 - param_3);
    if (0x20 - param_3 < 1) {
      uVar2 = 0;
      param_1 = param_2 << (-bVar1 & 0x1f);
    }
    else {
      param_1 = param_1 << ((byte)param_3 & 0x1f) | param_2 >> (bVar1 & 0x1f);
    }
  }
  return CONCAT44(uVar2,param_1);
}
/* GHIDRADEC_FUNCTION index=35 start=0xf00053a0 */

undefined8 __lshrdi3(uint param_1,uint param_2,int param_3)

{
  byte bVar1;
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
  uint uVar2;
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
  uVar2 = param_1;
  if (param_3 != 0) {
    uVar2 = param_1 >> ((byte)param_3 & 0x1f);
    bVar1 = (byte)(0x20 - param_3);
    if (0x20 - param_3 < 1) {
      uVar2 = 0;
      param_2 = param_1 >> (-bVar1 & 0x1f);
    }
    else {
      param_2 = param_2 >> ((byte)param_3 & 0x1f) | param_1 << (bVar1 & 0x1f);
    }
  }
  return CONCAT44(param_2,uVar2);
}
/* GHIDRADEC_FUNCTION index=36 start=0xf00053ec */

undefined8 __ashldi3(uint param_1,uint param_2,int param_3)

{
  byte bVar1;
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
  uint uVar2;
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
  uVar2 = param_2;
  if (param_3 != 0) {
    uVar2 = param_2 << ((byte)param_3 & 0x1f);
    bVar1 = (byte)(0x20 - param_3);
    if (0x20 - param_3 < 1) {
      uVar2 = 0;
      param_1 = param_2 << (-bVar1 & 0x1f);
    }
    else {
      param_1 = param_1 << ((byte)param_3 & 0x1f) | param_2 >> (bVar1 & 0x1f);
    }
  }
  return CONCAT44(uVar2,param_1);
}
/* GHIDRADEC_FUNCTION index=37 start=0xf0005438 */

undefined8 __ashrdi3(int param_1,uint param_2,int param_3)

{
  byte bVar1;
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
  int iVar2;
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
  iVar2 = param_1;
  if (param_3 != 0) {
    iVar2 = param_1 >> ((byte)param_3 & 0x1f);
    bVar1 = (byte)(0x20 - param_3);
    if (0x20 - param_3 < 1) {
      iVar2 = param_1 >> 0x1f;
      param_2 = param_1 >> (-bVar1 & 0x1f);
    }
    else {
      param_2 = param_2 >> ((byte)param_3 & 0x1f) | param_1 << (bVar1 & 0x1f);
    }
  }
  return CONCAT44(param_2,iVar2);
}
/* GHIDRADEC_FUNCTION index=38 start=0xf0005484 */

/* WARNING: Removing unreachable block (ram,0xf00054a0) */
/* WARNING: Removing unreachable block (ram,0xf000548c) */

sqword __ffsdi2(uint param_1,uint param_2)

{
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
  _ffs();
  if ((param_2 == 0) && (_ffs(), param_2 = param_1, param_1 != 0)) {
    param_2 = param_1 + 0x20;
  }
  return (qword)param_2 << 0x20;
}
/* GHIDRADEC_FUNCTION index=39 start=0xf00054c4 */

/* WARNING: Removing unreachable block (ram,0xf0005570) */
/* WARNING: Removing unreachable block (ram,0xf0005514) */
/* WARNING: Removing unreachable block (ram,0xf0005500) */
/* WARNING: Removing unreachable block (ram,0xf0005524) */
/* WARNING: Removing unreachable block (ram,0xf0005580) */
/* WARNING: Removing unreachable block (ram,0xf00054ec) */

undefined8 __muldi3(int param_1,uint param_2,undefined4 param_3,uint param_4)

{
  uint uVar1;
  uint uVar2;
  undefined4 unaff_l0;
  uint uVar3;
  uint uVar4;
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
  uVar3 = param_2 & 0xffff;
  uVar1 = uVar3;
  .umul(uVar3,param_4 & 0xffff);
  .umul(uVar3,param_4 >> 0x10);
  uVar4 = param_2 >> 0x10;
  uVar2 = uVar4;
  .umul(uVar4,param_4 & 0xffff);
  .umul(uVar4,param_4 >> 0x10);
  uVar3 = uVar3 + (uVar1 >> 0x10) + uVar2;
  if (uVar3 < uVar2) {
    uVar4 = uVar4 + 0x10000;
  }
  .umul(param_2,param_3);
  .umul(param_1,param_4);
  return CONCAT44(uVar3 * 0x10000 + (uVar1 & 0xffff),uVar4 + (uVar3 >> 0x10) + param_2 + param_1);
}
/* GHIDRADEC_FUNCTION index=40 start=0xf0005598 */

/* WARNING: Removing unreachable block (ram,0xf00056bc) */
/* WARNING: Removing unreachable block (ram,0xf000565c) */
/* WARNING: Removing unreachable block (ram,0xf0005640) */
/* WARNING: Removing unreachable block (ram,0xf0005954) */
/* WARNING: Removing unreachable block (ram,0xf00058f4) */
/* WARNING: Removing unreachable block (ram,0xf00058d8) */
/* WARNING: Removing unreachable block (ram,0xf000585c) */
/* WARNING: Removing unreachable block (ram,0xf00057fc) */
/* WARNING: Removing unreachable block (ram,0xf00057e0) */
/* WARNING: Removing unreachable block (ram,0xf0005bf8) */
/* WARNING: Removing unreachable block (ram,0xf0005bd4) */
/* WARNING: Removing unreachable block (ram,0xf0005b50) */
/* WARNING: Removing unreachable block (ram,0xf0005b34) */
/* WARNING: Removing unreachable block (ram,0xf0005ad8) */
/* WARNING: Removing unreachable block (ram,0xf0005ae4) */
/* WARNING: Removing unreachable block (ram,0xf0005b44) */
/* WARNING: Removing unreachable block (ram,0xf0005bc0) */
/* WARNING: Removing unreachable block (ram,0xf0005be8) */
/* WARNING: Removing unreachable block (ram,0xf000573c) */
/* WARNING: Removing unreachable block (ram,0xf00057f0) */
/* WARNING: Removing unreachable block (ram,0xf000584c) */
/* WARNING: Removing unreachable block (ram,0xf0005868) */
/* WARNING: Removing unreachable block (ram,0xf00058e8) */
/* WARNING: Removing unreachable block (ram,0xf0005944) */
/* WARNING: Removing unreachable block (ram,0xf0005960) */
/* WARNING: Removing unreachable block (ram,0xf0005650) */
/* WARNING: Removing unreachable block (ram,0xf00056ac) */
/* WARNING: Removing unreachable block (ram,0xf00056c8) */
/* WARNING: Removing unreachable block (ram,0xf0005ac8) */

undefined8 __udivmoddi4(uint param_1,uint param_2,uint param_3,uint param_4)

{
  byte bVar1;
  int iVar2;
  uint uVar3;
  undefined8 *puVar4;
  undefined8 in_o4_5;
  undefined4 unaff_l0;
  uint uVar5;
  undefined4 unaff_l1;
  uint uVar6;
  undefined4 unaff_l3;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  int iVar10;
  uint uVar11;
  undefined8 in_i0_1;
  undefined4 unaff_i2;
  undefined4 unaff_i3;
  undefined4 unaff_i4;
  byte bVar12;
  undefined4 unaff_i5;
  undefined4 unaff_fp;
  undefined4 unaff_i7;
  bool in_DECOMPILE_MODE;
  int in_CWP;
  undefined auStackX_0 [92];
  
  puVar4 = (undefined8 *)((qword)in_o4_5 >> 0x20);
  if (!in_DECOMPILE_MODE) {
    *(int *)(in_CWP * 0x40 + 0x8000) = (int)((qword)in_i0_1 >> 0x20);
    *(int *)((in_CWP * 0x10 + 1) * 4 + 0x8000) = (int)in_i0_1;
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
  if (param_3 == 0) {
    if (param_1 < param_4) {
      if (param_4 < 0x10000) {
        uVar3 = (param_4 < 0x100) - 1 & 8;
      }
      else {
        uVar3 = 0x18;
        if (param_4 < 0x1000000) {
          uVar3 = 0x10;
        }
      }
      iVar10 = 0x20 - ((byte)unk_F00F4A98[param_4 >> (sbyte)uVar3] + uVar3);
      if (iVar10 != 0) {
        param_4 = param_4 << ((byte)iVar10 & 0x1f);
        param_2 = param_2 << ((byte)iVar10 & 0x1f);
      }
      iVar2 = 0;
      uVar7 = param_4 >> 0x10;
      .urem(0,uVar7);
      uVar3 = 0;
      .udiv(0,uVar7);
      .umul();
      uVar5 = iVar2 << 0x10 | param_2 >> 0x10;
      if (uVar5 < uVar3) {
        uVar5 = uVar5 + param_4;
        if (param_4 <= uVar5) {
          if (uVar3 <= uVar5) {
            uVar5 = uVar5 - uVar3;
            goto loc_F00056A8;
          }
          uVar5 = uVar5 + param_4;
        }
        uVar5 = uVar5 - uVar3;
      }
      else {
        uVar5 = uVar5 - uVar3;
      }
loc_F00056A8:
      uVar3 = uVar5;
      .urem(uVar5,uVar7);
      .udiv(uVar5,uVar7);
      .umul();
      uVar7 = uVar3 << 0x10 | param_2 & 0xffff;
      if (((uVar7 < uVar5) && (uVar7 = uVar7 + param_4, param_4 <= uVar7)) && (uVar7 < uVar5)) {
        uVar7 = uVar7 + param_4;
      }
      uVar7 = uVar7 - uVar5;
      uVar3 = 0;
    }
    else {
      if (param_4 == 0) {
        param_4 = 1;
        .udiv(1,0);
      }
      if (param_4 < 0x10000) {
        uVar3 = (param_4 < 0x100) - 1 & 8;
      }
      else {
        uVar3 = 0x18;
        if (param_4 < 0x1000000) {
          uVar3 = 0x10;
        }
      }
      iVar10 = 0x20 - ((byte)unk_F00F4A98[param_4 >> (sbyte)uVar3] + uVar3);
      bVar1 = (byte)iVar10;
      if (iVar10 == 0) {
        uVar5 = -param_4;
        uVar3 = 1;
      }
      else {
        param_4 = param_4 << (bVar1 & 0x1f);
        uVar7 = 0 >> (0x20 - bVar1 & 0x1f);
        uVar11 = 0 << (bVar1 & 0x1f) | param_2 >> (0x20 - bVar1 & 0x1f);
        param_2 = param_2 << (bVar1 & 0x1f);
        uVar8 = param_4 >> 0x10;
        uVar3 = uVar7;
        .urem(uVar7,uVar8);
        .udiv(uVar7,uVar8);
        uVar5 = uVar7;
        .umul();
        uVar9 = uVar3 << 0x10 | uVar11 >> 0x10;
        if (uVar9 < uVar5) {
          uVar9 = uVar9 + param_4;
          uVar6 = uVar7 - 1;
          if (param_4 <= uVar9) {
            if (uVar5 <= uVar9) {
              uVar9 = uVar9 - uVar5;
              goto loc_F0005848;
            }
            uVar6 = uVar7 - 2;
            uVar9 = uVar9 + param_4;
          }
          uVar9 = uVar9 - uVar5;
        }
        else {
          uVar9 = uVar9 - uVar5;
          uVar6 = uVar7;
        }
loc_F0005848:
        uVar3 = uVar9;
        .urem(uVar9,uVar8);
        .udiv(uVar9,uVar8);
        uVar7 = uVar9;
        .umul();
        uVar5 = uVar3 << 0x10 | uVar11 & 0xffff;
        uVar3 = uVar9;
        if (uVar5 < uVar7) {
          uVar5 = uVar5 + param_4;
          uVar3 = uVar9 - 1;
          if ((param_4 <= uVar5) && (uVar5 < uVar7)) {
            uVar5 = uVar5 + param_4;
            uVar3 = uVar9 - 2;
          }
        }
        uVar3 = uVar6 << 0x10 | uVar3;
        uVar5 = uVar5 - uVar7;
      }
      uVar9 = param_4 >> 0x10;
      uVar7 = uVar5;
      .urem(uVar5,uVar9);
      .udiv(uVar7,uVar9);
      .umul();
      uVar5 = uVar5 << 0x10 | param_2 >> 0x10;
      if (uVar5 < uVar7) {
        uVar5 = uVar5 + param_4;
        if (param_4 <= uVar5) {
          if (uVar7 <= uVar5) {
            uVar5 = uVar5 - uVar7;
            goto loc_F0005940;
          }
          uVar5 = uVar5 + param_4;
        }
        uVar5 = uVar5 - uVar7;
      }
      else {
        uVar5 = uVar5 - uVar7;
      }
loc_F0005940:
      uVar7 = uVar5;
      .urem(uVar5,uVar9);
      .udiv(uVar5,uVar9);
      .umul();
      uVar7 = uVar7 << 0x10 | param_2 & 0xffff;
      if (((uVar7 < uVar5) && (uVar7 = uVar7 + param_4, param_4 <= uVar7)) && (uVar7 < uVar5)) {
        uVar7 = uVar7 + param_4;
      }
      uVar7 = uVar7 - uVar5;
    }
    if (puVar4 == (undefined8 *)0x0) goto loc_F0005CA4;
    *(uint *)((int)register0x00000038 + -0x14) = uVar7 >> ((byte)iVar10 & 0x1f);
    *(undefined4 *)((int)register0x00000038 + -0x18) = 0;
  }
  else {
    if (param_1 < param_3) {
      uVar3 = 0;
      if (puVar4 == (undefined8 *)0x0) goto loc_F0005CA4;
      *(uint *)((int)register0x00000038 + -0x14) = param_2;
    }
    else {
      if (param_3 < 0x10000) {
        uVar3 = (param_3 < 0x100) - 1 & 8;
      }
      else {
        uVar3 = 0x18;
        if (param_3 < 0x1000000) {
          uVar3 = 0x10;
        }
      }
      iVar10 = 0x20 - ((byte)unk_F00F4A98[param_3 >> (sbyte)uVar3] + uVar3);
      bVar1 = (byte)iVar10;
      bVar12 = 0x20 - bVar1;
      if (iVar10 == 0) {
        if ((param_3 < param_1) || (uVar5 = param_2, param_4 <= param_2)) {
          uVar5 = param_2 - param_4;
          param_1 = (param_1 - param_3) - (uint)(param_2 < uVar5);
        }
        uVar3 = 0;
        if (puVar4 == (undefined8 *)0x0) goto loc_F0005CA4;
        *(uint *)((int)register0x00000038 + -0x14) = uVar5;
      }
      else {
        uVar11 = param_3 << (bVar1 & 0x1f) | param_4 >> (bVar12 & 0x1f);
        param_4 = param_4 << (bVar1 & 0x1f);
        uVar7 = param_1 >> (bVar12 & 0x1f);
        uVar8 = param_1 << (bVar1 & 0x1f) | param_2 >> (bVar12 & 0x1f);
        param_2 = param_2 << (bVar1 & 0x1f);
        uVar9 = uVar11 >> 0x10;
        uVar3 = uVar7;
        .urem(uVar7,uVar9);
        .udiv(uVar7,uVar9);
        uVar5 = uVar7;
        .umul();
        uVar3 = uVar3 << 0x10 | uVar8 >> 0x10;
        if (uVar3 < uVar5) {
          uVar3 = uVar3 + uVar11;
          uVar6 = uVar7 - 1;
          if (uVar11 <= uVar3) {
            if (uVar5 <= uVar3) {
              uVar3 = uVar3 - uVar5;
              goto loc_F0005B30;
            }
            uVar6 = uVar7 - 2;
            uVar3 = uVar3 + uVar11;
          }
          uVar3 = uVar3 - uVar5;
        }
        else {
          uVar3 = uVar3 - uVar5;
          uVar6 = uVar7;
        }
loc_F0005B30:
        uVar5 = uVar3;
        .urem(uVar3,uVar9);
        .udiv(uVar3,uVar9);
        uVar7 = uVar3;
        .umul();
        uVar9 = uVar5 << 0x10 | uVar8 & 0xffff;
        uVar5 = uVar3;
        if (uVar9 < uVar7) {
          uVar9 = uVar9 + uVar11;
          uVar5 = uVar3 - 1;
          if ((uVar11 <= uVar9) && (uVar9 < uVar7)) {
            uVar9 = uVar9 + uVar11;
            uVar5 = uVar3 - 2;
          }
        }
        uVar8 = uVar6 << 0x10 | uVar5;
        uVar9 = uVar9 - uVar7;
        uVar5 = uVar5 & 0xffff;
        uVar3 = uVar5;
        .umul(uVar5,param_4 & 0xffff);
        .umul(uVar5,param_4 >> 0x10);
        uVar8 = uVar8 >> 0x10;
        uVar7 = uVar8;
        .umul(uVar8,param_4 & 0xffff);
        .umul(uVar8,param_4 >> 0x10);
        uVar5 = uVar5 + (uVar3 >> 0x10) + uVar7;
        if (uVar5 < uVar7) {
          uVar8 = uVar8 + 0x10000;
        }
        uVar8 = uVar8 + (uVar5 >> 0x10);
        uVar3 = uVar5 * 0x10000 + (uVar3 & 0xffff);
        if ((uVar9 < uVar8) || ((uVar5 = uVar3, uVar8 == uVar9 && (param_2 < uVar3)))) {
          uVar5 = uVar3 - param_4;
          uVar8 = (uVar8 - uVar11) - (uint)(uVar3 < uVar5);
        }
        uVar3 = 0;
        if (puVar4 == (undefined8 *)0x0) goto loc_F0005CA4;
        param_1 = (uVar9 - uVar8) - (uint)(param_2 < param_2 - uVar5);
        *(uint *)((int)register0x00000038 + -0x14) =
             param_1 << (bVar12 & 0x1f) | param_2 - uVar5 >> (bVar1 & 0x1f);
        param_1 = param_1 >> (bVar1 & 0x1f);
      }
    }
    uVar3 = 0;
    *(uint *)((int)register0x00000038 + -0x18) = param_1;
  }
  *puVar4 = *(undefined8 *)((int)register0x00000038 + -0x18);
loc_F0005CA4:
  *(undefined4 *)((int)register0x00000038 + -0xc) = 0;
  *(uint *)((int)register0x00000038 + -0x10) = uVar3;
  return CONCAT44((int)*(undefined8 *)((int)register0x00000038 + -0x10),
                  (int)((qword)*(undefined8 *)((int)register0x00000038 + -0x10) >> 0x20));
}
/* GHIDRADEC_FUNCTION index=41 start=0xf0005cb8 */

/* WARNING: Removing unreachable block (ram,0xf0005d14) */
/* WARNING: Removing unreachable block (ram,0xf0005cf4) */
/* WARNING: Removing unreachable block (ram,0xf0005d28) */
/* WARNING: Removing unreachable block (ram,0xf0005cd0) */

undefined8 __divdi3(int param_1,undefined4 param_2,int param_3,undefined4 param_4)

{
  undefined4 unaff_l0;
  uint uVar1;
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
  uVar1 = 0;
  if (param_1 < 0) {
    uVar1 = 0xffffffff;
    __negdi2(param_1,param_2);
  }
  if (param_3 < 0) {
    uVar1 = ~uVar1;
    __negdi2(param_3,param_4);
  }
  __udivmoddi4(param_1,param_2,param_3,param_4,0);
  if (uVar1 != 0) {
    __negdi2();
  }
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=42 start=0xf0005d40 */

/* WARNING: Removing unreachable block (ram,0xf0005d9c) */
/* WARNING: Removing unreachable block (ram,0xf0005d7c) */
/* WARNING: Removing unreachable block (ram,0xf0005db0) */
/* WARNING: Removing unreachable block (ram,0xf0005d58) */
/* WARNING: Heritage AFTER dead removal. Example location: o1 : 0xf0005d9c */
/* WARNING: Restarted to delay deadcode elimination for space: register */

undefined4 __moddi3(uint param_1,undefined4 param_2)

{
  uint uVar1;
  sqword in_o0_1;
  undefined8 uVar2;
  undefined4 unaff_l0;
  int iVar3;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 uVar4;
  undefined8 in_i0_1;
  sqword sVar5;
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
    *(int *)(in_CWP * 0x40 + 0x8000) = (int)((qword)in_i0_1 >> 0x20);
    *(int *)((in_CWP * 0x10 + 1) * 4 + 0x8000) = (int)in_i0_1;
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
  uVar1 = (uint)((qword)in_o0_1 >> 0x20);
  iVar3 = 0;
  sVar5 = in_o0_1;
  if (in_o0_1 < 0) {
    iVar3 = -1;
    __negdi2(uVar1);
    sVar5 = (qword)uVar1 << 0x20;
  }
  uVar4 = (undefined4)((qword)sVar5 >> 0x20);
  if ((int)param_1 < 0) {
    __negdi2(param_1);
    param_1 = uVar1;
    param_2 = (int)in_o0_1;
  }
  __udivmoddi4(uVar4,(int)in_o0_1,param_1,param_2,(undefined *)((int)register0x00000038 + -0x10));
  uVar4 = (undefined4)((qword)*(undefined8 *)((int)register0x00000038 + -0x10) >> 0x20);
  if (iVar3 != 0) {
    uVar2 = *(undefined8 *)((int)register0x00000038 + -0x10);
    __negdi2((int)((qword)uVar2 >> 0x20));
    *(undefined8 *)((int)register0x00000038 + -0x10) = uVar2;
    uVar4 = (undefined4)((qword)*(undefined8 *)((int)register0x00000038 + -0x10) >> 0x20);
  }
  return uVar4;
}
/* GHIDRADEC_FUNCTION index=43 start=0xf0005dc8 */

/* WARNING: Removing unreachable block (ram,0xf0005ddc) */

undefined8 __umoddi3(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined8 in_i0_1;
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
    *(int *)(in_CWP * 0x40 + 0x8000) = (int)((qword)in_i0_1 >> 0x20);
    *(int *)((in_CWP * 0x10 + 1) * 4 + 0x8000) = (int)in_i0_1;
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
  __udivmoddi4(param_1,param_2,param_3,param_4,(undefined *)((int)register0x00000038 + -0x10));
  return CONCAT44((int)*(undefined8 *)((int)register0x00000038 + -0x10),
                  (int)((qword)*(undefined8 *)((int)register0x00000038 + -0x10) >> 0x20));
}
/* GHIDRADEC_FUNCTION index=44 start=0xf0005df0 */

/* WARNING: Removing unreachable block (ram,0xf0005e04) */

undefined8 __udivdi3(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
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
  __udivmoddi4(param_1,param_2,param_3,param_4,0);
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=45 start=0xf0005e1c */

undefined8 __cmpdi2(int param_1,uint param_2,int param_3,uint param_4)

{
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  undefined4 uVar1;
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
  if (param_1 < param_3) {
    uVar1 = 0;
  }
  else if (param_3 < param_1) {
    uVar1 = 2;
  }
  else if (param_2 < param_4) {
    uVar1 = 0;
  }
  else {
    uVar1 = 2;
    if (param_2 <= param_4) {
      uVar1 = 1;
    }
  }
  return CONCAT44(param_2,uVar1);
}
/* GHIDRADEC_FUNCTION index=46 start=0xf0005e60 */

undefined8 __ucmpdi2(uint param_1,uint param_2,uint param_3,uint param_4)

{
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  undefined4 uVar1;
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
  if (param_1 < param_3) {
    uVar1 = 0;
  }
  else if (param_3 < param_1) {
    uVar1 = 2;
  }
  else if (param_2 < param_4) {
    uVar1 = 0;
  }
  else {
    uVar1 = 2;
    if (param_2 <= param_4) {
      uVar1 = 1;
    }
  }
  return CONCAT44(param_2,uVar1);
}
/* GHIDRADEC_FUNCTION index=47 start=0xf0005ea4 */

undefined8 _memchr(char *param_1,undefined4 param_2,int param_3)

{
  char cVar1;
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
  param_3 = param_3 + -1;
  if (param_3 < 0) {
loc_F0005EDC:
    param_1 = (char *)0x0;
  }
  else {
    cVar1 = *param_1;
    while (cVar1 != (char)param_2) {
      param_3 = param_3 + -1;
      if (param_3 < 0) goto loc_F0005EDC;
      cVar1 = param_1[1];
      param_1 = param_1 + 1;
    }
  }
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=48 start=0xf0005ee8 */

undefined8 _strncat(char *param_1,char *param_2,int param_3)

{
  char cVar1;
  char *pcVar2;
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
  cVar1 = *param_1;
  pcVar2 = param_1;
  while (cVar1 != '\0') {
    cVar1 = pcVar2[1];
    pcVar2 = pcVar2 + 1;
  }
  cVar1 = *param_2;
  do {
    *pcVar2 = cVar1;
    param_2 = param_2 + 1;
    if (cVar1 == '\0') {
locret_F0005F40:
      return CONCAT44(param_2,param_1);
    }
    param_3 = param_3 + -1;
    if (param_3 < 0) {
      *pcVar2 = '\0';
      goto locret_F0005F40;
    }
    cVar1 = *param_2;
    pcVar2 = pcVar2 + 1;
  } while( true );
}
/* GHIDRADEC_FUNCTION index=49 start=0xf0005f48 */

int _abs(int param_1)

{
  if (param_1 < 0) {
    param_1 = -param_1;
  }
  return param_1;
}

