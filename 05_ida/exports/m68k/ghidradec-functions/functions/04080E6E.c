
int sub_4080E6E(int param_1)

{
  undefined4 ***pppuVar1;
  int iVar2;
  undefined4 ***pppuVar3;
  undefined4 **ppuStack_54;
  undefined4 **ppuStack_50;
  undefined auStack_4c [12];
  undefined4 uStack_40;
  undefined4 uStack_3c;
  int iStack_14;
  undefined4 uStack_c;
  
  sub_408061A(0);
  _bcopy(unk_40B214A,auStack_4c,0x48);
  uStack_3c = 0x10000;
  uStack_40 = *(undefined4 *)(param_1 + 0x10);
  uStack_c = *(undefined4 *)(param_1 + 0x10);
  if (*(int *)(param_1 + 0x2c) == 5) {
    iStack_14 = *(int *)(param_1 + 0x20) * 2;
  }
  else {
    iStack_14 = *(int *)(param_1 + 0x20) * *(int *)(param_1 + 0x2c);
  }
  iVar2 = _msg_send(auStack_4c,0,0);
  if (iVar2 == 0) {
    ppuStack_54 = &ppuStack_54;
    ppuStack_50 = &ppuStack_54;
    pppuVar3 = (undefined4 ***)_kalloc(0x26);
    *pppuVar3 = (undefined4 **)0x6;
    pppuVar3[1] = *(undefined4 ***)(param_1 + 0x1c);
    *(undefined2 *)(pppuVar3 + 2) = *(undefined2 *)(param_1 + 0x22);
    *(undefined2 *)((int)pppuVar3 + 10) = *(undefined2 *)(param_1 + 0x26);
    *(undefined *)(pppuVar3 + 3) = *(undefined *)(param_1 + 0x2b);
    *(undefined *)((int)pppuVar3 + 0xd) = *(undefined *)(param_1 + 0x2f);
    *(undefined *)((int)pppuVar3 + 0xe) = 0;
    *(undefined *)(pppuVar3 + 8) = 2;
    *(undefined *)((int)pppuVar3 + 0x22) = 0;
    *(undefined *)((int)pppuVar3 + 0x21) = 0;
    *(undefined *)((int)pppuVar3 + 0x23) = 0;
    *(undefined *)(pppuVar3 + 9) = 0;
    pppuVar1 = pppuVar3;
    if ((undefined4 ***)ppuStack_50 != &ppuStack_54) {
      ppuStack_50[6] = pppuVar3;
      pppuVar1 = (undefined4 ***)ppuStack_54;
    }
    ppuStack_54 = pppuVar1;
    pppuVar3[7] = ppuStack_50;
    pppuVar3[6] = &ppuStack_54;
    ppuStack_50 = pppuVar3;
    _dspq_enqueue(&ppuStack_54);
    iVar2 = 0;
  }
  return iVar2;
}
