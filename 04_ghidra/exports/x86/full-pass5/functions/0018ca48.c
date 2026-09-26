/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0018ca48 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __regparm1 _outl(i386_ioport_t port,ulong data)

{
  undefined2 in_register_00000002;
  undefined2 in_stack_00000008;
  
  out((undefined2)data,CONCAT22(in_register_00000002,in_stack_00000008));
  LOCK();
  _DAT_001e772c = _DAT_001e772c + 1;
  UNLOCK();
  return;
}

