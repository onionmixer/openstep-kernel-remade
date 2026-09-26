/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0018cc40 */

void _reboot_mach(uint param_1)

{
  if (_kernel_task != 0) {
    _reboot_how = param_1;
    _calloutDispatch(_halt_thread,0);
    return;
  }
  _boot(1,param_1 | 4);
  return;
}

