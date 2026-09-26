/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1037d0. */
int __cdecl add_profil(char *a1, size_t a2, unsigned __int32 a3, unsigned int a4)
{
  int result; // eax
  _DWORD *v5; // ebx
  int v6; // esi

  result = dword_1E875C; /*0x1037d5*/
  v5 = *(_DWORD **)(dword_1E875C + 36); /*0x1037da*/
  v6 = active_u; /*0x1037dd*/
  if ( *(_DWORD *)(active_u + 604) ) /*0x1037e3*/
  {
    result = kalloc(0x18u); /*0x1037ee*/
    *(_DWORD *)(result + 8) = *v5; /*0x1037f5*/
    *(_DWORD *)(result + 12) = v5[1]; /*0x1037fb*/
    *(_DWORD *)(result + 16) = v5[2]; /*0x103801*/
    *(_DWORD *)(result + 20) = v5[3]; /*0x103807*/
    *(_DWORD *)(result + 4) = *(_DWORD *)(v6 + 588); /*0x103810*/
    *(_DWORD *)(v6 + 588) = result; /*0x103813*/
  }
  return result; /*0x10381c*/
}
