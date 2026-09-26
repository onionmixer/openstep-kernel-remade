
/* WARNING: Removing unreachable block (ram,0xf00bd520) */
/* WARNING: Removing unreachable block (ram,0xf00bd470) */
/* WARNING: Removing unreachable block (ram,0xf00bd44c) */
/* WARNING: Removing unreachable block (ram,0xf00bd3cc) */
/* WARNING: Removing unreachable block (ram,0xf00bd370) */
/* WARNING: Removing unreachable block (ram,0xf00bd330) */
/* WARNING: Removing unreachable block (ram,0xf00bd304) */
/* WARNING: Removing unreachable block (ram,0xf00bd2c4) */
/* WARNING: Removing unreachable block (ram,0xf00bd2d0) */
/* WARNING: Removing unreachable block (ram,0xf00bd31c) */
/* WARNING: Removing unreachable block (ram,0xf00bd358) */
/* WARNING: Removing unreachable block (ram,0xf00bd398) */
/* WARNING: Removing unreachable block (ram,0xf00bd3dc) */
/* WARNING: Removing unreachable block (ram,0xf00bd42c) */
/* WARNING: Removing unreachable block (ram,0xf00bd4bc) */
/* WARNING: Removing unreachable block (ram,0xf00bd534) */
/* WARNING: Removing unreachable block (ram,0xf00bd2a4) */

sqword -[kmDevice canBecomeOwner:](int param_1,uint param_2)

{
  int iVar1;
  int iVar2;
  undefined (*pauVar3) [14];
  undefined (*pauVar4) [14];
  undefined (*pauVar5) [14];
  undefined (*pauVar6) [14];
  undefined *puVar7;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  int iVar8;
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
  iVar2 = *(int *)(param_1 + 0x120);
  _objc_msgSend(iVar2,paBecomeowner,param_1);
  if (iVar2 != 0) {
    iVar8 = param_1;
    _objc_msgSend(param_1,paStringfromretu,iVar2);
    _IOLog(aKmCanbecomeown,iVar8);
  }
  pauVar6 = paIoconfigtable;
  if (word_F0120418 == 0) {
    word_F0120418 = 1;
    pauVar3 = paIoconfigtable;
    _objc_msgSend(paIoconfigtable,paNewfromsystemc);
    pauVar4 = pauVar3;
    _objc_msgSend();
    if (pauVar4 != (undefined (*) [14])0x0) {
      pauVar5 = pauVar4;
      _strcmp();
      if (pauVar5 == (undefined (*) [14])0x0) {
        word_F012041A = 1;
      }
      _objc_msgSend(pauVar6,paFreestring,pauVar4);
    }
    pauVar6 = pauVar3;
    _objc_msgSend(pauVar3,paValueforstring,aLanguage);
    if (pauVar6 != (undefined (*) [14])0x0) {
      iVar2 = 0;
      iVar8 = 0;
      do {
        pauVar4 = pauVar6;
        _strcmp(pauVar6,*(undefined4 *)(unk_F01203BC + iVar8));
        iVar1 = iVar2;
        if (pauVar4 == (undefined (*) [14])0x0) break;
        iVar2 = iVar2 + 1;
        iVar8 = iVar8 + 4;
        iVar1 = _glLanguage._0_4_;
      } while (iVar2 < 7);
      _glLanguage._0_4_ = iVar1;
      _objc_msgSend(paIoconfigtable,paFreestring,pauVar6);
    }
    _objc_msgSend(pauVar3,paFree);
  }
  if (word_F012041A != 0) {
    _prettyShutdown = 0;
  }
  if ((dword_F0132064 == 0) || (_prettyShutdown != 0)) {
    _objc_msgSend(param_1,paReturntovgamod);
    iVar2 = _basicConsole;
  }
  else {
    iVar2 = dword_F0132064;
    _objc_msgSend(dword_F0132064,paAllocateconsol);
  }
  *(int *)(param_1 + 0x10c) = iVar2;
  iVar2 = 2;
  if (_prettyShutdown == 0) {
    iVar2 = 1;
  }
  *(int *)(param_1 + 0x114) = iVar2;
  _FBAllocateConsole();
  *(int *)(param_1 + 0x10c) = iVar2;
  if (iVar2 == 0) {
    *(int *)(param_1 + 0x10c) = _basicConsole;
  }
  (**(code **)(*(int *)(param_1 + 0x10c) + 4))
            (*(int *)(param_1 + 0x10c),*(undefined4 *)(param_1 + 0x114),1,1,_mach_title);
  _objc_msgSend(param_1,paDrawgraphicpan,1);
  if (_prettyShutdown == 1) {
    puVar7 = aRestartingTheC;
  }
  else if (_prettyShutdown == 2) {
    puVar7 = aPleaseWaitUnti_0;
  }
  else {
    puVar7 = aPleaseWait;
  }
  _objc_msgSend(param_1,paGraphicpanelst,puVar7);
  _objc_msgSend(param_1,paAnimationctl,2);
  return (qword)param_2 << 0x20;
}
