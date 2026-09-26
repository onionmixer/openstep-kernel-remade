/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001ba788 */

undefined4
FUN_001ba788(int param_1,undefined4 param_2,undefined4 param_3,int param_4,int param_5,
            undefined4 param_6)

{
  char cVar1;
  undefined4 uVar2;
  int local_c;
  undefined *local_8;
  
  local_c = param_1;
  local_8 = PTR_s_AudioStream_001fa518;
  cVar1 = _objc_msgSendSuper(&local_c,PTR_s_canConvertRegion_rate_format_cha_001f9734,param_3,
                             param_4,param_5,param_6);
  if ((cVar1 == '\0') &&
     (((param_5 == 2 || (param_5 == 4)) ||
      (((param_4 != 0x5622 || (*(int *)(param_1 + 100) != 0xac44)) &&
       ((param_4 != 0xac44 || (*(int *)(param_1 + 100) != 0x5622)))))))) {
    uVar2 = 0;
  }
  else {
    uVar2 = 1;
  }
  return uVar2;
}

