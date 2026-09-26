
/* WARNING: Control flow encountered unimplemented instructions */
/* WARNING: Removing unreachable block (ram,0xf00969f0) */

void wo_chk_flt(void)

{
  uint unaff_g1;
  undefined8 *puVar1;
  undefined8 in_g4_5;
  undefined8 in_g6_7;
  int iVar2;
  int iVar3;
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
  int iVar4;
  undefined auStackX_0 [92];
  
  iVar2 = _active_pcb;
  if ((unaff_g1 & 2) != 0) {
    if ((*(uint *)((uint)(in_TL == 1) * 0x7000 + (uint)(in_TL == 2) * 0x7004 +
                   (uint)(in_TL == 3) * 0x7008 + (uint)(in_TL == 4) * 0x700c) & 0x40) == 0) {
      *(BADSPACEBASE **)(_active_pcb + 0x210) = register0x00000038;
      *(qword *)(iVar2 + 0x10) = CONCAT44(unaff_l0,unaff_l1);
      *(qword *)(iVar2 + 0x18) = CONCAT44(unaff_l2,unaff_l3);
      *(qword *)(iVar2 + 0x20) = CONCAT44(unaff_l4,unaff_l5);
      *(qword *)(iVar2 + 0x28) = CONCAT44(unaff_l6,unaff_l7);
      *(qword *)(iVar2 + 0x30) = CONCAT44(unaff_i0,unaff_i1);
      *(qword *)(iVar2 + 0x38) = CONCAT44(unaff_i2,unaff_i3);
      *(qword *)(iVar2 + 0x40) = CONCAT44(unaff_i4,unaff_i5);
      *(qword *)(iVar2 + 0x48) = CONCAT44(unaff_fp,unaff_i7);
      iVar2 = _active_pcb;
      iVar4 = in_CWP + -1;
      if (!in_DECOMPILE_MODE) {
        unaff_i0 = *(undefined4 *)(iVar4 * 0x40 + 0x8000);
        unaff_i1 = *(undefined4 *)((iVar4 * 0x10 + 1) * 4 + 0x8000);
        unaff_i2 = *(undefined4 *)((iVar4 * 0x10 + 2) * 4 + 0x8000);
        unaff_i3 = *(undefined4 *)((iVar4 * 0x10 + 3) * 4 + 0x8000);
        unaff_i4 = *(undefined4 *)((iVar4 * 0x10 + 4) * 4 + 0x8000);
        unaff_i5 = *(undefined4 *)((iVar4 * 0x10 + 5) * 4 + 0x8000);
        unaff_fp = *(undefined4 *)((iVar4 * 0x10 + 6) * 4 + 0x8000);
        unaff_i7 = *(undefined4 *)((iVar4 * 0x10 + 7) * 4 + 0x8000);
        unaff_l0 = *(uint *)((iVar4 * 0x10 + 8) * 4 + 0x8000);
        unaff_l1 = *(undefined4 *)((iVar4 * 0x10 + 9) * 4 + 0x8000);
        unaff_l2 = *(undefined4 *)((iVar4 * 0x10 + 10) * 4 + 0x8000);
        unaff_l3 = *(uint *)((iVar4 * 0x10 + 0xb) * 4 + 0x8000);
        unaff_l4 = *(undefined4 *)((iVar4 * 0x10 + 0xc) * 4 + 0x8000);
        unaff_l5 = *(undefined4 *)((iVar4 * 0x10 + 0xd) * 4 + 0x8000);
        unaff_l6 = *(undefined4 *)((iVar4 * 0x10 + 0xe) * 4 + 0x8000);
        unaff_l7 = *(undefined4 *)((iVar4 * 0x10 + 0xe) * 4 + 0x8000);
      }
      *(uint *)(_active_pcb + 0xc) =
           ((*(uint *)((uint)(in_TL == 1) * 0x6000 + (uint)(in_TL == 2) * 0x6004 +
                       (uint)(in_TL == 3) * 0x6008 + (uint)(in_TL == 4) * 0x600c) | unaff_l3) ^
           0xffffffff) & ~(-2 << ((byte)unaff_l6 & 0x1f));
      *(undefined4 *)(iVar2 + 0x230) = 1;
      iVar3 = *(int *)(iVar2 + 0x2a0);
      if ((unaff_l0 & 0x40) == 0) {
        *(undefined4 *)(iVar2 + 0x244) = unaff_l7;
        *(qword *)(iVar2 + 0x248) = CONCAT44(unaff_l5,unaff_l4);
        *(undefined8 *)(iVar2 + 0x250) = in_g4_5;
        *(undefined8 *)(iVar2 + 600) = in_g6_7;
        *(undefined4 *)(iVar2 + 0x240) = in_Y;
        *(qword *)(iVar2 + 0x260) = CONCAT44(unaff_i0,unaff_i1);
        *(qword *)(iVar2 + 0x268) = CONCAT44(unaff_i2,unaff_i3);
        *(qword *)(iVar2 + 0x270) = CONCAT44(unaff_i4,unaff_i5);
        *(qword *)(iVar2 + 0x278) = CONCAT44(unaff_fp,unaff_i7);
        *(uint *)(iVar2 + 0x234) = unaff_l0;
        *(undefined4 *)(iVar2 + 0x238) = unaff_l1;
        *(undefined4 *)(iVar2 + 0x23c) = unaff_l2;
        *(uint *)(iVar3 + 0x5c) = unaff_l0;
        iVar2 = iVar2 + 0x234;
      }
      else {
        *(undefined4 *)(iVar3 + 0x6c) = unaff_l7;
        *(qword *)(iVar3 + 0x70) = CONCAT44(unaff_l5,unaff_l4);
        *(undefined8 *)(iVar3 + 0x78) = in_g4_5;
        *(undefined8 *)(iVar3 + 0x80) = in_g6_7;
        *(undefined4 *)(iVar3 + 0x68) = in_Y;
        *(qword *)(iVar3 + 0x88) = CONCAT44(unaff_i0,unaff_i1);
        *(qword *)(iVar3 + 0x90) = CONCAT44(unaff_i2,unaff_i3);
        *(qword *)(iVar3 + 0x98) = CONCAT44(unaff_i4,unaff_i5);
        *(qword *)(iVar3 + 0xa0) = CONCAT44(unaff_fp,unaff_i7);
        *(uint *)(iVar3 + 0x5c) = unaff_l0;
        *(undefined4 *)(iVar3 + 0x60) = unaff_l1;
        *(undefined4 *)(iVar3 + 100) = unaff_l2;
        iVar2 = iVar3 + 0x5c;
      }
      _trap(9,iVar2);
      sys_rtt();
      return;
    }
    iVar4 = *(int *)(_active_pcb + 0x230) * 4 + _active_pcb;
    *(BADSPACEBASE **)(iVar4 + 0x210) = register0x00000038;
    puVar1 = (undefined8 *)((iVar4 - iVar2) * 0x10 + iVar2 + 0x10);
    *puVar1 = CONCAT44(unaff_l0,unaff_l1);
    puVar1[1] = CONCAT44(unaff_l2,unaff_l3);
    puVar1[2] = CONCAT44(unaff_l4,unaff_l5);
    puVar1[3] = CONCAT44(unaff_l6,unaff_l7);
    puVar1[4] = CONCAT44(unaff_i0,unaff_i1);
    puVar1[5] = CONCAT44(unaff_i2,unaff_i3);
    puVar1[6] = CONCAT44(unaff_i4,unaff_i5);
    puVar1[7] = CONCAT44(unaff_fp,unaff_i7);
    *(uint *)(_active_pcb + 0x230) = ((uint)((int)puVar1 - (iVar2 + 0x10)) >> 6) + 1;
                    /* WARNING: Unimplemented instruction - Truncating control flow here */
    halt_unimplemented();
  }
  if ((*(uint *)(_active_pcb + 0x294) & 1) == 0) {
                    /* WARNING: Unimplemented instruction - Truncating control flow here */
    halt_unimplemented();
  }
                    /* WARNING: Unimplemented instruction - Truncating control flow here */
  halt_unimplemented();
}
