/* GHIDRADEC_FUNCTION index=2175 start=0x407748e */

void _od_block_async(void)

{
  return;
}
/* GHIDRADEC_FUNCTION index=2176 start=0x4077496 */

undefined8 _od_drive_cmd(int param_1,int param_2,int param_3,uint param_4)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  
  iVar1 = *(int *)(param_1 + 0x210);
  _od_block_async(param_1,param_2);
  *(undefined *)(iVar1 + 7) = 0;
  *(byte *)(iVar1 + 6) = (byte)(param_2 + -0x40c3e18 >> 5) | 0x80;
  _delay(2);
  iVar4 = 1;
  do {
    if ((*(byte *)(iVar1 + 4) & 1) != 0) break;
    _delay(1);
    iVar4 = iVar4 + 1;
  } while (iVar4 < 0x2001);
  iVar3 = iVar4 / 1;
  if (iVar4 % 1 == 0) {
    *(undefined *)(iVar1 + 7) = 0;
  }
  if (iVar4 < 0x2001) {
    *(sword *)(param_1 + 0x25a) = (sword)param_3;
    *(char *)(iVar1 + 8) = (char)((uint)param_3 >> 8);
    *(char *)(iVar1 + 9) = (char)param_3;
    iVar4 = 1;
    do {
      if ((*(byte *)(iVar1 + 4) & 1) == 0) break;
      _delay(1);
      iVar4 = iVar4 + 1;
    } while (iVar4 < 0x2001);
    iVar3 = iVar4 / 1;
    if (iVar4 % 1 == 0) {
      *(undefined *)(iVar1 + 7) = 0;
    }
    if (iVar4 < 0x2001) {
      if ((param_4 & 9) == 0) {
        *(uint *)(param_1 + 0x220) = *(uint *)(param_1 + 0x220) | 0x8000000;
        *(byte *)(iVar1 + 5) = *(byte *)(iVar1 + 5) | 1;
        *(byte *)(iVar1 + 5) = *(byte *)(iVar1 + 5) & 0xf3;
        if (((param_3 == 0x5200) || (param_3 == 0x5300)) || (param_3 == 0x5600)) {
          *(undefined *)(param_1 + 0x260) = 0x10;
        }
        else {
          *(undefined *)(param_1 + 0x260) = 6;
        }
      }
      else {
        *(byte *)(iVar1 + 5) = *(byte *)(iVar1 + 5) & 0xf2;
      }
      if ((param_4 & 1) != 0) {
        do {
        } while ((*(byte *)(iVar1 + 4) & 1) == 0);
      }
      uVar2 = 0;
      goto loc_40775F8;
    }
    *(undefined *)(param_1 + 599) = 0x3b;
  }
  else {
    *(undefined *)(param_1 + 599) = 0x3a;
  }
  *(undefined *)(param_1 + 0x260) = 0;
  uVar2 = 0xffffffff;
loc_40775F8:
  return CONCAT44(uVar2,iVar3);
}
/* GHIDRADEC_FUNCTION index=2177 start=0x4077602 */

uint _od_dma_intr(int param_1)

{
  uint uVar1;
  char cVar2;
  char cVar3;
  char cVar4;
  char cVar5;
  byte bVar6;
  
  if ((*(uint *)(param_1 + 0x2c) & 0x4000) != 0) {
    *(uint *)(param_1 + 0x220) = *(uint *)(param_1 + 0x220) | 0x10010000;
  }
  uVar1 = *(uint *)(param_1 + 0x220);
  if ((uVar1 & 0x10000000) != 0) {
    cVar2 = (_od_spl & 0x10) != 0;
    *(uint *)(param_1 + 0x220) = *(uint *)(param_1 + 0x220) & 0xefffffff;
    cVar3 = param_1 < 0;
    cVar4 = param_1 == 0;
    cVar5 = '\0';
    bVar6 = 0;
    _odintr(param_1);
    uVar1 = (uint)(byte)(cVar2 << 4 | cVar3 << 3 | cVar4 << 2 | cVar5 << 1 | bVar6);
  }
  return uVar1;
}
/* GHIDRADEC_FUNCTION index=2178 start=0x407765a */

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
/* GHIDRADEC_FUNCTION index=2179 start=0x40780ee */

void _od_reset(int param_1,int param_2,int param_3)

{
  *(uint *)(param_1 + 0x220) = *(uint *)(param_1 + 0x220) | 0x800000;
  *(byte *)(param_3 + 4) = _disr_shadow | *(byte *)(param_3 + 4) & 0xfc | 1;
  _disr_shadow = _disr_shadow | 1;
  _delay(0x50);
  _disr_shadow = _disr_shadow & 0xfe;
  *(byte *)(param_3 + 4) = _disr_shadow;
  *(uint *)(param_1 + 0x220) = *(uint *)(param_1 + 0x220) | 0x8000000;
  *(undefined *)(param_1 + 0x26c) = *(undefined *)(param_1 + 0x269);
  *(undefined *)(param_1 + 0x268) = 0x13;
  if ((*(word *)(param_2 + 0x18) & 0xa00) == 0x200) {
    _delay(10000000);
    *(uint *)(param_1 + 0x220) = *(uint *)(param_1 + 0x220) | 0x200000;
    _odintr(param_1);
  }
  else {
    *(undefined *)(param_1 + 0x260) = 10;
  }
  return;
}
/* GHIDRADEC_FUNCTION index=2180 start=0x40781be */

undefined4 _od_async_attn(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  undefined4 uVar1;
  
  if ((*(uint *)(param_1 + 0x220) & 0x20000) == 0) {
    *(uint *)(param_1 + 0x220) = *(uint *)(param_1 + 0x220) | 0x20000;
    if (*(char *)(param_1 + 599) == '\b') {
      _od_drive_cmd(param_1,param_2,0x5000,6);
      *(undefined *)(param_1 + 0x268) = 0xd;
      uVar1 = 1;
    }
    else {
      _od_perror(param_1,param_2,8,param_3,param_4);
      *(uint *)(param_1 + 0x220) = *(uint *)(param_1 + 0x220) & 0xfffdffff;
      uVar1 = 0;
    }
  }
  else {
    uVar1 = _od_fsm(param_1,param_2,(int)*(char *)(param_1 + 0x268));
  }
  return uVar1;
}
/* GHIDRADEC_FUNCTION index=2181 start=0x4078248 */

void _od_perror(int param_1,int param_2,int param_3,undefined4 param_4,int param_5)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  char cVar4;
  int *piVar5;
  int iVar6;
  sword sVar7;
  undefined *puVar8;
  word wVar9;
  
  cVar4 = *(char *)(param_1 + 599);
  wVar9 = 0;
  iVar2 = *(int *)(param_2 + 8);
  iVar3 = *(int *)(iVar2 + 0xae);
  piVar5 = (int *)((&_odcinfo)[(param_1 + -0x40c3b88) * 0x451ab30b >> 2] + 0x18);
  if (((&_odcinfo)[(param_1 + -0x40c3b88) * 0x451ab30b >> 2] != 0) &&
     (piVar1 = (int *)*piVar5, piVar1 != piVar5)) {
    iVar6 = _disksort_first(piVar1);
    if (iVar6 != 0) {
      wVar9 = *(word *)(iVar6 + 0x1e);
    }
  }
  if (((_od_errmsg_filter <= param_3) || ((_od_dbug._0_1_ & 0x10) != 0)) &&
     ((*(uint *)(param_1 + 0x220) & 0x40000) == 0)) {
    if (*(sword *)(param_1 + 0x248) == 2) {
      puVar8 = (undefined *)&aRead;
    }
    else if (*(sword *)(param_1 + 0x248) == 1) {
      puVar8 = (undefined *)&aWrite;
    }
    else {
      puVar8 = aDriveCommand;
      if (*(sword *)(param_1 + 0x248) == 4) {
        puVar8 = (undefined *)&aErase;
      }
    }
    if (wVar9 == 0) {
      sVar7 = 0x3f;
    }
    else {
      sVar7 = (wVar9 & 7) + 0x61;
    }
    _od_xpr_alert(aOdDCSS,*(undefined2 *)(iVar2 + 0xd2),sVar7,puVar8,
                  *(undefined4 *)(_od_errtype + param_3 * 4),0);
    puVar8 = &unk_40A62E7;
    if ((*(uint *)(param_1 + 0x220) & 0x40000) != 0) {
      puVar8 = aTesting;
    }
    _od_xpr_alert(aSSBlockDPhysBl,*(undefined4 *)(DAT_40b1c14 + cVar4 * 8),puVar8,param_4,
                  param_5 - *(int *)(iVar2 + 0xbe),0);
    iVar2 = *(int *)(iVar3 + 100);
    _od_xpr_alert(aDDD,param_5 / iVar2,0,param_5 % iVar2,0,0);
    if ((_od_dbug._0_1_ & 4) != 0) {
      _od_note(param_1,0x4000,_od_xpr_alert);
    }
  }
  return;
}
/* GHIDRADEC_FUNCTION index=2182 start=0x40783c4 */

