/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x10d894. */
int __cdecl soo_ioctl(int a1, int a2, _DWORD *a3)
{
  int v3; // edx
  int v5; // edx

  v3 = *(_DWORD *)(a1 + 24); /*0x10d8a2*/
  if ( a2 == 536900607 ) /*0x10d8ab*/
  {
    *(_BYTE *)(v3 + 6) |= 0x80u; /*0x10d8f8*/
    return 0; /*0x10d8f8*/
  }
  if ( a2 > 536900607 ) /*0x10d8ad*/
  {
    if ( a2 == 1074033415 ) /*0x10d8de*/
    {
      *a3 = (*(_WORD *)(v3 + 6) & 0x40) != 0; /*0x10d95d*/
      return 0; /*0x10d95f*/
    }
    if ( a2 > 1074033415 ) /*0x10d8e0*/
    {
      if ( a2 != 1074033417 ) /*0x10d8f2*/
        goto LABEL_28; /*0x10d8f2*/
      v5 = *(__int16 *)(v3 + 90); /*0x10d948*/
    }
    else
    {
      if ( a2 != 1074030207 ) /*0x10d8e8*/
        goto LABEL_28; /*0x10d8e8*/
      v5 = *(unsigned __int16 *)(v3 + 36); /*0x10d934*/
    }
    *a3 = v5; /*0x10d94c*/
    return 0; /*0x10d94e*/
  }
  if ( a2 == -2147195266 ) /*0x10d8b5*/
  {
    if ( *a3 ) /*0x10d904*/
      *(_WORD *)(v3 + 6) |= 0x100u; /*0x10d909*/
    else
      *(_WORD *)(v3 + 6) &= ~0x100u; /*0x10d914*/
    return 0; /*0x10d90f*/
  }
  if ( a2 <= -2147195266 ) /*0x10d8b7*/
  {
    if ( a2 != -2147195267 ) /*0x10d8bf*/
      goto LABEL_28; /*0x10d8bf*/
    if ( *a3 ) /*0x10d91c*/
      *(_WORD *)(v3 + 6) |= 0x200u; /*0x10d921*/
    else
      *(_WORD *)(v3 + 6) &= ~0x200u; /*0x10d92c*/
    return 0; /*0x10d8fe*/
  }
  if ( a2 == -2147192056 ) /*0x10d8ce*/
  {
    *(_WORD *)(v3 + 90) = *(_WORD *)a3; /*0x10d93f*/
    return 0; /*0x10d943*/
  }
LABEL_28:
  if ( BYTE1(a2) == 105 ) /*0x10d971*/
    return ifioctl(v3, a2, a3); /*0x10d976*/
  if ( BYTE1(a2) == 114 ) /*0x10d983*/
    return rtioctl(a2, a3); /*0x10d987*/
  return (*(int (__stdcall **)(int, int, int, _DWORD *, _DWORD))(*(_DWORD *)(v3 + 12) + 28))(v3, 11, a2, a3, 0); /*0x10d9a2*/
}
