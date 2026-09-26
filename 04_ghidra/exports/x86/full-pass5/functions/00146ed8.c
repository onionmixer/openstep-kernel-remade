/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x00146ed8 */

void _ipc_init(void)

{
  kern_return_t kVar1;
  boolean_t in_stack_fffffff4;
  task_t *in_stack_fffffff8;
  
  kVar1 = _task_create(0,(ledger_array_t)0x0,0x1f6248,in_stack_fffffff4,in_stack_fffffff8);
  if (kVar1 != 0) {
                    /* WARNING: Subroutine does not return */
    _panic(s_ipc_init_001de704);
  }
  _ipc_soft_map = *(undefined4 *)(_ipc_soft_task + 0xc);
  _ipc_kernel_map =
       _kmem_suballoc(_kernel_map,&stack0xfffffff8,&stack0xfffffff4,_ipc_kernel_map_size,1);
  _ipc_host_init();
  return;
}

