
/* WARNING: Removing unreachable block (ram,0xf0098e60) */
/* WARNING: Removing unreachable block (ram,0xf0098e0c) */
/* WARNING: Removing unreachable block (ram,0xf0098e1c) */
/* WARNING: Removing unreachable block (ram,0xf0098e78) */
/* WARNING: Removing unreachable block (ram,0xf0098dec) */

undefined8 _fp_runq(undefined4 param_1,undefined4 param_2)

{
  undefined *puVar1;
  int iVar2;
  undefined4 unaff_l0;
  undefined4 *puVar3;
  undefined4 unaff_l1;
  int iVar4;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined *puVar5;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  uint uVar6;
  undefined4 unaff_i1;
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
  iVar4 = *(int *)(*(int *)(_active_threads + 0x28) + 0x284);
  puVar3 = (undefined4 *)(iVar4 + 0x90);
  if (*(int *)(iVar4 + 0x8c) != 0) {
    puVar5 = (undefined *)((int)register0x00000038 + -0x38);
    do {
      puVar1 = puVar5;
      _fpu_simulator(puVar5,*puVar3,iVar4 + 0x80,puVar3[1]);
      if (puVar1 != (undefined *)0x0) {
        if (_fpu_exists != 0) {
          __fp_write_pfsr(iVar4 + 0x80);
        }
        _fp_traps(puVar5,puVar1,param_1);
        break;
      }
      puVar3 = puVar3 + 2;
      iVar2 = *(int *)(iVar4 + 0x8c) + -1;
      *(int *)(iVar4 + 0x8c) = iVar2;
    } while (iVar2 != 0);
  }
  uVar6 = 0;
  iVar2 = iVar4;
  if (_fpu_exists != 0) {
    do {
      __fp_read_pfreg(iVar2,uVar6);
      uVar6 = uVar6 + 1;
      iVar2 = iVar2 + 4;
    } while (uVar6 < 0x20);
    __fp_write_pfsr(iVar4 + 0x80);
  }
  return CONCAT44(param_2,uVar6);
}

