/* GHIDRADEC_FUNCTION index=2600 start=0x4098f18 */

void _pmap_zero_page(undefined4 param_1)

{
  _bzero(param_1,_page_size);
  return;
}
/* GHIDRADEC_FUNCTION index=2601 start=0x4098f30 */

void _copy_from_phys(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  _bcopy(param_1,param_2,param_3);
  return;
}
/* GHIDRADEC_FUNCTION index=2602 start=0x4098f4a */

void _copy_to_phys(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  _bcopy(param_1,param_2,param_3);
  return;
}
/* GHIDRADEC_FUNCTION index=2603 start=0x4098f64 */

void _compress_data_from_phys(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  _compress_data(param_1,param_2,param_3);
  return;
}
/* GHIDRADEC_FUNCTION index=2604 start=0x4098f7e */

void _uncompress_data_to_phys
               (undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
               undefined4 param_5)

{
  _uncompress_data(param_1,param_2,param_3,param_4,param_5);
  return;
}
/* GHIDRADEC_FUNCTION index=2605 start=0x4098fa0 */

void _pmap_tt(int param_1,uint param_2,undefined4 param_3,int param_4,int param_5)

{
  int iVar1;
  undefined *puVar2;
  undefined uVar4;
  int iVar3;
  byte bVar5;
  
  iVar1 = *(int *)(param_1 + 0x24);
  if (_cache == 0) {
    param_5 = 0;
  }
  puVar2 = (undefined *)(iVar1 + 0x58);
  _bzero(puVar2,4);
  uVar4 = (undefined)((uint)param_3 >> 0x18);
  if (_cpu_type == '\0') {
    *puVar2 = uVar4;
    *(char *)(iVar1 + 0x59) = (char)((uint)(param_4 + -1) >> 0x18);
    *(byte *)(iVar1 + 0x5a) =
         *(byte *)(iVar1 + 0x5a) & 0x7b | (byte)((param_2 & 1) << 7) | (param_5 == 0) << 2 | 1;
    if (*(int *)(*(int *)(param_1 + 0xc) + 0x44) == 0) {
      bVar5 = *(byte *)(iVar1 + 0x5b) & 0x8f | 7;
    }
    else {
      bVar5 = *(byte *)(iVar1 + 0x5b) & 0xcb | 0x43;
    }
    *(byte *)(iVar1 + 0x5b) = bVar5;
  }
  else {
    *puVar2 = uVar4;
    *(char *)(iVar1 + 0x59) = (char)((uint)(param_4 + -1) >> 0x18);
    *(uint *)(iVar1 + 0x5a) = *(uint *)(iVar1 + 0x5a) & 0x7fffffff | param_2 << 0x1f;
    iVar3 = 2;
    if (param_5 != 0) {
      iVar3 = 1;
    }
    *(uint *)(iVar1 + 0x5b) = *(uint *)(iVar1 + 0x5b) & 0x9fffffff | iVar3 << 0x1d;
    if (*(int *)(*(int *)(param_1 + 0xc) + 0x44) == 0) {
      *(byte *)(iVar1 + 0x5a) = *(byte *)(iVar1 + 0x5a) & 0xdf | 0x40;
    }
    else {
      *(byte *)(iVar1 + 0x5a) = *(byte *)(iVar1 + 0x5a) & 0xbf | 0x20;
    }
  }
  _pmove_tt1(iVar1 + 0x58);
  if (param_2 == 0) {
    *(byte *)(iVar1 + 0x54) = *(byte *)(iVar1 + 0x54) & 0x7f;
  }
  else {
    *(byte *)(iVar1 + 0x54) = *(byte *)(iVar1 + 0x54) | 0x80;
  }
  return;
}
/* GHIDRADEC_FUNCTION index=2606 start=0x40990ba */

void _md_prepare_for_shutdown(void)

{
  _adb_watchdog(0);
  return;
}
/* GHIDRADEC_FUNCTION index=2607 start=0x40990ca */

void _md_shutdown_devices(undefined4 param_1,uint param_2)

{
  if ((_machine_type == '\0') || (_machine_type == '\x02')) {
    _od_update();
    if (((param_2 & 0x80000) != 0) && (_kernel_task != 0)) {
      _od_eject();
    }
  }
  return;
}
/* GHIDRADEC_FUNCTION index=2608 start=0x40990fc */

undefined4 _md_do_shutdown(undefined4 param_1,uint param_2,int param_3)

