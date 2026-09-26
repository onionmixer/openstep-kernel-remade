/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x161f10. */
void __cdecl insque(void *a1, void *a2)
{
  *(_DWORD *)a1 = *(_DWORD *)a2; /*0x161f1c*/
  *((_DWORD *)a1 + 1) = a2; /*0x161f1e*/
  *(_DWORD *)(*(_DWORD *)a2 + 4) = a1; /*0x161f23*/
  *(_DWORD *)a2 = a1; /*0x161f26*/
}
