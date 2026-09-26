/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x157eec. */
kern_return_t __cdecl processor_set_default(host_t host, processor_set_name_t *default_set)
{
  if ( !host ) /*0x157ef6*/
    return 4; /*0x157f10*/
  *default_set = (processor_set_name_t)&default_pset; /*0x157ef8*/
  pset_reference(&default_pset); /*0x157f03*/
  return 0; /*0x157f0c*/
}
