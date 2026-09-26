/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0016d554 */

void _port_request_notification(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  undefined4 local_30 [7];
  undefined4 local_14;
  undefined4 local_10;
  undefined4 local_8;
  
  puVar2 = &DAT_001dff10;
  puVar3 = local_30;
  for (iVar1 = 0xb; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar3 = *puVar2;
    puVar2 = puVar2 + 1;
    puVar3 = puVar3 + 1;
  }
  local_14 = param_1;
  local_10 = param_2;
  local_30[3] = 0;
  local_30[4] = _pn_register_port_k;
  local_8 = param_1;
  iVar1 = _msg_send_from_kernel(local_30,1,0);
  if (iVar1 != 0) {
    _printf(s_port_request_notification__msg_s_001e00c0,iVar1);
  }
  return;
}

