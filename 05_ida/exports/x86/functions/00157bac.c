/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x157bac. */
kern_return_t __cdecl host_processor_sets(
        host_priv_t host_priv,
        processor_set_name_array_t *processor_sets,
        mach_msg_type_number_t *processor_setsCnt)
{
  processor_set_t *v4; // ebx

  if ( !host_priv ) /*0x157bbc*/
    return 4; /*0x157bbe*/
  v4 = (processor_set_t *)kalloc(4u); /*0x157bcf*/
  if ( !v4 ) /*0x157bd6*/
    return 6; /*0x157bfc*/
  pset_reference(&default_pset); /*0x157bdd*/
  *v4 = convert_pset_name_to_port(&default_pset); /*0x157bec*/
  *processor_sets = v4; /*0x157bee*/
  *processor_setsCnt = 1; /*0x157bf0*/
  return 0; /*0x157c04*/
}
