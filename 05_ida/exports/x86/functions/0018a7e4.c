/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x18a7e4. */
unsigned __int32 sub_18A7E4()
{
  unsigned __int32 result; // eax

  dword_1E75F8 = 0; /*0x18a7e7*/
  result = __readcr0(); /*0x18a7f1*/
  LOBYTE(result) = result | 8; /*0x18a7f4*/
  __writecr0(result); /*0x18a7f6*/
  return result; /*0x18a7fb*/
}
