/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1199ac. */
int __cdecl vafsidtovfs(int a1, _DWORD *a2)
{
  _DWORD *v2; // ebx
  int result; // eax
  int v4; // [esp+Ch] [ebp-44h] BYREF
  _BYTE v5[12]; // [esp+10h] [ebp-40h] BYREF
  int v6; // [esp+1Ch] [ebp-34h]

  v2 = (_DWORD *)rootvfs; /*0x1199bb*/
  if ( !rootvfs ) /*0x1199c3*/
    return 22; /*0x119a0e*/
  while ( 1 ) /*0x1199d3*/
  {
    result = (*(int (__cdecl **)(_DWORD *, int *))(v2[1] + 8))(v2, &v4); /*0x1199d3*/
    if ( result ) /*0x1199da*/
      break; /*0x1199da*/
    result = (*(int (__cdecl **)(int, _BYTE *, _DWORD))(*(_DWORD *)(v4 + 28) + 20))(v4, v5, *(_DWORD *)(active_u + 28)); /*0x1199f3*/
    if ( result ) /*0x1199fa*/
      break; /*0x1199fa*/
    if ( v6 == a1 ) /*0x1199ff*/
    {
      *a2 = v2; /*0x119a01*/
      return 0; /*0x119a05*/
    }
    v2 = (_DWORD *)*v2; /*0x119a08*/
    if ( !v2 ) /*0x119a0c*/
      return 22; /*0x119a0c*/
  }
  return result; /*0x119a16*/
}
