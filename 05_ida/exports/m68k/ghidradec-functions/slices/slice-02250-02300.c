/* GHIDRADEC_FUNCTION index=2250 start=0x408046e */

int _snd_device_probe(int param_1,int param_2)

{
  if (param_2 == 0) {
    param_1 = _slot_id + param_1;
  }
  else {
    param_1 = 0;
  }
  return param_1;
}
/* GHIDRADEC_FUNCTION index=2251 start=0x408048a */

undefined4 _snd_device_attach(void)

{
  dword_40B507C = _slot_id + 0x200e000;
  _mon_csr_and(0xffffff7f);
  _mon_csr_or(0x20);
  _mon_csr_and(0xfffffff7);
  _mon_csr_or(2);
  _mon_send(3,0);
  _mon_send(7,0);
  _mon_send(0xc4,0xff);
  _install_scanned_intr(0x835,_snd_dev_intr,0);
  return 0;
}
/* GHIDRADEC_FUNCTION index=2252 start=0x408050e */

undefined4 _snd_device_def_dmasize(int param_1)

{
  undefined4 uVar1;
  
  uVar1 = 0x100;
  if (param_1 == 0) {
    uVar1 = _page_size;
  }
  return uVar1;
}
/* GHIDRADEC_FUNCTION index=2253 start=0x4080528 */

undefined4 _snd_device_def_high_water(int param_1)

{
  undefined4 uVar1;
  
  uVar1 = 0x10000;
  if (param_1 == 0) {
    uVar1 = 0xc0000;
  }
  return uVar1;
}
/* GHIDRADEC_FUNCTION index=2254 start=0x408053e */

undefined4 _snd_device_def_low_water(int param_1)

{
  undefined4 uVar1;
  
  uVar1 = 0xc000;
  if (param_1 == 0) {
    uVar1 = 0x80000;
  }
  return uVar1;
}
/* GHIDRADEC_FUNCTION index=2255 start=0x4080556 */

undefined4 _snd_dsp_cmd_port_msg(int param_1)

{
  undefined4 uVar1;
  
  switch(*(undefined4 *)(param_1 + 0x14)) {
  case :
    uVar1 = sub_408067A(param_1);
    break;
  case :
    uVar1 = sub_4080B2E(param_1);
    break;
  case :
    uVar1 = sub_4080BE6(param_1);
    break;
  case :
    uVar1 = sub_4080D78(param_1);
    break;
  case :
    uVar1 = sub_4080E6E(param_1);
    break;
  case :
    uVar1 = sub_4080F78(param_1);
    break;
  case :
    uVar1 = sub_4080F82(param_1);
    break;
  case :
    uVar1 = sub_4080FE0(param_1);
    break;
  :
    uVar1 = 0x66;
  }
  return uVar1;
}
/* GHIDRADEC_FUNCTION index=2256 start=0x4080d04 */

int _snd_dspcmd_def_dmasize(int param_1)

{
  byte bVar1;
  int iVar2;
  uint uVar3;
  
  uVar3 = (uint)*(word *)((&unk_40C6DF4)[param_1] + 0x4e);
  bVar1 = *(byte *)((&unk_40C6DF4)[param_1] + 0x53);
  if (bVar1 == 5) {
    iVar2 = uVar3 * 2;
  }
  else {
    iVar2 = uVar3 * bVar1;
  }
  return iVar2;
}
/* GHIDRADEC_FUNCTION index=2257 start=0x4080d3a */

undefined8 _snd_dspcmd_def_high_water(int param_1)

{
  undefined4 uVar1;
  undefined4 uVar2;
  
  uVar2 = 1;
  if (param_1 == 1) {
    uVar1 = 0xc0000;
  }
  else {
    uVar2 = 2;
    uVar1 = 0x10000;
  }
  return CONCAT44(uVar1,uVar2);
}
/* GHIDRADEC_FUNCTION index=2258 start=0x4080d58 */

undefined8 _snd_dspcmd_def_low_water(int param_1)

{
  undefined4 uVar1;
  undefined4 uVar2;
  
  uVar2 = 1;
  if (param_1 == 1) {
    uVar1 = 0x80000;
  }
  else {
    uVar2 = 2;
    uVar1 = 0xc000;
  }
  return CONCAT44(uVar1,uVar2);
}
/* GHIDRADEC_FUNCTION index=2259 start=0x408103e */

void _dsp_dev_init(void)

{
  dword_40C6D18 = _slot_id + 0x20000d0;
  dword_40C6D28 = 5;
  dword_40C6D10 = 0;
  dword_40C6E84 = 0;
  dword_40C6E7C = 0;
  dword_40C6E80 = 0;
  dword_40C6E5E = 0;
  _dspq_init_lmsg();
  sub_40826E6(0);
  return;
}
/* GHIDRADEC_FUNCTION index=2260 start=0x408108c */

void _dsp_dev_reset(void)

{
  if (dword_40C6E72 != 0) {
    dword_40C6E6A = 0;
    dword_40C6E6E = 0;
    _dspq_free_msg(dword_40C6E72);
  }
  dword_40C6E76 = 0;
  word_40C6E7A = 0;
  dword_40C6E84 = dword_40C6E84 | 0x20000;
  _dsp_dev_new_proto(0);
  _dspq_reset_lmsg();
  sub_40826E6(1);
  _install_scanned_intr(0xe40,sub_40818B4,0);
  return;
}
/* GHIDRADEC_FUNCTION index=2261 start=0x40810f6 */

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
/* GHIDRADEC_FUNCTION index=2262 start=0x40817ca */

void _dsp_dev_reset_hard(void)

{
  _dsp_dev_reset_chip();
  _dsp_dev_reset();
  return;
}
/* GHIDRADEC_FUNCTION index=2263 start=0x40817de */

undefined8 _dsp_dev_reset_chip(void)

{
  uint uVar1;
  int unaff_D2;
  char in_XF;
  bool bVar2;
  
  *_scr2 = *_scr2 & 0x7ffffff;
  if ((_machine_type != '\0') || (1 < _board_rev)) {
    if (_dma_chip == 0x139) {
      uVar1 = *_scr2 | 0x20;
    }
    else {
      uVar1 = *_scr2 & 0xffffffdf;
    }
    *_scr2 = uVar1;
  }
  *_scr2 = *_scr2 | 0x10000000;
  *_scr2 = *_scr2 | 0x80000000;
  uVar1 = *_scr2 & 0xefffffff;
  *_scr2 = uVar1;
  if ((_machine_type != '\0') || (bVar2 = _board_rev == 0, 1 < _board_rev)) {
    bVar2 = _dma_chip < 0x139;
    if (_dma_chip == 0x139) {
      uVar1 = *_scr2 & 0xffffffdf;
    }
    else {
      uVar1 = *_scr2 | 0x20;
    }
    *_scr2 = uVar1;
  }
  *(undefined *)(_slot_id_bmap + 0x2008000) = 0;
  return CONCAT44(CONCAT22((sword)(uVar1 >> 0x10),(word)(byte)(bVar2 << 4 | 4)),
                  (int)(sword)(word)(byte)(in_XF << 4 | (unaff_D2 < 0) << 3 | (unaff_D2 == 0) << 2))
  ;
}
/* GHIDRADEC_FUNCTION index=2264 start=0x4081b04 */

uint _dsp_dev_loop(void)

