
void sub_406DB14(int param_1,undefined4 param_2)

{
  undefined6 *puVar1;
  
  if (_fd_polling_mode == 0) {
    puVar1 = &aWrite_0;
    if ((*(byte *)(param_1 + 0x15f) & 1) != 0) {
      puVar1 = (undefined6 *)&aRead_0;
    }
    _printf(aFdDSectorDDCmd,*(undefined4 *)(param_1 + 0x10),*(undefined4 *)(param_1 + 0x13c),puVar1,
            *(undefined4 *)(param_1 + 0x9e),_fd_return_values,param_2);
  }
  return;
}

