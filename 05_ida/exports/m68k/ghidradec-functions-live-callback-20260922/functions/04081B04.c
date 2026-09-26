
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

