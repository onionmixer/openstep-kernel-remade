
/* WARNING: Control flow encountered unimplemented instructions */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void window_overflow(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                    undefined4 param_5,undefined4 param_6)

{
  undefined4 unaff_g1;
  uint uVar1;
  undefined4 unaff_g2;
  undefined4 unaff_g3;
  undefined4 in_o7;
  uint unaff_l0;
  undefined4 unaff_l1;
  undefined4 uVar2;
  undefined4 uVar3;
  uint uVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  uint uVar7;
  undefined4 uVar8;
  undefined4 uVar9;
  int iVar10;
  undefined4 uVar11;
  undefined4 uVar12;
  undefined4 unaff_i0;
  undefined4 unaff_i1;
  undefined4 unaff_i2;
  undefined4 unaff_i3;
  undefined4 unaff_i4;
  undefined4 unaff_i5;
  undefined4 unaff_fp;
  undefined *puVar13;
  undefined4 unaff_i7;
  undefined in_DECOMPILE_MODE;
  int in_TL;
  int in_CWP;
  undefined auStackX_0 [92];
  
  iVar10 = __nwindows + -1;
  uVar4 = *(uint *)((uint)(in_TL == 1) * 0x6000 + (uint)(in_TL == 2) * 0x6004 +
                    (uint)(in_TL == 3) * 0x6008 + (uint)(in_TL == 4) * 0x600c);
  uVar1 = uVar4 << ((byte)iVar10 & 0x1f) | uVar4 >> 1;
  if ((unaff_l0 & 0x40) != 0) {
    uVar7 = *(uint *)(*_active_pcb + 0xc);
    if (uVar7 == 0) {
      if (!(bool)in_DECOMPILE_MODE) {
        *(undefined4 *)(in_CWP * 0x40 + 0x8000) = unaff_i0;
        *(undefined4 *)((in_CWP * 0x10 + 1) * 4 + 0x8000) = unaff_i1;
        *(undefined4 *)((in_CWP * 0x10 + 2) * 4 + 0x8000) = unaff_i2;
        *(undefined4 *)((in_CWP * 0x10 + 3) * 4 + 0x8000) = unaff_i3;
        *(undefined4 *)((in_CWP * 0x10 + 4) * 4 + 0x8000) = unaff_i4;
        *(undefined4 *)((in_CWP * 0x10 + 5) * 4 + 0x8000) = unaff_i5;
        *(undefined4 *)((in_CWP * 0x10 + 6) * 4 + 0x8000) = unaff_fp;
        *(undefined4 *)((in_CWP * 0x10 + 7) * 4 + 0x8000) = unaff_i7;
        *(uint *)((in_CWP * 0x10 + 8) * 4 + 0x8000) = unaff_l0;
        *(undefined4 *)((in_CWP * 0x10 + 9) * 4 + 0x8000) = unaff_l1;
        *(uint *)((in_CWP * 0x10 + 10) * 4 + 0x8000) = uVar4;
        *(uint *)((in_CWP * 0x10 + 0xb) * 4 + 0x8000) = uVar4;
        *(uint *)((in_CWP * 0x10 + 0xc) * 4 + 0x8000) = uVar7;
        *(undefined4 *)((in_CWP * 0x10 + 0xd) * 4 + 0x8000) = unaff_g2;
        *(int *)((in_CWP * 0x10 + 0xe) * 4 + 0x8000) = iVar10;
        *(undefined4 *)((in_CWP * 0x10 + 0xf) * 4 + 0x8000) = unaff_g1;
      }
      uVar6 = 0;
      uVar2 = 0;
      uVar3 = 0;
      uVar5 = 0;
      uVar8 = 0;
      uVar9 = 0;
      uVar11 = 0;
      uVar12 = 0;
      puVar13 = (undefined *)register0x00000038;
      *(uint *)((uint)(in_TL == 1) * 0x6000 + (uint)(in_TL == 2) * 0x6004 +
                (uint)(in_TL == 3) * 0x6008 + (uint)(in_TL == 4) * 0x600c) = uVar1;
      *(qword *)register0x00000038 = CONCAT44(uVar6,uVar2);
      *(qword *)((int)register0x00000038 + 8) = CONCAT44(uVar3,uVar5);
      *(qword *)((int)register0x00000038 + 0x10) = CONCAT44(uVar8,uVar9);
      *(qword *)((int)register0x00000038 + 0x18) = CONCAT44(uVar11,uVar12);
      *(qword *)((int)register0x00000038 + 0x20) = CONCAT44(param_1,param_2);
      *(qword *)((int)register0x00000038 + 0x28) = CONCAT44(param_3,param_4);
      *(qword *)((int)register0x00000038 + 0x30) = CONCAT44(param_5,param_6);
      *(qword *)((int)register0x00000038 + 0x38) = CONCAT44(puVar13,in_o7);
                    /* WARNING: Unimplemented instruction - Truncating control flow here */
      halt_unimplemented();
    }
    *(uint *)(*_active_pcb + 0xc) = uVar7 & ~uVar1;
  }
  if (!(bool)in_DECOMPILE_MODE) {
    *(undefined4 *)(in_CWP * 0x40 + 0x8000) = unaff_i0;
    *(undefined4 *)((in_CWP * 0x10 + 1) * 4 + 0x8000) = unaff_i1;
    *(undefined4 *)((in_CWP * 0x10 + 2) * 4 + 0x8000) = unaff_i2;
    *(undefined4 *)((in_CWP * 0x10 + 3) * 4 + 0x8000) = unaff_i3;
    *(undefined4 *)((in_CWP * 0x10 + 4) * 4 + 0x8000) = unaff_i4;
    *(undefined4 *)((in_CWP * 0x10 + 5) * 4 + 0x8000) = unaff_i5;
    *(undefined4 *)((in_CWP * 0x10 + 6) * 4 + 0x8000) = unaff_fp;
    *(undefined4 *)((in_CWP * 0x10 + 7) * 4 + 0x8000) = unaff_i7;
    *(uint *)((in_CWP * 0x10 + 8) * 4 + 0x8000) = unaff_l0;
    *(undefined4 *)((in_CWP * 0x10 + 9) * 4 + 0x8000) = unaff_l1;
    *(uint *)((in_CWP * 0x10 + 10) * 4 + 0x8000) = uVar4;
    *(uint *)((in_CWP * 0x10 + 0xb) * 4 + 0x8000) = uVar4;
    *(undefined4 *)((in_CWP * 0x10 + 0xc) * 4 + 0x8000) = unaff_g3;
    *(undefined4 *)((in_CWP * 0x10 + 0xd) * 4 + 0x8000) = unaff_g2;
    *(int *)((in_CWP * 0x10 + 0xe) * 4 + 0x8000) = iVar10;
    *(undefined4 *)((in_CWP * 0x10 + 0xf) * 4 + 0x8000) = unaff_g1;
  }
  uVar6 = 0;
  iVar10 = in_CWP + 1;
  *(uint *)((uint)(in_TL == 1) * 0x6000 + (uint)(in_TL == 2) * 0x6004 + (uint)(in_TL == 3) * 0x6008
           + (uint)(in_TL == 4) * 0x600c) = uVar1;
  if (((uint)register0x00000038 & 7) != 0) {
    if ((*(uint *)((uint)(in_TL == 1) * 0x7000 + (uint)(in_TL == 2) * 0x7004 +
                   (uint)(in_TL == 3) * 0x7008 + (uint)(in_TL == 4) * 0x700c) & 0x40) == 0) {
      if (!(bool)in_DECOMPILE_MODE) {
        uVar6 = *(undefined4 *)(((iVar10 + -1) * 0x10 + 0xb) * 4 + 0x8000);
      }
      *(undefined4 *)
       ((uint)(in_TL == 1) * 0x6000 + (uint)(in_TL == 2) * 0x6004 + (uint)(in_TL == 3) * 0x6008 +
       (uint)(in_TL == 4) * 0x600c) = uVar6;
      sys_trap(param_1,param_2,param_3,param_4,param_5,param_6);
      return;
    }
    return;
  }
  if (register0x00000038 < &dword_F0000000) {
                    /* WARNING: Could not recover jumptable at 0xf00968b0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (*_v_mmu_wo)();
    return;
  }
  return;
}