{
  undefined2 extraout_D0u;
  undefined2 extraout_D0u_00;
  undefined2 extraout_D0u_01;
  undefined2 uVar1;
  undefined3 *puVar2;
  char cVar3;
  char cVar4;
  char cVar5;
  char cVar6;
  byte bVar7;
  
  if ((param_2 & 0x10000) != 0) {
                    /* WARNING: Subroutine does not return */
    _rtc_power_down();
  }
  cVar3 = '\0';
  cVar4 = '\0';
  cVar6 = '\0';
  bVar7 = 0;
  cVar5 = (param_2 & 8) == 0;
  if ((bool)cVar5) {
    _printf(aRebootingMach);
    if ((param_2 & 0x100000) == 0) {
      puVar2 = (undefined3 *)0x0;
      if ((param_2 & 2) != 0) {
        puVar2 = &aS_5;
      }
      cVar4 = '\0';
      cVar5 = puVar2 == (undefined3 *)0x0;
      cVar6 = '\0';
      bVar7 = 0;
      _mon_boot(puVar2);
      uVar1 = extraout_D0u_01;
    }
    else {
      cVar4 = param_3 < 0;
      cVar5 = param_3 == 0;
      cVar6 = '\0';
      bVar7 = 0;
      _mon_call(param_3);
      uVar1 = extraout_D0u_00;
    }
  }
  else {
    _printf(aHalting);
    _mon_call(&aH);
    uVar1 = extraout_D0u;
  }
  return CONCAT22(uVar1,(word)(byte)(cVar3 << 4 | cVar4 << 3 | cVar5 << 2 | cVar6 << 1 | bVar7));
}
/* GHIDRADEC_FUNCTION index=2609 start=0x4099184 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int _setconf(void)

{
  undefined (*pauVar1) [50];
  char cVar2;
  int iVar3;
  undefined5 *puVar4;
  int iVar5;
  sword sVar6;
  char *pcVar7;
  undefined *puVar8;
  char acStack_84 [128];
  
  sVar6 = 0;
  if ((__boothowto & 1) != 0) goto loc_40991AC;
  if (_rootdevice == '\0') {
    iVar5 = 0;
    if (_boot_dev != '\0') {
      if (_boot_info != '\0') {
        iVar5 = byte_40C8ED5 + -0x30;
      }
      dword_40B5644 = &off_40B2BDE;
      pauVar1 = off_40B2BDE;
      while (pauVar1 != (undefined (*) [50])0x0) {
        iVar3 = _strcmp(&_boot_dev,dword_40B5644[1]);
        if (iVar3 == 0) {
          puVar8 = _bus_dinit;
          iVar3 = _bus_dinit._0_4_;
          while (iVar3 != 0) {
            if ((((*(sword *)((int)puVar8 + 0x1a) != 0) && (iVar5 == *(sword *)((int)puVar8 + 4)))
                && (*(undefined (**) [50])puVar8 == *dword_40B5644)) &&
               (iVar3 = _strcmp(*(undefined4 *)((int)puVar8 + 0x16),dword_40B5644[1]), iVar3 == 0))
            {
              iVar3 = _printf(aRootOnSD,*(undefined4 *)((int)puVar8 + 0x16),iVar5);
              goto loc_40993F4;
            }
            puVar8 = (undefined *)((int)puVar8 + 0x2a);
            iVar3 = *(int *)puVar8;
          }
        }
        pauVar1 = *(undefined (**) [50])((int)dword_40B5644 + 10);
        dword_40B5644 = (undefined (**) [50])((int)dword_40B5644 + 10);
      }
      _printf(aRootDeviceSDNo,&_boot_dev,iVar5);
    }
    _printf(aNoSuitableRoot);
    iVar3 = _mon_boot(&aH);
loc_40993F4:
    if (*(sword *)(dword_40B5644 + 2) == -1) {
loc_4099402:
      _rootfs = 0x6e;
      byte_40B6A8D = 0x66;
      byte_40B6A8E = 0x73;
      byte_40B6A8F = 0;
    }
    else {
      _rootfs = 0x34;
      byte_40B6A8D = 0x2e;
      byte_40B6A8E = 0x33;
      byte_40B6A8F = 0;
      _rootdev = sVar6 + (sword)(iVar5 << 3);
      iVar3 = CONCAT22((sword)((uint)(iVar5 << 3) >> 0x10),_rootdev);
      _rootdev = _rootdev | (word)*(byte *)(dword_40B5644 + 2) << 8;
      *(word *)(dword_40B5644 + 2) = _rootdev;
    }
    return iVar3;
  }
  do {
    if ((__boothowto & 1) == 0) {
      pcVar7 = &_rootdevice;
      iVar3 = _printf(aRootOnS,&_rootdevice);
    }
    else {
loc_40991AC:
      _printf(aRootDevice);
      pcVar7 = acStack_84;
      iVar3 = _gets(pcVar7,pcVar7);
    }
    dword_40B5644 = &off_40B2BDE;
    pauVar1 = off_40B2BDE;
    while (pauVar1 != (undefined (*) [50])0x0) {
      if (((*dword_40B5644[1])[0] == *pcVar7) && ((*dword_40B5644[1])[1] == pcVar7[1])) {
        if (*(sword *)(dword_40B5644 + 2) == -1) goto loc_4099402;
        if (pcVar7[3] == '*') {
          pcVar7[3] = pcVar7[4];
        }
        if ((byte)(pcVar7[2] - 0x30U) < 8) {
          cVar2 = pcVar7[3];
          if ((byte)(cVar2 + 0x9fU) < 8) {
            sVar6 = cVar2 + -0x61;
          }
          else {
            sVar6 = 0;
            if (cVar2 != '\0') {
              puVar8 = aBadPartitionNu;
              goto loc_4099280;
            }
          }
          iVar3 = (int)pcVar7[2];
          iVar5 = iVar3 + -0x30;
          goto loc_40993F4;
        }
        puVar8 = aBadMissingUnit;
loc_4099280:
        _printf(puVar8);
        break;
      }
      pauVar1 = *(undefined (**) [50])((int)dword_40B5644 + 10);
      dword_40B5644 = (undefined (**) [50])((int)dword_40B5644 + 10);
    }
    dword_40B5644 = &off_40B2BDE;
    pauVar1 = off_40B2BDE;
    while (pauVar1 != (undefined (*) [50])0x0) {
      if (dword_40B5644 == &off_40B2BDE) {
        puVar4 = &aUse;
      }
      else {
        puVar4 = &aOr;
        if (*(int *)((int)dword_40B5644 + 10) != 0) {
          puVar4 = (undefined5 *)&DAT_40aca03;
        }
      }
      _printf(&aSSD,puVar4,dword_40B5644[1]);
      pauVar1 = *(undefined (**) [50])((int)dword_40B5644 + 10);
      dword_40B5644 = (undefined (**) [50])((int)dword_40B5644 + 10);
    }
    _printf(&asc_40A6049);
    __boothowto = __boothowto | 1;
  } while( true );
}
/* GHIDRADEC_FUNCTION index=2610 start=0x4099476 */

