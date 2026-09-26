/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1427b4. */
void __cdecl sub_1427B4(_DWORD *a1, _DWORD *a2)
{
  int v2; // edx
  _DWORD *v3; // ebx

  v2 = a2[1]; /*0x1427c0*/
  if ( a1[1] == v2 ) /*0x1427c6*/
  {
    a1[1] = a2[2] + 1; /*0x1427cc*/
    a2[5] = a1; /*0x1427cf*/
  }
  else
  {
    if ( a1[2] == a2[2] ) /*0x1427da*/
    {
      a1[2] = v2 - 1; /*0x1427dd*/
      a2[5] = a1[5]; /*0x1427e3*/
    }
    else
    {
      v3 = (_DWORD *)kalloc(0x1Cu); /*0x1427ef*/
      bcopy(a1, v3, 0x1Cu); /*0x1427f5*/
      ++*(_DWORD *)(v3[4] + 8); /*0x1427fd*/
      v3[1] = a2[2] + 1; /*0x142804*/
      v3[6] = 0; /*0x142807*/
      a1[2] = a2[1] - 1; /*0x142812*/
      v3[5] = a1[5]; /*0x142818*/
      a2[5] = v3; /*0x14281b*/
    }
    a1[5] = a2; /*0x14281e*/
  }
}
