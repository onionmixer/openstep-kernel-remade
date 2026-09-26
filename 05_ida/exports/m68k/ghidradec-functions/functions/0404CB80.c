
void _mach_net_init(void)

{
  undefined *puVar1;
  undefined4 uStack_8;
  
  _listener_zone = _zinit(0x14,2000,0x14,0,aNetListenerZon);
  dword_40B3722 = 0x11;
  dword_40B3726 = 0x7ec;
  dword_40B372A = 0;
  dword_40B372E = 0;
  dword_40B3736 = 0x7a7;
  puVar1 = _listeners;
  do {
    puVar1 = (undefined *)((int)puVar1 + 4);
  } while (puVar1 < &_mach_net_kmsg_zone);
  _mach_net_kmsg_zone = _zinit(0x800,0x2000,0x800,0,aMachNetMessage);
  _zchange(_mach_net_kmsg_zone,0,0,0,0);
  _kmem_alloc_wired(_kernel_map,&uStack_8,0x2000);
  _zcram(_mach_net_kmsg_zone,uStack_8,0x2000);
  return;
}