void _gets(byte *param_1,byte *param_2)

{
  byte bVar1;
  undefined4 uVar2;
  
loc_409948C:
  do {
    bVar1 = _cngetc();
    bVar1 = bVar1 & 0x7f;
    if (bVar1 == 0xd) {
loc_40994C4:
      *param_2 = 0;
      return;
    }
    if (bVar1 < 0xe) {
      if (bVar1 != 8) {
        if (bVar1 != 10) goto loc_409950C;
        goto loc_40994C4;
      }
loc_40994E0:
      if (param_1 == param_2) {
        uVar2 = 8;
loc_4099502:
        _cnputc(uVar2);
      }
      else {
        _cnputc(0x20);
        _cnputc(8);
        param_2 = param_2 + -1;
      }
      goto loc_409948C;
    }
    if (bVar1 == 0x40) {
loc_40994FC:
      uVar2 = 10;
      param_2 = param_1;
      goto loc_4099502;
    }
    if (bVar1 < 0x41) {
      if (bVar1 == 0x15) goto loc_40994FC;
    }
    else if (bVar1 == 0x7f) {
      if (param_1 != param_2) {
        _cnputc(8);
        _cnputc(8);
        goto loc_40994E0;
      }
      uVar2 = 8;
      goto loc_4099502;
    }
loc_409950C:
    *param_2 = bVar1;
    param_2 = param_2 + 1;
  } while( true );
}
/* GHIDRADEC_FUNCTION index=2611 start=0x409951c */

void _getfsname(undefined4 param_1,undefined4 param_2)

{
  if ((byte_40B606F & 1) != 0) {
    _printf(aSKeyS,param_1,param_1);
    _gets(param_2,param_2);
  }
  return;
}
/* GHIDRADEC_FUNCTION index=2612 start=0x4099556 */

int _initrootnet(void)

