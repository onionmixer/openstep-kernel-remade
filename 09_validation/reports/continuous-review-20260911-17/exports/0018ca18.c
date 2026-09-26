
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void _outb(i386_ioport_t port,uchar data)

{
  out(port,data);
  LOCK();
  _DAT_001e7724 = _DAT_001e7724 + 1;
  UNLOCK();
  return;
}

