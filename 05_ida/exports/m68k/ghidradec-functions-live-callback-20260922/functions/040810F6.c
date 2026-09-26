
void _dsp_dev_new_proto(uint param_1)

{
  int iVar1;
  int iVar2;
  int *piVar3;
  int *piVar4;
  int *piVar5;
  byte bVar6;
  word wVar7;
  int iVar8;
  sword sVar9;
  int *piVar10;
  
  if (((param_1 & 8) == 0) && ((dword_40C6E84 & 0x10) != 0)) {
    dword_40C6E84 = dword_40C6E84 & 0xffffffef;
    _snd_link_shutdown(0);
  }
  if (((param_1 & 0x10) == 0) && ((dword_40C6E84 & 0x20) != 0)) {
    dword_40C6E84 = dword_40C6E84 & 0x20;
    _snd_link_shutdown(1);
  }
  if ((param_1 & 1) == 0) {
    if ((dword_40C6E84 & 0x800) != 0) {
      dword_40C6E84 = dword_40C6E84 & 0xfffff7ff;
    }
  }
  else if (((dword_40C6E84 & 0x800) == 0) &&
          (dword_40C6E84 = dword_40C6E84 | 0x800, dword_40C6E5E == 0)) {
    dword_40C6E5E = _kalloc(0x80);
    dword_40C6E62 = dword_40C6E5E + 0x80;
    dword_40C6E66 = dword_40C6E5E;
  }
  if ((param_1 & 0x100) == 0) {
    dword_40C6E84 = dword_40C6E84 & 0xfffffbff;
  }
  else {
    dword_40C6E84 = dword_40C6E84 | 0x400;
  }
  if ((param_1 & 0x200) == 0) {
    dword_40C6E84 = dword_40C6E84 & 0xfffffeff;
  }
  else {
    dword_40C6E84 = dword_40C6E84 | 0x100;
  }
  if ((char)param_1 < '\0') {
    dword_40C6E84 = dword_40C6E84 | 0x200;
  }
  else {
    dword_40C6E84 = dword_40C6E84 & 0xfffffdff;
  }
  if ((param_1 & 0x40) == 0) {
    dword_40C6E84 = dword_40C6E84 & 0xffffbfff;
  }
  else {
    dword_40C6E84 = dword_40C6E84 | 0x4000;
  }
  if ((param_1 & 2) == 0) {
    if ((dword_40C6E84 & 0x2000) != 0) {
      dword_40C6E84 = dword_40C6E84 & 0xffffdfff;
      _dma_abort(&_dsp_var);
      while (iVar8 = _dma_dequeue(&_dsp_var,1), iVar8 != 0) {
        iVar8 = *(int *)(iVar8 + 0x18);
        if (iVar8 != 0) {
          if ((_dsp_var._0_4_ == 0) &&
             ((int *)((&unk_40C6DF4)[word_40C6E40] + 0x3e) ==
              *(int **)((&unk_40C6DF4)[word_40C6E40] + 0x3e))) {
            *(uint *)(iVar8 + 0x34) = *(uint *)(iVar8 + 0x34) | 1;
          }
          (**(code **)(iVar8 + 0x28))(iVar8);
        }
      }
      iVar8 = 0x12;
      piVar10 = &unk_40C6E3C;
      do {
        if (((iVar8 != 2) || ((param_1 & 0x20) == 0)) && (iVar1 = *piVar10, iVar1 != 0)) {
          piVar3 = (int *)(iVar1 + 0x3e);
          piVar5 = (int *)*piVar3;
          while (piVar3 != piVar5) {
            iVar2 = *piVar3;
            piVar5 = *(int **)(iVar2 + 0x2c);
            if (piVar5 == piVar3) {
              *(int **)(iVar1 + 0x42) = piVar3;
            }
            else {
              piVar5[0xc] = (int)piVar3;
            }
            *piVar3 = (int)piVar5;
            if (piVar5 == piVar3) {
              *(uint *)(iVar2 + 0x34) = *(uint *)(iVar2 + 0x34) | 1;
            }
            (**(code **)(iVar2 + 0x28))(iVar2);
            piVar5 = (int *)*piVar3;
          }
          _snd_stream_queue_reset(*piVar10);
          _kfree(*piVar10,0x54);
          *piVar10 = 0;
        }
        piVar10 = piVar10 + -1;
        wVar7 = (word)((uint)iVar8 >> 0x10);
        sVar9 = (sword)iVar8 + -1;
        iVar8 = CONCAT22(wVar7,sVar9);
      } while ((sVar9 != -1) || (iVar8 = (uint)wVar7 * 0x10000 + -1, wVar7 != 0));
    }
  }
  else if ((dword_40C6E84 & 0x2000) == 0) {
    dword_40C6E84 = dword_40C6E84 | 0x2000;
    iVar8 = 0x12;
    piVar10 = &unk_40C6E3C;
    do {
      if (((iVar8 != 2) || ((param_1 & 0x20) == 0)) && (iVar1 = *piVar10, iVar1 != 0)) {
        piVar5 = (int *)(iVar1 + 0x3e);
        if (piVar5 != (int *)*piVar5) {
          iVar2 = *(int *)(iVar1 + 0x42);
          piVar3 = *(int **)(iVar2 + 0x2c);
          piVar4 = *(int **)(iVar2 + 0x30);
          if (piVar3 == piVar5) {
            *(int **)(iVar1 + 0x42) = piVar4;
          }
          else {
            piVar3[0xc] = (int)piVar4;
          }
          if (piVar4 == piVar5) {
            *piVar5 = (int)piVar3;
          }
          else {
            piVar4[0xb] = (int)piVar3;
          }
          _dspq_start_complex(iVar2,(*(byte *)(*(int *)(iVar2 + 8) + 0x2d) & 0x7f) >> 6,0);
        }
        if (*piVar10 != 0) {
          *(code **)(*piVar10 + 0x3a) = _dspq_start_complex;
        }
      }
      piVar10 = piVar10 + -1;
      wVar7 = (word)((uint)iVar8 >> 0x10);
      sVar9 = (sword)iVar8 + -1;
      iVar8 = CONCAT22(wVar7,sVar9);
    } while ((sVar9 != -1) || (iVar8 = (uint)wVar7 * 0x10000 + -1, wVar7 != 0));
    dword_40C6D28 = dword_40C6D28 | 0x20;
    dword_40C6D14 = 3;
    dword_40C6D0C = sub_40818B4;
    dword_40C6D08 = 0x4081a16;
    _dma_init(&_dsp_var,0x1469);
  }
  if ((param_1 & 4) == 0) {
    if ((dword_40C6E84 & 0x1000) != 0) {
      dword_40C6E84 = dword_40C6E84 & 0xffffefff;
      dword_40C6E76 = 0;
      *_scr2 = *_scr2 & 0x9fffffff;
      sub_40826E6(0);
      _dma_abort(&_dsp_var);
      while (iVar8 = _dma_dequeue(&_dsp_var,1), iVar8 != 0) {
        iVar8 = *(int *)(iVar8 + 0x18);
        if (iVar8 != 0) {
          if (_dsp_var._0_4_ == 0) {
            *(uint *)(iVar8 + 0x34) = *(uint *)(iVar8 + 0x34) | 1;
          }
          (**(code **)(iVar8 + 0x28))(iVar8);
        }
      }
      _snd_stream_queue_reset(dword_40C6DF8);
      _kfree(dword_40C6DF8,0x54);
      dword_40C6DF8 = 0;
    }
  }
  else if ((dword_40C6E84 & 0x1000) == 0) {
    dword_40C6E84 = dword_40C6E84 | 0x1000;
    *_scr2 = *_scr2 | 0x40000000;
    sub_40826E6(1);
    dword_40C6D1C = 0x40000;
    dword_40C6E76 = 2;
    bVar6 = *(byte *)(dword_40C6DF8 + 0x53);
    if (bVar6 == 2) {
      bVar6 = *(byte *)(_slot_id_bmap + 0x2008000) | 0xc1;
loc_40814EA:
      *(byte *)(_slot_id_bmap + 0x2008000) = bVar6;
    }
    else if (bVar6 < 3) {
      if (bVar6 == 1) {
        bVar6 = *(byte *)(_slot_id_bmap + 0x2008000) | 0xe1;
        goto loc_40814EA;
      }
    }
    else if (bVar6 == 4) {
      *_scr2 = *_scr2 | 0x20000000;
      bVar6 = *(byte *)(_slot_id_bmap + 0x2008000) | 0xa1;
      goto loc_40814EA;
    }
    dword_40C6D28 = dword_40C6D28 | 0x80;
    dword_40C6D14 = 1;
    dword_40C6D0C = _dsp_dev_loop;
    _dma_init(&_dsp_var,0x1469);
    iVar8 = dword_40C6DF8;
    if (dword_40C6DF8 != 0) {
      piVar5 = (int *)(dword_40C6DF8 + 0x3e);
      piVar10 = (int *)*piVar5;
      while (piVar5 != piVar10) {
        iVar1 = *piVar5;
        piVar10 = *(int **)(iVar1 + 0x2c);
        if (piVar10 == piVar5) {
          *(int **)(iVar8 + 0x42) = piVar5;
        }
        else {
          piVar10[0xc] = (int)piVar5;
        }
        *piVar5 = (int)piVar10;
        _dma_enqueue(&_dsp_var,iVar1 + 0xc);
        piVar10 = (int *)*piVar5;
      }
    }
    iVar8 = 0x12;
    piVar10 = &unk_40C6E3C;
    do {
      if (*piVar10 != 0) {
        *(code **)(*piVar10 + 0x3a) = _dspq_start_simple;
      }
      piVar10 = piVar10 + -1;
      wVar7 = (word)((uint)iVar8 >> 0x10);
      sVar9 = (sword)iVar8 + -1;
      iVar8 = CONCAT22(wVar7,sVar9);
    } while ((sVar9 != -1) || (iVar8 = (uint)wVar7 * 0x10000 + -1, wVar7 != 0));
  }
  iVar8 = dword_40C6DFC;
  if ((param_1 & 0x20) == 0) {
    if (((param_1 & 2) == 0) && (dword_40C6E84 = dword_40C6E84 & 0xfffeffff, dword_40C6DFC != 0)) {
      piVar5 = (int *)(dword_40C6DFC + 0x3e);
      piVar10 = (int *)*piVar5;
      while (piVar5 != piVar10) {
        iVar1 = *piVar5;
        piVar10 = *(int **)(iVar1 + 0x2c);
        if (piVar10 == piVar5) {
          *(int **)(iVar8 + 0x42) = piVar5;
        }
        else {
          piVar10[0xc] = (int)piVar5;
        }
        *piVar5 = (int)piVar10;
        if (piVar10 == piVar5) {
          *(uint *)(iVar1 + 0x34) = *(uint *)(iVar1 + 0x34) | 1;
        }
        (**(code **)(iVar1 + 0x28))(iVar1);
        piVar10 = (int *)*piVar5;
      }
      _snd_stream_queue_reset(dword_40C6DFC);
      _kfree(dword_40C6DFC,0x54);
      dword_40C6DFC = 0;
    }
  }
  else {
    dword_40C6E84 = dword_40C6E84 | 0x10000;
  }
  if (((param_1 & 8) != 0) && ((dword_40C6E84 & 0x10) == 0)) {
    dword_40C6E84 = dword_40C6E84 | 0x10;
    _snd_link_init(0);
  }
  if (((param_1 & 0x10) != 0) && ((dword_40C6E84 & 0x20) == 0)) {
    dword_40C6E84 = dword_40C6E84 | 0x20;
    _snd_link_init(1);
  }
  if ((param_1 & 0x400) == 0) {
    if (_dma_chip != 0x139) {
      *_scr2 = *_scr2 & 0xff7fffff;
    }
    if (_bmap_chip == 0) goto loc_4081776;
    bVar6 = *(byte *)(_bmap_chip + 0xc) & 0xef;
  }
  else {
    if (_dma_chip != 0x139) {
      *_scr2 = *_scr2 | 0x800000;
    }
    if (_bmap_chip == 0) goto loc_4081776;
    bVar6 = *(byte *)(_bmap_chip + 0xc) | 0x10;
  }
  *(byte *)(_bmap_chip + 0xc) = bVar6;
loc_4081776:
  if (((dword_40C6E84 & 0x2c00) == 0) && ((dword_40C6E84 & 0x100) != 0)) {
    bVar6 = *(byte *)(_slot_id_bmap + 0x2008000) & 0xfe;
  }
  else {
    bVar6 = *(byte *)(_slot_id_bmap + 0x2008000) | 1;
  }
  *(byte *)(_slot_id_bmap + 0x2008000) = bVar6;
  return;
}

