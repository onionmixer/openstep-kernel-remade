/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x161f30. */
void __cdecl remque(void *a1)
{
  *(_DWORD *)(*(_DWORD *)a1 + 4) = *((_DWORD *)a1 + 1); /*0x161f3b*/
  **((_DWORD **)a1 + 1) = *(_DWORD *)a1; /*0x161f43*/
}
