
undefined * _in_bootp_buildpacket(undefined4 param_1,int param_2,undefined4 param_3)

{
  undefined *puVar1;
  
  puVar1 = (undefined *)_kalloc(0x148);
  _bzero(puVar1,0x148);
  *puVar1 = 0x45;
  *(sword *)(puVar1 + 4) = _ip_id;
  _ip_id = _ip_id + 1;
  puVar1[8] = 0xff;
  puVar1[9] = 0x11;
  *(undefined4 *)(puVar1 + 0xc) = *(undefined4 *)(param_2 + 4);
  *(undefined4 *)(puVar1 + 0x10) = 0xffffffff;
  *(undefined2 *)(puVar1 + 0x14) = 0x44;
  *(undefined2 *)(puVar1 + 0x16) = 0x43;
  *(undefined2 *)(puVar1 + 0x1a) = 0;
  puVar1[0x1c] = 1;
  puVar1[0x1d] = 1;
  puVar1[0x1e] = 6;
  *(undefined4 *)(puVar1 + 0x28) = 0;
  _bcopy(param_3,puVar1 + 0x38,6);
  _bcopy(&aNext,puVar1 + 0x108,4);
  puVar1[0x10c] = 1;
  puVar1[0x10e] = 0;
  *(undefined2 *)(puVar1 + 0x18) = 0x134;
  *(undefined2 *)(puVar1 + 2) = 0x148;
  *(undefined2 *)(puVar1 + 10) = 0;
  return puVar1;
}

