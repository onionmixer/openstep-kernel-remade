/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001ab364 */

int FUN_001ab364(int param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  char local_14 [8];
  int local_c;
  undefined *local_8;
  
  local_c = param_1;
  local_8 = PTR_s_IODirectDevice_001fa310;
  iVar1 = _objc_msgSendSuper(&local_c,PTR_s_initFromDeviceDescription__001f9560,param_3);
  if (iVar1 == 0) {
    param_1 = 0;
  }
  else {
    iVar2 = _objc_msgSend(param_1,PTR_s_startIOThread_001f9b5c);
    iVar1 = DAT_001e5168;
    if (iVar2 == 0) {
      DAT_001e5168 = DAT_001e5168 + 1;
      _sprintf(local_14,"%s%d",&DAT_001e5158,iVar1);
      _objc_msgSend(param_1,PTR_s_setName__001f947c,local_14);
      _objc_msgSend(param_1,PTR_s_setDeviceKind__001f9480,s_TokenRing_001e515b);
      _objc_msgSend(param_1,PTR_s_setUnit__001f9478,iVar1);
      iVar1 = _objc_msgSend(param_1,PTR_s__getInstanceTable__001f9afc,param_3);
      if (iVar1 == 0) {
        uVar3 = _objc_msgSend(param_1,PTR_s_interruptPort_001f9b58);
        uVar3 = _objc_msgSend(PTR_s_DriverCmdtr_001f9dcc,PTR_s_alloc_001f9210,
                              PTR_s_initPort__001f9b54,uVar3);
        uVar3 = _objc_msgSend(uVar3);
        *(undefined4 *)(param_1 + 0x154) = uVar3;
        _objc_msgSend(param_1,PTR_s__set8025FrameSizes_001f9af8);
      }
      else {
        _objc_msgSend(param_1,PTR_s_free_001f921c);
        param_1 = 0;
      }
    }
    else {
      _objc_msgSend(param_1,PTR_s_free_001f921c);
      param_1 = 0;
    }
  }
  return param_1;
}

