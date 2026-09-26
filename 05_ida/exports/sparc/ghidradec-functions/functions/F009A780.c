
/* WARNING: Removing unreachable block (ram,0xf009a950) */
/* WARNING: Removing unreachable block (ram,0xf009a920) */
/* WARNING: Removing unreachable block (ram,0xf009a894) */
/* WARNING: Removing unreachable block (ram,0xf009a908) */
/* WARNING: Removing unreachable block (ram,0xf009a934) */
/* WARNING: Removing unreachable block (ram,0xf009a95c) */
/* WARNING: Removing unreachable block (ram,0xf009a78c) */

undefined8 _srmmu_mmu_print_sfsr(uint param_1,undefined4 param_2)

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
  _printf(aMmuSfsrX,param_1);
  switch(param_1 & 0x1c) {
  case :
    puVar1 = aNoError;
    break;
  case :
    puVar1 = aInvalidAddress;
    break;
  case :
    puVar1 = aProtectionErro;
    break;
  case :
    puVar1 = aPrivilegeViola;
    break;
  case :
    puVar1 = aTranslationErr;
    break;
  case :
    puVar1 = aBusAccessError;
    break;
  case :
    puVar1 = aInternalError;
    break;
  case :
    puVar1 = aReservedError;
    break;
  :
    puVar1 = aUnknownError;
  }
  _printf(puVar1);
  if (param_1 != 0) {
    if ((param_1 & 0x20) == 0) {
      puVar2 = &aUser_0;
    }
    else {
      puVar2 = &aSupv;
    }
    if ((param_1 & 0x40) == 0) {
      puVar3 = (undefined6 *)&aData;
    }
    else {
      puVar3 = &aInstr;
    }
    if ((param_1 & 0x80) == 0) {
      puVar4 = &aFetch;
    }
    else {
      puVar4 = &aStore;
    }
    _printf(aOnSSSAtLevelD,puVar2,puVar3,puVar4,(param_1 & 0x300) >> 8);
    if ((param_1 & 0x400) != 0) {
      _printf(aMBusBusError_0);
    }
    if ((param_1 & 0x800) != 0) {
      _printf(aMBusTimeoutErr_0);
    }
    if ((param_1 & 0x1000) != 0) {
      _printf(aMBusUncorrecta_0);
    }
  }
  _printf(&DAT_f0117548);
  return CONCAT44(param_2,param_1);
}
