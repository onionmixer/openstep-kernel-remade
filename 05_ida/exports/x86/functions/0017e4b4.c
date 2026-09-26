/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x17e4b4. */
int _io_host_priv_self()
{
  int v0; // ebx
  int v2; // [esp+4h] [ebp-4h] BYREF

  v0 = dword_1E97B4; /*0x17e4bb*/
  port_reference(dword_1E97B4); /*0x17e4c2*/
  object_copyout(*(_DWORD *)(active_threads + 12), v0, 6, &v2); /*0x17e4d7*/
  return v2; /*0x17e4df*/
}