{
  bool bVar1;
  int iVar2;
  undefined4 uVar3;
  undefined *puVar4;
  int *piVar5;
  int iStack_28;
  undefined uStack_24;
  undefined uStack_23;
  undefined uStack_22;
  undefined uStack_21;
  undefined2 uStack_14;
  undefined auStack_10 [12];
  
  iStack_28 = 0;
  bVar1 = false;
  if ((_in_ifaddr != 0) && ((*(byte *)(*(int *)(_in_ifaddr + 0x20) + 0xd) & 8) == 0)) {
    return 0;
  }
  piVar5 = dword_40B5644;
  if (*(sword *)(dword_40B5644 + 2) != -1) {
    piVar5 = &off_40B2BDE;
    if (off_40B2BDE == 0) {
      return 0x13;
    }
    do {
      if (*(sword *)(piVar5 + 2) == -1) {
        puVar4 = _bus_dinit;
        iVar2 = _bus_dinit._0_4_;
        while ((iVar2 != 0 &&
               (((*(sword *)((int)puVar4 + 0x1a) == 0 || (*(sword *)((int)puVar4 + 4) != 0)) ||
                (*(int *)puVar4 != *dword_40B5644))))) {
          puVar4 = (undefined *)((int)puVar4 + 0x2a);
          iVar2 = *(int *)puVar4;
        }
      }
      piVar5 = (int *)((int)piVar5 + 10);
    } while (*piVar5 != 0);
  }
  if (*piVar5 == 0) {
    return 0x13;
  }
  uStack_24 = *(undefined *)piVar5[1];
  uStack_23 = *(undefined *)(piVar5[1] + 1);
  uStack_22 = 0x30;
  uStack_21 = 0;
  iVar2 = _socreate(2,&iStack_28,2,0);
  if (iVar2 == 0) {
    uStack_14 = 2;
    while (iVar2 = _ifioctl(iStack_28,0xc0206921,&uStack_24), iVar2 != 0) {
      if (iVar2 != 0x3c) {
        puVar4 = aInitrootnetAut;
        goto loc_4099660;
      }
      if (!bVar1) {
        _printf(aInitrootnetBoo);
        bVar1 = true;
      }
    }
    if (bVar1) {
      _printf(aInitrootnetBoo_0);
    }
    uVar3 = _inet_ntoa(auStack_10);
    _printf(aPrimaryNetwork,&uStack_24,uVar3);
  }
  else {
    puVar4 = aInitrootnetSoc;
loc_4099660:
    _printf(puVar4);
  }
  if (iStack_28 != 0) {
    _soclose(iStack_28);
    return iVar2;
  }
  return iVar2;
}
/* GHIDRADEC_FUNCTION index=2613 start=0x40996b8 */

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
/* GHIDRADEC_FUNCTION index=2614 start=0x409a044 */

void _unix_syscall(int *param_1)

{
  undefined4 *puVar1;
  int iVar2;
  int iVar3;
  int iStack_14;
  word *pwStack_10;
  int *piStack_c;
  
  iVar2 = _active_threads;
  iStack_14 = 0;
  puVar1 = *(undefined4 **)(_active_threads + 0x80);
  iVar3 = *param_1;
  if ((iVar3 < 0) || (_nsysent <= iVar3)) {
    pwStack_10 = (word *)DAT_40add4c;
  }
  else {
    pwStack_10 = (word *)(_sysent + iVar3 * 8);
  }
  if (**(int **)(*(int *)(_active_threads + 0xc) + 0x30) == 0) {
    _exception(5,0x10000,0);
  }
  *puVar1 = param_1;
  *(int **)(*(int *)(iVar2 + 0x24) + 0x48) = param_1;
  *(undefined *)(puVar1 + 0x19) = 0;
  piStack_c = param_1 + 1;
  if (pwStack_10 == (word *)_sysent) {
    iVar3 = *piStack_c;
    piStack_c = param_1 + 2;
    if ((iVar3 < 0) || (_nsysent <= iVar3)) {
      pwStack_10 = (word *)DAT_40add4c;
    }
    else {
      pwStack_10 = (word *)(_sysent + iVar3 * 8);
    }
  }
  if (0 < (sword)*pwStack_10) {
    _bcopy(piStack_c,puVar1 + 1,(int)((uint)*pwStack_10 << 0x10) >> 0xe);
  }
  puVar1[0x17] = 0;
  iVar3 = _setjmp(puVar1 + 10);
  if (iVar3 == 0) {
    *(undefined *)((int)puVar1 + 0x65) = 3;
    *(undefined *)((int)puVar1 + 0x6a) = 0;
    *(undefined4 *)((int)puVar1 + 0x66) = 0;
    (**(code **)(pwStack_10 + 2))();
    iStack_14 = (int)*(char *)(puVar1 + 0x19);
  }
  else if ((*(char *)(*(int *)(_active_threads + 0x80) + 100) == '\0') &&
          (*(char *)(*(int *)(_active_threads + 0x80) + 0x65) != '\x02')) {
    iStack_14 = 4;
  }
  _unix_syscall_return(iStack_14);
  return;
}
/* GHIDRADEC_FUNCTION index=2615 start=0x409a216 */

