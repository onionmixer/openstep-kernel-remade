
void _dspq_free_msg(uint *param_1)

{
  uint uVar1;
  uint *puVar2;
  int iVar3;
  
  if ((param_1 == (uint *)0x0) || (*(char *)(param_1 + 9) == '\0')) {
    iVar3 = _curipl();
    if (iVar3 == 0) {
      if (param_1 == (uint *)0x0) {
        if ((uint **)dword_40B5098 != &dword_40B5098) {
          do {
            puVar2 = dword_40B5098;
            dword_40B5098 = (uint *)dword_40B5098[6];
            if ((uint **)dword_40B5098 == &dword_40B5098) {
              dword_40B509C = (uint *)&dword_40B5098;
            }
            else {
              dword_40B5098[7] = (uint)&dword_40B5098;
            }
            _dspq_free_msg(puVar2);
          } while ((uint **)dword_40B5098 != &dword_40B5098);
        }
      }
      else {
        dword_40C6E4E = dword_40C6E4E + -1;
        if (*(char *)((int)param_1 + 0x23) == '\0') {
          if ((*param_1 < 5) && (*param_1 != 0)) {
            _vm_map_pageable(_kernel_map,~_page_mask & param_1[1],
                             ~_page_mask & _page_mask + param_1[2] + param_1[1],1);
            _vm_deallocate(_kernel_map,param_1[1],param_1[2]);
          }
          iVar3 = 0x26;
        }
        else {
          iVar3 = 0x26;
          uVar1 = *param_1;
          if (uVar1 != 0) {
            if (uVar1 < 5) {
              iVar3 = param_1[2] + 0x26;
            }
            else if (uVar1 == 9) {
              iVar3 = *(int *)(param_1[1] + 4) + 0x26;
            }
          }
        }
        _kfree(param_1,iVar3);
        if ((dword_40C6E4E < 0x200) && ((dword_40C6E84 & 0x40000) != 0)) {
          _port_set_add(dword_40C6EC0,dword_40C6EA8,0x10013);
          dword_40C6E84 = dword_40C6E84 & 0xfffbffff;
        }
      }
    }
    else {
      if ((uint **)dword_40B509C == &dword_40B5098) {
        dword_40B5098 = param_1;
      }
      else {
        dword_40B509C[6] = (uint)param_1;
      }
      param_1[7] = (uint)dword_40B509C;
      param_1[6] = (uint)&dword_40B5098;
      dword_40B509C = param_1;
      _callout_dispatch(4,_dspq_free_msg,0);
    }
  }
  else {
    dword_40C6E4E = dword_40C6E4E + -1;
    if ((uint **)dword_40B5094 == &dword_40B5090) {
      dword_40B5090 = param_1;
    }
    else {
      dword_40B5094[6] = (uint)param_1;
    }
    param_1[7] = (uint)dword_40B5094;
    param_1[6] = (uint)&dword_40B5090;
    dword_40B5094 = param_1;
  }
  return;
}

