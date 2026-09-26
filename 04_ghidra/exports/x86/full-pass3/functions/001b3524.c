/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001b3524 */

int _EvGetParameterChar(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                       undefined4 param_5,undefined4 *param_6)

{
  int iVar1;
  undefined4 local_8;
  
  local_8 = param_4;
  *param_6 = param_4;
  iVar1 = _objc_msgSend(PTR_s_EventDriver_001f9dc8,PTR_s_instance_001f9964);
  if (iVar1 == 0) {
    iVar1 = -0x2d9;
  }
  else {
    iVar1 = _objc_msgSend(iVar1,PTR_s_getCharValues_forParameter_count_001f9530,param_5,param_3,
                          &local_8);
    if (iVar1 == 0) {
      *param_6 = local_8;
    }
  }
  return iVar1;
}