void _unix_syscall_return(int param_1)

{
  int iVar1;
  int iVar2;
  int *piVar3;
  int iVar4;
  
  iVar2 = _active_threads;
  if (*(int *)(*(int *)(_active_threads + 0x24) + 0x4c) == 0) {
    piVar3 = (int *)_thread_user_state(_active_threads);
  }
  else {
    piVar3 = *(int **)(*(int *)(_active_threads + 0x24) + 0x48);
  }
  iVar1 = *(int *)(iVar2 + 0x80);
  if ((((param_1 != 0) && (param_1 != 0x17)) && (0x17 < param_1)) && (param_1 == 0x1c)) {
    iVar4 = _fspause(0);
    if (iVar4 != 0) {
      *(undefined *)(iVar1 + 0x65) = 2;
    }
    param_1 = (int)*(char *)(iVar1 + 100);
  }
  if (*(char *)(iVar1 + 0x65) == '\x03') {
    if (param_1 == 0) {
      *piVar3 = *(int *)(iVar1 + 0x5c);
      piVar3[1] = *(int *)(iVar1 + 0x60);
      *(word *)(piVar3 + 0x10) = *(word *)(piVar3 + 0x10) & 0xfffe;
    }
    else {
      *piVar3 = param_1;
      *(word *)(piVar3 + 0x10) = *(word *)(piVar3 + 0x10) | 1;
    }
  }
  else if (*(char *)(iVar1 + 0x65) == '\x02') {
    *(int *)((int)piVar3 + 0x42) = *(int *)((int)piVar3 + 0x42) + -2;
  }
  *(char *)(iVar1 + 100) = (char)param_1;
  if ((*(byte *)(*(int *)(iVar2 + 0x24) + 0x54) & 8) != 0) {
    _do_trace(piVar3);
  }
  _check_for_ast(piVar3);
  __return_with_state(piVar3);
  return;
}
/* GHIDRADEC_FUNCTION index=2616 start=0x409a2dc */

void _do_trace(int param_1)

{
  *(word *)(param_1 + 0x40) = *(word *)(param_1 + 0x40) & 0x3fff;
  _exception_with_continuation(6,0,0,0);
  return;
}
/* GHIDRADEC_FUNCTION index=2617 start=0x409a2fe */

void _check_for_ast(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  byte *pbVar6;
  uint uVar7;
  int iVar8;
  uint uVar9;
  int iVar10;
  
  iVar8 = _active_threads;
  iVar1 = *_active_u;
  uVar2 = *(undefined4 *)(*(int *)(_active_threads + 0x24) + 0x48);
  *(int *)(*(int *)(_active_threads + 0x24) + 0x48) = param_1;
  do {
    while( true ) {
      uVar9 = _need_ast;
      if (iVar1 != 0) {
        if (((*(byte *)(iVar1 + 0x29) & 0x20) != 0) && (_active_u[0x94] != 0)) {
          _addupc(*(undefined4 *)(param_1 + 0x42),_active_u + 0x8f,1);
          *(byte *)(iVar1 + 0x29) = *(byte *)(iVar1 + 0x29) & 0xdf;
        }
        _need_ast = _need_ast & 0xffffffdf;
        if (_need_ast == 0) {
          pbVar6 = (byte *)(*(int *)(_active_threads + 0x24) + 0x54);
          *pbVar6 = *pbVar6 & 0xef;
        }
        *dword_40B57D4 = param_1;
        if (((*(uint *)(iVar8 + 0x177) & 0x3ffffff) >> 0x18 == 0) &&
           ((*(char *)(iVar1 + 0x17) != '\0' ||
            ((uVar7 = *(uint *)(*(int *)(iVar8 + 0x80) + 0x72) | *(uint *)(iVar1 + 0x18), uVar7 != 0
             && ((((*(byte *)(iVar1 + 0x2b) & 0x10) != 0 ||
                  ((uVar7 & ~(*(uint *)(iVar1 + 0x1c) | *(uint *)(iVar1 + 0x20))) != 0)) &&
                 (iVar10 = _issig(0), iVar10 != 0)))))))) {
          _psig();
        }
      }
      _need_ast = ~uVar9 & _need_ast;
      if (_need_ast == 0) {
        pbVar6 = (byte *)(*(int *)(_active_threads + 0x24) + 0x54);
        *pbVar6 = *pbVar6 & 0xef;
      }
      if ((*(uint *)(iVar8 + 0x177) & 0x3ffffff) >> 0x18 == 0) break;
      _thread_halt_self();
    }
    if ((uVar9 & 4) == 0) {
      iVar10 = *(int *)(*(int *)(_processor_ptr + 0x128) + 0x104);
      iVar3 = *(int *)(*(int *)(_processor_ptr + 0x128) + 0x100);
      iVar4 = *(int *)(iVar8 + 0x54);
      iVar5 = *(int *)(iVar8 + 0x5c);
      if (((*(byte *)(iVar8 + 0x4b) & 2) == 0) && (*(int *)(_processor_ptr + 0x104) < 1)) {
        if ((iVar5 == 2) || ((2 < iVar5 || (iVar5 != 1)))) {
          if ((iVar10 == 0) ||
             ((iVar3 < iVar4 || ((iVar3 <= iVar4 && (*(int *)(_processor_ptr + 0x120) != 0)))))) {
loc_409A498:
            *(undefined4 *)(*(int *)(iVar8 + 0x24) + 0x48) = uVar2;
            return;
          }
        }
        else if ((*(int *)(_processor_ptr + 0x120) != 0) || ((iVar10 < 1 || (iVar3 < iVar4))))
        goto loc_409A498;
      }
    }
    *(int *)((int)_active_u + 0x1aa) = *(int *)((int)_active_u + 0x1aa) + 1;
    _thread_block();
  } while( true );
}
/* GHIDRADEC_FUNCTION index=2618 start=0x409a4aa */

