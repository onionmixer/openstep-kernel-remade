/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1cbeb8. */
char *__cdecl NXCopyStringBufferFromZone(const char *buffer, void *z)
{
  char *v2; // eax

  v2 = (char *)(*((int (__cdecl **)(void *, unsigned int))z + 1))(z, strlen(buffer) + 1); /*0x1cbee2*/
  return strcpy(v2, buffer); /*0x1cbef1*/
}
