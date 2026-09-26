/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001a0d90 */

void _keyboard_reboot(void)

{
  byte bVar1;
  
  if (DAT_001e4b78 != (code *)0x0) {
    (*DAT_001e4b78)();
  }
  do {
    bVar1 = _inb(100);
  } while ((bVar1 & 2) != 0);
  _outb(100,0xfe);
  return;
}

