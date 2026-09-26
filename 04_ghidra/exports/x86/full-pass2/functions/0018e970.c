/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0018e970 */

undefined4 _get_thread_cthreadstate(int param_1,undefined4 *param_2,int *param_3)

{
  if (*param_3 != 0) {
    *param_2 = *(undefined4 *)(*(int *)(param_1 + 0x28) + 0xe8);
    *param_3 = 1;
    return 0;
  }
  return 4;
}

