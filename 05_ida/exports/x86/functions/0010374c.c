/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x10374c. */
int __cdecl profil(char *a1, size_t a2, unsigned __int32 a3, unsigned int a4)
{
  _DWORD *v4; // eax
  _DWORD *v5; // ebx
  int v6; // esi
  _DWORD *v7; // eax
  int result; // eax
  int v9; // ebx

  v4 = *(_DWORD **)(dword_1E875C + 36); /*0x103756*/
  v5 = (_DWORD *)active_u; /*0x103759*/
  v6 = active_u + 584; /*0x10375f*/
  *(_DWORD *)(active_u + 592) = *v4; /*0x103767*/
  v5[149] = v4[1]; /*0x103770*/
  v5[150] = v4[2]; /*0x103779*/
  v5[151] = v4[3]; /*0x103782*/
  if ( !v5[146] ) /*0x103788*/
  {
    v7 = (_DWORD *)simple_lock_alloc(); /*0x103791*/
    v5[146] = v7; /*0x103796*/
    *v7 = 0; /*0x10379c*/
  }
  result = v5[147]; /*0x1037a2*/
  if ( result ) /*0x1037aa*/
  {
    do /*0x1037be*/
    {
      v9 = *(_DWORD *)(result + 4); /*0x1037ac*/
      kfree(result, 0x18u); /*0x1037b2*/
      result = v9; /*0x1037ba*/
    }
    while ( v9 ); /*0x1037be*/
  }
  *(_DWORD *)(v6 + 4) = 0; /*0x1037c0*/
  return result; /*0x1037ca*/
}
