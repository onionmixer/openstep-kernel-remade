/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1cdb44. */
unsigned int __cdecl method_getNumberOfArguments(Method m)
{
  unsigned int v1; // ebx
  char *i; // edx

  v1 = 0; /*0x1cdb4b*/
  for ( i = (char *)sub_1CD9A4(m->method_types); (unsigned __int8)(*i - 48) <= 9u; ++i ) /*0x1cdb56*/
    ; /*0x1cdb60*/
  for ( ; *i; ++v1 ) /*0x1cdb69*/
  {
    i = (char *)sub_1CD9A4(i); /*0x1cdb76*/
    if ( *i != 45 ) /*0x1cdb7e*/
      goto LABEL_7; /*0x1cdb7e*/
    do /*0x1cdb87*/
    {
      ++i; /*0x1cdb80*/
LABEL_7:
      ; /*0x1cdb81*/
    }
    while ( (unsigned __int8)(*i - 48) <= 9u ); /*0x1cdb87*/
  }
  return v1; /*0x1cdb91*/
}