void _od_note(int param_1,uint param_2,code *param_3)

{
  word wVar1;
  uint uVar2;
  sword sVar3;
  undefined5 **ppuVar4;
  word *pwVar5;
  undefined (**ppauVar6) [9];
  undefined *puVar7;
  undefined (*pauVar8) [9];
  
  if ((param_2 & 0x40000000) != 0) {
    (*param_3)(aDriveCmd);
    pwVar5 = (word *)&_od_dcmd;
    if (off_40B1DFC != (undefined5 *)0x0) {
      ppuVar4 = &off_40B1DFC;
      do {
        if ((pwVar5[1] & *(word *)(param_1 + 0x25a)) == *pwVar5) {
          (*param_3)(aS0xX,*ppuVar4,*(undefined2 *)(param_1 + 0x25a));
          goto loc_407843C;
        }
        ppuVar4 = ppuVar4 + 2;
        pwVar5 = pwVar5 + 4;
      } while (*ppuVar4 != (undefined5 *)0x0);
    }
    (*param_3)(aUnknown0xX,*(undefined2 *)(param_1 + 0x25a));
  }
loc_407843C:
  if ((param_2 & 0x20000000) != 0) {
    (*param_3)(aFormatterCmd);
    pwVar5 = &_od_fcmd;
    if (off_40B1ECA != (undefined (*) [9])0x0) {
      ppauVar6 = &off_40B1ECA;
      do {
        if (*pwVar5 == (word)*(byte *)(param_1 + 0x25c)) {
          pauVar8 = *ppauVar6;
          puVar7 = (undefined *)&aS;
          goto loc_4078490;
        }
        ppauVar6 = (undefined (**) [9])((int)ppauVar6 + 6);
        pwVar5 = pwVar5 + 3;
      } while (*ppauVar6 != (undefined (*) [9])0x0);
    }
    pauVar8 = (undefined (*) [9])(uint)*(byte *)(param_1 + 0x25c);
    puVar7 = aUnknown0xX;
loc_4078490:
    (*param_3)(puVar7,pauVar8);
  }
  if ((param_2 & 0x4000) != 0) {
    if ((*(word *)(param_1 + 0x24a) & 0xfffe) != 0) {
      uVar2 = 0xf;
      puVar7 = unk_40B1CBC;
      do {
        if (((uint)*(word *)(param_1 + 0x24a) & 1 << (uVar2 & 0x1f)) != 0) {
          (*param_3)(&aS_2,*(undefined4 *)puVar7);
        }
        puVar7 = (undefined *)((int)puVar7 + -8);
        uVar2 = uVar2 - 1;
      } while (0 < (int)uVar2);
    }
    if ((*(word *)(param_1 + 0x24c) & 0xfffe) != 0) {
      uVar2 = 0xf;
      puVar7 = unk_40B1D34;
      do {
        if (((uint)*(word *)(param_1 + 0x24c) & 1 << (uVar2 & 0x1f)) != 0) {
          (*param_3)(&aS_2,*(undefined4 *)puVar7);
        }
        puVar7 = (undefined *)((int)puVar7 + -8);
        uVar2 = uVar2 - 1;
      } while (0 < (int)uVar2);
    }
    if (*(sword *)(param_1 + 0x24e) != 0) {
      uVar2 = 0xf;
      puVar7 = unk_40B1DB4;
      do {
        if (((uint)*(word *)(param_1 + 0x24e) & 1 << (uVar2 & 0x1f)) != 0) {
          (*param_3)(&aS_2,*(undefined4 *)puVar7);
        }
        puVar7 = (undefined *)((int)puVar7 + -8);
        wVar1 = (word)(uVar2 >> 0x10);
        sVar3 = (sword)uVar2 + -1;
        uVar2 = CONCAT22(wVar1,sVar3);
      } while ((sVar3 != -1) || (uVar2 = (uint)wVar1 * 0x10000 - 1, wVar1 != 0));
    }
  }
  return;
}
/* GHIDRADEC_FUNCTION index=2183 start=0x407853c */

undefined4 _od_attn(int param_1,int param_2,int param_3,uint param_4)

{
  undefined4 uVar1;
  
  if ((param_4 & 2) != 0) {
    *(word *)(param_2 + 0x18) = *(word *)(param_2 + 0x18) & 0xdfff;
  }
  if ((*(uint *)(param_1 + 0x220) & 0x4000000) == 0) {
    if ((param_4 & 2) == 0) {
      *(undefined2 *)(param_1 + 0x24e) = 0;
      *(undefined2 *)(param_1 + 0x24c) = *(undefined2 *)(param_1 + 0x24e);
      *(undefined2 *)(param_1 + 0x24a) = *(undefined2 *)(param_1 + 0x24c);
      uVar1 = 0;
    }
    else {
      *(byte *)(param_3 + 5) = *(byte *)(param_3 + 5) & 0xfd;
      *(word *)(param_2 + 0x18) = *(word *)(param_2 + 0x18) & 0xdfff;
      *(uint *)(param_1 + 0x220) = *(uint *)(param_1 + 0x220) | 0x4000000;
      _od_status(param_1,param_2,param_3,0x2000,6);
      *(undefined *)(param_1 + 0x26d) = *(undefined *)(param_1 + 0x267);
      *(undefined *)(param_1 + 0x26e) = *(undefined *)(param_1 + 0x268);
      *(undefined2 *)(param_1 + 0x24e) = 0;
      *(undefined2 *)(param_1 + 0x24c) = *(undefined2 *)(param_1 + 0x24e);
      *(undefined2 *)(param_1 + 0x24a) = *(undefined2 *)(param_1 + 0x24c);
      *(undefined *)(param_1 + 0x268) = 9;
      uVar1 = 1;
    }
  }
  else {
    uVar1 = _od_fsm(param_1,param_2,(int)*(char *)(param_1 + 0x268));
  }
  return uVar1;
}
/* GHIDRADEC_FUNCTION index=2184 start=0x40785f8 */

word _od_status(int param_1,undefined4 param_2,int param_3,undefined4 param_4,uint param_5)

{
  int iVar1;
  word wVar2;
  char cVar3;
  
  cVar3 = '\0';
  iVar1 = _od_drive_cmd(param_1,param_2,param_4,param_5 & 0xc | 2);
  if (iVar1 == 0) {
    _delay(0x96);
    *(undefined *)(param_3 + 7) = 0;
    *(undefined *)(param_3 + 7) = 0x20;
    wVar2 = (word)(byte)(cVar3 << 4);
    if ((param_5 & 1) != 0) {
      iVar1 = 1;
      do {
        if ((*(byte *)(param_3 + 4) & 1) != 0) {
          if (iVar1 < 0x989681) {
            return *(word *)(param_3 + 8);
          }
          break;
        }
        _delay(1);
        iVar1 = iVar1 + 1;
      } while (iVar1 < 0x989681);
      *(undefined *)(param_1 + 599) = 0x3a;
      *(undefined *)(param_1 + 0x260) = 0;
      wVar2 = 0xffff;
    }
  }
  else {
    wVar2 = 0xffff;
  }
  return wVar2;
}
/* GHIDRADEC_FUNCTION index=2185 start=0x40786ba */

undefined4
_od_cmd(word param_1,undefined2 param_2,undefined4 param_3,int param_4,int param_5,
       undefined *param_6,int param_7,int param_8,int param_9,int param_10)