{
  byte bVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  undefined4 uVar6;
  int iVar7;
  int iVar8;
  uint *puVar9;
  undefined4 *puVar10;
  bool bVar11;
  bool bVar12;
  bool bVar13;
  char cVar14;
  bool bVar15;
  code *pcVar16;
  
  if (dword_40C6E76 == 7) {
    return 7;
  }
  uVar5 = _curipl();
  uVar4 = dword_40B21C4;
  if (uVar5 == dword_40B21C4) {
    return uVar5;
  }
  dword_40B21C4 = _curipl();
  if ((dword_40C6E84 & 0x2000) == 0) {
    if ((dword_40C6E84 & 0x1000) == 0) {
      if ((dword_40C6E84 & 0xc00) == 0) {
        uVar5 = dword_40C6E84 & 0x100;
        goto joined_r0x04081c58;
      }
loc_4081C5A:
      *(byte *)(_slot_id_bmap + 0x2008000) = *(byte *)(_slot_id_bmap + 0x2008000) | 1;
    }
    else {
      while (iVar8 = _dma_dequeue(&_dsp_var,0), iVar8 != 0) {
        iVar8 = *(int *)(iVar8 + 0x18);
        *(int *)(dword_40C6DF8 + 0x26) = *(int *)(iVar8 + 4) + *(int *)(dword_40C6DF8 + 0x26);
        if (_dsp_var._0_4_ == 0) {
          *(uint *)(iVar8 + 0x34) = *(uint *)(iVar8 + 0x34) | 1;
        }
        (**(code **)(iVar8 + 0x28))(iVar8);
      }
    }
  }
  else if (((dword_40C6E76 == 6) || (dword_40C6E76 == 2)) && (unk_40C6D04 == 0)) {
    iVar8 = (&unk_40C6DF4)[word_40C6E40];
    if (*(byte *)(iVar8 + 0x53) == 5) {
      iVar7 = (uint)*(word *)(iVar8 + 0x4e) * 2;
    }
    else {
      iVar7 = (uint)*(byte *)(iVar8 + 0x53) * (uint)*(word *)(iVar8 + 0x4e);
    }
    uVar6 = 0;
    if (dword_40C6E76 == 2) {
      uVar6 = 0x40000;
    }
    sub_40824BC(iVar7,word_40C6E40,*(undefined *)(iVar8 + 0x53),uVar6);
    iVar8 = 0x14;
    do {
      uVar5 = dword_40C6E76;
      if (dword_40C6E76 == 0) break;
      _dspq_execute();
      iVar8 = iVar8 + -1;
      uVar5 = dword_40C6E76;
    } while (iVar8 != 0);
joined_r0x04081c58:
    if (uVar5 == 0) goto loc_4081C5A;
  }
  if ((word_40C6E7A == 1) &&
     (iVar8 = (&unk_40C6DF4)[word_40C6E40], (int *)(iVar8 + 0x3e) != *(int **)(iVar8 + 0x3e))) {
    sub_40821FA(dword_40C6E42,*(undefined2 *)(iVar8 + 0x50),*(undefined *)(iVar8 + 0x52),
                *(undefined *)(iVar8 + 0x53),0x40000);
    word_40C6E7A = word_40C6E7A | 2;
  }
loc_4081CE0:
  if ((((((*(byte *)(_slot_id_bmap + 0x2008002) & 1) == 0) ||
        (((dword_40C6E84 & 0x2c00) == 0 && ((dword_40C6E84 & 0x100) != 0)))) ||
       (dword_40C6E5A == (uint *)0x0)) ||
      ((dword_40C6E56 <= dword_40C6E5A ||
       (((((dword_40C6E66 != (uint *)0x0 && (dword_40C6E62 <= dword_40C6E66)) ||
          (dword_40C6E76 == 2)) || ((dword_40C6E76 == 6 || (dword_40C6E76 == 1)))) ||
        (dword_40C6E76 == 3)))))) &&
     (((dword_40C6E76 != 1 && (dword_40C6E76 != 4)) && (dword_40C6E76 != 5)))) {
    cVar14 = dword_40C6E46 < &dword_40C6E46;
    if ((undefined4 **)dword_40C6E46 == &dword_40C6E46) {
      if (((dword_40C6E84 & 0x10000) == 0) || (dword_40C6DFC == 0)) goto loc_40820F4;
      puVar9 = (uint *)(dword_40C6DFC + 0x3e);
      cVar14 = puVar9 < (uint *)*puVar9;
      if (puVar9 == (uint *)*puVar9) goto loc_40820F4;
    }
    iVar8 = _dspq_check();
    if (iVar8 == 0) goto loc_40820F4;
  }
  if (((undefined4 **)dword_40C6E46 != &dword_40C6E46) ||
     ((((dword_40C6E84 & 0x10000) != 0 && (dword_40C6DFC != 0)) &&
      ((int *)(dword_40C6DFC + 0x3e) != *(int **)(dword_40C6DFC + 0x3e))))) {
    _dspq_execute();
  }
  if ((dword_40C6E84 & 0x2000) != 0) {
    iVar8 = (&unk_40C6DF4)[word_40C6E40];
    if (dword_40C6E76 == 4) {
      puVar9 = (uint *)(iVar8 + 0x3e);
      cVar14 = puVar9 < (uint *)*puVar9;
      if (puVar9 == (uint *)*puVar9) goto loc_40820F4;
      dword_40C6E76 = 5;
      sub_40821FA(dword_40C6E42,*(undefined2 *)(iVar8 + 0x50),*(undefined *)(iVar8 + 0x52),
                  *(undefined *)(iVar8 + 0x53),0);
      goto loc_4081CE0;
    }
    if (dword_40C6E76 < 5) {
      if (dword_40C6E76 != 1) goto loc_4081ED2;
      puVar9 = (uint *)(iVar8 + 0x3e);
      cVar14 = puVar9 < (uint *)*puVar9;
      if (puVar9 == (uint *)*puVar9) goto loc_40820F4;
      bVar1 = *(byte *)(iVar8 + 0x53);
      if (bVar1 == 5) {
        iVar8 = (uint)*(word *)(iVar8 + 0x4e) * 2;
      }
      else {
        iVar8 = (uint)bVar1 * (uint)*(word *)(iVar8 + 0x4e);
      }
      sub_408229E(iVar8,word_40C6E40,(uint)bVar1,0x40000);
      if (word_40C6E40 == 0) {
        word_40C6E7A = 0;
      }
      dword_40C6E76 = 2;
      goto loc_4081CE0;
    }
    if (dword_40C6E76 == 5) {
      bVar1 = *(byte *)(iVar8 + 0x53);
      if (bVar1 == 5) {
        iVar8 = (uint)*(word *)(iVar8 + 0x4e) * 2;
      }
      else {
        iVar8 = (uint)bVar1 * (uint)*(word *)(iVar8 + 0x4e);
      }
      sub_408229E(iVar8,word_40C6E40,(uint)bVar1,0);
      dword_40C6E76 = 6;
      goto loc_4081CE0;
    }
  }
loc_4081ED2:
  if (((*(byte *)(_slot_id_bmap + 0x2008002) & 1) != 0) &&
     (((dword_40C6E84 & 0x2c00) != 0 || ((dword_40C6E84 & 0x100) == 0)))) {
    if (dword_40C6E5A == (uint *)0x0) {
loc_40820C4:
      if ((dword_40C6E66 == (uint *)0x0) || (dword_40C6E66 != dword_40C6E62)) goto loc_4081CE0;
      goto loc_40820D8;
    }
    if (((dword_40C6E5A < dword_40C6E56) &&
        ((((dword_40C6E66 == (uint *)0x0 || (dword_40C6E66 < dword_40C6E62)) && (dword_40C6E76 != 1)
          ) && ((dword_40C6E76 != 2 && (dword_40C6E76 != 6)))))) && (dword_40C6E76 != 3)) {
      if (_cpu_type == '\0') {
        uVar5 = *(uint *)(_slot_id_bmap + 0x2008004);
      }
      else {
        uVar5 = CONCAT31((uint3)*(byte *)(_slot_id_bmap + 0x2008006) |
                         (uint3)(((uint)*(byte *)(_slot_id_bmap + 0x2008005) << 0x10) >> 8),
                         *(undefined *)(_slot_id_bmap + 0x2008007));
      }
      uVar2 = uVar5 & 0x7fff;
      uVar3 = uVar5 & 0xff0000;
      if (uVar3 == 0x40000) {
        if ((((dword_40C6E84 & 0x2000) != 0) && (dword_40C6E76 == 0)) &&
           ((uVar2 < 0x13 && ((&unk_40C6DF4)[uVar2] != 0)))) {
          dword_40C6E76 = 4;
          dword_40C6E42 = 0;
          word_40C6E40 = (word)uVar2;
          goto loc_4081CE0;
        }
      }
      else if (uVar3 < 0x40001) {
        if ((uVar3 == 0x10000) && ((dword_40C6E84 & 0x401) == 0x401)) {
          dword_40C6E84 = dword_40C6E84 & 0xfffffffe;
          goto loc_4081CE0;
        }
      }
      else if (uVar3 == 0x50000) {
        if ((((dword_40C6E84 & 0x2000) != 0) &&
            (((uVar2 != 0 || ((word_40C6E7A & 2) != 0)) && (dword_40C6E76 == 0)))) &&
           ((uVar2 < 0x13 && ((&unk_40C6DF4)[uVar2] != 0)))) {
          dword_40C6E76 = 1;
          word_40C6E40 = (word)uVar2;
          goto loc_4081CE0;
        }
      }
      else if ((uVar3 == 0xa0000) && ((dword_40C6E84 & 0x400) != 0)) goto loc_4081CE0;
      if ((((dword_40C6E84 & 0x800) == 0) || ((uVar5 & 0x800000) == 0)) ||
         (dword_40C6E66 == (uint *)0x0)) {
        *dword_40C6E5A = uVar5;
        dword_40C6E5A = dword_40C6E5A + 1;
        puVar10 = &dword_40C6E7C;
        if (dword_40C6E7C != 0) {
          pcVar16 = _snd_reply_dsp_msg;
          iVar8 = dword_40C6E7C;
          goto loc_40820A4;
        }
      }
      else {
        *dword_40C6E66 = uVar5;
        dword_40C6E66 = dword_40C6E66 + 1;
        puVar10 = &dword_40C6E80;
        if (dword_40C6E80 != 0) {
          pcVar16 = _snd_reply_dsp_err;
          iVar8 = dword_40C6E80;
loc_40820A4:
          _callout_dispatch(4,pcVar16,iVar8);
          *puVar10 = 0;
        }
      }
    }
  }
  if ((dword_40C6E5A == (uint *)0x0) || (dword_40C6E5A != dword_40C6E56)) goto loc_40820C4;
loc_40820D8:
  *(byte *)(_slot_id_bmap + 0x2008000) = *(byte *)(_slot_id_bmap + 0x2008000) & 0xfe;
  goto loc_4081CE0;
loc_40820F4:
  if (dword_40C6E76 == 0) {
    uVar5 = _dspq_awaited_conditions();
    if (((uVar5 & 2) != 0) && ((*(byte *)(_slot_id_bmap + 0x2008002) & 1) == 0)) {
      *(byte *)(_slot_id_bmap + 0x2008000) = *(byte *)(_slot_id_bmap + 0x2008000) | 1;
    }
    if ((((uVar5 & 4) != 0) && ((*(byte *)(_slot_id_bmap + 0x2008002) & 2) == 0)) &&
       (uVar5 = (uint)(sword)(word)(byte)(cVar14 << 4 |
                                          ((char)*(byte *)(_slot_id_bmap + 0x2008002) < '\0') << 3 |
                                         4), cVar14 = uVar5 < uVar4, (int)uVar4 < (int)uVar5)) {
      *(byte *)(_slot_id_bmap + 0x2008000) = *(byte *)(_slot_id_bmap + 0x2008000) | 2;
    }
  }
  else {
    cVar14 = 4 < dword_40C6E76;
    if ((dword_40C6E76 == 4) || (cVar14 = 1 < dword_40C6E76, dword_40C6E76 == 1)) {
      *(byte *)(_slot_id_bmap + 0x2008000) = *(byte *)(_slot_id_bmap + 0x2008000) & 0xfe;
      *(byte *)(_slot_id_bmap + 0x2008000) = *(byte *)(_slot_id_bmap + 0x2008000) & 0xfd;
    }
  }
  if ((dword_40C6E5A == (uint *)0x0) ||
     (cVar14 = dword_40C6E5A < dword_40C6E56, dword_40C6E5A != dword_40C6E56)) {
    bVar11 = (int)dword_40C6E66 < 0;
    bVar13 = false;
    bVar12 = true;
    bVar15 = false;
    if (dword_40C6E66 == (uint *)0x0) goto loc_40821E2;
    cVar14 = dword_40C6E66 < dword_40C6E62;
    bVar13 = SBORROW4((int)dword_40C6E66,(int)dword_40C6E62);
    bVar11 = (int)dword_40C6E66 - (int)dword_40C6E62 < 0;
    bVar12 = false;
    bVar15 = (bool)cVar14;
    if (dword_40C6E66 != dword_40C6E62) goto loc_40821E2;
  }
  bVar1 = *(byte *)(_slot_id_bmap + 0x2008000) & 0xfe;
  *(byte *)(_slot_id_bmap + 0x2008000) = bVar1;
  bVar11 = (char)bVar1 < '\0';
  bVar12 = bVar1 == 0;
  bVar13 = false;
  bVar15 = false;
loc_40821E2:
  dword_40B21C4 = uVar4;
  return (uint)(byte)(cVar14 << 4 | bVar11 << 3 | bVar12 << 2 | bVar13 << 1 | bVar15);
}
/* GHIDRADEC_FUNCTION index=2265 start=0x4082764 */

void _dspq_init_lmsg(void)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  int iVar3;
  
  dword_40C6E4A = &dword_40C6E46;
  dword_40C6E46 = &dword_40C6E46;
  dword_40C6E4E = 0;
  dword_40B5094 = &dword_40B5090;
  dword_40B5090 = &dword_40B5090;
  dword_40B509C = &dword_40B5098;
  dword_40B5098 = &dword_40B5098;
  iVar3 = 0x14;
  do {
    puVar2 = (undefined4 *)_kalloc(0xa6);
    puVar1 = puVar2;
    if ((undefined4 **)dword_40B5094 != &dword_40B5090) {
      dword_40B5094[6] = puVar2;
      puVar1 = dword_40B5090;
    }
    dword_40B5090 = puVar1;
    puVar2[7] = dword_40B5094;
    puVar2[6] = &dword_40B5090;
    dword_40B5094 = puVar2;
    iVar3 = iVar3 + -1;
  } while (iVar3 != 0);
  return;
}
/* GHIDRADEC_FUNCTION index=2266 start=0x40827e2 */

void _dspq_reset_lmsg(void)

{
  undefined4 *puVar1;
  
  if ((undefined4 **)dword_40C6E46 != &dword_40C6E46) {
    do {
      puVar1 = dword_40C6E46;
      dword_40C6E46 = (undefined4 *)dword_40C6E46[6];
      if ((undefined4 **)dword_40C6E46 == &dword_40C6E46) {
        dword_40C6E4A = &dword_40C6E46;
      }
      else {
        dword_40C6E46[7] = &dword_40C6E46;
      }
      _dspq_free_msg(puVar1);
    } while ((undefined4 **)dword_40C6E46 != &dword_40C6E46);
  }
  if ((undefined4 **)dword_40B5090 != &dword_40B5090) {
    do {
      puVar1 = dword_40B5090;
      dword_40B5090 = (undefined4 *)dword_40B5090[6];
      if ((undefined4 **)dword_40B5090 == &dword_40B5090) {
        dword_40B5094 = &dword_40B5090;
      }
      else {
        dword_40B5090[7] = &dword_40B5090;
      }
      _kfree(puVar1,0xa6);
    } while ((undefined4 **)dword_40B5090 != &dword_40B5090);
  }
  if ((undefined4 **)dword_40B5098 != &dword_40B5098) {
    _dspq_free_msg(0);
  }
  return;
}
/* GHIDRADEC_FUNCTION index=2267 start=0x40829e4 */

