/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x10a384. */
int __cdecl uiomove(int a1, int a2, int a3, _DWORD *a4)
{
  int result; // eax
  _DWORD *v5; // esi
  unsigned int v6; // ebx
  int v7; // edx

  result = 0; /*0x10a38d*/
  while ( a2 > 0 && a4[5] ) /*0x10a39d*/
  {
    v5 = (_DWORD *)*a4; /*0x10a3a3*/
    v6 = *(_DWORD *)(*a4 + 4); /*0x10a3a5*/
    if ( v6 ) /*0x10a3aa*/
    {
      if ( a2 < v6 ) /*0x10a3bb*/
        v6 = a2; /*0x10a3bd*/
      v7 = a4[3]; /*0x10a3c0*/
      if ( v7 == 1 ) /*0x10a3c6*/
      {
        if ( a3 ) /*0x10a408*/
          result = copywithin(*v5, a1, v6); /*0x10a41c*/
        else
          result = copywithin(a1, *v5, v6); /*0x10a411*/
      }
      else
      {
        if ( v7 > 1 ) /*0x10a3c8*/
        {
          if ( v7 != 2 ) /*0x10a3d3*/
            goto LABEL_21; /*0x10a3d3*/
        }
        else if ( v7 ) /*0x10a3cc*/
        {
          goto LABEL_21; /*0x10a3cc*/
        }
        if ( a3 ) /*0x10a3d9*/
          result = copyin(*v5, a1, v6); /*0x10a3f4*/
        else
          result = copyout(a1, *v5, v6); /*0x10a3e3*/
        if ( result ) /*0x10a3fe*/
          return result; /*0x10a3fe*/
      }
LABEL_21:
      *v5 += v6; /*0x10a424*/
      v5[1] -= v6; /*0x10a426*/
      a4[5] -= v6; /*0x10a429*/
      a4[2] += v6; /*0x10a42c*/
      a1 += v6; /*0x10a42f*/
      a2 -= v6; /*0x10a432*/
    }
    else
    {
      *a4 = v5 + 2; /*0x10a3af*/
      --a4[1]; /*0x10a3b1*/
    }
  }
  return result; /*0x10a43f*/
}
