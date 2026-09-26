
/* WARNING: Removing unreachable block (ram,0xf00a1104) */
/* WARNING: Removing unreachable block (ram,0xf00a103c) */
/* WARNING: Removing unreachable block (ram,0xf00a0f74) */
/* WARNING: Removing unreachable block (ram,0xf00a0eac) */
/* WARNING: Removing unreachable block (ram,0xf00a0de4) */
/* WARNING: Removing unreachable block (ram,0xf00a0d1c) */
/* WARNING: Removing unreachable block (ram,0xf00a0c54) */
/* WARNING: Removing unreachable block (ram,0xf00a0b8c) */
/* WARNING: Removing unreachable block (ram,0xf00a0ac4) */
/* WARNING: Removing unreachable block (ram,0xf00a09fc) */
/* WARNING: Removing unreachable block (ram,0xf00a0934) */
/* WARNING: Removing unreachable block (ram,0xf00a086c) */
/* WARNING: Removing unreachable block (ram,0xf00a07a4) */
/* WARNING: Removing unreachable block (ram,0xf00a0730) */
/* WARNING: Removing unreachable block (ram,0xf00a06a4) */
/* WARNING: Removing unreachable block (ram,0xf00a05dc) */
/* WARNING: Removing unreachable block (ram,0xf00a0514) */
/* WARNING: Removing unreachable block (ram,0xf00a044c) */
/* WARNING: Removing unreachable block (ram,0xf00a0384) */
/* WARNING: Removing unreachable block (ram,0xf00a02bc) */
/* WARNING: Removing unreachable block (ram,0xf00a01f4) */
/* WARNING: Removing unreachable block (ram,0xf00a012c) */
/* WARNING: Removing unreachable block (ram,0xf00a0064) */
/* WARNING: Removing unreachable block (ram,0xf009fff0) */
/* WARNING: Removing unreachable block (ram,0xf009ff64) */
/* WARNING: Removing unreachable block (ram,0xf009fe9c) */
/* WARNING: Removing unreachable block (ram,0xf009fdd4) */
/* WARNING: Removing unreachable block (ram,0xf009fd0c) */
/* WARNING: Removing unreachable block (ram,0xf009fce4) */
/* WARNING: Removing unreachable block (ram,0xf009fcc0) */
/* WARNING: Removing unreachable block (ram,0xf009fca0) */
/* WARNING: Removing unreachable block (ram,0xf009fc78) */
/* WARNING: Removing unreachable block (ram,0xf009fc54) */
/* WARNING: Removing unreachable block (ram,0xf009fc34) */
/* WARNING: Removing unreachable block (ram,0xf009fc0c) */
/* WARNING: Removing unreachable block (ram,0xf009fbec) */
/* WARNING: Removing unreachable block (ram,0xf009fbdc) */
/* WARNING: Removing unreachable block (ram,0xf009fbfc) */
/* WARNING: Removing unreachable block (ram,0xf009fc20) */
/* WARNING: Removing unreachable block (ram,0xf009fc44) */
/* WARNING: Removing unreachable block (ram,0xf009fc64) */
/* WARNING: Removing unreachable block (ram,0xf009fc8c) */
/* WARNING: Removing unreachable block (ram,0xf009fcb0) */
/* WARNING: Removing unreachable block (ram,0xf009fcd0) */
/* WARNING: Removing unreachable block (ram,0xf009fcf8) */
/* WARNING: Removing unreachable block (ram,0xf009fd70) */
/* WARNING: Removing unreachable block (ram,0xf009fe38) */
/* WARNING: Removing unreachable block (ram,0xf009ff00) */
/* WARNING: Removing unreachable block (ram,0xf009ffc8) */
/* WARNING: Removing unreachable block (ram,0xf00a0000) */
/* WARNING: Removing unreachable block (ram,0xf00a00c8) */
/* WARNING: Removing unreachable block (ram,0xf00a0190) */
/* WARNING: Removing unreachable block (ram,0xf00a0258) */
/* WARNING: Removing unreachable block (ram,0xf00a0320) */
/* WARNING: Removing unreachable block (ram,0xf00a03e8) */
/* WARNING: Removing unreachable block (ram,0xf00a04b0) */
/* WARNING: Removing unreachable block (ram,0xf00a0578) */
/* WARNING: Removing unreachable block (ram,0xf00a0640) */
/* WARNING: Removing unreachable block (ram,0xf00a0708) */
/* WARNING: Removing unreachable block (ram,0xf00a0740) */
/* WARNING: Removing unreachable block (ram,0xf00a0808) */
/* WARNING: Removing unreachable block (ram,0xf00a08d0) */
/* WARNING: Removing unreachable block (ram,0xf00a0998) */
/* WARNING: Removing unreachable block (ram,0xf00a0a60) */
/* WARNING: Removing unreachable block (ram,0xf00a0b28) */
/* WARNING: Removing unreachable block (ram,0xf00a0bf0) */
/* WARNING: Removing unreachable block (ram,0xf00a0cb8) */
/* WARNING: Removing unreachable block (ram,0xf00a0d80) */
/* WARNING: Removing unreachable block (ram,0xf00a0e48) */
/* WARNING: Removing unreachable block (ram,0xf00a0f10) */
/* WARNING: Removing unreachable block (ram,0xf00a0fd8) */
/* WARNING: Removing unreachable block (ram,0xf00a10a0) */
/* WARNING: Removing unreachable block (ram,0xf00a1168) */
/* WARNING: Removing unreachable block (ram,0xf009fbc8) */

