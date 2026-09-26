
void _swapinStack(uint param_1)

{
  int iVar1;
  int *piVar2;
  
  piVar2 = (int *)(~_page_mask & param_1);
  dword_40C2334 = dword_40C2334 + -1;
  _vm_map_pageable(_kernel_map,piVar2,~_page_mask & (int)piVar2 + _page_mask + dword_40B371A,0);
  _lock_write(&_stack_queue_lock);
  *(undefined4 *)(param_1 - 4) = 2;
  if (*piVar2 == -0x1120532) {
    *piVar2 = 0;
    dword_40C2338 = dword_40C2338 + -1;
    iVar1 = 0;
    if (0 < dword_40B371E) {
      do {
        if (piVar2[2] == 0) {
          sub_404A45C(piVar2);
        }
        piVar2 = (int *)(dword_40B371A + (int)piVar2);
        iVar1 = iVar1 + 1;
      } while (iVar1 < dword_40B371E);
    }
  }
  _lock_done(&_stack_queue_lock);
  return;
}

