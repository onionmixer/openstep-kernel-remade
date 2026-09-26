
undefined4 _kern_serv_port_death_proc(int *param_1,undefined4 param_2)

{
  *(undefined4 *)(*param_1 + 0x4b8) = param_2;
  return 0;
}
