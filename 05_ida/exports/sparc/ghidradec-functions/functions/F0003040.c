
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
