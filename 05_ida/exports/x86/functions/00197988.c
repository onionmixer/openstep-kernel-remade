/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x197988. */
char *__cdecl kmLocalizeString(char *__s2)
{
  int v1; // edi
  const char **v2; // ebx
  int v3; // esi
  char *result; // eax

  v1 = glLanguage; /*0x19798e*/
  if ( (unsigned int)glLanguage > 6 ) /*0x197997*/
    v1 = 0; /*0x197999*/
  if ( !kmLocalizedStrings[0] ) /*0x1979a2*/
    return __s2; /*0x1979a2*/
  v2 = (const char **)kmLocalizedStrings; /*0x1979a4*/
  v3 = 0; /*0x1979a9*/
  while ( strcmp(*v2, __s2) ) /*0x1979bd*/
  {
    v2 += 7; /*0x1979cc*/
    v3 += 7; /*0x1979cf*/
    if ( !*v2 ) /*0x1979d2*/
      return __s2; /*0x1979d5*/
  }
  result = (&kmLocalizedStrings[v1])[v3]; /*0x1979bf*/
  if ( !result ) /*0x1979c8*/
    return __s2; /*0x1979d7*/
  return result; /*0x1979dd*/
}
