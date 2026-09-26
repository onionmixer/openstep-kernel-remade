
undefined4
_snd_reply_recorded_data
          (undefined4 param_1,undefined4 param_2,undefined4 param_3,int param_4,int param_5)

{
  undefined *puVar1;
  undefined4 uVar2;
  int iVar3;
  undefined auStack_34 [48];
  
  puVar1 = auStack_34;
  iVar3 = 0x30;
  if (param_5 != 0) {
    iVar3 = param_4 + 0x2c;
    puVar1 = (undefined *)_kalloc(iVar3);
  }
  puVar1[3] = 0;
  *(int *)(puVar1 + 4) = iVar3;
  *(undefined4 *)(puVar1 + 8) = 0;
  *(undefined4 *)(puVar1 + 0x10) = param_1;
  *(undefined4 *)(puVar1 + 0xc) = 0;
  *(undefined4 *)(puVar1 + 0x14) = 300;
  *(undefined4 *)(puVar1 + 0x18) = dword_40B21FC;
  *(undefined4 *)(puVar1 + 0x1c) = param_2;
  *(undefined4 *)(puVar1 + 0x20) = dword_40B21F0;
  *(undefined4 *)(puVar1 + 0x24) = dword_40B21F4;
  *(undefined4 *)(puVar1 + 0x28) = dword_40B21F8;
  *(int *)(puVar1 + 0x28) = param_4;
  if (param_5 == 0) {
    *(undefined4 *)(puVar1 + 0x2c) = param_3;
  }
  else {
    puVar1[0x23] = puVar1[0x23] | 8;
    _bcopy(param_3,puVar1 + 0x2c,param_4);
  }
  uVar2 = _msg_send(puVar1,0x21,0);
  if (param_5 != 0) {
    _kfree(puVar1,iVar3);
  }
  return uVar2;
}
