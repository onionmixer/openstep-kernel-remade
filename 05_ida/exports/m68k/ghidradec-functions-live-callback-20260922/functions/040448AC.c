
/* WARNING: Type propagation algorithm not settling */

uint _mach_msg_trap(code ***param_1,code ***param_2,code ***param_3,code ***param_4,code **param_5,
                   code ***param_6,undefined4 param_7)

{
  code **ppcVar1;
  code *pcVar2;
  code *pcVar3;
  word wVar4;
  int iVar5;
  code **ppcVar6;
  code ***pppcVar7;
  uint uVar8;
  uint uVar9;
  code **ppcVar10;
  code **ppcVar11;
  code ***pppcVar12;
  code ***pppcVar13;
  code ***pppcVar14;
  code ***pppcVar15;
  code ****ppppcVar16;
  code ***pppcStack_64;
  code ***pppcStack_60;
  code ****ppppcStack_5c;
  code ****ppppcStack_58;
  code **ppcStack_28;
  code ***pppcStack_24;
  code **ppcStack_20;
  code **ppcStack_1c;
  code ***pppcStack_18;
  code **ppcStack_14;
  code **ppcStack_10;
  code **ppcStack_c;
  code ***pppcStack_8;
  
  pppcVar7 = _ipc_kmsg_cache;
  pppcVar13 = _active_threads;
  if (param_2 != (code ***)0x3) {
    if (param_2 == (code ***)0x1) {
      pppcVar13 = (code ***)_active_threads[3][0x1f];
      pppcVar7 = (code ***)_active_threads[3][2];
      ppppcStack_58 = &pppcStack_18;
      ppppcStack_5c = (code ****)0x0;
      pppcStack_60 = param_3;
      pppcStack_64 = param_1;
      uVar9 = _ipc_kmsg_get();
      if (uVar9 != 0) {
        return uVar9;
      }
      ppppcStack_58 = (code ****)0x0;
      pppcStack_64 = pppcStack_18;
      pppcStack_60 = pppcVar13;
      ppppcStack_5c = (code ****)pppcVar7;
      uVar9 = _ipc_kmsg_copyin();
      if (uVar9 == 0) {
        ppppcStack_58 = (code ****)0x0;
        ppppcStack_5c = (code ****)0x0;
        pppcStack_60 = (code ***)0x0;
        pppcStack_64 = pppcStack_18;
        uVar9 = _ipc_mqueue_send();
        if (uVar9 != 0) {
          pppcStack_60 = pppcStack_18;
          pppcStack_64 = (code ***)0x4045300;
          ppppcStack_5c = (code ****)pppcVar13;
          ppppcStack_58 = (code ****)pppcVar7;
          uVar8 = _ipc_kmsg_copyout_pseudo();
          pppcStack_64 = (code ***)((int)pppcStack_18[4] + (int)pppcStack_18[6]);
          _ipc_kmsg_put(param_1,pppcStack_18);
          return uVar8 | uVar9;
        }
        return 0;
      }
      ppppcStack_58 = (code ****)pppcStack_18[2];
      if (0 < (int)ppppcStack_58) {
        ppppcStack_5c = (code ****)pppcStack_18;
        pppcStack_60 = (code ***)0x40452a6;
        _kfree();
        return uVar9;
      }
      ppppcStack_58 = (code ****)pppcStack_18;
      ppppcStack_5c = (code ****)0x40452d4;
      _ipc_kmsg_free();
      return uVar9;
    }
    if (param_2 == (code ***)0x2) {
      pppcVar7 = (code ***)_active_threads[3][0x1f];
      pppcVar14 = (code ***)_active_threads[3][2];
      ppppcStack_58 = (code ****)&ppcStack_20;
      ppppcStack_5c = (code ****)&ppcStack_1c;
      pppcStack_60 = (code ***)param_5;
      pppcStack_64 = pppcVar7;
      uVar9 = _ipc_mqueue_copyin();
      if (uVar9 != 0) {
        return uVar9;
      }
      pppcVar13[0x2f] = (code **)param_1;
      pppcVar13[0x31] = (code **)param_4;
      pppcVar13[0x34] = ppcStack_20;
      pppcVar13[0x35] = ppcStack_1c;
      ppppcStack_58 = (code ****)&ppcStack_28;
      ppppcStack_5c = &pppcStack_24;
      pppcStack_60 = (code ***)_mach_msg_continue;
      pppcStack_64 = (code ***)0x0;
      uVar9 = _ipc_mqueue_receive(ppcStack_1c,0,0xffffffff,0);
      ppppcStack_58 = (code ****)ppcStack_20;
      ppppcStack_5c = (code ****)0x40453a2;
      _ipc_object_release();
      if (uVar9 != 0) {
        return uVar9;
      }
      pppcStack_24[9] = ppcStack_28;
      if (param_4 < pppcStack_24[6]) {
        ppppcStack_5c = (code ****)pppcStack_24;
        pppcStack_60 = (code ***)0x40453cc;
        ppppcStack_58 = (code ****)pppcVar7;
        _ipc_kmsg_copyout_dest();
        pppcStack_60 = (code ***)0x18;
        pppcStack_64 = pppcStack_24;
        _ipc_kmsg_put(param_1);
        return 0x10004004;
      }
      ppppcStack_58 = (code ****)0x0;
      pppcStack_64 = pppcStack_24;
      pppcStack_60 = pppcVar7;
      ppppcStack_5c = (code ****)pppcVar14;
      uVar9 = _ipc_kmsg_copyout();
      if (uVar9 == 0) {
        ppppcStack_58 = (code ****)((int)pppcStack_24[4] + (int)pppcStack_24[6]);
        ppppcStack_5c = (code ****)pppcStack_24;
        pppcStack_60 = param_1;
        pppcStack_64 = (code ***)0x4045452;
        uVar9 = _ipc_kmsg_put();
        return uVar9;
      }
      if ((uVar9 & 0xffffc3ff) == 0x1000400c) {
        ppppcStack_58 = (code ****)((int)pppcStack_24[4] + (int)pppcStack_24[6]);
        ppppcVar16 = (code ****)&ppppcStack_5c;
        ppppcStack_5c = (code ****)pppcStack_24;
      }
      else {
        ppppcStack_5c = (code ****)pppcStack_24;
        pppcStack_60 = (code ***)0x4045426;
        ppppcStack_58 = (code ****)pppcVar7;
        _ipc_kmsg_copyout_dest();
        pppcStack_60 = (code ***)0x18;
        ppppcVar16 = &pppcStack_64;
        pppcStack_64 = pppcStack_24;
      }
      *(code ****)((int)ppppcVar16 + -4) = param_1;
      *(undefined4 *)((int)ppppcVar16 + -8) = 0x4045436;
      _ipc_kmsg_put();
      return uVar9;
    }
    if (param_2 == (code ***)0x0) {
      ppppcStack_58 = (code ****)0x0;
      ppppcStack_5c = (code ****)0x4045462;
      _thread_syscall_return();
    }
    goto loc_4045464;
  }
  pppcVar14 = (code ***)_active_threads[3][0x1f];
  if (((param_3 + -6 < (code ***)0xd5) && (((uint)param_3 & 3) == 0)) &&
     (_ipc_kmsg_cache != (code ***)0x0)) {
    _ipc_kmsg_cache = (code ***)0x0;
    pppcVar7[4] = (code **)0x0;
    ppppcStack_58 = (code ****)param_3;
    ppppcStack_5c = (code ****)(pppcVar7 + 5);
    pppcStack_60 = param_1;
    pppcStack_64 = (code ***)0x4044910;
    iVar5 = _copyinmsg();
    if (iVar5 != 0) {
      ppppcStack_58 = (code ****)pppcVar7[2];
      if ((int)ppppcStack_58 < 1) {
        ppppcStack_58 = (code ****)pppcVar7;
        ppppcStack_5c = (code ****)0x4044928;
        _ipc_kmsg_free();
      }
      else {
        ppppcStack_5c = (code ****)pppcVar7;
        pppcStack_60 = (code ***)0x4044f4c;
        _kfree();
      }
      goto loc_4044F4E;
    }
    pppcVar7[4] = (code **)0x0;
    pppcVar7[6] = (code **)param_3;
  }
  else {
loc_4044F4E:
    ppppcStack_58 = &pppcStack_8;
    ppppcStack_5c = (code ****)0x0;
    pppcStack_60 = param_3;
    pppcStack_64 = param_1;
    ppppcStack_58 = (code ****)_ipc_kmsg_get();
    pppcVar7 = pppcStack_8;
    if (ppppcStack_58 != (code ****)0x0) {
      ppppcStack_5c = (code ****)0x4044f70;
      _thread_syscall_return();
      pppcVar7 = pppcStack_8;
    }
  }
  if (pppcVar7[5] == (code **)0x12) {
    if (pppcVar7[8] == (code **)0x0) {
      ppcVar10 = pppcVar14[4];
      ppcVar6 = pppcVar14[3];
      ppcVar11 = (code **)((uint)pppcVar7[7] >> 8);
      pcVar3 = (code *)((int)pppcVar7[7] << 0x18);
      if ((((ppcVar10 <= ppcVar11) ||
           (ppcVar1 = ppcVar6 + (int)ppcVar11 * 4,
           ((uint)pcVar3 | 0x40000) != ((uint)*ppcVar1 & 0xff840000))) ||
          (ppcVar1[2] != (code *)0x0)) || (pppcVar15 = (code ***)ppcVar1[1], -1 < (int)pppcVar15[1])
         ) goto loc_4044F88;
      ppcVar1[2] = ppcVar6[2];
      ppcVar6[2] = (code *)ppcVar11;
      *ppcVar1 = pcVar3;
      ppcVar1[1] = (code *)0x0;
      pppcVar7[5] = (code **)0x12;
      pppcVar7[7] = (code **)pppcVar15;
      if (ppcVar10 <= (code **)((uint)param_5 >> 8)) goto loc_40450B2;
      ppcVar6 = ppcVar6 + (int)((uint)param_5 >> 8) * 4;
      pcVar3 = *ppcVar6;
      if ((int)param_5 << 0x18 != ((uint)pcVar3 & 0xff000000)) goto loc_40450B2;
      if (((uint)pcVar3 & 0x80000) == 0) {
        if ((((uint)pcVar3 & 0x20000) == 0) ||
           (ppcVar6 = (code **)ppcVar6[1], ppcVar6[0xb] != (code *)0x0)) goto loc_40450B2;
        iVar5 = 0x3c;
      }
      else {
        ppcVar6 = (code **)ppcVar6[1];
        iVar5 = 0xc;
      }
      ppcVar10 = (code **)((int)ppcVar6 + iVar5);
      *ppcVar6 = *ppcVar6 + 1;
loc_4044ACA:
      if (pppcVar15[0xb] == (code **)0x0) {
        pppcVar12 = pppcVar15 + 0xf;
      }
      else {
        pppcVar12 = (code ***)(pppcVar15[0xb] + 3);
      }
      ppcVar11 = pppcVar12[1];
      if ((ppcVar11 != (code **)0x0) && (*ppcVar10 == (code *)0x0)) {
        pppcVar13[0x2f] = (code **)param_1;
        pppcVar13[0x31] = (code **)param_4;
        pppcVar13[0x34] = ppcVar6;
        pppcVar13[0x35] = ppcVar10;
        if (ppcVar11[0xc] == _mach_msg_continue) {
          ppppcStack_5c = (code ****)_mach_msg_continue;
          pppcStack_60 = pppcVar13;
          pppcStack_64 = (code ***)0x4044b42;
          ppppcStack_58 = (code ****)ppcVar11;
          iVar5 = _thread_handoff();
          if (iVar5 == 0) goto loc_4044B50;
loc_4044CBC:
          ppcVar6 = (code **)ppcVar10[1];
          if (ppcVar6 == (code **)0x0) {
            ppcVar10[1] = (code *)pppcVar13;
          }
          else {
            ppcVar10 = (code **)ppcVar6[0x24];
            pppcVar13[0x23] = ppcVar6;
            pppcVar13[0x24] = ppcVar10;
            ppcVar6[0x24] = (code *)pppcVar13;
            ppcVar10[0x23] = (code *)pppcVar13;
          }
          pppcVar13[0x25] = (code **)0x10004001;
          pppcVar13[0x26] = (code **)0xffffffff;
          ppcVar6 = (code **)ppcVar11[0x23];
          if (ppcVar11 == ppcVar6) {
            pppcVar12[1] = (code **)0x0;
          }
          else {
            pcVar3 = ppcVar11[0x24];
            pppcVar12[1] = ppcVar6;
            ppcVar6[0x24] = pcVar3;
            *(code ***)(pcVar3 + 0x8c) = ppcVar6;
            ppcVar11[0x23] = (code *)ppcVar11;
            ppcVar11[0x24] = (code *)ppcVar11;
          }
          pppcVar7[9] = pppcVar15[0xc];
          pppcVar15[0xc] = (code **)((int)pppcVar15[0xc] + 1);
          pppcVar14 = *(code ****)(ppcVar11[3] + 0x7c);
          param_1 = (code ***)ppcVar11[0x2f];
          param_4 = (code ***)ppcVar11[0x31];
          ppppcStack_58 = (code ****)ppcVar11[0x34];
          ppcVar6 = (code **)*ppppcStack_58;
          *ppppcStack_58 = (code ***)((int)ppcVar6 + -1);
          if (ppcVar6 == (code **)0x1) {
            wVar4 = *(word *)(ppppcStack_58 + 1);
            goto loc_4044D44;
          }
          goto loc_4044D5C;
        }
loc_4044B50:
        if (ppcVar11[0xc] == _exception_raise_continue) {
          ppppcStack_5c = (code ****)_mach_msg_continue;
          pppcStack_60 = pppcVar13;
          pppcStack_64 = (code ***)0x4044b70;
          ppppcStack_58 = (code ****)ppcVar11;
          iVar5 = _thread_handoff();
          if (iVar5 != 0) {
            ppcVar6 = (code **)ppcVar10[1];
            if (ppcVar6 == (code **)0x0) {
              ppcVar10[1] = (code *)pppcVar13;
            }
            else {
              ppcVar10 = (code **)ppcVar6[0x24];
              pppcVar13[0x23] = ppcVar6;
              pppcVar13[0x24] = ppcVar10;
              ppcVar6[0x24] = (code *)pppcVar13;
              ppcVar10[0x23] = (code *)pppcVar13;
            }
            pppcVar13[0x25] = (code **)0x10004001;
            pppcVar13[0x26] = (code **)0xffffffff;
            ppcVar6 = (code **)ppcVar11[0x23];
            if (ppcVar11 == ppcVar6) {
              pppcVar12[1] = (code **)0x0;
            }
            else {
              pcVar3 = ppcVar11[0x24];
              pppcVar12[1] = ppcVar6;
              ppcVar6[0x24] = pcVar3;
              *(code ***)(pcVar3 + 0x8c) = ppcVar6;
              ppcVar11[0x23] = (code *)ppcVar11;
              ppcVar11[0x24] = (code *)ppcVar11;
            }
            pppcStack_60 = (code ***)0x4044bdc;
            ppppcStack_5c = (code ****)pppcVar15;
            ppppcStack_58 = (code ****)pppcVar7;
            _exception_raise_continue_fast();
            return 0;
          }
        }
        if (param_3 <= ppcVar11[0x26]) {
          ppppcStack_5c = (code ****)_mach_msg_continue;
          pppcStack_60 = pppcVar13;
          pppcStack_64 = (code ***)0x4044c12;
          ppppcStack_58 = (code ****)ppcVar11;
          iVar5 = _thread_handoff();
          if (iVar5 != 0) {
            if ((ppcVar11[0xc] != _mach_msg_receive_continue) ||
               (((byte)*(code *)((int)ppcVar11 + 0xc2) & 2) != 0)) {
              pppcVar15[0xd] = (code **)((int)pppcVar15[0xd] + 1);
              ppcVar6 = (code **)ppcVar10[1];
              if (ppcVar6 == (code **)0x0) {
                ppcVar10[1] = (code *)pppcVar13;
              }
              else {
                ppcVar10 = (code **)ppcVar6[0x24];
                pppcVar13[0x23] = ppcVar6;
                pppcVar13[0x24] = ppcVar10;
                ppcVar6[0x24] = (code *)pppcVar13;
                ppcVar10[0x23] = (code *)pppcVar13;
              }
              pppcVar13[0x25] = (code **)0x10004001;
              pppcVar13[0x26] = (code **)0xffffffff;
              ppcVar6 = (code **)ppcVar11[0x23];
              if (ppcVar11 == ppcVar6) {
                pppcVar12[1] = (code **)0x0;
              }
              else {
                pcVar3 = ppcVar11[0x24];
                pppcVar12[1] = ppcVar6;
                ppcVar6[0x24] = pcVar3;
                *(code ***)(pcVar3 + 0x8c) = ppcVar6;
                ppcVar11[0x23] = (code *)ppcVar11;
                ppcVar11[0x24] = (code *)ppcVar11;
              }
              ppcVar11[0x25] = (code *)0x0;
              ppcVar11[0x26] = (code *)pppcVar7;
              ppcVar11[0x27] = (code *)pppcVar15[0xc];
              pppcVar15[0xc] = (code **)((int)pppcVar15[0xc] + 1);
              ppcVar11[0x10] = (code *)0x0;
              ppppcStack_58 = (code ****)0x4044ca8;
              (*ppcVar11[0xc])();
              return 0;
            }
            goto loc_4044CBC;
          }
        }
      }
      ppppcStack_5c = (code ****)0x4044ae6;
      ppppcStack_58 = (code ****)ppcVar6;
      _ipc_object_release();
    }
    else {
loc_4044F88:
      ppppcStack_58 = (code ****)0x0;
      ppppcStack_5c = (code ****)_active_threads[3][2];
      pppcStack_64 = pppcVar7;
      pppcStack_60 = pppcVar14;
      iVar5 = _ipc_kmsg_copyin();
      if (iVar5 != 0) {
        ppppcStack_58 = (code ****)pppcVar7[2];
        if ((int)ppppcStack_58 < 1) {
          ppppcStack_5c = (code ****)0x4044fb8;
          ppppcStack_58 = (code ****)pppcVar7;
          _ipc_kmsg_free();
        }
        else {
          pppcStack_60 = (code ***)0x4044f84;
          ppppcStack_5c = (code ****)pppcVar7;
          _kfree();
        }
        ppppcStack_5c = (code ****)0x4044fc2;
        ppppcStack_58 = (code ****)iVar5;
        _thread_syscall_return();
      }
      if (((uint)pppcVar7[5] & 0x40000000) == 0) {
        pppcVar15 = (code ***)pppcVar7[7];
        if (pppcVar15[2] == _ipc_space_kernel) goto loc_404503C;
        if (((((int)pppcVar15[1] < 0) &&
             (((pppcVar15[0xd] < pppcVar15[0xe] || ((char)pppcVar7[5] == '\x12')) &&
              (ppcVar6 = pppcVar7[8], ppcVar6 != (code **)0x0)))) &&
            ((ppcVar6 != (code **)0xffffffff && ((int)ppcVar6[1] < 0)))) &&
           ((pppcVar14 == (code ***)ppcVar6[2] && (param_5 == (code **)ppcVar6[3])))) {
loc_4045028:
          if (ppcVar6[0xb] == (code *)0x0) {
            *ppcVar6 = *ppcVar6 + 1;
            ppcVar10 = ppcVar6 + 0xf;
            goto loc_4044ACA;
          }
        }
      }
    }
loc_40450B2:
    ppppcStack_58 = (code ****)0x0;
    ppppcStack_5c = (code ****)0x0;
    pppcStack_60 = (code ***)0x0;
    pppcStack_64 = pppcVar7;
    uVar9 = _ipc_mqueue_send();
    if (uVar9 != 0) {
      ppppcStack_58 = (code ****)_active_threads[3][2];
      pppcStack_64 = (code ***)0x40450e0;
      pppcStack_60 = pppcVar7;
      ppppcStack_5c = (code ****)pppcVar14;
      uVar8 = _ipc_kmsg_copyout_pseudo();
      pppcStack_64 = (code ***)((int)pppcVar7[4] + (int)pppcVar7[6]);
      _ipc_kmsg_put(param_1,pppcVar7);
      _thread_syscall_return(uVar8 | uVar9);
    }
loc_4045102:
    ppppcStack_58 = (code ****)&ppcStack_10;
    ppppcStack_5c = (code ****)&ppcStack_c;
    pppcStack_60 = (code ***)param_5;
    pppcStack_64 = pppcVar14;
    ppppcStack_58 = (code ****)_ipc_mqueue_copyin();
    if (ppppcStack_58 != (code ****)0x0) {
      ppppcStack_5c = (code ****)0x4045126;
      _thread_syscall_return();
    }
    pppcVar13[0x2f] = (code **)param_1;
    pppcVar13[0x31] = (code **)param_4;
    pppcVar13[0x34] = ppcStack_10;
    pppcVar13[0x35] = ppcStack_c;
    ppppcStack_58 = (code ****)&ppcStack_14;
    ppppcStack_5c = &pppcStack_8;
    pppcStack_60 = (code ***)_mach_msg_continue;
    pppcStack_64 = (code ***)0x0;
    iVar5 = _ipc_mqueue_receive(ppcStack_c,0,0xffffffff,0);
    ppppcStack_58 = (code ****)ppcStack_10;
    ppppcStack_5c = (code ****)0x404517a;
    _ipc_object_release();
    if (iVar5 != 0) {
      ppppcStack_5c = (code ****)0x4045188;
      ppppcStack_58 = (code ****)iVar5;
      _thread_syscall_return();
    }
    pppcStack_8[9] = ppcStack_14;
    pppcVar15 = (code ***)pppcStack_8[7];
    pppcVar7 = pppcStack_8;
  }
  else {
    if ((pppcVar7[5] != (code **)0x1513) || (param_5 != pppcVar7[8])) goto loc_4044F88;
    if ((pppcVar14[4] <= (code **)((uint)param_5 >> 8)) ||
       (ppcVar6 = pppcVar14[3] + (int)((uint)param_5 >> 8) * 4,
       ((int)param_5 << 0x18 | 0x20000U) != ((uint)*ppcVar6 & 0xff020000))) goto loc_4044F88;
    ppcVar6 = (code **)ppcVar6[1];
    ppcVar10 = (code **)((uint)pppcVar7[7] >> 8);
    if (((pppcVar14[4] <= ppcVar10) ||
        (ppcVar10 = pppcVar14[3] + (int)ppcVar10 * 4,
        ((int)pppcVar7[7] << 0x18 | 0x10000U) != ((uint)*ppcVar10 & 0xff010000))) ||
       (pppcVar15 = (code ***)ppcVar10[1], -1 < (int)pppcVar15[1])) goto loc_4044F88;
    pppcVar15[6] = (code **)((int)pppcVar15[6] + 1);
    *pppcVar15 = (code **)((int)*pppcVar15 + 1);
    ppcVar6[7] = ppcVar6[7] + 1;
    *ppcVar6 = *ppcVar6 + 1;
    pppcVar7[5] = (code **)0x1211;
    pppcVar7[7] = (code **)pppcVar15;
    pppcVar7[8] = ppcVar6;
    if (pppcVar15[2] != _ipc_space_kernel) {
      if (pppcVar15[0xe] <= pppcVar15[0xd]) goto loc_40450B2;
      goto loc_4045028;
    }
loc_404503C:
    ppppcStack_5c = (code ****)0x4045044;
    ppppcStack_58 = (code ****)pppcVar7;
    pppcVar7 = (code ***)_ipc_kobject_server();
    if (pppcVar7 == (code ***)0x0) goto loc_4045102;
    pppcVar15 = (code ***)pppcVar7[7];
    if (((-1 < (int)pppcVar15[1]) || (pppcVar14 != (code ***)pppcVar15[2])) ||
       (((param_5 != pppcVar15[3] ||
         ((pppcVar15[0xb] != (code **)0x0 || (pppcVar15[0x10] != (code **)0x0)))) ||
        (pppcVar15[0xf] != (code **)0x0)))) {
      ppppcStack_58 = (code ****)0x0;
      ppppcStack_5c = (code ****)0x0;
      pppcStack_60 = (code ***)0x10000;
      pppcStack_64 = pppcVar7;
      _ipc_mqueue_send();
      goto loc_4045102;
    }
    pppcVar7[9] = pppcVar15[0xc];
    pppcVar15[0xc] = (code **)((int)pppcVar15[0xc] + 1);
    if (*pppcVar15 == (code **)0x0) {
      wVar4 = *(word *)(pppcVar15 + 1);
      ppppcStack_58 = (code ****)pppcVar15;
loc_4044D44:
      ppppcStack_5c = (code ****)(&_ipc_object_zones)[wVar4 & 0x7fff];
      pppcStack_60 = (code ***)0x4044d5a;
      _zfree();
    }
  }
loc_4044D5C:
  pppcVar13 = (code ***)((int)pppcVar7[4] + (int)pppcVar7[6]);
  if (param_4 < pppcVar13) {
loc_404519C:
    pppcVar13 = (code ***)((int)pppcVar7[4] + (int)pppcVar7[6]);
    if (param_4 < pppcVar13) {
      pppcStack_60 = (code ***)0x40451b4;
      ppppcStack_5c = (code ****)pppcVar7;
      ppppcStack_58 = (code ****)pppcVar14;
      _ipc_kmsg_copyout_dest();
      pppcStack_60 = (code ***)0x18;
      pppcStack_64 = pppcVar7;
      _ipc_kmsg_put(param_1);
      _thread_syscall_return(0x10004004);
    }
    ppppcStack_58 = (code ****)0x0;
    ppppcStack_5c = (code ****)_active_threads[3][2];
    pppcStack_64 = pppcVar7;
    pppcStack_60 = pppcVar14;
    uVar9 = _ipc_kmsg_copyout();
    if (uVar9 != 0) {
      if ((uVar9 & 0xffffc3ff) == 0x1000400c) {
        ppppcStack_58 = (code ****)((int)pppcVar7[4] + (int)pppcVar7[6]);
        pppcStack_64 = (code ***)0x4045216;
        pppcStack_60 = param_1;
        ppppcStack_5c = (code ****)pppcVar7;
        _ipc_kmsg_put();
      }
      else {
        pppcStack_60 = (code ***)0x4045226;
        ppppcStack_5c = (code ****)pppcVar7;
        ppppcStack_58 = (code ****)pppcVar14;
        _ipc_kmsg_copyout_dest();
        pppcStack_60 = (code ***)0x18;
        pppcStack_64 = pppcVar7;
        _ipc_kmsg_put(param_1);
      }
      ppppcStack_5c = (code ****)0x4045240;
      ppppcStack_58 = (code ****)uVar9;
      _thread_syscall_return();
    }
  }
  else {
    ppcVar6 = pppcVar7[5];
    if (ppcVar6 == (code **)0x1211) {
      ppcVar6 = pppcVar7[8];
      if ((((ppcVar6 != (code **)0x0) && (ppcVar6 != (code **)0xffffffff)) &&
          ((int)pppcVar15[1] < 0)) && ((int)ppcVar6[1] < 0)) {
        ppcVar10 = pppcVar14[3];
        pcVar3 = ppcVar10[2];
        if (pcVar3 != (code *)0x0) {
          ppcVar11 = ppcVar10 + (int)pcVar3 * 4;
          ppcVar10[2] = ppcVar11[2];
          ppcVar11[2] = (code *)0x0;
          pcVar2 = *ppcVar11;
          *ppcVar11 = (code *)((uint)(pcVar2 + 0x1000000) | 0x40001);
          ppcVar11[1] = (code *)ppcVar6;
          *pppcVar15 = (code **)((int)*pppcVar15 + -1);
          ppcVar6 = (code **)0x0;
          if (pppcVar14 == (code ***)pppcVar15[2]) {
            ppcVar6 = pppcVar15[3];
          }
          ppcVar10 = pppcVar15[6];
          pppcVar15[6] = (code **)((int)ppcVar10 + -1);
          if ((ppcVar10 == (code **)0x1) &&
             (ppppcStack_5c = (code ****)pppcVar15[8], ppppcStack_5c != (code ****)0x0)) {
            ppppcStack_58 = (code ****)pppcVar15[5];
            pppcVar15[8] = (code **)0x0;
            pppcStack_60 = (code ***)0x4044e2e;
            _ipc_notify_no_senders();
          }
          pppcVar7[5] = (code **)0x1112;
          pppcVar7[7] = (code **)((uint)(pcVar2 + 0x1000000) >> 0x18 | (int)pcVar3 << 8);
          pppcVar7[8] = ppcVar6;
          goto loc_4044F00;
        }
      }
      goto loc_404519C;
    }
    ppppcStack_58 = (code ****)pppcVar15;
    if (ppcVar6 < (code **)0x1212) {
      if ((ppcVar6 != (code **)0x12) || (-1 < (int)pppcVar15[1])) goto loc_404519C;
      if (pppcVar14 == (code ***)pppcVar15[2]) {
        *pppcVar15 = (code **)((int)*pppcVar15 + -1);
        pppcVar15[7] = (code **)((int)pppcVar15[7] + -1);
        ppcVar6 = pppcVar15[3];
      }
      else {
        ppppcStack_5c = (code ****)0x4044e66;
        _ipc_notify_send_once();
        ppcVar6 = (code **)0x0;
      }
      pppcVar7[5] = (code **)0x1200;
      pppcVar7[7] = (code **)0x0;
      pppcVar7[8] = ppcVar6;
    }
    else {
      if ((ppcVar6 != (code **)0x80000012) || (-1 < (int)pppcVar15[1])) goto loc_404519C;
      if (pppcVar14 == (code ***)pppcVar15[2]) {
        *pppcVar15 = (code **)((int)*pppcVar15 + -1);
        pppcVar15[7] = (code **)((int)pppcVar15[7] + -1);
        ppcVar6 = pppcVar15[3];
      }
      else {
        ppppcStack_5c = (code ****)0x4044ea0;
        _ipc_notify_send_once();
        ppcVar6 = (code **)0x0;
      }
      pppcVar7[5] = (code **)0x80001200;
      pppcVar7[7] = (code **)0x0;
      pppcVar7[8] = ppcVar6;
      ppppcStack_58 = (code ****)_active_threads[3][2];
      pppcStack_60 = (code ***)((int)pppcVar7 + (int)(pppcVar7[6] + 5));
      pppcStack_64 = pppcVar7 + 0xb;
      ppppcStack_5c = (code ****)pppcVar14;
      uVar9 = _ipc_kmsg_copyout_body();
      if (uVar9 != 0) {
        ppppcStack_58 = (code ****)((int)pppcVar7[4] + (int)pppcVar7[6]);
        pppcStack_64 = (code ***)0x4044ef4;
        pppcStack_60 = param_1;
        ppppcStack_5c = (code ****)pppcVar7;
        _ipc_kmsg_put();
        return uVar9 | 0x1000400c;
      }
    }
  }
loc_4044F00:
  pppcVar7[4] = (code **)0x0;
  if (pppcVar7[2] == (code **)0x100) {
    pppcStack_60 = pppcVar7 + 5;
    pppcStack_64 = (code ***)0x4044f1e;
    ppppcStack_5c = (code ****)param_1;
    ppppcStack_58 = (code ****)pppcVar13;
    iVar5 = _copyoutmsg();
    if ((iVar5 == 0) && (_ipc_kmsg_cache == (code ***)0x0)) {
      ppppcStack_58 = (code ****)0x0;
      ppppcStack_5c = (code ****)0x4044f3e;
      _ipc_kmsg_cache = pppcVar7;
      _thread_syscall_return();
      return 0;
    }
  }
  pppcStack_64 = (code ***)0x4045252;
  pppcStack_60 = param_1;
  ppppcStack_5c = (code ****)pppcVar7;
  ppppcStack_58 = (code ****)pppcVar13;
  pppcStack_64 = (code ***)_ipc_kmsg_put();
  _thread_syscall_return();
loc_4045464:
  if (((uint)param_2 & 1) != 0) {
    ppppcStack_58 = (code ****)param_7;
    ppppcStack_5c = (code ****)param_6;
    pppcStack_60 = param_3;
    pppcStack_64 = param_2;
    uVar9 = _mach_msg_send(param_1);
    if (uVar9 != 0) {
      return uVar9;
    }
  }
  if (((uint)param_2 & 2) != 0) {
    ppppcStack_58 = (code ****)param_7;
    ppppcStack_5c = (code ****)param_6;
    pppcStack_60 = (code ***)param_5;
    pppcStack_64 = param_4;
    uVar9 = _mach_msg_receive(param_1,param_2);
    if (uVar9 != 0) {
      return uVar9;
    }
  }
  return 0;
}

