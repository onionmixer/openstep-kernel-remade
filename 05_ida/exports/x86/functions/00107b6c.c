/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x107b6c. */
gid_t getgid(void)
{
  gid_t result; // eax

  *(_DWORD *)(dword_1E875C + 96) = *(__int16 *)(*(_DWORD *)(active_u + 28) + 8); /*0x107b81*/
  result = *(__int16 *)(*(_DWORD *)(active_u + 28) + 4); /*0x107b92*/
  *(_DWORD *)(dword_1E875C + 100) = result; /*0x107b96*/
  return result; /*0x107b9b*/
}
