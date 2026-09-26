/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001a5d60 */

undefined4 FUN_001a5d60(undefined4 param_1,undefined4 param_2,int param_3)

{
  undefined4 uVar1;
  undefined4 local_c;
  undefined *local_8;
  
  if (param_3 == -0x44d) {
    return 0x16;
  }
  if (param_3 < -0x44c) {
    if (param_3 == -0x44e) {
      return 6;
    }
  }
  else if (param_3 == -0x44c) {
    return 6;
  }
  local_c = param_1;
  local_8 = PTR_s_IODevice_001fa108;
  uVar1 = _objc_msgSendSuper(&local_c,PTR_s_errnoFromReturn__001f93b4,param_3);
  return uVar1;
}

