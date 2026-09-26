/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1586d4. */
int __cdecl msg_send_from_kernel(_DWORD *a1, char a2, int a3)
{
  int v3; // edx
  int v4; // ebx
  int v5; // ebx
  int v6; // eax
  int v8; // [esp+Ch] [ebp-4h] BYREF

  v3 = a1[1]; /*0x1586e6*/
  v4 = v3 + 3; /*0x1586eb*/
  LOBYTE(v4) = (v3 + 3) & 0xFC; /*0x1586ed*/
  v5 = ipc_kmsg_get_from_kernel(a1, v4, v3 - v4, &v8); /*0x1586fe*/
  if ( !v5 ) /*0x158705*/
  {
    ipc_kmsg_copyin_compat_from_kernel((_DWORD *)v8); /*0x15870b*/
    if ( (a2 & 2) != 0 ) /*0x158719*/
      panic(aMsgSendFromKer); /*0x158720*/
    v6 = 196608; /*0x158732*/
    if ( (a2 & 1) != 0 ) /*0x15873d*/
      v6 = 196624; /*0x15873f*/
    v5 = ipc_mqueue_send(v8, v6, a3, 0); /*0x15874e*/
    if ( v5 ) /*0x158755*/
      ipc_kmsg_destroy((_DWORD *)v8); /*0x15875b*/
  }
  return msg_return_translate(v5); /*0x15876c*/
}
