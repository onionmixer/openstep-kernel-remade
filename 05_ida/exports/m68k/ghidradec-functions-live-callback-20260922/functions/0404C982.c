
undefined4
_netipc_listen(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined2 param_4,
              undefined2 param_5,byte param_6,int param_7)

{
  undefined4 uVar1;
  undefined4 *puVar2;
  
  if (*(sword *)(*(int *)(_active_u + 0x1a) + 2) == 0) {
    if (param_7 == 0) {
      uVar1 = 4;
    }
    else {
      puVar2 = (undefined4 *)_zalloc(_listener_zone);
      puVar2[1] = param_2;
      *(undefined2 *)(puVar2 + 3) = param_4;
      puVar2[2] = param_3;
      *(undefined2 *)((int)puVar2 + 0xe) = param_5;
      puVar2[4] = param_7;
      _ipc_object_reference(param_7);
      *puVar2 = *(undefined4 *)(_listeners + (uint)(param_6 & 0xf) * 4);
      *(undefined4 **)(_listeners + (uint)(param_6 & 0xf) * 4) = puVar2;
      _ipc_kobject_set(param_7,0,0x11);
      uVar1 = 0;
    }
  }
  else {
    uVar1 = 8;
  }
  return uVar1;
}

