/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1bf3fc. */
int __cdecl audio_server(_DWORD *a1, int a2)
{
  int v2; // ecx
  int (__cdecl *v3)(int, int); // eax

  *(_BYTE *)(a2 + 3) = 1; /*0x1bf407*/
  *(_DWORD *)(a2 + 4) = 32; /*0x1bf40b*/
  *(_DWORD *)(a2 + 8) = a1[2]; /*0x1bf415*/
  *(_DWORD *)(a2 + 12) = 0; /*0x1bf418*/
  *(_DWORD *)(a2 + 16) = a1[4]; /*0x1bf422*/
  *(_DWORD *)(a2 + 20) = a1[5] + 100; /*0x1bf42b*/
  *(_DWORD *)(a2 + 24) = 268509186; /*0x1bf434*/
  *(_DWORD *)(a2 + 28) = -303; /*0x1bf437*/
  v2 = a1[5]; /*0x1bf43e*/
  if ( (unsigned int)(v2 - 700) > 0x24 ) /*0x1bf44a*/
    return 0; /*0x1bf44a*/
  v3 = funcs_1BF45E[v2 - 700]; /*0x1bf44c*/
  if ( !v3 ) /*0x1bf455*/
    return 0; /*0x1bf457*/
  v3((int)a1, a2); /*0x1bf45e*/
  return 1; /*0x1bf468*/
}
