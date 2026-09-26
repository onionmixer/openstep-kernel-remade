/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x11bdd0. */
int __cdecl vno_lockrelease(int a1)
{
  int v1; // edx
  int i; // ecx
  int v3; // eax
  int v4; // esi
  char v5; // bl
  int v7; // [esp+Ch] [ebp-1Ch]
  int v8; // [esp+10h] [ebp-18h]
  _WORD v9[2]; // [esp+14h] [ebp-14h] BYREF
  int v10; // [esp+18h] [ebp-10h]
  int v11; // [esp+1Ch] [ebp-Ch]

  v1 = *(_DWORD *)(*(_DWORD *)active_u + 40); /*0x11bde3*/
  if ( (v1 & 0x20000000) == 0 ) /*0x11bdec*/
    return 0; /*0x11bdec*/
  v7 = 0; /*0x11bdf2*/
  *(_DWORD *)(*(_DWORD *)active_u + 40) = v1 & 0xDFFFFFFF; /*0x11bdff*/
  v8 = *(_DWORD *)(a1 + 24); /*0x11be05*/
  for ( i = *(_DWORD *)(active_u + 344); i >= 0; --i ) /*0x11be15*/
  {
    v3 = *(_DWORD *)(*(_DWORD *)(active_u + 336) + 4 * i); /*0x11be24*/
    if ( v3 ) /*0x11be29*/
    {
      v4 = *(_DWORD *)(active_u + 340); /*0x11be2b*/
      v5 = *(_BYTE *)(i + v4); /*0x11be31*/
      if ( (v5 & 4) != 0 ) /*0x11be37*/
      {
        if ( *(_DWORD *)(v3 + 24) == v8 ) /*0x11be3f*/
        {
          v7 = 1; /*0x11be41*/
          *(_BYTE *)(i + v4) = v5 & 0xFB; /*0x11be4b*/
        }
        else
        {
          *(_DWORD *)(*(_DWORD *)active_u + 40) |= 0x20000000u; /*0x11be52*/
        }
      }
    }
  }
  if ( !v7 ) /*0x11be60*/
    return 0; /*0x11bea4*/
  v9[0] = 3; /*0x11be62*/
  v9[1] = 0; /*0x11be68*/
  v10 = 0; /*0x11be6e*/
  v11 = 0; /*0x11be75*/
  return (*(int (__stdcall **)(int, _WORD *, int, _DWORD, _DWORD))(*(_DWORD *)(v8 + 28) + 96))( /*0x11bea9*/
           v8,
           v9,
           8,
           *(_DWORD *)(active_u + 28),
           *(__int16 *)(*(_DWORD *)active_u + 48));
}