{
  uint *puVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  int iVar5;
  
  iVar2 = (sword)(word)(((uint)param_1 << 0x18) >> 0x1b) * 0xda;
  iVar5 = *(int *)(DAT_40c3f32 + iVar2 + 0x44);
  puVar1 = (uint *)(DAT_40c3f32 + iVar2);
  if (param_10 == 0) {
    while ((*puVar1 & 8) != 0) {
      *puVar1 = *puVar1 | 0x40;
      _sleep(puVar1,0x14);
    }
  }
  *puVar1 = 9;
  *(undefined2 *)(DAT_40c3f32 + iVar2 + 0x6a) = param_2;
  if (param_9 == 0) {
    *(word *)(unk_40C3FA0 + iVar2) = *(word *)(unk_40C3FA0 + iVar2) | 0x80;
  }
  if ((param_7 != 0) && ((*(byte *)(param_7 + 7) & 1) != 0)) {
    DAT_40c3f32[iVar2 + 0x6c] = *(undefined *)(param_7 + 8);
    DAT_40c3f32[iVar2 + 0x6d] = *(undefined *)(param_7 + 9);
    *(word *)(unk_40C3FA0 + iVar2) = *(word *)(unk_40C3FA0 + iVar2) | 0x100;
  }
  *(int *)(DAT_40c3f32 + iVar2 + 0x3c) = param_10;
  *(word *)(DAT_40c3f32 + iVar2 + 0x1e) = param_1;
  *(undefined4 *)(DAT_40c3f32 + iVar2 + 0x24) = param_3;
  iVar5 = *(int *)(iVar5 + 0x5c);
  iVar5 = iVar5 * ((param_5 + -1 + iVar5) / iVar5);
  *(int *)(DAT_40c3f32 + iVar2 + 0x14) = iVar5;
  *(int *)(DAT_40c3f32 + iVar2 + 0x20) = param_4;
  if ((param_7 != 0) && (param_4 != 0)) {
    iVar3 = _useracc(param_4,iVar5,0);
    if (iVar3 == 0) {
      return 0xe;
    }
    *puVar1 = *puVar1 | 0x10;
    *(undefined4 *)(DAT_40c3f32 + iVar2 + 0x2c) =
         *(undefined4 *)(*(int *)(_active_threads + 0xc) + 0x34);
    *(word *)(*(int *)(DAT_40c3f32 + iVar2 + 0x2c) + 0x2a) =
         *(word *)(*(int *)(DAT_40c3f32 + iVar2 + 0x2c) + 0x2a) | 0x800;
    _vslock(param_4,iVar5);
  }
  _odstrategy(puVar1);
  if (_active_threads == 0) {
    iVar3 = 0;
    do {
      _delay(1);
      if ((*puVar1 & 2) != 0) break;
      iVar3 = iVar3 + 1;
    } while (iVar3 < 10000000);
    if (iVar3 == 10000000) {
      dword_40C3DA8 = dword_40C3DA8 | 0x200000;
      _odintr(_od_ctrl);
    }
  }
  else {
    _biowait(puVar1);
  }
  *(word *)(unk_40C3FA0 + iVar2) = *(word *)(unk_40C3FA0 + iVar2) & 0xfe7f;
  if ((param_7 != 0) && (param_4 != 0)) {
    _vsunlock(param_4,iVar5,(*puVar1 & 1) != 0);
    *(word *)(*(int *)(DAT_40c3f32 + iVar2 + 0x2c) + 0x2a) =
         *(word *)(*(int *)(DAT_40c3f32 + iVar2 + 0x2c) + 0x2a) & 0xf7ff;
  }
  if ((param_10 == 0) && (*puVar1 = *puVar1 & 0xfffffff7, (*puVar1 & 0x40) != 0)) {
    _wakeup(puVar1);
  }
  if ((*puVar1 & 4) == 0) {
    if (param_8 != 0) {
      *(undefined4 *)(param_8 + 2) = *(undefined4 *)(DAT_40c3f32 + iVar2 + 0x28);
    }
    uVar4 = 0;
  }
  else {
    if (param_6 != (undefined *)0x0) {
      *param_6 = (char)*(undefined2 *)(DAT_40c3f32 + iVar2 + 0x1c);
    }
    uVar4 = 5;
  }
  return uVar4;
}
/* GHIDRADEC_FUNCTION index=2186 start=0x40788ec */

int _od_read_label(undefined4 param_1,int param_2,int param_3)

