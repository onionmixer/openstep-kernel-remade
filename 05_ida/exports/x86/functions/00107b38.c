/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x107b38. */
uid_t getuid(void)
{
  uid_t result; // eax

  *(_DWORD *)(dword_1E875C + 96) = *(__int16 *)(*(_DWORD *)(active_u + 28) + 6); /*0x107b4d*/
  result = *(__int16 *)(*(_DWORD *)(active_u + 28) + 2); /*0x107b5e*/
  *(_DWORD *)(dword_1E875C + 100) = result; /*0x107b62*/
  return result; /*0x107b67*/
}
