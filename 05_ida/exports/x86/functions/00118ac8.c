/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x118ac8. */
int __cdecl unp_internalize(int a1)
{
  int v1; // edx
  signed int v2; // edi
  unsigned int *v3; // esi
  int v4; // ebx
  int v5; // eax
  unsigned int *v7; // esi
  signed int i; // ebx
  int v9; // eax
  unsigned int v10; // [esp-4h] [ebp-14h]
  int v11; // [esp+Ch] [ebp-4h]

  v1 = a1; /*0x118ad1*/
  v2 = (unsigned int)*(__int16 *)(a1 + 8) >> 2; /*0x118ada*/
  v3 = (unsigned int *)(*(_DWORD *)(a1 + 4) + a1); /*0x118adf*/
  v4 = 0; /*0x118ae2*/
  if ( v2 ) /*0x118ae6*/
  {
    while ( 1 ) /*0x118aea*/
    {
      v10 = *v3++; /*0x118aea*/
      v11 = v1; /*0x118aee*/
      v5 = getf(v10); /*0x118af1*/
      v1 = v11; /*0x118af9*/
      if ( !v5 ) /*0x118afe*/
        return 9; /*0x118b00*/
      if ( ++v4 >= v2 ) /*0x118b0b*/
        goto LABEL_5; /*0x118b0b*/
    }
  }
  else
  {
LABEL_5:
    v7 = (unsigned int *)(*(_DWORD *)(v1 + 4) + v1); /*0x118b0d*/
    for ( i = 0; i < v2; ++i ) /*0x118b16*/
    {
      v9 = getf(*v7); /*0x118b1b*/
      *v7++ = v9; /*0x118b20*/
      ++*(_WORD *)(v9 + 14); /*0x118b25*/
      ++*(_WORD *)(v9 + 16); /*0x118b29*/
      ++unp_rights; /*0x118b2d*/
    }
    return 0; /*0x118b3b*/
  }
}
