/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x00181d64 */

undefined4
_kern_IOLookupByObjectNumber(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  undefined4 uVar1;
  
  if (param_1 != 0) {
    uVar1 = _objc_msgSend(PTR_s_IODevice_001f9d68,PTR_s_lookupByObjectNumber_deviceKind__001f9360,
                          param_2,param_3,param_4);
    return uVar1;
  }
  return 0xfffffd3f;
}

