/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x12f9f0. */
void __cdecl rinval(int a1)
{
  int *i; // edi
  int v2; // ebx
  int v3; // edx
  int v4; // eax
  int v5; // [esp+Ch] [ebp-4h]

  for ( i = rtable; i < (int *)unixauthtab; ++i ) /*0x12fa04*/
  {
    v2 = *i; /*0x12fa0c*/
    if ( *i ) /*0x12fa0c*/
    {
      do /*0x12fb76*/
      {
        v5 = *(_DWORD *)(v2 + 8); /*0x12fa1b*/
        if ( *(_DWORD *)(v2 + 48) == a1 ) /*0x12fa27*/
        {
          v3 = 0; /*0x12fa2d*/
          v4 = rtable[(*(_BYTE *)(v2 + 91) /*0x12fa62*/
                     ^ (unsigned __int8)(*(_BYTE *)(v2 + 90)
                                       ^ *(_BYTE *)(v2 + 89)
                                       ^ *(_BYTE *)(v2 + 88)
                                       ^ *(_BYTE *)(v2 + 87)
                                       ^ *(_BYTE *)(v2 + 86)
                                       ^ *(_BYTE *)(v2 + 85)
                                       ^ *(_BYTE *)(v2 + 84)
                                       ^ *(_BYTE *)(v2 + 81)
                                       ^ *(_BYTE *)(v2 + 80)
                                       ^ *(_BYTE *)(v2 + 79)
                                       ^ *(_BYTE *)(v2 + 78)
                                       ^ *(_BYTE *)(v2 + 77)
                                       ^ *(_BYTE *)(v2 + 76)
                                       ^ *(_BYTE *)(v2 + 75)
                                       ^ *(_BYTE *)(v2 + 74)))
                    & 0x3F];
          if ( v4 ) /*0x12fa6b*/
          {
            while ( v4 != v2 ) /*0x12fa72*/
            {
              v3 = v4; /*0x12fac8*/
              v4 = *(_DWORD *)(v4 + 8); /*0x12faca*/
              if ( !v4 ) /*0x12facf*/
                goto LABEL_11; /*0x12facf*/
            }
            if ( v3 ) /*0x12fa76*/
              *(_DWORD *)(v3 + 8) = *(_DWORD *)(v2 + 8); /*0x12fabb*/
            else
              rtable[(*(_BYTE *)(v2 + 91) /*0x12faae*/
                    ^ (unsigned __int8)(*(_BYTE *)(v2 + 90)
                                      ^ *(_BYTE *)(v2 + 89)
                                      ^ *(_BYTE *)(v2 + 88)
                                      ^ *(_BYTE *)(v2 + 87)
                                      ^ *(_BYTE *)(v2 + 86)
                                      ^ *(_BYTE *)(v2 + 85)
                                      ^ *(_BYTE *)(v2 + 84)
                                      ^ *(_BYTE *)(v2 + 81)
                                      ^ *(_BYTE *)(v2 + 80)
                                      ^ *(_BYTE *)(v2 + 79)
                                      ^ *(_BYTE *)(v2 + 78)
                                      ^ *(_BYTE *)(v2 + 77)
                                      ^ *(_BYTE *)(v2 + 76)
                                      ^ *(_BYTE *)(v2 + 75)
                                      ^ *(_BYTE *)(v2 + 74)))
                   & 0x3F] = *(_DWORD *)(v2 + 8);
            --rnhash; /*0x12fabe*/
          }
LABEL_11:
          ++*(_WORD *)(v2 + 18); /*0x12fad1*/
          binvalfree(v2 + 12); /*0x12fad6*/
          dnlc_purge_vp(v2 + 12); /*0x12fadc*/
          if ( *(_WORD *)(v2 + 18) > 1u ) /*0x12fae9*/
          {
            *(_DWORD *)(v2 + 8) = rtable[(*(_BYTE *)(v2 + 91) /*0x12fb25*/
                                        ^ (unsigned __int8)(*(_BYTE *)(v2 + 90)
                                                          ^ *(_BYTE *)(v2 + 89)
                                                          ^ *(_BYTE *)(v2 + 88)
                                                          ^ *(_BYTE *)(v2 + 87)
                                                          ^ *(_BYTE *)(v2 + 86)
                                                          ^ *(_BYTE *)(v2 + 85)
                                                          ^ *(_BYTE *)(v2 + 84)
                                                          ^ *(_BYTE *)(v2 + 81)
                                                          ^ *(_BYTE *)(v2 + 80)
                                                          ^ *(_BYTE *)(v2 + 79)
                                                          ^ *(_BYTE *)(v2 + 78)
                                                          ^ *(_BYTE *)(v2 + 77)
                                                          ^ *(_BYTE *)(v2 + 76)
                                                          ^ *(_BYTE *)(v2 + 75)
                                                          ^ *(_BYTE *)(v2 + 74)))
                                       & 0x3F];
            rtable[(*(_BYTE *)(v2 + 91) /*0x12fb5b*/
                  ^ (unsigned __int8)(*(_BYTE *)(v2 + 90)
                                    ^ *(_BYTE *)(v2 + 89)
                                    ^ *(_BYTE *)(v2 + 88)
                                    ^ *(_BYTE *)(v2 + 87)
                                    ^ *(_BYTE *)(v2 + 86)
                                    ^ *(_BYTE *)(v2 + 85)
                                    ^ *(_BYTE *)(v2 + 84)
                                    ^ *(_BYTE *)(v2 + 81)
                                    ^ *(_BYTE *)(v2 + 80)
                                    ^ *(_BYTE *)(v2 + 79)
                                    ^ *(_BYTE *)(v2 + 78)
                                    ^ *(_BYTE *)(v2 + 77)
                                    ^ *(_BYTE *)(v2 + 76)
                                    ^ *(_BYTE *)(v2 + 75)
                                    ^ *(_BYTE *)(v2 + 74)))
                 & 0x3F] = v2;
            ++rnhash; /*0x12fb62*/
          }
          vn_rele(v2 + 12); /*0x12fb69*/
        }
        v2 = v5; /*0x12fb71*/
      }
      while ( v5 ); /*0x12fb76*/
    }
  }
}
