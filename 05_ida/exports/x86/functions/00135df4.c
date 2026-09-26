/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x135df4. */
int __cdecl pmap_kgetport(int a1, int a2, int a3, int a4)
{
  int v4; // ecx
  _WORD *v5; // edx
  int v6; // eax
  _DWORD *v7; // ebx
  int v9; // [esp+Ch] [ebp-28h]
  __int16 v10; // [esp+12h] [ebp-22h] BYREF
  _DWORD v11[4]; // [esp+14h] [ebp-20h] BYREF
  _DWORD v12[4]; // [esp+24h] [ebp-10h] BYREF

  v10 = 0; /*0x135e00*/
  v9 = 0; /*0x135e06*/
  if ( !word_1E59F0 ) /*0x135e15*/
  {
    v4 = 15; /*0x135e17*/
    v5 = &unk_1E5A18; /*0x135e1c*/
    do /*0x135e2d*/
    {
      *v5-- = -1; /*0x135e24*/
      --v4; /*0x135e2c*/
    }
    while ( v4 >= 0 ); /*0x135e2d*/
    ++word_1E59F0; /*0x135e2f*/
  }
  v11[0] = *(_DWORD *)a1; /*0x135e38*/
  v11[1] = *(_DWORD *)(a1 + 4); /*0x135e3e*/
  v11[2] = *(_DWORD *)(a1 + 8); /*0x135e44*/
  v11[3] = *(_DWORD *)(a1 + 12); /*0x135e4a*/
  HIWORD(v11[0]) = __ROR2__(111, 8); /*0x135e56*/
  v6 = clntkudp_create((int)v11, 0x2000186A0LL, 4, (int)&word_1E59F0); /*0x135e6c*/
  v7 = (_DWORD *)v6; /*0x135e71*/
  if ( v6 ) /*0x135e78*/
  {
    v12[0] = a2; /*0x135e81*/
    v12[1] = a3; /*0x135e87*/
    v12[2] = a4; /*0x135e8d*/
    v12[3] = 0; /*0x135e90*/
    if ( (**(int (__cdecl ***)(int, int, int (__cdecl *)(XDR *, pmap *), _DWORD *, int (__cdecl *)(XDR *, unsigned __int16 *), __int16 *, int, int))(v6 + 4))( /*0x135ebe*/
           v6,
           3,
           xdr_pmap,
           v12,
           xdr_u_short,
           &v10,
           dword_1DD0D8,
           dword_1DD0DC) )
    {
      v9 = 1; /*0x135ec7*/
    }
    else if ( v10 ) /*0x135ed7*/
    {
      *(_WORD *)(a1 + 2) = __ROR2__(v10, 8); /*0x135ee8*/
    }
    else
    {
      v9 = -1; /*0x135ed9*/
    }
    (*(void (__stdcall **)(_DWORD))(*(_DWORD *)(*v7 + 32) + 16))(*v7); /*0x135ef5*/
    (*(void (__stdcall **)(_DWORD *))(v7[1] + 16))(v7); /*0x135efe*/
  }
  return v9; /*0x135f06*/
}
