
int _np_write(byte param_1,int *param_2)

{
  undefined4 uVar1;
  uint *puVar2;
  uint uVar3;
  uint uVar4;
  uint *puVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  int *piVar10;
  int *piVar11;
  undefined4 *puVar12;
  undefined4 uVar13;
  undefined *puVar14;
  undefined4 uStack_e;
  int iStack_a;
  undefined uStack_5;
  
  iVar8 = (int)(sword)(word)param_1;
  iVar6 = iVar8 * 0x14c;
  puVar12 = (undefined4 *)(_np_softc + iVar6);
  uVar1 = *puVar12;
  if (1 < param_1) {
    return 6;
  }
  if (param_2[1] == 1) {
    puVar2 = (uint *)*param_2;
    if ((*(uint *)(_np_softc + iVar6 + 0x106) & 1) == 0) {
      return 0x52;
    }
    iVar9 = *(int *)(_np_softc + iVar6 + 0x13e) * 4 * *(int *)(_np_softc + iVar6 + 0x13a);
    uVar4 = puVar2[1];
    if ((iVar9 - uVar4 == 0 || iVar9 < (int)uVar4) &&
       ((uVar3 = *puVar2, uVar3 == (~_page_mask & _page_mask + uVar3) ||
        ((uVar4 + uVar3 & 0xf) == 0)))) {
      while( true ) {
        if ((*(int *)(_np_softc + iVar6 + 0x126) == 0) || (*(int *)(_np_softc + iVar6 + 0x126) == 7)
           ) {
          return 0x50;
        }
        if (*(int *)(_np_softc + iVar6 + 0x126) != 1) break;
        _sleep(iVar6 + 0x40c3b4a,0x28);
      }
      if ((*(uint *)(_np_softc + iVar6 + 0x106) & 0x20) != 0) {
        if ((*(uint *)(_np_softc + iVar6 + 0x106) & 0x10) == 0) {
          uVar13 = 0x4c;
        }
        else {
          uVar13 = 0x4f;
        }
        iVar9 = _np_serial_cmd(puVar12,uVar13,&uStack_5);
        if ((iVar9 != 0) && (iVar9 != 0x51)) {
          return iVar9;
        }
        *(uint *)(_np_softc + iVar6 + 0x106) = *(uint *)(_np_softc + iVar6 + 0x106) & 0xffffffdf;
      }
      uVar13 = *(undefined4 *)(*(int *)(_active_threads + 0xc) + 8);
      iVar9 = *(int *)(_kernel_task + 8);
      *(undefined4 *)(_np_softc + iVar6 + 0x144) = 0;
      *(uint *)(_np_softc + iVar6 + 0x148) = ~_page_mask & _page_mask + puVar2[1];
      puVar5 = (uint *)(_np_softc + iVar6 + 0x144);
      iVar7 = _vm_map_find(iVar9,0,0,puVar5,*(undefined4 *)(_np_softc + iVar6 + 0x148),1);
      if (iVar7 != 0) {
        return 0xc;
      }
      _vm_map_reference(uVar13);
      iVar7 = _vm_map_copy(iVar9,uVar13,*puVar5,*(undefined4 *)(_np_softc + iVar6 + 0x148),*puVar2,0
                           ,0);
      if (iVar7 == 0) {
        _vm_map_deallocate(uVar13);
        iVar7 = _vm_map_protect(iVar9,*puVar5,*(int *)(_np_softc + iVar6 + 0x148) + *puVar5,1,0);
        if (iVar7 == 0) {
          iVar7 = _vm_map_pageable(iVar9,~_page_mask & *puVar5,
                                   ~_page_mask &
                                   _page_mask + *(int *)(_np_softc + iVar6 + 0x148) + *puVar5,0);
          if (iVar7 == 0) {
            *(uint *)(_np_softc + iVar6 + 0x100) =
                 (*(int *)(_np_softc + iVar6 + 0x148) + -1 + _page_size) / _page_size + 1;
            _kmem_alloc_wired(_kernel_map,iVar6 + 0x40c3b20,
                              *(int *)(_np_softc + iVar6 + 0x100) * 0x1c);
            *(undefined4 *)(_np_softc + iVar6 + 0x12e) = 3;
loc_40744CE:
            do {
              iVar7 = _np_wait_printer_ready(puVar12);
              if (iVar7 != 0) goto loc_40748EC;
              _dma_list(iVar6 + 0x40c3a28,*(undefined4 *)(_np_softc + iVar6 + 0xfc),
                        *(undefined4 *)(_np_softc + iVar6 + 0x144),
                        *(undefined4 *)(_np_softc + iVar6 + 0x148),*(undefined4 *)(iVar9 + 0x20),0,
                        *(undefined4 *)(_np_softc + iVar6 + 0x100),0,0);
              for (piVar10 = *(int **)(_np_softc + iVar6 + 0xfc); *piVar10 != 0;
                  piVar10 = piVar10 + 7) {
              }
              piVar11 = piVar10;
              if (*(char *)(piVar10[2] + -1) != '\0') {
                piVar11 = piVar10 + 7;
                *piVar10 = (int)piVar11;
                piVar10[4] = 0;
                piVar10[8] = *(int *)(_np_softc + iVar6 + 0x44);
                piVar10[9] = piVar10[8] + 0x10;
                *piVar11 = 0;
                piVar10[0xb] = 0;
              }
              *(int *)(_np_softc + iVar6 + 0x12a) = piVar11[1];
              _np_send(uVar1,0xc2,
                       *(uint *)(_np_softc + iVar6 + 0x132) & 0x1ff |
                       (*(uint *)(_np_softc + iVar6 + 0x13a) & 0x7f) << 0x10);
              if (_np_softc[iVar6 + 0x142] != _np_softc[iVar6 + 0x143]) {
                if (_np_softc[iVar6 + 0x143] == '\0') {
                  _np_setgpout(puVar12,0x40);
                }
                else {
                  _np_cleargpout(puVar12,0x40);
                }
                _np_nap(_hz,puVar12);
                _np_softc[iVar6 + 0x142] = _np_softc[iVar6 + 0x143];
              }
              _np_setgpout(puVar12,0x10);
              _np_setmask(puVar12,4);
              _timeout(_np_serial_timeout,puVar12,_hz * 0x1e);
              _np_softc[iVar6 + 0x104] = _np_softc[iVar6 + 0x104] & 0xfe;
              while (((((_np_softc[iVar6 + 0x11b] & 4) == 0 &&
                       (*(int *)(_np_softc + iVar6 + 0x126) != 1)) &&
                      (*(int *)(_np_softc + iVar6 + 0x126) != 6)) &&
                     ((_np_softc[iVar6 + 0x104] & 1) == 0))) {
                _np_gpinwait(puVar12,_hz * 5);
              }
              _untimeout(_np_serial_timeout,puVar12);
              _np_clearmask(puVar12,4);
              if ((_np_softc[iVar6 + 0x104] & 1) != 0) {
                puVar14 = aNpDVsreqTimeou;
loc_4074862:
                _printf(puVar14,iVar8 * 4 >> 2);
                _lock_write(iVar6 + 0x40c3b36);
                _np_power_off(puVar12);
                _lock_done(iVar6 + 0x40c3b36);
                iVar7 = 5;
                goto loc_40748EC;
              }
              if ((*(int *)(_np_softc + iVar6 + 0x126) == 1) ||
                 (*(int *)(_np_softc + iVar6 + 0x126) == 6)) {
                _np_cleargpout(puVar12,0x10);
                goto loc_40744CE;
              }
              _np_setgpout(puVar12,0x20);
              _np_setstate(puVar12,3);
              uStack_e = 0;
              if (_np_softc[iVar6 + 0x142] == '\0') {
                iStack_a = *(int *)(_np_softc + iVar6 + 0x136) * 0x705;
              }
              else {
                iStack_a = *(int *)(_np_softc + iVar6 + 0x136) * 0x544;
              }
              _us_timeout(_np_startdata,puVar12,&uStack_e,1);
              if (*(int *)(_np_softc + iVar6 + 0x126) == 3) goto loc_4074744;
              iVar7 = *(int *)(_np_softc + iVar6 + 0x126);
              while (iVar7 == 4) {
loc_4074744:
                do {
                  piVar10 = (int *)(_np_softc + iVar6 + 0x126);
                  _sleep(piVar10,0x14);
                } while (*piVar10 == 3);
                iVar7 = *piVar10;
              }
              uVar4 = *(uint *)(_np_softc + iVar6 + 0x126);
              if (uVar4 != 8) {
                if (uVar4 < 9) {
                  if (uVar4 == 1) goto loc_40744CE;
                }
                else if (uVar4 == 9) {
                  iVar7 = _np_setstate_rdyerr(puVar12);
                  if (iVar7 != 0) goto loc_40748EC;
                  _printf(aNpDTimeoutWait,iVar8 * 4 >> 2);
                  goto loc_40744CE;
                }
                iVar7 = _np_setstate_rdyerr(puVar12);
                *(uint *)(_np_softc + iVar6 + 0x106) =
                     *(uint *)(_np_softc + iVar6 + 0x106) & 0xfffffffe;
                goto loc_40748EC;
              }
              *(int *)(_np_softc + iVar6 + 0x12e) = *(int *)(_np_softc + iVar6 + 0x12e) + -1;
              if (*(int *)(_np_softc + iVar6 + 0x12e) == 0) {
                puVar14 = aNpDDmaUnderrun_0;
                goto loc_4074862;
              }
              _printf(aNpDDmaUnderrun,iVar8 * 4 >> 2);
              _np_setmask(puVar12,4);
              while (((_np_softc[iVar6 + 0x11b] & 4) != 0 &&
                     (*(int *)(_np_softc + iVar6 + 0x126) != 1))) {
                _np_gpinwait(puVar12,_hz * 5);
              }
              _np_clearmask(puVar12,4);
              if ((*(int *)(_np_softc + iVar6 + 0x126) == 8) &&
                 (iVar7 = _np_setstate_rdyerr(puVar12), iVar7 != 0)) {
loc_40748EC:
                iVar8 = _vm_map_remove(iVar9,*(undefined4 *)(_np_softc + iVar6 + 0x144),
                                       *(int *)(_np_softc + iVar6 + 0x148) +
                                       *(int *)(_np_softc + iVar6 + 0x144));
                if (iVar8 == 0) {
                  _kmem_free(_kernel_map,*(undefined4 *)(_np_softc + iVar6 + 0xfc),
                             *(int *)(_np_softc + iVar6 + 0x100) * 0x1c);
                  *(undefined4 *)(_np_softc + iVar6 + 0xfc) = 0;
                  *param_2 = *param_2 + 8;
                  param_2[1] = param_2[1] + -1;
                  *puVar2 = puVar2[1] + *puVar2;
                  param_2[2] = puVar2[1] + param_2[2];
                  *(undefined4 *)((int)param_2 + 0x12) = 0;
                  puVar2[1] = 0;
                  return iVar7;
                }
                    /* WARNING: Subroutine does not return */
                _panic(aNpWriteCanTRem);
              }
            } while( true );
          }
          iVar8 = _vm_map_remove(iVar9,*puVar5,*(int *)(_np_softc + iVar6 + 0x148) + *puVar5);
          if (iVar8 != 0) {
                    /* WARNING: Subroutine does not return */
            _panic(aNpWriteVmMapPa);
          }
        }
        else {
          iVar8 = _vm_map_remove(iVar9,*puVar5,*(int *)(_np_softc + iVar6 + 0x148) + *puVar5);
          if (iVar8 != 0) {
                    /* WARNING: Subroutine does not return */
            _panic(aNpWriteVmMapPr);
          }
        }
      }
      else {
        iVar8 = _vm_map_remove(iVar9,*puVar5,*(int *)(_np_softc + iVar6 + 0x148) + *puVar5);
        if (iVar8 != 0) {
                    /* WARNING: Subroutine does not return */
          _panic(aNpWriteVmMapCo);
        }
        _vm_map_deallocate(uVar13);
      }
      return 0xe;
    }
  }
  return 0x16;
}

