
/* WARNING: Control flow encountered unimplemented instructions */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void window_underflow(void)

{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined8 *puVar5;
  qword in_l0_1;
  undefined8 uVar6;
  uint uVar7;
  undefined4 uVar8;
  uint uVar9;
  undefined4 uVar10;
  undefined8 uVar11;
  int iVar12;
  undefined8 uVar13;
  undefined8 in_i0_1;
  undefined8 uVar14;
  undefined8 in_i2_3;
  undefined8 uVar15;
  undefined8 in_i4_5;
  undefined8 uVar16;
  qword in_fp_7;
  undefined8 uVar17;
  qword qVar18;
  undefined in_DECOMPILE_MODE;
  int in_TL;
  int in_CWP;
  int iVar19;
  
  iVar12 = __nwindows + -1;
  uVar7 = *(uint *)((uint)(in_TL == 1) * 0x6000 + (uint)(in_TL == 2) * 0x6004 +
                    (uint)(in_TL == 3) * 0x6008 + (uint)(in_TL == 4) * 0x600c);
  uVar9 = uVar7 << 1;
  *(uint *)((uint)(in_TL == 1) * 0x6000 + (uint)(in_TL == 2) * 0x6004 + (uint)(in_TL == 3) * 0x6008
           + (uint)(in_TL == 4) * 0x600c) = uVar7 >> ((byte)iVar12 & 0x1f) | uVar9;
  qVar18 = in_l0_1 & 0x4000000000;
  iVar19 = in_CWP + -1;
  if (!(bool)in_DECOMPILE_MODE) {
    in_i0_1 = CONCAT44(*(undefined4 *)(iVar19 * 0x40 + 0x8000),
                       *(undefined4 *)((iVar19 * 0x10 + 1) * 4 + 0x8000));
    in_i2_3 = CONCAT44(*(undefined4 *)((iVar19 * 0x10 + 2) * 4 + 0x8000),
                       *(undefined4 *)((iVar19 * 0x10 + 3) * 4 + 0x8000));
    in_i4_5 = CONCAT44(*(undefined4 *)((iVar19 * 0x10 + 4) * 4 + 0x8000),
                       *(undefined4 *)((iVar19 * 0x10 + 5) * 4 + 0x8000));
    in_fp_7 = CONCAT44(*(undefined4 *)((iVar19 * 0x10 + 6) * 4 + 0x8000),
                       *(undefined4 *)((iVar19 * 0x10 + 7) * 4 + 0x8000));
    in_l0_1 = CONCAT44(*(undefined4 *)((iVar19 * 0x10 + 8) * 4 + 0x8000),
                       *(undefined4 *)((iVar19 * 0x10 + 9) * 4 + 0x8000));
    uVar7 = *(uint *)((iVar19 * 0x10 + 0xb) * 4 + 0x8000);
    uVar9 = *(uint *)((iVar19 * 0x10 + 0xc) * 4 + 0x8000);
    iVar12 = *(int *)((iVar19 * 0x10 + 0xe) * 4 + 0x8000);
  }
  uVar2 = (undefined4)in_i0_1;
  uVar1 = (undefined4)((qword)in_i0_1 >> 0x20);
  uVar3 = (undefined4)((qword)in_i2_3 >> 0x20);
  uVar4 = (undefined4)((qword)in_i4_5 >> 0x20);
  puVar5 = (undefined8 *)(in_fp_7 >> 0x20);
  if (qVar18 != 0) {
    iVar12 = in_CWP + -2;
    uVar6 = *puVar5;
    uVar8 = (undefined4)puVar5[1];
    uVar11 = puVar5[2];
    uVar13 = puVar5[3];
    uVar14 = puVar5[4];
    uVar15 = puVar5[5];
    uVar16 = puVar5[6];
    uVar17 = puVar5[7];
    if (!(bool)in_DECOMPILE_MODE) {
      *(int *)(iVar12 * 0x40 + 0x8000) = (int)((qword)uVar14 >> 0x20);
      *(int *)((iVar12 * 0x10 + 1) * 4 + 0x8000) = (int)uVar14;
      *(int *)((iVar12 * 0x10 + 2) * 4 + 0x8000) = (int)((qword)uVar15 >> 0x20);
      *(int *)((iVar12 * 0x10 + 3) * 4 + 0x8000) = (int)uVar15;
      *(int *)((iVar12 * 0x10 + 4) * 4 + 0x8000) = (int)((qword)uVar16 >> 0x20);
      *(int *)((iVar12 * 0x10 + 5) * 4 + 0x8000) = (int)uVar16;
      *(int *)((iVar12 * 0x10 + 6) * 4 + 0x8000) = (int)((qword)uVar17 >> 0x20);
      *(int *)((iVar12 * 0x10 + 7) * 4 + 0x8000) = (int)uVar17;
      *(int *)((iVar12 * 0x10 + 8) * 4 + 0x8000) = (int)((qword)uVar6 >> 0x20);
      *(int *)((iVar12 * 0x10 + 9) * 4 + 0x8000) = (int)uVar6;
      *(undefined4 *)((iVar12 * 0x10 + 10) * 4 + 0x8000) = uVar8;
      *(undefined4 *)((iVar12 * 0x10 + 0xb) * 4 + 0x8000) = uVar8;
      *(int *)((iVar12 * 0x10 + 0xc) * 4 + 0x8000) = (int)((qword)uVar11 >> 0x20);
      *(int *)((iVar12 * 0x10 + 0xd) * 4 + 0x8000) = (int)uVar11;
      *(int *)((iVar12 * 0x10 + 0xe) * 4 + 0x8000) = (int)((qword)uVar13 >> 0x20);
      *(int *)((iVar12 * 0x10 + 0xf) * 4 + 0x8000) = (int)uVar13;
    }
    uVar6 = 0;
    uVar8 = 0;
    uVar11 = 0;
    uVar13 = 0;
    iVar12 = iVar12 + 1;
    if (!(bool)in_DECOMPILE_MODE) {
      *(undefined4 *)(iVar12 * 0x40 + 0x8000) = uVar1;
      *(undefined4 *)((iVar12 * 0x10 + 1) * 4 + 0x8000) = uVar2;
      *(undefined4 *)((iVar12 * 0x10 + 2) * 4 + 0x8000) = uVar3;
      *(undefined4 *)((iVar12 * 0x10 + 3) * 4 + 0x8000) = 0;
      *(undefined4 *)((iVar12 * 0x10 + 4) * 4 + 0x8000) = uVar4;
      *(undefined4 *)((iVar12 * 0x10 + 5) * 4 + 0x8000) = 0;
      *(undefined8 **)((iVar12 * 0x10 + 6) * 4 + 0x8000) = puVar5;
      *(undefined4 *)((iVar12 * 0x10 + 7) * 4 + 0x8000) = 0;
      *(int *)((iVar12 * 0x10 + 8) * 4 + 0x8000) = (int)((qword)uVar6 >> 0x20);
      *(int *)((iVar12 * 0x10 + 9) * 4 + 0x8000) = (int)uVar6;
      *(undefined4 *)((iVar12 * 0x10 + 10) * 4 + 0x8000) = uVar8;
      *(undefined4 *)((iVar12 * 0x10 + 0xb) * 4 + 0x8000) = uVar8;
      *(int *)((iVar12 * 0x10 + 0xc) * 4 + 0x8000) = (int)((qword)uVar11 >> 0x20);
      *(int *)((iVar12 * 0x10 + 0xd) * 4 + 0x8000) = (int)uVar11;
      *(int *)((iVar12 * 0x10 + 0xe) * 4 + 0x8000) = (int)((qword)uVar13 >> 0x20);
      *(int *)((iVar12 * 0x10 + 0xf) * 4 + 0x8000) = (int)uVar13;
    }
                    /* WARNING: Unimplemented instruction - Truncating control flow here */
    halt_unimplemented();
  }
  iVar19 = in_CWP + -2;
  qVar18 = in_fp_7;
  if (!(bool)in_DECOMPILE_MODE) {
    in_i0_1 = CONCAT44(*(undefined4 *)(iVar19 * 0x40 + 0x8000),
                       *(undefined4 *)((iVar19 * 0x10 + 1) * 4 + 0x8000));
    in_i2_3 = CONCAT44(*(undefined4 *)((iVar19 * 0x10 + 2) * 4 + 0x8000),
                       *(undefined4 *)((iVar19 * 0x10 + 3) * 4 + 0x8000));
    in_i4_5 = CONCAT44(*(undefined4 *)((iVar19 * 0x10 + 4) * 4 + 0x8000),
                       *(undefined4 *)((iVar19 * 0x10 + 5) * 4 + 0x8000));
    qVar18 = CONCAT44(*(undefined4 *)((iVar19 * 0x10 + 6) * 4 + 0x8000),
                      *(undefined4 *)((iVar19 * 0x10 + 7) * 4 + 0x8000));
    in_l0_1 = CONCAT44(*(undefined4 *)((iVar19 * 0x10 + 8) * 4 + 0x8000),
                       *(undefined4 *)((iVar19 * 0x10 + 9) * 4 + 0x8000));
    uVar7 = *(uint *)((iVar19 * 0x10 + 0xb) * 4 + 0x8000);
    uVar9 = *(uint *)((iVar19 * 0x10 + 0xc) * 4 + 0x8000);
    iVar12 = *(int *)((iVar19 * 0x10 + 0xe) * 4 + 0x8000);
  }
  uVar8 = (undefined4)((qword)in_i0_1 >> 0x20);
  if ((in_fp_7 & 0x700000000) != 0) {
    if (!(bool)in_DECOMPILE_MODE) {
      *(undefined4 *)(iVar19 * 0x40 + 0x8000) = uVar8;
      *(int *)((iVar19 * 0x10 + 1) * 4 + 0x8000) = (int)in_i0_1;
      *(int *)((iVar19 * 0x10 + 2) * 4 + 0x8000) = (int)((qword)in_i2_3 >> 0x20);
      *(int *)((iVar19 * 0x10 + 3) * 4 + 0x8000) = (int)in_i2_3;
      *(int *)((iVar19 * 0x10 + 4) * 4 + 0x8000) = (int)((qword)in_i4_5 >> 0x20);
      *(int *)((iVar19 * 0x10 + 5) * 4 + 0x8000) = (int)in_i4_5;
      *(int *)((iVar19 * 0x10 + 6) * 4 + 0x8000) = (int)(qVar18 >> 0x20);
      *(int *)((iVar19 * 0x10 + 7) * 4 + 0x8000) = (int)qVar18;
      *(int *)((iVar19 * 0x10 + 8) * 4 + 0x8000) = (int)(in_l0_1 >> 0x20);
      *(int *)((iVar19 * 0x10 + 9) * 4 + 0x8000) = (int)in_l0_1;
      *(uint *)((iVar19 * 0x10 + 10) * 4 + 0x8000) = uVar7;
      *(uint *)((iVar19 * 0x10 + 0xb) * 4 + 0x8000) = uVar7;
      *(uint *)((iVar19 * 0x10 + 0xc) * 4 + 0x8000) = uVar9;
      *(undefined4 *)((iVar19 * 0x10 + 0xd) * 4 + 0x8000) = 0;
      *(int *)((iVar19 * 0x10 + 0xe) * 4 + 0x8000) = iVar12;
      *(undefined4 *)((iVar19 * 0x10 + 0xf) * 4 + 0x8000) = 0;
    }
    uVar6 = 0;
    uVar8 = 0;
    uVar11 = 0;
    uVar13 = 0;
    iVar19 = iVar19 + 1;
    if (!(bool)in_DECOMPILE_MODE) {
      *(undefined4 *)(iVar19 * 0x40 + 0x8000) = uVar1;
      *(undefined4 *)((iVar19 * 0x10 + 1) * 4 + 0x8000) = uVar2;
      *(undefined4 *)((iVar19 * 0x10 + 2) * 4 + 0x8000) = uVar3;
      *(undefined4 *)((iVar19 * 0x10 + 3) * 4 + 0x8000) = 0;
      *(undefined4 *)((iVar19 * 0x10 + 4) * 4 + 0x8000) = uVar4;
      *(undefined4 *)((iVar19 * 0x10 + 5) * 4 + 0x8000) = 0;
      *(undefined8 **)((iVar19 * 0x10 + 6) * 4 + 0x8000) = puVar5;
      *(undefined4 *)((iVar19 * 0x10 + 7) * 4 + 0x8000) = 0;
      *(int *)((iVar19 * 0x10 + 8) * 4 + 0x8000) = (int)((qword)uVar6 >> 0x20);
      *(int *)((iVar19 * 0x10 + 9) * 4 + 0x8000) = (int)uVar6;
      *(undefined4 *)((iVar19 * 0x10 + 10) * 4 + 0x8000) = uVar8;
      *(undefined4 *)((iVar19 * 0x10 + 0xb) * 4 + 0x8000) = uVar8;
      *(int *)((iVar19 * 0x10 + 0xc) * 4 + 0x8000) = (int)((qword)uVar11 >> 0x20);
      *(int *)((iVar19 * 0x10 + 0xd) * 4 + 0x8000) = (int)uVar11;
      *(int *)((iVar19 * 0x10 + 0xe) * 4 + 0x8000) = (int)((qword)uVar13 >> 0x20);
      *(int *)((iVar19 * 0x10 + 0xf) * 4 + 0x8000) = (int)uVar13;
    }
    *(undefined4 *)
     ((uint)(in_TL == 1) * 0x6000 + (uint)(in_TL == 2) * 0x6004 + (uint)(in_TL == 3) * 0x6008 +
     (uint)(in_TL == 4) * 0x600c) = 0;
    sys_trap();
    return;
  }
  uVar10 = 0xf0000000;
  if (puVar5 < &dword_F0000000) {
                    /* WARNING: Could not recover jumptable at 0xf00975c8. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (*_v_mmu_wu)();
    return;
  }
  if (!(bool)in_DECOMPILE_MODE) {
    *(undefined4 *)(iVar19 * 0x40 + 0x8000) = uVar8;
    *(int *)((iVar19 * 0x10 + 1) * 4 + 0x8000) = (int)in_i0_1;
    *(int *)((iVar19 * 0x10 + 2) * 4 + 0x8000) = (int)((qword)in_i2_3 >> 0x20);
    *(int *)((iVar19 * 0x10 + 3) * 4 + 0x8000) = (int)in_i2_3;
    *(int *)((iVar19 * 0x10 + 4) * 4 + 0x8000) = (int)((qword)in_i4_5 >> 0x20);
    *(int *)((iVar19 * 0x10 + 5) * 4 + 0x8000) = (int)in_i4_5;
    *(int *)((iVar19 * 0x10 + 6) * 4 + 0x8000) = (int)(qVar18 >> 0x20);
    *(int *)((iVar19 * 0x10 + 7) * 4 + 0x8000) = (int)qVar18;
    *(int *)((iVar19 * 0x10 + 8) * 4 + 0x8000) = (int)(in_l0_1 >> 0x20);
    *(int *)((iVar19 * 0x10 + 9) * 4 + 0x8000) = (int)in_l0_1;
    *(uint *)((iVar19 * 0x10 + 10) * 4 + 0x8000) = uVar7;
    *(uint *)((iVar19 * 0x10 + 0xb) * 4 + 0x8000) = uVar7;
    *(undefined4 *)((iVar19 * 0x10 + 0xc) * 4 + 0x8000) = uVar10;
    *(undefined4 *)((iVar19 * 0x10 + 0xd) * 4 + 0x8000) = 0;
    *(int *)((iVar19 * 0x10 + 0xe) * 4 + 0x8000) = iVar12;
    *(undefined4 *)((iVar19 * 0x10 + 0xf) * 4 + 0x8000) = 0;
  }
  uVar6 = 0;
  uVar8 = 0;
  uVar11 = 0;
  uVar13 = 0;
  iVar19 = iVar19 + 1;
  if (!(bool)in_DECOMPILE_MODE) {
    *(undefined4 *)(iVar19 * 0x40 + 0x8000) = uVar1;
    *(undefined4 *)((iVar19 * 0x10 + 1) * 4 + 0x8000) = uVar2;
    *(undefined4 *)((iVar19 * 0x10 + 2) * 4 + 0x8000) = uVar3;
    *(undefined4 *)((iVar19 * 0x10 + 3) * 4 + 0x8000) = 0;
    *(undefined4 *)((iVar19 * 0x10 + 4) * 4 + 0x8000) = uVar4;
    *(undefined4 *)((iVar19 * 0x10 + 5) * 4 + 0x8000) = 0;
    *(undefined8 **)((iVar19 * 0x10 + 6) * 4 + 0x8000) = puVar5;
    *(undefined4 *)((iVar19 * 0x10 + 7) * 4 + 0x8000) = 0;
    *(int *)((iVar19 * 0x10 + 8) * 4 + 0x8000) = (int)((qword)uVar6 >> 0x20);
    *(int *)((iVar19 * 0x10 + 9) * 4 + 0x8000) = (int)uVar6;
    *(undefined4 *)((iVar19 * 0x10 + 10) * 4 + 0x8000) = uVar8;
    *(undefined4 *)((iVar19 * 0x10 + 0xb) * 4 + 0x8000) = uVar8;
    *(int *)((iVar19 * 0x10 + 0xc) * 4 + 0x8000) = (int)((qword)uVar11 >> 0x20);
    *(int *)((iVar19 * 0x10 + 0xd) * 4 + 0x8000) = (int)uVar11;
    *(int *)((iVar19 * 0x10 + 0xe) * 4 + 0x8000) = (int)((qword)uVar13 >> 0x20);
    *(int *)((iVar19 * 0x10 + 0xf) * 4 + 0x8000) = (int)uVar13;
  }
  func_0xf00975f0();
  return;
}
