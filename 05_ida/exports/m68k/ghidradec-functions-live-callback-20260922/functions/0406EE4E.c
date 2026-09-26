
int sub_406EE4E(int param_1)

{
  int iVar1;
  undefined *puVar2;
  
  puVar2 = _fd_density_info;
  iVar1 = _fd_density_info._0_4_;
  while( true ) {
    if (iVar1 == 0) {
      return 0;
    }
    if (param_1 == *(int *)puVar2) break;
    puVar2 = (undefined *)((int)puVar2 + 0xc);
    iVar1 = *(int *)puVar2;
  }
  return *(int *)((int)puVar2 + 4);
}

