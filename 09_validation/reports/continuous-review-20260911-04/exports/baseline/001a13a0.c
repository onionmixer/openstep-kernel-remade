
undefined4 _PCexception(int param_1,int param_2)

{
  undefined1 uVar1;
  int *piVar2;
  undefined4 uVar3;
  int iVar4;
  int iVar5;
  uint in_CR2;
  
  piVar2 = *(int **)(*(int *)(param_1 + 0x28) + 0xec);
  iVar5 = 0;
  if (piVar2 != (int *)0x0) {
    iVar5 = *piVar2;
  }
  if (iVar5 == 0) {
    iVar5 = 0;
  }
  else if (*(uint *)(iVar5 + 0x84) < 8) {
    iVar5 = iVar5 + 0x88 + *(uint *)(iVar5 + 0x84) * 0x84;
  }
  else {
    iVar5 = 0;
  }
  if (*(int *)(iVar5 + 0x48) == 0) {
LAB_001a14d5:
    uVar3 = 0;
  }
  else {
    if (*(int *)(param_2 + 0x30) == 0xe) {
      uVar1 = *(undefined1 *)(DAT_001e875c + 0x68);
      *(undefined1 *)(DAT_001e875c + 0x68) = 0;
      uVar3 = 1;
      if ((*(byte *)(param_2 + 0x34) & 2) != 0) {
        uVar3 = 3;
      }
      iVar4 = _vm_fault(*(undefined4 *)(*(int *)(param_1 + 0xc) + 0xc),~_page_mask & in_CR2,uVar3,0,
                        0);
      *(undefined1 *)(DAT_001e875c + 0x68) = uVar1;
      if (iVar4 != 0) {
        *(undefined4 *)(iVar5 + 0x4c) = *(undefined4 *)(param_2 + 0x30);
        *(undefined4 *)(iVar5 + 0x50) = *(undefined4 *)(param_2 + 0x34);
        *(int *)(iVar5 + 0x54) = iVar4;
        _exception_with_continuation(1,iVar4);
        if (*(int *)(iVar5 + 0x54) != 0) {
          *(undefined4 *)(iVar5 + 0x58) = 1;
          _PCcallMonitor(param_1,param_2);
        }
      }
    }
    else if ((*(int *)(param_2 + 0x30) == 7) && (*(int *)(iVar5 + 0x6c) == 0)) {
      _fp_noextension(param_2);
    }
    else {
      if ((*(byte *)(param_2 + 0x42) & 2) == 0) {
        iVar4 = _PCemulatePROT(param_1,param_2);
      }
      else {
        iVar4 = _PCemulateREAL(param_1,param_2);
      }
      if (iVar4 == 0) goto LAB_001a14d5;
    }
    if ((*(int *)(iVar5 + 0x58) == 0) &&
       ((*(int *)(iVar5 + 0x74) != 0 || (iVar5 = _PCtimersPending(iVar5), iVar5 != 0)))) {
      _PCcallMonitor(param_1,param_2);
    }
    uVar3 = _thread_exception_return();
  }
  return uVar3;
}

