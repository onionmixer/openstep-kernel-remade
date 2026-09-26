/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0016dae0 */

void FUN_0016dae0(int param_1,int param_2,undefined4 *param_3)

{
  if (((*(int *)(param_1 + 4) == 0x20) && (*(char *)(param_1 + 3) == '\0')) &&
     (*(int *)(param_1 + 0x18) == 0x10012006)) {
    if ((code *)param_3[0xb] == (code *)0x0) {
      *(undefined4 *)(param_2 + 0x1c) = 0xfffffed1;
    }
    else {
      (*(code *)param_3[0xb])(*param_3,*(undefined4 *)(param_1 + 0x1c));
      *(undefined4 *)(param_2 + 0x1c) = 0xfffffecf;
    }
  }
  else {
    *(undefined4 *)(param_2 + 0x1c) = 0xfffffed0;
  }
  return;
}

