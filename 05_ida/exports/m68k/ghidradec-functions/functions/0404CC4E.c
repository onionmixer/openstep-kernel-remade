
void _netipc_msg_release(undefined4 param_1)

{
  _zfree(_mach_net_kmsg_zone,param_1);
  return;
}
