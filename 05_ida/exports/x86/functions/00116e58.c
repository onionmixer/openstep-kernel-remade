/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x116e58. */
int __cdecl bind(int a1, const sockaddr *a2, socklen_t a3)
{
  _DWORD *v3; // ebx
  int result; // eax
  int v5; // esi
  int v6; // [esp+8h] [ebp-4h] BYREF

  v3 = *(_DWORD **)(dword_1E875C + 36); /*0x116e65*/
  result = getsock(*v3); /*0x116e6b*/
  v5 = result; /*0x116e70*/
  if ( result ) /*0x116e77*/
  {
    *(_BYTE *)(dword_1E875C + 104) = sockargs(&v6, v3[1], v3[2], 8); /*0x116e93*/
    result = dword_1E875C; /*0x116e96*/
    if ( !*(_BYTE *)(dword_1E875C + 104) ) /*0x116e9e*/
    {
      *(_BYTE *)(dword_1E875C + 104) = sobind(*(_DWORD *)(v5 + 24), v6); /*0x116eb8*/
      m_freem(v6); /*0x116ebf*/
    }
  }
  return result; /*0x116ec7*/
}
