/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x135f10. */
int __cdecl getport_loop(int a1, int a2, int a3, int a4)
{
  int v4; // ecx
  _WORD *v5; // edx
  int v6; // eax
  _DWORD *v7; // ebx
  int v8; // ecx
  int v9; // eax
  int v11; // [esp+Ch] [ebp-2Ch]
  int v12; // [esp+10h] [ebp-28h]
  __int16 v13; // [esp+16h] [ebp-22h] BYREF
  _DWORD v14[4]; // [esp+18h] [ebp-20h] BYREF
  _DWORD v15[4]; // [esp+28h] [ebp-10h] BYREF

  v11 = 0; /*0x135f19*/
  while ( 1 ) /*0x135f20*/
  {
    v13 = 0; /*0x135f20*/
    v12 = 0; /*0x135f26*/
    if ( !word_1E59F0 ) /*0x135f35*/
    {
      v4 = 15; /*0x135f37*/
      v5 = &unk_1E5A18; /*0x135f3c*/
      do /*0x135f4d*/
      {
        *v5-- = -1; /*0x135f44*/
        --v4; /*0x135f4c*/
      }
      while ( v4 >= 0 ); /*0x135f4d*/
      ++word_1E59F0; /*0x135f4f*/
    }
    v14[0] = *(_DWORD *)a1; /*0x135f5b*/
    v14[1] = *(_DWORD *)(a1 + 4); /*0x135f64*/
    v14[2] = *(_DWORD *)(a1 + 8); /*0x135f6d*/
    v14[3] = *(_DWORD *)(a1 + 12); /*0x135f76*/
    HIWORD(v14[0]) = __ROR2__(111, 8); /*0x135f82*/
    v6 = clntkudp_create((int)v14, 0x2000186A0LL, 4, (int)&word_1E59F0); /*0x135f98*/
    v7 = (_DWORD *)v6; /*0x135f9d*/
    if ( v6 ) /*0x135fa4*/
    {
      v15[0] = a2; /*0x135fad*/
      v15[1] = a3; /*0x135fb3*/
      v15[2] = a4; /*0x135fb9*/
      v15[3] = 0; /*0x135fbc*/
      if ( (**(int (__cdecl ***)(int, int, int (__cdecl *)(XDR *, pmap *), _DWORD *, int (__cdecl *)(XDR *, unsigned __int16 *), __int16 *, int, int))(v6 + 4))( /*0x135fea*/
             v6,
             3,
             xdr_pmap,
             v15,
             xdr_u_short,
             &v13,
             dword_1DD0D8,
             dword_1DD0DC) )
      {
        v12 = 1; /*0x135ff3*/
      }
      else if ( v13 ) /*0x136003*/
      {
        *(_WORD *)(a1 + 2) = __ROR2__(v13, 8); /*0x136017*/
      }
      else
      {
        v12 = -1; /*0x136005*/
      }
      (*(void (__cdecl **)(_DWORD))(*(_DWORD *)(*v7 + 32) + 16))(*v7); /*0x136024*/
      (*(void (__cdecl **)(_DWORD *))(v7[1] + 16))(v7); /*0x13602d*/
    }
    if ( v12 <= 0 ) /*0x136037*/
      break; /*0x136037*/
    if ( (*(_BYTE *)(active_threads + 380) & 3) != 0 /*0x136071*/
      || (v8 = *(_DWORD *)active_u,
          (v9 = *(_DWORD *)(*(_DWORD *)(active_threads + 132) + 124) | *(_DWORD *)(*(_DWORD *)active_u + 24)) != 0)
      && ((*(_BYTE *)(v8 + 40) & 0x10) != 0 || (v9 & ~(*(_DWORD *)(v8 + 28) | *(_DWORD *)(v8 + 32))) != 0)
      && issig(0) )
    {
      printf("Portmapper not responding; giving up\n"); /*0x136082*/
      return v12; /*0x136082*/
    }
    if ( ++v11 == 1 ) /*0x13608b*/
      printf("Portmapper not responding; still trying\n"); /*0x136096*/
  }
  if ( v11 ) /*0x1360a8*/
    printf(aPortm); /*0x1360af*/
  return v12; /*0x1360b9*/
}
