/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x16d090. */
int __cdecl kern_serv_callout(int *a1, void (__cdecl *a2)(int), void (__cdecl *a3)(int))
{
  int v3; // ebx
  int v4; // ecx
  int v5; // eax
  void (__cdecl **v7)(int); // edx
  int v8; // eax
  int v9; // ecx
  int v10; // [esp+Ch] [ebp-4h]

  v3 = *a1; /*0x16d09f*/
  if ( curipl() || *(_DWORD *)(v3 + 8) != task_self() ) /*0x16d0b2*/
  {
    v10 = splhigh(); /*0x16d0c5*/
    do /*0x16d0da*/
    {
      while ( *(_DWORD *)v3 ) /*0x16d0c8*/
        ; /*0x16d0ca*/
    }
    while ( _InterlockedExchange((volatile __int32 *)v3, 1) == 1 ); /*0x16d0da*/
    v4 = v3 + 60; /*0x16d0dc*/
    v5 = *(_DWORD *)(v3 + 60); /*0x16d0df*/
    if ( v3 + 60 == v5 ) /*0x16d0e4*/
    {
      _InterlockedExchange((volatile __int32 *)v3, 0); /*0x16d0e8*/
      splx(v10); /*0x16d0ee*/
      return 6; /*0x16d0f8*/
    }
    v7 = *(void (__cdecl ***)(int))(v3 + 60); /*0x16d0fc*/
    v8 = *(_DWORD *)(v5 + 8); /*0x16d0fe*/
    if ( v4 == v8 ) /*0x16d103*/
      *(_DWORD *)(v3 + 64) = v8; /*0x16d105*/
    else
      *(_DWORD *)(v8 + 12) = v4; /*0x16d10c*/
    *(_DWORD *)(v3 + 60) = v8; /*0x16d10f*/
    *v7 = a2; /*0x16d115*/
    v7[1] = a3; /*0x16d117*/
    v9 = *(_DWORD *)(v3 + 56); /*0x16d11a*/
    if ( v3 + 52 == v9 ) /*0x16d122*/
      *(_DWORD *)(v3 + 52) = v7; /*0x16d124*/
    else
      *(_DWORD *)(v9 + 8) = v7; /*0x16d12c*/
    v7[3] = (void (__cdecl *)(int))v9; /*0x16d12f*/
    v7[2] = (void (__cdecl *)(int))(v3 + 52); /*0x16d135*/
    *(_DWORD *)(v3 + 56) = v7; /*0x16d138*/
    _InterlockedExchange((volatile __int32 *)v3, 0); /*0x16d13d*/
    splx(v10); /*0x16d143*/
    calloutDispatchUnique(sub_16D164, *(_DWORD *)(v3 + 12)); /*0x16d151*/
  }
  else
  {
    a2((int)a3); /*0x16d0b8*/
  }
  return 0; /*0x16d15b*/
}
