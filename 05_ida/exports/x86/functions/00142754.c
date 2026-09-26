/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x142754. */
void __cdecl sub_142754(int a1, int a2)
{
  int v2; // eax

  if ( a2 ) /*0x14275f*/
  {
    v2 = *(_DWORD *)(a1 + 24); /*0x142761*/
    if ( v2 ) /*0x142766*/
    {
      while ( *(_DWORD *)(v2 + 24) ) /*0x142777*/
        v2 = *(_DWORD *)(v2 + 24); /*0x142770*/
      *(_DWORD *)(v2 + 24) = a2; /*0x142779*/
    }
    else
    {
      *(_DWORD *)(a1 + 24) = a2; /*0x142768*/
    }
  }
}