undefined8 _pmap_print_info(undefined4 param_1,undefined4 param_2)

{
  undefined *puVar1;
  int iVar2;
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
  if (_pmap_var_info != 0) {
    _printf(aDRegTblsVmPage,word_F013DE72,word_F013DE74);
    _printf(aDRegPoolsVmPag,word_F013DE76,word_F013DE78);
    _printf(aTksegtblsD,DAT_f013de7c._0_4_);
    _printf(aNksegtblsInuse,DAT_f013de7c._8_4_);
    _printf(aTksegpoolsD,DAT_f013de7c._4_4_);
    _printf(aKsegActiveCoun,dword_F013DE38);
    _printf(aKsegSemiActive,dword_F013DE48);
    _printf(aNuregtblsAlloc,DAT_f013de7c._28_4_);
    _printf(aNuregtblsInuse,DAT_f013de7c._24_4_);
    _printf(aNuregpoolsD,DAT_f013de7c._32_4_);
    _printf(aRegFreeCountD,dword_F013DFA8);
    _printf(aRegSemiActiveC,dword_F013DFB8);
    _printf(aRegActiveCount,dword_F013DF98);
    _printf(aNusegtblsAlloc,DAT_f013de7c._16_4_);
    _printf(aNusegtblsInuse,DAT_f013de7c._12_4_);
    _printf(aNusegpoolsD,DAT_f013de7c._20_4_);
    _printf(aSegFreeCountD,dword_F013DFD8);
    _printf(aSegSemiActiveC,dword_F013DFE8);
    _printf(aSegActiveCount,dword_F013DFC8);
  }
  if ((dword_F013DEA0 == 0) && (_pmap_func_info0 != 0)) {
    puVar1 = aPmapVacflushD;
    iVar2 = 0;
loc_F009FD70:
    _printf(puVar1,iVar2);
  }
  else if ((dword_F013DEA0 != 0) && (_pmap_func_info1 != 0)) {
    puVar1 = aPmapVacflushD_0;
    iVar2 = dword_F013DEA0;
    goto loc_F009FD70;
  }
  if ((dword_F013DEA4 == 0) && (_pmap_func_info0 != 0)) {
    puVar1 = aPmapMapD;
    iVar2 = 0;
loc_F009FDD4:
    _printf(puVar1,iVar2);
  }
  else if ((dword_F013DEA4 != 0) && (_pmap_func_info1 != 0)) {
    puVar1 = aPmapMapD_0;
    iVar2 = dword_F013DEA4;
    goto loc_F009FDD4;
  }
  if ((dword_F013DEA8 == 0) && (_pmap_func_info0 != 0)) {
    puVar1 = aPmapChangeProt;
    iVar2 = 0;
loc_F009FE38:
    _printf(puVar1,iVar2);
  }
  else if ((dword_F013DEA8 != 0) && (_pmap_func_info1 != 0)) {
    puVar1 = aPmapChangeProt_0;
    iVar2 = dword_F013DEA8;
    goto loc_F009FE38;
  }
  if ((dword_F013DEAC == 0) && (_pmap_func_info0 != 0)) {
    puVar1 = aPmapCreateD;
    iVar2 = 0;
loc_F009FE9C:
    _printf(puVar1,iVar2);
  }
  else if ((dword_F013DEAC != 0) && (_pmap_func_info1 != 0)) {
    puVar1 = aPmapCreateD_0;
    iVar2 = dword_F013DEAC;
    goto loc_F009FE9C;
  }
  if ((dword_F013DEB0 == 0) && (_pmap_func_info0 != 0)) {
    puVar1 = aPmapDestroyD;
    iVar2 = 0;
loc_F009FF00:
    _printf(puVar1,iVar2);
  }
  else if ((dword_F013DEB0 != 0) && (_pmap_func_info1 != 0)) {
    puVar1 = aPmapDestroyD_0;
    iVar2 = dword_F013DEB0;
    goto loc_F009FF00;
  }
  if ((dword_F013DEB4 == 0) && (_pmap_func_info0 != 0)) {
    puVar1 = aPmapReferenceD;
    iVar2 = 0;
loc_F009FF64:
    _printf(puVar1,iVar2);
  }
  else if ((dword_F013DEB4 != 0) && (_pmap_func_info1 != 0)) {
    puVar1 = aPmapReferenceD_0;
    iVar2 = dword_F013DEB4;
    goto loc_F009FF64;
  }
  if ((dword_F013DEB8 == 0) && (_pmap_func_info0 != 0)) {
    puVar1 = aPmapPageTableE_3;
    iVar2 = 0;
loc_F009FFC8:
    _printf(puVar1,iVar2);
  }
  else if ((dword_F013DEB8 != 0) && (_pmap_func_info1 != 0)) {
    puVar1 = aPmapPageTableE_4;
    iVar2 = dword_F013DEB8;
    goto loc_F009FFC8;
  }
  if (_pmap_opt_info != 0) {
    _printf(aPmapPageTableE_5,dword_F013DEB8);
    _printf(aPmapPageTableE_6,DAT_f013debc);
  }
  if ((dword_F013DEC0 == 0) && (_pmap_func_info0 != 0)) {
    puVar1 = aPmapGetpteD;
    iVar2 = 0;
loc_F00A0064:
    _printf(puVar1,iVar2);
  }
  else if ((dword_F013DEC0 != 0) && (_pmap_func_info1 != 0)) {
    puVar1 = aPmapGetpteD_0;
    iVar2 = dword_F013DEC0;
    goto loc_F00A0064;
  }
  if ((dword_F013DEC4 == 0) && (_pmap_func_info0 != 0)) {
    puVar1 = aPmapRemoveD;
    iVar2 = 0;
loc_F00A00C8:
    _printf(puVar1,iVar2);
  }
  else if ((dword_F013DEC4 != 0) && (_pmap_func_info1 != 0)) {
    puVar1 = aPmapRemoveD_0;
    iVar2 = dword_F013DEC4;
    goto loc_F00A00C8;
  }
  if ((dword_F013DEC8 == 0) && (_pmap_func_info0 != 0)) {
    puVar1 = aPmapRemoveAllD;
    iVar2 = 0;
loc_F00A012C:
    _printf(puVar1,iVar2);
  }
  else if ((dword_F013DEC8 != 0) && (_pmap_func_info1 != 0)) {
    puVar1 = aPmapRemoveAllD_0;
    iVar2 = dword_F013DEC8;
    goto loc_F00A012C;
  }
  if ((dword_F013DECC == 0) && (_pmap_func_info0 != 0)) {
    puVar1 = aPmapExpandD;
    iVar2 = 0;
loc_F00A0190:
    _printf(puVar1,iVar2);
  }
  else if ((dword_F013DECC != 0) && (_pmap_func_info1 != 0)) {
    puVar1 = aPmapExpandD_0;
    iVar2 = dword_F013DECC;
    goto loc_F00A0190;
  }
  if ((dword_F013DED0 == 0) && (_pmap_func_info0 != 0)) {
    puVar1 = aPmapEnterDevD;
    iVar2 = 0;
loc_F00A01F4:
    _printf(puVar1,iVar2);
  }
  else if ((dword_F013DED0 != 0) && (_pmap_func_info1 != 0)) {
    puVar1 = aPmapEnterDevD_0;
    iVar2 = dword_F013DED0;
    goto loc_F00A01F4;
  }
  if ((dword_F013DED4 == 0) && (_pmap_func_info0 != 0)) {
    puVar1 = aPmapEnterCache;
    iVar2 = 0;
loc_F00A0258:
    _printf(puVar1,iVar2);
  }
  else if ((dword_F013DED4 != 0) && (_pmap_func_info1 != 0)) {
    puVar1 = aPmapEnterCache_0;
    iVar2 = dword_F013DED4;
    goto loc_F00A0258;
  }
  if ((dword_F013DED8 == 0) && (_pmap_func_info0 != 0)) {
    puVar1 = aPmapEnterShare;
    iVar2 = 0;
loc_F00A02BC:
    _printf(puVar1,iVar2);
  }
  else if ((dword_F013DED8 != 0) && (_pmap_func_info1 != 0)) {
    puVar1 = aPmapEnterShare_0;
    iVar2 = dword_F013DED8;
    goto loc_F00A02BC;
  }
  if ((dword_F013DEDC == 0) && (_pmap_func_info0 != 0)) {
    puVar1 = aPmapCopyOnWrit;
    iVar2 = 0;
loc_F00A0320:
    _printf(puVar1,iVar2);
  }
  else if ((dword_F013DEDC != 0) && (_pmap_func_info1 != 0)) {
    puVar1 = aPmapCopyOnWrit_0;
    iVar2 = dword_F013DEDC;
    goto loc_F00A0320;
  }
  if ((dword_F013DEE0 == 0) && (_pmap_func_info0 != 0)) {
    puVar1 = aPmapMovePageD;
    iVar2 = 0;
loc_F00A0384:
    _printf(puVar1,iVar2);
  }
  else if ((dword_F013DEE0 != 0) && (_pmap_func_info1 != 0)) {
    puVar1 = aPmapMovePageD_0;
    iVar2 = dword_F013DEE0;
    goto loc_F00A0384;
  }
  if ((dword_F013DEE4 == 0) && (_pmap_func_info0 != 0)) {
    puVar1 = aPmapProtectD;
    iVar2 = 0;
loc_F00A03E8:
    _printf(puVar1,iVar2);
  }
  else if ((dword_F013DEE4 != 0) && (_pmap_func_info1 != 0)) {
    puVar1 = aPmapProtectD_0;
    iVar2 = dword_F013DEE4;
    goto loc_F00A03E8;
  }
  if ((dword_F013DEE8 == 0) && (_pmap_func_info0 != 0)) {
    puVar1 = aPmapPageProtec;
    iVar2 = 0;
loc_F00A044C:
    _printf(puVar1,iVar2);
  }
  else if ((dword_F013DEE8 != 0) && (_pmap_func_info1 != 0)) {
    puVar1 = aPmapPageProtec_0;
    iVar2 = dword_F013DEE8;
    goto loc_F00A044C;
  }
  if ((dword_F013DEEC == 0) && (_pmap_func_info0 != 0)) {
    puVar1 = aPmapChangeWiri_0;
    iVar2 = 0;
loc_F00A04B0:
    _printf(puVar1,iVar2);
  }
  else if ((dword_F013DEEC != 0) && (_pmap_func_info1 != 0)) {
    puVar1 = aPmapChangeWiri_1;
    iVar2 = dword_F013DEEC;
    goto loc_F00A04B0;
  }
  if ((dword_F013DEF0 == 0) && (_pmap_func_info0 != 0)) {
    puVar1 = aPmapResidentEx;
    iVar2 = 0;
loc_F00A0514:
    _printf(puVar1,iVar2);
  }
  else if ((dword_F013DEF0 != 0) && (_pmap_func_info1 != 0)) {
    puVar1 = aPmapResidentEx_0;
    iVar2 = dword_F013DEF0;
    goto loc_F00A0514;
  }
  if ((dword_F013DEF4 == 0) && (_pmap_func_info0 != 0)) {
    puVar1 = aPmapExtractD;
    iVar2 = 0;
loc_F00A0578:
    _printf(puVar1,iVar2);
  }
  else if ((dword_F013DEF4 != 0) && (_pmap_func_info1 != 0)) {
    puVar1 = aPmapExtractD_0;
    iVar2 = dword_F013DEF4;
    goto loc_F00A0578;
  }
  if ((dword_F013DEF8 == 0) && (_pmap_func_info0 != 0)) {
    puVar1 = aPmapClearPageA;
    iVar2 = 0;
loc_F00A05DC:
    _printf(puVar1,iVar2);
  }
  else if ((dword_F013DEF8 != 0) && (_pmap_func_info1 != 0)) {
    puVar1 = aPmapClearPageA_0;
    iVar2 = dword_F013DEF8;
    goto loc_F00A05DC;
  }
  if ((dword_F013DEFC == 0) && (_pmap_func_info0 != 0)) {
    puVar1 = aPmapCheckPageA_0;
    iVar2 = 0;
loc_F00A0640:
    _printf(puVar1,iVar2);
  }
  else if ((dword_F013DEFC != 0) && (_pmap_func_info1 != 0)) {
    puVar1 = aPmapCheckPageA_1;
    iVar2 = dword_F013DEFC;
    goto loc_F00A0640;
  }
  if ((dword_F013DF00 == 0) && (_pmap_func_info0 != 0)) {
    puVar1 = aPmapCollectD;
    iVar2 = 0;
loc_F00A06A4:
    _printf(puVar1,iVar2);
  }
  else if ((dword_F013DF00 != 0) && (_pmap_func_info1 != 0)) {
    puVar1 = aPmapCollectD_0;
    iVar2 = dword_F013DF00;
    goto loc_F00A06A4;
  }
  if ((dword_F013DF04 == 0) && (_pmap_func_info0 != 0)) {
    puVar1 = aPmapActivateD;
    iVar2 = 0;
loc_F00A0708:
    _printf(puVar1,iVar2);
  }
  else if ((dword_F013DF04 != 0) && (_pmap_func_info1 != 0)) {
    puVar1 = aPmapActivateD_0;
    iVar2 = dword_F013DF04;
    goto loc_F00A0708;
  }
  if (_pmap_opt_info != 0) {
    _printf(aPmapActivateD_1,dword_F013DF04);
    _printf(aPmapActivateAc,DAT_f013df08);
  }
  if ((dword_F013DF0C == 0) && (_pmap_func_info0 != 0)) {
    puVar1 = aPmapDeactivate;
    iVar2 = 0;
loc_F00A07A4:
    _printf(puVar1,iVar2);
  }
  else if ((dword_F013DF0C != 0) && (_pmap_func_info1 != 0)) {
    puVar1 = aPmapDeactivate_0;
    iVar2 = dword_F013DF0C;
    goto loc_F00A07A4;
  }
  if ((dword_F013DF10 == 0) && (_pmap_func_info0 != 0)) {
    puVar1 = aPmapKernelD;
    iVar2 = 0;
loc_F00A0808:
    _printf(puVar1,iVar2);
  }
  else if ((dword_F013DF10 != 0) && (_pmap_func_info1 != 0)) {
    puVar1 = aPmapKernelD_0;
    iVar2 = dword_F013DF10;
    goto loc_F00A0808;
  }
  if ((dword_F013DF14 == 0) && (_pmap_func_info0 != 0)) {
    puVar1 = aPmapZeroPageD;
    iVar2 = 0;
loc_F00A086C:
    _printf(puVar1,iVar2);
  }
  else if ((dword_F013DF14 != 0) && (_pmap_func_info1 != 0)) {
    puVar1 = aPmapZeroPageD_0;
    iVar2 = dword_F013DF14;
    goto loc_F00A086C;
  }
  if ((dword_F013DF18 == 0) && (_pmap_func_info0 != 0)) {
    puVar1 = aPmapCopyPageD;
    iVar2 = 0;
loc_F00A08D0:
    _printf(puVar1,iVar2);
  }
  else if ((dword_F013DF18 != 0) && (_pmap_func_info1 != 0)) {
    puVar1 = aPmapCopyPageD_0;
    iVar2 = dword_F013DF18;
    goto loc_F00A08D0;
  }
  if ((dword_F013DF1C == 0) && (_pmap_func_info0 != 0)) {
    puVar1 = aCopyToPhysD;
    iVar2 = 0;
loc_F00A0934:
    _printf(puVar1,iVar2);
  }
  else if ((dword_F013DF1C != 0) && (_pmap_func_info1 != 0)) {
    puVar1 = aCopyToPhysD_0;
    iVar2 = dword_F013DF1C;
    goto loc_F00A0934;
  }
  if ((dword_F013DF20 == 0) && (_pmap_func_info0 != 0)) {
    puVar1 = aCopyFromPhysD;
    iVar2 = 0;
loc_F00A0998:
    _printf(puVar1,iVar2);
  }
  else if ((dword_F013DF20 != 0) && (_pmap_func_info1 != 0)) {
    puVar1 = aCopyFromPhysD_0;
    iVar2 = dword_F013DF20;
    goto loc_F00A0998;
  }
  if ((dword_F013DF24 == 0) && (_pmap_func_info0 != 0)) {
    puVar1 = aAddPoolD;
    iVar2 = 0;
loc_F00A09FC:
    _printf(puVar1,iVar2);
  }
  else if ((dword_F013DF24 != 0) && (_pmap_func_info1 != 0)) {
    puVar1 = aAddPoolD_0;
    iVar2 = dword_F013DF24;
    goto loc_F00A09FC;
  }
  if ((dword_F013DF28 == 0) && (_pmap_func_info0 != 0)) {
    puVar1 = aDelFirstPoolD;
    iVar2 = 0;
loc_F00A0A60:
    _printf(puVar1,iVar2);
  }
  else if ((dword_F013DF28 != 0) && (_pmap_func_info1 != 0)) {
    puVar1 = aDelFirstPoolD_0;
    iVar2 = dword_F013DF28;
    goto loc_F00A0A60;
  }
  if ((dword_F013DF2C == 0) && (_pmap_func_info0 != 0)) {
    puVar1 = aDelAnyPoolD;
    iVar2 = 0;
loc_F00A0AC4:
    _printf(puVar1,iVar2);
  }
  else if ((dword_F013DF2C != 0) && (_pmap_func_info1 != 0)) {
    puVar1 = aDelAnyPoolD_0;
    iVar2 = dword_F013DF2C;
    goto loc_F00A0AC4;
  }
  if ((dword_F013DF30 == 0) && (_pmap_func_info0 != 0)) {
    puVar1 = aVmToSrmmuProtD;
    iVar2 = 0;
loc_F00A0B28:
    _printf(puVar1,iVar2);
  }
  else if ((dword_F013DF30 != 0) && (_pmap_func_info1 != 0)) {
    puVar1 = aVmToSrmmuProtD_0;
    iVar2 = dword_F013DF30;
    goto loc_F00A0B28;
  }
  if ((dword_F013DF34 == 0) && (_pmap_func_info0 != 0)) {
    puVar1 = aSrmmuToVmProtD;
    iVar2 = 0;
loc_F00A0B8C:
    _printf(puVar1,iVar2);
  }
  else if ((dword_F013DF34 != 0) && (_pmap_func_info1 != 0)) {
    puVar1 = aSrmmuToVmProtD_0;
    iVar2 = dword_F013DF34;
    goto loc_F00A0B8C;
  }
  if ((dword_F013DF38 == 0) && (_pmap_func_info0 != 0)) {
    puVar1 = aSetInvalidpteD;
    iVar2 = 0;
loc_F00A0BF0:
    _printf(puVar1,iVar2);
  }
  else if ((dword_F013DF38 != 0) && (_pmap_func_info1 != 0)) {
    puVar1 = aSetInvalidpteD_0;
    iVar2 = dword_F013DF38;
    goto loc_F00A0BF0;
  }
  if ((dword_F013DF3C == 0) && (_pmap_func_info0 != 0)) {
    puVar1 = aUpdatePteD;
    iVar2 = 0;
loc_F00A0C54:
    _printf(puVar1,iVar2);
  }
  else if ((dword_F013DF3C != 0) && (_pmap_func_info1 != 0)) {
    puVar1 = aUpdatePteD_0;
    iVar2 = dword_F013DF3C;
    goto loc_F00A0C54;
  }
  if ((dword_F013DF40 == 0) && (_pmap_func_info0 != 0)) {
    puVar1 = aSetPteD;
    iVar2 = 0;
loc_F00A0CB8:
    _printf(puVar1,iVar2);
  }
  else if ((dword_F013DF40 != 0) && (_pmap_func_info1 != 0)) {
    puVar1 = aSetPteD_0;
    iVar2 = dword_F013DF40;
    goto loc_F00A0CB8;
  }
  if ((dword_F013DF44 == 0) && (_pmap_func_info0 != 0)) {
    puVar1 = aSetPteModrefD;
    iVar2 = 0;
loc_F00A0D1C:
    _printf(puVar1,iVar2);
  }
  else if ((dword_F013DF44 != 0) && (_pmap_func_info1 != 0)) {
    puVar1 = aSetPteModrefD_0;
    iVar2 = dword_F013DF44;
    goto loc_F00A0D1C;
  }
  if ((dword_F013DF48 == 0) && (_pmap_func_info0 != 0)) {
    puVar1 = aSetPtpD;
    iVar2 = 0;
loc_F00A0D80:
    _printf(puVar1,iVar2);
  }
  else if ((dword_F013DF48 != 0) && (_pmap_func_info1 != 0)) {
    puVar1 = aSetPtpD_0;
    iVar2 = dword_F013DF48;
    goto loc_F00A0D80;
  }
  if ((dword_F013DF4C == 0) && (_pmap_func_info0 != 0)) {
    puVar1 = aSetInvalidptpD;
    iVar2 = 0;
loc_F00A0DE4:
    _printf(puVar1,iVar2);
  }
  else if ((dword_F013DF4C != 0) && (_pmap_func_info1 != 0)) {
    puVar1 = aSetInvalidptpD_0;
    iVar2 = dword_F013DF4C;
    goto loc_F00A0DE4;
  }
  if ((dword_F013DF50 == 0) && (_pmap_func_info0 != 0)) {
    puVar1 = aPmapAllocRegEn;
    iVar2 = 0;
loc_F00A0E48:
    _printf(puVar1,iVar2);
  }
  else if ((dword_F013DF50 != 0) && (_pmap_func_info1 != 0)) {
    puVar1 = aPmapAllocRegEn_0;
    iVar2 = dword_F013DF50;
    goto loc_F00A0E48;
  }
  if ((dword_F013DF54 == 0) && (_pmap_func_info0 != 0)) {
    puVar1 = aPmapDeallocReg;
    iVar2 = 0;
loc_F00A0EAC:
    _printf(puVar1,iVar2);
  }
  else if ((dword_F013DF54 != 0) && (_pmap_func_info1 != 0)) {
    puVar1 = aPmapDeallocReg_0;
    iVar2 = dword_F013DF54;
    goto loc_F00A0EAC;
  }
  if ((dword_F013DF58 == 0) && (_pmap_func_info0 != 0)) {
    puVar1 = aPmapSegEntryD;
    iVar2 = 0;
loc_F00A0F10:
    _printf(puVar1,iVar2);
  }
  else if ((dword_F013DF58 != 0) && (_pmap_func_info1 != 0)) {
    puVar1 = aPmapSegEntryD_0;
    iVar2 = dword_F013DF58;
    goto loc_F00A0F10;
  }
  if ((dword_F013DF5C == 0) && (_pmap_func_info0 != 0)) {
    puVar1 = aPmapAllocKsegE;
    iVar2 = 0;
loc_F00A0F74:
    _printf(puVar1,iVar2);
  }
  else if ((dword_F013DF5C != 0) && (_pmap_func_info1 != 0)) {
    puVar1 = aPmapAllocKsegE_0;
    iVar2 = dword_F013DF5C;
    goto loc_F00A0F74;
  }
  if ((dword_F013DF60 == 0) && (_pmap_func_info0 != 0)) {
    puVar1 = aPmapDeallocKse;
    iVar2 = 0;
loc_F00A0FD8:
    _printf(puVar1,iVar2);
  }
  else if ((dword_F013DF60 != 0) && (_pmap_func_info1 != 0)) {
    puVar1 = aPmapDeallocKse_0;
    iVar2 = dword_F013DF60;
    goto loc_F00A0FD8;
  }
  if ((dword_F013DF64 == 0) && (_pmap_func_info0 != 0)) {
    puVar1 = aPmapAllocSegEn;
    iVar2 = 0;
loc_F00A103C:
    _printf(puVar1,iVar2);
  }
  else if ((dword_F013DF64 != 0) && (_pmap_func_info1 != 0)) {
    puVar1 = aPmapAllocSegEn_0;
    iVar2 = dword_F013DF64;
    goto loc_F00A103C;
  }
  if ((dword_F013DF68 == 0) && (_pmap_func_info0 != 0)) {
    puVar1 = aPmapDeallocSeg;
    iVar2 = 0;
loc_F00A10A0:
    _printf(puVar1,iVar2);
  }
  else if ((dword_F013DF68 != 0) && (_pmap_func_info1 != 0)) {
    puVar1 = aPmapDeallocSeg_0;
    iVar2 = dword_F013DF68;
    goto loc_F00A10A0;
  }
  if ((dword_F013DF6C == 0) && (_pmap_func_info0 != 0)) {
    puVar1 = aPmapAllocConte;
    iVar2 = 0;
loc_F00A1104:
    _printf(puVar1,iVar2);
  }
  else if ((dword_F013DF6C != 0) && (_pmap_func_info1 != 0)) {
    puVar1 = aPmapAllocConte_0;
    iVar2 = dword_F013DF6C;
    goto loc_F00A1104;
  }
  if ((dword_F013DF70 == 0) && (_pmap_func_info0 != 0)) {
    puVar1 = aGarbageCollect;
    iVar2 = 0;
  }
  else {
    if ((dword_F013DF70 == 0) || (_pmap_func_info1 == 0)) goto locret_F00A1170;
    puVar1 = aGarbageCollect_0;
    iVar2 = dword_F013DF70;
  }
  _printf(puVar1,iVar2);
locret_F00A1170:
  return CONCAT44(param_2,param_1);
}

