
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
    _trap(9,*_active_pcb + 0x234,uVar2,unaff_g1,2);
    sys_rtt();
    return;
  }
  uVar8 = *(uint *)(*_active_pcb + 0x294);
  if (((unaff_l1 | *(uint *)(*_active_pcb + 0x23c)) & 3) != 0) {
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

