/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x16af6c. */
void __cdecl sub_16AF6C(_DWORD *a1)
{
  char *v1; // esi
  int v2; // ebx
  unsigned int v3; // eax

  v1 = (char *)&unk_1F6E04; /*0x16af78*/
  if ( !a1[5] ) /*0x16af7d*/
  {
    v2 = 1; /*0x16af83*/
    if ( zone_free_space_count > 1 ) /*0x16af8f*/
    {
      while ( 1 ) /*0x16afa0*/
      {
        v3 = -**(_DWORD **)v1 & (**(_DWORD **)v1 + a1[7] - 1); /*0x16afa0*/
        if ( *(_DWORD *)(*(_DWORD *)v1 + 4) >= v3 ) /*0x16afa5*/
          break; /*0x16afa5*/
        v1 += 4; /*0x16afb4*/
        if ( zone_free_space_count <= ++v2 ) /*0x16afbb*/
          return; /*0x16afbb*/
      }
      a1[7] = v3; /*0x16afa7*/
      a1[15] = *(_DWORD *)v1; /*0x16afac*/
    }
  }
}
