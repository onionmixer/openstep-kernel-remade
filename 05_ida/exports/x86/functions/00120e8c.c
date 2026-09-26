/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x120e8c. */
int __cdecl if_attach(
        int a1,
        int a2,
        int a3,
        int a4,
        int a5,
        int a6,
        __int16 a7,
        int a8,
        __int16 a9,
        __int16 a10,
        unsigned int a11,
        int a12)
{
  int v12; // ebx
  int v13; // esi
  int *v14; // edx
  int v15; // eax
  int i; // ebx
  int (__stdcall *v17)(int, const char *, __int16 *); // eax
  __int16 v19; // [esp+Ch] [ebp-8h] BYREF
  unsigned int v20; // [esp+Eh] [ebp-6h]

  v12 = 0; /*0x120e98*/
  v13 = ifnet; /*0x120e9a*/
  if ( ifnet ) /*0x120ea2*/
  {
    while ( *(char **)v13 != "null" || *(_DWORD *)(v13 + 20) != a11 ) /*0x120eaf*/
    {
      v13 = *(_DWORD *)(v13 + 92); /*0x120eb5*/
      if ( !v13 ) /*0x120eba*/
        goto LABEL_5; /*0x120eba*/
    }
    v12 = 1; /*0x120fbc*/
  }
LABEL_5:
  if ( !v12 ) /*0x120ebe*/
  {
    v13 = kalloc(0x60u); /*0x120ec7*/
    bzero((void *)v13, 0x60u); /*0x120ecc*/
  }
  *(_DWORD *)v13 = a6; /*0x120ed7*/
  *(_DWORD *)(v13 + 4) = a8; /*0x120edc*/
  *(_WORD *)(v13 + 8) = a7; /*0x120ee3*/
  *(_WORD *)(v13 + 10) = a9; /*0x120eeb*/
  *(_WORD *)(v13 + 12) = a10; /*0x120ef3*/
  *(_DWORD *)(v13 + 16) = 0; /*0x120ef7*/
  *(_DWORD *)(v13 + 24) = 0; /*0x120efe*/
  *(_DWORD *)(v13 + 40) = ifqmaxlen; /*0x120f0b*/
  *(_DWORD *)(v13 + 48) = a1; /*0x120f11*/
  *(_DWORD *)(v13 + 52) = a3; /*0x120f17*/
  *(_DWORD *)(v13 + 56) = a5; /*0x120f1d*/
  *(_DWORD *)(v13 + 60) = a2; /*0x120f23*/
  *(_DWORD *)(v13 + 64) = a4; /*0x120f29*/
  *(_DWORD *)(v13 + 88) = a12; /*0x120f2f*/
  *(_DWORD *)(v13 + 20) = a11; /*0x120f32*/
  *(_DWORD *)(v13 + 68) = 0; /*0x120f35*/
  *(_DWORD *)(v13 + 72) = 0; /*0x120f3c*/
  *(_DWORD *)(v13 + 76) = 0; /*0x120f43*/
  *(_DWORD *)(v13 + 80) = 0; /*0x120f4a*/
  *(_DWORD *)(v13 + 84) = 0; /*0x120f51*/
  if ( !v12 ) /*0x120f5a*/
  {
    v14 = &ifnet; /*0x120f5c*/
    if ( ifnet ) /*0x120f68*/
    {
      do /*0x120f76*/
      {
        v15 = *v14; /*0x120f6c*/
        if ( *(_DWORD *)(*v14 + 20) < a11 ) /*0x120f71*/
          break; /*0x120f71*/
        v14 = (int *)(v15 + 92); /*0x120f73*/
      }
      while ( *(_DWORD *)(v15 + 92) ); /*0x120f76*/
    }
    *(_DWORD *)(v13 + 92) = *v14; /*0x120f7e*/
    *v14 = v13; /*0x120f81*/
  }
  if ( !*(_DWORD *)(v13 + 20) ) /*0x120f83*/
  {
    for ( i = dword_1E58D8; i; i = *(_DWORD *)(i + 8) ) /*0x120f91*/
      (*(void (__cdecl **)(_DWORD, int))i)(*(_DWORD *)(i + 4), v13); /*0x120f9b*/
    if ( !hostid ) /*0x120fae*/
    {
      v17 = *(int (__stdcall **)(int, const char *, __int16 *))(v13 + 56); /*0x120fb3*/
      if ( v17 ) /*0x120fb8*/
      {
        if ( !v17(v13, "getaddr", &v19) ) /*0x120fcb*/
        {
          LOWORD(v20) = v19 ^ v20; /*0x120fd4*/
          hostid = _byteswap_ulong(v20); /*0x120fe2*/
        }
      }
    }
  }
  return v13; /*0x120fec*/
}
