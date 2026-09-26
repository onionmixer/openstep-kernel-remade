
void _fd_shutdown(void)

{
  undefined4 *puVar1;
  sword sVar2;
  undefined4 *puVar3;
  
  puVar1 = _file_list;
  while (puVar3 = puVar1, (undefined4 **)puVar3 != &_file_list) {
    puVar1 = (undefined4 *)*puVar3;
    sVar2 = *(sword *)((int)puVar3 + 0xe);
    while (0 < sVar2) {
      _closef(puVar3);
      sVar2 = *(sword *)((int)puVar3 + 0xe);
    }
  }
  return;
}
