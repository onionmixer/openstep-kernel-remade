/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0018ca30 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void _outw(i386_ioport_t port,ushort data)

{
  out(port,data);
  LOCK();
  _DAT_001e7728 = _DAT_001e7728 + 1;
  UNLOCK();
  return;
}

