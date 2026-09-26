/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001b182c */

undefined4 FUN_001b182c(int param_1,undefined4 param_2,int param_3,uint param_4,undefined4 param_5)

{
  undefined4 uVar1;
  
  if (param_3 == *(int *)(param_1 + 0x134)) {
    if (param_4 < 7) {
      *(undefined4 *)(param_1 + 0x118 + param_4 * 4) = param_5;
    }
    uVar1 = 0;
  }
  else {
    uVar1 = 0xfffffd3f;
  }
  return uVar1;
}

