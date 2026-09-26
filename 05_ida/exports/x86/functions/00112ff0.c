/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x112ff0. */
int __cdecl ndqb(int *a1, int a2)
{
  int v2; // edx
  int v3; // ebx
  int v4; // ecx
  int v5; // ebx
  char *v6; // edx
  unsigned int v7; // ecx
  int v9; // [esp+Ch] [ebp-4h]

  v9 = spltty(); /*0x113001*/
  v2 = *a1; /*0x113004*/
  if ( *a1 > 0 ) /*0x113008*/
  {
    v4 = a1[1]; /*0x113018*/
    v5 = v4 + 52; /*0x11301e*/
    LOBYTE(v5) = (v4 + 52) & 0xC0; /*0x113020*/
    v3 = v5 - v4; /*0x113023*/
    if ( v2 < v3 ) /*0x113027*/
      v3 = *a1; /*0x113029*/
    if ( a2 ) /*0x11302f*/
    {
      v6 = (char *)a1[1]; /*0x113031*/
      v7 = v3 + v4; /*0x113033*/
      if ( (unsigned int)v6 < v7 ) /*0x113038*/
      {
        while ( (*v6 & a2) == 0 ) /*0x113042*/
        {
          if ( (unsigned int)++v6 >= v7 ) /*0x113047*/
            goto LABEL_10; /*0x113047*/
        }
        v3 = (int)&v6[-a1[1]]; /*0x113012*/
      }
    }
  }
  else
  {
    v3 = -v2; /*0x11300c*/
  }
LABEL_10:
  splx(v9); /*0x113049*/
  return v3; /*0x113057*/
}
