/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001c6ec8 */

int FUN_001c6ec8(int param_1)

{
  undefined4 uVar1;
  int iVar2;
  int *piVar3;
  char *pcVar4;
  int local_24;
  int local_20;
  int local_1c;
  int local_18;
  int local_14;
  int local_10;
  int local_c;
  int local_8;
  
  if (*(char *)(param_1 + 0x250) != '\0') {
    uVar1 = _objc_msgSend(param_1,PTR_s_name_001f9228);
    _IOLog("%s: verifying selected mode.\n",uVar1);
  }
  iVar2 = _objc_msgSend(param_1,PTR_s_runVPCode_withRegs__001f9590,0,&local_24);
  if (iVar2 == 0) {
    uVar1 = _objc_msgSend(param_1,PTR_s_name_001f9228);
    pcVar4 = "%s: Failed to verify mode.\n";
  }
  else {
    if (local_24 != 0) {
      uVar1 = _objc_msgSend(param_1,PTR_s_name_001f9228);
      _IOLog("%s: Selected mode is invalid.\n",uVar1);
      iVar2 = _objc_msgSend(param_1,PTR_s_runVPCode_withRegs__001f9590,4,0);
      if (iVar2 == 0) {
        uVar1 = _objc_msgSend(param_1,PTR_s_name_001f9228);
        pcVar4 = "%s: Failed to set default mode.\n";
        goto LAB_001c7037;
      }
    }
    if (*(char *)(param_1 + 0x250) != '\0') {
      uVar1 = _objc_msgSend(param_1,PTR_s_name_001f9228);
      _IOLog("%s: Getting display info.\n",uVar1);
    }
    iVar2 = _objc_msgSend(param_1,PTR_s_runVPCode_withRegs__001f9590,5,&local_24);
    if (iVar2 != 0) {
      piVar3 = (int *)_objc_msgSend(param_1,PTR_s_displayInfo_001f9610);
      *piVar3 = local_24;
      piVar3[1] = local_20;
      piVar3[2] = local_1c;
      piVar3[3] = local_18;
      piVar3[4] = local_14;
      piVar3[6] = local_10;
      piVar3[7] = local_c;
      piVar3[0x18] = local_8;
      iVar2 = _objc_msgSend(param_1,PTR_s_getPixelEncoding_001f958c);
      if (iVar2 == 0) {
        return 0;
      }
      uVar1 = _objc_msgSend(param_1,PTR_s_name_001f9228);
      _IOLog("%s: IOVPCodeDisplay: Initialized.\n",uVar1);
      return param_1;
    }
    uVar1 = _objc_msgSend(param_1,PTR_s_name_001f9228);
    pcVar4 = "%s: Failed to obtain display info.\n";
  }
LAB_001c7037:
  _IOLog(pcVar4,uVar1);
  return 0;
}

