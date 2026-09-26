
undefined4 _convert_port_to_host(int param_1)

{
  undefined4 uVar1;
  
  uVar1 = 0;
  if ((((param_1 != 0) && (param_1 != -1)) && ((int)*(uint *)(param_1 + 4) < 0)) &&
     ((*(uint *)(param_1 + 4) & 0xffff) - 3 < 2)) {
    uVar1 = *(undefined4 *)(param_1 + 0x10);
  }
  return uVar1;
}

