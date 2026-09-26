
/* WARNING: Removing unreachable block (ram,0xf00a670c) */
/* WARNING: Removing unreachable block (ram,0xf00a669c) */
/* WARNING: Removing unreachable block (ram,0xf00a666c) */
/* WARNING: Removing unreachable block (ram,0xf00a6684) */
/* WARNING: Removing unreachable block (ram,0xf00a66b4) */
/* WARNING: Removing unreachable block (ram,0xf00a6740) */
/* WARNING: Removing unreachable block (ram,0xf00a6644) */

undefined8 _log_mtos_err(uint param_1,uint param_2)

{
  undefined *puVar1;
  undefined6 *puVar2;
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
  if ((param_1 & 0x80000) != 0) {
    _printf(aMultipleErrors_0);
  }
  if ((param_1 & 0x1000000) == 0) {
    puVar1 = aErrorDuringUse;
  }
  else {
    puVar1 = aErrorDuringSup;
  }
  _printf(puVar1);
  if ((param_1 & 0x40000000) != 0) {
    _printf(aLateError);
  }
  if ((param_1 & 0x20000000) != 0) {
    _printf(aTimeoutError_0);
  }
  if ((param_1 & 0x10000000) != 0) {
    _printf(aBusError_0);
  }
  if ((param_1 & 0x1000000) == 0) {
    puVar2 = &aUser_4;
  }
  else {
    puVar2 = &aSupv_3;
  }
  _printf(aRequestedTrans_0,puVar2,*(undefined4 *)(_nameof_siz + (param_1 >> 0x17 & 0x1c)),
          param_1 & 0xf,param_2,param_1 >> 0x14 & 0xf);
  _printf(aSpecificCycleS,*(undefined4 *)(_nameof_ssiz + ((param_1 & 0xe00) >> 7)),param_1 & 0xf,
          param_2 & 0xffffffe0 | param_1 >> 0xc & 0x1f);
  return CONCAT44(param_2,param_1);
}