void _dspq_enqueue_hc(undefined4 param_1)

{
  undefined4 ***pppuVar1;
  undefined4 ***pppuVar2;
  undefined4 **ppuStack_c;
  undefined4 **ppuStack_8;
  
  ppuStack_c = &ppuStack_c;
  ppuStack_8 = &ppuStack_c;
  pppuVar2 = (undefined4 ***)sub_408288E(param_1);
  *(undefined *)((int)pppuVar2 + 0x21) = 0;
  pppuVar1 = pppuVar2;
  if ((undefined4 ***)ppuStack_8 != &ppuStack_c) {
    ppuStack_8[6] = pppuVar2;
    pppuVar1 = (undefined4 ***)ppuStack_c;
  }
  ppuStack_c = pppuVar1;
  pppuVar2[7] = ppuStack_8;
  pppuVar2[6] = &ppuStack_c;
  ppuStack_8 = pppuVar2;
  _dspq_enqueue(&ppuStack_c);
  return;
}
/* GHIDRADEC_FUNCTION index=2268 start=0x4082a3a */

void _dspq_enqueue_hm(undefined4 *param_1)

{
  undefined4 ***pppuVar1;
  undefined4 ***pppuVar2;
  undefined4 **ppuStack_c;
  undefined4 **ppuStack_8;
  
  ppuStack_c = &ppuStack_c;
  ppuStack_8 = &ppuStack_c;
  pppuVar2 = (undefined4 ***)sub_4082936(0xc00,0x400);
  *(undefined *)((int)pppuVar2 + 0x21) = 1;
  pppuVar1 = pppuVar2;
  if ((undefined4 ***)ppuStack_8 != &ppuStack_c) {
    ppuStack_8[6] = pppuVar2;
    pppuVar1 = (undefined4 ***)ppuStack_c;
  }
  ppuStack_c = pppuVar1;
  pppuVar2[7] = ppuStack_8;
  pppuVar2[6] = &ppuStack_c;
  ppuStack_8 = pppuVar2;
  pppuVar2 = (undefined4 ***)sub_40828DE();
  *pppuVar2[1] = param_1;
  pppuVar2[2] = (undefined4 **)0x4;
  *(undefined *)((int)pppuVar2 + 0x21) = 3;
  pppuVar1 = pppuVar2;
  if ((undefined4 ***)ppuStack_8 != &ppuStack_c) {
    ppuStack_8[6] = pppuVar2;
    pppuVar1 = (undefined4 ***)ppuStack_c;
  }
  ppuStack_c = pppuVar1;
  pppuVar2[7] = ppuStack_8;
  pppuVar2[6] = &ppuStack_c;
  ppuStack_8 = pppuVar2;
  pppuVar2 = (undefined4 ***)sub_408288E(0x13);
  *(undefined *)((int)pppuVar2 + 0x21) = 2;
  pppuVar1 = pppuVar2;
  if ((undefined4 ***)ppuStack_8 != &ppuStack_c) {
    ppuStack_8[6] = pppuVar2;
    pppuVar1 = (undefined4 ***)ppuStack_c;
  }
  ppuStack_c = pppuVar1;
  pppuVar2[7] = ppuStack_8;
  pppuVar2[6] = &ppuStack_c;
  ppuStack_8 = pppuVar2;
  _dspq_enqueue(&ppuStack_c);
  return;
}
/* GHIDRADEC_FUNCTION index=2269 start=0x4082b0a */

void _dspq_enqueue_syscall(undefined4 *param_1)

{
  undefined4 ***pppuVar1;
  undefined4 ***pppuVar2;
  undefined4 **ppuStack_c;
  undefined4 **ppuStack_8;
  
  ppuStack_c = &ppuStack_c;
  ppuStack_8 = &ppuStack_c;
  pppuVar2 = (undefined4 ***)sub_4082936(0x800c00,0x400);
  *(undefined *)((int)pppuVar2 + 0x21) = 1;
  pppuVar1 = pppuVar2;
  if ((undefined4 ***)ppuStack_8 != &ppuStack_c) {
    ppuStack_8[6] = pppuVar2;
    pppuVar1 = (undefined4 ***)ppuStack_c;
  }
  ppuStack_c = pppuVar1;
  pppuVar2[7] = ppuStack_8;
  pppuVar2[6] = &ppuStack_c;
  ppuStack_8 = pppuVar2;
  pppuVar2 = (undefined4 ***)sub_408288E(0x16);
  *(undefined *)((int)pppuVar2 + 0x21) = 3;
  pppuVar1 = pppuVar2;
  if ((undefined4 ***)ppuStack_8 != &ppuStack_c) {
    ppuStack_8[6] = pppuVar2;
    pppuVar1 = (undefined4 ***)ppuStack_c;
  }
  ppuStack_c = pppuVar1;
  pppuVar2[7] = ppuStack_8;
  pppuVar2[6] = &ppuStack_c;
  ppuStack_8 = pppuVar2;
  pppuVar2 = (undefined4 ***)sub_40828DE();
  *pppuVar2[1] = param_1;
  pppuVar2[2] = (undefined4 **)0x4;
  *(undefined *)((int)pppuVar2 + 0x21) = 2;
  pppuVar1 = pppuVar2;
  if ((undefined4 ***)ppuStack_8 != &ppuStack_c) {
    ppuStack_8[6] = pppuVar2;
    pppuVar1 = (undefined4 ***)ppuStack_c;
  }
  ppuStack_c = pppuVar1;
  pppuVar2[7] = ppuStack_8;
  pppuVar2[6] = &ppuStack_c;
  ppuStack_8 = pppuVar2;
  _dspq_enqueue(&ppuStack_c);
  return;
}
/* GHIDRADEC_FUNCTION index=2270 start=0x4082bdc */

void _dspq_enqueue_hf(undefined4 param_1,undefined4 param_2)

{
  undefined4 ***pppuVar1;
  undefined4 ***pppuVar2;
  undefined4 **ppuStack_c;
  undefined4 **ppuStack_8;
  
  ppuStack_c = &ppuStack_c;
  ppuStack_8 = &ppuStack_c;
  pppuVar2 = (undefined4 ***)sub_408298E(param_1,param_2);
  *(undefined *)((int)pppuVar2 + 0x21) = 0;
  pppuVar1 = pppuVar2;
  if ((undefined4 ***)ppuStack_8 != &ppuStack_c) {
    ppuStack_8[6] = pppuVar2;
    pppuVar1 = (undefined4 ***)ppuStack_c;
  }
  ppuStack_c = pppuVar1;
  pppuVar2[7] = ppuStack_8;
  pppuVar2[6] = &ppuStack_c;
  ppuStack_8 = pppuVar2;
  _dspq_enqueue(&ppuStack_c);
  return;
}
/* GHIDRADEC_FUNCTION index=2271 start=0x4082c36 */

void _dspq_enqueue_cond(undefined4 param_1,undefined4 param_2)

{
  undefined4 ***pppuVar1;
  undefined4 ***pppuVar2;
  undefined4 **ppuStack_c;
  undefined4 **ppuStack_8;
  
  ppuStack_c = &ppuStack_c;
  ppuStack_8 = &ppuStack_c;
  pppuVar2 = (undefined4 ***)sub_4082936(param_1,param_2);
  *(undefined *)((int)pppuVar2 + 0x21) = 0;
  pppuVar1 = pppuVar2;
  if ((undefined4 ***)ppuStack_8 != &ppuStack_c) {
    ppuStack_8[6] = pppuVar2;
    pppuVar1 = (undefined4 ***)ppuStack_c;
  }
  ppuStack_c = pppuVar1;
  pppuVar2[7] = ppuStack_8;
  pppuVar2[6] = &ppuStack_c;
  ppuStack_8 = pppuVar2;
  _dspq_enqueue(&ppuStack_c);
  return;
}
/* GHIDRADEC_FUNCTION index=2272 start=0x4082c90 */

/* WARNING: Removing unreachable block (ram,0x04082cfa) */

void _dspq_enqueue_state(undefined4 param_1)

{
  undefined4 *puVar1;
  undefined4 *puStack_c;
  undefined4 *puStack_8;
  
  puStack_c = dword_40B5090;
  puVar1 = (undefined4 *)dword_40B5090[6];
  if ((undefined4 **)puVar1 == &dword_40B5090) {
    dword_40B5094 = &dword_40B5090;
  }
  else {
    puVar1[7] = &dword_40B5090;
  }
  *dword_40B5090 = 0xc;
  dword_40B5090 = puVar1;
  puStack_c[1] = param_1;
  *(undefined *)(puStack_c + 8) = 0;
  *(undefined *)(puStack_c + 9) = 1;
  *(undefined *)((int)puStack_c + 0x23) = 0;
  *(undefined *)((int)puStack_c + 0x22) = 1;
  *(undefined *)((int)puStack_c + 0x21) = 0;
  puStack_c[7] = &puStack_c;
  puStack_c[6] = &puStack_c;
  puStack_8 = puStack_c;
  _dspq_enqueue(&puStack_c);
  return;
}
/* GHIDRADEC_FUNCTION index=2273 start=0x4082d1e */

void _dspq_enqueue(int *param_1)

{
  int *piVar1;
  int iVar2;
  byte *pbVar3;
  int iVar4;
  undefined4 *puVar5;
  
  piVar1 = (int *)*param_1;
  pbVar3 = (byte *)(piVar1 + 8);
  iVar4 = 0;
  for (; piVar1 != param_1; piVar1 = (int *)piVar1[6]) {
    iVar4 = iVar4 + 1;
  }
  puVar5 = dword_40C6E46;
  if ((undefined4 **)dword_40C6E46 != &dword_40C6E46) {
    do {
      if ((*pbVar3 < *(byte *)(puVar5 + 8)) &&
         ((*(byte *)((int)puVar5 + 0x21) < 2 || ((puVar5[8] & 0x4ff00) == 0)))) break;
      puVar5 = (undefined4 *)puVar5[6];
    } while ((undefined4 **)puVar5 != &dword_40C6E46);
  }
  if ((undefined4 **)dword_40C6E46 == &dword_40C6E46) {
    dword_40C6E46 = (undefined4 *)*param_1;
    dword_40C6E4A = param_1[1];
    iVar2 = *param_1;
    *(undefined4 ***)(param_1[1] + 0x18) = &dword_40C6E46;
    *(undefined4 ***)(iVar2 + 0x1c) = &dword_40C6E46;
  }
  else {
    if ((undefined4 **)puVar5 == &dword_40C6E46) {
      *(int *)(dword_40C6E4A + 0x18) = *param_1;
      *(int *)(*param_1 + 0x1c) = dword_40C6E4A;
      dword_40C6E4A = param_1[1];
    }
    else {
      if ((undefined4 **)puVar5[7] == &dword_40C6E46) {
        dword_40C6E46 = (undefined4 *)*param_1;
      }
      else {
        ((undefined4 *)puVar5[7])[6] = *param_1;
      }
      *(undefined4 *)(*param_1 + 0x1c) = puVar5[7];
      puVar5[7] = param_1[1];
    }
    *(undefined4 **)(param_1[1] + 0x18) = puVar5;
  }
  dword_40C6E4E = iVar4 + dword_40C6E4E;
  iVar4 = _curipl();
  if (((iVar4 == 0) && (0x1ff < dword_40C6E4E)) && ((dword_40C6E84 & 0x40000) == 0)) {
    _port_set_remove(dword_40C6EC0,0x10013);
    dword_40C6E84 = dword_40C6E84 | 0x40000;
  }
  if ((dword_40C6E84 & 0x40) == 0) {
    _dspq_execute();
  }
  return;
}
/* GHIDRADEC_FUNCTION index=2274 start=0x4082e62 */

