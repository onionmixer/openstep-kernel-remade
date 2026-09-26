/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1bee8c. */
int __cdecl Event_server(_DWORD *a1, int a2)
{
  int v2; // ecx
  int (__cdecl *v3)(int, int); // eax

  *(_BYTE *)(a2 + 3) = 1; /*0x1bee97*/
  *(_DWORD *)(a2 + 4) = 32; /*0x1bee9b*/
  *(_DWORD *)(a2 + 8) = a1[2]; /*0x1beea5*/
  *(_DWORD *)(a2 + 12) = 0; /*0x1beea8*/
  *(_DWORD *)(a2 + 16) = a1[4]; /*0x1beeb2*/
  *(_DWORD *)(a2 + 20) = a1[5] + 100; /*0x1beebb*/
  *(_DWORD *)(a2 + 24) = 268509186; /*0x1beec4*/
  *(_DWORD *)(a2 + 28) = -303; /*0x1beec7*/
  v2 = a1[5]; /*0x1beece*/
  if ( (unsigned int)(v2 - 31000) > 8 ) /*0x1beeda*/
    return 0; /*0x1beeda*/
  v3 = funcs_1BEEEE[v2 - 31000]; /*0x1beedc*/
  if ( !v3 ) /*0x1beee5*/
    return 0; /*0x1beee7*/
  v3((int)a1, a2); /*0x1beeee*/
  return 1; /*0x1beef8*/
}
