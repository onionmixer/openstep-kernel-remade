/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x00152aec */

/* WARNING: Type propagation algorithm not settling */

uint _mach_msg_trap(code **param_1,code *param_2,code **param_3,code *param_4,code **param_5,
                   code **param_6,code *param_7)

{
  ushort uVar1;
  int iVar2;
  undefined4 uVar3;
  int iVar4;
  code *pcVar5;
  code *pcVar6;
  code *pcVar7;
  int iVar8;
  code *pcVar9;
  uint uVar10;
  uint uVar11;
  code **ppcVar12;
  code **ppcVar13;
  code *pcVar14;
  code ***pppcVar15;
  code ***pppcVar16;
  code ***pppcVar17;
  code **ppcStack_98;
  code **ppcStack_94;
  code ***pppcStack_90;
  code ***pppcStack_8c;
  code ***pppcStack_88;
  code *local_74;
  code *local_70;
  code *local_5c;
  code *local_50;
  code **local_4c;
  code **local_48;
  code **local_40;
  code *local_3c;
  code **local_38;
  code *local_34;
  code *local_30;
  code **local_2c;
  code *local_28;
  code **local_24;
  code *local_20;
  code *local_1c;
  code **local_18;
  code *local_14;
  code *local_10;
  code *local_c;
  code **local_8;
  
  ppcVar12 = _ipc_kmsg_cache;
  ppcVar13 = _active_threads;
  if (param_2 == (code *)0x3) {
    local_48 = *(code ***)(_active_threads[3] + 0x88);
    if (((param_3 + -6 < (code **)0xd5) && (((uint)param_3 & 3) == 0)) &&
       (local_4c = _ipc_kmsg_cache, _ipc_kmsg_cache != (code **)0x0)) {
      _ipc_kmsg_cache = (code **)0x0;
      ppcVar12[4] = (code *)0x0;
      pppcStack_88 = (code ***)param_3;
      pppcStack_8c = (code ***)(ppcVar12 + 5);
      pppcStack_90 = (code ***)param_1;
      ppcStack_94 = (code **)0x152b67;
      iVar4 = _copyinmsg();
      if (iVar4 != 0) {
        pppcStack_88 = (code ***)ppcVar12[2];
        if ((int)pppcStack_88 < 1) {
          pppcStack_88 = (code ***)ppcVar12;
          pppcStack_8c = (code ***)0x152b82;
          _ipc_kmsg_free();
        }
        else {
          pppcStack_8c = (code ***)ppcVar12;
          pppcStack_90 = (code ***)0x1535a6;
          _kfree();
        }
        goto LAB_001535a9;
      }
      ppcVar12[4] = (code *)0x0;
      ppcVar12[6] = (code *)param_3;
    }
    else {
LAB_001535a9:
      pppcStack_88 = &local_8;
      pppcStack_8c = (code ***)0x0;
      pppcStack_90 = (code ***)param_3;
      ppcStack_94 = param_1;
      ppcStack_98 = (code **)0x1535bc;
      pppcStack_88 = (code ***)_ipc_kmsg_get();
      if (pppcStack_88 != (code ***)0x0) {
        pppcStack_8c = (code ***)0x1535cb;
        _thread_syscall_return();
      }
      local_4c = local_8;
    }
    if (local_4c[5] == (code *)0x12) {
      if (local_4c[8] == (code *)0x0) {
        ppcVar12 = local_48 + 2;
        do {
          do {
          } while (*ppcVar12 != (code *)0x0);
          LOCK();
          pcVar5 = *ppcVar12;
          *ppcVar12 = (code *)0x1;
          UNLOCK();
        } while (pcVar5 == (code *)0x1);
        pcVar14 = local_48[6];
        pcVar7 = local_48[5];
        pcVar9 = (code *)((uint)local_4c[7] >> 8);
        uVar10 = (int)local_4c[7] << 0x18;
        if (((pcVar14 <= pcVar9) ||
            (pcVar6 = pcVar7 + (int)pcVar9 * 0x10,
            (*(uint *)pcVar6 & 0xff840000) != (uVar10 | 0x40000))) || (*(uint *)(pcVar6 + 8) != 0))
        goto LAB_00152ecc;
        pcVar5 = *(code **)(pcVar6 + 4);
        do {
          do {
          } while (*(int *)pcVar5 != 0);
          LOCK();
          iVar4 = *(int *)pcVar5;
          *(int *)pcVar5 = 1;
          UNLOCK();
        } while (iVar4 == 1);
        if (-1 < *(int *)(pcVar5 + 8)) goto LAB_00152dca;
        *(uint *)(pcVar6 + 8) = *(uint *)(pcVar7 + 8);
        *(code **)(pcVar7 + 8) = pcVar9;
        *(uint *)pcVar6 = uVar10;
        *(uint *)(pcVar6 + 4) = 0;
        local_4c[5] = (code *)0x12;
        local_4c[7] = pcVar5;
        if (pcVar14 <= (code *)((uint)param_5 >> 8)) {
LAB_00152edc:
          LOCK();
          *(int *)pcVar5 = 0;
          UNLOCK();
          LOCK();
          local_48[2] = (code *)0x0;
          UNLOCK();
          goto LAB_001537e0;
        }
        pcVar7 = pcVar7 + (int)((uint)param_5 >> 8) * 0x10;
        uVar10 = *(uint *)pcVar7;
        if ((uVar10 & 0xff000000) != (int)param_5 << 0x18) goto LAB_00152edc;
        if ((uVar10 & 0x80000) == 0) {
          if ((uVar10 & 0x20000) != 0) {
            local_74 = *(code **)(pcVar7 + 4);
            LOCK();
            iVar4 = *(int *)local_74;
            *(int *)local_74 = 1;
            UNLOCK();
            if (iVar4 != 1) {
              if (*(int *)(local_74 + 0x30) == 0) {
                local_70 = local_74 + 0x40;
                goto LAB_00152e90;
              }
              LOCK();
              *(int *)local_74 = 0;
              UNLOCK();
            }
          }
          goto LAB_00152edc;
        }
        local_74 = *(code **)(pcVar7 + 4);
        do {
          do {
          } while (*(int *)local_74 != 0);
          LOCK();
          iVar4 = *(int *)local_74;
          *(int *)local_74 = 1;
          UNLOCK();
        } while (iVar4 == 1);
        local_70 = local_74 + 0x10;
LAB_00152e90:
        LOCK();
        local_48[2] = (code *)0x0;
        UNLOCK();
        *(int *)(local_74 + 4) = *(int *)(local_74 + 4) + 1;
        do {
          do {
          } while (*(int *)local_70 != 0);
          LOCK();
          iVar4 = *(int *)local_70;
          *(int *)local_70 = 1;
          UNLOCK();
        } while (iVar4 == 1);
LAB_00152ec1:
        LOCK();
        *(int *)local_74 = 0;
        UNLOCK();
LAB_00152ef0:
        if (*(int *)(pcVar5 + 0x30) == 0) {
          local_5c = pcVar5 + 0x40;
        }
        else {
          local_5c = (code *)(*(int *)(pcVar5 + 0x30) + 0x10);
        }
        LOCK();
        iVar4 = *(int *)local_5c;
        *(int *)local_5c = 1;
        UNLOCK();
        if (iVar4 != 1) {
          iVar4 = *(int *)(local_5c + 8);
          if ((iVar4 == 0) || (*(int *)(local_70 + 4) != 0)) {
            LOCK();
            *(int *)local_5c = 0;
            UNLOCK();
          }
          else {
            ppcVar13[0x31] = (code *)param_1;
            ppcVar13[0x33] = param_4;
            ppcVar13[0x36] = local_74;
            ppcVar13[0x37] = local_70;
            if (*(code **)(iVar4 + 0x34) == _mach_msg_continue) {
              pppcStack_8c = (code ***)_mach_msg_continue;
              pppcStack_90 = (code ***)ppcVar13;
              ppcStack_94 = (code **)0x152fac;
              pppcStack_88 = (code ***)iVar4;
              iVar8 = _thread_handoff();
              if (iVar8 == 0) goto LAB_00152fb7;
LAB_001531b4:
              LOCK();
              *(int *)pcVar5 = 0;
              UNLOCK();
              pcVar14 = *(code **)(local_70 + 8);
              if (pcVar14 == (code *)0x0) {
                *(code ***)(local_70 + 8) = ppcVar13;
              }
              else {
                pcVar7 = *(code **)(pcVar14 + 0x94);
                ppcVar13[0x24] = pcVar14;
                ppcVar13[0x25] = pcVar7;
                *(code ***)(pcVar14 + 0x94) = ppcVar13;
                *(code ***)(pcVar7 + 0x90) = ppcVar13;
              }
              ppcVar13[0x26] = (code *)0x10004001;
              ppcVar13[0x27] = (code *)0xffffffff;
              LOCK();
              *(int *)local_70 = 0;
              UNLOCK();
              iVar8 = *(int *)(iVar4 + 0x90);
              if (iVar8 == iVar4) {
                *(int *)(local_5c + 8) = 0;
              }
              else {
                iVar2 = *(int *)(iVar4 + 0x94);
                *(int *)(local_5c + 8) = iVar8;
                *(int *)(iVar8 + 0x94) = iVar2;
                *(int *)(iVar2 + 0x90) = iVar8;
                *(int *)(iVar4 + 0x90) = iVar4;
                *(int *)(iVar4 + 0x94) = iVar4;
              }
              local_4c[9] = *(code **)(pcVar5 + 0x34);
              *(int *)(pcVar5 + 0x34) = *(int *)(pcVar5 + 0x34) + 1;
              LOCK();
              *(int *)local_5c = 0;
              UNLOCK();
              local_48 = *(code ***)(*(int *)(iVar4 + 0xc) + 0x88);
              param_1 = *(code ***)(iVar4 + 0xc4);
              param_4 = *(code **)(iVar4 + 0xcc);
              pppcStack_88 = *(code ****)(iVar4 + 0xd8);
              do {
                do {
                } while (*pppcStack_88 != (code **)0x0);
                LOCK();
                iVar4 = (int)*pppcStack_88;
                *pppcStack_88 = (code **)0x1;
                UNLOCK();
              } while (iVar4 == 1);
              iVar4 = *(int *)((int)pppcStack_88 + 4);
              *(int *)((int)pppcStack_88 + 4) = iVar4 + -1;
              LOCK();
              *pppcStack_88 = (code **)0x0;
              UNLOCK();
              if (iVar4 == 1) {
                uVar1 = *(ushort *)((int)pppcStack_88 + 10);
                goto LAB_0015329d;
              }
              goto LAB_001532b2;
            }
LAB_00152fb7:
            if (*(code **)(iVar4 + 0x34) == _exception_raise_continue) {
              pppcStack_8c = (code ***)_mach_msg_continue;
              pppcStack_90 = (code ***)ppcVar13;
              ppcStack_94 = (code **)0x152fd3;
              pppcStack_88 = (code ***)iVar4;
              iVar8 = _thread_handoff();
              if (iVar8 != 0) {
                pcVar14 = *(code **)(local_70 + 8);
                if (pcVar14 == (code *)0x0) {
                  *(code ***)(local_70 + 8) = ppcVar13;
                }
                else {
                  pcVar7 = *(code **)(pcVar14 + 0x94);
                  ppcVar13[0x24] = pcVar14;
                  ppcVar13[0x25] = pcVar7;
                  *(code ***)(pcVar14 + 0x94) = ppcVar13;
                  *(code ***)(pcVar7 + 0x90) = ppcVar13;
                }
                ppcVar13[0x26] = (code *)0x10004001;
                ppcVar13[0x27] = (code *)0xffffffff;
                LOCK();
                *(int *)local_70 = 0;
                UNLOCK();
                iVar8 = *(int *)(iVar4 + 0x90);
                if (iVar8 == iVar4) {
                  *(int *)(local_5c + 8) = 0;
                }
                else {
                  iVar2 = *(int *)(iVar4 + 0x94);
                  *(int *)(local_5c + 8) = iVar8;
                  *(int *)(iVar8 + 0x94) = iVar2;
                  *(int *)(iVar2 + 0x90) = iVar8;
                  *(int *)(iVar4 + 0x90) = iVar4;
                  *(int *)(iVar4 + 0x94) = iVar4;
                }
                LOCK();
                *(int *)local_5c = 0;
                UNLOCK();
                pppcStack_88 = (code ***)local_4c;
                pppcStack_90 = (code ***)0x15306e;
                pppcStack_8c = (code ***)pcVar5;
                _exception_raise_continue_fast();
                return 0;
              }
            }
            if (param_3 <= *(code ***)(iVar4 + 0x9c)) {
              pppcStack_8c = (code ***)_mach_msg_continue;
              pppcStack_90 = (code ***)ppcVar13;
              ppcStack_94 = (code **)0x1530b2;
              pppcStack_88 = (code ***)iVar4;
              iVar8 = _thread_handoff();
              if (iVar8 != 0) {
                if ((*(code **)(iVar4 + 0x34) != _mach_msg_receive_continue) ||
                   ((*(byte *)(iVar4 + 0xc9) & 2) != 0)) {
                  *(int *)(pcVar5 + 0x38) = *(int *)(pcVar5 + 0x38) + 1;
                  LOCK();
                  *(int *)pcVar5 = 0;
                  UNLOCK();
                  pcVar14 = *(code **)(local_70 + 8);
                  if (pcVar14 == (code *)0x0) {
                    *(code ***)(local_70 + 8) = ppcVar13;
                  }
                  else {
                    pcVar7 = *(code **)(pcVar14 + 0x94);
                    ppcVar13[0x24] = pcVar14;
                    ppcVar13[0x25] = pcVar7;
                    *(code ***)(pcVar14 + 0x94) = ppcVar13;
                    *(code ***)(pcVar7 + 0x90) = ppcVar13;
                  }
                  ppcVar13[0x26] = (code *)0x10004001;
                  ppcVar13[0x27] = (code *)0xffffffff;
                  LOCK();
                  *(int *)local_70 = 0;
                  UNLOCK();
                  iVar8 = *(int *)(iVar4 + 0x90);
                  if (iVar8 == iVar4) {
                    *(int *)(local_5c + 8) = 0;
                  }
                  else {
                    iVar2 = *(int *)(iVar4 + 0x94);
                    *(int *)(local_5c + 8) = iVar8;
                    *(int *)(iVar8 + 0x94) = iVar2;
                    *(int *)(iVar2 + 0x90) = iVar8;
                    *(int *)(iVar4 + 0x90) = iVar4;
                    *(int *)(iVar4 + 0x94) = iVar4;
                  }
                  *(undefined4 *)(iVar4 + 0x98) = 0;
                  *(code ***)(iVar4 + 0x9c) = local_4c;
                  *(int *)(iVar4 + 0xa0) = *(int *)(pcVar5 + 0x34);
                  *(int *)(pcVar5 + 0x34) = *(int *)(pcVar5 + 0x34) + 1;
                  LOCK();
                  *(int *)local_5c = 0;
                  UNLOCK();
                  *(undefined4 *)(iVar4 + 0x44) = 0;
                  pppcStack_88 = (code ***)0x153187;
                  (**(code **)(iVar4 + 0x34))();
                  return 0;
                }
                goto LAB_001531b4;
              }
            }
            LOCK();
            *(int *)local_5c = 0;
            UNLOCK();
          }
        }
        LOCK();
        *(int *)pcVar5 = 0;
        UNLOCK();
        LOCK();
        *(int *)local_70 = 0;
        UNLOCK();
        pppcStack_88 = (code ***)local_74;
        pppcStack_8c = (code ***)0x152f2b;
        _ipc_object_release();
      }
      else {
LAB_001535ec:
        pppcStack_88 = (code ***)0x0;
        pppcStack_8c = *(code ****)(_active_threads[3] + 0xc);
        ppcStack_94 = local_4c;
        ppcStack_98 = (code **)0x153607;
        pppcStack_90 = (code ***)local_48;
        iVar4 = _ipc_kmsg_copyin();
        if (iVar4 != 0) {
          pppcStack_88 = (code ***)local_4c[2];
          if ((int)pppcStack_88 < 1) {
            pppcStack_88 = (code ***)local_4c;
            pppcStack_8c = (code ***)0x153620;
            _ipc_kmsg_free();
          }
          else {
            pppcStack_8c = (code ***)local_4c;
            pppcStack_90 = (code ***)0x1535e6;
            _kfree();
          }
          pppcStack_8c = (code ***)0x153629;
          pppcStack_88 = (code ***)iVar4;
          _thread_syscall_return();
        }
        if (((byte)*(code *)((int)local_4c + 0x17) & 0x40) == 0) {
          pcVar5 = local_4c[7];
          do {
            do {
            } while (*(int *)pcVar5 != 0);
            LOCK();
            iVar4 = *(int *)pcVar5;
            *(int *)pcVar5 = 1;
            UNLOCK();
          } while (iVar4 == 1);
          if (*(int *)(pcVar5 + 0xc) == _ipc_space_kernel) goto LAB_0015365a;
          if ((*(int *)(pcVar5 + 8) < 0) &&
             ((((*(uint *)(pcVar5 + 0x38) < *(uint *)(pcVar5 + 0x3c) ||
                (*(code *)(local_4c + 5) == (code)0x12)) &&
               (local_74 = local_4c[8], local_74 != (code *)0x0)) &&
              (local_74 != (code *)0xffffffff)))) {
            LOCK();
            iVar4 = *(int *)local_74;
            *(int *)local_74 = 1;
            UNLOCK();
            if (iVar4 != 1) {
              if (((*(int *)(local_74 + 8) < 0) && (*(code ***)(local_74 + 0xc) == local_48)) &&
                 ((*(code ***)(local_74 + 0x10) == param_5 && (*(int *)(local_74 + 0x30) == 0)))) {
                *(int *)(local_74 + 4) = *(int *)(local_74 + 4) + 1;
                local_70 = local_74 + 0x40;
                do {
                  do {
                  } while (*(int *)local_70 != 0);
                  LOCK();
                  iVar4 = *(int *)local_70;
                  *(int *)local_70 = 1;
                  UNLOCK();
                } while (iVar4 == 1);
                LOCK();
                *(int *)local_74 = 0;
                UNLOCK();
                goto LAB_00152ef0;
              }
              LOCK();
              *(int *)local_74 = 0;
              UNLOCK();
            }
          }
          LOCK();
          *(int *)pcVar5 = 0;
          UNLOCK();
        }
      }
LAB_001537e0:
      pppcStack_88 = (code ***)0x0;
      pppcStack_8c = (code ***)0x0;
      pppcStack_90 = (code ***)0x0;
      ppcStack_94 = local_4c;
      ppcStack_98 = (code **)0x1537ef;
      uVar10 = _ipc_mqueue_send();
      if (uVar10 != 0) {
        pppcStack_88 = *(code ****)(_active_threads[3] + 0xc);
        pppcStack_90 = (code ***)local_4c;
        ppcStack_94 = (code **)0x15380e;
        pppcStack_8c = (code ***)local_48;
        uVar11 = _ipc_kmsg_copyout_pseudo();
        ppcStack_94 = (code **)(local_4c[6] + (int)local_4c[4]);
        ppcStack_98 = local_4c;
        _ipc_kmsg_put(param_1);
        _thread_syscall_return(uVar10 | uVar11);
      }
LAB_0015382d:
      pppcStack_88 = (code ***)&local_10;
      pppcStack_8c = (code ***)&local_c;
      pppcStack_90 = (code ***)param_5;
      ppcStack_98 = (code **)0x153842;
      ppcStack_94 = local_48;
      pppcStack_88 = (code ***)_ipc_mqueue_copyin();
      if (pppcStack_88 != (code ***)0x0) {
        pppcStack_8c = (code ***)0x153851;
        _thread_syscall_return();
      }
      ppcVar13[0x31] = (code *)param_1;
      ppcVar13[0x33] = param_4;
      ppcVar13[0x36] = local_10;
      ppcVar13[0x37] = local_c;
      pppcStack_88 = (code ***)&local_14;
      pppcStack_8c = &local_8;
      pppcStack_90 = (code ***)_mach_msg_continue;
      ppcStack_94 = (code **)0x0;
      ppcStack_98 = (code **)0x0;
      iVar4 = _ipc_mqueue_receive(local_c,0,0xffffffff);
      pppcStack_88 = (code ***)local_10;
      pppcStack_8c = (code ***)0x1538b0;
      _ipc_object_release();
      if (iVar4 != 0) {
        pppcStack_8c = (code ***)0x1538bd;
        pppcStack_88 = (code ***)iVar4;
        _thread_syscall_return();
      }
      local_4c = local_8;
      local_8[9] = local_14;
      pcVar5 = local_8[7];
    }
    else {
      if ((local_4c[5] != (code *)0x1513) || ((code **)local_4c[8] != param_5)) goto LAB_001535ec;
      ppcVar12 = local_48 + 2;
      do {
        do {
        } while (*ppcVar12 != (code *)0x0);
        LOCK();
        pcVar5 = *ppcVar12;
        *ppcVar12 = (code *)0x1;
        UNLOCK();
      } while (pcVar5 == (code *)0x1);
      if ((local_48[6] <= (code *)((uint)param_5 >> 8)) ||
         (pcVar5 = local_48[5] + (int)((uint)param_5 >> 8) * 0x10,
         (*(uint *)pcVar5 & 0xff020000) != ((int)param_5 << 0x18 | 0x20000U))) {
LAB_00152ecc:
        LOCK();
        local_48[2] = (code *)0x0;
        UNLOCK();
        goto LAB_001535ec;
      }
      local_74 = *(code **)(pcVar5 + 4);
      pcVar5 = (code *)((uint)local_4c[7] >> 8);
      if ((local_48[6] <= pcVar5) ||
         (pcVar5 = local_48[5] + (int)pcVar5 * 0x10,
         (*(uint *)pcVar5 & 0xff010000) != ((int)local_4c[7] << 0x18 | 0x10000U)))
      goto LAB_00152ecc;
      pcVar5 = *(code **)(pcVar5 + 4);
      do {
        do {
        } while (*(int *)pcVar5 != 0);
        LOCK();
        iVar4 = *(int *)pcVar5;
        *(int *)pcVar5 = 1;
        UNLOCK();
      } while (iVar4 == 1);
      if (-1 < *(int *)(pcVar5 + 8)) {
LAB_00152dca:
        LOCK();
        *(int *)pcVar5 = 0;
        UNLOCK();
        goto LAB_00152ecc;
      }
      LOCK();
      iVar4 = *(int *)local_74;
      *(int *)local_74 = 1;
      UNLOCK();
      if (iVar4 == 1) goto LAB_00152dca;
      LOCK();
      local_48[2] = (code *)0x0;
      UNLOCK();
      *(int *)(pcVar5 + 0x1c) = *(int *)(pcVar5 + 0x1c) + 1;
      *(int *)(pcVar5 + 4) = *(int *)(pcVar5 + 4) + 1;
      *(int *)(local_74 + 0x20) = *(int *)(local_74 + 0x20) + 1;
      *(int *)(local_74 + 4) = *(int *)(local_74 + 4) + 1;
      local_4c[5] = (code *)0x1211;
      local_4c[7] = pcVar5;
      local_4c[8] = local_74;
      if (*(int *)(pcVar5 + 0xc) != _ipc_space_kernel) {
        if ((*(uint *)(pcVar5 + 0x38) < *(uint *)(pcVar5 + 0x3c)) &&
           (*(int *)(local_74 + 0x30) == 0)) {
          *(int *)(local_74 + 4) = *(int *)(local_74 + 4) + 1;
          local_70 = local_74 + 0x40;
          do {
            do {
            } while (*(int *)local_70 != 0);
            LOCK();
            iVar4 = *(int *)local_70;
            *(int *)local_70 = 1;
            UNLOCK();
          } while (iVar4 == 1);
          goto LAB_00152ec1;
        }
        LOCK();
        *(int *)pcVar5 = 0;
        UNLOCK();
        LOCK();
        *(int *)local_74 = 0;
        UNLOCK();
        goto LAB_001537e0;
      }
      LOCK();
      *(int *)local_74 = 0;
      UNLOCK();
LAB_0015365a:
      LOCK();
      *(int *)pcVar5 = 0;
      UNLOCK();
      pppcStack_88 = (code ***)local_4c;
      pppcStack_8c = (code ***)0x153709;
      local_4c = (code **)_ipc_kobject_server();
      if (local_4c == (code **)0x0) goto LAB_0015382d;
      pcVar5 = local_4c[7];
      do {
        do {
        } while (*(int *)pcVar5 != 0);
        LOCK();
        iVar4 = *(int *)pcVar5;
        *(int *)pcVar5 = 1;
        UNLOCK();
      } while (iVar4 == 1);
      if (((-1 < *(int *)(pcVar5 + 8)) || (*(code ***)(pcVar5 + 0xc) != local_48)) ||
         ((*(code ***)(pcVar5 + 0x10) != param_5 || (*(int *)(pcVar5 + 0x30) != 0)))) {
        LOCK();
        *(int *)pcVar5 = 0;
        UNLOCK();
LAB_001537a6:
        pppcStack_88 = (code ***)0x0;
        pppcStack_8c = (code ***)0x0;
        pppcStack_90 = (code ***)0x10000;
        ppcStack_98 = (code **)0x1537ab;
        ppcStack_94 = local_4c;
        _ipc_mqueue_send();
        goto LAB_0015382d;
      }
      pcVar14 = pcVar5 + 0x40;
      do {
        do {
        } while (*(int *)pcVar14 != 0);
        LOCK();
        iVar4 = *(int *)pcVar14;
        *(int *)pcVar14 = 1;
        UNLOCK();
      } while (iVar4 == 1);
      if ((*(int *)(pcVar5 + 0x48) != 0) || (*(int *)(pcVar5 + 0x44) != 0)) {
        LOCK();
        *(int *)pcVar14 = 0;
        UNLOCK();
        LOCK();
        *(int *)pcVar5 = 0;
        UNLOCK();
        goto LAB_001537a6;
      }
      local_4c[9] = *(code **)(pcVar5 + 0x34);
      *(int *)(pcVar5 + 0x34) = *(int *)(pcVar5 + 0x34) + 1;
      LOCK();
      *(int *)pcVar14 = 0;
      UNLOCK();
      LOCK();
      *(int *)pcVar5 = 0;
      UNLOCK();
      if (*(int *)(pcVar5 + 4) == 0) {
        uVar1 = *(ushort *)(pcVar5 + 10);
        pppcStack_88 = (code ***)pcVar5;
LAB_0015329d:
        pppcStack_8c = (code ***)(&_ipc_object_zones)[uVar1 & 0x7fff];
        pppcStack_90 = (code ***)0x1532af;
        _zfree();
      }
    }
LAB_001532b2:
    local_50 = local_4c[6] + (int)local_4c[4];
    if (param_4 < local_50) {
LAB_001538d4:
      local_50 = local_4c[6] + (int)local_4c[4];
      if (param_4 < local_50) {
        pppcStack_88 = (code ***)local_48;
        pppcStack_8c = (code ***)local_4c;
        pppcStack_90 = (code ***)0x1538f2;
        _ipc_kmsg_copyout_dest();
        pppcStack_90 = (code ***)0x18;
        ppcStack_94 = local_4c;
        ppcStack_98 = param_1;
        _ipc_kmsg_put();
        _thread_syscall_return(0x10004004);
      }
      pppcStack_88 = (code ***)0x0;
      pppcStack_8c = *(code ****)(_active_threads[3] + 0xc);
      pppcStack_90 = (code ***)local_48;
      ppcStack_94 = local_4c;
      ppcStack_98 = (code **)0x153929;
      uVar10 = _ipc_kmsg_copyout();
      if (uVar10 != 0) {
        if ((uVar10 & 0xffffc3ff) == 0x1000400c) {
          pppcStack_88 = (code ***)(local_4c[6] + (int)local_4c[4]);
          pppcStack_8c = (code ***)local_4c;
          pppcStack_90 = (code ***)param_1;
          ppcStack_94 = (code **)0x153957;
          _ipc_kmsg_put();
        }
        else {
          pppcStack_88 = (code ***)local_48;
          pppcStack_8c = (code ***)local_4c;
          pppcStack_90 = (code ***)0x153969;
          _ipc_kmsg_copyout_dest();
          pppcStack_90 = (code ***)0x18;
          ppcStack_94 = local_4c;
          ppcStack_98 = param_1;
          _ipc_kmsg_put();
        }
        pppcStack_8c = (code ***)0x15397e;
        pppcStack_88 = (code ***)uVar10;
        _thread_syscall_return();
      }
    }
    else {
      pcVar14 = local_4c[5];
      if (pcVar14 == (code *)0x1211) {
        pcVar14 = local_4c[8];
        if ((pcVar14 != (code *)0x0) && (pcVar14 != (code *)0xffffffff)) {
          ppcVar13 = local_48 + 2;
          do {
            do {
            } while (*ppcVar13 != (code *)0x0);
            LOCK();
            pcVar7 = *ppcVar13;
            *ppcVar13 = (code *)0x1;
            UNLOCK();
          } while (pcVar7 == (code *)0x1);
          do {
            do {
            } while (*(int *)pcVar5 != 0);
            LOCK();
            iVar4 = *(int *)pcVar5;
            *(int *)pcVar5 = 1;
            UNLOCK();
          } while (iVar4 == 1);
          if (*(int *)(pcVar5 + 8) < 0) {
            LOCK();
            iVar4 = *(int *)pcVar14;
            *(int *)pcVar14 = 1;
            UNLOCK();
            if (iVar4 != 1) {
              if (*(int *)(pcVar14 + 8) < 0) {
                LOCK();
                *(int *)pcVar14 = 0;
                UNLOCK();
                pcVar7 = local_48[5];
                iVar4 = *(int *)(pcVar7 + 8);
                if (iVar4 != 0) {
                  pcVar9 = pcVar7 + iVar4 * 0x10;
                  *(uint *)(pcVar7 + 8) = *(uint *)(pcVar9 + 8);
                  *(uint *)(pcVar9 + 8) = 0;
                  uVar10 = *(uint *)pcVar9;
                  *(uint *)pcVar9 = uVar10 + 0x1000000 | 0x40001;
                  *(code **)(pcVar9 + 4) = pcVar14;
                  LOCK();
                  local_48[2] = (code *)0x0;
                  UNLOCK();
                  *(int *)(pcVar5 + 4) = *(int *)(pcVar5 + 4) + -1;
                  pcVar14 = (code *)0x0;
                  if (*(code ***)(pcVar5 + 0xc) == local_48) {
                    pcVar14 = *(code **)(pcVar5 + 0x10);
                  }
                  iVar8 = *(int *)(pcVar5 + 0x1c);
                  *(int *)(pcVar5 + 0x1c) = iVar8 + -1;
                  if ((iVar8 == 1) &&
                     (pppcStack_8c = *(code ****)(pcVar5 + 0x24), pppcStack_8c != (code ***)0x0)) {
                    pppcStack_88 = *(code ****)(pcVar5 + 0x18);
                    *(int *)(pcVar5 + 0x24) = 0;
                    LOCK();
                    *(int *)pcVar5 = 0;
                    UNLOCK();
                    pppcStack_90 = (code ***)0x153400;
                    _ipc_notify_no_senders();
                  }
                  else {
                    LOCK();
                    *(int *)pcVar5 = 0;
                    UNLOCK();
                  }
                  local_4c[5] = (code *)0x1112;
                  local_4c[7] = (code *)(uVar10 + 0x1000000 >> 0x18 | iVar4 << 8);
                  local_4c[8] = pcVar14;
                  goto LAB_00153544;
                }
              }
              else {
                LOCK();
                *(int *)pcVar14 = 0;
                UNLOCK();
              }
            }
          }
          LOCK();
          *(int *)pcVar5 = 0;
          UNLOCK();
          LOCK();
          local_48[2] = (code *)0x0;
          UNLOCK();
        }
        goto LAB_001538d4;
      }
      pppcStack_88 = (code ***)pcVar5;
      if ((code *)0x1211 < pcVar14) {
        if (pcVar14 == (code *)0x80000012) {
          do {
            do {
            } while (*(int *)pcVar5 != 0);
            LOCK();
            iVar4 = *(int *)pcVar5;
            *(int *)pcVar5 = 1;
            UNLOCK();
          } while (iVar4 == 1);
          if (*(int *)(pcVar5 + 8) < 0) {
            if (*(code ***)(pcVar5 + 0xc) == local_48) {
              *(int *)(pcVar5 + 4) = *(int *)(pcVar5 + 4) + -1;
              *(int *)(pcVar5 + 0x20) = *(int *)(pcVar5 + 0x20) + -1;
              pcVar14 = *(code **)(pcVar5 + 0x10);
              LOCK();
              *(int *)pcVar5 = 0;
              UNLOCK();
            }
            else {
              LOCK();
              *(int *)pcVar5 = 0;
              UNLOCK();
              pppcStack_8c = (code ***)0x1534da;
              _ipc_notify_send_once();
              pcVar14 = (code *)0x0;
            }
            local_4c[5] = (code *)0x80001200;
            local_4c[7] = (code *)0x0;
            local_4c[8] = pcVar14;
            pppcStack_88 = *(code ****)(_active_threads[3] + 0xc);
            pppcStack_8c = (code ***)local_48;
            pppcStack_90 = (code ***)((int)local_4c + (int)(local_4c[6] + 0x14));
            ppcStack_94 = local_4c + 0xb;
            ppcStack_98 = (code **)0x153518;
            uVar10 = _ipc_kmsg_copyout_body();
            if (uVar10 != 0) {
              pppcStack_88 = (code ***)(local_4c[6] + (int)local_4c[4]);
              pppcStack_8c = (code ***)local_4c;
              pppcStack_90 = (code ***)param_1;
              ppcStack_94 = (code **)0x153535;
              _ipc_kmsg_put();
              return uVar10 | 0x1000400c;
            }
            goto LAB_00153544;
          }
        }
        goto LAB_001538d4;
      }
      if (pcVar14 != (code *)0x12) goto LAB_001538d4;
      do {
        do {
        } while (*(int *)pcVar5 != 0);
        LOCK();
        iVar4 = *(int *)pcVar5;
        *(int *)pcVar5 = 1;
        UNLOCK();
      } while (iVar4 == 1);
      if (-1 < *(int *)(pcVar5 + 8)) goto LAB_001538d4;
      if (*(code ***)(pcVar5 + 0xc) == local_48) {
        *(int *)(pcVar5 + 4) = *(int *)(pcVar5 + 4) + -1;
        *(int *)(pcVar5 + 0x20) = *(int *)(pcVar5 + 0x20) + -1;
        pcVar14 = *(code **)(pcVar5 + 0x10);
        LOCK();
        *(int *)pcVar5 = 0;
        UNLOCK();
      }
      else {
        LOCK();
        *(int *)pcVar5 = 0;
        UNLOCK();
        pppcStack_8c = (code ***)0x15347a;
        _ipc_notify_send_once();
        pcVar14 = (code *)0x0;
      }
      local_4c[5] = (code *)0x1200;
      local_4c[7] = (code *)0x0;
      local_4c[8] = pcVar14;
    }
LAB_00153544:
    local_4c[4] = (code *)0x0;
    if (local_4c[2] == (code *)0x100) {
      pppcStack_88 = (code ***)local_50;
      pppcStack_8c = (code ***)param_1;
      pppcStack_90 = (code ***)(local_4c + 5);
      ppcStack_94 = (code **)0x15356f;
      iVar4 = _copyoutmsg();
      if ((iVar4 == 0) && (_ipc_kmsg_cache == (code **)0x0)) {
        _ipc_kmsg_cache = local_4c;
        pppcStack_88 = (code ***)0x0;
        pppcStack_8c = (code ***)0x153597;
        _thread_syscall_return();
        return 0;
      }
    }
    pppcStack_88 = (code ***)local_50;
    pppcStack_8c = (code ***)local_4c;
    pppcStack_90 = (code ***)param_1;
    ppcStack_94 = (code **)0x153999;
    ppcStack_94 = (code **)_ipc_kmsg_put();
    ppcStack_98 = (code **)0x1539a1;
    _thread_syscall_return();
  }
  else {
    if (param_2 == (code *)0x1) {
      ppcVar13 = *(code ***)(_active_threads[3] + 0x88);
      ppcVar12 = *(code ***)(_active_threads[3] + 0xc);
      pppcStack_88 = &local_18;
      pppcStack_8c = (code ***)0x0;
      pppcStack_90 = (code ***)param_3;
      ppcStack_94 = param_1;
      ppcStack_98 = (code **)0x1539dd;
      uVar10 = _ipc_kmsg_get();
      if (uVar10 != 0) {
        return uVar10;
      }
      pppcStack_88 = (code ***)0x0;
      ppcStack_94 = local_18;
      ppcStack_98 = (code **)0x153a08;
      pppcStack_90 = (code ***)ppcVar13;
      pppcStack_8c = (code ***)ppcVar12;
      uVar10 = _ipc_kmsg_copyin();
      if (uVar10 != 0) {
        pppcStack_88 = (code ***)local_18[2];
        if (0 < (int)pppcStack_88) {
          pppcStack_8c = (code ***)local_18;
          pppcStack_90 = (code ***)0x1539f3;
          _kfree();
          return uVar10;
        }
        pppcStack_88 = (code ***)local_18;
        pppcStack_8c = (code ***)0x153a21;
        _ipc_kmsg_free();
        return uVar10;
      }
      pppcStack_88 = (code ***)0x0;
      pppcStack_8c = (code ***)0x0;
      pppcStack_90 = (code ***)0x0;
      ppcStack_94 = local_18;
      ppcStack_98 = (code **)0x153a37;
      uVar10 = _ipc_mqueue_send();
      if (uVar10 == 0) {
        return 0;
      }
      pppcStack_90 = (code ***)local_18;
      ppcStack_94 = (code **)0x153a52;
      pppcStack_8c = (code ***)ppcVar13;
      pppcStack_88 = (code ***)ppcVar12;
      uVar11 = _ipc_kmsg_copyout_pseudo();
      uVar10 = uVar10 | uVar11;
      ppcStack_94 = (code **)(local_18[6] + (int)local_18[4]);
      pppcVar15 = &ppcStack_98;
      ppcStack_98 = local_18;
LAB_00153b74:
      pppcVar16 = (code ***)((int)pppcVar15 + -4);
      *(code ***)((int)pppcVar15 + -4) = param_1;
LAB_00153b78:
      *(undefined4 *)((int)pppcVar16 + -4) = 0x153b7d;
      _ipc_kmsg_put();
      return uVar10;
    }
    if (param_2 == (code *)0x2) {
      ppcVar12 = *(code ***)(_active_threads[3] + 0x88);
      uVar3 = *(undefined4 *)(_active_threads[3] + 0xc);
      pppcStack_88 = (code ***)&local_20;
      pppcStack_8c = (code ***)&local_1c;
      pppcStack_90 = (code ***)param_5;
      ppcStack_98 = (code **)0x153a98;
      ppcStack_94 = ppcVar12;
      uVar10 = _ipc_mqueue_copyin();
      if (uVar10 != 0) {
        return uVar10;
      }
      ppcVar13[0x31] = (code *)param_1;
      ppcVar13[0x33] = param_4;
      ppcVar13[0x36] = local_20;
      ppcVar13[0x37] = local_1c;
      pppcStack_88 = (code ***)&local_28;
      pppcStack_8c = &local_24;
      pppcStack_90 = (code ***)_mach_msg_continue;
      ppcStack_94 = (code **)0x0;
      ppcStack_98 = (code **)0x0;
      uVar10 = _ipc_mqueue_receive(local_1c,0,0xffffffff);
      pppcStack_88 = (code ***)local_20;
      pppcStack_8c = (code ***)0x153af8;
      _ipc_object_release();
      if (uVar10 != 0) {
        return uVar10;
      }
      local_24[9] = local_28;
      if (param_4 < local_24[6]) {
        pppcStack_8c = (code ***)local_24;
        pppcStack_90 = (code ***)0x153b17;
        pppcStack_88 = (code ***)ppcVar12;
        _ipc_kmsg_copyout_dest();
        pppcStack_90 = (code ***)0x18;
        ppcStack_94 = local_24;
        ppcStack_98 = param_1;
        _ipc_kmsg_put();
        return 0x10004004;
      }
      pppcStack_88 = (code ***)0x0;
      ppcStack_94 = local_24;
      ppcStack_98 = (code **)0x153b3d;
      pppcStack_90 = (code ***)ppcVar12;
      pppcStack_8c = (code ***)uVar3;
      uVar10 = _ipc_kmsg_copyout();
      if (uVar10 == 0) {
        pppcStack_88 = (code ***)(local_24[6] + (int)local_24[4]);
        pppcStack_8c = (code ***)local_24;
        pppcStack_90 = (code ***)param_1;
        ppcStack_94 = (code **)0x153b98;
        uVar10 = _ipc_kmsg_put();
        return uVar10;
      }
      if ((uVar10 & 0xffffc3ff) == 0x1000400c) {
        pppcStack_88 = (code ***)(local_24[6] + (int)local_24[4]);
        pppcStack_8c = (code ***)local_24;
        pppcVar16 = (code ***)&pppcStack_90;
        pppcStack_90 = (code ***)param_1;
        goto LAB_00153b78;
      }
      pppcStack_8c = (code ***)local_24;
      pppcStack_90 = (code ***)0x153b6e;
      pppcStack_88 = (code ***)ppcVar12;
      _ipc_kmsg_copyout_dest();
      pppcStack_90 = (code ***)0x18;
      pppcVar15 = &ppcStack_94;
      ppcStack_94 = local_24;
      goto LAB_00153b74;
    }
    if (param_2 == (code *)0x0) {
      pppcStack_88 = (code ***)0x0;
      pppcStack_8c = (code ***)0x153bad;
      _thread_syscall_return();
    }
  }
  if (((uint)param_2 & 1) != 0) {
    ppcVar13 = *(code ***)(_active_threads[3] + 0x88);
    uVar3 = *(undefined4 *)(_active_threads[3] + 0xc);
    pppcStack_88 = &local_2c;
    pppcStack_8c = (code ***)0x0;
    pppcStack_90 = (code ***)param_3;
    ppcStack_94 = param_1;
    ppcStack_98 = (code **)0x153be3;
    uVar10 = _ipc_kmsg_get();
    if (uVar10 == 0) {
      if ((char)param_2 < '\0') {
        if (param_7 != (code *)0x0) {
          pppcStack_88 = (code ***)param_7;
          goto LAB_00153c1e;
        }
        uVar10 = 0x1000000b;
      }
      else {
        pppcStack_88 = (code ***)0x0;
LAB_00153c1e:
        ppcStack_94 = local_2c;
        ppcStack_98 = (code **)0x153c2c;
        pppcStack_90 = (code ***)ppcVar13;
        pppcStack_8c = (code ***)uVar3;
        uVar10 = _ipc_kmsg_copyin();
        if (uVar10 == 0) {
          if (((uint)param_2 & 0x20) == 0) {
            pppcStack_88 = (code ***)0x0;
            pppcStack_8c = (code ***)param_6;
            pppcStack_90 = (code ***)((uint)param_2 & 0x10);
            ppcStack_94 = local_2c;
            ppcStack_98 = (code **)0x153cde;
            uVar11 = _ipc_mqueue_send();
LAB_00153ce3:
            uVar10 = 0;
            if (uVar11 == 0) goto LAB_00153d0e;
          }
          else {
            pppcStack_88 = (code ***)0x0;
            pppcStack_8c = (code ***)(code **)0x0;
            if (((uint)param_2 & 0x10) != 0) {
              pppcStack_8c = (code ***)param_6;
            }
            pppcStack_90 = (code ***)0x10;
            ppcStack_94 = local_2c;
            ppcStack_98 = (code **)0x153c70;
            uVar11 = _ipc_mqueue_send();
            if (uVar11 != 0x10000004) goto LAB_00153ce3;
            pppcStack_90 = (code ***)local_2c[7];
            if (param_7 == (code *)0x0) {
              uVar11 = 0x1000000b;
            }
            else {
              pppcStack_88 = (code ***)(local_2c + 3);
              pppcStack_8c = (code ***)param_7;
              ppcStack_98 = (code **)0x153c9b;
              ppcStack_94 = ppcVar13;
              uVar11 = _ipc_marequest_create();
              if (uVar11 == 0) {
                pppcStack_88 = (code ***)0x0;
                pppcStack_8c = (code ***)0x0;
                pppcStack_90 = (code ***)0x10000;
                ppcStack_94 = local_2c;
                ppcStack_98 = (code **)0x153cb6;
                _ipc_mqueue_send();
                return 0x10000005;
              }
            }
          }
          pppcStack_90 = (code ***)local_2c;
          ppcStack_94 = (code **)0x153cf5;
          pppcStack_8c = (code ***)ppcVar13;
          pppcStack_88 = (code ***)uVar3;
          uVar10 = _ipc_kmsg_copyout_pseudo();
          uVar10 = uVar11 | uVar10;
          ppcStack_94 = (code **)(local_2c[6] + (int)local_2c[4]);
          ppcStack_98 = local_2c;
          _ipc_kmsg_put(param_1);
          goto LAB_00153d0e;
        }
      }
      pppcStack_88 = (code ***)local_2c[2];
      if ((int)pppcStack_88 < 1) {
        pppcStack_88 = (code ***)local_2c;
        pppcStack_8c = (code ***)0x153c45;
        _ipc_kmsg_free();
      }
      else {
        pppcStack_8c = (code ***)local_2c;
        pppcStack_90 = (code ***)0x153c13;
        _kfree();
      }
    }
LAB_00153d0e:
    if (uVar10 != 0) {
      return uVar10;
    }
  }
  ppcVar13 = _active_threads;
  if (((uint)param_2 & 2) == 0) {
    return 0;
  }
  ppcVar12 = *(code ***)(_active_threads[3] + 0x88);
  uVar3 = *(undefined4 *)(_active_threads[3] + 0xc);
  pppcStack_88 = (code ***)&local_34;
  pppcStack_8c = (code ***)&local_30;
  pppcStack_90 = (code ***)param_5;
  ppcStack_98 = (code **)0x153d49;
  ppcStack_94 = ppcVar12;
  local_74 = (code *)_ipc_mqueue_copyin();
  if (local_74 != (code *)0x0) goto LAB_00153f1e;
  ppcVar13[0x31] = (code *)param_1;
  ppcVar13[0x32] = param_2;
  ppcVar13[0x33] = param_4;
  ppcVar13[0x34] = (code *)param_6;
  ppcVar13[0x35] = param_7;
  ppcVar13[0x36] = local_34;
  ppcVar13[0x37] = local_30;
  if (((uint)param_2 & 0x800) == 0) {
    pppcStack_88 = (code ***)&local_3c;
    pppcStack_8c = &local_38;
    pppcStack_90 = (code ***)_mach_msg_receive_continue;
    ppcStack_94 = (code **)0x0;
    ppcStack_98 = param_6;
    local_74 = (code *)_ipc_mqueue_receive(local_30,(uint)param_2 & 0x100,0xffffffff);
    pppcStack_88 = (code ***)local_34;
    pppcStack_8c = (code ***)0x153e4e;
    _ipc_object_release();
    if (local_74 != (code *)0x0) goto LAB_00153f1e;
    local_38[9] = local_3c;
    if (param_4 < local_38[6]) {
      pppcStack_8c = (code ***)local_38;
      pppcStack_90 = (code ***)0x153e73;
      pppcStack_88 = (code ***)ppcVar12;
      _ipc_kmsg_copyout_dest();
      pppcStack_90 = (code ***)0x18;
      ppcStack_94 = local_38;
      ppcStack_98 = param_1;
      _ipc_kmsg_put();
      return 0x10004004;
    }
  }
  else {
    pppcStack_88 = (code ***)&local_3c;
    pppcStack_8c = &local_38;
    pppcStack_90 = (code ***)_mach_msg_receive_continue;
    ppcStack_94 = (code **)0x0;
    ppcStack_98 = param_6;
    local_74 = (code *)_ipc_mqueue_receive(local_30,(uint)param_2 & 0x100,param_4);
    pppcStack_88 = (code ***)local_34;
    pppcStack_8c = (code ***)0x153dd6;
    _ipc_object_release();
    if (local_74 != (code *)0x0) {
      if (local_74 == (code *)0x10004004) {
        local_40 = local_38;
        pppcStack_88 = (code ***)0x4;
        pppcStack_8c = (code ***)(param_1 + 1);
        pppcStack_90 = &local_40;
        ppcStack_94 = (code **)0x153e04;
        _copyout();
      }
      goto LAB_00153f1e;
    }
    local_38[9] = local_3c;
  }
  if (((uint)param_2 & 0x200) == 0) {
    pppcStack_88 = (code ***)0x0;
LAB_00153eae:
    ppcStack_94 = local_38;
    ppcStack_98 = (code **)0x153ebc;
    pppcStack_90 = (code ***)ppcVar12;
    pppcStack_8c = (code ***)uVar3;
    local_74 = (code *)_ipc_kmsg_copyout();
    if (local_74 == (code *)0x0) {
      pppcStack_88 = (code ***)(local_38[6] + (int)local_38[4]);
      pppcStack_8c = (code ***)local_38;
      pppcStack_90 = (code ***)param_1;
      ppcStack_94 = (code **)0x153f1c;
      local_74 = (code *)_ipc_kmsg_put();
      goto LAB_00153f1e;
    }
  }
  else {
    if (param_7 != (code *)0x0) {
      pppcStack_88 = (code ***)param_7;
      goto LAB_00153eae;
    }
    local_74 = (code *)0x10004007;
  }
  if (((uint)local_74 & 0xffffc3ff) == 0x1000400c) {
    pppcStack_88 = (code ***)(local_38[6] + (int)local_38[4]);
    pppcStack_8c = (code ***)local_38;
    pppcVar17 = (code ***)&pppcStack_90;
    pppcStack_90 = (code ***)param_1;
  }
  else {
    pppcStack_8c = (code ***)local_38;
    pppcStack_90 = (code ***)0x153ef2;
    pppcStack_88 = (code ***)ppcVar12;
    _ipc_kmsg_copyout_dest();
    pppcStack_90 = (code ***)0x18;
    ppcStack_94 = local_38;
    pppcVar17 = &ppcStack_98;
    ppcStack_98 = param_1;
  }
  *(undefined4 *)((int)pppcVar17 + -4) = 0x153f01;
  _ipc_kmsg_put();
LAB_00153f1e:
  if (local_74 == (code *)0x0) {
    return 0;
  }
  return (uint)local_74;
}

