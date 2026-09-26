/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1ca4c8. */
id __cdecl _internal_object_copy(Class *__src, size_t a2)
{
  void *v2; // eax
  int v4; // [esp+0h] [ebp-4h]
  int savedregs; // [esp+4h] [ebp+0h]

  v2 = (void *)NXZoneFromPtr(__src); /*0x1ca4d0*/
  if ( !v2 ) /*0x1ca4da*/
    v2 = (void *)NXDefaultMallocZone(v4, savedregs); /*0x1ca4dc*/
  return _internal_object_copyFromZone(__src, a2, v2); /*0x1ca4ec*/
}
