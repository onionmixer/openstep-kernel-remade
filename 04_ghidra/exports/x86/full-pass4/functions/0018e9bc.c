/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0018e9bc */

undefined4 _get_thread_state_flavor_list(undefined4 *param_1,uint *param_2)

{
  if (3 < *param_2) {
    *param_1 = 0xffffffff;
    param_1[1] = 0x10;
    param_1[2] = 0xfffffffe;
    param_1[3] = 0x1b;
    param_1[4] = 0xfffffffd;
    param_1[5] = 2;
    param_1[6] = 0xfffffffc;
    param_1[7] = 1;
    *param_2 = 8;
    return 0;
  }
  return 4;
}