undefined4 _dspq_check(void)

{
  uint uVar1;
  
  if (dword_40C6E76 == 7) {
    return 0;
  }
  if (dword_40C6E72 != 0) {
    if (_cpu_type == '\0') {
      uVar1 = *(uint *)(_slot_id_bmap + 0x2008000);
    }
    else {
      uVar1 = CONCAT31((uint3)(((uint)*(byte *)(_slot_id_bmap + 0x2008000) << 0x18) >> 8) |
                       (uint3)(((uint)*(byte *)(_slot_id_bmap + 0x2008001) << 0x10) >> 8) |
                       (uint3)*(byte *)(_slot_id_bmap + 0x2008002),
                       *(undefined *)(_slot_id_bmap + 0x2008003));
    }
    if ((dword_40C6E6A & uVar1) == dword_40C6E6E) {
      return 1;
    }
  }
  if (((((dword_40C6E84 & 0x10000) == 0) || (dword_40C6DFC == 0)) ||
      (dword_40C6DFC + 0x3e == *(int *)(dword_40C6DFC + 0x3e))) ||
     ((*(byte *)(_slot_id_bmap + 0x2008002) & 2) == 0)) {
    if ((undefined4 **)dword_40C6E46 == &dword_40C6E46) {
      return 0;
    }
    switch(*dword_40C6E46) {
    case :
      if (_cpu_type == '\0') {
        uVar1 = *(uint *)(_slot_id_bmap + 0x2008000);
      }
      else {
        uVar1 = (uint)*(byte *)(_slot_id_bmap + 0x2008000) << 0x18 |
                (uint)*(byte *)(_slot_id_bmap + 0x2008001) << 0x10;
        do {
          uVar1 = uVar1 & 0xffff00ff | (uint)*(byte *)(_slot_id_bmap + 0x2008002) << 8;
        } while (*(byte *)(_slot_id_bmap + 0x2008002) != *(byte *)(_slot_id_bmap + 0x2008002));
        uVar1 = CONCAT31((int3)(uVar1 >> 8),*(undefined *)(_slot_id_bmap + 0x2008003));
      }
      if ((dword_40C6E46[1] & uVar1) != dword_40C6E46[2]) {
        return 0;
      }
      break;
    case :
    case :
    case :
    case :
      if ((*(byte *)(_slot_id_bmap + 0x2008002) & 2) == 0) {
        *(byte *)(_slot_id_bmap + 0x2008000) = *(byte *)(_slot_id_bmap + 0x2008000) | 2;
        return 0;
      }
      if ((((dword_40C6E76 != 5) || (*(char *)((int)dword_40C6E46 + 0x21) == '\x01')) ||
          (*(char *)(dword_40C6E46 + 8) != '\0')) &&
         (((dword_40C6E76 == 4 || (dword_40C6E76 == 5)) || (dword_40C6E76 == 6)))) {
        return 0;
      }
      break;
    case :
    case :
      if (dword_40C6E76 != 0) {
        return 0;
      }
      break;
    case :
      if (*(char *)(_slot_id_bmap + 0x2008001) < '\0') {
        return 0;
      }
      break;
    case :
      if (dword_40C6E76 != 0) {
        return 0;
      }
      break;
    case :
    case :
    case :
    case :
      if ((*(byte *)(_slot_id_bmap + 0x2008002) & 1) == 0) {
        *(byte *)(_slot_id_bmap + 0x2008000) = *(byte *)(_slot_id_bmap + 0x2008000) | 1;
        return 0;
      }
      if (((dword_40C6E76 == 1) || (dword_40C6E76 == 2)) || (dword_40C6E76 == 3)) {
        return 0;
      }
    }
  }
  return 1;
}
/* GHIDRADEC_FUNCTION index=2275 start=0x4083130 */

uint _dspq_execute(void)

