/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0010ccd4 */

void _nosys(void)

{
  if ((*(int *)(_active_u + 0x60) == 1) || (*(int *)(_active_u + 0x60) == 3)) {
    *(undefined1 *)(DAT_001e875c + 0x68) = 0x16;
  }
  _exception_from_kernel(5,0x10000,0);
  return;
}

