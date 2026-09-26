
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void _outw(i386_ioport_t port,ushort data)

{
  out(port,data);
  LOCK();
  _DAT_001e7728 = _DAT_001e7728 + 1;
  UNLOCK();
  return;
}