{
  undefined4 uVar1;
  int *piVar2;
  char *pcVar3;
  sword *psVar4;
  undefined4 *puVar5;
  sword sVar6;
  undefined uVar7;
  undefined uVar8;
  byte *pbVar9;
  byte bVar10;
  char cVar11;
  uint3 uVar12;
  uint3 uVar13;
  uint uVar14;
  int *piVar15;
  uint3 *puVar16;
  uint uVar17;
  int iVar18;
  uint unaff_D4;
  int *piVar19;
  int iVar20;
  uint3 *puVar21;
  uint *puVar22;
  bool bVar23;
  code *pcVar24;
  
  bVar23 = false;
  uVar17 = _curipl();
  uVar14 = dword_40B21C8;
  if (uVar17 != dword_40B21C8) {
    dword_40B21C8 = _curipl();
    if (_cpu_type == '\0') {
      uVar17 = *(uint *)(_slot_id_bmap + 0x2008000);
    }
    else {
      uVar17 = unaff_D4 & 0xff | (uint)*(byte *)(_slot_id_bmap + 0x2008000) << 0x18 |
               (uint)*(byte *)(_slot_id_bmap + 0x2008001) << 0x10 |
               (uint)*(byte *)(_slot_id_bmap + 0x2008002) << 8;
    }
    if ((dword_40C6E72 != 0) && ((dword_40C6E6A & uVar17) == dword_40C6E6E)) {
      _callout_dispatch(4,sub_4083CCA,dword_40C6E72);
      dword_40C6E72 = 0;
    }
    if ((int **)dword_40C6E46 != &dword_40C6E46) {
      do {
        iVar18 = _dspq_check();
        piVar15 = dword_40C6E46;
        if (iVar18 == 0) break;
        piVar2 = (int *)dword_40C6E46[6];
        piVar19 = piVar2;
        if ((int **)piVar2 != &dword_40C6E46) {
          piVar2[7] = (int)&dword_40C6E46;
          piVar19 = dword_40C6E4A;
        }
        dword_40C6E4A = piVar19;
        switch(*dword_40C6E46) {
        case :
          if (dword_40C6E46[3] != 0) {
            if (_cpu_type == '\0') {
              iVar18 = *(int *)(_slot_id_bmap + 0x2008000);
            }
            else {
              iVar18 = (uint)(uint3)((uint3)(((uint)*(byte *)(_slot_id_bmap + 0x2008000) << 0x18) >>
                                            8) |
                                     (uint3)(((uint)*(byte *)(_slot_id_bmap + 0x2008001) << 0x10) >>
                                            8) | (uint3)*(byte *)(_slot_id_bmap + 0x2008002)) << 8;
            }
            piVar19 = dword_40C6E46 + 5;
            dword_40C6E46 = piVar2;
            *piVar19 = iVar18;
            pcVar24 = _snd_reply_dsp_cond_true;
            piVar19 = piVar15;
            goto loc_40838DC;
          }
          break;
        case :
          iVar18 = dword_40C6E46[2] - (dword_40C6E46[3] - dword_40C6E46[1]);
          dword_40C6E46 = piVar2;
          for (; 0 < iVar18; iVar18 = iVar18 + -1) {
            pcVar3 = (char *)piVar15[3];
            piVar15[3] = (int)(pcVar3 + 1);
            cVar11 = *pcVar3;
            iVar20 = 0x32;
            bVar10 = *(byte *)(_slot_id_bmap + 0x2008002);
            while ((bVar10 & 2) == 0) {
              _delay(2);
              iVar20 = iVar20 + -1;
              if (iVar20 == 0) goto loc_4083360;
              bVar10 = *(byte *)(_slot_id_bmap + 0x2008002);
            }
            if (iVar20 != 0) {
              if (_cpu_type == '\0') {
                *(int *)(_slot_id_bmap + 0x2008004) = (int)cVar11;
              }
              else {
                *(char *)(_slot_id_bmap + 0x2008005) = (char)cVar11 >> 7;
                *(char *)(_slot_id_bmap + 0x2008006) = cVar11 >> 7;
                *(char *)(_slot_id_bmap + 0x2008007) = cVar11;
              }
            }
loc_4083360:
            if (iVar20 == 0) break;
          }
          piVar2 = dword_40C6E46;
          if (iVar18 != 0) {
            piVar15[3] = piVar15[3] + -1;
loc_40835B6:
            *(byte *)(_slot_id_bmap + 0x2008000) = *(byte *)(_slot_id_bmap + 0x2008000) | 2;
loc_408395E:
            bVar10 = *(byte *)((int)piVar15 + 0x21);
            if (bVar10 != 2) {
              if (bVar10 < 3) {
                *(byte *)((int)piVar15 + 0x21) = bVar10 | 4;
              }
              else if (bVar10 != 3) goto loc_408398E;
              *(undefined *)((int)piVar15 + 0x21) = 5;
            }
            *(undefined *)((int)piVar15 + 0x21) = 4;
loc_408398E:
            bVar23 = dword_40C6E46 < &dword_40C6E46;
            if ((int **)dword_40C6E46 == &dword_40C6E46) {
              dword_40C6E4A = piVar15;
            }
            else {
              dword_40C6E46[7] = (int)piVar15;
            }
            piVar15[6] = (int)dword_40C6E46;
            piVar15[7] = (int)&dword_40C6E46;
            dword_40B21C8 = uVar14;
            dword_40C6E46 = piVar15;
            return (uint)(byte)(bVar23 << 4 | ((int)piVar15 < 0) << 3 | (piVar15 == (int *)0x0) << 2
                               );
          }
          break;
        case :
          uVar17 = (uint)(dword_40C6E46[2] - (dword_40C6E46[3] - dword_40C6E46[1])) >> 1;
          dword_40C6E46 = piVar2;
          if (uVar17 != 0) {
            do {
              psVar4 = (sword *)piVar15[3];
              piVar15[3] = (int)(psVar4 + 1);
              sVar6 = *psVar4;
              iVar18 = 0x32;
              bVar10 = *(byte *)(_slot_id_bmap + 0x2008002);
              while ((bVar10 & 2) == 0) {
                _delay(2);
                iVar18 = iVar18 + -1;
                if (iVar18 == 0) goto loc_408341C;
                bVar10 = *(byte *)(_slot_id_bmap + 0x2008002);
              }
              if (iVar18 != 0) {
                if (_cpu_type == '\0') {
                  *(int *)(_slot_id_bmap + 0x2008004) = (int)sVar6;
                }
                else {
                  cVar11 = (char)((word)sVar6 >> 8);
                  *(char *)(_slot_id_bmap + 0x2008005) = cVar11 >> 7;
                  *(char *)(_slot_id_bmap + 0x2008006) = cVar11;
                  *(char *)(_slot_id_bmap + 0x2008007) = (char)sVar6;
                }
              }
loc_408341C:
            } while ((iVar18 != 0) && (uVar17 = uVar17 - 1, 0 < (int)uVar17));
          }
          piVar2 = dword_40C6E46;
          if (uVar17 != 0) {
            piVar15[3] = piVar15[3] + -2;
            goto loc_40835B6;
          }
          break;
        case :
          iVar18 = dword_40C6E46[2] - (dword_40C6E46[3] - dword_40C6E46[1]);
          puVar16 = (uint3 *)dword_40C6E46[3];
          dword_40C6E46 = piVar2;
          if (0 < iVar18) {
            do {
              puVar21 = puVar16;
              uVar7 = *(undefined *)puVar21;
              uVar8 = *(undefined *)((int)puVar21 + 1);
              uVar13 = *puVar21;
              uVar12 = *puVar21;
              iVar20 = 0x32;
              bVar10 = *(byte *)(_slot_id_bmap + 0x2008002);
              while ((bVar10 & 2) == 0) {
                _delay(2);
                iVar20 = iVar20 + -1;
                if (iVar20 == 0) goto loc_40834E4;
                bVar10 = *(byte *)(_slot_id_bmap + 0x2008002);
              }
              if (iVar20 != 0) {
                if (_cpu_type == '\0') {
                  *(uint *)(_slot_id_bmap + 0x2008004) = (uint)uVar12;
                }
                else {
                  *(undefined *)(_slot_id_bmap + 0x2008005) = uVar7;
                  *(undefined *)(_slot_id_bmap + 0x2008006) = uVar8;
                  *(char *)(_slot_id_bmap + 0x2008007) = (char)uVar13;
                }
              }
loc_40834E4:
            } while ((iVar20 != 0) &&
                    (iVar18 = iVar18 + -3, puVar16 = (uint3 *)((int)puVar21 + 3), 0 < iVar18));
            piVar2 = dword_40C6E46;
            if (0 < iVar18) {
              piVar15[3] = (int)((int)puVar21 + 2);
              goto loc_40835B6;
            }
          }
          break;
        case :
          uVar17 = (uint)(dword_40C6E46[2] - (dword_40C6E46[3] - dword_40C6E46[1])) >> 2;
          dword_40C6E46 = piVar2;
          if (uVar17 != 0) {
            do {
              puVar5 = (undefined4 *)piVar15[3];
              piVar15[3] = (int)(puVar5 + 1);
              uVar1 = *puVar5;
              iVar18 = 0x32;
              bVar10 = *(byte *)(_slot_id_bmap + 0x2008002);
              while ((bVar10 & 2) == 0) {
                _delay(2);
                iVar18 = iVar18 + -1;
                if (iVar18 == 0) goto loc_40835A0;
                bVar10 = *(byte *)(_slot_id_bmap + 0x2008002);
              }
              if (iVar18 != 0) {
                if (_cpu_type == '\0') {
                  *(undefined4 *)(_slot_id_bmap + 0x2008004) = uVar1;
                }
                else {
                  *(char *)(_slot_id_bmap + 0x2008005) = (char)((uint)uVar1 >> 0x10);
                  *(char *)(_slot_id_bmap + 0x2008006) = (char)((uint)uVar1 >> 8);
                  *(char *)(_slot_id_bmap + 0x2008007) = (char)uVar1;
                }
              }
loc_40835A0:
            } while ((iVar18 != 0) && (uVar17 = uVar17 - 1, 0 < (int)uVar17));
          }
          piVar2 = dword_40C6E46;
          if (uVar17 != 0) {
            piVar15[3] = piVar15[3] + -4;
            goto loc_40835B6;
          }
          break;
        case :
        case :
          word_40C6E40._1_1_ = *(byte *)((int)dword_40C6E46 + 0xe);
          iVar18 = (&unk_40C6DF4)[(byte)word_40C6E40];
          word_40C6E40._0_1_ = 0;
          dword_40C6E42 = dword_40C6E46[1];
          piVar19 = dword_40C6E46 + 2;
          dword_40C6E46 = piVar2;
          *(undefined2 *)(iVar18 + 0x4e) = *(undefined2 *)piVar19;
          *(undefined2 *)(iVar18 + 0x50) = *(undefined2 *)((int)piVar15 + 10);
          *(undefined *)(iVar18 + 0x52) = *(undefined *)(piVar15 + 3);
          *(undefined *)(iVar18 + 0x53) = *(undefined *)((int)piVar15 + 0xd);
          if (*piVar15 == 5) {
            dword_40C6E76 = 4;
          }
          else {
            word_40C6E7A = 1;
          }
          piVar2 = dword_40C6E46;
          if ((int *)(iVar18 + 0x3e) != *(int **)(iVar18 + 0x3e)) {
            *(byte *)(_slot_id_bmap + 0x2008000) = *(byte *)(_slot_id_bmap + 0x2008000) | 2;
            piVar2 = dword_40C6E46;
          }
          break;
        case :
          pbVar9 = (byte *)((int)dword_40C6E46 + 7);
          dword_40C6E46 = piVar2;
          *(byte *)(_slot_id_bmap + 0x2008001) = *pbVar9 | 0x80;
          piVar2 = dword_40C6E46;
          break;
        case :
          uVar17 = dword_40C6E46[2] |
                   ~dword_40C6E46[1] &
                   ((uint)*(byte *)(_slot_id_bmap + 0x2008000) << 0x18 |
                   (uint)*(byte *)(_slot_id_bmap + 0x2008001) << 0x10);
          dword_40C6E46 = piVar2;
          *(char *)(_slot_id_bmap + 0x2008000) = (char)(uVar17 >> 0x18);
          *(char *)(_slot_id_bmap + 0x2008001) = (char)(uVar17 >> 0x10);
          cVar11 = *(char *)(_slot_id_bmap + 0x2008000);
          while (piVar2 = dword_40C6E46, cVar11 < '\0') {
            _delay(1);
            cVar11 = *(char *)(_slot_id_bmap + 0x2008000);
          }
          break;
        case :
          pcVar24 = sub_4083CCA;
          dword_40C6E46 = piVar2;
          goto loc_4083918;
        case :
          dword_40C6E46 = piVar2;
          _dsp_dev_reset_chip();
          _delay(2);
          if (((dword_40C6E84 & 0x2c00) != 0) ||
             (piVar2 = dword_40C6E46, (dword_40C6E84 & 0x100) == 0)) {
            *(undefined *)(_slot_id_bmap + 0x2008000) = 1;
            piVar2 = dword_40C6E46;
          }
          break;
        case :
          if (_cpu_type == '\0') {
            piVar19 = *(int **)(_slot_id_bmap + 0x2008000);
          }
          else {
            piVar19 = (int *)CONCAT31((uint3)(((uint)*(byte *)(_slot_id_bmap + 0x2008000) << 0x18)
                                             >> 8) |
                                      (uint3)(((uint)*(byte *)(_slot_id_bmap + 0x2008001) << 0x10)
                                             >> 8) | (uint3)*(byte *)(_slot_id_bmap + 0x2008002),
                                      *(undefined *)(_slot_id_bmap + 0x2008003));
          }
          pcVar24 = _snd_reply_dsp_regs;
          dword_40C6E46 = piVar2;
loc_40838DC:
          _callout_dispatch(4,pcVar24,piVar19);
          piVar2 = dword_40C6E46;
          break;
        case :
          dword_40C6E76 = dword_40C6E46[1];
          break;
        case :
        case :
        case :
        case :
          iVar18 = *dword_40C6E46;
          if (iVar18 == 0xd) {
            uVar17 = 1;
          }
          else if (iVar18 == 0xe) {
            uVar17 = 2;
          }
          else {
            uVar17 = 4;
            if (iVar18 == 0xf) {
              uVar17 = 3;
            }
          }
          puVar22 = (uint *)dword_40C6E46[3];
          iVar18 = dword_40C6E46[2] - ((int)puVar22 - dword_40C6E46[1]);
          dword_40C6E46 = piVar2;
          for (; 0 < iVar18; iVar18 = iVar18 - uVar17) {
            iVar20 = 0x19;
            bVar10 = *(byte *)(_slot_id_bmap + 0x2008002);
            while ((bVar10 & 1) == 0) {
              _delay(1);
              iVar20 = iVar20 + -1;
              if (iVar20 == 0) goto loc_408372A;
              bVar10 = *(byte *)(_slot_id_bmap + 0x2008002);
            }
            if (iVar20 != 0) {
              if (_cpu_type == '\0') {
                if (uVar17 == 2) {
                  *(sword *)puVar22 = (sword)*(undefined4 *)(_slot_id_bmap + 0x2008004);
                }
                else {
                  if (uVar17 < 3) {
                    if (uVar17 == 1) {
                      *(undefined *)puVar22 = *(undefined *)(_slot_id_bmap + 0x2008007);
                      goto loc_408372A;
                    }
                  }
                  else if (uVar17 == 3) goto loc_40836F2;
                  *puVar22 = *(uint *)(_slot_id_bmap + 0x2008004) & 0xffffff;
                }
              }
              else if (uVar17 == 2) {
                *(undefined2 *)puVar22 = *(undefined2 *)(_slot_id_bmap + 0x2008006);
              }
              else if (uVar17 < 3) {
                if (uVar17 == 1) {
                  *(undefined *)puVar22 = *(undefined *)(_slot_id_bmap + 0x2008007);
                }
                else {
loc_408366C:
                  *puVar22 = CONCAT31((uint3)*(byte *)(_slot_id_bmap + 0x2008006) |
                                      (uint3)(((uint)*(byte *)(_slot_id_bmap + 0x2008005) << 0x10)
                                             >> 8),*(undefined *)(_slot_id_bmap + 0x2008007));
                }
              }
              else {
                if (uVar17 != 3) goto loc_408366C;
loc_40836F2:
                *(undefined *)puVar22 = *(undefined *)(_slot_id_bmap + 0x2008005);
                *(undefined *)((int)puVar22 + 1) = *(undefined *)(_slot_id_bmap + 0x2008006);
                *(undefined *)((int)puVar22 + 2) = *(undefined *)(_slot_id_bmap + 0x2008007);
              }
            }
loc_408372A:
            if (iVar20 == 0) break;
            puVar22 = (uint *)(uVar17 + (int)puVar22);
          }
          piVar15[3] = (int)puVar22;
          if (iVar18 != 0) goto loc_408395E;
          bVar23 = true;
          piVar2 = dword_40C6E46;
          break;
        case :
          piVar19 = dword_40C6E46 + 1;
          dword_40C6E46 = piVar2;
          _dsp_dev_new_proto(*piVar19);
          piVar2 = dword_40C6E46;
        }
        dword_40C6E46 = piVar2;
        if (bVar23) {
          if (piVar15[4] == 0) {
            bVar23 = false;
            goto loc_4083938;
          }
          iVar18 = _curipl();
          if (iVar18 == 0) {
            sub_4083A7A(piVar15);
          }
          else {
            pcVar24 = sub_4083A7A;
loc_4083918:
            _callout_dispatch(4,pcVar24,piVar15);
          }
        }
        else {
loc_4083938:
          _dspq_free_msg(piVar15);
        }
      } while ((int **)dword_40C6E46 != &dword_40C6E46);
    }
    if ((((int **)dword_40C6E46 == &dword_40C6E46) || (*(byte *)((int)dword_40C6E46 + 0x21) < 2)) ||
       ((dword_40C6E46[8] & 0x4ff00U) == 0)) {
      uVar17 = dword_40C6E84;
      if ((((dword_40C6E84 & 0x10000) != 0) && (dword_40C6DFC != 0)) &&
         (dword_40C6DFC + 0x3e != *(int *)(dword_40C6DFC + 0x3e))) {
        iVar18 = 0x28;
        do {
          if ((*(byte *)(_slot_id_bmap + 0x2008002) & 2) != 0) break;
          _delay(1);
          iVar18 = iVar18 + -1;
        } while (iVar18 != 0);
        uVar17 = (uint)*(byte *)(_slot_id_bmap + 0x2008002);
        if ((*(byte *)(_slot_id_bmap + 0x2008002) & 2) != 0) {
          uVar17 = sub_4084026(dword_40C6DFC);
        }
      }
    }
    else {
      uVar17 = (uint)(byte)((*(byte *)((int)dword_40C6E46 + 0x21) == 0) << 4);
    }
  }
  dword_40B21C8 = uVar14;
  return uVar17;
}
/* GHIDRADEC_FUNCTION index=2276 start=0x4083af0 */

void _dspq_free_msg(uint *param_1)

