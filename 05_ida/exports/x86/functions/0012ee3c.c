/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x12ee3c. */
char *__cdecl sub_12EE3C(_DWORD *a1)
{
  _DWORD *v1; // ecx
  __int16 *v2; // edx
  unsigned int v3; // eax
  char *v4; // edx
  char *result; // eax

  v1 = (_DWORD *)*a1; /*0x12ee44*/
  if ( *(_DWORD *)*a1 > 1u )
  {
    printf("authfree: unknown authflavor %d\n", *v1);
  }
  else
  {
    v2 = unixauthtab; /*0x12ee51*/
    v3 = 8 * MAXCLIENTS + 2027840; /*0x12ee63*/
    if ( (unsigned int)unixauthtab >= v3 ) /*0x12ee6a*/
    {
LABEL_5:
      (*(void (__cdecl **)(_DWORD))(v1[8] + 16))(*a1); /*0x12ee78*/
    }
    else
    {
      while ( *((_DWORD **)v2 + 1) != v1 ) /*0x12ee6f*/
      {
        v2 += 4; /*0x12ee71*/
        if ( (unsigned int)v2 >= v3 ) /*0x12ee76*/
          goto LABEL_5; /*0x12ee76*/
      }
      *v2 = 0; /*0x12ee88*/
    }
  }
  clntkudp_freecred(a1); /*0x12eead*/
  *a1 = 0; /*0x12eeb2*/
  v4 = (char *)&chtable; /*0x12eeb8*/
  result = (char *)&chtable + 12 * MAXCLIENTS; /*0x12eec8*/
  if ( &chtable >= (_UNKNOWN *)result ) /*0x12eed1*/
    return (char *)(*(int (__stdcall **)(_DWORD *))(a1[1] + 16))(a1); /*0x12eee0*/
  while ( *((_DWORD **)v4 + 2) != a1 ) /*0x12eed7*/
  {
    v4 += 12; /*0x12eed9*/
    if ( v4 >= result ) /*0x12eede*/
      return (char *)(*(int (__stdcall **)(_DWORD *))(a1[1] + 16))(a1); /*0x12eede*/
  }
  *((_DWORD *)v4 + 1) = 0; /*0x12ee90*/
  return result; /*0x12eeec*/
}
