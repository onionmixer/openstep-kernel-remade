/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x116db4. */
int __cdecl socket(int a1, int a2, int a3)
{
  int *v3; // esi
  int result; // eax
  int v5; // ebx
  char *v6; // [esp+Ch] [ebp-4h] BYREF

  v3 = *(int **)(dword_1E875C + 36); /*0x116dc2*/
  result = falloc(); /*0x116dc5*/
  v5 = result; /*0x116dca*/
  if ( result ) /*0x116dce*/
  {
    *(_DWORD *)(result + 8) = 3; /*0x116dd0*/
    *(_WORD *)(result + 12) = 2; /*0x116dd7*/
    *(_DWORD *)(result + 20) = &socketops; /*0x116ddd*/
    *(_BYTE *)(dword_1E875C + 104) = socreate(*v3, &v6, v3[1], v3[2]); /*0x116dff*/
    if ( *(_BYTE *)(dword_1E875C + 104) ) /*0x116e08*/
    {
      result = *(_DWORD *)(active_u + 336); /*0x116e38*/
      *(_DWORD *)(result + 4 * *(_DWORD *)(dword_1E875C + 96)) = 0; /*0x116e3e*/
      *(_WORD *)(v5 + 14) = 0; /*0x116e45*/
    }
    else
    {
      *(_DWORD *)(v5 + 24) = v6; /*0x116e11*/
      result = *(_DWORD *)(active_u + 336); /*0x116e22*/
      *(_DWORD *)(result + 4 * *(_DWORD *)(dword_1E875C + 96)) = v5; /*0x116e28*/
    }
  }
  return result; /*0x116e4e*/
}