{
  uint uVar1;
  uint *puVar2;
  int iVar3;
  
  if ((param_1 == (uint *)0x0) || (*(char *)(param_1 + 9) == '\0')) {
    iVar3 = _curipl();
    if (iVar3 == 0) {
      if (param_1 == (uint *)0x0) {
        if ((uint **)dword_40B5098 != &dword_40B5098) {
          do {
            puVar2 = dword_40B5098;
            dword_40B5098 = (uint *)dword_40B5098[6];
            if ((uint **)dword_40B5098 == &dword_40B5098) {
              dword_40B509C = (uint *)&dword_40B5098;
            }
            else {
              dword_40B5098[7] = (uint)&dword_40B5098;
            }
            _dspq_free_msg(puVar2);
          } while ((uint **)dword_40B5098 != &dword_40B5098);
        }
      }
      else {
        dword_40C6E4E = dword_40C6E4E + -1;
        if (*(char *)((int)param_1 + 0x23) == '\0') {
          if ((*param_1 < 5) && (*param_1 != 0)) {
            _vm_map_pageable(_kernel_map,~_page_mask & param_1[1],
                             ~_page_mask & _page_mask + param_1[2] + param_1[1],1);
            _vm_deallocate(_kernel_map,param_1[1],param_1[2]);
          }
          iVar3 = 0x26;
        }
        else {
          iVar3 = 0x26;
          uVar1 = *param_1;
          if (uVar1 != 0) {
            if (uVar1 < 5) {
              iVar3 = param_1[2] + 0x26;
            }
            else if (uVar1 == 9) {
              iVar3 = *(int *)(param_1[1] + 4) + 0x26;
            }
          }
        }
        _kfree(param_1,iVar3);
        if ((dword_40C6E4E < 0x200) && ((dword_40C6E84 & 0x40000) != 0)) {
          _port_set_add(dword_40C6EC0,dword_40C6EA8,0x10013);
          dword_40C6E84 = dword_40C6E84 & 0xfffbffff;
        }
      }
    }
    else {
      if ((uint **)dword_40B509C == &dword_40B5098) {
        dword_40B5098 = param_1;
      }
      else {
        dword_40B509C[6] = (uint)param_1;
      }
      param_1[7] = (uint)dword_40B509C;
      param_1[6] = (uint)&dword_40B5098;
      dword_40B509C = param_1;
      _callout_dispatch(4,_dspq_free_msg,0);
    }
  }
  else {
    dword_40C6E4E = dword_40C6E4E + -1;
    if ((uint **)dword_40B5094 == &dword_40B5090) {
      dword_40B5090 = param_1;
    }
    else {
      dword_40B5094[6] = (uint)param_1;
    }
    param_1[7] = (uint)dword_40B5094;
    param_1[6] = (uint)&dword_40B5090;
    dword_40B5094 = param_1;
  }
  return;
}
/* GHIDRADEC_FUNCTION index=2277 start=0x4083d22 */

uint _dspq_awaited_conditions(void)

{
  uint uVar1;
  uint uVar2;
  
  uVar1 = 0;
  if ((undefined4 **)dword_40C6E46 != &dword_40C6E46) {
    switch(*dword_40C6E46) {
    case :
      uVar2 = dword_40C6E46[1];
      if ((uVar2 & 0x1800) != 0) {
        uVar1 = 8;
      }
      if ((uVar2 & 0x600) != 0) {
        uVar1 = uVar1 | 4;
      }
      if ((uVar2 & 0x100) != 0) {
        uVar1 = uVar1 | 2;
      }
      if ((uVar2 & 0x800000) == 0) goto loc_4083DDE;
    case :
      uVar2 = 1;
      break;
    case :
    case :
    case :
    case :
      uVar2 = 4;
      break;
    :
      goto loc_4083DDE;
    case :
    case :
    case :
    case :
      uVar2 = 2;
    }
    uVar1 = uVar2 | uVar1;
  }
loc_4083DDE:
  if ((((uVar1 == 0) && ((dword_40C6E84 & 0x10000) != 0)) && (dword_40C6DFC != 0)) &&
     (dword_40C6DFC + 0x3e != *(int *)(dword_40C6DFC + 0x3e))) {
    uVar1 = 4;
  }
  return uVar1;
}
/* GHIDRADEC_FUNCTION index=2278 start=0x4083e1c */

undefined4 _dspq_start_simple(int param_1,int param_2)

{
  int *piVar1;
  undefined4 uVar2;
  int iVar3;
  
  iVar3 = 1;
  if (param_2 == 0) {
    iVar3 = 2;
  }
  if ((dword_40C6E84 & 0x20000) == 0) {
    if (param_2 == 1) {
      *(undefined4 *)(param_1 + 0x18) = 4;
      _dma_enqueue(&_dsp_var,param_1 + 0xc);
    }
    else {
      piVar1 = *(int **)((&unk_40C6DF4)[iVar3] + 0x42);
      if (piVar1 == (int *)((&unk_40C6DF4)[iVar3] + 0x3e)) {
        *piVar1 = param_1;
      }
      else {
        piVar1[0xb] = param_1;
      }
      *(int **)(param_1 + 0x30) = piVar1;
      *(int *)(param_1 + 0x2c) = (&unk_40C6DF4)[iVar3] + 0x3e;
      *(int *)((&unk_40C6DF4)[iVar3] + 0x42) = param_1;
    }
    if (((dword_40C6E84 & 0x10000) != 0) || ((undefined4 **)dword_40C6E46 != &dword_40C6E46)) {
      iVar3 = _dspq_check();
      if (iVar3 != 0) {
        _callout_dispatch(1,_dspq_execute,0);
      }
    }
    uVar2 = 1;
  }
  else {
    uVar2 = 0;
  }
  return uVar2;
}
/* GHIDRADEC_FUNCTION index=2279 start=0x4083ef2 */

undefined4 _dspq_start_complex(int param_1,int param_2)

{
  undefined4 uVar1;
  int iVar2;
  uint uVar3;
  int *piVar4;
  
  iVar2 = **(int **)(*(int *)(param_1 + 8) + 0x3a);
  if ((dword_40C6E84 & 0x20000) == 0) {
    uVar3 = 0;
    piVar4 = &unk_40C6DF4;
    do {
      if (iVar2 == *piVar4) break;
      piVar4 = piVar4 + 1;
      uVar3 = uVar3 + 1;
    } while ((int)uVar3 < 0x13);
    piVar4 = *(int **)(iVar2 + 0x42);
    if (piVar4 == (int *)(iVar2 + 0x3e)) {
      *piVar4 = param_1;
    }
    else {
      piVar4[0xb] = param_1;
    }
    *(int **)(param_1 + 0x30) = piVar4;
    *(int *)(param_1 + 0x2c) = iVar2 + 0x3e;
    *(int *)(iVar2 + 0x42) = param_1;
    if (param_2 == 0) {
      *(byte *)(_slot_id_bmap + 0x2008000) = *(byte *)(_slot_id_bmap + 0x2008000) | 2;
    }
    else {
      if (((dword_40C6E76 != 1) && (dword_40C6E76 != 2)) && (dword_40C6E76 != 6)) {
        *(byte *)(_slot_id_bmap + 0x2008000) = *(byte *)(_slot_id_bmap + 0x2008000) | 1;
      }
      if ((word_40C6E7A == 1) || ((dword_40C6E76 == 1 && (word_40C6E40 == uVar3)))) {
        _dsp_dev_loop();
      }
    }
    if (((dword_40C6E84 & 0x10000) != 0) || ((undefined4 **)dword_40C6E46 != &dword_40C6E46)) {
      iVar2 = _dspq_check();
      if (iVar2 != 0) {
        _callout_dispatch(1,_dspq_execute,0);
      }
    }
    uVar1 = 1;
  }
  else {
    uVar1 = 0;
  }
  return uVar1;
}
/* GHIDRADEC_FUNCTION index=2280 start=0x40842fe */

uint _snd_link_init(uint param_1)

{
  int iVar1;
  int iVar2;
  undefined4 *puVar3;
  int iVar4;
  int iVar5;
  uint uVar6;
  undefined4 uVar7;
  undefined4 uVar8;
  undefined4 uVar9;
  undefined4 *puVar10;
  int iVar11;
  int iVar12;
  int *piVar13;
  char cVar14;
  char cVar15;
  char cVar16;
  char cVar17;
  byte bVar18;
  undefined4 uStack_1c;
  int iStack_c;
  int iStack_8;
  
  piVar13 = &dword_40C6DFC;
  if (param_1 == 0) {
    piVar13 = &dword_40C6DF8;
  }
  iVar1 = *piVar13;
  *(int *)((int)&dword_40B511A + param_1 * 0x3e) = iVar1;
  iVar2 = *(int *)(iVar1 + 0x2a);
  if (param_1 == 0) {
    puVar10 = &dword_40C6E94;
    uStack_1c = __NXAudioSndoutDevice;
  }
  else {
    puVar10 = &dword_40C6E8C;
    uStack_1c = __NXAudioSndinDevice;
  }
  (*___NXAudioGetBufferOptions)(uStack_1c,&iStack_8,&iStack_c);
  iVar4 = iStack_8;
  iVar5 = _snd_get_owner(puVar10,_snd_var);
  if (iVar5 == 0) {
    uVar6 = _printf(aSounddspLinkCo);
  }
  else {
    dword_40B21D0 = *(undefined4 *)(iVar5 + 4);
    *(byte *)(iVar1 + 0x24) = *(byte *)(iVar1 + 0x24) | 8;
    dword_40B21D4 = 1;
    iVar5 = iVar4;
    iVar12 = iVar2;
    if (iVar2 < iVar4) {
      iVar5 = iVar2;
      iVar12 = iVar4;
    }
    iVar5 = iVar12 / iVar5;
    iVar11 = iStack_c;
    if (param_1 != 0) {
      iVar11 = *(int *)(iVar1 + 0x2e);
    }
    *(int *)((int)&unk_40B516C + param_1 * 4) = iVar11 * iVar12;
    puVar10 = &unk_40B50A0 + param_1 * 2;
    (&dword_40B50A4)[param_1 * 2] = puVar10;
    (&unk_40B50A0)[param_1 * 2] = puVar10;
    puVar3 = &unk_40B50B0 + param_1 * 2;
    (&dword_40B50B4)[param_1 * 2] = puVar3;
    (&unk_40B50B0)[param_1 * 2] = puVar3;
    *(undefined **)(unk_40B50C0 + param_1 * 8 + 4) = unk_40B50C0 + param_1 * 8;
    *(undefined **)(unk_40B50C0 + param_1 * 8) = unk_40B50C0 + param_1 * 8;
    (&dword_40B50D4)[param_1 * 2] = &unk_40B50D0 + param_1 * 2;
    (&unk_40B50D0)[param_1 * 2] = &unk_40B50D0 + param_1 * 2;
    *(undefined4 *)((int)&unk_40B515C + param_1 * 4) = 0;
    uVar7 = _kalloc(iVar11 * 0x38);
    uVar8 = _kalloc(iVar5 * iVar11 * 0x38);
    uVar9 = _kalloc(_page_mask + *(int *)((int)&unk_40B516C + param_1 * 4) & ~_page_mask);
    *(undefined4 *)((int)&unk_40B5164 + param_1 * 4) = uVar9;
    if (iVar12 == iVar4) {
      sub_408462A(uVar7,uVar9,iVar11,iVar4,_snd_link_snd_complete,param_1,puVar10);
      *(int *)((int)&unk_40B5174 + param_1 * 4) = iVar11;
      sub_408462A(uVar8,*(undefined4 *)((int)&unk_40B5164 + param_1 * 4),iVar11 * iVar5,iVar2,
                  sub_4084AFE,unk_40B50E0 + param_1 * 0x3e,puVar3);
      *(int *)((int)&unk_40B517C + param_1 * 4) = iVar11 * iVar5;
    }
    else {
      sub_408462A(uVar7,uVar9,iVar11,iVar2,sub_4084AFE,unk_40B50E0 + param_1 * 0x3e,puVar3);
      *(int *)((int)&unk_40B517C + param_1 * 4) = iVar11;
      iVar11 = iVar11 * iVar5;
      sub_408462A(uVar8,*(undefined4 *)((int)&unk_40B5164 + param_1 * 4),iVar11,iVar4,
                  _snd_link_snd_complete,param_1,puVar10);
      *(int *)((int)&unk_40B5174 + param_1 * 4) = iVar11;
      (*___NXAudioSetBufferOptions)(uStack_1c,0,iStack_8,iVar11);
    }
    (*___NXAudioInitLinkedStream)(dword_40B21D0);
    cVar17 = 1 < param_1;
    cVar16 = SBORROW4(1,param_1);
    cVar14 = (int)(1 - param_1) < 0;
    cVar15 = param_1 == 1;
    if ((bool)cVar15) {
      bVar18 = cVar17;
      _printf(aSounddspCodecD);
    }
    else {
      puVar10 = &unk_40B50B0 + param_1 * 2;
      puVar3 = (undefined4 *)(&unk_40B50B0)[param_1 * 2];
      cVar17 = puVar10 < puVar3;
      cVar16 = SBORROW4((int)puVar10,(int)puVar3);
      iVar2 = (int)puVar10 - (int)puVar3;
      cVar15 = puVar10 == puVar3;
      while (cVar14 = iVar2 < 0, bVar18 = cVar17, !(bool)cVar15) {
        iVar2 = (&unk_40B50B0)[param_1 * 2];
        puVar10 = *(undefined4 **)(iVar2 + 0x2c);
        if (puVar10 == &unk_40B50B0 + param_1 * 2) {
          (&dword_40B50B4)[param_1 * 2] = puVar10;
        }
        else {
          puVar10[0xc] = &unk_40B50B0 + param_1 * 2;
        }
        (&unk_40B50B0)[param_1 * 2] = puVar10;
        (**(code **)(iVar1 + 0x3a))(iVar2,1,0);
        puVar10 = &unk_40B50B0 + param_1 * 2;
        puVar3 = (undefined4 *)(&unk_40B50B0)[param_1 * 2];
        cVar17 = puVar10 < puVar3;
        cVar16 = SBORROW4((int)puVar10,(int)puVar3);
        iVar2 = (int)puVar10 - (int)puVar3;
        cVar15 = puVar10 == puVar3;
      }
    }
    uVar6 = (uint)(byte)(cVar17 << 4 | cVar14 << 3 | cVar15 << 2 | cVar16 << 1 | bVar18);
  }
  return uVar6;
}
/* GHIDRADEC_FUNCTION index=2281 start=0x408461c */

