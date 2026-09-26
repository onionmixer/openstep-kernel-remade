/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x128190. */
int __cdecl ip_freemoptions(int a1)
{
  int v1; // esi
  int v2; // ebx
  int result; // eax

  if ( a1 ) /*0x12819b*/
  {
    v1 = *(_DWORD *)(a1 + 4) + a1; /*0x12819f*/
    v2 = 0; /*0x1281a2*/
    if ( *(_WORD *)(v1 + 6) ) /*0x1281a4*/
    {
      do /*0x1281c0*/
        in_delmulti(*(int **)(v1 + 4 * v2++ + 8)); /*0x1281b1*/
      while ( v2 < *(unsigned __int16 *)(v1 + 6) ); /*0x1281c0*/
    }
    return m_free(a1); /*0x1281c3*/
  }
  return result; /*0x1281cb*/
}
