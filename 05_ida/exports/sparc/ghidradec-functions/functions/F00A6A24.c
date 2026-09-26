
/* WARNING: Removing unreachable block (ram,0xf00a6b04) */
/* WARNING: Removing unreachable block (ram,0xf00a6b2c) */
/* WARNING: Removing unreachable block (ram,0xf00a6ad8) */
/* WARNING: Removing unreachable block (ram,0xf00a6ab0) */
/* WARNING: Removing unreachable block (ram,0xf00a6a68) */
/* WARNING: Removing unreachable block (ram,0xf00a6a98) */
/* WARNING: Removing unreachable block (ram,0xf00a6ad0) */
/* WARNING: Removing unreachable block (ram,0xf00a6ae8) */
/* WARNING: Removing unreachable block (ram,0xf00a6b58) */
/* WARNING: Removing unreachable block (ram,0xf00a6b94) */
/* WARNING: Removing unreachable block (ram,0xf00a6a50) */

undefined8 _log_mem_err(uint param_1,uint param_2,undefined4 param_3,int param_4)

{
  undefined *puVar1;
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
  bool bVar2;
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
  if (param_4 == 0) {
    if (((param_1 & 1) != 0) && (_log_ce_error != 0)) {
      _printf(aSofterrorEccMe);
    }
    if ((param_1 & 0x10000) != 0) {
      _printf(aMultipleErrors_1);
    }
    bVar2 = (param_1 & 8) == 0;
    if (_cpu == 0x72) {
      if ((param_1 & 0x20000) != 0) {
        _printf(aGraphicsError);
      }
      bVar2 = (param_1 & 8) == 0;
      if ((param_1 & 2) != 0) {
        _printf(aMisreferencedS);
        bVar2 = (param_1 & 8) == 0;
      }
    }
    if (bVar2) goto loc_F00A6AD8;
    puVar1 = aUncorrectableE;
  }
  else {
    puVar1 = aUncorrectableE_0;
  }
  _printf(puVar1);
loc_F00A6AD8:
  _prom_nextnode(0);
  _prom_getprop();
  if (*(int *)((int)register0x00000038 + -0xc) == 0) {
    _printf(aNoSimmDecodeFu);
  }
  else if ((param_4 == 0) && ((param_1 & 1) != 0)) {
    _log_ce_mem_err(param_1,param_2,param_3);
  }
  else if ((param_4 != 0) || ((param_1 & 8) != 0)) {
    _log_ue_mem_err(param_2,param_3,*(undefined4 *)((int)register0x00000038 + -0xc));
  }
  if (((param_4 != 0) || ((param_1 & 1) == 0)) || (_log_ce_error != 0)) {
    _printf(aPhysicalAddres_6,param_2 & 0xf,param_3);
  }
  return CONCAT44(param_2,param_1);
}
