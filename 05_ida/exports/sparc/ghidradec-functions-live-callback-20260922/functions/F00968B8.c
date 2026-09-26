
/* WARNING: Control flow encountered unimplemented instructions */
/* WARNING: Removing unreachable block (ram,0xf00969f0) */

void wo_chk_flt(void)

{
  undefined (*pauVar1) [676];
  uint unaff_g1;
  undefined8 *puVar2;
  undefined8 in_g4_5;
  undefined8 in_g6_7;
  undefined *puVar3;
  int iVar4;
  uint unaff_l0;
  undefined4 unaff_l1;
  undefined4 unaff_l2;
  uint unaff_l3;
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
  undefined4 in_Y;
  bool in_DECOMPILE_MODE;
  int in_TL;
  int in_CWP;
  int iVar5;
  undefined auStackX_0 [92];
  
  pauVar1 = _active_pcb;
  if ((unaff_g1 & 2) != 0) {
    if ((*(uint *)((uint)(in_TL == 1) * 0x7000 + (uint)(in_TL == 2) * 0x7004 +
                   (uint)(in_TL == 3) * 0x7008 + (uint)(in_TL == 4) * 0x700c) & 0x40) == 0) {
      *(BADSPACEBASE **)(*_active_pcb + 0x210) = register0x00000038;
      *(qword *)(*pauVar1 + 0x10) = CONCAT44(unaff_l0,unaff_l1);
      *(qword *)(*pauVar1 + 0x18) = CONCAT44(unaff_l2,unaff_l3);
      *(qword *)(*pauVar1 + 0x20) = CONCAT44(unaff_l4,unaff_l5);
      *(qword *)(*pauVar1 + 0x28) = CONCAT44(unaff_l6,unaff_l7);
      *(qword *)(*pauVar1 + 0x30) = CONCAT44(unaff_i0,unaff_i1);
      *(qword *)(*pauVar1 + 0x38) = CONCAT44(unaff_i2,unaff_i3);
      *(qword *)(*pauVar1 + 0x40) = CONCAT44(unaff_i4,unaff_i5);
      *(qword *)(*pauVar1 + 0x48) = CONCAT44(unaff_fp,unaff_i7);
      pauVar1 = _active_pcb;
      iVar5 = in_CWP + -1;
      if (!in_DECOMPILE_MODE) {
        unaff_i0 = *(undefined4 *)(iVar5 * 0x40 + 0x8000);
        unaff_i1 = *(undefined4 *)((iVar5 * 0x10 + 1) * 4 + 0x8000);
        unaff_i2 = *(undefined4 *)((iVar5 * 0x10 + 2) * 4 + 0x8000);
        unaff_i3 = *(undefined4 *)((iVar5 * 0x10 + 3) * 4 + 0x8000);
        unaff_i4 = *(undefined4 *)((iVar5 * 0x10 + 4) * 4 + 0x8000);
        unaff_i5 = *(undefined4 *)((iVar5 * 0x10 + 5) * 4 + 0x8000);
        unaff_fp = *(undefined4 *)((iVar5 * 0x10 + 6) * 4 + 0x8000);
        unaff_i7 = *(undefined4 *)((iVar5 * 0x10 + 7) * 4 + 0x8000);
        unaff_l0 = *(uint *)((iVar5 * 0x10 + 8) * 4 + 0x8000);
        unaff_l1 = *(undefined4 *)((iVar5 * 0x10 + 9) * 4 + 0x8000);
        unaff_l2 = *(undefined4 *)((iVar5 * 0x10 + 10) * 4 + 0x8000);
        unaff_l3 = *(uint *)((iVar5 * 0x10 + 0xb) * 4 + 0x8000);
        unaff_l4 = *(undefined4 *)((iVar5 * 0x10 + 0xc) * 4 + 0x8000);
        unaff_l5 = *(undefined4 *)((iVar5 * 0x10 + 0xd) * 4 + 0x8000);
        unaff_l6 = *(undefined4 *)((iVar5 * 0x10 + 0xe) * 4 + 0x8000);
        unaff_l7 = *(undefined4 *)((iVar5 * 0x10 + 0xe) * 4 + 0x8000);
      }
      *(uint *)(*_active_pcb + 0xc) =
           ((*(uint *)((uint)(in_TL == 1) * 0x6000 + (uint)(in_TL == 2) * 0x6004 +
                       (uint)(in_TL == 3) * 0x6008 + (uint)(in_TL == 4) * 0x600c) | unaff_l3) ^
           0xffffffff) & ~(-2 << ((byte)unaff_l6 & 0x1f));
      *(undefined4 *)(*pauVar1 + 0x230) = 1;
      iVar4 = *(int *)(*pauVar1 + 0x2a0);
      if ((unaff_l0 & 0x40) == 0) {
        *(undefined4 *)(*pauVar1 + 0x244) = unaff_l7;
        *(qword *)(*pauVar1 + 0x248) = CONCAT44(unaff_l5,unaff_l4);
        *(undefined8 *)(*pauVar1 + 0x250) = in_g4_5;
        *(undefined8 *)(*pauVar1 + 600) = in_g6_7;
        *(undefined4 *)(*pauVar1 + 0x240) = in_Y;
        *(qword *)(*pauVar1 + 0x260) = CONCAT44(unaff_i0,unaff_i1);
        *(qword *)(*pauVar1 + 0x268) = CONCAT44(unaff_i2,unaff_i3);
        *(qword *)(*pauVar1 + 0x270) = CONCAT44(unaff_i4,unaff_i5);
        *(qword *)(*pauVar1 + 0x278) = CONCAT44(unaff_fp,unaff_i7);
        *(uint *)(*pauVar1 + 0x234) = unaff_l0;
        *(undefined4 *)(*pauVar1 + 0x238) = unaff_l1;
        *(undefined4 *)(*pauVar1 + 0x23c) = unaff_l2;
        *(uint *)(iVar4 + 0x5c) = unaff_l0;
        puVar3 = *pauVar1 + 0x234;
      }
      else {
        *(undefined4 *)(iVar4 + 0x6c) = unaff_l7;
        *(qword *)(iVar4 + 0x70) = CONCAT44(unaff_l5,unaff_l4);
        *(undefined8 *)(iVar4 + 0x78) = in_g4_5;
        *(undefined8 *)(iVar4 + 0x80) = in_g6_7;
        *(undefined4 *)(iVar4 + 0x68) = in_Y;
        *(qword *)(iVar4 + 0x88) = CONCAT44(unaff_i0,unaff_i1);
        *(qword *)(iVar4 + 0x90) = CONCAT44(unaff_i2,unaff_i3);
        *(qword *)(iVar4 + 0x98) = CONCAT44(unaff_i4,unaff_i5);
        *(qword *)(iVar4 + 0xa0) = CONCAT44(unaff_fp,unaff_i7);
        *(uint *)(iVar4 + 0x5c) = unaff_l0;
        *(undefined4 *)(iVar4 + 0x60) = unaff_l1;
        *(undefined4 *)(iVar4 + 100) = unaff_l2;
        puVar3 = (undefined *)(iVar4 + 0x5c);
      }
      _trap(9,puVar3);
      sys_rtt();
      return;
    }
    iVar5 = *(int *)(*_active_pcb + 0x230);
    *(BADSPACEBASE **)(*_active_pcb + iVar5 * 4 + 0x210) = register0x00000038;
    puVar2 = (undefined8 *)(*pauVar1 + 0x10 + (iVar5 << 6));
    *puVar2 = CONCAT44(unaff_l0,unaff_l1);
    puVar2[1] = CONCAT44(unaff_l2,unaff_l3);
    puVar2[2] = CONCAT44(unaff_l4,unaff_l5);
    puVar2[3] = CONCAT44(unaff_l6,unaff_l7);
    puVar2[4] = CONCAT44(unaff_i0,unaff_i1);
    puVar2[5] = CONCAT44(unaff_i2,unaff_i3);
    puVar2[6] = CONCAT44(unaff_i4,unaff_i5);
    puVar2[7] = CONCAT44(unaff_fp,unaff_i7);
    *(uint *)(*_active_pcb + 0x230) = ((uint)((int)puVar2 - (int)(*pauVar1 + 0x10)) >> 6) + 1;
                    /* WARNING: Unimplemented instruction - Truncating control flow here */
    halt_unimplemented();
  }
  if ((*(uint *)(*_active_pcb + 0x294) & 1) == 0) {
                    /* WARNING: Unimplemented instruction - Truncating control flow here */
    halt_unimplemented();
  }
                    /* WARNING: Unimplemented instruction - Truncating control flow here */
  halt_unimplemented();
}

