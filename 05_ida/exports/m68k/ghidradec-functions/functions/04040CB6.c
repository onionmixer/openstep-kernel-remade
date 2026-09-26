
void _ipc_port_pdrequest(int param_1,undefined4 param_2,undefined4 *param_3)

{
  undefined4 uVar1;
  
  uVar1 = *(undefined4 *)(param_1 + 0x24);
  *(undefined4 *)(param_1 + 0x24) = param_2;
  *param_3 = uVar1;
  return;
}
