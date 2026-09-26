
undefined4
FUN_04063a24(int param_1,undefined2 param_2,undefined2 param_3,undefined4 param_4,undefined4 param_5
            ,char *param_6,char *param_7,undefined4 param_8)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  void *pvVar3;
  
  if (DAT_040b4e81 == '\0') {
    _lock_init(&DAT_040b4e82,1);
    DAT_040b4e81 = '\x01';
  }
  if (DAT_040b06ec == 0) {
    puVar1 = (undefined4 *)_kalloc(0x62);
    puVar1[2] = param_1;
    *(undefined2 *)(puVar1 + 3) = param_2;
    *(undefined2 *)((int)puVar1 + 0xe) = param_3;
    puVar1[4] = param_4;
    puVar1[5] = param_5;
    *(undefined4 *)((int)puVar1 + 0x5e) = param_8;
    _strcpy((char *)(puVar1 + 6),param_6);
    _strcpy((char *)(puVar1 + 0x16),param_7);
    _lock_write(&DAT_040b4e82);
    *(undefined4 **)PTR_LOOP_040b0700 = puVar1;
    puVar1[1] = PTR_LOOP_040b0700;
    *puVar1 = &PTR_LOOP_040b06fc;
    PTR_LOOP_040b0700 = (undefined *)puVar1;
    _lock_done(&DAT_040b4e82);
    uVar2 = 0;
  }
  else if (param_1 == 0) {
    pvVar3 = (void *)_kalloc(0x82);
    _bcopy(&DAT_040b0710,pvVar3,0x70);
    *(undefined1 *)((int)pvVar3 + 3) = 1;
    *(undefined4 *)((int)pvVar3 + 4) = 0x82;
    *(int *)((int)pvVar3 + 0x10) = DAT_040b06ec;
    *(undefined4 *)((int)pvVar3 + 0x1c) = param_5;
    *(undefined4 *)((int)pvVar3 + 0x20) = 0;
    *(undefined4 *)((int)pvVar3 + 0x28) = param_8;
    _strcpy((char *)((int)pvVar3 + 0x30),param_6);
    *(undefined1 *)((int)pvVar3 + 0x70) = 2;
    *(undefined1 *)((int)pvVar3 + 0x71) = 0x20;
    *(ushort *)((int)pvVar3 + 0x72) = *(ushort *)((int)pvVar3 + 0x72) & 0x2f | 0x20;
    *(byte *)((int)pvVar3 + 0x73) = *(byte *)((int)pvVar3 + 0x73) & 0xf9 | 8;
    *(undefined2 *)((int)pvVar3 + 0x74) = param_2;
    *(undefined2 *)((int)pvVar3 + 0x76) = param_3;
    *(undefined1 *)((int)pvVar3 + 0x78) = 8;
    *(undefined1 *)((int)pvVar3 + 0x79) = 8;
    *(ushort *)((int)pvVar3 + 0x7a) = *(ushort *)((int)pvVar3 + 0x7a) & 0x6f | 0x60;
    *(byte *)((int)pvVar3 + 0x7b) = *(byte *)((int)pvVar3 + 0x7b) & 0xf9 | 8;
    _strcpy((char *)((int)pvVar3 + 0x7c),param_7);
    uVar2 = _msg_send_from_kernel(pvVar3,1,0);
  }
  else {
    uVar2 = 4;
  }
  return uVar2;
}

