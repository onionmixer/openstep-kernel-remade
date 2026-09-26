/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x00107898 */

void _get_posix_proc(uint param_1)

{
  uint *puVar1;
  char local_54 [80];
  
  puVar1 = (uint *)(&_posix_proc_hash)[param_1 & 0x3f];
  while( true ) {
    if (puVar1 == (uint *)0x0) {
      _sprintf(local_54,s_get_posix_proc____no_posix_proc_s_001da924,param_1);
                    /* WARNING: Subroutine does not return */
      _panic(local_54);
    }
    if (*puVar1 == param_1) break;
    puVar1 = (uint *)puVar1[7];
  }
  return;
}

