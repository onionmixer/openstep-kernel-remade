/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001aca48 */

void FUN_001aca48(int param_1,undefined4 param_2,int param_3)

{
  int local_c;
  undefined *local_8;
  
  if ((*(char *)(param_1 + 0x1c8) != '\0') && (param_3 != 3)) {
    *(undefined1 *)(param_1 + 0x1c8) = 0;
  }
  local_c = param_1;
  local_8 = PTR_s_IODisk_001fa388;
  _objc_msgSendSuper(&local_c,PTR_s_setLastReadyState__001f9c6c,param_3);
  return;
}

