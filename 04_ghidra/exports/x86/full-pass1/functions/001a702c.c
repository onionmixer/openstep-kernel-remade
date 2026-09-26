/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001a702c */

void FUN_001a702c(int param_1,undefined4 param_2,char param_3)

{
  int local_c;
  undefined *local_8;
  
  _objc_msgSend(param_1,PTR_s__freePartitions_001f9c44);
  *(undefined1 *)(param_1 + 0x1a8) = 0;
  local_c = param_1;
  local_8 = PTR_s_IOLogicalDisk_001fa158;
  _objc_msgSendSuper(&local_c,PTR_s_setFormattedInternal__001f9ca0,(int)param_3);
  return;
}

