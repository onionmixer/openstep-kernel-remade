/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x00107914 */

undefined4 _insert_posix_proc(uint *param_1,uint param_2)

{
  uint *puVar1;
  
  puVar1 = (uint *)(&_posix_proc_hash)[param_2 & 0x3f];
  while( true ) {
    if (puVar1 == (uint *)0x0) {
      *param_1 = param_2;
      param_1[7] = (&_posix_proc_hash)[param_2 & 0x3f];
      (&_posix_proc_hash)[param_2 & 0x3f] = param_1;
      return 1;
    }
    if (*puVar1 == param_2) break;
    puVar1 = (uint *)puVar1[7];
  }
  return 0;
}

