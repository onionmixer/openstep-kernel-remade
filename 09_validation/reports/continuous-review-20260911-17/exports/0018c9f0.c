
ushort _inw(i386_ioport_t port)

{
  ushort uVar1;
  
  uVar1 = in(port);
  return uVar1;
}

