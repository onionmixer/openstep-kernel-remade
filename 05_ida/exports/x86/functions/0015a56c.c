/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x15a56c. */
_BOOL4 __cdecl object_copyin(int a1, int a2, int a3, int a4, int a5)
{
  return ipc_object_copyin_compat(*(_DWORD *)(a1 + 136), a2, a3, a4, a5) == 0; /*0x15a599*/
}
