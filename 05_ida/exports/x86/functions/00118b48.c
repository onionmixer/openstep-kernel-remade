/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x118b48. */
void unp_gc()
{
  int *i; // ebx
  int j; // ebx
  __int16 v2; // dx
  int v3; // eax
  int v4; // eax
  int v5; // edx
  int k; // ebx
  __int16 v7; // ax

  if ( !unp_gcing ) /*0x118b53*/
  {
    unp_gcing = 1; /*0x118b59*/
LABEL_3:
    unp_defer = 0; /*0x118b63*/
    for ( i = (int *)file_list; i != &file_list; i = (int *)*i ) /*0x118b79*/
      i[2] &= 0xFFFFFFCF; /*0x118b7c*/
    do /*0x118c2e*/
    {
      for ( j = file_list; (int *)j != &file_list; j = *(_DWORD *)j ) /*0x118b98*/
      {
        v2 = *(_WORD *)(j + 14); /*0x118ba0*/
        if ( v2 ) /*0x118ba7*/
        {
          v3 = *(_DWORD *)(j + 8); /*0x118ba9*/
          if ( (v3 & 0x20) != 0 ) /*0x118bae*/
          {
            LOBYTE(v3) = v3 & 0xDF; /*0x118bb0*/
            *(_DWORD *)(j + 8) = v3; /*0x118bb2*/
            --unp_defer; /*0x118bb5*/
          }
          else
          {
            if ( (v3 & 0x10) != 0 || *(_WORD *)(j + 16) == v2 ) /*0x118bc8*/
              continue; /*0x118bc8*/
            LOBYTE(v3) = v3 | 0x10; /*0x118bca*/
            *(_DWORD *)(j + 8) = v3; /*0x118bcc*/
          }
          if ( *(_WORD *)(j + 12) == 2 ) /*0x118bd4*/
          {
            v4 = *(_DWORD *)(j + 24); /*0x118bd6*/
            if ( v4 ) /*0x118bdb*/
            {
              v5 = *(_DWORD *)(v4 + 12); /*0x118bdd*/
              if ( *(_UNKNOWN **)(v5 + 4) == &unixdomain && (*(_BYTE *)(v5 + 10) & 0x10) != 0 ) /*0x118bed*/
              {
                if ( (*(_BYTE *)(v4 + 56) & 1) != 0 ) /*0x118bf3*/
                {
                  sbwait(v4 + 36); /*0x118bf9*/
                  goto LABEL_3; /*0x118c01*/
                }
                unp_scan(*(_DWORD *)(v4 + 48), unp_mark); /*0x118c11*/
              }
            }
          }
        }
      }
    }
    while ( unp_defer ); /*0x118c2e*/
    for ( k = file_list; (int *)k != &file_list; k = *(_DWORD *)k ) /*0x118c40*/
    {
      v7 = *(_WORD *)(k + 14); /*0x118c44*/
      if ( *(_WORD *)(k + 16) == v7 && (*(_BYTE *)(k + 8) & 0x10) == 0 ) /*0x118c52*/
      {
        if ( v7 ) /*0x118c57*/
        {
          do /*0x118c65*/
            unp_discard(k); /*0x118c5d*/
          while ( *(_WORD *)(k + 16) ); /*0x118c65*/
        }
        k = file_list; /*0x118c6c*/
      }
    }
    unp_gcing = 0; /*0x118c7c*/
  }
}
