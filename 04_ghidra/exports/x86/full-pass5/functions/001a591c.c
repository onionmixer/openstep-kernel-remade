/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001a591c */

void FUN_001a591c(int param_1,undefined4 param_2,int param_3,undefined4 param_4,undefined4 param_5,
                 undefined4 param_6,undefined4 param_7)

{
  int iVar1;
  
  *(int *)(param_1 + 0x154) = *(int *)(param_1 + 0x154) + 1;
  *(int *)(param_1 + 0x158) = *(int *)(param_1 + 0x158) + param_3;
  iVar1 = __udivdi3(param_4,param_5,1000000,0);
  *(int *)(param_1 + 0x15c) = *(int *)(param_1 + 0x15c) + iVar1;
  iVar1 = __udivdi3(param_6,param_7,1000000,0);
  *(int *)(param_1 + 0x160) = *(int *)(param_1 + 0x160) + iVar1;
  return;
}

