/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x101488. */
void __cdecl bcopy16(char *a1, char *a2, signed int a3)
{
  char *v3; // ebx
  int v4; // edx
  int v5; // eax
  int v6; // ecx
  _WORD *v7; // edi
  char *v8; // esi
  int v9; // eax

  v3 = a1; /*0x10148e*/
  v4 = a3; /*0x101491*/
  if ( a3 > 15 ) /*0x101497*/
  {
    v5 = (unsigned __int8)a1 & 3; /*0x1014a6*/
    if ( ((unsigned __int8)a1 & 3) != 0 ) /*0x1014a9*/
    {
      qmemcpy(a2, a1, 4 - v5); /*0x1014b9*/
      v4 = a3 - (4 - v5); /*0x1014bb*/
      a2 += 4 - v5; /*0x1014bd*/
      v3 = &a1[4 - v5]; /*0x1014c0*/
    }
    v6 = v4 >> 1; /*0x1014c6*/
    v7 = a2; /*0x1014c8*/
    v8 = v3; /*0x1014cb*/
    while ( v6 ) /*0x1014cd*/
    {
      *v7 = *(_WORD *)v8; /*0x1014cd*/
      v8 += 2; /*0x1014cd*/
      ++v7; /*0x1014cd*/
      --v6; /*0x1014cd*/
    }
    if ( (v4 & 1) != 0 ) /*0x1014d3*/
    {
      v9 = v4; /*0x1014d5*/
      LOBYTE(v9) = v4 & 0xFE; /*0x1014d7*/
      a2[v9] = v3[v9]; /*0x1014df*/
    }
  }
  else
  {
    qmemcpy(a2, a1, a3); /*0x1014a0*/
  }
}
