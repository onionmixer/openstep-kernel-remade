/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x12f8a8. */
int __cdecl sub_12F8A8(_BYTE *a1, int a2)
{
  int v2; // ebx
  __int16 v3; // ax

  v2 = rtable[(a1[27] /*0x12f8e4*/
             ^ (unsigned __int8)(a1[26]
                               ^ a1[25]
                               ^ a1[24]
                               ^ a1[23]
                               ^ a1[22]
                               ^ a1[21]
                               ^ a1[20]
                               ^ a1[17]
                               ^ a1[16]
                               ^ a1[15]
                               ^ a1[14]
                               ^ a1[13]
                               ^ a1[12]
                               ^ a1[11]
                               ^ a1[10]))
            & 0x3F];
  if ( !v2 ) /*0x12f8ed*/
    return 0; /*0x12f9e3*/
  while ( bcmp((const void *)(v2 + 64), a1, 0x20u) || *(_DWORD *)(v2 + 48) != a2 ) /*0x12f914*/
  {
    v2 = *(_DWORD *)(v2 + 8); /*0x12f9d8*/
    if ( !v2 ) /*0x12f9dd*/
      return 0; /*0x12f9dd*/
  }
  v3 = *(_WORD *)(v2 + 18); /*0x12f91a*/
  *(_WORD *)(v2 + 18) = v3 + 1; /*0x12f922*/
  if ( v3 ) /*0x12f929*/
  {
    ++ractive; /*0x12f988*/
  }
  else
  {
    if ( *(_DWORD *)v2 ) /*0x12f92b*/
    {
      if ( *(_DWORD *)v2 == v2 ) /*0x12f933*/
      {
        rpfreelist = nullptr; /*0x12f935*/
      }
      else
      {
        if ( rpfreelist == (void *)v2 ) /*0x12f94a*/
          rpfreelist = *(void **)v2; /*0x12f94c*/
        **(_DWORD **)(v2 + 4) = *(_DWORD *)v2; /*0x12f956*/
        *(_DWORD *)(*(_DWORD *)v2 + 4) = *(_DWORD *)(v2 + 4); /*0x12f95d*/
      }
      *(_DWORD *)(v2 + 4) = 0; /*0x12f960*/
      *(_DWORD *)v2 = 0; /*0x12f967*/
      --rnfree; /*0x12f96d*/
    }
    ++*(_DWORD *)(*(_DWORD *)(*(_DWORD *)(v2 + 48) + 296) + 24); /*0x12f97c*/
    ++rreactive; /*0x12f97f*/
  }
  if ( *(_DWORD *)v2 ) /*0x12f98e*/
  {
    if ( *(_DWORD *)v2 == v2 ) /*0x12f996*/
    {
      rpfreelist = nullptr; /*0x12f998*/
    }
    else
    {
      if ( rpfreelist == (void *)v2 ) /*0x12f9aa*/
        rpfreelist = *(void **)v2; /*0x12f9ac*/
      **(_DWORD **)(v2 + 4) = *(_DWORD *)v2; /*0x12f9b6*/
      *(_DWORD *)(*(_DWORD *)v2 + 4) = *(_DWORD *)(v2 + 4); /*0x12f9bd*/
    }
    *(_DWORD *)(v2 + 4) = 0; /*0x12f9c0*/
    *(_DWORD *)v2 = 0; /*0x12f9c7*/
    --rnfree; /*0x12f9cd*/
  }
  return v2; /*0x12f9e8*/
}
