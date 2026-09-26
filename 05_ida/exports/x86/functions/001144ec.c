/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1144ec. */
void __cdecl m_adj(int *a1, int a2)
{
  int v2; // ebx
  int *v3; // edx
  __int16 v4; // cx
  int v5; // ecx
  __int16 v6; // si
  int v7; // ecx
  int *v8; // edx
  int v9; // eax

  v2 = a2; /*0x1144f5*/
  v3 = a1; /*0x1144f8*/
  if ( a1 ) /*0x1144fc*/
  {
    if ( a2 < 0 ) /*0x114504*/
    {
      v5 = *((__int16 *)a1 + 4); /*0x11452e*/
      if ( *a1 ) /*0x114532*/
      {
        do /*0x114540*/
        {
          v3 = (int *)*v3; /*0x114538*/
          v5 += *((__int16 *)v3 + 4); /*0x11453e*/
        }
        while ( *v3 ); /*0x114540*/
      }
      v6 = *((_WORD *)v3 + 4); /*0x114545*/
      if ( v6 < -a2 ) /*0x11454e*/
      {
        v7 = v5 + a2; /*0x114570*/
        v8 = a1; /*0x114572*/
        while ( 1 ) /*0x114578*/
        {
          v9 = *((__int16 *)v8 + 4); /*0x114578*/
          if ( v9 >= v7 ) /*0x11457e*/
            break; /*0x11457e*/
          v7 -= v9; /*0x114580*/
          v8 = (int *)*v8; /*0x114582*/
          if ( !v8 ) /*0x114586*/
            goto LABEL_18; /*0x114586*/
        }
        *((_WORD *)v8 + 4) = v7; /*0x114568*/
LABEL_18:
        while ( 1 ) /*0x114592*/
        {
          v8 = (int *)*v8; /*0x114592*/
          if ( !v8 ) /*0x114596*/
            break; /*0x114596*/
          *((_WORD *)v8 + 4) = 0; /*0x11458c*/
        }
      }
      else
      {
        *((_WORD *)v3 + 4) = v6 + a2; /*0x114553*/
      }
    }
    else
    {
      while ( v2 > 0 ) /*0x11450a*/
      {
        v4 = *((_WORD *)v3 + 4); /*0x114510*/
        if ( v4 > v2 ) /*0x114519*/
        {
          *((_WORD *)v3 + 4) = v4 - v2; /*0x11455f*/
          v3[1] += v2; /*0x114563*/
          return; /*0x114566*/
        }
        v2 -= v4; /*0x11451b*/
        *((_WORD *)v3 + 4) = 0; /*0x11451d*/
        v3 = (int *)*v3; /*0x114523*/
        if ( !v3 ) /*0x114527*/
          return; /*0x114527*/
      }
    }
  }
}
