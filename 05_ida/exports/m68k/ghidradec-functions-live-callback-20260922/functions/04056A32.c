
undefined4 _kern_serv_boot_port(int *param_1,undefined4 param_2)

{
  *(undefined4 *)(*param_1 + 0x10) = param_2;
  return 0;
}

