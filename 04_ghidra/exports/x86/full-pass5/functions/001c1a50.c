/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001c1a50 */

void FUN_001c1a50(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined1 param_4)

{
  undefined4 uVar1;
  
  uVar1 = _objc_msgSend(param_1,PTR_s_deviceDescription_001f9378);
  uVar1 = _objc_msgSend(param_1,PTR_s_class_001f9234,PTR_s_getPCIConfigData_atRegister_with_001f9668
                        ,param_3,param_4,uVar1);
  _objc_msgSend(uVar1);
  return;
}