void _traceback(undefined4 *param_1)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  
  if (_traceback_recursive != 0) {
    _printf(aTracebackRecur);
                    /* WARNING: Subroutine does not return */
    _longjmp(_traceback_jb);
  }
  _traceback_recursive = 1;
  _printf(aTracebackFp0xX,param_1);
  puVar3 = _interrupt_stack;
  puVar1 = _interrupt_stack + 0x400;
  do {
    puVar2 = param_1;
    if ((((uint)puVar2 & 1) != 0) ||
       (((puVar2 < puVar3 || (puVar1 < puVar2)) &&
        ((puVar2 < (undefined4 *)0x10000000 || ((undefined4 *)0x14000000 < puVar2))))))
    goto loc_409A556;
    _printf(aCalledFromPc0x,puVar2[1],*puVar2,puVar2[2],puVar2[3],puVar2[4],puVar2[5]);
    param_1 = (undefined4 *)*puVar2;
  } while ((undefined4 *)*puVar2 != puVar2);
  _printf(aLoopingFp);
loc_409A556:
  _printf(aLastFp0xX,puVar2);
  _traceback_recursive = 0;
  return;
}
/* GHIDRADEC_FUNCTION index=2619 start=0x409a574 */

int _do_writeback(int param_1)

{
  byte bVar1;
  uint uVar2;
  int iVar3;
  word wVar4;
  uint uVar5;
  int iVar6;
  undefined4 uVar7;
  
  iVar6 = 0;
  if ((*(byte *)(param_1 + 0x53) & 0x98) != 0x80) goto loc_409A682;
  uVar5 = *(uint *)(param_1 + 0x6c);
  uVar2 = (*(byte *)(param_1 + 0x53) & 0x7f) >> 5;
  wVar4 = (word)(uVar5 >> 0x10);
  if (uVar2 == 1) {
    uVar2 = *(uint *)(param_1 + 0x68) & 3;
    if (uVar2 == 1) {
      uVar5 = (uint)wVar4;
    }
    else if (uVar2 < 2) {
      if (uVar2 == 0) {
        uVar5 = uVar5 >> 0x18;
      }
    }
    else if (uVar2 == 2) {
      uVar5 = uVar5 >> 8;
    }
    uVar7 = 1;
loc_409A668:
    bVar1 = *(byte *)(param_1 + 0x53);
  }
  else {
    if (uVar2 < 2) {
      if (uVar2 != 0) goto loc_409A682;
      uVar2 = *(uint *)(param_1 + 0x68) & 3;
      if (uVar2 == 1) {
        uVar5 = uVar5 << 8 | uVar5 >> 0x18;
      }
      else if (1 < uVar2) {
        if (uVar2 == 2) {
          uVar5 = uVar5 << 0x10 | uVar5 >> 0x10;
        }
        else if (uVar2 == 3) {
          uVar5 = uVar5 << 0x18 | uVar5 >> 8;
        }
      }
      uVar7 = 0;
      goto loc_409A668;
    }
    if (uVar2 != 2) goto loc_409A682;
    uVar2 = *(uint *)(param_1 + 0x68) & 3;
    if (uVar2 == 1) {
      uVar5 = uVar5 >> 8;
    }
    else if (uVar2 < 2) {
      if (uVar2 == 0) {
        uVar5 = (uint)wVar4;
      }
    }
    else if ((uVar2 != 2) && (uVar2 == 3)) {
      uVar5 = uVar5 << 8 | uVar5 >> 0x18;
    }
    uVar7 = 2;
    bVar1 = *(byte *)(param_1 + 0x53);
  }
  iVar6 = _move_space(*(undefined4 *)(param_1 + 0x68),bVar1 & 7,uVar7,uVar5,param_1);
loc_409A682:
  bVar1 = *(byte *)(param_1 + 0x51);
  if (((bVar1 & 0x98) == 0x80) &&
     (iVar3 = _move_space(*(undefined4 *)(param_1 + 0x60),bVar1 & 7,(bVar1 & 0x7f) >> 5,
                          *(undefined4 *)(param_1 + 100),param_1), iVar6 == 0)) {
    iVar6 = iVar3;
  }
  bVar1 = *(byte *)(param_1 + 0x4f);
  if (((bVar1 & 0x98) == 0x80) &&
     (iVar3 = _move_space(*(undefined4 *)(param_1 + 0x58),bVar1 & 7,(bVar1 & 0x7f) >> 5,
                          *(undefined4 *)(param_1 + 0x5c),param_1), iVar6 == 0)) {
    iVar6 = iVar3;
  }
  return iVar6;
}
/* GHIDRADEC_FUNCTION index=2620 start=0x409a6fa */

