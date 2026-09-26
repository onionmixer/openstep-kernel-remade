/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001b993c */

void FUN_001b993c(undefined4 param_1,undefined4 param_2,int param_3,undefined4 param_4,
                 undefined4 param_5,uint param_6)

{
  uint uVar1;
  
  uVar1 = *(int *)(param_3 + 4) - *(int *)(param_3 + 8);
  if (param_6 < uVar1) {
    uVar1 = param_6;
  }
  *(uint *)(param_3 + 8) = *(int *)(param_3 + 8) + uVar1;
  return;
}

