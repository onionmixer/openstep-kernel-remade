
void _nmi(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
         undefined4 param_5)

{
  bool bVar1;
  bool bVar2;
  int iVar3;
  undefined6 *puVar4;
  uint uVar5;
  
  bVar1 = false;
  bVar2 = false;
  if ((_dma_chip == 0x139) || ((*(uint *)(_slot_id + 0x2200020) & 1) == 0)) {
    uVar5 = *(uint *)(_slot_id + 0x200e008);
    *(byte *)(_slot_id + 0x200e001) = *(byte *)(_slot_id + 0x200e001) | 0x10;
    if (-1 < (char)uVar5) {
      if (((byte)(uVar5 >> 8) & 0x18) == 0x18) {
        bVar1 = true;
      }
      else if (((uVar5 & 0xffff) >> 8 & 8) == 0) {
        bVar2 = true;
      }
    }
  }
  else {
    *(undefined4 *)(_slot_id + 0x2200020) = 0;
    bVar1 = true;
  }
  iVar3 = _slot_id;
  if ((_dma_chip != 0x139) && ((*_intrstat & 0x40000000) != 0)) {
    *(undefined4 *)(_slot_id + 0x2200004) = 0;
    *(undefined4 *)(iVar3 + 0x2200004) = 0;
    uVar5 = (uint)(*(int *)(iVar3 + 0x2200008) - (iVar3 + 0x4000000)) /
            (uint)(0x8000000 / _num_regions);
    puVar4 = &aFront;
    if ((uVar5 & 1) != 0) {
      puVar4 = (undefined6 *)&aBack;
    }
    uVar5 = uVar5 & 0xfffffffe;
    _printf(aParityErrorAtA,*(undefined4 *)(iVar3 + 0x2200008),uVar5,uVar5 | 1,puVar4);
                    /* WARNING: Subroutine does not return */
    _panic(aParityError);
  }
  if (bVar1) {
    _mini_mon(&aNmi,aNmiMiniMonitor,param_1,param_2,param_3,param_4,param_5);
  }
  else if (bVar2) {
    _mini_mon(&aRestart,aRestartPowerOf);
  }
  return;
}

