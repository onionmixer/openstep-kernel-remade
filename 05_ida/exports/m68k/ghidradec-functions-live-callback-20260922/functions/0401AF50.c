
void _forceclose(sword param_1)

{
  int iVar1;
  undefined4 *puVar2;
  
  puVar2 = _file_list;
  if ((undefined4 **)_file_list != &_file_list) {
    do {
      if ((((*(sword *)((int)puVar2 + 0xe) != 0) && (*(sword *)(puVar2 + 3) == 1)) &&
          (iVar1 = *(int *)((int)puVar2 + 0x16), iVar1 != 0)) &&
         (((*(int *)(iVar1 + 0x28) == 4 || (*(int *)(iVar1 + 0x28) == 9)) &&
          (param_1 == *(sword *)(iVar1 + 0x2c))))) {
        puVar2[2] = puVar2[2] & 0xfffffffc;
      }
      puVar2 = (undefined4 *)*puVar2;
    } while ((undefined4 **)puVar2 != &_file_list);
  }
  return;
}

