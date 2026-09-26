/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x00161e24 */

kern_return_t
_processor_set_tasks
          (processor_set_t processor_set,task_array_t *task_list,
          mach_msg_type_number_t *task_listCnt)

{
  kern_return_t kVar1;
  
  kVar1 = _processor_set_things(processor_set,task_list,task_listCnt,0);
  return kVar1;
}

