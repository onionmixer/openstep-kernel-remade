/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x120a7c. */
int __cdecl nb_free_wrapper(int a1)
{
  *(_DWORD *)(a1 + 4) = 12; /*0x120a82*/
  *(_WORD *)(a1 + 8) = 0; /*0x120a89*/
  return m_free(a1); /*0x120a97*/
}
