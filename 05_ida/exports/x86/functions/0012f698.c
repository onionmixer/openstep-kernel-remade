/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x12f698. */
int __cdecl sub_12F698(int a1)
{
  int result; // eax

  *(_DWORD *)(a1 + 8) = rtable[(*(_BYTE *)(a1 + 91) /*0x12f6d8*/
                              ^ (unsigned __int8)(*(_BYTE *)(a1 + 90)
                                                ^ *(_BYTE *)(a1 + 89)
                                                ^ *(_BYTE *)(a1 + 88)
                                                ^ *(_BYTE *)(a1 + 87)
                                                ^ *(_BYTE *)(a1 + 86)
                                                ^ *(_BYTE *)(a1 + 85)
                                                ^ *(_BYTE *)(a1 + 84)
                                                ^ *(_BYTE *)(a1 + 81)
                                                ^ *(_BYTE *)(a1 + 80)
                                                ^ *(_BYTE *)(a1 + 79)
                                                ^ *(_BYTE *)(a1 + 78)
                                                ^ *(_BYTE *)(a1 + 77)
                                                ^ *(_BYTE *)(a1 + 76)
                                                ^ *(_BYTE *)(a1 + 75)
                                                ^ *(_BYTE *)(a1 + 74)))
                             & 0x3F];
  result = (*(_BYTE *)(a1 + 91) /*0x12f70b*/
          ^ (unsigned __int8)(*(_BYTE *)(a1 + 90)
                            ^ *(_BYTE *)(a1 + 89)
                            ^ *(_BYTE *)(a1 + 88)
                            ^ *(_BYTE *)(a1 + 87)
                            ^ *(_BYTE *)(a1 + 86)
                            ^ *(_BYTE *)(a1 + 85)
                            ^ *(_BYTE *)(a1 + 84)
                            ^ *(_BYTE *)(a1 + 81)
                            ^ *(_BYTE *)(a1 + 80)
                            ^ *(_BYTE *)(a1 + 79)
                            ^ *(_BYTE *)(a1 + 78)
                            ^ *(_BYTE *)(a1 + 77)
                            ^ *(_BYTE *)(a1 + 76)
                            ^ *(_BYTE *)(a1 + 75)
                            ^ *(_BYTE *)(a1 + 74)))
         & 0x3F;
  rtable[result] = a1; /*0x12f70e*/
  ++rnhash; /*0x12f715*/
  return result; /*0x12f71d*/
}
