/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x157f1c. */
int __cdecl xxx_processor_set_default_priv(int a1, _DWORD *a2)
{
  if ( !a1 ) /*0x157f26*/
    return 4; /*0x157f40*/
  *a2 = &default_pset; /*0x157f28*/
  pset_reference(&default_pset); /*0x157f33*/
  return 0; /*0x157f3c*/
}
