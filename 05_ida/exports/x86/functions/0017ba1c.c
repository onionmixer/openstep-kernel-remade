/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x17ba1c. */
int __cdecl sub_17BA1C(int a1, unsigned int a2, unsigned int a3)
{
  int i; // ebx
  unsigned int v5; // ecx
  unsigned int v6; // edx
  unsigned int v7; // eax
  int v9; // [esp+10h] [ebp-4h]

  v9 = 0; /*0x17ba28*/
  lock_read(a1); /*0x17ba33*/
  for ( i = *(_DWORD *)(a1 + 16); i != a1 + 12; i = *(_DWORD *)(i + 4) ) /*0x17ba38*/
  {
    if ( (*(_BYTE *)(i + 24) & 5) != 0 ) /*0x17ba44*/
    {
      if ( sub_17BA1C(*(_DWORD *)(i + 16), a2, a3) != 5 ) /*0x17ba5a*/
        continue; /*0x17ba5a*/
LABEL_12:
      v9 = 5; /*0x17baa1*/
      continue; /*0x17baa1*/
    }
    v5 = *(_DWORD *)(i + 8); /*0x17ba60*/
    if ( a3 >= v5 ) /*0x17ba66*/
    {
      v6 = *(_DWORD *)(i + 12); /*0x17ba68*/
      if ( v6 > a2 ) /*0x17ba6d*/
      {
        if ( v5 > a2 ) /*0x17ba77*/
          a2 = *(_DWORD *)(i + 8); /*0x17ba79*/
        v7 = a3; /*0x17ba7b*/
        if ( v6 <= a3 ) /*0x17ba80*/
          v7 = *(_DWORD *)(i + 12); /*0x17ba82*/
        if ( sub_17BC50(*(_DWORD *)(i + 16), a2 + *(_DWORD *)(i + 20) - v5, *(_DWORD *)(i + 20) - v5 + v7) ) /*0x17ba95*/
          goto LABEL_12; /*0x17ba9f*/
      }
    }
  }
  lock_done(a1); /*0x17bab9*/
  return v9; /*0x17bac4*/
}