{
  uint uVar1;
  undefined2 uVar2;
  word wVar3;
  int iVar4;
  bool bVar5;
  undefined4 uVar6;
  int *piVar7;
  int iVar8;
  int iVar9;
  int iVar10;
  uint *puVar11;
  undefined4 uVar12;
  int iVar13;
  sword sVar14;
  int iVar15;
  undefined *puVar16;
  int *unaff_A3;
  undefined *puVar17;
  undefined *puVar18;
  undefined auStack_32 [7];
  char acStack_2b [39];
  
  uVar12 = _od_readlabel;
  bVar5 = false;
  if (_od_empty < 1) {
    puVar17 = _od_vol;
    do {
      if (-1 < *(sword *)(puVar17 + 0xd8)) break;
      puVar17 = puVar17 + 0xda;
    } while (puVar17 < (undefined *)0x40c592e);
    if (puVar17 == (undefined *)0x40c592e) {
                    /* WARNING: Subroutine does not return */
      _panic(aOdOutOfVols);
    }
  }
  else {
    puVar17 = DAT_40c3dee + _od_empty * 0xda;
  }
  _disksort_free(puVar17);
  _bzero(puVar17,0xda);
  _disksort_init(puVar17);
  *(undefined2 *)(puVar17 + 0xd8) = 0x8020;
  *(sword *)(puVar17 + 0xd2) = (sword)(param_2 + -0x40c3e18 >> 5);
  *(undefined **)(param_2 + 8) = puVar17;
  uVar6 = _od_errmsg_filter;
  iVar13 = ((int)(puVar17 + -0x40c3ec8) * -0x2593f69b >> 1) << 3;
  if (_inhibit_label_errs != 0) {
    _od_errmsg_filter = 9;
  }
  iVar4 = *(char *)(param_2 + 0x1c) * 0x30;
  *(undefined **)(puVar17 + 0xb6) = _od_drive_info + iVar4;
  iVar10 = *(char *)(param_2 + 0x1c) * 6;
  *(int **)(puVar17 + 0xba) = (int *)((int)&_od_more_info + iVar10);
  iVar15 = 0;
  do {
    piVar7 = _od_label;
    iVar9 = *(int *)(DAT_40b1f72 + iVar15 * 4 + iVar4);
    puVar16 = puVar17;
    if (iVar9 != -1) {
      *(int **)(puVar17 + 0xae) = _od_label;
      if (piVar7 == (int *)0x0) {
                    /* WARNING: Subroutine does not return */
        _panic(aOdNoLabelAlloc);
      }
      _bzero(piVar7,0x1c48);
      *(int *)(puVar17 + 0xbe) =
           *(int *)((int)&_od_more_info + iVar10) *
           (int)*(sword *)((int)&_od_more_info + iVar10 + 4);
      piVar7[0x17] = *(int *)(DAT_40b1f72 + iVar4 + 0x10);
      piVar7[0x19] = (int)*(sword *)((int)&_od_more_info + iVar10 + 4);
      piVar7[0x18] = 1;
      *(word *)(puVar17 + 0xd8) = *(word *)(puVar17 + 0xd8) | 0x2000;
      if ((*(byte *)(param_2 + 0x18) & 0x40) == 0) {
        _od_spinup = 1;
        iVar8 = _od_cmd(iVar13,0xf0,0,0,0,acStack_2b,0,0,0,0);
        if (iVar8 == 5) {
          if ((byte)(acStack_2b[0] - 0x3aU) < 2) {
            *(word *)(puVar17 + 0xd8) = *(word *)(puVar17 + 0xd8) & 0xdfff;
            if (param_3 != 0) {
              *(word *)(param_2 + 0x18) = *(word *)(param_2 + 0x18) | 0x1000;
            }
            goto loc_4078DFE;
          }
          if ((acStack_2b[0] == '\x14') || (acStack_2b[0] == '\b')) {
            *(word *)(puVar17 + 0xd8) = *(word *)(puVar17 + 0xd8) & 0xdfff;
            *(word *)(param_2 + 0x18) = *(word *)(param_2 + 0x18) | 0x1000;
            goto loc_4078DFE;
          }
        }
        if (iVar8 != 0) {
          *(word *)(puVar17 + 0xd8) = *(word *)(puVar17 + 0xd8) & 0xdfff;
          *(word *)(param_2 + 0x18) = *(word *)(param_2 + 0x18) | 0x1000;
          goto loc_4078E00;
        }
      }
      *(word *)(param_2 + 0x18) = *(word *)(param_2 + 0x18) | 0x5000;
      iVar8 = _od_cmd(iVar13,2,iVar9,uVar12,0x1c48,acStack_2b,0,0,0,0);
      unaff_A3 = piVar7;
      if (iVar8 == 0) {
        iVar8 = _od_validate_label(uVar12,iVar9);
        if (iVar8 == 0) {
          _bcopy(uVar12,piVar7,0x1c48);
          if ((*piVar7 != 0x4e655854) && (1 < *piVar7 + 0x9b93a9ceU)) {
            iVar8 = 0x16;
            goto loc_4078E00;
          }
          if ((int)*(sword *)((int)&_od_more_info + iVar10 + 4) == piVar7[0x19]) {
            *(undefined4 *)(puVar17 + 0xb2) = _od_bad_block;
            if (((*piVar7 == 0x4e655854) || (*piVar7 == 0x646c5632)) ||
               (iVar8 = _od_cmd(iVar13,2,iVar9 + 4,_od_bad_block,0x3000,0,0,0,0,0), iVar8 == 0)) {
              iVar8 = piVar7[0x19] * piVar7[0x18] * piVar7[0x1a];
              *(int *)(puVar17 + 0xc2) = iVar8;
              if (*piVar7 == 0x4e655854) {
                iVar8 = iVar8 / piVar7[0x19] >> 1;
              }
              else {
                iVar8 = iVar8 >> 2;
              }
              *(int *)(puVar17 + 0xca) = iVar8;
              *(undefined4 *)(puVar17 + 0xc6) = _od_bitmap;
              iVar9 = _od_cmd(iVar13,2,piVar7[0x19] + iVar9,_od_bitmap,
                              *(undefined4 *)(puVar17 + 0xca),0,0,0,0,0);
              if (iVar9 == 0) {
                iVar10 = (int)*(sword *)(*(int *)(param_2 + 0x14) + 0xc);
                if (-1 < iVar10) {
                  *(int *)(_dk_bps + iVar10 * 4) =
                       (piVar7[0x1b] * piVar7[0x19] * piVar7[0x17]) / 0x3c;
                }
                if (param_3 == 0) {
                  if (*piVar7 == 0x4e655854) {
                    uVar12 = 1;
                  }
                  else {
                    uVar12 = 3;
                    if (*piVar7 == 0x646c5632) {
                      uVar12 = 2;
                    }
                  }
                  _printf(aDiskLabelSLabe,piVar7 + 3,uVar12);
                  _od_canon_label(param_1,param_2,puVar17);
                }
                puVar16 = _od_vol;
                goto loc_4078CE4;
              }
            }
          }
        }
      }
      else if (_dma_recover_rl != 0) {
        _od_cmd(iVar13,2,0,uVar12,0x400,acStack_2b,0,0,0,0);
      }
    }
    iVar15 = iVar15 + 1;
  } while (iVar15 < 4);
  if ((*(byte *)(param_2 + 0x18) & 0x40) == 0) goto loc_4078DFE;
  *(word *)(puVar17 + 0xd8) = *(word *)(puVar17 + 0xd8) | 0x2000;
  iVar10 = unaff_A3[0x19] * unaff_A3[0x18] * unaff_A3[0x1a];
  *(int *)(puVar17 + 0xc2) = iVar10;
  if (*unaff_A3 == 0x4e655854) {
    iVar10 = iVar10 / unaff_A3[0x19] >> 1;
  }
  else {
    iVar10 = iVar10 >> 2;
  }
  *(int *)(puVar17 + 0xca) = iVar10;
  *(undefined4 *)(puVar17 + 0xb2) = _od_bad_block;
  _bzero(_od_bad_block,0x3000);
  *(undefined4 *)(puVar17 + 0xc6) = _od_bitmap;
  _bzero(_od_bitmap,*(undefined4 *)(puVar17 + 0xca));
  iVar10 = _rtc_get();
  unaff_A3[10] = iVar10;
  unaff_A3[9] = -0x80000000;
  *unaff_A3 = 0x646c5633;
  iVar10 = _od_write_label(puVar17,0);
  if (iVar10 == 0) {
    *(word *)(puVar17 + 0xd8) = *(word *)(puVar17 + 0xd8) | 0x4000;
    goto loc_407901E;
  }
loc_4078DDE:
  iVar8 = 5;
  puVar16 = puVar17;
  goto loc_4078E00;
  while (puVar16 = puVar16 + 0xda, puVar16 < (undefined *)0x40c592e) {
loc_4078CE4:
    if (((puVar16[0xd8] & 0x40) != 0) && (*(int *)(*(int *)(puVar16 + 0xae) + 0x28) == piVar7[10]))
    {
      *(undefined2 *)(puVar17 + 0xd8) = 0;
      *(sword *)(puVar16 + 0xd2) = (sword)(param_2 + -0x40c3e18 >> 5);
      *(undefined **)(param_2 + 8) = puVar16;
      *(word *)(puVar16 + 0xd8) = *(word *)(puVar16 + 0xd8) | 0x2000;
      iVar13 = ((int)(puVar16 + -0x40c3ec8) * -0x2593f69b >> 1) << 3;
      bVar5 = true;
      goto loc_407901E;
    }
  }
  iVar15 = _rtc_get();
  iVar10 = piVar7[10];
  piVar7[10] = iVar15;
  *(word *)(puVar17 + 0xd8) = *(word *)(puVar17 + 0xd8) | 0x6000;
  iVar15 = _od_write_label(puVar17,0);
  puVar16 = puVar17;
  if (iVar15 != 0) {
    if (iVar15 != 0x13) goto loc_4078DDE;
    piVar7[10] = iVar10;
    *(word *)(puVar17 + 0xd8) = *(word *)(puVar17 + 0xd8) | 4;
  }
loc_407901E:
  iVar8 = 0;
  if (_od_empty < 1) {
    if ((_od_specific == (undefined *)0x0) ||
       ((*(int *)(puVar16 + 0xae) != 0 && (puVar16 == _od_specific)))) {
      if (!bVar5) {
        iVar13 = (int)(puVar16 + -0x40c3ec8) * -0x2593f69b >> 1;
        _sprintf(auStack_32,&aOdD,iVar13);
        uVar12 = 1;
        if ((puVar16[0xd9] & 4) != 0) {
          uVar12 = 3;
        }
        wVar3 = (sword)iVar13 << 3;
        _vol_notify_dev((int)(sword)(wVar3 | (sword)_od_blk_major << 8),
                        (int)(sword)(wVar3 | (sword)_od_raw_major << 8),&unk_40A62E7,
                        CARRY4(*(uint *)(*(int *)(puVar16 + 0xae) + 0x24),
                               *(uint *)(*(int *)(puVar16 + 0xae) + 0x24)),auStack_32,uVar12);
      }
      goto loc_40792AA;
    }
    uVar2 = *(undefined2 *)(puVar16 + 0xd2);
    _od_cmd(iVar13,0xf6,0,0,0,0,0,0,0,0);
    if (((_rootdev >> 8 != _od_blk_major) ||
        ((unk_40C3FA0[(sword)(word)(((uint)_rootdev << 0x18) >> 0x1b) * 0xda] & 0x20) != 0)) &&
       (_panel_req_port != 0)) {
      _vol_panel_remove(_od_vol_tag);
      _vol_panel_disk_label
                (_od_panel_abort,*(int *)(_od_specific + 0xae) + 0xc,1,uVar2,_od_specific,1,
                 &_od_vol_tag);
      goto loc_4079218;
    }
    iVar15 = 0;
    iVar10 = *(int *)(_od_specific + 0xae);
    puVar18 = aWrongDiskPleas_1;
    puVar17 = _od_specific;
  }
  else {
    if (!bVar5) {
      _od_empty = 0;
      _wakeup(&_od_empty);
loc_40792AA:
      if (_od_alert_present == 0) {
        _alert_done();
      }
      else {
        _vol_panel_remove(_od_vol_tag);
        _od_alert_abort = 0;
        _od_alert_present = 0;
      }
      _od_spinup = 0;
      if (_od_requested == 1) {
        _od_specific = (undefined *)0x0;
        _od_requested = 2;
        _wakeup(&_od_requested);
      }
      iVar13 = _hz;
      if (_hz < 0) {
        iVar13 = _hz + 1;
      }
      _od_runout_time = (undefined2)(iVar13 >> 1);
      _od_runout = 0;
      if ((!bVar5) && ((puVar16[0xd8] & 0x40) != 0)) {
        _od_label = (int *)0x0;
        _wakeup(&_od_label);
      }
      sVar14 = (sword)_od_blk_major;
      for (iVar13 = _mounttab; iVar13 != 0; iVar13 = *(int *)(iVar13 + 0x1c)) {
        if ((((word)(*(word *)(iVar13 + 4) & 0xfff8) ==
              (word)((sword)((int)(puVar16 + -0x40c3ec8) * -0x2593f69b >> 1) << 3 | sVar14 << 8)) &&
            (*(int *)(iVar13 + 10) != 0)) &&
           ((*(word *)(iVar13 + 4) != 0xffff &&
            (iVar10 = *(int *)(*(int *)(iVar13 + 10) + 0x20),
            (*(uint *)(iVar10 + 0xd0) & 0xffff00) == 0x10000)))) {
          *(undefined *)(iVar10 + 0xd1) = 2;
          *(undefined *)(iVar10 + 0xd0) = 1;
        }
      }
      *(word *)(param_2 + 0x18) = *(word *)(param_2 + 0x18) | 0x8000;
      *(word *)(puVar16 + 0xd8) = *(word *)(puVar16 + 0xd8) & 0xffbf;
      _od_drive_start(puVar16);
      _od_ctrl_start(*(undefined4 *)(&DAT_40c3e28 + (uint)*(word *)(puVar16 + 0xd2) * 4));
      goto loc_4078FB0;
    }
    uVar2 = *(undefined2 *)(puVar16 + 0xd2);
    _od_cmd(iVar13,0xf6,0,0,0,0,0,0,0,0);
    if (((_rootdev >> 8 != _od_blk_major) ||
        ((unk_40C3FA0[(sword)(word)(((uint)_rootdev << 0x18) >> 0x1b) * 0xda] & 0x20) != 0)) &&
       (_panel_req_port != 0)) {
      iVar10 = _od_empty * 0xda;
      _vol_panel_remove(_od_vol_tag);
      _vol_panel_disk_num(_od_panel_abort,_od_empty + -1,1,uVar2,DAT_40c3dee + iVar10,1,&_od_vol_tag
                         );
loc_4079218:
      _od_alert_present = 1;
      goto loc_4078DFE;
    }
    iVar15 = _od_empty + -1;
    iVar10 = *(int *)(puVar16 + 0xae);
    puVar18 = aWrongDiskThatW;
    puVar17 = puVar16;
  }
  _od_alert(aInsertDisk,puVar18,iVar10 + 0xc,(int)(puVar17 + -0x40c3ec8) * -0x2593f69b >> 1,iVar15,0
            ,0,0,0,0);
loc_4078DFE:
  iVar8 = 2;
loc_4078E00:
  if (((puVar16 == _od_vol) && (param_3 == 0)) &&
     ((iVar10 = _strcmp(&_boot_dev,&aOd), iVar10 == 0 &&
      (((unk_40B6904 & 8) == 0 && ((byte_40B606F & 1) == 0)))))) {
    _mon_boot(0);
  }
  if ((*(word *)(puVar16 + 0xd8) & 0x10) != 0) {
    *(word *)(puVar16 + 0xd8) = *(word *)(puVar16 + 0xd8) & 0xffef;
    _wakeup(puVar16 + 0xd8);
  }
  _od_cmd(iVar13,0xf6,0,0,0,0,0,0,0,0);
  if (((param_3 != 0) && ((0 < _od_empty || (_od_specific != (undefined *)0x0)))) &&
     ((_alert_key == 0x6e || ((_od_alert_abort != 0 || ((*(byte *)(param_2 + 0x18) & 0x40) != 0)))))
     ) {
    if (_od_empty < 1) {
      if (_od_specific != (undefined *)0x0) {
        while (puVar11 = (uint *)_disksort_first(_od_specific), puVar11 != (uint *)0x0) {
          *(undefined2 *)(puVar11 + 7) = 6;
          uVar1 = *puVar11;
          *puVar11 = uVar1 | 4;
          if ((uVar1 & 2) == 0) {
            _biodone(puVar11);
          }
          _disksort_remove(_od_specific,puVar11);
        }
        *(undefined2 *)(_od_specific + 0xd8) = 0x8008;
        _od_ctrl_start(*(undefined4 *)(param_2 + 0x10));
      }
    }
    else {
      _od_empty = -1;
      _wakeup(&_od_empty);
    }
    if (_od_alert_present == 0) {
      _alert_done();
    }
    else {
      _vol_panel_remove(_od_vol_tag);
      _od_alert_abort = 0;
      _od_alert_present = 0;
    }
    if (_od_requested == 1) {
      _od_specific = (undefined *)0x0;
      _od_requested = 2;
      _wakeup(&_od_requested);
    }
  }
  if (!bVar5) {
    *(undefined2 *)(puVar16 + 0xd8) = 0;
  }
  _od_spinup = 0;
loc_4078FB0:
  if ((*(word *)(puVar16 + 0xd8) & 0x10) != 0) {
    *(word *)(puVar16 + 0xd8) = *(word *)(puVar16 + 0xd8) & 0xffef;
    _wakeup(puVar16 + 0xd8);
  }
  *(word *)(puVar16 + 0xd8) = *(word *)(puVar16 + 0xd8) & 0xffdf;
  _od_errmsg_filter = uVar6;
  return iVar8;
}
/* GHIDRADEC_FUNCTION index=2187 start=0x40793fe */

