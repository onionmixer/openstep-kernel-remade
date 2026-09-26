
/* WARNING: Removing unreachable block (ram,0xf009af88) */
/* WARNING: Removing unreachable block (ram,0xf009af58) */
/* WARNING: Removing unreachable block (ram,0xf009aecc) */
/* WARNING: Removing unreachable block (ram,0xf009af40) */
/* WARNING: Removing unreachable block (ram,0xf009af6c) */
/* WARNING: Removing unreachable block (ram,0xf009af94) */
/* WARNING: Removing unreachable block (ram,0xf009adc4) */

undefined8 _swift_mmu_print_sfsr(uint param_1,undefined4 param_2)

{
  undefined *puVar1;
  undefined5 *puVar2;
  undefined6 *puVar3;
  undefined6 *puVar4;
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
  _printf(aMmuSfsrX_0,param_1);
  switch(param_1 & 0x1c) {
  case :
    puVar1 = aNoError_0;
    break;
  case :
    puVar1 = aInvalidAddress_0;
    break;
  case :
    puVar1 = aProtectionErro_0;
    break;
  case :
    puVar1 = aPrivilegeViola_0;
    break;
  case :
    puVar1 = aTranslationErr_0;
    break;
  case :
    puVar1 = aBusAccessError_0;
    break;
  case :
    puVar1 = aInternalError_0;
    break;
  case :
    puVar1 = aReservedError_0;
    break;
  :
    puVar1 = aUnknownError_0;
  }
  _printf(puVar1);
  if (param_1 != 0) {
    if ((param_1 & 0x20) == 0) {
      puVar2 = &aUser_1;
    }
    else {
      puVar2 = &aSupv_0;
    }
    if ((param_1 & 0x40) == 0) {
      puVar3 = (undefined6 *)&aData_0;
    }
    else {
      puVar3 = &aInstr_0;
    }
    if ((param_1 & 0x80) == 0) {
      puVar4 = &aFetch_0;
    }
    else {
      puVar4 = &aStore_0;
    }
    _printf(aOnSSSAtLevelD_0,puVar2,puVar3,puVar4,(param_1 & 0x300) >> 8);
    if ((param_1 & 0x400) != 0) {
      _printf(aBusError);
    }
    if ((param_1 & 0x800) != 0) {
      _printf(aTimeoutError);
    }
    if ((param_1 & 0x6000) != 0) {
      _printf(aParityError);
    }
  }
  _printf(&DAT_f01176c8);
  return CONCAT44(param_2,param_1);
}
