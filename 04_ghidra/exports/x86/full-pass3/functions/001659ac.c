/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001659ac */

void _kernel_task_create(task_t param_1,int param_2)

{
  undefined4 uVar1;
  boolean_t unaff_EBX;
  task_t *in_stack_fffffff0;
  undefined1 local_c [4];
  int local_8;
  
  _task_create(param_1,(ledger_array_t)0x0,(mach_msg_type_number_t)&local_8,unaff_EBX,
               in_stack_fffffff0);
  _task_deallocate(local_8);
  _vm_map_deallocate(*(undefined4 *)(local_8 + 0xc));
  if (param_2 == 0) {
    *(undefined4 *)(local_8 + 0xc) = _kernel_map;
  }
  else {
    uVar1 = _kmem_suballoc(_kernel_map,local_c,&stack0xfffffff0,param_2,0);
    *(undefined4 *)(local_8 + 0xc) = uVar1;
  }
  *(undefined4 *)(local_8 + 0x50) = 1;
  return;
}