int _move_space(undefined4 param_1,uint param_2,undefined4 param_3,undefined4 param_4,int param_5)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  uint uVar4;
  int iVar5;
  int iVar6;
  int unaff_D6;
  undefined4 uStack_10;
  undefined4 uStack_c;
  undefined4 uStack_8;
  
  iVar5 = _active_threads;
  iVar2 = *(int *)(param_5 + 0x42);
  iVar1 = *_active_u;
  if (iVar1 != 0) {
    unaff_D6 = *dword_40B57D4;
    *dword_40B57D4 = param_5;
  }
  uVar3 = *(undefined4 *)(*(int *)(iVar5 + 0x24) + 0x48);
  *(int *)(*(int *)(iVar5 + 0x24) + 0x48) = param_5;
  while( true ) {
    iVar6 = __move_space(param_1,param_2,param_3,param_4,&uStack_8,&uStack_c,&uStack_10);
    if ((iVar6 == 0) || ((param_2 & 0xfffffffc) != 0)) break;
    _exception_from_kernel(uStack_8,uStack_c,uStack_10);
    if ((((*(uint *)(_active_threads + 0x177) & 0x3ffffff) >> 0x18 != 0) ||
        (iVar2 != *(int *)(param_5 + 0x42))) ||
       (((iVar1 != 0 && ((*(uint *)(iVar5 + 0x177) & 0x3ffffff) >> 0x18 == 0)) &&
        ((*(char *)(iVar1 + 0x17) != '\0' ||
         ((uVar4 = *(uint *)(*(int *)(iVar5 + 0x80) + 0x72) | *(uint *)(iVar1 + 0x18), uVar4 != 0 &&
          (((*(byte *)(iVar1 + 0x2b) & 0x10) != 0 ||
           ((uVar4 & ~(*(uint *)(iVar1 + 0x1c) | *(uint *)(iVar1 + 0x20))) != 0)))))))))) break;
  }
  *(undefined4 *)(*(int *)(iVar5 + 0x24) + 0x48) = uVar3;
  if (iVar1 != 0) {
    *dword_40B57D4 = unaff_D6;
  }
  return iVar6;
}
/* GHIDRADEC_FUNCTION index=2621 start=0x409a7ea */

void _bmap_parity_error(int param_1)

{
  int iVar1;
  undefined6 *puVar2;
  int iVar3;
  
  *(byte *)(_bmap_chip + 8) = *(byte *)(_bmap_chip + 8) | 0x80;
  if (_dma_chip == 0x139) {
    iVar1 = 0x4000000;
    if (_machine_type == '\x03') {
      iVar1 = 0x2000000;
    }
  }
  else {
    iVar1 = 0x8000000;
  }
  iVar3 = 4;
  if ((_machine_type == '\x03') &&
     ((param_1 - (_slot_id + 0x4000000)) / (iVar1 / _num_regions) != 0)) {
    iVar3 = 2;
  }
  if (_machine_type == '\x03') {
    iVar1 = iVar3 + 1;
  }
  else {
    iVar1 = iVar3 + 3;
  }
  puVar2 = (undefined6 *)&DAT_40ace31;
  if (_machine_type == '\x03') {
    puVar2 = &aAnd;
  }
  _printf(aParityErrorAtA_0,param_1,iVar3,puVar2,iVar1);
                    /* WARNING: Subroutine does not return */
  _panic(aParityError);
}
/* GHIDRADEC_FUNCTION index=2622 start=0x409a8ba */

