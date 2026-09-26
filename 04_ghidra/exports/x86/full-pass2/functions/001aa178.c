/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001aa178 */

int FUN_001aa178(int param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  undefined4 uVar2;
  char local_14 [8];
  int local_c;
  undefined *local_8;
  
  local_c = param_1;
  local_8 = PTR_s_IODirectDevice_001fa2c0;
  iVar1 = _objc_msgSendSuper(&local_c,PTR_s_initFromDeviceDescription__001f9560,param_3);
  if (iVar1 == 0) {
    param_1 = 0;
  }
  else {
    iVar1 = _objc_msgSend(param_1,PTR_s_startIOThread_001f9b5c);
    if (iVar1 == 0) {
      uVar2 = _objc_msgSend(param_1,PTR_s_interruptPort_001f9b58);
      uVar2 = _objc_msgSend(PTR_s_DriverCmd_001f9dd4,PTR_s_alloc_001f9210,PTR_s_initPort__001f9b54,
                            uVar2);
      uVar2 = _objc_msgSend(uVar2);
      *(undefined4 *)(param_1 + 300) = uVar2;
      uVar2 = _objc_msgSend(PTR_s_NXLock_001f9da4,PTR_s_new_001f9468);
      *(undefined4 *)(param_1 + 0x138) = uVar2;
      *(int *)(param_1 + 0x148) = param_1 + 0x144;
      *(int *)(param_1 + 0x144) = param_1 + 0x144;
      iVar1 = DAT_001e86fc;
      DAT_001e86fc = DAT_001e86fc + 1;
      _sprintf(local_14,"%s%d",&DAT_001e5144,iVar1);
      _objc_msgSend(param_1,PTR_s_setName__001f947c,local_14);
      _objc_msgSend(param_1,PTR_s_setDeviceKind__001f9480,s_Ethernet_001e5147);
      _objc_msgSend(param_1,PTR_s_setUnit__001f9478,iVar1);
      _objc_msgSend(param_1,PTR_s_registerDevice_001f948c);
    }
    else {
      _objc_msgSend(param_1,PTR_s_free_001f921c);
      param_1 = 0;
    }
  }
  return param_1;
}

