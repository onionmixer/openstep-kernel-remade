/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x157c0c. */
kern_return_t __cdecl host_processor_set_priv(
        host_priv_t host_priv,
        processor_set_name_t set_name,
        processor_set_t *set)
{
  if ( host_priv && set_name ) /*0x157c1d*/
  {
    *set = set_name; /*0x157c30*/
    pset_reference(set_name); /*0x157c33*/
    return 0; /*0x157c38*/
  }
  else
  {
    *set = 0; /*0x157c1f*/
    return 4; /*0x157c25*/
  }
}
