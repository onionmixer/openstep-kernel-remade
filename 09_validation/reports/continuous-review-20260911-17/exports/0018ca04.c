
ulong _inl(i386_ioport_t port)

{
  uint uVar1;
  
  uVar1 = in(port);
  return uVar1 & 0xffff;
}

