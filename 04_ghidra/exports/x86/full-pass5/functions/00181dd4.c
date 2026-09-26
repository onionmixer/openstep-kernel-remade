/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x00181dd4 */

undefined4
_kern_IOGetIntValues
          (int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,undefined4 param_5,
          undefined4 *param_6)

{
  undefined4 uVar1;
  undefined4 local_8;
  
  local_8 = param_4;
  if (param_1 == 0) {
    uVar1 = 0xfffffd3f;
  }
  else {
    uVar1 = _objc_msgSend(PTR_s_IODevice_001f9d68,PTR_s_getIntValues_forParameter_object_001f9368,
                          param_5,param_3,param_2,&local_8);
    *param_6 = local_8;
  }
  return uVar1;
}

