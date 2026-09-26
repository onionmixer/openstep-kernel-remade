/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x00161e40 */

kern_return_t
_processor_set_threads
          (processor_set_t processor_set,thread_act_array_t *thread_list,
          mach_msg_type_number_t *thread_listCnt)

{
  kern_return_t kVar1;
  
  kVar1 = _processor_set_things(processor_set,thread_list,thread_listCnt,1);
  return kVar1;
}

