
void sub_407BA0A(int *param_1,int param_2)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  undefined *puVar4;
  
  iVar1 = *param_1;
  puVar4 = *(undefined **)(*(int *)(iVar1 + 0x10) + 8);
  iVar2 = *(int *)((int)param_1 + 0x226);
  if (*(int *)((int)param_1 + 0x22e) == 0) {
    if (*(int *)((int)param_1 + 0x232) != 0) {
      *(undefined *)((int)param_1 + 0x21e) = 9;
      if (param_2 == 0) {
        puVar4[2] = 0;
      }
      *puVar4 = (char)*(undefined4 *)((int)param_1 + 0x232);
      puVar4[1] = (char)((uint)*(undefined4 *)((int)param_1 + 0x232) >> 8);
      puVar4[3] = 0;
      puVar4[3] = 0x98;
      return;
    }
    puVar4 = aTransferLenExc;
  }
  else {
    *(undefined *)((int)param_1 + 0x21e) = 6;
    if (*(int *)((int)param_1 + 0x22e) < 0x10001) {
      _dma_list(param_1 + 1,(int)param_1 + 0xfe,*(undefined4 *)((int)param_1 + 0x22a),
                *(int *)((int)param_1 + 0x22e),*(undefined4 *)(iVar2 + 0x3e),param_2,10,0,0);
      _dma_start(param_1 + 1,(int)param_1 + 0xfe,param_2);
      *puVar4 = (char)*(undefined4 *)((int)param_1 + 0x22e);
      puVar4[1] = (char)((uint)*(undefined4 *)((int)param_1 + 0x22e) >> 8);
      uVar3 = 0x30;
      if (param_2 == 0x40000) {
        uVar3 = 0x38;
      }
      *(undefined4 *)(*(int *)(iVar1 + 0x10) + 0x14) = uVar3;
      _busgo(*(undefined4 *)(iVar2 + 0x10));
      return;
    }
    puVar4 = aDmaLen64k;
  }
  sub_407BCB6(iVar1,0,puVar4);
  return;
}
