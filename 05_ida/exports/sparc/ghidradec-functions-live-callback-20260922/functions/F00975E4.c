
/* WARNING: Control flow encountered unimplemented instructions */
/* WARNING: Removing unreachable block (ram,0xf0097678) */

void wu_chk_flt(void)

{
  undefined4 unaff_g1;
  undefined8 in_g2_3;
  undefined4 unaff_g4;
  byte bVar1;
  undefined4 unaff_g5;
  undefined8 in_g6_7;
  undefined *puVar2;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  uint unaff_l4;
  undefined4 unaff_l5;
  undefined (*pauVar3) [676];
  undefined4 uVar4;
  undefined4 unaff_i0;
  undefined4 uVar5;
  undefined4 unaff_i1;
  undefined4 uVar6;
  undefined4 unaff_i2;
  undefined4 uVar7;
  undefined4 unaff_i3;
  undefined4 uVar8;
  undefined4 unaff_i4;
  undefined4 uVar9;
  undefined4 unaff_i5;
  undefined4 uVar10;
  undefined *unaff_fp;
  undefined *puVar11;
  undefined4 unaff_i7;
  undefined4 uVar12;
  undefined4 in_Y;
  bool in_DECOMPILE_MODE;
  int in_TL;
  int in_CWP;
  int iVar13;
  
  pauVar3 = _active_pcb;
  if ((unaff_l4 & 2) != 0) {
    uVar4 = *(undefined4 *)(*_active_pcb + 0x2a0);
    *(undefined4 *)(*_active_pcb + 0x244) = unaff_g1;
    *(undefined8 *)(*pauVar3 + 0x248) = in_g2_3;
    *(qword *)(*pauVar3 + 0x250) = CONCAT44(unaff_g4,unaff_g5);
    *(undefined8 *)(*pauVar3 + 600) = in_g6_7;
    *(undefined4 *)(*pauVar3 + 0x240) = in_Y;
    iVar13 = in_CWP + -1;
    uVar5 = unaff_i0;
    uVar6 = unaff_i1;
    uVar7 = unaff_i2;
    uVar8 = unaff_i3;
    uVar9 = unaff_i4;
    uVar10 = unaff_i5;
    puVar11 = unaff_fp;
    uVar12 = unaff_i7;
    if (!in_DECOMPILE_MODE) {
      uVar5 = *(undefined4 *)(iVar13 * 0x40 + 0x8000);
      uVar6 = *(undefined4 *)((iVar13 * 0x10 + 1) * 4 + 0x8000);
      uVar7 = *(undefined4 *)((iVar13 * 0x10 + 2) * 4 + 0x8000);
      uVar8 = *(undefined4 *)((iVar13 * 0x10 + 3) * 4 + 0x8000);
      uVar9 = *(undefined4 *)((iVar13 * 0x10 + 4) * 4 + 0x8000);
      uVar10 = *(undefined4 *)((iVar13 * 0x10 + 5) * 4 + 0x8000);
      puVar11 = *(undefined **)((iVar13 * 0x10 + 6) * 4 + 0x8000);
      uVar12 = *(undefined4 *)((iVar13 * 0x10 + 7) * 4 + 0x8000);
      unaff_l0 = *(undefined4 *)((iVar13 * 0x10 + 8) * 4 + 0x8000);
      unaff_l1 = *(undefined4 *)((iVar13 * 0x10 + 9) * 4 + 0x8000);
      unaff_l3 = *(undefined4 *)((iVar13 * 0x10 + 0xb) * 4 + 0x8000);
      unaff_l4 = *(uint *)((iVar13 * 0x10 + 0xc) * 4 + 0x8000);
      unaff_l5 = *(undefined4 *)((iVar13 * 0x10 + 0xd) * 4 + 0x8000);
      pauVar3 = *(undefined (**) [676])((iVar13 * 0x10 + 0xe) * 4 + 0x8000);
      uVar4 = *(undefined4 *)((iVar13 * 0x10 + 0xe) * 4 + 0x8000);
    }
    bVar1 = (byte)*(undefined4 *)
                   ((uint)(in_TL == 1) * 0x7000 + (uint)(in_TL == 2) * 0x7004 +
                    (uint)(in_TL == 3) * 0x7008 + (uint)(in_TL == 4) * 0x700c);
    if (!in_DECOMPILE_MODE) {
      *(undefined4 *)(iVar13 * 0x40 + 0x8000) = uVar5;
      *(undefined4 *)((iVar13 * 0x10 + 1) * 4 + 0x8000) = uVar6;
      *(undefined4 *)((iVar13 * 0x10 + 2) * 4 + 0x8000) = uVar7;
      *(undefined4 *)((iVar13 * 0x10 + 3) * 4 + 0x8000) = uVar8;
      *(undefined4 *)((iVar13 * 0x10 + 4) * 4 + 0x8000) = uVar9;
      *(undefined4 *)((iVar13 * 0x10 + 5) * 4 + 0x8000) = uVar10;
      *(undefined **)((iVar13 * 0x10 + 6) * 4 + 0x8000) = puVar11;
      *(undefined4 *)((iVar13 * 0x10 + 7) * 4 + 0x8000) = uVar12;
      *(undefined4 *)((iVar13 * 0x10 + 8) * 4 + 0x8000) = unaff_l0;
      *(undefined4 *)((iVar13 * 0x10 + 9) * 4 + 0x8000) = unaff_l1;
      *(undefined4 *)((iVar13 * 0x10 + 10) * 4 + 0x8000) = unaff_l3;
      *(undefined4 *)((iVar13 * 0x10 + 0xb) * 4 + 0x8000) = unaff_l3;
      *(uint *)((iVar13 * 0x10 + 0xc) * 4 + 0x8000) = unaff_l4;
      *(undefined4 *)((iVar13 * 0x10 + 0xd) * 4 + 0x8000) = unaff_l5;
      *(undefined (**) [676])((iVar13 * 0x10 + 0xe) * 4 + 0x8000) = pauVar3;
      *(undefined4 *)((iVar13 * 0x10 + 0xf) * 4 + 0x8000) = uVar4;
    }
    uVar5 = 0;
    uVar6 = 0;
    uVar7 = 0;
    iVar13 = 0;
    puVar2 = (undefined *)0x0;
    uRam00000260 = CONCAT44(unaff_i0,unaff_i1);
    uRam00000268 = CONCAT44(unaff_i2,unaff_i3);
    uRam00000270 = CONCAT44(unaff_i4,unaff_i5);
    uRam00000278 = CONCAT44(unaff_fp,unaff_i7);
    uRam00000234 = 0;
    uRam00000238 = 0;
    uRam0000023c = 0;
    *(undefined4 *)
     ((uint)(in_TL == 1) * 0x6000 + (uint)(in_TL == 2) * 0x6004 + (uint)(in_TL == 3) * 0x6008 +
     (uint)(in_TL == 4) * 0x600c) = 0;
    *(int *)(iVar13 + 0xc) = 1 << (bVar1 & 0x1f);
    *(undefined4 *)(iVar13 + 0x230) = 0;
    _trap(9,iVar13 + 0x234,uVar7,uVar6,2);
    *(undefined4 *)(puVar2 + 0x5c) = uVar5;
    sys_rtt();
    return;
  }
  if ((*(uint *)(*_active_pcb + 0x294) & 1) == 0) {
                    /* WARNING: Unimplemented instruction - Truncating control flow here */
    halt_unimplemented();
  }
                    /* WARNING: Unimplemented instruction - Truncating control flow here */
  halt_unimplemented();
}

