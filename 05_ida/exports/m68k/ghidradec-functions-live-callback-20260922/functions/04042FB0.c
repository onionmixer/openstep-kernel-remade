
undefined4 _ipc_space_create_special(undefined4 *param_1)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  
  puVar1 = (undefined4 *)_zalloc(_ipc_space_zone);
  if (puVar1 == (undefined4 *)0x0) {
    uVar2 = 6;
  }
  else {
    *puVar1 = 1;
    puVar1[1] = 0;
    *param_1 = puVar1;
    uVar2 = 0;
  }
  return uVar2;
}

