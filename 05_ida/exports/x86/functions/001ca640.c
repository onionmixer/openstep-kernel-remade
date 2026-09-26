/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1ca640. */
id __cdecl object_reallocFromZone(id anObject, size_t nBytes, void *z)
{
  return _zoneRealloc(anObject, nBytes, z); /*0x1ca658*/
}
