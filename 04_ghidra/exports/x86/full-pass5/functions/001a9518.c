/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001a9518 */

char * FUN_001a9518(undefined4 param_1,undefined4 param_2,int param_3)

{
  char *pcVar1;
  undefined4 local_c;
  undefined *local_8;
  
  if (param_3 == -0x321) {
    return "Not Owner";
  }
  if (param_3 == -800) {
    return "Buffer Flushed";
  }
  local_c = param_1;
  local_8 = PTR_s_IODirectDevice_001fa248;
  pcVar1 = (char *)_objc_msgSendSuper(&local_c,PTR_s_stringFromReturn__001f9490,param_3);
  return pcVar1;
}