void _snd_link_abort(void)

{
  dword_40B21D4 = 0;
  return;
}
/* GHIDRADEC_FUNCTION index=2282 start=0x4084838 */

void _snd_link_shutdown(int param_1)

{
  undefined *puVar1;
  undefined *puVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int unaff_D5;
  int unaff_A2;
  
  *(undefined4 *)((int)&unk_40B515C + param_1 * 4) = _active_threads;
  if (param_1 == 0) {
    iVar7 = 0;
    if (dword_40B21D4 != 0) {
      iVar6 = 0;
      do {
        _assert_wait(0,1);
        iVar5 = _hz;
        if (_hz < 0) {
          iVar5 = _hz + 1;
        }
        _thread_set_timeout(iVar5 >> 1);
        _thread_block();
        _untimeout(_thread_timeout,_active_threads);
      } while ((_sound_active != 0) && (iVar6 = iVar6 + 1, iVar6 < 4));
    }
  }
  else {
    *(undefined4 *)((int)&unk_40B515C + param_1 * 4) = _active_threads;
    iVar7 = *(int *)(dword_40C6DFC + 0x2e);
    unaff_D5 = dword_40C6DFC;
  }
  if (unk_40B50C0 + param_1 * 8 != *(undefined **)(unk_40B50C0 + param_1 * 8)) {
    do {
      puVar1 = *(undefined **)(unaff_A2 + 0x2c);
      puVar2 = *(undefined **)(unaff_A2 + 0x30);
      if (puVar1 == unk_40B50C0 + param_1 * 8) {
        *(undefined **)(unk_40B50C0 + param_1 * 8 + 4) = puVar2;
      }
      else {
        *(undefined **)(puVar1 + 0x30) = puVar2;
      }
      if (puVar2 == unk_40B50C0 + param_1 * 8) {
        *(undefined **)(unk_40B50C0 + param_1 * 8) = puVar1;
      }
      else {
        *(undefined **)(puVar2 + 0x2c) = puVar1;
      }
      puVar4 = (undefined4 *)(&dword_40B50A4)[param_1 * 2];
      if (puVar4 == &unk_40B50A0 + param_1 * 2) {
        (&unk_40B50A0)[param_1 * 2] = unaff_A2;
      }
      else {
        puVar4[0xb] = unaff_A2;
      }
      *(undefined4 **)(unaff_A2 + 0x30) = puVar4;
      *(undefined4 **)(unaff_A2 + 0x2c) = &unk_40B50A0 + param_1 * 2;
      (&dword_40B50A4)[param_1 * 2] = unaff_A2;
    } while (unk_40B50C0 + param_1 * 8 != *(undefined **)(unk_40B50C0 + param_1 * 8));
  }
  if (&unk_40B50D0 + param_1 * 2 != (undefined4 *)(&unk_40B50D0)[param_1 * 2]) {
    do {
      puVar4 = *(undefined4 **)(unaff_A2 + 0x2c);
      puVar3 = *(undefined4 **)(unaff_A2 + 0x30);
      if (puVar4 == &unk_40B50D0 + param_1 * 2) {
        (&dword_40B50D4)[param_1 * 2] = puVar3;
      }
      else {
        puVar4[0xc] = puVar3;
      }
      if (puVar3 == &unk_40B50D0 + param_1 * 2) {
        (&unk_40B50D0)[param_1 * 2] = puVar4;
      }
      else {
        puVar3[0xb] = puVar4;
      }
      puVar4 = (undefined4 *)(&dword_40B50B4)[param_1 * 2];
      if (puVar4 == &unk_40B50B0 + param_1 * 2) {
        (&unk_40B50B0)[param_1 * 2] = unaff_A2;
      }
      else {
        puVar4[0xb] = unaff_A2;
      }
      *(undefined4 **)(unaff_A2 + 0x30) = puVar4;
      *(undefined4 **)(unaff_A2 + 0x2c) = &unk_40B50B0 + param_1 * 2;
      (&dword_40B50B4)[param_1 * 2] = unaff_A2;
    } while (&unk_40B50D0 + param_1 * 2 != (undefined4 *)(&unk_40B50D0)[param_1 * 2]);
  }
  if (iVar7 != 0) {
    _assert_wait(unaff_D5,1);
    _thread_set_timeout(_hz);
    _thread_block();
    _untimeout(_thread_timeout,_active_threads);
  }
  *(undefined4 *)((int)&unk_40B515C + param_1 * 4) = 0;
  sub_40846D2(param_1);
  return;
}
/* GHIDRADEC_FUNCTION index=2283 start=0x4084a18 */

void _snd_link_pause(void)

{
  return;
}
/* GHIDRADEC_FUNCTION index=2284 start=0x4084a20 */

byte _snd_link_resume(uint param_1)

{
  int iVar1;
  undefined8 *puVar2;
  undefined4 *puVar3;
  bool bVar4;
  bool bVar5;
  bool bVar6;
  bool bVar7;
  bool bVar8;
  
  if (param_1 == dword_40B511A) {
    bVar8 = &unk_40B50D0 < unk_40B50D0;
    bVar7 = SBORROW4(0x40b50d0,(int)unk_40B50D0);
    bVar4 = (int)&unk_40B50D0 - (int)unk_40B50D0 < 0;
    bVar5 = (undefined4 **)unk_40B50D0 == &unk_40B50D0;
    if (!bVar5) {
      do {
        puVar3 = unk_40B50D0;
        unk_40B50D0 = (undefined4 *)unk_40B50D0[0xb];
        if ((undefined4 **)unk_40B50D0 == &unk_40B50D0) {
          dword_40B50D4 = &unk_40B50D0;
        }
        else {
          unk_40B50D0[0xc] = &unk_40B50D0;
        }
        (**(code **)(param_1 + 0x3a))(puVar3,1,0);
      } while ((undefined4 **)unk_40B50D0 != &unk_40B50D0);
      bVar8 = false;
      bVar7 = false;
      bVar5 = true;
      bVar4 = false;
    }
  }
  else {
    bVar8 = param_1 < dword_40B5158;
    bVar7 = SBORROW4(param_1,dword_40B5158);
    bVar4 = (int)(param_1 - dword_40B5158) < 0;
    bVar5 = false;
    if (param_1 == dword_40B5158) {
      bVar8 = &unk_40B50D8 < unk_40B50D8._0_4_;
      iVar1 = (int)&unk_40B50D8 - (int)unk_40B50D8._0_4_;
      bVar6 = unk_40B50D8._0_4_ == &unk_40B50D8;
      puVar2 = unk_40B50D8._0_4_;
      while( true ) {
        bVar4 = iVar1 < 0;
        bVar7 = SBORROW4(0x40b50d8,(int)puVar2);
        bVar5 = true;
        unk_40B50D8._0_4_ = puVar2;
        if (bVar6) break;
        unk_40B50D8._0_4_ = *(undefined8 **)((int)puVar2 + 0x2c);
        if (unk_40B50D8._0_4_ == &unk_40B50D8) {
          unk_40B50D8._4_4_ = &unk_40B50D8;
        }
        else {
          *(undefined8 **)(unk_40B50D8._0_4_ + 6) = &unk_40B50D8;
        }
        (**(code **)(param_1 + 0x3a))(puVar2,0,0);
        bVar8 = &unk_40B50D8 < unk_40B50D8._0_4_;
        iVar1 = (int)&unk_40B50D8 - (int)unk_40B50D8._0_4_;
        bVar6 = unk_40B50D8._0_4_ == &unk_40B50D8;
        puVar2 = unk_40B50D8._0_4_;
      }
    }
  }
  return bVar8 << 4 | bVar4 << 3 | bVar5 << 2 | bVar7 << 1 | bVar8;
}
/* GHIDRADEC_FUNCTION index=2285 start=0x4084d8c */

int _snd_link_snd_complete(int param_1)

