
void _fd_set_density_info(int param_1,int param_2)

{
  int iVar1;
  undefined *puVar2;
  
  puVar2 = _fd_density_info;
  iVar1 = _fd_density_info._0_4_;
  while ((iVar1 != 0 && (param_2 != *(int *)puVar2))) {
    puVar2 = (undefined *)((int)puVar2 + 0xc);
    iVar1 = *(int *)puVar2;
  }
  *(int *)(param_1 + 0x17a) = *(int *)puVar2;
  *(int *)(param_1 + 0x17e) = *(int *)((int)puVar2 + 4);
  *(int *)(param_1 + 0x182) = *(int *)((int)puVar2 + 8);
  _fd_set_sector_size(param_1,*(undefined4 *)(param_1 + 0x186));
  if (param_2 == 0) {
    *(uint *)(param_1 + 0x176) = *(uint *)(param_1 + 0x176) & 0xfffffffe;
  }
  return;
}
