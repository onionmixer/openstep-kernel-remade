/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1cf1dc. */
int __usercall sub_1CF1DC@<eax>(int result@<eax>, int a2)
{
  unsigned int i; // edi
  int v3; // eax
  unsigned int j; // ebx
  unsigned int v5; // [esp+Ch] [ebp-Ch]
  unsigned int v6; // [esp+10h] [ebp-8h]
  int v7; // [esp+14h] [ebp-4h]

  v7 = *(_DWORD *)(a2 + 4); /*0x1cf1eb*/
  for ( i = 0; *(_DWORD *)(a2 + 8) > i; ++i ) /*0x1cf1f3*/
  {
    result = 16 * i; /*0x1cf1fa*/
    if ( *(_DWORD *)(v7 + 16 * i + 12) ) /*0x1cf200*/
    {
      v3 = *(_DWORD *)(v7 + result + 12); /*0x1cf207*/
      v5 = *(unsigned __int16 *)(v3 + 8); /*0x1cf20f*/
      result = v5 + *(unsigned __int16 *)(v3 + 10); /*0x1cf216*/
      v6 = result; /*0x1cf218*/
      for ( j = v5; v6 > j; ++j ) /*0x1cf220*/
        sub_1CF128(*(_DWORD *)(*(_DWORD *)(v7 + 16 * i + 12) + 4 * j + 12), *(_DWORD *)(v7 + 16 * i)); /*0x1cf23b*/
    }
  }
  return result; /*0x1cf255*/
}
