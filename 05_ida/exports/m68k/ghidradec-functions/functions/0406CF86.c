
void _fc_send_byte(int *param_1,undefined param_2)

{
  int iVar1;
  
  iVar1 = sub_406CFE8(param_1,0);
  if (iVar1 == 0) {
    *(undefined *)(*param_1 + 5) = param_2;
  }
  return;
}
