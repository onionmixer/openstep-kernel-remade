/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1cbe50. */
NXAtom __cdecl NXUniqueStringWithLength(const char *buffer, int length)
{
  char *v2; // ebx
  const char *v3; // edi
  char v5; // [esp+Ch] [ebp-100h] BYREF

  if ( length + 1 <= 256 ) /*0x1cbe67*/
    v2 = &v5; /*0x1cbe78*/
  else
    v2 = (char *)malloc(length + 1); /*0x1cbe6f*/
  memmove(v2, buffer, length); /*0x1cbe84*/
  v2[length] = 0; /*0x1cbe89*/
  v3 = NXUniqueString(v2); /*0x1cbe93*/
  if ( length + 1 > 256 ) /*0x1cbea0*/
    free(v2); /*0x1cbea3*/
  return v3; /*0x1cbeb0*/
}
