/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x14b7bc. */
int __cdecl ipc_notify_port_destroyed_compat(int a1, int a2)
{
  _DWORD *v2; // eax

  v2 = (_DWORD *)kalloc(0x34u); /*0x14b7c7*/
  if ( v2 ) /*0x14b7d1*/
  {
    v2[2] = 52; /*0x14b7f4*/
    v2[3] = 0; /*0x14b7fb*/
    v2[4] = 0; /*0x14b802*/
    qmemcpy(v2 + 5, &ipc_notify_port_destroyed_template, 0x20u); /*0x14b817*/
    v2[5] = -2147483631; /*0x14b819*/
    v2[7] = a1; /*0x14b820*/
    v2[12] = a2; /*0x14b826*/
    return ipc_mqueue_send((int)v2, 0x10000, 0, 0); /*0x14b833*/
  }
  else
  {
    printf("dropped port-destroyed-compat (0x%08x, 0x%08x)\n", a1, a2); /*0x14b7dd*/
    ipc_port_release_send(a1); /*0x14b7e3*/
    return ipc_port_release_receive(a2); /*0x14b7ec*/
  }
}
