/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x00185274 */

int _vol_panel_remove(undefined4 param_1)

{
  undefined4 *puVar1;
  int iVar2;
  int iVar3;
  undefined4 *puVar4;
  undefined4 *puVar5;
  
  iVar3 = 0;
  if (_panel_req_port != 0) {
    puVar1 = (undefined4 *)_kalloc(0x20);
    puVar4 = &DAT_001e150c;
    puVar5 = puVar1;
    for (iVar3 = 8; iVar3 != 0; iVar3 = iVar3 + -1) {
      *puVar5 = *puVar4;
      puVar4 = puVar4 + 1;
      puVar5 = puVar5 + 1;
    }
    puVar1[3] = DAT_001e13f4;
    puVar1[4] = _panel_req_port;
    puVar1[7] = param_1;
    iVar3 = _msg_send_from_kernel(puVar1,1,0);
    if (iVar3 != 0) {
      _printf(s_vol_panel_remove__msg_send_retur_001e166b,iVar3);
    }
  }
  iVar2 = FUN_001857fc(param_1);
  if (iVar2 != 0) {
    _kfree(iVar2,0x14);
  }
  return iVar3;
}

