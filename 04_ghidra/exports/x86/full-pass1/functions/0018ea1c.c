/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0018ea1c */

undefined4 _thread_userstack(undefined4 param_1,int param_2,int param_3,uint param_4,int *param_5)

{
  int iVar1;
  
  if (*param_5 == 0) {
    *param_5 = -0x40000000;
  }
  if (param_2 == -1) {
    if (param_4 < 0x10) {
      return 4;
    }
    iVar1 = *(int *)(param_3 + 0x1c);
    if (iVar1 == 0) {
      iVar1 = -0x40000000;
    }
    *param_5 = iVar1;
  }
  return 0;
}

