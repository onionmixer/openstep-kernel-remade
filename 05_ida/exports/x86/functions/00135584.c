/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x135584. */
int __cdecl clntkudp_freecred(int a1)
{
  int v1; // ebx
  int result; // eax

  v1 = *(_DWORD *)(a1 + 8); /*0x13558b*/
  result = crfree(*(_WORD **)(v1 + 116)); /*0x135592*/
  *(_DWORD *)(v1 + 116) = -269488145; /*0x135597*/
  return result; /*0x13559e*/
}
