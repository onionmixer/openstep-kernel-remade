/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x00195c68 */

undefined4 FUN_00195c68(int param_1)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  char *pcVar4;
  int iVar5;
  char *pcVar6;
  char *pcVar7;
  bool bVar8;
  
  iVar2 = _objc_msgSend(*(undefined4 *)(param_1 + 0x120),PTR_s_becomeOwner__001f9494,param_1);
  if (iVar2 != 0) {
    uVar3 = _objc_msgSend(param_1,PTR_s_stringFromReturn__001f9490,iVar2);
    _IOLog(s_km_canBecomeOwner__becomeOwner_f_001e3d8c,uVar3);
  }
  if (DAT_001e3d88 == 0) {
    DAT_001e3d88 = 1;
    uVar3 = _objc_msgSend(PTR_s_IOConfigTable_001f9d90,PTR_s_newFromSystemConfig_001f94ac);
    pcVar4 = (char *)_objc_msgSend(uVar3,PTR_s_valueForStringKey__001f9308,
                                   s_Shutdown_Graphics_001e3db8);
    if (pcVar4 != (char *)0x0) {
      iVar2 = 3;
      bVar8 = true;
      pcVar6 = pcVar4;
      pcVar7 = &DAT_001e3dca;
      do {
        if (iVar2 == 0) break;
        iVar2 = iVar2 + -1;
        bVar8 = *pcVar6 == *pcVar7;
        pcVar6 = pcVar6 + 1;
        pcVar7 = pcVar7 + 1;
      } while (bVar8);
      if (bVar8) {
        DAT_001e3d8a = 1;
      }
      _objc_msgSend(PTR_s_IOConfigTable_001f9d90,PTR_s_freeString__001f9314,pcVar4);
    }
    pcVar4 = (char *)_objc_msgSend(uVar3,PTR_s_valueForStringKey__001f9308,s_Language_001e3dcd);
    if (pcVar4 != (char *)0x0) {
      iVar2 = 0;
      do {
        iVar5 = _strcmp(pcVar4,(&PTR_s_English_001e3d34)[iVar2]);
        iVar1 = iVar2;
        if (iVar5 == 0) break;
        iVar2 = iVar2 + 1;
        iVar1 = _glLanguage;
      } while (iVar2 < 7);
      _glLanguage = iVar1;
      _objc_msgSend(PTR_s_IOConfigTable_001f9d90,PTR_s_freeString__001f9314,pcVar4);
    }
    _objc_msgSend(uVar3,PTR_s_free_001f921c);
  }
  if (DAT_001e3d8a != 0) {
    _prettyShutdown = 0;
  }
  if ((DAT_001e7768 == 0) || (_prettyShutdown != 0)) {
    _objc_msgSend(param_1,PTR_s_returnToVGAMode_001f94b0);
    *(undefined4 *)(param_1 + 0x10c) = _basicConsole;
  }
  else {
    uVar3 = _objc_msgSend(DAT_001e7768,PTR_s_allocateConsoleInfo_001f949c);
    *(undefined4 *)(param_1 + 0x10c) = uVar3;
  }
  if (_prettyShutdown == 0) {
    *(undefined4 *)(param_1 + 0x114) = 1;
  }
  else {
    *(undefined4 *)(param_1 + 0x114) = 2;
  }
  (**(code **)(*(int *)(param_1 + 0x10c) + 4))
            (*(int *)(param_1 + 0x10c),*(undefined4 *)(param_1 + 0x114),1,1,_mach_title);
  _objc_msgSend(param_1,PTR_s_drawGraphicPanel__001f94b4,1);
  if (_prettyShutdown == 1) {
    pcVar4 = s_Restarting_the_computer____001e3dd6;
  }
  else if (_prettyShutdown == 2) {
    pcVar4 = s_Please_wait_until_it_s_safe_to_t_001e3df2;
  }
  else {
    pcVar4 = s_Please_wait____001e3e29;
  }
  _objc_msgSend(param_1,PTR_s_graphicPanelString__001f94b8,pcVar4);
  _objc_msgSend(param_1,PTR_s_animationCtl__001f94a4,2);
  return 0;
}

