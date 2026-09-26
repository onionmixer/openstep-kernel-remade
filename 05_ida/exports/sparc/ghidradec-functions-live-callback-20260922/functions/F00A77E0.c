
/* WARNING: Removing unreachable block (ram,0xf00a78e4) */
/* WARNING: Removing unreachable block (ram,0xf00a78a4) */
/* WARNING: Removing unreachable block (ram,0xf00a7884) */
/* WARNING: Removing unreachable block (ram,0xf00a7830) */
/* WARNING: Removing unreachable block (ram,0xf00a780c) */
/* WARNING: Removing unreachable block (ram,0xf00a7850) */
/* WARNING: Removing unreachable block (ram,0xf00a7898) */
/* WARNING: Removing unreachable block (ram,0xf00a78d4) */
/* WARNING: Removing unreachable block (ram,0xf00a78f0) */
/* WARNING: Removing unreachable block (ram,0xf00a7800) */

undefined8 _check_fsr(undefined4 param_1,undefined4 param_2,uint param_3,uint param_4,int param_5)

{
  uint uVar1;
  undefined *puVar2;
  undefined6 *puVar3;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
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
  if (((param_4 & 0x3c00) != 0) && ((param_4 & 0x3000) != 0)) {
    _splaudio();
    uVar1 = param_4;
    _vac_parity_chk_dis(param_4,0);
    if (uVar1 == 0) {
      puVar2 = aFatalSystemFau_0;
    }
    else {
      puVar2 = aModuleParityEr;
    }
    _printf(puVar2);
    _pmap_getpte(*(undefined4 *)(*(int *)(*(int *)(_active_threads + 0xc) + 0xc) + 0x24),param_3,
                 (undefined *)((int)register0x00000038 + -0xc));
    if ((*(uint *)((int)register0x00000038 + -0xc) & 3) == 2) {
      _log_mem_err(param_4,0,
                   (*(uint *)((int)register0x00000038 + -0xc) >> 8) << 0xc | param_3 & 0xfff,1);
    }
    else {
      _printf(aAddrXIsNotVali,param_3);
    }
    _printf(aControlRegiste_0);
    if (param_5 == 2) {
      puVar3 = &aWrite_0;
    }
    else {
      puVar3 = (undefined6 *)&aRead_0;
    }
    _printf(aSfsr0xXSFault,param_4,puVar3);
    _printf(aAtVaddr0xX,param_3);
    _panic(aMemoryError_0);
  }
  return CONCAT44(param_2,param_1);
}

