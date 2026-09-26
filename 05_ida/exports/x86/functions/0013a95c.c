/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x13a95c. */
unsigned int __cdecl uncompress_data(int a1, int a2, _DWORD *a3, int a4)
{
  int *v4; // edi
  signed int v6; // ebx
  char v7; // cl
  unsigned int v8; // edx
  int v10; // [esp+Ch] [ebp-Ch]
  char *v11; // [esp+10h] [ebp-8h]
  signed int v12; // [esp+14h] [ebp-4h]

  v12 = (unsigned int)(a4 + 3) >> 2; /*0x13a973*/
  v11 = (char *)(a1 + 4); /*0x13a979*/
  v4 = (int *)(a1 + ((unsigned int)(a4 + 3) >> 5) + 4); /*0x13a97f*/
  v10 = 0; /*0x13a986*/
  v6 = 0; /*0x13a98d*/
  if ( v12 ) /*0x13a992*/
  {
LABEL_2:
    v7 = *v11++; /*0x13a994*/
    v8 = 0; /*0x13a99d*/
    while ( v12 > v6 ) /*0x13a9a3*/
    {
      if ( v7 >= 0 ) /*0x13a9a7*/
      {
        *a3 = v10; /*0x13a9bb*/
      }
      else
      {
        v10 = *v4; /*0x13a9ab*/
        *a3 = *v4++; /*0x13a9ae*/
      }
      ++a3; /*0x13a9bd*/
      v7 *= 2; /*0x13a9c0*/
      ++v8; /*0x13a9c2*/
      ++v6; /*0x13a9c3*/
      if ( v8 > 7 ) /*0x13a9c7*/
      {
        if ( v12 > v6 ) /*0x13a9cc*/
          goto LABEL_2; /*0x13a9cc*/
        return (unsigned int)(a4 + 3) >> 2; /*0x13a9cc*/
      }
    }
  }
  return (unsigned int)(a4 + 3) >> 2; /*0x13a9d4*/
}
