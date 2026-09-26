/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0015db48 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void _mach_net_init(void)

{
  undefined4 *puVar1;
  undefined4 local_8;
  
  _listener_zone = _zinit(0x14,2000,0x14,0,s_net_listener_zone_001def29);
  DAT_001e5bac = 0x11;
  DAT_001e5bb0 = 0x7ec;
  _DAT_001e5bb4 = 0;
  _DAT_001e5bb8 = 0;
  _DAT_001e5bc0 = 0x7a7;
  puVar1 = &_listeners;
  do {
    *puVar1 = 0;
    puVar1 = puVar1 + 2;
  } while (puVar1 < &_mach_net_kmsg_zone);
  _mach_net_kmsg_zone = _zinit(0x800,0x2000,0x800,0,s_mach_net_messages_001def3b);
  _zchange(_mach_net_kmsg_zone,0,0,0,0);
  _kmem_alloc_wired(_kernel_map,&local_8,0x2000);
  _zcram(_mach_net_kmsg_zone,local_8,0x2000);
  return;
}