undefined4 _od_write_label(int param_1,undefined4 param_2)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  undefined2 uVar5;
  int iVar4;
  undefined4 uVar6;
  int iVar7;
  undefined2 *puVar8;
  int iVar9;
  word wStack_14;
  undefined auStack_a [5];
  char cStack_5;
  
  uVar6 = 1;
  piVar1 = *(int **)(param_1 + 0xae);
  if ((*piVar1 == 0x4e655854) || (*piVar1 == 0x646c5632)) {
    wStack_14 = 0x1c48;
    puVar8 = (undefined2 *)((int)piVar1 + 0x1c46);
  }
  else {
    wStack_14 = 0x230;
    puVar8 = (undefined2 *)((int)piVar1 + 0x22e);
  }
  iVar3 = ((param_1 + -0x40c3ec8) * -0x2593f69b >> 1) << 3;
  if (piVar1[9] < 0) {
    for (iVar7 = 3; *(int *)(*(int *)(param_1 + 0xb6) + 0x18 + iVar7 * 4) == -1; iVar7 = iVar7 + -1)
    {
    }
    iVar9 = iVar7 + 1;
  }
  else {
    iVar7 = 0;
    iVar9 = 4;
  }
  if (iVar7 < iVar9) {
    do {
      iVar2 = *(int *)(*(int *)(param_1 + 0xb6) + 0x18 + iVar7 * 4);
      if (iVar2 != -1) {
        if (-1 < *(sword *)(param_1 + 0xd8)) {
          return 0x14;
        }
        if (((*(sword *)(piVar1 + 0x1c) == 0) || (iVar2 < *(sword *)(piVar1 + 0x1c))) ||
           (piVar1[0x19] * piVar1[0x18] * piVar1[0x1a] - (int)*(sword *)((int)piVar1 + 0x72) < iVar2
           )) {
          piVar1[1] = iVar2;
          *puVar8 = 0;
          uVar5 = _checksum_16(piVar1,wStack_14 >> 1);
          *puVar8 = uVar5;
          iVar4 = _od_cmd(iVar3,1,iVar2,piVar1,0x1c48,&cStack_5,0,0,0,param_2);
          if ((iVar4 == 0) &&
             ((((*piVar1 == 0x4e655854 || (*piVar1 == 0x646c5632)) ||
               (iVar4 = _od_cmd(iVar3,1,iVar2 + 4,*(undefined4 *)(param_1 + 0xb2),0x3000,&cStack_5,0
                                ,0,0,param_2), iVar4 == 0)) &&
              (iVar4 = _od_cmd(iVar3,1,piVar1[0x19] + iVar2,*(undefined4 *)(param_1 + 0xc6),
                               *(undefined4 *)(param_1 + 0xca),&cStack_5,0,0,0,param_2), iVar4 == 0)
              ))) {
            if ((piVar1[9] < 0) && (_dma_recover_wl != 0)) {
              uVar6 = _kalloc(0x400);
              _od_cmd(iVar3,2,iVar2,uVar6,0x400,auStack_a,0,0,0,param_2);
              _kfree(uVar6,0x400);
            }
            uVar6 = 0;
          }
          else if ((iVar4 == 5) && (cStack_5 == '\x13')) {
            return 0x13;
          }
        }
      }
      iVar7 = iVar7 + 1;
    } while (iVar7 < iVar9);
  }
  return uVar6;
}
/* GHIDRADEC_FUNCTION index=2188 start=0x40795fa */

