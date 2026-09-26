/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x14cff0. */
int __cdecl ipc_port_copyout_send(int a1, int a2)
{
  int v2; // ebx
  int v4; // [esp+8h] [ebp-4h] BYREF

  if ( !a1 || a1 == -1 ) /*0x14d002*/
    return a1; /*0x14d040*/
  v2 = ipc_object_copyout(a2, a1, 17, 1, &v4); /*0x14d016*/
  if ( v2 ) /*0x14d01d*/
  {
    ipc_port_release_send(a1); /*0x14d020*/
    if ( v2 == 20 ) /*0x14d028*/
      return -1; /*0x14d02a*/
    else
      return 0; /*0x14d034*/
  }
  return v4; /*0x14d049*/
}
