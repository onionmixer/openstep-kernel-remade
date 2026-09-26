/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1cd558. */
_DWORD *__cdecl _cache_create(int a1)
{
  int v1; // ebx
  int v2; // eax
  _DWORD *result; // eax
  int i; // edx
  int v5; // [esp-4h] [ebp-10h]
  int v6; // [esp+0h] [ebp-Ch]
  int v7; // [esp+0h] [ebp-Ch]
  int v8; // [esp+4h] [ebp-8h]

  v1 = NXDefaultMallocZone(v6, v8); /*0x1cd56b*/
  v2 = NXDefaultMallocZone(24, v7); /*0x1cd56f*/
  result = (_DWORD *)(*(int (__stdcall **)(int, int))(v1 + 4))(v2, v5); /*0x1cd578*/
  for ( i = 0; i < 4; ++i ) /*0x1cd57a*/
    result[i + 2] = 0; /*0x1cd57c*/
  result[1] = 0; /*0x1cd589*/
  *result = 3; /*0x1cd591*/
  *(_DWORD *)(a1 + 32) = result; /*0x1cd593*/
  *(_DWORD *)(a1 + 16) &= ~0x20u; /*0x1cd596*/
  if ( dword_1E55A8 ) /*0x1cd5a1*/
    *(_DWORD *)(a1 + 16) &= ~0x40u; /*0x1cd5a3*/
  return result; /*0x1cd5aa*/
}
