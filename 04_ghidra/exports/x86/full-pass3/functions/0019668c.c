/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0019668c */

undefined4 FUN_0019668c(int param_1,undefined4 param_2,char param_3)

{
  int iVar1;
  
  if (*(int *)(param_1 + 0x114) == 1) {
    iVar1 = *(int *)(param_1 + 0x10c);
  }
  else {
    if (*(int *)(param_1 + 0x114) != 3) {
      return 0;
    }
    iVar1 = *(int *)(param_1 + 0x110);
  }
  (**(code **)(iVar1 + 0x14))(iVar1,(int)param_3);
  return 0;
}

