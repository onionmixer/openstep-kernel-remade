
void _user_trap(int param_1)

{
  undefined1 uVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  uint uVar5;
  uint *puVar6;
  uint in_CR2;
  int local_20;
  int local_14;
  int local_10;
  
  iVar2 = _active_threads;
  puVar6 = (uint *)(param_1 + 0x34);
  uVar5 = 0;
  local_20 = *(int *)(param_1 + 0x30);
  iVar3 = *_active_u;
  if (iVar3 != 0) {
    local_14 = _active_u[0x5e];
    local_10 = _active_u[0x5f];
  }
  switch(local_20) {
  case 0:
    uVar4 = 3;
    local_20 = 0;
    break;
  case 1:
    uVar4 = 6;
    local_20 = 1;
    break;
  default:
    uVar4 = 2;
    break;
  case 3:
    uVar4 = 6;
    local_20 = 3;
    break;
  case 4:
    uVar4 = 5;
    local_20 = 4;
    break;
  case 5:
    uVar4 = 5;
    local_20 = 5;
    break;
  case 6:
    uVar4 = 2;
    local_20 = 6;
    break;
  case 7:
    _fp_noextension(param_1);
    goto LAB_00192065;
  case 0xb:
    uVar4 = 2;
    local_20 = 0xb;
    uVar5 = *puVar6;
    break;
  case 0xc:
    uVar4 = 2;
    local_20 = 0xc;
    uVar5 = *puVar6;
    break;
  case 0xd:
    uVar4 = 2;
    local_20 = 0xd;
    uVar5 = *puVar6;
    break;
  case 0xe:
    uVar1 = *(undefined1 *)(DAT_001e875c + 0x68);
    *(undefined1 *)(DAT_001e875c + 0x68) = 0;
    uVar4 = 1;
    if ((*(byte *)puVar6 & 2) != 0) {
      uVar4 = 3;
    }
    local_20 = _vm_fault(*(undefined4 *)(*(int *)(iVar2 + 0xc) + 0xc),~_page_mask & in_CR2,uVar4,0,0
                        );
    *(undefined1 *)(DAT_001e875c + 0x68) = uVar1;
    if (local_20 == 0) goto LAB_00192065;
    uVar4 = 1;
    uVar5 = in_CR2;
    break;
  case 0x10:
    _fp_extension_fault(param_1);
    goto LAB_00192065;
  case 0x11:
    uVar4 = 5;
    local_20 = 0x11;
  }
  _exception(uVar4,local_20,uVar5);
LAB_00192065:
  if (((iVar3 != 0) && (_active_u[0x97] != 0)) &&
     (iVar3 = ((_active_u[0x5f] - local_10) / 1000 + (_active_u[0x5e] - local_14) * 1000) /
              (_tick / 1000), iVar3 != 0)) {
    _addupc(*(undefined4 *)(param_1 + 0x38),_active_u + 0x92,iVar3);
  }
                    /* WARNING: Subroutine does not return */
  _thread_exception_return();
}

