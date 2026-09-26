/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1a553c. */
char *__cdecl IOFindNameForValue(int a1, _DWORD *a2)
{
  _DWORD *v2; // eax

  v2 = a2; /*0x1a5542*/
  if ( a2[1] ) /*0x1a5545*/
  {
    while ( *v2 != a1 ) /*0x1a554e*/
    {
      v2 += 2; /*0x1a5550*/
      if ( !v2[1] ) /*0x1a5553*/
        goto LABEL_4; /*0x1a5557*/
    }
    return (char *)v2[1]; /*0x1a5574*/
  }
  else
  {
LABEL_4:
    sprintf(byte_1E8688, "%d(d) (UNDEFINED)", a1); /*0x1a5559*/
    return byte_1E8688; /*0x1a5569*/
  }
}
