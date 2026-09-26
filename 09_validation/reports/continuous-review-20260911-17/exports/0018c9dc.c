
uchar _inb(i386_ioport_t port)

{
  uchar uVar1;
  
  uVar1 = in(port);
  return uVar1;
}

