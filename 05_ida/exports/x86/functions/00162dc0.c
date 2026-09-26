/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x162dc0. */
int sched_init()
{
  int v0; // ebx
  unsigned int v1; // edx
  int *v2; // eax
  int v3; // ecx

  dword_1F6700 = (int)recompute_priorities; /*0x162dc5*/
  dword_1F6704 = 0; /*0x162dcf*/
  init_timeout_element(recompute_priorities_timer); /*0x162dde*/
  min_quantum = hz / 10; /*0x162df0*/
  v0 = 0; /*0x162df8*/
  v1 = 0; /*0x162dfa*/
  v2 = wait_queue; /*0x162dfc*/
  v3 = 0; /*0x162e01*/
  do /*0x162e28*/
  {
    dword_1F6A14[v3] = (int)v2; /*0x162e04*/
    wait_queue[v1 / 2] = (int)v2; /*0x162e0a*/
    wait_lock[v1 / 4] = 0; /*0x162e11*/
    v1 += 4; /*0x162e1b*/
    v2 += 2; /*0x162e1e*/
    v3 += 2; /*0x162e21*/
    ++v0; /*0x162e24*/
  }
  while ( v0 <= 58 ); /*0x162e28*/
  pset_sys_bootstrap(); /*0x162e2a*/
  dword_1F648C = (int)&action_queue; /*0x162e2f*/
  action_queue = (int)&action_queue; /*0x162e39*/
  action_lock = 0; /*0x162e43*/
  sched_tick = 0; /*0x162e4d*/
  return ast_init(); /*0x162e5f*/
}
