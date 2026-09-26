
undefined4 _kern_serv_handler(int param_1,int param_2)

{
  undefined4 uVar1;
  undefined auStack_24 [3];
  undefined uStack_21;
  undefined4 uStack_20;
  undefined4 uStack_1c;
  undefined4 uStack_18;
  undefined4 uStack_14;
  int iStack_10;
  undefined4 uStack_c;
  int iStack_8;
  
  uStack_21 = 1;
  uStack_20 = 0x20;
  uStack_1c = *(undefined4 *)(param_1 + 8);
  uStack_18 = 0;
  uStack_14 = *(undefined4 *)(param_1 + 0x10);
  iStack_10 = *(int *)(param_1 + 0x14) + 100;
  uStack_c = 0x2200018;
  iStack_8 = -0x12f;
  if ((*(int *)(param_1 + 0x14) - 100U < 0xd) &&
     (*(code **)(unk_40ACEE2 + *(int *)(param_1 + 0x14) * 4) != (code *)0x0)) {
    (**(code **)(unk_40ACEE2 + *(int *)(param_1 + 0x14) * 4))(param_1,auStack_24,param_2);
    if (iStack_8 == -0x131) {
      uVar1 = 0;
    }
    else {
      uVar1 = _msg_send(auStack_24,CARRY4(~*(uint *)(param_2 + 4),~*(uint *)(param_2 + 4)),
                        *(undefined4 *)(param_2 + 4));
    }
  }
  else {
    uVar1 = 0xfffffed1;
  }
  return uVar1;
}
