
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
