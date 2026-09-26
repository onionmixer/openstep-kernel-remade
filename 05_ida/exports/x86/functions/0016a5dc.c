/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x16a5dc. */
__int32 __cdecl zcram(int a1, _DWORD *a2, unsigned int a3)
{
  _DWORD *v3; // esi
  unsigned int v4; // edi
  int v5; // edx
  _DWORD *v6; // eax
  _DWORD *v7; // edx
  int v9; // eax

  v3 = a2; /*0x16a5e5*/
  if ( !a2 ) /*0x16a5ea*/
    panic(aZcramMemoryAtZ); /*0x16a5f1*/
  v4 = *(_DWORD *)(a1 + 28); /*0x16a5f9*/
  if ( (*(_BYTE *)(a1 + 44) & 1) != 0 ) /*0x16a600*/
  {
    lock_write(a1 + 48); /*0x16a606*/
  }
  else
  {
    v5 = splhigh(); /*0x16a615*/
    do /*0x16a62a*/
    {
      while ( *(_DWORD *)a1 ) /*0x16a618*/
        ; /*0x16a61a*/
    }
    while ( _InterlockedExchange((volatile __int32 *)a1, 1) == 1 ); /*0x16a62a*/
    *(_DWORD *)(a1 + 4) = v5; /*0x16a62c*/
  }
  while ( a3 >= v4 ) /*0x16a668*/
  {
    v6 = *(_DWORD **)(a1 + 12); /*0x16a634*/
    if ( !v6 || v3 <= v6 ) /*0x16a63d*/
    {
      v7 = (_DWORD *)(a1 + 16); /*0x16a63f*/
      goto LABEL_14; /*0x16a642*/
    }
    do /*0x16a646*/
    {
      v7 = v6; /*0x16a648*/
LABEL_14:
      v6 = (_DWORD *)*v7; /*0x16a64a*/
    }
    while ( *v7 && v3 > v6 ); /*0x16a646*/
    *v3 = v6; /*0x16a650*/
    *v7 = v3; /*0x16a652*/
    *(_DWORD *)(a1 + 12) = v3; /*0x16a654*/
    *(_DWORD *)(a1 + 8) = *(_DWORD *)(a1 + 8); /*0x16a65a*/
    a3 -= v4; /*0x16a65d*/
    v3 = (_DWORD *)((char *)v3 + v4); /*0x16a660*/
    *(_DWORD *)(a1 + 20) += v4; /*0x16a662*/
  }
  if ( (*(_BYTE *)(a1 + 44) & 1) != 0 ) /*0x16a66e*/
    return lock_done(a1 + 48); /*0x16a674*/
  v9 = *(_DWORD *)(a1 + 4); /*0x16a67c*/
  _InterlockedExchange((volatile __int32 *)a1, 0); /*0x16a681*/
  return splx(v9); /*0x16a68c*/
}
