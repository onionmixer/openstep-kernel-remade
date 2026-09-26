/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x18b04c. */
int __cdecl argstrcpy(char *a1, _BYTE *a2)
{
  int v4; // ebx
  char v5; // dl

  v4 = 0; /*0x18b056*/
  while ( 1 ) /*0x18b058*/
  {
    v5 = *a1; /*0x18b058*/
    if ( *a1 == 32 || !v5 || v5 == 9 || v5 == 44 ) /*0x18b06b*/
      break; /*0x18b06b*/
    ++v4; /*0x18b06d*/
    *a2 = v5; /*0x18b06e*/
    ++a1; /*0x18b070*/
    ++a2; /*0x18b071*/
  }
  *a2 = 0; /*0x18b074*/
  return v4; /*0x18b079*/
}
