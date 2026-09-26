/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1603b4. */
char *safe_prf(char *a1, ...)
{
  char *result; // eax
  int v2; // [esp-4h] [ebp-8h]
  char *v3; // [esp+0h] [ebp-4h] BYREF
  va_list va; // [esp+10h] [ebp+Ch] BYREF

  va_start(va, a1);
  v3 = &byte_1E5BC4; /*0x1603ba*/
  prf(a1, (int)va, 8, (int)&v3); /*0x1603cf*/
  result = v3; /*0x1603d4*/
  *v3 = 0; /*0x1603d7*/
  v3 = &byte_1E5BC4; /*0x1603da*/
  if ( byte_1E5BC4 ) /*0x1603eb*/
  {
    do /*0x160405*/
    {
      v2 = *v3++; /*0x1603f6*/
      miniMonPutchar(v2); /*0x1603fa*/
      result = v3; /*0x160402*/
    }
    while ( *v3 ); /*0x160405*/
  }
  return result; /*0x16040a*/
}
