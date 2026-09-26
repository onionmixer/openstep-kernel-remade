
uint _dma_intr(int param_1,undefined4 param_2,undefined8 param_3)

{
  int iVar1;
  uint *puVar2;
  int iVar3;
  sword sVar4;
  sword sVar5;
  uint uVar6;
  uint in_D1;
  uint extraout_D1;
  uint extraout_D1_00;
  int *piVar7;
  char cVar8;
  char cVar9;
  char cVar10;
  char cVar11;
  byte bVar12;
  
  puVar2 = *(uint **)(param_1 + 0x1c);
  piVar7 = *(int **)(param_1 + 8);
  if (((*(uint *)(param_1 + 0x2c) & 0x1000) == 0) || (piVar7 == (int *)0x0)) {
    uVar6 = _printf(aSpuriousDmaInt,puVar2);
    *puVar2 = 0x100000;
  }
  else {
    if (_dma_chip == 0x139) {
      do {
      } while (*puVar2 == 0);
      uVar6 = *puVar2 & 0xb000000;
    }
    else {
      uVar6 = *puVar2 & 0x1b000000;
    }
    if ((uVar6 == 0x1000000) || (uVar6 == 0x3000000)) {
      if (_dma_chip == 0x139) {
        do {
        } while (*puVar2 == 0);
        uVar6 = *puVar2 & 0xb000000;
      }
      else {
        uVar6 = *puVar2 & 0x1b000000;
      }
      if ((uVar6 == 0x1000000) || (uVar6 == 0x3000000)) {
        uVar6 = _printf(aSpuriousDmaInt_0,uVar6,puVar2);
        return uVar6;
      }
      _printf(aBadDmaCsrReadD,puVar2);
      in_D1 = extraout_D1;
    }
    piVar7[4] = uVar6;
    if (uVar6 == 0x9000000) {
      if ((*(uint *)(param_1 + 0x2c) & 8) != 0) {
        if (_dma_chip == 0x139) {
          piVar7[5] = puVar2[0xffd];
        }
        else {
          piVar7[5] = *(int *)(_slot_id + 0x2004050);
        }
      }
      piVar7 = (int *)*piVar7;
      *(int **)(param_1 + 8) = piVar7;
      sVar4 = _dma_chip;
      iVar1 = *piVar7;
      if (iVar1 == 0) {
        *puVar2 = *(uint *)(param_1 + 0x20) | 0x80000;
        *(uint *)(param_1 + 0x2c) = *(uint *)(param_1 + 0x2c) & 0xffffdfff;
      }
      else {
        uVar6 = *(uint *)(iVar1 + 4) & 0xfffffff;
        if ((int)uVar6 < _slot_id + 0x4000000) {
loc_4067256:
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
        if (iVar3 <= (int)uVar6) goto loc_4067256;
        do {
          puVar2[0x1002] = *(uint *)(iVar1 + 4);
          sVar5 = _dma_chip;
          if (sVar4 != 0x139) break;
        } while (puVar2[0x1002] != *(uint *)(iVar1 + 4));
        in_D1 = *(uint *)(iVar1 + 8) & 0xfffffff;
        if ((int)in_D1 < _slot_id + 0x4000000) {
loc_40672D0:
                    /* WARNING: Subroutine does not return */
          _panic(aAttemptedDmaOu);
        }
        if (sVar4 == 0x139) {
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
        if (iVar3 <= (int)in_D1) goto loc_40672D0;
        do {
          puVar2[0x1003] = *(uint *)(iVar1 + 8);
          sVar4 = _dma_chip;
          if (sVar5 != 0x139) break;
        } while (puVar2[0x1003] != *(uint *)(iVar1 + 8));
        if ((*(uint *)(param_1 + 0x2c) & 0x10) != 0) {
          uVar6 = *(uint *)(iVar1 + 4) & 0xfffffff;
          if ((int)uVar6 < _slot_id + 0x4000000) {
loc_4067356:
                    /* WARNING: Subroutine does not return */
            _panic(aAttemptedDmaOu);
          }
          if (sVar5 == 0x139) {
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
          if (iVar3 <= (int)uVar6) goto loc_4067356;
          do {
            puVar2[0xffe] = *(uint *)(iVar1 + 4);
            sVar5 = _dma_chip;
            if (sVar4 != 0x139) break;
          } while (puVar2[0xffe] != *(uint *)(iVar1 + 4));
          uVar6 = *(uint *)(iVar1 + 8) & 0xfffffff;
          if ((int)uVar6 < _slot_id + 0x4000000) {
loc_40673D0:
                    /* WARNING: Subroutine does not return */
            _panic(aAttemptedDmaOu);
          }
          if (sVar4 == 0x139) {
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
          if (iVar3 <= (int)uVar6) goto loc_40673D0;
          in_D1 = CONCAT22((sword)(uVar6 >> 0x10),_dma_chip);
          do {
            puVar2[0xfff] = *(uint *)(iVar1 + 8);
            if (sVar5 != 0x139) break;
          } while (puVar2[0xfff] != *(uint *)(iVar1 + 8));
        }
        *puVar2 = *(uint *)(param_1 + 0x20) | 0xa0000;
      }
      if ((char)*(undefined4 *)(param_1 + 0x2c) < '\0') {
        _callout_dispatch(*(undefined4 *)(param_1 + 0x18),*(undefined4 *)(param_1 + 0x10),
                          *(undefined4 *)(param_1 + 0x14));
        in_D1 = extraout_D1_00;
      }
      if (_dma_chip == 0x139) {
        do {
        } while (*puVar2 == 0);
        uVar6 = *puVar2 & 0xb000000;
      }
      else {
        uVar6 = *puVar2 & 0x1b000000;
      }
      if ((uVar6 != 0xa000000) && (uVar6 != 0x1a000000)) {
        return 0;
      }
      uVar6 = uVar6 & 0xfdffffff;
      *(uint *)(param_1 + 0x2c) = *(uint *)(param_1 + 0x2c) & 0xffffdfff;
      piVar7[4] = uVar6;
    }
    if ((*(uint *)(param_1 + 0x2c) & 0x2000) != 0) {
      if ((*(uint *)(param_1 + 0x2c) & 8) != 0) {
        if (_dma_chip == 0x139) {
          piVar7[5] = puVar2[0xffd];
        }
        else {
          piVar7[5] = *(int *)(_slot_id + 0x2004050);
        }
      }
      piVar7[4] = 0x9000000;
      *(int *)(param_1 + 8) = *piVar7;
      piVar7 = *(int **)(param_1 + 8);
      piVar7[4] = uVar6;
    }
    if ((_dma_chip == 0x139) || ((*(uint *)(param_1 + 0x2c) & 8) == 0)) {
      piVar7[5] = puVar2[0x1000];
    }
    else {
      piVar7[5] = (CONCAT31((int3)(in_D1 >> 8),*(undefined *)(_slot_id_bmap + 0x2006007)) |
                  0xfffffff0) + puVar2[0x1000];
    }
    *(uint *)(param_1 + 0x2c) = *(uint *)(param_1 + 0x2c) & 0xffffcfff;
    if ((((_dma_chip == 0x139) || ((uVar6 & 0x10000000) == 0)) &&
        ((*(uint *)(param_1 + 0x2c) & 4) != 0)) && (*piVar7 != 0)) {
      _dma_start(param_1,*piVar7,*(undefined4 *)(param_1 + 0x20));
      uVar6 = *(uint *)(param_1 + 0x2c);
      if ((char)uVar6 < '\0') {
        uVar6 = _callout_dispatch(*(undefined4 *)(param_1 + 0x18),*(undefined4 *)(param_1 + 0x10),
                                  *(undefined4 *)(param_1 + 0x14));
      }
    }
    else {
      *(undefined4 *)(param_1 + 8) = 0;
      *puVar2 = 0x100000;
      *(uint *)(param_1 + 0x24) = uVar6;
      *(uint *)(param_1 + 0x28) = puVar2[0x1000];
      if (uVar6 == 0xa000000) {
        *(uint *)(param_1 + 0x2c) = *(uint *)(param_1 + 0x2c) | 0x4000;
      }
      if ((*(uint *)(param_1 + 0x2c) & 0x20) != 0) {
        (**(code **)(param_1 + 0xc))(*(undefined4 *)(param_1 + 0x14));
      }
      uVar6 = 0;
      if ((*(uint *)(param_1 + 0x2c) & 0x4001) != 0) {
        _callout_dispatch(*(undefined4 *)(param_1 + 0x18),*(undefined4 *)(param_1 + 0x10),
                          *(undefined4 *)(param_1 + 0x14));
        uVar6 = (param_3._2_4_ & 0x7ffffff) >> 0x18;
        if (((int)uVar6 < *(int *)(param_1 + 0x18) + 1) && (*(int *)(param_1 + 0x18) != 4)) {
          cVar8 = '\0';
          iVar1 = *(int *)(param_1 + 0x18);
          cVar9 = iVar1 < 0;
          cVar10 = iVar1 == 0;
          cVar11 = '\0';
          bVar12 = 0;
          _softint_run(iVar1);
          uVar6 = (uint)(byte)(cVar8 << 4 | cVar9 << 3 | cVar10 << 2 | cVar11 << 1 | bVar12);
        }
      }
    }
  }
  return uVar6;
}

