/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1ca4f4. */
int __cdecl _internal_object_dispose(_DWORD *a1)
{
  if ( a1 ) /*0x1ca4fd*/
  {
    *a1 = _objc_getFreedObjectClass(); /*0x1ca504*/
    free(a1); /*0x1ca507*/
  }
  return 0; /*0x1ca50e*/
}
