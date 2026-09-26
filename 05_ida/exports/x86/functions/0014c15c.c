/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x14c15c. */
int __cdecl ipc_object_copyin_header(int a1, int a2, int a3, int a4)
{
  int result; // eax
  int v5; // [esp+8h] [ebp-4h] BYREF

  result = ipc_right_lookup_write(a1, a2, &v5); /*0x14c170*/
  if ( !result ) /*0x14c17a*/
    return ipc_right_copyin_header(a1, a2, v5, a3, a4); /*0x14c18a*/
  return result; /*0x14c192*/
}