undefined4 _allocbuf(int param_1,int param_2)

{
  int iVar1;
  uint *puVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  
  puVar2 = dword_40B58B0;
  iVar5 = _m68k_page_size * ((param_2 + -1 + _m68k_page_size) / _m68k_page_size);
  iVar1 = *(int *)(param_1 + 0x18);
  if (iVar1 != iVar5) {
    if (iVar5 < iVar1) {
      if (dword_40B58B0 != &DAT_40b58a4) {
        *(uint *)(dword_40B58B0[4] + 0xc) = dword_40B58B0[3];
        *(uint *)(puVar2[3] + 0x10) = puVar2[4];
        *puVar2 = *puVar2 | 8;
        _pagemove(iVar5 + *(int *)(param_1 + 0x20),puVar2[8],*(int *)(param_1 + 0x18) - iVar5);
        puVar2[6] = *(int *)(param_1 + 0x18) - iVar5;
        *(int *)(param_1 + 0x18) = iVar5;
        *(byte *)((int)puVar2 + 1) = *(byte *)((int)puVar2 + 1) | 1;
        puVar2[5] = 0;
        _brelse(puVar2);
      }
    }
    else if (iVar5 - iVar1 != 0 && iVar1 <= iVar5) {
      do {
        iVar4 = iVar5 - *(int *)(param_1 + 0x18);
        iVar3 = _getnewbuf();
        iVar1 = *(int *)(iVar3 + 0x18);
        if (iVar1 <= iVar4) {
          iVar4 = iVar1;
        }
        _pagemove(*(int *)(iVar3 + 0x20) + (iVar1 - iVar4),
                  *(int *)(param_1 + 0x18) + *(int *)(param_1 + 0x20),iVar4);
        *(int *)(param_1 + 0x18) = iVar4 + *(int *)(param_1 + 0x18);
        iVar4 = *(int *)(iVar3 + 0x18) - iVar4;
        *(int *)(iVar3 + 0x18) = iVar4;
        if (iVar4 < *(int *)(iVar3 + 0x14)) {
          *(int *)(iVar3 + 0x14) = iVar4;
        }
        if (*(int *)(iVar3 + 0x18) < 1) {
          *(undefined4 *)(*(int *)(iVar3 + 8) + 4) = *(undefined4 *)(iVar3 + 4);
          *(undefined4 *)(*(int *)(iVar3 + 4) + 8) = *(undefined4 *)(iVar3 + 8);
          *(int *)(iVar3 + 4) = dword_40B58A8;
          *(undefined4 **)(iVar3 + 8) = &DAT_40b58a4;
          *(int *)(dword_40B58A8 + 8) = iVar3;
          dword_40B58A8 = iVar3;
          *(undefined2 *)(iVar3 + 0x1e) = 0xffff;
          *(undefined2 *)(iVar3 + 0x1c) = 0;
          *(byte *)(iVar3 + 1) = *(byte *)(iVar3 + 1) | 1;
        }
        _brelse(iVar3);
      } while (iVar5 - *(int *)(param_1 + 0x18) != 0 && *(int *)(param_1 + 0x18) <= iVar5);
    }
  }
  *(int *)(param_1 + 0x14) = param_2;
  return 1;
}
/* GHIDRADEC_FUNCTION index=2623 start=0x409aa1e */

void _bfree(int param_1)

{
  *(undefined4 *)(param_1 + 0x14) = 0;
  return;
}
/* GHIDRADEC_FUNCTION index=2624 start=0x409aa2e */

undefined8 __udivdi3(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  undefined auStack_2c [8];
  undefined8 uStack_24;
  undefined4 uStack_1c;
  undefined4 uStack_18;
  undefined4 uStack_14;
  undefined4 uStack_10;
  undefined4 uStack_c;
  undefined4 uStack_8;
  
  uStack_14 = 0;
  uStack_10 = 0;
  uStack_c = param_1;
  uStack_8 = param_2;
  uStack_1c = param_3;
  uStack_18 = param_4;
  __bdiv(&uStack_14,&uStack_1c,&uStack_24,auStack_2c,0x10,8);
  return uStack_24;
}

