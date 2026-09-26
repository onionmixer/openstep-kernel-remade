/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x14c11c. */
int __cdecl ipc_object_copyin_compat(int a1, int a2, int a3, int a4, int a5)
{
  int result; // eax
  int v6; // [esp+8h] [ebp-4h] BYREF

  result = ipc_right_lookup_write(a1, a2, &v6); /*0x14c130*/
  if ( !result ) /*0x14c13a*/
    return ipc_right_copyin_compat(a1, a2, v6, a3, a4, a5); /*0x14c14e*/
  return result; /*0x14c156*/
}
