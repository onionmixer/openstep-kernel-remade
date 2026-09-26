
int _trap(int param_1,uint param_2,int param_3,uint param_4,undefined4 *param_5)

{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  undefined uVar5;
  byte *pbVar6;
  bool bVar7;
  bool bVar8;
  uint uVar9;
  int iVar10;
  int iVar11;
  int iVar12;
  undefined *puVar13;
  undefined4 uStack_60;
  int iStack_5c;
  uint uStack_54;
  uint uStack_50;
  int iStack_4c;
  int iStack_40;
  int iStack_38;
  int iStack_34;
  uint uStack_30;
  code *pcStack_28;
  int iStack_24;
  int iStack_20;
  undefined uStack_11;
  int iStack_8;
  
  iVar11 = _active_threads;
  bVar8 = false;
  bVar7 = false;
  iStack_8 = 0;
  if (_active_threads == 0) {
    iStack_40 = 0;
  }
  else {
    iStack_40 = *(int *)(_active_threads + 0x24);
  }
  iStack_4c = 0;
  uStack_50 = 0;
  uStack_54 = 0;
  if ((*(byte *)(param_5 + 0x10) & 0x20) == 0) {
    iVar10 = *_active_u;
    if (iVar10 != 0) {
      iStack_24 = *(int *)((int)_active_u + 0x16e);
      iStack_20 = *(int *)((int)_active_u + 0x172);
      iStack_5c = *dword_40B57D4;
      *dword_40B57D4 = (int)param_5;
    }
    uVar1 = *(undefined4 *)(iStack_40 + 0x48);
    *(undefined4 **)(iStack_40 + 0x48) = param_5;
    if (param_1 == 0x34) goto loc_4099D9C;
    if (param_1 < 0x35) {
      if (param_1 == 0x18) goto loc_4099DC0;
      if (param_1 < 0x19) {
        if (param_1 != 0xc) {
          if (param_1 < 0xd) {
            if ((param_1 != 4) && (param_1 == 8)) {
              if ((_bmap_chip != 0) &&
                 ((*(char *)(_bmap_chip + 8) < '\0' && ((*(byte *)(_bmap_chip + 8) & 0x40) != 0))))
              {
                    /* WARNING: Subroutine does not return */
                _bmap_parity_error(param_4);
              }
              if (((_dma_chip == 0x139) && (_slot_id + 0x200e000U <= param_4)) &&
                 (param_4 < _slot_id + 0x200e00cU)) goto loc_409A000;
              iStack_4c = 1;
              uStack_50 = 1;
              goto loc_4099DF8;
            }
          }
          else if (param_1 != 0x10) {
            iVar12 = 0x14;
            goto loc_4099BA4;
          }
loc_4099D9C:
          iStack_4c = 2;
          goto loc_4099DA2;
        }
        iStack_4c = 1;
        uStack_50 = 2;
      }
      else {
        if (param_1 == 0x24) {
          _do_trace(param_5);
          goto loc_4099E1C;
        }
        if (param_1 < 0x25) {
          iVar12 = 0x1c;
loc_4099BA4:
          if (iVar12 != param_1) goto loc_4099D9C;
          goto loc_4099DC0;
        }
        if ((param_1 != 0x28) && (param_1 != 0x2c)) goto loc_4099D9C;
        iStack_4c = 4;
loc_4099DA2:
        uStack_50 = *(word *)((int)param_5 + 0x46) & 0xfff;
      }
    }
    else {
      if (param_1 != 0xd0) {
        if (param_1 < 0xd1) {
          if (param_1 != 0xc4) {
            if (param_1 < 0xc5) {
              if (param_1 == 0xbc) {
                iStack_4c = 6;
                goto loc_4099DF8;
              }
              if (param_1 == 0xc0) goto loc_4099DBA;
            }
            else if ((param_1 == 200) || (param_1 == 0xcc)) goto loc_4099DBA;
            goto loc_4099D9C;
          }
        }
        else if (param_1 != 0xdc) {
          if (0xdc < param_1) {
            if (param_1 == 0x40c) {
loc_4099C4E:
              uVar5 = *(undefined *)(dword_40B57D4 + 0x19);
              *(undefined *)(dword_40B57D4 + 0x19) = 0;
              uStack_50 = _vm_fault(*(undefined4 *)(*(int *)(iVar11 + 0xc) + 8),
                                    ~_page_mask & param_4,param_3,0,0);
              *(undefined *)(dword_40B57D4 + 0x19) = uVar5;
              if (uStack_50 == 0) {
                if (param_3 == 1) {
                  _tlb_update_read(param_2,param_4);
                }
                else {
                  _tlb_update_write(param_2,param_4);
                }
                if ((_cpu_type == '\0') || (iVar12 = _do_writeback(param_5), iVar12 == 0)) {
loc_409A000:
                  *(undefined4 *)(iStack_40 + 0x48) = uVar1;
                  if (iVar10 != 0) {
                    *dword_40B57D4 = iStack_5c;
                  }
                  if (bVar8) {
                    return (int)*(sword *)(unk_40B2C9A +
                                          (*(uint *)((int)param_5 + 0x46) >> 0x1c) * 2);
                  }
                  return 0;
                }
                goto loc_4099E1C;
              }
              if ((_cpu_type != '\0') && (_do_writeback(param_5), param_3 != 1)) goto loc_4099E1C;
              iStack_4c = 1;
              uStack_54 = param_4;
              goto loc_4099DF8;
            }
            if (param_1 < 0x40d) {
              if (param_1 == 0x404) goto loc_4099C4E;
            }
            else if (param_1 == 0x410) goto loc_4099C4E;
            goto loc_4099D9C;
          }
          if ((param_1 != 0xd4) && (param_1 != 0xd8)) goto loc_4099D9C;
        }
      }
loc_4099DBA:
      bVar7 = true;
loc_4099DC0:
      iStack_4c = 3;
      uStack_50 = *(word *)((int)param_5 + 0x46) & 0xfff;
    }
loc_4099DF8:
    while ((*(uint *)(iVar11 + 0x177) & 0x3ffffff) >> 0x18 != 0) {
      _thread_halt_self_with_continuation(0);
    }
    _exception_with_continuation(iStack_4c,uStack_50,uStack_54,0);
loc_4099E1C:
    do {
      while (iVar10 != 0) {
        if ((*(uint *)(iVar11 + 0x177) & 0x3ffffff) >> 0x18 == 0) {
          if ((*(char *)(iVar10 + 0x17) != '\0') ||
             ((uVar9 = *(uint *)(*(int *)(iVar11 + 0x80) + 0x72) | *(uint *)(iVar10 + 0x18),
              uVar9 != 0 &&
              (((*(byte *)(iVar10 + 0x2b) & 0x10) != 0 ||
               ((uVar9 & ~(*(uint *)(iVar10 + 0x1c) | *(uint *)(iVar10 + 0x20))) != 0)))))) {
            if (bVar7) {
              _need_ast = _need_ast | 4;
              if (_need_ast != 0) {
                pbVar6 = (byte *)(*(int *)(_active_threads + 0x24) + 0x54);
                *pbVar6 = *pbVar6 | 0x10;
              }
            }
            else {
              if ((*(char *)(iVar10 + 0x17) != '\0') || (iVar12 = _issig(0), iVar12 != 0)) {
                _psig();
              }
              bVar8 = true;
            }
          }
          break;
        }
loc_4099EB8:
        _thread_halt_self_with_continuation(0);
      }
      if ((*(uint *)(iVar11 + 0x177) & 0x3ffffff) >> 0x18 != 0) goto loc_4099EB8;
      if ((*(byte *)(param_5 + 0x10) & 0x20) != 0) goto loc_4099F80;
      iVar12 = *(int *)(*(int *)(_processor_ptr + 0x128) + 0x104);
      iVar2 = *(int *)(*(int *)(_processor_ptr + 0x128) + 0x100);
      iVar3 = *(int *)(iVar11 + 0x54);
      iVar4 = *(int *)(iVar11 + 0x5c);
      if (((*(byte *)(iVar11 + 0x4b) & 2) == 0) && (*(int *)(_processor_ptr + 0x104) < 1)) {
        if ((iVar4 == 2) || ((2 < iVar4 || (iVar4 != 1)))) {
          if ((iVar12 == 0) ||
             ((iVar2 < iVar3 || ((iVar2 <= iVar3 && (*(int *)(_processor_ptr + 0x120) != 0))))))
          goto loc_4099F80;
        }
        else if ((*(int *)(_processor_ptr + 0x120) != 0) || ((iVar12 < 1 || (iVar2 < iVar3))))
        goto loc_4099F80;
      }
      *(int *)((int)_active_u + 0x1aa) = *(int *)((int)_active_u + 0x1aa) + 1;
      _thread_block();
      if (((iVar10 == 0) || ((*(uint *)(iVar11 + 0x177) & 0x3ffffff) >> 0x18 != 0)) ||
         ((*(char *)(iVar10 + 0x17) == '\0' &&
          ((uVar9 = *(uint *)(*(int *)(iVar11 + 0x80) + 0x72) | *(uint *)(iVar10 + 0x18), uVar9 == 0
           || (((*(byte *)(iVar10 + 0x2b) & 0x10) == 0 &&
               ((uVar9 & ~(*(uint *)(iVar10 + 0x1c) | *(uint *)(iVar10 + 0x20))) == 0))))))))
      goto loc_4099F80;
    } while( true );
  }
  if (param_1 == 0x404) {
loc_4099750:
    if (_active_threads != 0) {
      uStack_11 = *(undefined *)(dword_40B57D4 + 0x19);
      *(undefined *)(dword_40B57D4 + 0x19) = 0;
    }
    iStack_38 = 0;
    if ((param_2 & 0xfffffffc) == 0) {
      iStack_34 = *(int *)(*(int *)(iVar11 + 0xc) + 8);
    }
    else if (((iVar11 == 0) || (*(int *)(*(int *)(iVar11 + 0xc) + 0x48) == 0)) ||
            (iStack_34 = *(int *)(*(int *)(iVar11 + 0xc) + 8), _kernel_map == iStack_34)) {
      iStack_34 = _kernel_map;
    }
    else {
      iStack_38 = _kernel_map;
    }
    uStack_30 = _vm_fault(iStack_34,~_page_mask & param_4,param_3,0,&iStack_8);
    if ((uStack_30 != 0) && (iStack_38 != 0)) {
      uStack_30 = _vm_fault(iStack_38,param_4 & ~_page_mask,param_3,0,&iStack_8);
    }
    if (iVar11 != 0) {
      *(undefined *)(dword_40B57D4 + 0x19) = uStack_11;
    }
    if (uStack_30 != 0) {
      iStack_4c = 1;
      uStack_50 = uStack_30;
      uStack_54 = param_4;
      goto loc_4099890;
    }
    if (param_3 == 1) {
      _tlb_update_read(param_2,param_4);
    }
    else {
      _tlb_update_write(param_2,param_4);
    }
    if (_cpu_type != '\0') {
      uVar9 = _do_writeback(param_5);
      if ((uVar9 & 0x40000000) != 0) goto loc_4099890;
      if ((int)uVar9 < 0) goto loc_40999E8;
    }
loc_40999D4:
    iVar11 = 0;
  }
  else {
    if (0x404 < param_1) {
      if ((param_1 != 0x40c) && (param_1 != 0x410)) goto loc_40999E8;
      goto loc_4099750;
    }
    if (param_1 != 8) {
      if (param_1 != 0x24) goto loc_40999E8;
      if (iStack_40 != 0) {
        *(byte *)(iStack_40 + 0x54) = *(byte *)(iStack_40 + 0x54) | 8;
      }
      goto loc_40999D4;
    }
loc_4099890:
    if (((_bmap_chip != 0) && (*(char *)(_bmap_chip + 8) < '\0')) &&
       ((*(byte *)(_bmap_chip + 8) & 0x40) != 0)) {
                    /* WARNING: Subroutine does not return */
      _bmap_parity_error(param_4);
    }
    if (iVar11 == 0) {
      pcStack_28 = (code *)0x0;
    }
    else {
      pcStack_28 = *(code **)(iVar11 + 0x70);
    }
    if (pcStack_28 == (code *)0x0) {
      if ((_copyoutstr < *(code **)((int)param_5 + 0x42)) &&
         (*(code **)((int)param_5 + 0x42) < _fast_setjmp)) {
        pcStack_28 = _FAULT_ERROR;
        if (iStack_8 == 0) {
          _fault_error = 0xe;
        }
        else {
          _fault_error = iStack_8;
        }
      }
      if (pcStack_28 == (code *)0x0) {
        if (_probe_recover != (code *)0x0) {
          pcStack_28 = _probe_recover;
        }
        if (pcStack_28 == (code *)0x0) {
          if ((_dma_chip != 0x139) ||
             (((param_4 < _slot_id + 0x200e000U || (_slot_id + 0x200e00cU <= param_4)) &&
              ((param_4 < _slot_id + 0x200f000U || (_slot_id + 0x200f00cU <= param_4)))))) {
            _printf(aUnexpectedKern);
loc_40999E8:
            _gdb_from_trap(param_5,(int)*(sword *)(param_5 + 0x10),
                           *(undefined4 *)((int)param_5 + 0x42),param_4);
            _printf(aTrapType0xXFco,param_1,param_2,param_3,param_4);
            _printf(aTrapPc0xXSp0xX,*(undefined4 *)((int)param_5 + 0x42),param_5[0xf],
                    (int)*(sword *)(param_5 + 0x10));
            if (iVar11 == 0) {
              iVar12 = -1;
              iVar10 = -1;
            }
            else {
              iVar12 = (int)*(sword *)(*_active_u + 0x30);
              iVar10 = *_active_u;
            }
            _printf(aTrapCpuDTh0xXP,0,iVar11,iVar10,iVar12,iStack_40);
            iVar11 = _setjmp(_traceback_jb + _traceback_recursive * 0x34);
            if (iVar11 == 0) {
              _traceback(param_5[0xe]);
            }
            puVar13 = _trap_type;
            while( true ) {
              if (*(sword *)puVar13 == 0) {
                _printf(aTrapStrayVecto,param_1 >> 2,param_1);
                    /* WARNING: Subroutine does not return */
                _panic(&aTrap);
              }
              if (*(sword *)puVar13 == param_1) break;
              puVar13 = (undefined *)((int)puVar13 + 6);
            }
                    /* WARNING: Subroutine does not return */
            _panic(*(undefined4 *)((int)puVar13 + 2));
          }
          goto loc_40999D4;
        }
      }
    }
    *(code **)((int)param_5 + 0x42) = pcStack_28;
    if ((iVar11 != 0) && (*(code **)(iVar11 + 0x70) == _move_space_fault)) {
      if (iStack_4c == 0) {
        iStack_4c = 1;
        uStack_50 = 1;
        uStack_60 = 0x40000000;
      }
      else {
        uStack_60 = 0x80000000;
      }
      *param_5 = uStack_60;
      param_5[1] = iStack_4c;
      param_5[8] = uStack_50;
      param_5[9] = uStack_54;
    }
    iVar11 = (int)*(sword *)(unk_40B2C9A + (*(uint *)((int)param_5 + 0x46) >> 0x1c) * 2);
  }
  return iVar11;
loc_4099F80:
  if ((_active_u[0x94] != 0) &&
     (iVar11 = ((*(int *)((int)_active_u + 0x172) - iStack_20) / 1000 +
               (*(int *)((int)_active_u + 0x16e) - iStack_24) * 1000) / (_tick / 1000), iVar11 != 0)
     ) {
    _addupc(*(undefined4 *)((int)param_5 + 0x42),_active_u + 0x8f,iVar11);
  }
  goto loc_409A000;
}