void _od_update(void)

{
  uint uVar1;
  uint *puVar2;
  undefined *puVar3;
  undefined *puVar4;
  
  puVar4 = _od_vol;
  puVar3 = unk_40C3FA0;
  do {
    if ((*(word *)puVar3 & 0xf004) == 0xf000) {
      puVar2 = (uint *)(puVar4 + 0x6a);
      while ((*puVar2 & 8) != 0) {
        *puVar2 = *puVar2 | 0x40;
        _sleep(puVar2,0x14);
      }
      *puVar2 = 8;
      *(word *)puVar3 = *(word *)puVar3 | 0x400;
      _od_write_label(puVar4,0x7f);
      if ((*(word *)puVar3 & 0x200) != 0) {
        _wakeup(puVar4);
      }
      *(word *)puVar3 = *(word *)puVar3 & 63999;
      uVar1 = *puVar2;
      *puVar2 = uVar1 & 0xfffffff7;
      if ((uVar1 & 0x40) != 0) {
        _wakeup(puVar2);
      }
    }
    if (((sword)*(word *)puVar3 < 0) &&
       (*(word *)puVar3 = *(word *)puVar3 & 0xefff, (*(word *)puVar3 & 0x800) != 0)) {
      _od_cmd((int)(puVar4 + -0x40c3ec8) * 0x69b02594,0xf6,0,0,0,0,0,0,0,0);
    }
    puVar3 = (undefined *)((int)puVar3 + 0xda);
    puVar4 = puVar4 + 0xda;
  } while (puVar4 < (undefined *)0x40c592e);
  return;
}
/* GHIDRADEC_FUNCTION index=2189 start=0x4079720 */

void _od_update_thread(void)

{
  undefined4 uVar1;
  undefined4 uVar2;
  
  uVar1 = *(undefined4 *)(_active_threads + 0x4c);
  uVar2 = *(undefined4 *)(_active_threads + 0x54);
  *(undefined4 *)(_active_threads + 0x4c) = 0x1f;
  *(undefined4 *)(_active_threads + 0x54) = 0x1f;
  _od_update();
  *(undefined4 *)(_active_threads + 0x4c) = uVar1;
  *(undefined4 *)(_active_threads + 0x54) = uVar2;
  _od_update_time = 0;
  _thread_terminate(_active_threads);
  _thread_halt_self();
  return;
}
/* GHIDRADEC_FUNCTION index=2190 start=0x4079784 */

undefined4 _od_validate_label(int *param_1,int param_2)

{
  int iVar1;
  sword sVar2;
  word wVar3;
  sword sVar4;
  sword *psVar5;
  
  iVar1 = *param_1;
  if (iVar1 != 0) {
    if ((iVar1 == 0x4e655854) || (iVar1 == 0x646c5632)) {
      wVar3 = 0x1c48;
      psVar5 = (sword *)((int)param_1 + 0x1c46);
    }
    else {
      wVar3 = 0x230;
      psVar5 = (sword *)((int)param_1 + 0x22e);
    }
    if (param_1[1] == param_2) {
      sVar2 = *psVar5;
      *psVar5 = 0;
      sVar4 = _checksum_16(param_1,wVar3 >> 1);
      if (sVar2 != sVar4) {
        return 0xffffffff;
      }
      return 0;
    }
  }
  return 0xffffffff;
}
/* GHIDRADEC_FUNCTION index=2191 start=0x40797f2 */

void _od_spiral(void)

{
  word *pwVar1;
  undefined *puVar2;
  undefined *puVar3;
  
  puVar2 = _od_drive;
  puVar3 = unk_40C3E36;
  pwVar1 = &word_40C3E30;
  do {
    if ((*puVar3 == -1) && ((*(byte *)(*(int *)((int)puVar2 + 8) + 0xd8) & 0x20) != 0)) {
      _od_cmd((*(int *)((int)puVar2 + 8) + -0x40c3ec8) * 0x69b02594 & 0xfffffff8,0xf3,0,0,0,0,0,0,0,
              0);
      *pwVar1 = *pwVar1 & 0xdfff;
      *puVar3 = '\0';
    }
    puVar3 = puVar3 + 0x20;
    pwVar1 = pwVar1 + 0x10;
    puVar2 = (undefined *)((int)puVar2 + 0x20);
  } while (puVar2 < &_od_empty);
  _thread_terminate(_active_threads);
  _thread_halt_self();
  return;
}
/* GHIDRADEC_FUNCTION index=2192 start=0x4079892 */

void _od_creq_timeout(int param_1)

{
  *(undefined2 *)(param_1 + 10) = 0;
  _wakeup(_od_creq_timeout);
  return;
}
/* GHIDRADEC_FUNCTION index=2193 start=0x40798ae */

int _odioctl(word param_1,int param_2,uint *param_3)

