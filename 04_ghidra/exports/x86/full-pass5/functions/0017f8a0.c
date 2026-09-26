/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0017f8a0 */

void FUN_0017f8a0(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  undefined4 uVar1;
  undefined4 extraout_EDX;
  
  _objc_msgSend(param_1,PTR_s_range_001f9278);
  uVar1 = _objc_msgSend(PTR_s_KernBusMemoryRangeMapping_001f9d7c,PTR_s_alloc_001f9210,
                        PTR_s_initWithRange_subRange_inTarget__001f92a8,param_1,0,extraout_EDX,
                        param_3,param_4);
  _objc_msgSend(uVar1);
  return;
}

