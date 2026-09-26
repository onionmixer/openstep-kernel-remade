/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x00165964 */

void _task_init(void)

{
  int iVar1;
  boolean_t inherit_memory;
  task_t *child_task;
  
  child_task = (task_t *)0x11800;
  inherit_memory = 0x8c;
  _task_zone = _zinit(0x8c,0x11800,0x2300,0,s_tasks_001dfb94);
  _task_create(0,(ledger_array_t)0x0,0x1dfb90,inherit_memory,child_task);
  iVar1 = _kernel_task;
  *(undefined4 *)(_kernel_task + 0x4c) = 1;
  *(undefined4 *)(iVar1 + 0x50) = 1;
  return;
}

