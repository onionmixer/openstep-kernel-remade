
int _vol_panel_remove(undefined4 param_1)

{
  undefined4 *puVar1;
  int iVar2;
  int iVar3;
  
  iVar3 = 0;
  if (_panel_req_port != 0) {
    puVar1 = (undefined4 *)_kalloc(0x20);
    *puVar1 = dword_40B080C;
    puVar1[1] = dword_40B0810;
    puVar1[2] = dword_40B0814;
    puVar1[3] = dword_40B0818;
    puVar1[4] = dword_40B081C;
    puVar1[5] = dword_40B0820;
    puVar1[6] = dword_40B0824;
    puVar1[7] = dword_40B0828;
    puVar1[3] = dword_40B06F4;
    puVar1[4] = _panel_req_port;
    puVar1[7] = param_1;
    iVar3 = _msg_send_from_kernel(puVar1,1,0);
    if (iVar3 != 0) {
      _printf(aVolPanelRemove,iVar3);
    }
  }
  iVar2 = sub_4064092(param_1);
  if (iVar2 != 0) {
    _kfree(iVar2,0x14);
  }
  return iVar3;
}

