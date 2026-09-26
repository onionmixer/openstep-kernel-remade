/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x16b84c. */
__int32 __cdecl zfree(int a1, _DWORD *a2)
{
  int v2; // edx
  _DWORD *i; // ebx
  _DWORD *v4; // eax
  _DWORD *j; // edx
  int v7; // eax

  if ( (*(_BYTE *)(a1 + 44) & 1) != 0 ) /*0x16b85c*/
  {
    lock_write(a1 + 48); /*0x16b862*/
  }
  else
  {
    v2 = splhigh(); /*0x16b871*/
    do /*0x16b886*/
    {
      while ( *(_DWORD *)a1 ) /*0x16b874*/
        ; /*0x16b876*/
    }
    while ( _InterlockedExchange((volatile __int32 *)a1, 1) == 1 ); /*0x16b886*/
    *(_DWORD *)(a1 + 4) = v2; /*0x16b888*/
  }
  if ( zone_check ) /*0x16b892*/
  {
    for ( i = *(_DWORD **)(a1 + 16); i; i = (_DWORD *)*i ) /*0x16b899*/
    {
      if ( i == a2 ) /*0x16b89e*/
        panic(aZfree); /*0x16b8a5*/
    }
  }
  v4 = *(_DWORD **)(a1 + 12); /*0x16b8b3*/
  if ( v4 && a2 > v4 ) /*0x16b8bc*/
    goto LABEL_16; /*0x16b8bc*/
  for ( j = (_DWORD *)(a1 + 16); ; j = v4 ) /*0x16b8be*/
  {
    v4 = (_DWORD *)*j; /*0x16b8ca*/
    if ( !*j || a2 <= v4 ) /*0x16b8c6*/
      break; /*0x16b8c6*/
LABEL_16:
    ; /*0x16b8c8*/
  }
  *a2 = v4; /*0x16b8d0*/
  *j = a2; /*0x16b8d2*/
  *(_DWORD *)(a1 + 12) = a2; /*0x16b8d4*/
  --*(_DWORD *)(a1 + 8); /*0x16b8d7*/
  if ( (*(_BYTE *)(a1 + 44) & 1) != 0 ) /*0x16b8de*/
    return lock_done(a1 + 48); /*0x16b8e4*/
  v7 = *(_DWORD *)(a1 + 4); /*0x16b8ec*/
  _InterlockedExchange((volatile __int32 *)a1, 0); /*0x16b8f1*/
  return splx(v7); /*0x16b8fc*/
}
