/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0016da3c */

void FUN_0016da3c(int param_1,int param_2,undefined4 *param_3)

{
  if ((*(int *)(param_1 + 4) == 0x18) && (*(char *)(param_1 + 3) == '\x01')) {
    if ((code *)param_3[9] == (code *)0x0) {
      *(undefined4 *)(param_2 + 0x1c) = 0xfffffed1;
    }
    else {
      (*(code *)param_3[9])(*param_3);
      *(undefined4 *)(param_2 + 0x1c) = 0xfffffecf;
    }
  }
  else {
    *(undefined4 *)(param_2 + 0x1c) = 0xfffffed0;
  }
  return;
}

