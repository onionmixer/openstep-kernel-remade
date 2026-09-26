
/* WARNING: Removing unreachable block (ram,0xf0098d64) */
/* WARNING: Removing unreachable block (ram,0xf0098d8c) */
/* WARNING: Removing unreachable block (ram,0xf0098d70) */
/* WARNING: Removing unreachable block (ram,0xf0098da0) */
/* WARNING: Removing unreachable block (ram,0xf0098d54) */
/* WARNING: Removing unreachable block (ram,0xf0098d0c) */

undefined8 _fp_is_disabled(uint *param_1,undefined4 param_2)

{
  undefined *puVar1;
  undefined4 unaff_l0;
  undefined *puVar2;
  undefined4 unaff_l1;
  undefined *puVar3;
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
  puVar2 = *(undefined **)(*(int *)(_active_threads + 0x28) + 0x284);
  puVar1 = DAT_f0113400;
  if (puVar2 == (undefined *)0x0) {
    _fpu_ctxalloc();
    *(undefined **)(*(int *)(_active_threads + 0x28) + 0x284) = puVar1;
    puVar2 = puVar1;
  }
  _fp_ctxp = puVar2;
  if (_fpu_exists == 0) {
    _flush_user_windows_to_stack();
    puVar3 = (undefined *)((int)register0x00000038 + -0x38);
    puVar1 = puVar3;
    _fp_emulator(puVar3,param_1[1],param_1,param_1[0x11],puVar2);
    if (puVar1 != (undefined *)0x0) {
      _fp_traps(puVar3,puVar1,param_1);
    }
  }
  else if ((*param_1 & 0x1000) == 0) {
    *param_1 = *param_1 | 0x1000;
    _fp_enable(puVar2);
  }
  else {
    _panic(aFpDisabledNoFp);
  }
  return CONCAT44(param_2,param_1);
}