{
  int iVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  undefined4 *puVar5;
  int iVar6;
  int iVar7;
  int *piVar8;
  
  iVar2 = *(int *)(param_1 + 8);
  piVar8 = &dword_40C6DFC;
  if (iVar2 == 0) {
    piVar8 = &dword_40C6DF8;
  }
  iVar1 = *piVar8;
  iVar7 = 1;
  puVar4 = (undefined4 *)(&dword_40B50A4)[iVar2 * 2];
  if (puVar4 == &unk_40B50A0 + iVar2 * 2) {
    (&unk_40B50A0)[iVar2 * 2] = param_1;
  }
  else {
    puVar4[0xb] = param_1;
  }
  *(undefined4 **)(param_1 + 0x30) = puVar4;
  *(undefined4 **)(param_1 + 0x2c) = &unk_40B50A0 + iVar2 * 2;
  (&dword_40B50A4)[iVar2 * 2] = param_1;
  if (((iVar2 == 0) && ((dword_40C6E84 & 0x10) == 0)) ||
     ((iVar2 == 1 && ((dword_40C6E84 & 0x20) == 0)))) {
    _callout_dispatch(4,sub_40846D2,iVar2);
    iVar7 = 0;
  }
  else {
    puVar4 = &unk_40B50B0 + iVar2 * 2;
    puVar5 = (undefined4 *)(&unk_40B50B0)[iVar2 * 2];
    if (puVar5 == puVar4) {
      iVar7 = 0;
    }
    else if ((uint)puVar5[1] < *(uint *)(param_1 + 4)) {
      do {
        iVar6 = (&unk_40B50B0)[iVar2 * 2];
        puVar5 = *(undefined4 **)(iVar6 + 0x2c);
        if (puVar5 == puVar4) {
          (&dword_40B50B4)[iVar2 * 2] = puVar4;
        }
        else {
          puVar5[0xc] = puVar4;
        }
        (&unk_40B50B0)[iVar2 * 2] = puVar5;
        if ((*(uint *)(iVar6 + 0x10) < *(uint *)(param_1 + 0x10)) ||
           (*(uint *)(param_1 + 0x14) < *(uint *)(iVar6 + 0x14))) {
joined_r0x04084e9e:
          if (puVar5 == puVar4) {
            (&dword_40B50B4)[iVar2 * 2] = iVar6;
          }
          else {
            puVar5[0xc] = iVar6;
          }
          *(undefined4 **)(iVar6 + 0x2c) = puVar5;
          *(undefined4 **)(iVar6 + 0x30) = &unk_40B50B0 + iVar2 * 2;
          (&unk_40B50B0)[iVar2 * 2] = iVar6;
          return iVar7;
        }
        if ((*(byte *)(iVar1 + 0x24) & 0x10) != 0) {
          puVar4 = (undefined4 *)(&dword_40B50D4)[iVar2 * 2];
          if (puVar4 == &unk_40B50D0 + iVar2 * 2) {
            (&unk_40B50D0)[iVar2 * 2] = iVar6;
          }
          else {
            puVar4[0xb] = iVar6;
          }
          *(undefined4 **)(iVar6 + 0x30) = puVar4;
          *(undefined4 **)(iVar6 + 0x2c) = &unk_40B50D0 + iVar2 * 2;
          (&dword_40B50D4)[iVar2 * 2] = iVar6;
          return iVar7;
        }
        iVar7 = (**(code **)(iVar1 + 0x3a))(iVar6,1 - iVar2,0);
        if (iVar7 == 0) {
          puVar5 = (undefined4 *)(&unk_40B50B0)[iVar2 * 2];
          goto joined_r0x04084e9e;
        }
      } while (puVar4 != (undefined4 *)(&unk_40B50B0)[iVar2 * 2]);
    }
    else {
      puVar3 = (undefined4 *)puVar5[0xb];
      if (puVar3 == puVar4) {
        (&dword_40B50B4)[iVar2 * 2] = puVar3;
      }
      else {
        puVar3[0xc] = puVar4;
      }
      (&unk_40B50B0)[iVar2 * 2] = puVar3;
      if (puVar5[5] == *(int *)(param_1 + 0x14)) {
        if ((*(byte *)(iVar1 + 0x24) & 0x10) == 0) {
          iVar7 = (**(code **)(iVar1 + 0x3a))(puVar5,1 - iVar2,0);
          if (iVar7 == 0) {
            puVar4 = (undefined4 *)(&unk_40B50A0)[iVar2 * 2];
            if (puVar4 == &unk_40B50A0 + iVar2 * 2) {
              (&dword_40B50A4)[iVar2 * 2] = puVar5;
            }
            else {
              puVar4[0xc] = puVar5;
            }
            puVar5[0xb] = puVar4;
            puVar5[0xc] = &unk_40B50A0 + iVar2 * 2;
            (&unk_40B50A0)[iVar2 * 2] = puVar5;
          }
        }
        else {
          puVar4 = (undefined4 *)(&dword_40B50D4)[iVar2 * 2];
          if (puVar4 == &unk_40B50D0 + iVar2 * 2) {
            (&unk_40B50D0)[iVar2 * 2] = puVar5;
          }
          else {
            puVar4[0xb] = puVar5;
          }
          puVar5[0xc] = puVar4;
          puVar5[0xb] = &unk_40B50D0 + iVar2 * 2;
          (&dword_40B50D4)[iVar2 * 2] = puVar5;
        }
      }
      else {
        if (puVar3 == &unk_40B50B0 + iVar2 * 2) {
          (&dword_40B50B4)[iVar2 * 2] = puVar5;
        }
        else {
          puVar3[0xc] = puVar5;
        }
        puVar5[0xb] = puVar3;
        puVar5[0xc] = &unk_40B50B0 + iVar2 * 2;
        (&unk_40B50B0)[iVar2 * 2] = puVar5;
      }
    }
  }
  return iVar7;
}
/* GHIDRADEC_FUNCTION index=2286 start=0x408503e */

undefined4 * _snd_rcv_alloc_msg_frame(void)

{
  dword_40C6ED8 = 0x2000;
  return &_snd_rcv_msg;
}
/* GHIDRADEC_FUNCTION index=2287 start=0x4085056 */

void _snd_reply_ret_device(undefined4 param_1,undefined4 param_2)

{
  undefined4 uStack_1c;
  undefined4 uStack_18;
  undefined4 uStack_14;
  undefined4 uStack_10;
  undefined4 uStack_c;
  undefined4 uStack_8;
  
  uStack_1c = dword_40B21D8;
  uStack_18 = dword_40B21DC;
  uStack_14 = dword_40B21E0;
  uStack_8 = 0x12f;
  uStack_10 = param_2;
  uStack_c = param_1;
  _msg_send(&uStack_1c,1,0);
  return;
}
/* GHIDRADEC_FUNCTION index=2288 start=0x40850b2 */

void _snd_reply_ret_stream(undefined4 param_1,undefined4 param_2)

{
  undefined4 uStack_1c;
  undefined4 uStack_18;
  undefined4 uStack_14;
  undefined4 uStack_10;
  undefined4 uStack_c;
  undefined4 uStack_8;
  
  uStack_1c = dword_40B21D8;
  uStack_18 = dword_40B21DC;
  uStack_14 = dword_40B21E0;
  uStack_8 = 0x130;
  uStack_10 = param_2;
  uStack_c = param_1;
  _msg_send(&uStack_1c,1,0);
  return;
}
/* GHIDRADEC_FUNCTION index=2289 start=0x4085176 */

void _snd_reply_illegal_msg
               (undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  undefined4 uStack_28;
  undefined4 uStack_24;
  undefined4 uStack_20;
  undefined4 uStack_1c;
  undefined4 uStack_18;
  undefined4 uStack_14;
  uint uStack_10;
  undefined4 uStack_c;
  undefined4 uStack_8;
  
  uStack_28 = dword_40B21D8;
  uStack_20 = dword_40B21E0;
  uStack_14 = 0x13a;
  uStack_24 = 0x24;
  uStack_1c = param_1;
  uStack_18 = param_2;
  uStack_10 = dword_40B21FC & 0xffff002f | 0x20;
  uStack_c = param_3;
  uStack_8 = param_4;
  _msg_send(&uStack_28,1,0);
  return;
}
/* GHIDRADEC_FUNCTION index=2290 start=0x40851fc */

undefined4
_snd_reply_recorded_data
          (undefined4 param_1,undefined4 param_2,undefined4 param_3,int param_4,int param_5)

{
  undefined *puVar1;
  undefined4 uVar2;
  int iVar3;
  undefined auStack_34 [48];
  
  puVar1 = auStack_34;
  iVar3 = 0x30;
  if (param_5 != 0) {
    iVar3 = param_4 + 0x2c;
    puVar1 = (undefined *)_kalloc(iVar3);
  }
  puVar1[3] = 0;
  *(int *)(puVar1 + 4) = iVar3;
  *(undefined4 *)(puVar1 + 8) = 0;
  *(undefined4 *)(puVar1 + 0x10) = param_1;
  *(undefined4 *)(puVar1 + 0xc) = 0;
  *(undefined4 *)(puVar1 + 0x14) = 300;
  *(undefined4 *)(puVar1 + 0x18) = dword_40B21FC;
  *(undefined4 *)(puVar1 + 0x1c) = param_2;
  *(undefined4 *)(puVar1 + 0x20) = dword_40B21F0;
  *(undefined4 *)(puVar1 + 0x24) = dword_40B21F4;
  *(undefined4 *)(puVar1 + 0x28) = dword_40B21F8;
  *(int *)(puVar1 + 0x28) = param_4;
  if (param_5 == 0) {
    *(undefined4 *)(puVar1 + 0x2c) = param_3;
  }
  else {
    puVar1[0x23] = puVar1[0x23] | 8;
    _bcopy(param_3,puVar1 + 0x2c,param_4);
  }
  uVar2 = _msg_send(puVar1,0x21,0);
  if (param_5 != 0) {
    _kfree(puVar1,iVar3);
  }
  return uVar2;
}
/* GHIDRADEC_FUNCTION index=2291 start=0x40852c2 */

void _snd_reply_timed_out(undefined4 param_1,undefined4 param_2)

{
  sub_408510E(param_1,param_2,0x12d);
  return;
}
/* GHIDRADEC_FUNCTION index=2292 start=0x40852dc */

void _snd_reply_ret_samples(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  undefined4 uStack_28;
  undefined4 uStack_24;
  undefined4 uStack_20;
  undefined4 uStack_1c;
  undefined4 uStack_18;
  undefined4 uStack_14;
  undefined4 uStack_10;
  undefined4 uStack_c;
  undefined4 uStack_8;
  
  uStack_28 = dword_40B21D8;
  uStack_20 = dword_40B21E0;
  uStack_1c = dword_40B21E4;
  uStack_24 = 0x24;
  uStack_14 = 0x12e;
  uStack_18 = param_1;
  uStack_10 = dword_40B21FC;
  uStack_c = param_2;
  uStack_8 = param_3;
  _msg_send(&uStack_28,0x21,0);
  return;
}
/* GHIDRADEC_FUNCTION index=2293 start=0x408534c */

void _snd_reply_overflow(undefined4 param_1,undefined4 param_2)

{
  sub_408510E(param_1,param_2,0x133);
  return;
}
/* GHIDRADEC_FUNCTION index=2294 start=0x4085366 */

void _snd_reply_started(undefined4 param_1,undefined4 param_2)

{
  sub_408510E(param_1,param_2,0x135);
  return;
}
/* GHIDRADEC_FUNCTION index=2295 start=0x4085380 */

void _snd_reply_completed(undefined4 param_1,undefined4 param_2)

{
  sub_408510E(param_1,param_2,0x136);
  return;
}
/* GHIDRADEC_FUNCTION index=2296 start=0x408539a */

void _snd_reply_aborted(undefined4 param_1,undefined4 param_2)

{
  sub_408510E(param_1,param_2,0x137);
  return;
}
/* GHIDRADEC_FUNCTION index=2297 start=0x40853b4 */

void _snd_reply_paused(undefined4 param_1,undefined4 param_2)

{
  sub_408510E(param_1,param_2,0x138);
  return;
}
/* GHIDRADEC_FUNCTION index=2298 start=0x40853ce */

void _snd_reply_resumed(undefined4 param_1,undefined4 param_2)

{
  sub_408510E(param_1,param_2,0x139);
  return;
}
/* GHIDRADEC_FUNCTION index=2299 start=0x40853e8 */

void _snd_reply_ret_parms(undefined4 param_1,undefined4 param_2)

{
  undefined4 uStack_24;
  undefined4 uStack_20;
  undefined4 uStack_1c;
  undefined4 uStack_18;
  undefined4 uStack_14;
  undefined4 uStack_10;
  undefined4 uStack_c;
  undefined4 uStack_8;
  
  uStack_24 = dword_40B21D8;
  uStack_1c = dword_40B21E0;
  uStack_18 = dword_40B21E4;
  uStack_10 = 0x131;
  uStack_20 = 0x20;
  uStack_14 = param_1;
  uStack_c = dword_40B21FC;
  uStack_8 = param_2;
  _msg_send(&uStack_24,1,0);
  return;
}

