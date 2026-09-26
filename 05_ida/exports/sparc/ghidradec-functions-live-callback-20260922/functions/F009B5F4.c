
/* WARNING: Removing unreachable block (ram,0xf009b824) */
/* WARNING: Removing unreachable block (ram,0xf009b7f0) */
/* WARNING: Removing unreachable block (ram,0xf009b7c0) */
/* WARNING: Removing unreachable block (ram,0xf009b794) */
/* WARNING: Removing unreachable block (ram,0xf009b708) */
/* WARNING: Removing unreachable block (ram,0xf009b77c) */
/* WARNING: Removing unreachable block (ram,0xf009b7a8) */
/* WARNING: Removing unreachable block (ram,0xf009b7d8) */
/* WARNING: Removing unreachable block (ram,0xf009b808) */
/* WARNING: Removing unreachable block (ram,0xf009b830) */
/* WARNING: Removing unreachable block (ram,0xf009b600) */

undefined8 _vik_mmu_print_sfsr(uint param_1,undefined4 param_2)

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
  _printf(aMmuSfsrX_1,param_1);
  switch(param_1 & 0x1c) {
  case :
    puVar1 = aNoError_1;
    break;
  case :
    puVar1 = aInvalidAddress_1;
    break;
  case :
    puVar1 = aProtectionErro_1;
    break;
  case :
    puVar1 = aPrivilegeViola_1;
    break;
  case :
    puVar1 = aTranslationErr_1;
    break;
  case :
    puVar1 = aBusAccessError_1;
    break;
  case :
    puVar1 = aInternalError_1;
    break;
  case :
    puVar1 = aReservedError_1;
    break;
  :
    puVar1 = aUnknownError_1;
  }
  _printf(puVar1);
  if (param_1 != 0) {
    if ((param_1 & 0x20) == 0) {
      puVar2 = &aUser_3;
    }
    else {
      puVar2 = &aSupv_2;
    }
    if ((param_1 & 0x40) == 0) {
      puVar3 = (undefined6 *)&aData_1;
    }
    else {
      puVar3 = &aInstr_1;
    }
    if ((param_1 & 0x80) == 0) {
      puVar4 = &aFetch_1;
    }
    else {
      puVar4 = &aStore_1;
    }
    _printf(aOnSSSAtLevelD_1,puVar2,puVar3,puVar4,(param_1 & 0x300) >> 8);
    if ((param_1 & 0x400) != 0) {
      _printf(aMBusBusError_1);
    }
    if ((param_1 & 0x800) != 0) {
      _printf(aMBusTimeoutErr_1);
    }
    if ((param_1 & 0x1000) != 0) {
      _printf(aMBusUncorrecta_1);
    }
    if ((param_1 & 0x2000) != 0) {
      _printf(aMBusUndefinedE);
    }
    if ((param_1 & 0x4000) != 0) {
      _printf(aParityError_0);
    }
    if ((param_1 & 0x10000) != 0) {
      _printf(aControlSpaceSc);
    }
    if ((param_1 & 0x8000) != 0) {
      _printf(aStoreBufferErr_0);
    }
  }
  _printf(&DAT_f0117ad0);
  return CONCAT44(param_2,param_1);
}

