
bool _netipc_msg_send(int param_1)

{
  bool bVar1;
  
  bVar1 = *(int *)(param_1 + 0x28) == 0x7a7;
  if (bVar1) {
    sub_404C758(param_1);
  }
  return bVar1;
}

