
/* WARNING: Removing unreachable block (ram,0xf0003908) */

void machcall(void)

{
  _machcall(_active_pcb + 0x234);
  sys_rtt();
  return;
}
