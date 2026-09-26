/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001b725c */

void FUN_001b725c(int param_1)

{
  int local_c;
  undefined *local_8;
  
  _objc_msgSend(PTR_s_IOAudio_001f9dbc,PTR_s__setInstance__001f97c4,0);
  _IOFree(*(undefined4 *)(param_1 + 0x174),0x1c);
  local_c = param_1;
  local_8 = PTR_s_IODirectDevice_001fa478;
  _objc_msgSendSuper(&local_c,PTR_s_free_001f921c);
  return;
}

