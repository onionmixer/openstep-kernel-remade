/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1cd7ec. */
int __cdecl sub_1CD7EC(int a1)
{
  int v1; // esi
  unsigned int v2; // ebx
  int result; // eax
  int v4; // edi
  int v5; // eax
  int v6; // [esp+0h] [ebp-Ch]
  int v7; // [esp+0h] [ebp-Ch]
  int v8; // [esp+4h] [ebp-8h]

  v1 = *(_DWORD *)(a1 + 32); /*0x1cd7f5*/
  if ( (_UNKNOWN *)v1 != &emptyCache ) /*0x1cd7fe*/
  {
    v2 = 0; /*0x1cd800*/
    do /*0x1cd841*/
    {
      if ( *(_DWORD *)(v1 + 4 * v2 + 8) ) /*0x1cd808*/
      {
        result = *(_DWORD *)(v1 + 4 * v2 + 8); /*0x1cd80f*/
        if ( *(id (**)(id, SEL, ...))(result + 8) == _objc_msgForward ) /*0x1cd81a*/
        {
          v4 = NXDefaultMallocZone(v6, v8); /*0x1cd821*/
          v5 = NXDefaultMallocZone(*(_DWORD *)(v1 + 4 * v2 + 8), v7); /*0x1cd828*/
          result = (*(int (__cdecl **)(int))(v4 + 8))(v5); /*0x1cd831*/
        }
      }
      *(_DWORD *)(v1 + 4 * v2++ + 8) = 0; /*0x1cd836*/
    }
    while ( *(_DWORD *)v1 >= v2 ); /*0x1cd841*/
    *(_DWORD *)(v1 + 4) = 0; /*0x1cd843*/
    *(_DWORD *)(a1 + 16) &= ~0x20u; /*0x1cd84d*/
  }
  return result; /*0x1cd854*/
}
