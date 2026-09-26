
/* WARNING: Removing unreachable block (ram,0xf000314c) */
/* WARNING: Removing unreachable block (ram,0xf0003144) */

void _return_with_state(void)

{
  _flush_user_windows();
  _reset_windows();
  *(undefined4 *)(*(int *)(*_active_pcb + 0x2a0) + 0x5c) = *(undefined4 *)(*_active_pcb + 0x234);
  sys_rtt();
  return;
}

