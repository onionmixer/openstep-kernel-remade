/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0018ca18 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void _outb(i386_ioport_t port,uchar data)

{
  out(port,data);
  LOCK();
  _DAT_001e7724 = _DAT_001e7724 + 1;
  UNLOCK();
  return;
}

