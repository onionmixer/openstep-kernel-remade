/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x12f720. */
int __cdecl rp_rmhash(_BYTE *a1)
{
  int v1; // ebx
  int result; // eax
  int v3; // edx

  v1 = 0; /*0x12f727*/
  result = (a1[91] /*0x12f759*/
          ^ (unsigned __int8)(a1[90]
                            ^ a1[89]
                            ^ a1[88]
                            ^ a1[87]
                            ^ a1[86]
                            ^ a1[85]
                            ^ a1[84]
                            ^ a1[81]
                            ^ a1[80]
                            ^ a1[79]
                            ^ a1[78]
                            ^ a1[77]
                            ^ a1[76]
                            ^ a1[75]
                            ^ a1[74]))
         & 0x3F;
  v3 = rtable[result]; /*0x12f75c*/
  if ( v3 ) /*0x12f765*/
  {
    while ( (_BYTE *)v3 != a1 ) /*0x12f76a*/
    {
      v1 = v3; /*0x12f7c0*/
      v3 = *(_DWORD *)(v3 + 8); /*0x12f7c2*/
      if ( !v3 ) /*0x12f7c7*/
        return result; /*0x12f7c7*/
    }
    if ( v1 ) /*0x12f76e*/
    {
      *(_DWORD *)(v1 + 8) = *(_DWORD *)(v3 + 8); /*0x12f7b3*/
    }
    else
    {
      result = (*(_BYTE *)(v3 + 91) /*0x12f7a0*/
              ^ (unsigned __int8)(*(_BYTE *)(v3 + 90)
                                ^ *(_BYTE *)(v3 + 89)
                                ^ *(_BYTE *)(v3 + 88)
                                ^ *(_BYTE *)(v3 + 87)
                                ^ *(_BYTE *)(v3 + 86)
                                ^ *(_BYTE *)(v3 + 85)
                                ^ *(_BYTE *)(v3 + 84)
                                ^ *(_BYTE *)(v3 + 81)
                                ^ *(_BYTE *)(v3 + 80)
                                ^ *(_BYTE *)(v3 + 79)
                                ^ *(_BYTE *)(v3 + 78)
                                ^ *(_BYTE *)(v3 + 77)
                                ^ *(_BYTE *)(v3 + 76)
                                ^ *(_BYTE *)(v3 + 75)
                                ^ *(_BYTE *)(v3 + 74)))
             & 0x3F;
      rtable[result] = *(_DWORD *)(v3 + 8); /*0x12f7a6*/
    }
    --rnhash; /*0x12f7b6*/
  }
  return result; /*0x12f7c9*/
}
