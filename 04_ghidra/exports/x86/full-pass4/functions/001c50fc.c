/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001c50fc */

undefined4 FUN_001c50fc(int param_1,undefined4 param_2,uint param_3)

{
  int iVar1;
  uint uVar2;
  undefined4 uVar3;
  
  iVar1 = _objc_msgSend(param_1,PTR_s_displayInfo_001f9610);
  if ((-1 < (int)param_3) &&
     (uVar2 = _objc_msgSend(param_1,PTR_s_displayModeCount_001f95fc), param_3 < uVar2)) {
    if (*(int *)(iVar1 + 0x80) != 0) {
      uVar3 = _objc_msgSend(param_1,PTR_s_name_001f9228,param_3,*(int *)(iVar1 + 0x80));
      _IOLog("%s: Display mode %d not available (error 0x%0x)\n",uVar3);
      return 0;
    }
    *(uint *)(param_1 + 0x214) = param_3;
    return 1;
  }
  uVar3 = _objc_msgSend(param_1,PTR_s_name_001f9228,param_3);
  _IOLog("%s: Invalid display mode: %d\n",uVar3);
  return 0;
}

