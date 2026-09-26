/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0016a198 */

void _init_timers(void)

{
  int iVar1;
  undefined *puVar2;
  
  puVar2 = &_kernel_timer;
  iVar1 = 0;
  do {
    _timer_init(puVar2);
    (&_current_timer)[iVar1] = 0;
    iVar1 = iVar1 + 1;
    puVar2 = puVar2 + 0x10;
  } while (iVar1 < 1);
  return;
}

