/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x166984. */
kern_return_t __cdecl task_get_assignment(task_t task, processor_set_name_t *assigned_set)
{
  processor_set_name_t v2; // eax

  if ( !*(_DWORD *)(task + 8) ) /*0x16698d*/
    return 5; /*0x1669a4*/
  v2 = *(_DWORD *)(task + 44); /*0x166993*/
  *assigned_set = v2; /*0x166996*/
  pset_reference(v2); /*0x166999*/
  return 0; /*0x1669a2*/
}
