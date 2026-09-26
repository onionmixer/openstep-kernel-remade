
int _fifosp(int param_1)

{
  int iVar1;
  undefined auStack_3e [28];
  undefined4 uStack_22;
  undefined4 uStack_1e;
  undefined4 uStack_1a;
  undefined4 uStack_16;
  undefined4 uStack_12;
  undefined4 uStack_e;
  
  iVar1 = _kalloc(0x8a);
  _bzero(iVar1,0x8a);
  *(undefined **)(iVar1 + 0x20) = _fifo_vnodeops;
  (**(code **)(*(int *)(param_1 + 0x1c) + 0x14))
            (param_1,auStack_3e,*(undefined4 *)(_active_u + 0x1a));
  *(undefined4 *)(iVar1 + 0x4a) = uStack_22;
  *(undefined4 *)(iVar1 + 0x4e) = uStack_1e;
  *(undefined4 *)(iVar1 + 0x52) = uStack_1a;
  *(undefined4 *)(iVar1 + 0x56) = uStack_16;
  *(undefined4 *)(iVar1 + 0x5a) = uStack_12;
  *(undefined4 *)(iVar1 + 0x5e) = uStack_e;
  return iVar1;
}
