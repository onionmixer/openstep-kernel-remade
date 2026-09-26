/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x14b5d4. */
int __cdecl ipc_notify_send_once(int a1)
{
  _DWORD *v1; // eax

  v1 = (_DWORD *)kalloc(0x2Cu); /*0x14b5df*/
  if ( v1 ) /*0x14b5e9*/
  {
    v1[2] = 44; /*0x14b600*/
    v1[3] = 0; /*0x14b607*/
    v1[4] = 0; /*0x14b60e*/
    qmemcpy(v1 + 5, &ipc_notify_send_once_template, 0x18u); /*0x14b623*/
    v1[7] = a1; /*0x14b625*/
    return ipc_mqueue_send((int)v1, 0x10000, 0, 0); /*0x14b632*/
  }
  else
  {
    printf("dropped send-once (0x%08x)\n", a1); /*0x14b5f1*/
    return ipc_port_release_sonce(a1); /*0x14b5f7*/
  }
}
