
void _free_file(undefined4 *param_1)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  
  puVar1 = (undefined4 *)*param_1;
  puVar2 = (undefined4 *)param_1[1];
  puVar3 = puVar2;
  if (puVar1 != &_file_list) {
    puVar1[1] = puVar2;
    puVar3 = dword_40B59C8;
  }
  dword_40B59C8 = puVar3;
  *puVar2 = puVar1;
  _zfree(_file_zone,param_1);
  return;
}

