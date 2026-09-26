/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1476ec. */
int __cdecl ipc_kmsg_put(int a1, int a2, int a3)
{
  int v3; // esi
  int v4; // eax

  *(_DWORD *)(a2 + 16) = 0; /*0x1476fa*/
  v3 = 0; /*0x14770f*/
  if ( copyoutmsg(a2 + 20, a1, a3) ) /*0x147707*/
    v3 = 268451848; /*0x147715*/
  if ( *(_DWORD *)(a2 + 8) == 256 && !ipc_kmsg_cache ) /*0x14772a*/
  {
    ipc_kmsg_cache = a2; /*0x14772c*/
    return v3; /*0x147732*/
  }
  v4 = *(_DWORD *)(a2 + 8); /*0x147734*/
  if ( v4 > 0 ) /*0x147739*/
  {
LABEL_13:
    kfree(a2, *(_DWORD *)(a2 + 8)); /*0x14775c*/
    return v3; /*0x14775e*/
  }
  if ( v4 == -2 ) /*0x14773e*/
  {
    KernDeviceInterruptMsgRelease(a2); /*0x14774d*/
    return v3; /*0x147752*/
  }
  if ( v4 != -1 ) /*0x147740*/
  {
    if ( v4 == -3 ) /*0x147745*/
    {
      netipc_msg_release(a2); /*0x147755*/
      return v3; /*0x14775a*/
    }
    goto LABEL_13; /*0x147745*/
  }
  return v3; /*0x147768*/
}
