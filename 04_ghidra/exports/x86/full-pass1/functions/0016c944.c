/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0016c944 */

undefined4 _kern_serv_version(int *param_1,int param_2)

{
  if (1 < param_2) {
    *(int *)(*param_1 + 0x4c8) = param_2;
    return 0;
  }
  return 0x67;
}