{
  uint uVar1;
  sword sVar2;
  uint *puVar3;
  uint uVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  undefined *puVar9;
  int *piVar10;
  undefined4 uVar11;
  undefined4 uStack_2c;
  int iStack_28;
  uint uStack_24;
  uint uStack_20;
  undefined auStack_1c [8];
  int *piStack_14;
  uint uStack_10;
  uint uStack_c;
  uint uStack_8;
  
  uVar4 = (param_1 & 0xff) >> 3;
  iVar5 = uVar4 * 0xda;
  uVar1 = *param_3;
  if (param_2 == 0x2000640f) {
loc_40799D6:
    iVar5 = _od_lock(param_2);
    return iVar5;
  }
  if (param_2 < 0x20006410) {
    if (param_2 == -0x7ff39bf2) {
      uStack_c = param_3[1];
      uStack_8 = param_3[2];
      uStack_10 = uVar1;
      iVar5 = _vm_map_pageable(*(undefined4 *)(*(int *)(_active_threads + 0xc) + 8),uVar1,uStack_c,
                               uStack_8);
      if (uStack_8 == 0) {
        _od_make_free_pages();
        return iVar5;
      }
      return iVar5;
    }
    if (param_2 < -0x7ff39bf1) {
      if (param_2 == -0x7ffb9bf4) {
        iVar5 = _suser();
        if (iVar5 != 0) {
          _od_dbug = *param_3;
          if ((_od_dbug & 0x1000000) != 0) {
            byte_40C3DF7 = byte_40C3DF7 & 0xbf;
            return 0;
          }
          byte_40C3DF7 = byte_40C3DF7 | 0x40;
          return 0;
        }
        goto loc_4079EE4;
      }
    }
    else {
      if (param_2 == 0x20006407) {
        iVar5 = _suser();
        if (iVar5 != 0) {
          _bzero(&_od_stats,0x28);
          return 0;
        }
        goto loc_4079EE4;
      }
      if (param_2 == 0x20006408) {
        _copyoutmsg(&_od_stats,uVar1,0x28);
        return 0;
      }
    }
  }
  else {
    if (param_2 == 0x4004640b) {
      *param_3 = _od_dbug;
      return 0;
    }
    if (param_2 < 0x4004640c) {
      if (param_2 == 0x20006410) goto loc_40799D6;
    }
    else {
      if (param_2 == 0x40046411) {
        puVar9 = _od_vol;
        do {
          if (-1 < *(sword *)(puVar9 + 0xd8)) break;
          puVar9 = puVar9 + 0xda;
        } while (puVar9 < (undefined *)0x40c592e);
        if (puVar9 == (undefined *)0x40c592e) {
          *param_3 = 0xffffffff;
          return 0;
        }
        *param_3 = (int)(puVar9 + -0x40c3ec8) * -0x2593f69b >> 1;
        return 0;
      }
      if (param_2 == 0x40306405) {
        iVar5 = (char)(&byte_40C3E34)[(uint)*(word *)(_od_vol + iVar5 + 0xd2) * 0x20] * 0x30;
        *param_3 = *(uint *)(_od_drive_info + iVar5);
        param_3[1] = *(uint *)(_od_drive_info + iVar5 + 4);
        param_3[2] = *(uint *)(_od_drive_info + iVar5 + 8);
        param_3[3] = *(uint *)(DAT_40b1f66 + iVar5);
        param_3[4] = *(uint *)(DAT_40b1f66 + iVar5 + 4);
        param_3[5] = *(uint *)(DAT_40b1f66 + iVar5 + 8);
        param_3[6] = *(uint *)(DAT_40b1f66 + iVar5 + 0xc);
        param_3[7] = *(uint *)(DAT_40b1f66 + iVar5 + 0x10);
        param_3[8] = *(uint *)(DAT_40b1f66 + iVar5 + 0x14);
        param_3[9] = *(uint *)(DAT_40b1f66 + iVar5 + 0x18);
        param_3[10] = *(uint *)(DAT_40b1f66 + iVar5 + 0x1c);
        param_3[0xb] = *(uint *)(DAT_40b1f66 + iVar5 + 0x20);
        return 0;
      }
    }
  }
  if ((0x1e < uVar4) || (-1 < *(sword *)(unk_40C3FA0 + iVar5))) {
    return 6;
  }
  piStack_14 = *(int **)(_od_vol + iVar5 + 0xae);
  if (param_2 == 0x20006402) {
    if ((unk_40C3FA0[iVar5] & 0x40) == 0) {
      return 6;
    }
    uVar11 = *(undefined4 *)(_od_vol + iVar5 + 0xca);
    piVar10 = *(int **)(_od_vol + iVar5 + 0xc6);
loc_4079D46:
    iVar5 = _copyoutmsg(piVar10,uVar1,uVar11);
    return iVar5;
  }
  if (0x20006402 < param_2) {
    if (param_2 != 0x20006412) {
      if (param_2 < 0x20006413) {
        if (param_2 != 0x20006403) {
          return 0x19;
        }
        iVar8 = _suser();
        if (iVar8 != 0) {
          if (*(int *)(_od_vol + iVar5 + 0xc6) == 0) {
            return 0;
          }
          iVar8 = _copyinmsg(uVar1,*(int *)(_od_vol + iVar5 + 0xc6),
                             *(undefined4 *)(_od_vol + iVar5 + 0xca));
          *(word *)(unk_40C3FA0 + iVar5) = *(word *)(unk_40C3FA0 + iVar5) | 0x1000;
          if (_od_update_time == 0) {
            _od_update_time = 1;
            return iVar8;
          }
          return iVar8;
        }
      }
      else if (param_2 == 0x20006413) {
        iVar8 = _suser();
        if (iVar8 != 0) {
          if (*(int *)(_od_vol + iVar5 + 0xb2) == 0) {
            return 0;
          }
          iVar8 = _copyinmsg(uVar1,*(int *)(_od_vol + iVar5 + 0xb2),0x3000);
          *(word *)(unk_40C3FA0 + iVar5) = *(word *)(unk_40C3FA0 + iVar5) | 0x1000;
          _od_canon_remap(_od_ctrl);
          if (_od_update_time == 0) {
            _od_update_time = 1;
            return iVar8;
          }
          return iVar8;
        }
      }
      else {
        if (param_2 != 0x20006415) {
          return 0x19;
        }
        iVar8 = _suser();
        if ((iVar8 != 0) ||
           (*(sword *)(_od_vol + iVar5 + 0xce) == *(sword *)(*(int *)(_active_u + 0x1a) + 6))) {
          _od_sync((int)(sword)((sword)((int)(uVar4 * 2) >> 1) << 3 | (sword)_od_blk_major << 8));
          iVar5 = _od_cmd((int)(sword)param_1,0xf1,0,0,0,0,0,0,0,0);
          return iVar5;
        }
      }
      goto loc_4079EE4;
    }
    if ((unk_40C3FA0[iVar5] & 0x40) == 0) {
      return 6;
    }
    uVar11 = 0x3000;
    piVar10 = *(int **)(_od_vol + iVar5 + 0xb2);
    goto loc_4079D46;
  }
  if (param_2 == 0x20006400) {
    if ((unk_40C3FA0[iVar5] & 0x40) == 0) {
      return 6;
    }
    if (piStack_14[9] < 0) {
      return 6;
    }
    uVar11 = 0x1c48;
    piVar10 = piStack_14;
    goto loc_4079D46;
  }
  if (param_2 < 0x20006401) {
    if (param_2 != -0x3faf9bfc) {
      return 0x19;
    }
    puVar3 = param_3 + 4;
    if (*(char *)puVar3 != -0xf) {
      iVar8 = _suser();
      if (iVar8 == 0) goto loc_4079EE4;
      if (*(char *)puVar3 != -0xf) goto loc_4079E02;
    }
    if ((*(sword *)(_od_vol + iVar5 + 0xce) == *(sword *)(*(int *)(_active_u + 0x1a) + 6)) ||
       (iVar5 = _suser(), iVar5 != 0)) {
loc_4079E02:
      _microtime(auStack_1c);
      iVar5 = _od_cmd((int)(sword)param_1,*(undefined *)puVar3,*(undefined4 *)((int)param_3 + 0x12),
                      param_3[1],*param_3,param_3 + 0xc,puVar3,param_3 + 0xc,0,0);
      _microtime(&uStack_24);
      _timevalsub(&uStack_24,auStack_1c);
      param_3[2] = uStack_24;
      param_3[3] = uStack_20;
      if (*(sword *)((int)param_3 + 0x1a) != 0) {
        uStack_2c = 0;
        iStack_28 = (uint)*(word *)((int)param_3 + 0x1a) * 1000;
        _timevalfix(&uStack_2c);
        _us_timeout(_od_creq_timeout,puVar3,&uStack_2c,0);
        sVar2 = *(sword *)((int)param_3 + 0x1a);
        while (sVar2 != 0) {
          _sleep(_od_creq_timeout,0x14);
          sVar2 = *(sword *)((int)param_3 + 0x1a);
        }
        return iVar5;
      }
      return iVar5;
    }
loc_4079EE4:
    return (int)*(char *)(dword_40B57D4 + 100);
  }
  iVar8 = _suser();
  if (iVar8 == 0) goto loc_4079EE4;
  iVar8 = *(int *)(_od_vol + iVar5 + 0xca);
  if (piStack_14 == (int *)0x0) {
    iVar6 = _kmem_alloc_wired(_kernel_map,&piStack_14,0x1c48);
    if (iVar6 != 0) {
                    /* WARNING: Subroutine does not return */
      _panic(aOdSlabelAlloc);
    }
    iVar6 = 0;
  }
  else {
    iVar6 = piStack_14[10];
  }
  iVar7 = _copyinmsg(uVar1,piStack_14,0x1c48);
  if (iVar7 != 0) {
    return iVar7;
  }
  *(int **)(_od_vol + iVar5 + 0xae) = piStack_14;
  if (*(int *)(_od_vol + iVar5 + 0xb2) == 0) {
    iVar7 = _kmem_alloc_wired(_kernel_map,_od_vol + iVar5 + 0xb2,0x3000);
    if (iVar7 != 0) {
      return 0xc;
    }
    _bzero(*(undefined4 *)(_od_vol + iVar5 + 0xb2),0x3000);
  }
  *(int *)(_od_vol + iVar5 + 0xbe) = piStack_14[0x19] * **(int **)(_od_vol + iVar5 + 0xba);
  iVar7 = piStack_14[0x19] * piStack_14[0x18] * piStack_14[0x1a];
  *(int *)(_od_vol + iVar5 + 0xc2) = iVar7;
  if (*piStack_14 == 0x4e655854) {
    iVar7 = iVar7 / piStack_14[0x19] >> 1;
  }
  else {
    iVar7 = iVar7 >> 2;
  }
  if (*(int *)(_od_vol + iVar5 + 0xc6) != 0) {
    if (iVar7 == iVar8) goto loc_4079C5E;
    _kmem_free(_kernel_map,*(int *)(_od_vol + iVar5 + 0xc6),0x10000);
  }
  *(int *)(_od_vol + iVar5 + 0xca) = iVar7;
  iVar8 = _kmem_alloc_wired(_kernel_map,_od_vol + iVar5 + 0xc6,0x10000);
  if (iVar8 != 0) {
    return 0xc;
  }
  _bzero(*(undefined4 *)(_od_vol + iVar5 + 0xc6),*(undefined4 *)(_od_vol + iVar5 + 0xca));
loc_4079C5E:
  if (iVar6 == 0) {
    iVar6 = _rtc_get();
  }
  piStack_14[10] = iVar6;
  *(byte *)(piStack_14 + 9) = *(byte *)(piStack_14 + 9) & 0x7f;
  iVar8 = _od_write_label(_od_vol + iVar5,0);
  if (iVar8 == 0) {
    *(word *)(unk_40C3FA0 + iVar5) = *(word *)(unk_40C3FA0 + iVar5) | 0x4000;
    (&word_40C3E30)[(uint)*(word *)(_od_vol + iVar5 + 0xd2) * 0x10] =
         (&word_40C3E30)[(uint)*(word *)(_od_vol + iVar5 + 0xd2) * 0x10] | 0x8000;
    _od_canon_remap(_od_ctrl);
    return 0;
  }
  return 5;
}
/* GHIDRADEC_FUNCTION index=2194 start=0x4079f4c */

