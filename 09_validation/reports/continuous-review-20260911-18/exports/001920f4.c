
void _kernel_trap(int param_1)

{
  int iVar1;
  int iVar2;
  undefined1 unaff_BL;
  undefined4 uVar3;
  uint *puVar4;
  uint uVar5;
  uint in_CR2;
  int local_10;
  uint local_c;
  
  puVar4 = (uint *)(param_1 + 0x34);
  uVar5 = 0;
  iVar1 = *(int *)(param_1 + 0x30);
  switch(iVar1) {
  case 1:
  case 3:
    FUN_00192438(param_1);
    return;
  case 7:
    goto switchD_0019211a_caseD_7;
  case 10:
    if ((*(byte *)(param_1 + 0x41) & 0x40) != 0) {
      FUN_001924e0(param_1);
      _thread_exception_return();
    }
    break;
  case 0xb:
  case 0xc:
  case 0xd:
    if ((*(byte *)puVar4 & 6) == 4) {
      FUN_001924e0(param_1);
      uVar5 = *puVar4;
      _exception_from_kernel(2,iVar1,uVar5);
      _thread_exception_return();
    }
    break;
  case 0xe:
    if (_active_threads != 0) {
      unaff_BL = *(undefined1 *)(DAT_001e875c + 0x68);
      *(undefined1 *)(DAT_001e875c + 0x68) = 0;
    }
    if (in_CR2 < 0xc0000000) {
      uVar3 = 1;
      if ((*(byte *)puVar4 & 2) != 0) {
        uVar3 = 3;
      }
      local_10 = _vm_fault(*(undefined4 *)(*(int *)(_active_threads + 0xc) + 0xc),
                           ~_page_mask & in_CR2,uVar3,0,0);
    }
    else {
      local_10 = FUN_001923e0();
    }
    if (_active_threads != 0) {
      *(undefined1 *)(DAT_001e875c + 0x68) = unaff_BL;
    }
    if (local_10 == 0) {
      return;
    }
    iVar2 = FUN_001924a0(puVar4);
    if (iVar2 != 0) {
      return;
    }
    local_c = in_CR2;
    if (in_CR2 < 0xc0000000) {
      FUN_001924e0(param_1);
      _exception_from_kernel(1,local_10,in_CR2);
      _thread_exception_return();
      uVar5 = in_CR2;
    }
    break;
  case 0x10:
    _fp_kernel_extension_fault(param_1);
    goto switchD_0019211a_caseD_7;
  }
  iVar2 = FUN_001924a0(puVar4);
  if (iVar2 == 0) {
    _DoAlert(s_Kernel_Trap_001e280d,&DAT_001e280c);
    _printf(s_unexpected_kernel_trap__x_eip__x_001e2819,iVar1,*(undefined4 *)(param_1 + 0x38));
    switch(iVar1) {
    case 0:
      uVar3 = 3;
      local_10 = 0;
      break;
    default:
      uVar3 = 2;
      local_10 = iVar1;
      break;
    case 4:
      uVar3 = 5;
      local_10 = 4;
      break;
    case 5:
      uVar3 = 3;
      local_10 = 5;
      break;
    case 6:
      uVar3 = 2;
      local_10 = 6;
      break;
    case 0xb:
      uVar3 = 2;
      local_10 = 0xb;
      uVar5 = *puVar4;
      break;
    case 0xc:
      uVar3 = 2;
      local_10 = 0xc;
      uVar5 = *puVar4;
      break;
    case 0xd:
      uVar3 = 2;
      local_10 = 0xd;
      uVar5 = *puVar4;
      break;
    case 0xe:
      uVar3 = 1;
      uVar5 = local_c;
      break;
    case 0x11:
      uVar3 = 5;
      local_10 = 0x11;
    }
    __i386_backtrace(*(undefined4 *)(param_1 + 0x18),4);
    _kdp_raise_exception(uVar3,local_10,uVar5,param_1);
    _DoRestore();
                    /* WARNING: Subroutine does not return */
    _panic(s_continued_after_kernel_trap_001e283b);
  }
switchD_0019211a_caseD_7:
  return;
}

