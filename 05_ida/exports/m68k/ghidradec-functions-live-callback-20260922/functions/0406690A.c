
undefined4 _dma_start(int param_1,int *param_2,uint param_3)

{
  int *piVar1;
  uint *puVar2;
  int iVar3;
  int iVar4;
  word wVar5;
  word wVar6;
  uint uVar7;
  uint uVar8;
  bool bVar9;
  
  *(uint *)(param_1 + 0x20) = param_3;
  puVar2 = *(uint **)(param_1 + 0x1c);
  for (piVar1 = param_2; piVar1 != (int *)0x0; piVar1 = (int *)*piVar1) {
    sub_40664EE(param_1,piVar1);
  }
  if (_dma_chip == 0x139) {
    *puVar2 = param_3 | 0x100000;
    wVar5 = _dma_chip;
    if ((param_2[3] & 4U) == 0) {
      if ((int)(param_2[1] & 0xfffffffU) < _slot_id + 0x4000000) {
loc_4066A18:
                    /* WARNING: Subroutine does not return */
        _panic(aAttemptedDmaOu);
      }
      if (_machine_type == '\x03') {
        iVar3 = _slot_id + 0x6000000;
      }
      else {
        iVar3 = _slot_id + 0x8000000;
      }
      if (iVar3 <= (int)(param_2[1] & 0xfffffffU)) goto loc_4066A18;
      do {
        puVar2[0x1000] = param_2[1];
        if (wVar5 != 0x139) break;
      } while (puVar2[0x1000] != param_2[1]);
    }
    else {
      if ((int)(param_2[1] & 0xfffffffU) < _slot_id + 0x4000000) {
loc_40669A6:
                    /* WARNING: Subroutine does not return */
        _panic(aAttemptedDmaOu);
      }
      if (_machine_type == '\x03') {
        iVar3 = _slot_id + 0x6000000;
      }
      else {
        iVar3 = _slot_id + 0x8000000;
      }
      if (iVar3 <= (int)(param_2[1] & 0xfffffffU)) goto loc_40669A6;
      do {
        puVar2[0x1080] = param_2[1];
        if (wVar5 != 0x139) break;
      } while (puVar2[0x1080] != param_2[1]);
    }
  }
  else {
    if ((param_2[3] & 4U) == 0) {
      uVar7 = param_3 | 0x100000;
    }
    else {
      uVar7 = param_3 | 0x900000;
    }
    *puVar2 = uVar7;
    wVar5 = _dma_chip;
    if ((int)(param_2[1] & 0xfffffffU) < _slot_id + 0x4000000) {
loc_4066AB8:
                    /* WARNING: Subroutine does not return */
      _panic(aAttemptedDmaOu);
    }
    if (_dma_chip == 0x139) {
      if (_machine_type == '\x03') {
        iVar3 = _slot_id + 0x6000000;
      }
      else {
        iVar3 = _slot_id + 0x8000000;
      }
    }
    else {
      iVar3 = _slot_id + 0xc000000;
    }
    if (iVar3 <= (int)(param_2[1] & 0xfffffffU)) goto loc_4066AB8;
    do {
      puVar2[0x1000] = param_2[1];
      if (wVar5 != 0x139) break;
    } while (puVar2[0x1000] != param_2[1]);
  }
  wVar5 = _dma_chip;
  if (_slot_id + 0x4000000 <= (int)(param_2[2] & 0xfffffffU)) {
    if (_dma_chip == 0x139) {
      if (_machine_type == '\x03') {
        iVar3 = _slot_id + 0x6000000;
      }
      else {
        iVar3 = _slot_id + 0x8000000;
      }
    }
    else {
      iVar3 = _slot_id + 0xc000000;
    }
    if ((int)(param_2[2] & 0xfffffffU) < iVar3) {
      do {
        puVar2[0x1001] = param_2[2];
        wVar6 = _dma_chip;
        if (wVar5 != 0x139) break;
      } while (puVar2[0x1001] != param_2[2]);
      if ((*(uint *)(param_1 + 0x2c) & 0x10) != 0) {
        if (wVar5 == 0x139) {
          if ((int)(param_2[1] & 0xfffffffU) < _slot_id + 0x4000000) {
loc_4066BB6:
                    /* WARNING: Subroutine does not return */
            _panic(aAttemptedDmaOu);
          }
          if (_machine_type == '\x03') {
            iVar3 = _slot_id + 0x6000000;
          }
          else {
            iVar3 = _slot_id + 0x8000000;
          }
          if (iVar3 <= (int)(param_2[1] & 0xfffffffU)) goto loc_4066BB6;
          do {
            puVar2[0xffc] = param_2[1];
            wVar5 = _dma_chip;
            if (wVar6 != 0x139) break;
          } while (puVar2[0xffc] != param_2[1]);
          if ((int)(param_2[2] & 0xfffffffU) < _slot_id + 0x4000000) {
loc_4066C30:
                    /* WARNING: Subroutine does not return */
            _panic(aAttemptedDmaOu);
          }
          if (wVar6 == 0x139) {
            if (_machine_type == '\x03') {
              iVar3 = _slot_id + 0x6000000;
            }
            else {
              iVar3 = _slot_id + 0x8000000;
            }
          }
          else {
            iVar3 = _slot_id + 0xc000000;
          }
          if (iVar3 <= (int)(param_2[2] & 0xfffffffU)) goto loc_4066C30;
          do {
            puVar2[0xffd] = param_2[2];
            bVar9 = wVar5 < 0x139;
            if (wVar5 != 0x139) goto loc_4066CBA;
          } while (puVar2[0xffd] != param_2[2]);
        }
        else {
          if (((int)(param_2[1] & 0xfffffffU) < _slot_id + 0x4000000) ||
             (_slot_id + 0xc000000 <= (int)(param_2[1] & 0xfffffffU))) {
                    /* WARNING: Subroutine does not return */
            _panic(aAttemptedDmaOu);
          }
          do {
            puVar2[0x1002] = param_2[1];
            bVar9 = wVar6 < 0x139;
            if (wVar6 != 0x139) goto loc_4066CBA;
          } while (puVar2[0x1002] != param_2[1]);
        }
      }
      bVar9 = _dma_chip < 0x139;
      if (_dma_chip != 0x139) {
loc_4066CBA:
        iVar3 = _slot_id;
        wVar5 = _dma_chip;
        if ((*(uint *)(param_1 + 0x2c) & 8) != 0) {
          if ((int)(param_2[1] & 0xfffffffU) < _slot_id + 0x4000000) {
loc_4066D1A:
                    /* WARNING: Subroutine does not return */
            _panic(aAttemptedDmaOu);
          }
          if (_dma_chip == 0x139) {
            if (_machine_type == '\x03') {
              iVar4 = _slot_id + 0x6000000;
            }
            else {
              iVar4 = _slot_id + 0x8000000;
            }
          }
          else {
            iVar4 = _slot_id + 0xc000000;
          }
          if (iVar4 <= (int)(param_2[1] & 0xfffffffU)) goto loc_4066D1A;
          do {
            *(int *)(iVar3 + 0x200411c) = param_2[1];
            bVar9 = wVar5 < 0x139;
            if (wVar5 != 0x139) break;
            uVar7 = *(uint *)(iVar3 + 0x200411c);
            bVar9 = uVar7 < (uint)param_2[1];
          } while (uVar7 != param_2[1]);
        }
      }
      *(int **)(param_1 + 8) = param_2;
      wVar5 = _dma_chip;
      iVar3 = *param_2;
      if (iVar3 == 0) {
        *puVar2 = param_3 | 0x10000;
loc_4066F72:
        uVar7 = *(uint *)(param_1 + 0x2c);
        uVar8 = uVar7 | 0x1000;
        *(uint *)(param_1 + 0x2c) = uVar8;
        return CONCAT22((sword)(uVar7 >> 0x10),
                        (word)(byte)(bVar9 << 4 | ((int)uVar8 < 0) << 3 | (uVar8 == 0) << 2));
      }
      uVar7 = *(uint *)(iVar3 + 4) & 0xfffffff;
      if (_slot_id + 0x4000000 <= (int)uVar7) {
        if (_dma_chip == 0x139) {
          if (_machine_type == '\x03') {
            iVar4 = _slot_id + 0x6000000;
          }
          else {
            iVar4 = _slot_id + 0x8000000;
          }
        }
        else {
          iVar4 = _slot_id + 0xc000000;
        }
        if ((int)uVar7 < iVar4) {
          do {
            puVar2[0x1002] = *(uint *)(iVar3 + 4);
            wVar6 = _dma_chip;
            if (wVar5 != 0x139) break;
          } while (puVar2[0x1002] != *(uint *)(iVar3 + 4));
          uVar7 = *(uint *)(iVar3 + 8) & 0xfffffff;
          if (_slot_id + 0x4000000 <= (int)uVar7) {
            if (wVar5 == 0x139) {
              if (_machine_type == '\x03') {
                iVar4 = _slot_id + 0x6000000;
              }
              else {
                iVar4 = _slot_id + 0x8000000;
              }
            }
            else {
              iVar4 = _slot_id + 0xc000000;
            }
            if ((int)uVar7 < iVar4) {
              do {
                puVar2[0x1003] = *(uint *)(iVar3 + 8);
                wVar5 = _dma_chip;
                bVar9 = wVar6 < 0x139;
                if (wVar6 != 0x139) break;
                bVar9 = puVar2[0x1003] < *(uint *)(iVar3 + 8);
              } while (puVar2[0x1003] != *(uint *)(iVar3 + 8));
              if ((*(uint *)(param_1 + 0x2c) & 0x10) != 0) {
                uVar7 = *(uint *)(iVar3 + 4) & 0xfffffff;
                if ((int)uVar7 < _slot_id + 0x4000000) {
loc_4066EB0:
                    /* WARNING: Subroutine does not return */
                  _panic(aAttemptedDmaOu);
                }
                if (wVar6 == 0x139) {
                  if (_machine_type == '\x03') {
                    iVar4 = _slot_id + 0x6000000;
                  }
                  else {
                    iVar4 = _slot_id + 0x8000000;
                  }
                }
                else {
                  iVar4 = _slot_id + 0xc000000;
                }
                if (iVar4 <= (int)uVar7) goto loc_4066EB0;
                do {
                  puVar2[0xffe] = *(uint *)(iVar3 + 4);
                  wVar6 = _dma_chip;
                  if (wVar5 != 0x139) break;
                } while (puVar2[0xffe] != *(uint *)(iVar3 + 4));
                uVar7 = *(uint *)(iVar3 + 8) & 0xfffffff;
                if ((int)uVar7 < _slot_id + 0x4000000) {
loc_4066F2A:
                    /* WARNING: Subroutine does not return */
                  _panic(aAttemptedDmaOu);
                }
                if (wVar5 == 0x139) {
                  if (_machine_type == '\x03') {
                    iVar4 = _slot_id + 0x6000000;
                  }
                  else {
                    iVar4 = _slot_id + 0x8000000;
                  }
                }
                else {
                  iVar4 = _slot_id + 0xc000000;
                }
                if (iVar4 <= (int)uVar7) goto loc_4066F2A;
                do {
                  puVar2[0xfff] = *(uint *)(iVar3 + 8);
                  bVar9 = wVar6 < 0x139;
                  if (wVar6 != 0x139) break;
                  bVar9 = puVar2[0xfff] < *(uint *)(iVar3 + 8);
                } while (puVar2[0xfff] != *(uint *)(iVar3 + 8));
              }
              *puVar2 = param_3 | 0x30000;
              *(uint *)(param_1 + 0x2c) = *(uint *)(param_1 + 0x2c) | 0x2000;
              goto loc_4066F72;
            }
          }
                    /* WARNING: Subroutine does not return */
          _panic(aAttemptedDmaOu);
        }
      }
                    /* WARNING: Subroutine does not return */
      _panic(aAttemptedDmaOu);
    }
  }
                    /* WARNING: Subroutine does not return */
  _panic(aAttemptedDmaOu);
}

