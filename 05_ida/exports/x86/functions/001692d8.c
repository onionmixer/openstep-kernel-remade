/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1692d8. */
void __cdecl calloutDispatchUnique(int a1, int a2)
{
  int v2; // edi
  int *v3; // edx
  int *v4; // eax

  if ( dword_1DFCBC ) /*0x1692eb*/
  {
    v2 = splsched(); /*0x1692f6*/
    do /*0x169311*/
    {
      while ( dword_1E7244 ) /*0x1692ff*/
        ; /*0x1692fd*/
    }
    while ( _InterlockedExchange(&dword_1E7244, 1) == 1 ); /*0x169311*/
    v3 = (int *)dword_1E7250; /*0x169313*/
    if ( (int *)dword_1E7250 == &dword_1E7250 ) /*0x16931f*/
      goto LABEL_10; /*0x16931f*/
    do /*0x169336*/
    {
      if ( v3[2] == a1 && v3[3] == a2 ) /*0x16932c*/
        break; /*0x16932c*/
      v3 = (int *)*v3; /*0x16932e*/
    }
    while ( v3 != &dword_1E7250 ); /*0x169336*/
    if ( v3 == &dword_1E7250 ) /*0x16933e*/
    {
LABEL_10:
      if ( (int *)dword_1E7248 == &dword_1E7248 ) /*0x16934e*/
        panic(aInternalentrya); /*0x169355*/
      v4 = (int *)dword_1E7248; /*0x169370*/
      *(_DWORD *)(*(_DWORD *)dword_1E7248 + 4) = &dword_1E7248; /*0x169377*/
      dword_1E7248 = *v4; /*0x169380*/
      v4[2] = a1; /*0x169388*/
      v4[3] = a2; /*0x16938b*/
      v4[4] = 0; /*0x16938e*/
      v4[5] = 0; /*0x169395*/
      v4[6] = 0; /*0x16939c*/
      *v4 = (int)&dword_1E7250; /*0x1693a3*/
      v4[1] = dword_1E7254; /*0x1693af*/
      *(_DWORD *)v4[1] = v4; /*0x1693b5*/
      dword_1E7254 = (int)v4; /*0x1693b7*/
      ++dword_1E7260; /*0x1693bd*/
      v4[7] = 1; /*0x1693c3*/
      sub_169C64(); /*0x1693ca*/
    }
    else
    {
      _InterlockedExchange(&dword_1E7244, 0); /*0x1693d6*/
    }
    splx(v2); /*0x1693dd*/
  }
}
