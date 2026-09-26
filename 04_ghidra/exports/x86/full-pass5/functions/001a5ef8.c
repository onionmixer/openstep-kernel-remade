/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001a5ef8 */

int FUN_001a5ef8(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                undefined4 param_5,undefined4 param_6,undefined4 param_7)

{
  char cVar1;
  int iVar2;
  undefined4 local_c;
  undefined4 local_8;
  
  cVar1 = _objc_msgSend(param_1,PTR_s_isWriteProtected_001f9cb0);
  if (cVar1 == '\0') {
    iVar2 = _objc_msgSend(param_1,PTR_s__diskParamCommon_length_deviceOf_001f9cb8,param_3,param_4,
                          &local_8,&local_c);
    if (iVar2 == 0) {
      iVar2 = _objc_msgSend(*(undefined4 *)(param_1 + 0x184),
                            PTR_s_writeAt_length_buffer_actualLeng_001f9cac,local_8,local_c,param_5,
                            param_6,param_7);
    }
  }
  else {
    iVar2 = -0x2cf;
  }
  return iVar2;
}

