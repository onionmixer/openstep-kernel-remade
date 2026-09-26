/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1840ec. */
int __cdecl sub_1840EC(unsigned __int16 a1)
{
  unsigned int v1; // eax
  int v2; // edx
  int v4; // ebx
  int *v5; // eax

  v1 = (unsigned __int8)a1 >> 3; /*0x1840f9*/
  v2 = a1 & 7; /*0x1840fe*/
  if ( v1 > 0xF || (a1 & 7u) > 7 ) /*0x184109*/
    return 0; /*0x18410b*/
  v4 = 9 * v1; /*0x184113*/
  v5 = &dword_1E7324[9 * v1]; /*0x18411a*/
  if ( v2 != 7 ) /*0x184123*/
    return v5[v2 + 1]; /*0x184140*/
  if ( dword_1E7564 == HIBYTE(a1) ) /*0x184132*/
    return 0; /*0x184134*/
  return dword_1E7324[v4]; /*0x184144*/
}
