/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x11b158. */
int __cdecl btrash(int a1)
{
  int v1; // ebx
  int *v2; // eax
  int *v3; // edx
  int v4; // eax

  while ( 1 ) /*0x11b165*/
  {
    v1 = splhigh(); /*0x11b165*/
    v2 = &bfreelist; /*0x11b167*/
    if ( &bfreelist >= &dword_1E882C ) /*0x11b171*/
      return splx(v1); /*0x11b1be*/
    while ( 1 ) /*0x11b174*/
    {
      v3 = (int *)v2[3]; /*0x11b174*/
      if ( v3 != v2 ) /*0x11b179*/
        break; /*0x11b179*/
LABEL_7:
      v2 += 17; /*0x11b1ab*/
      if ( v2 >= &dword_1E882C ) /*0x11b1b3*/
        return splx(v1); /*0x11b1b3*/
    }
    while ( v3[16] != a1 && a1 ) /*0x11b183*/
    {
      v3 = (int *)v3[3]; /*0x11b1a4*/
      if ( v3 == v2 ) /*0x11b1a9*/
        goto LABEL_7; /*0x11b1a9*/
    }
    v4 = *v3; /*0x11b185*/
    BYTE1(v4) = BYTE1(*v3) & 0xFD; /*0x11b187*/
    *v3 = v4 | 0x10000; /*0x11b18f*/
    sub_11B26C((int)v3); /*0x11b192*/
    splx(v1); /*0x11b198*/
  }
}