uint _od_canon_remap(undefined4 param_1,undefined4 param_2,int param_3,int param_4)

{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  uint uVar6;
  byte *pbVar7;
  sword *psStack_8;
  
  uVar1 = _od_errmsg_filter;
  uVar6 = 0;
  _od_errmsg_filter = 9;
  _kmem_alloc_wired(_kernel_map,&psStack_8,0x400);
  iVar2 = _od_cmd(((param_3 + -0x40c3ec8) * -0x2593f69b >> 1) << 3,2,
                  (0x4d50 - **(int **)(param_3 + 0xba)) *
                  (int)*(sword *)(*(int **)(param_3 + 0xba) + 1),psStack_8,0x400,0,0,0,0,0);
  if ((((iVar2 == 0) && (*psStack_8 == -0x1fe)) && (uVar6 = (uint)(word)psStack_8[1], param_4 == 0))
     && (iVar2 = 0, uVar6 != 0)) {
    iVar5 = 4;
    do {
      pbVar7 = (byte *)(iVar5 + (int)psStack_8);
      iVar4 = (uint)pbVar7[3] +
              (int)*(sword *)(*(int *)(param_3 + 0xba) + 4) *
              CONCAT31((int3)((uint)pbVar7[1] * 0x100 + (uint)*pbVar7 * 0x10000 >> 8),pbVar7[2]);
      if ((iVar4 != 0) && (*(int *)(param_3 + 0xbe) <= iVar4)) {
        iVar3 = _od_locate_alt(param_1,param_2,param_3,iVar4 - *(int *)(param_3 + 0xbe),iVar4);
        if (iVar3 == -1) {
          iVar4 = _od_remap(param_1,param_2,param_3,iVar4);
          if (iVar4 == 0) break;
        }
      }
      iVar5 = iVar5 + 4;
      iVar2 = iVar2 + 1;
    } while (iVar2 < (int)uVar6);
  }
  _kmem_free(_kernel_map,psStack_8,0x400);
  _od_errmsg_filter = uVar1;
  return uVar6;
}
/* GHIDRADEC_FUNCTION index=2195 start=0x407a09c */

void _od_canon_label(undefined4 param_1,undefined4 param_2,int param_3)

{
  undefined4 uVar1;
  int iVar2;
  uint uVar3;
  sword *psStack_12;
  undefined auStack_e [2];
  undefined uStack_c;
  undefined auStack_b [2];
  undefined uStack_9;
  undefined auStack_8 [2];
  undefined uStack_6;
  
  uVar1 = _od_errmsg_filter;
  _od_errmsg_filter = 9;
  _kmem_alloc_wired(_kernel_map,&psStack_12,0x400);
  iVar2 = _od_cmd(((param_3 + -0x40c3ec8) * -0x2593f69b >> 1) << 3,2,
                  (0x4d6a - **(int **)(param_3 + 0xba)) *
                  (int)*(sword *)(*(int **)(param_3 + 0xba) + 1),psStack_12,0x400,0,0,0,0,0);
  if ((iVar2 == 0) && (*psStack_12 == -0xff)) {
    _bcopy(psStack_12 + 0x1b,auStack_e,2);
    uStack_c = 0x2f;
    _bcopy(psStack_12 + 0x1c,auStack_b,2);
    uStack_9 = 0x2f;
    _bcopy(psStack_12 + 0x1a,auStack_8,2);
    uStack_6 = 0;
    uVar3 = _od_canon_remap(param_1,param_2,param_3,1);
    _printf(aLotSSerialSDat,psStack_12 + 9,psStack_12 + 0x11,auStack_e,uVar3 & 0xffff,
            (int)(sword)(uVar3 >> 0x10));
  }
  _kmem_free(_kernel_map,psStack_12,0x400);
  _od_errmsg_filter = uVar1;
  return;
}
/* GHIDRADEC_FUNCTION index=2196 start=0x407a1dc */

undefined4 _od_lock(int param_1)

{
  word wVar1;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  sword sVar5;
  undefined4 *puVar6;
  undefined *puVar7;
  char *pcVar8;
  undefined4 *puVar9;
  
  wVar1 = *(word *)(*(int *)(*(int *)(_active_threads + 0xc) + 0x34) + 0x30);
  if (((param_1 == 0x2000640f) && (_od_lock_pid != 0)) ||
     ((param_1 == 0x20006410 && (wVar1 != _od_lock_pid)))) {
    uVar2 = 0x10;
  }
  else {
    _od_lock_pid = wVar1;
    if (param_1 == 0x20006410) {
      puVar7 = _od_drive;
      do {
        if ((((*(word *)((int)puVar7 + 0x18) & 0xc000) == 0xc000) &&
            (iVar4 = *(int *)((int)puVar7 + 8), iVar4 != 0)) &&
           ((*(byte *)(iVar4 + 0xd8) & 0x20) != 0)) {
          sVar5 = (sword)_od_blk_major;
          iVar3 = _getnewbuf_count();
          if (2 < iVar3) {
            _update((int)(sword)((sword)((iVar4 + -0x40c3ec8) * -0x2593f69b >> 1) << 3 | sVar5 << 8)
                    ,0xfffffff8);
          }
        }
        puVar7 = (undefined *)((int)puVar7 + 0x20);
      } while (puVar7 < &_od_empty);
    }
    puVar9 = _all_psets;
    if ((undefined4 **)_all_psets != &_all_psets) {
      do {
        for (puVar6 = (undefined4 *)puVar9[0x4c]; puVar6 != puVar9 + 0x4c;
            puVar6 = (undefined4 *)puVar6[6]) {
          pcVar8 = (char *)(*(int *)(puVar6[3] + 0x30) + 8);
          iVar4 = _strcmp(pcVar8,*(int *)(_kernel_task + 0x30) + 8);
          if (((iVar4 != 0) && (iVar4 = _strcmp(pcVar8,&aBiod), iVar4 != 0)) &&
             (((uint)_od_lock_pid != (int)*(sword *)(*(int *)(puVar6[3] + 0x34) + 0x30) &&
              (*pcVar8 != '\0')))) {
            if (param_1 == 0x2000640f) {
              _thread_suspend(puVar6);
            }
            else {
              _thread_resume(puVar6);
            }
          }
        }
        puVar6 = puVar9 + 0x50;
        puVar9 = (undefined4 *)*puVar6;
      } while ((undefined4 **)*puVar6 != &_all_psets);
    }
    if (param_1 == 0x2000640f) {
      _mfs_cache_clear();
    }
    if (param_1 == 0x20006410) {
      _od_lock_pid = 0;
    }
    uVar2 = 0;
  }
  return uVar2;
}
/* GHIDRADEC_FUNCTION index=2197 start=0x407a368 */

void _od_make_free_pages(void)

{
  int iVar1;
  undefined4 uStack_8;
  
  iVar1 = _page_size * 2 * _vm_page_free_target;
  _kmem_alloc_wired(_kernel_map,&uStack_8,iVar1);
  _kmem_free(_kernel_map,uStack_8,iVar1);
  return;
}
/* GHIDRADEC_FUNCTION index=2198 start=0x407a3ac */

void _od_unlock_check(sword param_1)

{
  if (_od_lock_pid == param_1) {
    _od_lock(0x20006410);
  }
  return;
}
/* GHIDRADEC_FUNCTION index=2199 start=0x407a3cc */

void _odminphys(int param_1)

{
  int iVar1;
  
  iVar1 = 0x10000;
  if (_dma_chip == 0x139) {
    iVar1 = 0x2000;
  }
  if (iVar1 < *(int *)(param_1 + 0x14)) {
    *(int *)(param_1 + 0x14) = iVar1;
  }
  return;
}

