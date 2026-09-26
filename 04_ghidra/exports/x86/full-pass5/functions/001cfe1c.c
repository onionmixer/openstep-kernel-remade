/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001cfe1c */

void _objc_setMultithreaded(char param_1)

{
  if (param_1 == '\x01') {
    __objc_multithread_mask = 0;
    return;
  }
  __objc_multithread_mask = 0xffffffff;
  return;
}

