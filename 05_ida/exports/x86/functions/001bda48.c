/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1bda48. */
int __cdecl checksum16(_WORD *a1, int a2)
{
  unsigned int v3; // ebx
  int result; // eax

  v3 = 0; /*0x1bda4f*/
  while ( --a2 != -1 ) /*0x1bda69*/
    v3 += (unsigned __int16)__ROR2__(*a1++, 8); /*0x1bda64*/
  result = HIWORD(v3) + (unsigned __int16)v3; /*0x1bda77*/
  if ( result > 0xFFFF ) /*0x1bda7e*/
    LOWORD(result) = result + 1; /*0x1bda80*/
  return (unsigned __int16)result; /*0x1bda8a*/
}
