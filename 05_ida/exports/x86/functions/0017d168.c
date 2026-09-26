/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x17d168. */
_WORD *__cdecl vnode_pager_create(int a1)
{
  _WORD *v1; // eax
  _WORD *v2; // ebx

  v1 = (_WORD *)zalloc(vstruct_zone); /*0x17d177*/
  v2 = v1; /*0x17d17c*/
  if ( !v1 ) /*0x17d183*/
    return nullptr; /*0x17d185*/
  bzero(v1, 0x18u); /*0x17d18f*/
  *(_DWORD *)v2 = 0; /*0x17d194*/
  v2[7] = 1; /*0x17d19a*/
  **(_DWORD **)a1 = v2; /*0x17d1a2*/
  *((_DWORD *)v2 + 5) = a1; /*0x17d1a4*/
  *((_BYTE *)v2 + 12) &= ~1u; /*0x17d1a7*/
  ++*(_WORD *)(a1 + 6); /*0x17d1ab*/
  do /*0x17d1c9*/
  {
    while ( vstruct_lock ) /*0x17d1b7*/
      ; /*0x17d1b5*/
  }
  while ( _InterlockedExchange(&vstruct_lock, 1) == 1 ); /*0x17d1c9*/
  --v2[7]; /*0x17d1cb*/
  _InterlockedExchange(&vstruct_lock, 0); /*0x17d1d1*/
  return v2; /*0x17d1dc*/
}
