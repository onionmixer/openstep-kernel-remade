/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x16d554. */
int __cdecl port_request_notification(int a1, int a2)
{
  int result; // eax
  _DWORD v3[11]; // [esp+8h] [ebp-2Ch] BYREF

  qmemcpy(v3, &unk_1DFF10, sizeof(v3)); /*0x16d570*/
  v3[7] = a1; /*0x16d572*/
  v3[8] = a2; /*0x16d575*/
  v3[3] = 0; /*0x16d578*/
  v3[4] = pn_register_port_k; /*0x16d585*/
  v3[10] = a1; /*0x16d588*/
  result = msg_send_from_kernel(v3, 1, 0); /*0x16d593*/
  if ( result )
    return printf("port_request_notification: msg_send returned %d\n", result);
  return result; /*0x16d5ad*/
}
