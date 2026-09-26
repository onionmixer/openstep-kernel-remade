
/* WARNING: Removing unreachable block (ram,0xf00038e0) */

void syscall(void)

{
  _syscall(_active_pcb + 0x234);
  sys_rtt();
  return;
}
