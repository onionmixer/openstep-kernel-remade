/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x161e40. */
kern_return_t __cdecl processor_set_threads(
        processor_set_t processor_set,
        thread_act_array_t *thread_list,
        mach_msg_type_number_t *thread_listCnt)
{
  return processor_set_things(processor_set, (int **)thread_list, thread_listCnt, 1); /*0x161e58*/
}
