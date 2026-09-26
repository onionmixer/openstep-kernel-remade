
undefined4 _host_kernel_version(int param_1,undefined4 param_2)

{
  undefined4 uVar1;
  
  if (param_1 == 0) {
    uVar1 = 4;
  }
  else {
    _strncpy(param_2,_version,0x200);
    uVar1 = 0;
  }
  return uVar1;
}
