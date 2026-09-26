/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x185be8. */
char __cdecl kdp_exception_ack(_BYTE *a1, unsigned int a2)
{
  char result; // al

  result = (char)a1; /*0x185beb*/
  if ( a2 > 7 && *a1 == 0x8D ) /*0x185bf7*/
  {
    result = a1[1]; /*0x185bf9*/
    if ( byte_1F66B6 == result ) /*0x185c02*/
    {
      dword_1F66B8 = 0; /*0x185c04*/
      byte_1F66B6 = ++result; /*0x185c10*/
    }
  }
  return result; /*0x185c18*/
}
