
int sub_4080D78(int param_1)

{
  undefined4 ***pppuVar1;
  int iVar2;
  undefined4 ***pppuVar3;
  undefined4 **ppuStack_5c;
  undefined4 **ppuStack_58;
  undefined auStack_54 [12];
  undefined4 uStack_48;
  undefined4 uStack_44;
  undefined4 uStack_18;
  undefined2 uStack_10;
  undefined2 uStack_e;
  undefined4 uStack_c;
  undefined4 uStack_8;
  
  sub_408061A(0);
  _bcopy(unk_40B20FA,auStack_54,0x50);
  uStack_44 = 0x10000;
  uStack_48 = *(undefined4 *)(param_1 + 0x10);
  uStack_18 = *(undefined4 *)(param_1 + 0x10);
  uStack_8 = *(undefined4 *)(param_1 + 0x3c);
  uStack_10 = *(undefined2 *)(param_1 + 0x34);
  uStack_e = *(undefined2 *)(param_1 + 0x36);
  uStack_c = *(undefined4 *)(param_1 + 0x38);
  iVar2 = _msg_send(auStack_54,0,0);
  if (iVar2 == 0) {
    ppuStack_5c = &ppuStack_5c;
    ppuStack_58 = &ppuStack_5c;
    pppuVar3 = (undefined4 ***)_kalloc(0x26);
    *pppuVar3 = (undefined4 **)0x5;
    pppuVar3[1] = *(undefined4 ***)(param_1 + 0x1c);
    *(undefined2 *)(pppuVar3 + 2) = *(undefined2 *)(param_1 + 0x22);
    *(undefined2 *)((int)pppuVar3 + 10) = *(undefined2 *)(param_1 + 0x26);
    *(undefined *)(pppuVar3 + 3) = *(undefined *)(param_1 + 0x2b);
    *(undefined *)((int)pppuVar3 + 0xd) = *(undefined *)(param_1 + 0x2f);
    *(undefined *)((int)pppuVar3 + 0xe) = 0;
    *(undefined *)((int)pppuVar3 + 0x23) = 0;
    *(undefined *)(pppuVar3 + 9) = 0;
    pppuVar1 = pppuVar3;
    if ((undefined4 ***)ppuStack_58 != &ppuStack_5c) {
      ppuStack_58[6] = pppuVar3;
      pppuVar1 = (undefined4 ***)ppuStack_5c;
    }
    ppuStack_5c = pppuVar1;
    pppuVar3[7] = ppuStack_58;
    pppuVar3[6] = &ppuStack_5c;
    ppuStack_58 = pppuVar3;
    _dspq_enqueue(&ppuStack_5c);
    iVar2 = 0;
  }
  return iVar2;
}
