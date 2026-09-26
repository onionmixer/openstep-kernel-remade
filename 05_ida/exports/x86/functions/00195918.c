/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x195918. */
__int32 kmEnableAnimation()
{
  int v0; // ecx
  int v1; // edx
  __int32 result; // eax

  if ( !dword_1E7778 ) /*0x195922*/
  {
    dword_1E7774 = 0; /*0x195924*/
    dword_1E7778 = 1; /*0x19592e*/
  }
  if ( MEMORY[0x1114C] ) /*0x19593f*/
  {
    do /*0x195961*/
    {
      while ( dword_1E7774 ) /*0x19594f*/
        ; /*0x19594d*/
    }
    while ( _InterlockedExchange(&dword_1E7774, 1) == 1 ); /*0x195961*/
    dword_1E38E8 = 1; /*0x195963*/
    _InterlockedExchange(&dword_1E7774, 0); /*0x19596f*/
    do /*0x195991*/
    {
      while ( dword_1E7774 ) /*0x19597f*/
        ; /*0x19597d*/
    }
    while ( _InterlockedExchange(&dword_1E7774, 1) == 1 ); /*0x195991*/
    if ( kmId ) /*0x19599a*/
    {
      v0 = *((_DWORD *)kmId + 67); /*0x1959b8*/
      v1 = *((_DWORD *)kmId + 69); /*0x1959be*/
    }
    else
    {
      v0 = basicConsole; /*0x19599c*/
      v1 = 1; /*0x1959a2*/
      if ( MEMORY[0x1114C] ) /*0x1959ae*/
        v1 = 2; /*0x1959b0*/
    }
    if ( dword_1E38E8 > 0 ) /*0x1959cb*/
    {
      if ( v1 == 2 ) /*0x1959d0*/
      {
        if ( v0 ) /*0x1959de*/
          (*(void (__cdecl **)(int, char *))(v0 + 12))(v0, &byte_1E384C[12 * dword_1E38E8]); /*0x1959ef*/
        if ( ++dword_1E38E8 > 3 ) /*0x195a01*/
          dword_1E38E8 = 1; /*0x195a03*/
        ns_timeout((int)sub_19585C, 0, 111111111); /*0x195a1d*/
      }
      else
      {
        dword_1E38E8 = -dword_1E38E8; /*0x1959d4*/
      }
    }
    return _InterlockedExchange(&dword_1E7774, 0); /*0x195a24*/
  }
  return result; /*0x195a2c*/
}
