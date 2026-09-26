/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x113060. */
int __cdecl ndflush(int *a1, int a2)
{
  int v3; // ecx
  int v4; // edx
  int v5; // eax
  int v6; // eax
  int v7; // eax
  int v9; // [esp+Ch] [ebp-4h]

  v9 = spltty(); /*0x113074*/
  if ( *a1 > 0 ) /*0x11307a*/
  {
    while ( a2 > 0 ) /*0x113082*/
    {
      if ( !*a1 ) /*0x11308b*/
        goto LABEL_14; /*0x11308b*/
      v3 = a1[1]; /*0x113091*/
      LOBYTE(v3) = v3 & 0xC0; /*0x113094*/
      v4 = a1[2]; /*0x113097*/
      v5 = v4 - 1; /*0x11309a*/
      LOBYTE(v5) = (v4 - 1) & 0xC0; /*0x11309d*/
      if ( v3 == v5 ) /*0x1130a1*/
        v6 = a1[2]; /*0x1130a3*/
      else
        v6 = v3 + 64; /*0x1130a8*/
      v7 = v6 - a1[1]; /*0x1130ab*/
      if ( a2 < v7 ) /*0x1130b0*/
      {
        *a1 -= a2; /*0x1130f4*/
        a1[1] += a2; /*0x1130f6*/
        if ( *a1 > 0 ) /*0x1130fc*/
          return splx(v9); /*0x1130fc*/
        *(_DWORD *)v3 = cfreelist; /*0x113104*/
        cfreelist = v3; /*0x113106*/
        cfreecount += 52; /*0x11310c*/
        if ( cwaiting ) /*0x11311a*/
        {
          wakeup((int)&cwaiting); /*0x113121*/
          cwaiting = 0; /*0x113126*/
        }
        break; /*0x113126*/
      }
      a2 -= v7; /*0x1130b2*/
      *a1 -= v7; /*0x1130b4*/
      a1[1] = *(_DWORD *)v3 + 12; /*0x1130bb*/
      *(_DWORD *)v3 = cfreelist; /*0x1130c4*/
      cfreelist = v3; /*0x1130c6*/
      cfreecount += 52; /*0x1130cc*/
      if ( cwaiting ) /*0x1130da*/
      {
        wakeup((int)&cwaiting); /*0x1130e1*/
        cwaiting = 0; /*0x1130e6*/
      }
    }
    if ( *a1 > 0 ) /*0x113133*/
      return splx(v9); /*0x113133*/
LABEL_14:
    a1[2] = 0; /*0x113135*/
    a1[1] = 0; /*0x11313c*/
    *a1 = 0; /*0x113143*/
  }
  return splx(v9); /*0x113155*/
}
