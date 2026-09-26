/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x12d3b4. */
int __cdecl sub_12D3B4(__int64 a1)
{
  __int64 i; // rax

  for ( i = a1; (_DWORD)i; LODWORD(i) = *(_DWORD *)i ) /*0x12d3bf*/
  {
    *(_DWORD *)HIDWORD(i) = i + *(_DWORD *)(i + 4); /*0x12d3c9*/
    *(_DWORD *)(HIDWORD(i) + 4) = *(__int16 *)(i + 8); /*0x12d3cf*/
    HIDWORD(i) += 8; /*0x12d3d2*/
  }
  return i; /*0x12d3dd*/
}
