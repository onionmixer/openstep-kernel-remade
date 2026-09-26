/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x142fa0. */
unsigned int __cdecl scanc(int a1, unsigned __int8 *a2, int a3, unsigned __int8 a4)
{
  unsigned __int8 *v4; // edx
  unsigned int v5; // ecx

  v4 = a2; /*0x142fa5*/
  v5 = (unsigned int)&a2[a1]; /*0x142fb0*/
  while ( (unsigned int)v4 < v5 && (a4 & *(_BYTE *)(*v4 + a3)) == 0 ) /*0x142fc3*/
    ++v4; /*0x142fb8*/
  return v5 - (_DWORD)v4; /*0x142fcc*/
}
