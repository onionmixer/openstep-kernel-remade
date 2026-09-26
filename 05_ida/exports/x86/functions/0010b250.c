/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x10b250. */
void __cdecl realitexpire(_DWORD *a1)
{
  int v1; // eax
  int v2; // ebx
  int v3; // ecx
  int v4; // ecx
  int v5; // [esp+Ch] [ebp-8h]
  int v6; // [esp+10h] [ebp-4h]

  psignal((unsigned int)a1, (const char *)0xE); /*0x10b25f*/
  if ( a1[21] || a1[22] ) /*0x10b26d*/
  {
    while ( *(_DWORD *)mtime != *((_DWORD *)mtime + 2) ) /*0x10b29e*/
      ; /*0x10b290*/
    v5 = *((_DWORD *)mtime + 2); /*0x10b2a0*/
    v6 = *((_DWORD *)mtime + 1); /*0x10b2a3*/
    v1 = splclock(mtime); /*0x10b2a6*/
    v2 = v1; /*0x10b2ab*/
    if ( a1[23] >= v5 - 10 ) /*0x10b2b6*/
    {
      splx(v1); /*0x10b2cd*/
      while ( 1 ) /*0x10b2dd*/
      {
        v2 = splclock(v3); /*0x10b2dd*/
        timevaladd(a1 + 23, a1 + 21); /*0x10b2e4*/
        v4 = a1[23]; /*0x10b2e9*/
        if ( v4 > v5 || v4 == v5 && a1[24] > v6 ) /*0x10b2fe*/
          break; /*0x10b2fe*/
        splx(v2); /*0x10b31d*/
      }
      hzto(a1 + 23); /*0x10b301*/
    }
    else
    {
      a1[23] = v5; /*0x10b2be*/
      a1[24] = v6; /*0x10b2c1*/
      hzto(a1 + 23); /*0x10b2c8*/
    }
    timeout((int)realitexpire); /*0x10b30d*/
    splx(v2); /*0x10b313*/
  }
  else
  {
    a1[24] = 0; /*0x10b273*/
    a1[23] = 0; /*0x10b27a*/
  }
}
