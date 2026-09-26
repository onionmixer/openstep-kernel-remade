
void _odintr(undefined *param_1)

{
  undefined *puVar1;
  int *piVar2;
  undefined uVar3;
  byte bVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  undefined *puVar9;
  int iVar10;
  int iVar11;
  char cVar12;
  byte bVar13;
  byte unaff_D3b;
  byte bVar14;
  byte unaff_D4b;
  undefined *puVar15;
  undefined **ppuVar16;
  undefined *puStack_50;
  undefined *puStack_4c;
  undefined *puStack_48;
  undefined *puStack_44;
  
  iVar7 = (&_odcinfo)[(int)(param_1 + -0x40c3b88) * 0x451ab30b >> 2];
  iVar6 = (int)(char)param_1[0x272];
  iVar5 = iVar6 * 0x20;
  puVar15 = _od_drive + iVar5;
  puVar1 = *(undefined **)(param_1 + 0x210);
  *(uint *)(param_1 + 0x220) = *(uint *)(param_1 + 0x220) | 0x8000;
  if ((*(uint *)(param_1 + 0x220) & 0x210000) == 0) {
    unaff_D3b = puVar1[4];
    unaff_D4b = puVar1[10];
    puVar1[4] = _disr_shadow | 0xfc;
    puVar1[5] = puVar1[5] & 0xfe;
  }
  puStack_44 = puVar15;
  if ((*(uint *)(param_1 + 0x220) & 0x8000000) == 0) {
    puStack_48 = param_1;
    puStack_4c = (undefined *)0x4077702;
    iVar7 = _od_attn();
    if (iVar7 == 0) {
      if ((*(uint *)(param_1 + 0x220) & 0x200000) != 0) {
        *(uint *)(param_1 + 0x220) = *(uint *)(param_1 + 0x220) & 0xffdfffff;
      }
      _printf();
    }
    else if (iVar7 == 1) {
      *(uint *)(param_1 + 0x220) = *(uint *)(param_1 + 0x220) | 0x1000000;
    }
    goto loc_40780D8;
  }
  *(uint *)(param_1 + 0x220) = *(uint *)(param_1 + 0x220) & 0xf7ffffff;
  param_1[0x260] = 0;
  cVar12 = '\0';
  if ((*(uint *)(param_1 + 0x220) & 0x200000) == 0) {
    if ((*(uint *)(param_1 + 0x220) & 0x10000) != 0) {
      cVar12 = '9';
      *(uint *)(param_1 + 0x220) = *(uint *)(param_1 + 0x220) & 0xfffeffff;
      goto loc_40777F0;
    }
    if ((char)unaff_D3b < '\0') {
      if ((unaff_D4b & 8) == 0) {
        if ((unaff_D4b & 4) == 0) {
          if ((unaff_D4b & 2) == 0) {
            if ((unaff_D4b & 1) == 0) {
              _printf();
              goto loc_40777F0;
            }
            cVar12 = '\x03';
          }
          else {
            cVar12 = '\x02';
          }
        }
        else {
          cVar12 = '\x01';
        }
      }
      else {
        cVar12 = '8';
      }
    }
    else if ((unaff_D3b & 0x10) == 0) {
      if ((unaff_D3b & 0x20) == 0) {
        if ((unaff_D3b & 0x40) != 0) {
          cVar12 = '\r';
        }
        goto loc_40777F0;
      }
      cVar12 = '\x05';
    }
    else {
      (&word_40C3E30)[iVar6 * 0x10] = (&word_40C3E30)[iVar6 * 0x10] & 0xdfff;
      (&DAT_40c3e35)[iVar5] = 0xff;
      cVar12 = '\x04';
    }
loc_40777F4:
    if ((*(uint *)(param_1 + 0x220) & 0x4000) == 0) {
      param_1[599] = cVar12;
      *(uint *)(param_1 + 0x220) = *(uint *)(param_1 + 0x220) | 0x4000;
    }
  }
  else {
    cVar12 = '5';
    *(uint *)(param_1 + 0x220) = *(uint *)(param_1 + 0x220) & 0xffdfffff;
loc_40777F0:
    if (cVar12 != '\0') goto loc_40777F4;
  }
  puVar1[7] = 0;
  puStack_48 = param_1;
  puStack_4c = (undefined *)0x4077820;
  iVar8 = _od_attn();
  if (iVar8 == 1) goto loc_40780D8;
  if ((*(word *)(param_1 + 0x24a) & 4) != 0) {
    param_1[599] = 8;
  }
  if ((*(word *)(param_1 + 0x24a) & 0x4000) != 0) {
    param_1[599] = 0x14;
  }
  if ((*(uint *)(param_1 + 0x220) & 0x1000000) != 0) {
    puStack_48 = param_1;
    puStack_4c = (undefined *)0x4077864;
    puStack_44 = puVar15;
    _od_async_attn();
    *(uint *)(param_1 + 0x220) = *(uint *)(param_1 + 0x220) & 0xffffbfff;
    goto loc_40780D8;
  }
  if ((*(uint *)(param_1 + 0x220) & 0x2000000) != 0) {
    _wakeup();
    *(uint *)(param_1 + 0x220) = *(uint *)(param_1 + 0x220) & 0xfdffffff;
  }
  if (*(int **)(iVar7 + 0x18) == (int *)(iVar7 + 0x18)) {
    _printf();
    goto loc_40780D8;
  }
  puVar9 = (undefined *)_disksort_first();
  if (puVar9 == (undefined *)0x0) {
    _printf();
    goto loc_40780D8;
  }
  iVar7 = *(int *)(puVar9 + 0x24);
  iVar8 = *(int *)(param_1 + 0x238);
  iVar10 = (sword)(word)((uint)*(undefined4 *)(puVar9 + 0x1f) >> 0x1b) * 0xda;
  piVar2 = *(int **)(DAT_40c3f32 + iVar10 + 0x44);
  if ((*(uint *)(param_1 + 0x220) & 0x4800000) == 0) {
    if ((*(uint *)(param_1 + 0x220) & 0x4000) == 0) {
      if ((*(uint *)(param_1 + 0x220) & 0x100000) != 0) {
        puStack_44 = (undefined *)0x4077938;
        _dma_cleanup();
      }
      if ((piVar2 != (int *)0x0) && ((*(uint *)(param_1 + 0x220) & 0x20000000) != 0)) {
        iVar11 = (int)(char)param_1[0x266] +
                 (int)(char)param_1[0x265] + *(int *)(param_1 + 0x244) + *(int *)(param_1 + 0x238);
        param_1[0x256] = (char)(iVar11 % piVar2[0x19]);
        *(sword *)(param_1 + 0x254) = (sword)(iVar11 / piVar2[0x19]);
        *(uint *)(param_1 + 0x220) = *(uint *)(param_1 + 0x220) | 0x80000000;
      }
      if ((((*(uint *)(param_1 + 0x220) & 0x1000) != 0) &&
          ((*(uint *)(param_1 + 0x220) & 0x20000000) != 0)) && (param_1[0x25c] == '\x02')) {
        puVar1[0xd] = (char)_od_frmr;
        *(uint *)(param_1 + 0x220) = *(uint *)(param_1 + 0x220) & 0xffffefff;
      }
      if ((((param_1[0x25c] & 0x82) != 0) && ((*(uint *)(param_1 + 0x220) & 0x100000) != 0)) &&
         (puVar1[0xb] != '\0')) {
        if ((int)dword_40C3EA0 < (int)(uint)(byte)puVar1[0xb]) {
          dword_40C3EA0 = (uint)(byte)puVar1[0xb];
        }
        if (_od_stats == 0) {
          _od_stats = (uint)(byte)puVar1[0xb];
        }
        else {
          iVar11 = _od_stats + (byte)puVar1[0xb];
          if (iVar11 < 0) {
            iVar11 = iVar11 + 1;
          }
          _od_stats = iVar11 >> 1;
        }
        if (DAT_40c3f32 + iVar10 == puVar9) {
          uVar3 = puVar1[0xb];
          *(undefined4 *)(DAT_40c3f32 + iVar10 + 0x28) = 0;
          DAT_40c3f32[iVar10 + 0x2b] = uVar3;
        }
      }
      *(uint *)(param_1 + 0x220) = *(uint *)(param_1 + 0x220) & 0xffefffff;
      if ((((*(uint *)(param_1 + 0x220) & 0x800) == 0) ||
          ((*(uint *)(param_1 + 0x220) & 0x20000000) == 0)) ||
         ((param_1[0x25c] != '\x02' || ((int)(uint)(byte)puVar1[0xb] <= _od_maxecc)))) {
        if ((((((param_1[0x25c] & 8) == 0) || ((*(uint *)(param_1 + 0x220) & 0x20000000) == 0)) ||
             (*piVar2 == 0x4e655854)) ||
            (((*(uint *)(param_1 + 0x220) & 0x80000) != 0 && ((char)unk_40C3FA0[iVar10 + 1] < '\0'))
            )) || ((int)(uint)(byte)puVar1[0xb] <= _od_maxecc)) {
          ppuVar16 = (undefined **)&stack0xffffffc4;
        }
        else {
          param_1[599] = 0x3c;
          puStack_44 = (undefined *)0x3;
          puStack_4c = param_1;
          puStack_50 = (undefined *)0x4077b6e;
          puStack_48 = puVar15;
          _od_perror();
          if ((*(uint *)(param_1 + 0x220) & 0x800) == 0) {
            *(int *)(param_1 + 0x240) = *(int *)(param_1 + 0x23c) - *(int *)(param_1 + 0x244);
            *(undefined4 *)(param_1 + 0x23c) = *(undefined4 *)(param_1 + 0x244);
          }
          *(uint *)(param_1 + 0x220) = *(uint *)(param_1 + 0x220) | 0x800;
          param_1[0x25e] = 0;
          param_1[0x271] = param_1[0x271] + '\x01';
          *(undefined2 *)(param_1 + 0x248) = 2;
          ppuVar16 = (undefined **)&stack0xffffffc4;
        }
      }
      else {
        if (((((int)(uint)(byte)puVar1[0xb] < _od_maxecc_l1) ||
             (_od_maxecc_h1 < (int)(uint)(byte)puVar1[0xb])) &&
            (((int)(uint)(byte)puVar1[0xb] < _od_maxecc_l2 ||
             (_od_maxecc_h2 < (int)(uint)(byte)puVar1[0xb])))) ||
           (_od_write_retry < (int)(uint)(byte)param_1[0x271])) {
          param_1[599] = 0x3c;
          goto loc_4077BC8;
        }
        param_1[599] = 0x3c;
        puStack_44 = (undefined *)0x1;
        puStack_4c = param_1;
        puStack_50 = (undefined *)0x4077afc;
        puStack_48 = puVar15;
        _od_perror();
        param_1[0x25e] = 0;
        *(undefined2 *)(param_1 + 0x248) = 1;
        ppuVar16 = &puStack_50;
        puStack_50 = (undefined *)0x1;
      }
    }
    else {
loc_4077BC8:
      if ((*(uint *)(param_1 + 0x220) & 0x800) != 0) {
        *(undefined2 *)(param_1 + 0x248) = 1;
        *(int *)(param_1 + 0x23c) = *(int *)(param_1 + 0x240) + *(int *)(param_1 + 0x23c);
        *(uint *)(param_1 + 0x220) = *(uint *)(param_1 + 0x220) & 0xfffff7ff;
      }
      if ((*(uint *)(param_1 + 0x220) & 0x100000) != 0) {
        _dma_abort();
        *(uint *)(param_1 + 0x220) = *(uint *)(param_1 + 0x220) & 0xefefffff;
        puVar1[7] = 0;
        puStack_44 = (undefined *)0x4077c20;
        sub_407AA5C();
      }
      iVar11 = 0;
      if (((*(uint *)(param_1 + 0x220) & 0x20000000) == 0) || (*(sword *)(param_1 + 0x248) != 1))
      goto loc_4077C78;
      bVar13 = param_1[0x25c];
      if (bVar13 == 4) {
loc_4077C58:
        iVar11 = (*(int *)(param_1 + 0x244) - (uint)(byte)puVar1[3]) + -1;
        if (param_1[599] == '\x04') {
          iVar11 = *(int *)(param_1 + 0x244) - (uint)(byte)puVar1[3];
        }
      }
      else if (bVar13 < 5) {
        if (bVar13 == 1) goto loc_4077C58;
      }
      else if (bVar13 == 8) goto loc_4077C58;
loc_4077C78:
      if (iVar11 != 0) {
        iVar7 = iVar11 + iVar7;
        iVar8 = iVar11 + iVar8;
      }
      *(uint *)(param_1 + 0x220) = *(uint *)(param_1 + 0x220) & 0xffffbfff;
      iVar11 = (char)param_1[599] * 8;
      bVar13 = _od_err[iVar11];
      if (bVar13 == 2) {
        bVar13 = param_1[0x25e];
        param_1[0x25e] = bVar13 + 1;
        if (bVar13 <= (byte)_od_err[iVar11 + 1]) {
          *(uint *)(param_1 + 0x220) = *(uint *)(param_1 + 0x220) | 0x800000;
          param_1[0x26b] = param_1[0x269];
          puStack_44 = (undefined *)0x2;
          puStack_4c = param_1;
          puStack_50 = (undefined *)0x4078028;
          puStack_48 = puVar15;
          _od_perror();
          puStack_50 = (undefined *)0x6;
          _od_drive_cmd(param_1,puVar15,0x1000);
          (&DAT_40c3e35)[iVar5] = 0xff;
          (&word_40C3E30)[iVar6 * 0x10] = (&word_40C3E30)[iVar6 * 0x10] & 0xdfff;
          param_1[0x268] = 8;
          goto loc_40780D8;
        }
        bVar13 = param_1[0x25f];
        param_1[0x25f] = bVar13 + 1;
        if (bVar13 <= (byte)_od_err[iVar11 + 2]) {
          param_1[0x25e] = 0;
          goto loc_40780BA;
        }
        *(int *)(puVar9 + 0x24) = iVar7;
        *(int *)(param_1 + 0x238) = iVar8;
        if ((*(uint *)(param_1 + 0x220) & 0x40000) == 0) {
loc_40780AA:
          ppuVar16 = (undefined **)&stack0xffffffc4;
        }
        else {
          puStack_44 = (undefined *)0x8;
          puStack_4c = param_1;
          puStack_50 = (undefined *)0x4077fe4;
          puStack_48 = puVar15;
          _od_perror();
          *(uint *)(param_1 + 0x220) = *(uint *)(param_1 + 0x220) | 0x4000;
          puStack_50 = (undefined *)(int)(char)param_1[0x26a];
          ppuVar16 = &puStack_50;
        }
      }
      else {
        if (2 < bVar13) {
          if (bVar13 == 3) {
            *(uint *)(param_1 + 0x220) = *(uint *)(param_1 + 0x220) | 0x800000;
            puStack_44 = (undefined *)0x9;
            puStack_4c = param_1;
            puStack_50 = (undefined *)0x407806c;
            puStack_48 = puVar15;
            _od_perror();
            puStack_50 = (undefined *)0x6;
            _od_drive_cmd(param_1,puVar15,0x5600);
            param_1[0x268] = 7;
            *(uint *)(param_1 + 0x220) = *(uint *)(param_1 + 0x220) | 0x400;
            *(undefined2 *)(unk_40C3FA0 + iVar10) = 0;
            goto loc_40780D8;
          }
          if (bVar13 != 4) goto loc_40780D8;
          bVar13 = param_1[0x25e];
          param_1[0x25e] = bVar13 + 1;
          if ((byte)_od_err[iVar11 + 1] < bVar13) goto loc_40780AA;
loc_40780BA:
          puStack_44 = (undefined *)0x7;
          puStack_4c = param_1;
          puStack_50 = (undefined *)0x40780cc;
          puStack_48 = puVar15;
          _od_perror();
          puStack_50 = puVar1;
          _od_reset(param_1,puVar15);
          goto loc_40780D8;
        }
        if (bVar13 != 1) goto loc_40780D8;
        if (((*(uint *)(param_1 + 0x220) & 0x40000) == 0) ||
           ((param_1[599] == '\x04' && (param_1[0x25e] == '\0')))) {
          if (((*(sword *)(param_1 + 0x248) == 1) &&
              ((*piVar2 != 0x4e655854 &&
               (((*(uint *)(param_1 + 0x220) & 0x80000) == 0 || (-1 < (char)unk_40C3FA0[iVar10 + 1])
                ))))) && ((param_1[599] != '\x04' || (param_1[0x25e] != '\0')))) {
            puStack_48 = param_1;
            puStack_4c = (undefined *)0x4077d50;
            puStack_44 = puVar15;
            iVar7 = _od_remap();
            if (iVar7 == 0) goto loc_40780AA;
            puStack_44 = (undefined *)0x5;
            puStack_4c = param_1;
            puStack_50 = (undefined *)0x4077d6c;
            puStack_48 = puVar15;
            _od_perror();
            ppuVar16 = &puStack_50;
            puStack_50 = (undefined *)0x1;
          }
          else {
            if (((*(uint *)(param_1 + 0x220) & 0x80000) == 0) || ((unk_40C3FA0[iVar10] & 1) == 0)) {
              bVar13 = _od_err[iVar11 + 1];
              bVar14 = _od_err[iVar11 + 2];
            }
            else {
              bVar13 = DAT_40c3f32[iVar10 + 0x6c];
              bVar14 = DAT_40c3f32[iVar10 + 0x6d];
            }
            if ((*(uint *)(param_1 + 0x220) & 0x1000) != 0) {
              bVar13 = 4;
              bVar14 = 0;
            }
            if ((param_1[0x25c] == '\b') && (param_1[0x25e] == '\0')) {
              dword_40C3EA4 = dword_40C3EA4 + 1;
            }
            bVar4 = param_1[0x25e];
            param_1[0x25e] = bVar4 + 1;
            if (bVar13 <= bVar4) {
              param_1[0x25e] = 0;
              bVar13 = param_1[0x25f];
              param_1[0x25f] = bVar13 + 1;
              if (bVar13 < bVar14) {
                *(uint *)(param_1 + 0x220) = *(uint *)(param_1 + 0x220) | 0x800000;
                puStack_44 = (undefined *)0x2;
                puStack_4c = param_1;
                puStack_50 = (undefined *)0x4077f4c;
                puStack_48 = puVar15;
                _od_perror();
                puStack_50 = (undefined *)0x6;
                _od_drive_cmd(param_1,puVar15,0x1000);
                param_1[0x26b] = param_1[0x269];
                param_1[0x268] = 8;
                (&DAT_40c3e35)[iVar5] = 0xff;
                (&word_40C3E30)[iVar6 * 0x10] = (&word_40C3E30)[iVar6 * 0x10] & 0xdfff;
                goto loc_40780D8;
              }
              if ((((param_1[599] == '\x04') && (*piVar2 != 0x4e655854)) &&
                  (param_1[0x25c] == '\x02')) && (*(int *)(param_1 + 0x244) == 1)) {
                puStack_44 = (undefined *)0x4;
                puStack_4c = param_1;
                puStack_50 = (undefined *)0x4077e34;
                puStack_48 = puVar15;
                _od_perror();
                param_1[0x25f] = 0;
                param_1[0x25e] = param_1[0x25f];
                puStack_50 = puVar15;
                _od_sect_to(param_1);
                goto loc_40780D8;
              }
              if ((((param_1[599] == '\x03') || (param_1[599] == '\x1f')) &&
                  ((*piVar2 != 0x4e655854 &&
                   ((param_1[0x25c] == '\x02' && (*(int *)(param_1 + 0x244) == 1)))))) &&
                 ((_od_dbug._0_1_ & 2) == 0)) {
                if ((*(uint *)(param_1 + 0x220) & 0x1000) == 0) {
                  param_1[0x270] = 0;
                  *(uint *)(param_1 + 0x220) = *(uint *)(param_1 + 0x220) | 0x1000;
                }
                if ((byte)param_1[0x270] < 0x10) {
                  puVar1[0xd] = param_1[0x270] | (byte)_od_frmr & 0xf0;
                  param_1[0x270] = param_1[0x270] + '\x01';
                  param_1[0x25e] = 1;
                  puStack_44 = (undefined *)0x6;
                  puStack_4c = param_1;
                  puStack_50 = (undefined *)0x4077ef0;
                  puStack_48 = puVar15;
                  _od_perror();
                  goto loc_4077F78;
                }
                puVar1[0xd] = (byte)_od_frmr;
                *(uint *)(param_1 + 0x220) = *(uint *)(param_1 + 0x220) & 0xffffefff;
              }
              if (param_1[0x25c] == '\b') {
                dword_40C3EA8 = dword_40C3EA8 + 1;
              }
              *(int *)(puVar9 + 0x24) = iVar7;
              *(int *)(param_1 + 0x238) = iVar8;
              goto loc_40780AA;
            }
loc_4077F78:
            puStack_44 = (undefined *)0x1;
            puStack_4c = param_1;
            puStack_50 = (undefined *)0x4077f8a;
            puStack_48 = puVar15;
            _od_perror();
            puStack_50 = (undefined *)(int)(char)param_1[0x269];
            ppuVar16 = &puStack_50;
          }
        }
        else {
          puStack_44 = (undefined *)0x8;
          puStack_4c = param_1;
          puStack_50 = (undefined *)0x4077cf4;
          puStack_48 = puVar15;
          _od_perror();
          *(uint *)(param_1 + 0x220) = *(uint *)(param_1 + 0x220) | 0x4000;
          puStack_50 = (undefined *)(int)(char)param_1[0x26a];
          ppuVar16 = &puStack_50;
        }
      }
    }
  }
  else {
    ppuVar16 = (undefined **)&stack0xffffffc4;
  }
  *(undefined **)((int)ppuVar16 + -4) = puVar15;
  *(undefined **)((int)ppuVar16 + -8) = param_1;
  *(undefined4 *)((int)ppuVar16 + -0xc) = 0x40780b8;
  _od_fsm();
loc_40780D8:
  *(uint *)(param_1 + 0x220) = *(uint *)(param_1 + 0x220) & 0xffff7fff;
  return;
}
