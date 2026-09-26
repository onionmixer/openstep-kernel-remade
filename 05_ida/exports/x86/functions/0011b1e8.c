/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x11b1e8. */
void __cdecl binval(int a1)
{
  int *v1; // ecx
  int *v2; // eax

  while ( 1 ) /*0x11b1ef*/
  {
    v1 = (int *)&bufhash; /*0x11b1ef*/
    if ( &bufhash >= (_UNKNOWN *)&cnt ) /*0x11b1fa*/
      break; /*0x11b1fa*/
    while ( 1 ) /*0x11b1fc*/
    {
      v2 = (int *)v1[1]; /*0x11b1fc*/
      if ( v2 != v1 ) /*0x11b201*/
        break; /*0x11b201*/
LABEL_7:
      v1 += 3; /*0x11b22f*/
      if ( v1 >= &cnt ) /*0x11b238*/
        return; /*0x11b238*/
    }
    while ( v2[16] != a1 || (*v2 & 0x10000) != 0 ) /*0x11b211*/
    {
      v2 = (int *)v2[1]; /*0x11b228*/
      if ( v2 == v1 ) /*0x11b22d*/
        goto LABEL_7; /*0x11b22d*/
    }
    *v2 |= 0x10000u; /*0x11b219*/
    sub_11B26C((int)v2); /*0x11b21c*/
  }
}
