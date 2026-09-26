/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x00106cfc */

void _uzone_init(void)

{
  _u_task_zone = _zinit(0x298,0x53000,0xa600,0,s_utasks_001da879);
  _u_thread_zone = _zinit(0x158,0x2b000,0x5600,0,s_uthreads_001da880);
  return;
}

