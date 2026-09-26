/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1ca488. */
id __cdecl _internal_object_copyFromZone(Class *__src, size_t a2, void *a3)
{
  id v3; // ebx

  if ( !__src ) /*0x1ca496*/
    return nullptr; /*0x1ca4bc*/
  v3 = _zoneAlloc(*__src, a2, a3); /*0x1ca4a7*/
  memmove(v3, __src, (*__src)->instance_size + a2); /*0x1ca4b3*/
  return v3; /*0x1ca4c1*/
}
