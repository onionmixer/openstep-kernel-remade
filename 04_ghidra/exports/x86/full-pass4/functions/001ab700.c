/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001ab700 */

void FUN_001ab700(int param_1,undefined4 param_2,uint param_3)

{
  longlong lVar1;
  
  if ((*(int *)(param_1 + 0x158) != 0) || (*(int *)(param_1 + 0x15c) != 0)) {
    _ns_untimeout(FUN_001aaea0,param_1);
  }
  _IOGetTimestamp(param_1 + 0x158);
  lVar1 = (ulonglong)param_3 * 1000000 + *(longlong *)(param_1 + 0x158);
  *(longlong *)(param_1 + 0x158) = lVar1;
  _ns_abstimeout(FUN_001aaea0,param_1,lVar1,4);
  return;
}

