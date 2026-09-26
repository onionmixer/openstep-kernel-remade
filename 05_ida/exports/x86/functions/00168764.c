/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x168764. */
kern_return_t __cdecl thread_get_assignment(thread_act_t thread, processor_set_name_t *assigned_set)
{
  processor_set_name_t v2; // edx

  v2 = *(_DWORD *)(thread + 384); /*0x16876d*/
  *assigned_set = v2; /*0x168773*/
  pset_reference(v2); /*0x168776*/
  return 0; /*0x16877f*/
}
