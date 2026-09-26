/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x12f400. */
void __cdecl setdiropargs(void *a1, int a2, int a3)
{
  bcopy((const void *)(*(_DWORD *)(a3 + 48) + 64), a1, 0x20u); /*0x12f418*/
  *((_DWORD *)a1 + 8) = a2; /*0x12f41d*/
}
