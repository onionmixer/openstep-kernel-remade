/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0017f8f0 */

int FUN_0017f8f0(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                undefined4 param_5,undefined4 param_6,int param_7,undefined4 param_8)

{
  int iVar1;
  int iVar2;
  undefined8 uVar3;
  int local_c;
  undefined *local_8;
  
  iVar1 = param_7;
  if (param_7 == 0) {
    param_1 = _objc_msgSend(param_1,PTR_s_free_001f921c);
  }
  else {
    local_c = param_1;
    local_8 = PTR_s_KernBusRangeMapping_001f9f00;
    iVar2 = _objc_msgSendSuper(&local_c,PTR_s_initWithRange_subRange__001f92ac,param_3,param_4,
                               param_5);
    if (iVar2 == 0) {
      param_1 = 0;
    }
    else {
      uVar3 = _objc_msgSend(param_1,PTR_s_mappedRange_001f92b0);
      iVar2 = __KernBusMemoryCreateMapping(uVar3,&param_6,iVar1,0,param_8);
      if (iVar2 == 0) {
        *(int *)(param_1 + 0x10) = iVar1;
        *(undefined4 *)(param_1 + 0x14) = param_6;
      }
      else {
        param_1 = _objc_msgSend(param_1,PTR_s_free_001f921c);
      }
    }
  }
  return param_1;
}

