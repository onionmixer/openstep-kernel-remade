
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

