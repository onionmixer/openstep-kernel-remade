/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x00166984 */

kern_return_t _task_get_assignment(task_t task,processor_set_name_t *assigned_set)

{
  processor_set_name_t pVar1;
  
  if (*(int *)(task + 8) != 0) {
    pVar1 = *(processor_set_name_t *)(task + 0x2c);
    *assigned_set = pVar1;
    _pset_reference(pVar1);
    return 0;
  }
  return 5;
}

