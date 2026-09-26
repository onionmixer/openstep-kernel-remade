/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x15746c. */
int exception_raise_continue()
{
  int v0; // eax
  int v2; // [esp+0h] [ebp-8h] BYREF
  unsigned int v3; // [esp+4h] [ebp-4h] BYREF

  v0 = ipc_mqueue_receive( /*0x157496*/
         *(_DWORD *)(active_threads + 196) + 64,
         0,
         0xFFFFFFFF,
         0,
         1,
         (int)exception_raise_continue,
         &v3,
         &v2);
  return exception_raise_continue_slow(v0, v3, v2); /*0x1574ac*/
}
