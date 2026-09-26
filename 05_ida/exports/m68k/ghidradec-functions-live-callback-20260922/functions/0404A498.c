
void sub_404A498(uint param_1)

{
  undefined4 *puVar1;
  bool bVar2;
  undefined4 *puVar3;
  int iVar4;
  undefined4 *puVar5;
  undefined4 *puVar6;
  
  puVar6 = (undefined4 *)(param_1 & ~_page_mask);
  bVar2 = true;
  iVar4 = 0;
  puVar5 = puVar6;
  if (0 < dword_40B371E) {
    do {
      if (puVar5[2] != 0) {
        bVar2 = false;
      }
      iVar4 = iVar4 + 1;
      puVar5 = (undefined4 *)(dword_40B371A + (int)puVar5);
    } while (iVar4 < dword_40B371E);
  }
  if (bVar2) {
    iVar4 = 0;
    if (0 < dword_40B371E) {
      do {
        puVar5 = (undefined4 *)*puVar6;
        puVar1 = (undefined4 *)puVar6[1];
        puVar3 = puVar1;
        if (puVar5 != &dword_40B3712) {
          puVar5[1] = puVar1;
          puVar3 = dword_40B3716;
        }
        dword_40B3716 = puVar3;
        *puVar1 = puVar5;
        dword_40AF7D4 = dword_40AF7D4 + -1;
        dword_40C2330 = dword_40C2330 + -1;
        _stack_finalize(puVar6 + 3);
        puVar6 = (undefined4 *)(dword_40B371A + (int)puVar6);
        iVar4 = iVar4 + 1;
      } while (iVar4 < dword_40B371E);
    }
    _kmem_free(_kernel_map,param_1,dword_40B371A);
    _stackStats = _stackStats + -1;
  }
  else {
    iVar4 = _canSwap(param_1);
    if (iVar4 != 0) {
      _doSwapout(param_1);
    }
  }
  return;
}

