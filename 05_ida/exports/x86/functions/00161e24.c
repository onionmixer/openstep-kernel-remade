/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x161e24. */
kern_return_t __cdecl processor_set_tasks(
        processor_set_t processor_set,
        task_array_t *task_list,
        mach_msg_type_number_t *task_listCnt)
{
  return processor_set_things(processor_set, (int **)task_list, task_listCnt, 0); /*0x161e3c*/
}
