
int sub_408667A(int param_1)

{
  uint uVar1;
  uint *puVar2;
  int iVar3;
  byte bVar4;
  int iVar5;
  uint *puVar6;
  bool bVar7;
  bool bVar8;
  int iVar9;
  undefined4 uVar10;
  uint uVar11;
  uint *puVar12;
  uint uVar13;
  uint *puVar14;
  uint uVar15;
  uint unaff_D6;
  int iVar16;
  uint **ppuVar17;
  uint *puStack_ac;
  uint *puStack_a8;
  uint *puStack_a4;
  uint *puStack_a0;
  uint **ppuStack_9c;
  uint **ppuStack_98;
  uint *puStack_6a;
  uint uStack_64;
  uint *puStack_5c;
  uint *puStack_58;
  uint *puStack_54;
  uint uStack_50;
  int iStack_4c;
  byte bStack_45;
  uint uStack_44;
  uint *puStack_3c;
  char cStack_31;
  uint *puStack_30;
  uint uStack_2c;
  undefined4 uStack_28;
  undefined4 uStack_24;
  uint *puStack_20;
  uint *puStack_1c;
  uint *puStack_18;
  uint *puStack_14;
  int iStack_10;
  uint *puStack_c;
  uint *puStack_8;
  
  uVar13 = 0;
  puStack_30 = (uint *)0x0;
  puStack_6a = (uint *)0x0;
  puVar12 = (uint *)0x0;
  iVar16 = 0;
  uVar1 = *(uint *)(param_1 + 0xc);
  puVar2 = *(uint **)(param_1 + 0x1c);
  ppuStack_98 = *(uint ***)(param_1 + 0x24);
  bVar7 = false;
  uStack_44 = 0;
  bStack_45 = 1;
  uVar15 = 0xffffffff;
  puStack_54 = (uint *)0x0;
  puStack_58 = (uint *)0x0;
  puStack_5c = (uint *)0x0;
  bVar8 = false;
  cStack_31 = (char)uVar1;
  if (-1 < cStack_31) {
    iStack_4c = (&unk_40C6DF4)[uVar1 & 0x7f];
    if (iStack_4c == 0) {
      return 0x6b;
    }
    bVar7 = true;
  }
  puVar6 = (uint *)(uVar1 & 0x7f);
  if (cStack_31 < '\0') {
    uVar15 = -(int)-(puVar6 == (uint *)0x2);
  }
  if (!bVar7) {
    ppuStack_9c = (uint **)&dword_40C6E94;
    if (uVar15 == 1) {
      ppuStack_9c = (uint **)&dword_40C6E8C;
    }
    puStack_a0 = (uint *)0x4086724;
    iVar9 = _snd_get_owner();
    if (iVar9 == 0) {
      return 0x6b;
    }
    puStack_3c = *(uint **)(iVar9 + 4);
  }
  if (*(int *)(param_1 + 0x14) != 0) {
    if (*(int *)(param_1 + 0x14) != 1) {
      return 0x66;
    }
    if (bVar7) {
      ppuStack_98 = (uint **)0x0;
      ppuStack_9c = *(uint ***)(iStack_4c + 0x26);
      puStack_a0 = *(uint **)(param_1 + 0x10);
      ppuVar17 = &puStack_a0;
    }
    else {
      ppuStack_98 = &puStack_c;
      ppuStack_9c = &puStack_8;
      puStack_a0 = puStack_3c;
      puStack_a4 = (uint *)0x4086776;
      (*___NXAudioStreamInfo)();
      puStack_a4 = puStack_c;
      puStack_a8 = puStack_8;
      puStack_ac = *(uint **)(param_1 + 0x10);
      ppuVar17 = &puStack_ac;
    }
    *(undefined4 *)((int)ppuVar17 + -4) = 0x408678c;
    _snd_reply_ret_samples();
    return 0;
  }
  iVar9 = *(int *)(param_1 + 4) + -0x28;
  iStack_10 = param_1 + 0x28;
  if (0 < iVar9) {
    bStack_45 = 1;
    do {
      switch(*(undefined4 *)(iStack_10 + 4)) {
      case :
        iVar9 = iVar9 + -0x28;
        unaff_D6 = *(uint *)(iStack_10 + 0xc);
        uStack_2c = *(uint *)(iStack_10 + 0x24);
        uVar13 = *(uint *)(iStack_10 + 0x20);
        if ((iVar16 == 0) && (uVar15 == 1)) {
          iVar16 = 0x67;
        }
        if ((uVar1 & 0x80) == 0) {
          if ((puVar6 < (uint *)0x13) && (iVar5 = (&unk_40C6DF4)[(int)puVar6], iVar5 != 0)) {
            if (((dword_40C6E84 & 0x10000) == 0) || ((uVar1 & 0x7f) != 2)) {
              uStack_64 = (uint)*(word *)(iVar5 + 0x4e);
              if (*(byte *)(iVar5 + 0x53) == 5) {
                puVar12 = (uint *)(uStack_64 * 2);
              }
              else {
                puVar12 = (uint *)(*(byte *)(iVar5 + 0x53) * uStack_64);
              }
            }
            goto loc_4086884;
          }
          iVar16 = 0x6b;
        }
        else {
loc_4086884:
          if ((iVar16 == 0) && ((uVar1 & 0x80) == 0)) {
            if (((dword_40C6E84 & 0x10000) == 0) || (puVar6 != (uint *)0x2)) {
              if ((dword_40C6E84 & 0x2000) != 0) {
                if ((puVar12 != (uint *)0x0) && (uStack_2c % (uint)puVar12 == 0)) {
                  uVar15 = uVar13 % (uint)puVar12;
                  goto loc_40868F0;
                }
loc_40868F4:
                iVar16 = 0x6f;
              }
            }
            else {
              if (*(byte *)(dword_40C6DFC + 0x53) == 5) {
                uVar15 = 2;
              }
              else {
                uVar15 = (uint)*(byte *)(dword_40C6DFC + 0x53);
              }
              if (uVar15 == 0) {
                iVar16 = 0x67;
              }
              else {
                uVar15 = uStack_2c % uVar15;
loc_40868F0:
                if (uVar15 != 0) goto loc_40868F4;
              }
            }
          }
        }
        uVar15 = 0;
        iStack_10 = iStack_10 + 0x28;
        break;
      case :
        uVar13 = *(uint *)(iStack_10 + 0x1e) >> 0x14;
        iVar5 = uVar13 + 0x20;
        iVar9 = iVar9 - iVar5;
        if (uVar13 == 0) {
          bStack_45 = 0;
        }
        else {
          iVar16 = 0x6e;
        }
        uVar13 = *(uint *)(iStack_10 + 0x10);
        if ((uVar1 & 0x80) == 0) {
          if ((puVar6 < (uint *)0x13) && (iVar3 = (&unk_40C6DF4)[(int)puVar6], iVar3 != 0)) {
            if (*(byte *)(iVar3 + 0x53) == 5) {
              puVar12 = (uint *)((uint)*(word *)(iVar3 + 0x4e) * 2);
            }
            else {
              puVar12 = (uint *)((uint)*(byte *)(iVar3 + 0x53) * (uint)*(word *)(iVar3 + 0x4e));
            }
            goto loc_408696A;
          }
          iVar16 = 0x6b;
        }
        else {
loc_408696A:
          if (iVar16 == 0) {
            if ((((uVar1 & 0x80) == 0) && ((dword_40C6E84 & 0x2000) != 0)) &&
               ((puVar12 == (uint *)0x0 || (uVar13 % (uint)puVar12 != 0)))) {
              iVar16 = 0x6f;
            }
            if ((iVar16 == 0) && (uVar15 == 0)) {
              iVar16 = 0x67;
            }
          }
        }
        uVar15 = 1;
        iStack_10 = iStack_10 + iVar5;
        break;
      case :
        iVar5 = iStack_10 + 0x18;
        iVar9 = iVar9 + -0x18;
        puStack_30 = *(uint **)(iStack_10 + 0xc);
        puStack_6a = *(uint **)(iStack_10 + 0x10);
        puVar12 = *(uint **)(iStack_10 + 0x14);
        iStack_10 = iVar5;
        if (puStack_30 == (uint *)0x0) {
          if ((uVar1 & 0x80) == 0) {
            ppuStack_9c = (uint **)0x4086a2c;
            ppuStack_98 = (uint **)puVar6;
            puStack_30 = (uint *)_snd_dspcmd_def_high_water();
          }
          else {
            ppuStack_9c = (uint **)0x4086a22;
            ppuStack_98 = (uint **)uVar15;
            puStack_30 = (uint *)_snd_device_def_high_water();
          }
        }
        if (puStack_6a == (uint *)0x0) {
          if ((uVar1 & 0x80) == 0) {
            ppuStack_9c = (uint **)0x4086a50;
            ppuStack_98 = (uint **)puVar6;
            puStack_6a = (uint *)_snd_dspcmd_def_low_water();
          }
          else {
            ppuStack_9c = (uint **)0x4086a46;
            ppuStack_98 = (uint **)uVar15;
            puStack_6a = (uint *)_snd_device_def_low_water();
          }
        }
        if (puVar12 == (uint *)0x0) {
          if ((uVar1 & 0x80) == 0) {
            ppuStack_9c = (uint **)0x4086a72;
            ppuStack_98 = (uint **)puVar6;
            puVar12 = (uint *)_snd_dspcmd_def_dmasize();
          }
          else {
            ppuStack_9c = (uint **)0x4086a68;
            ppuStack_98 = (uint **)uVar15;
            puVar12 = (uint *)_snd_device_def_dmasize();
          }
          if (puVar12 != (uint *)0x0) goto loc_4086A78;
loc_4086AC0:
          iVar16 = 0x67;
        }
        else {
loc_4086A78:
          if (((uint)_page_size % (uint)puVar12 != 0) || (_page_size < puVar12)) goto loc_4086AC0;
          if ((uVar1 & 0x80) == 0) {
            uVar11 = (uint)*(word *)((&unk_40C6DF4)[(int)puVar6] + 0x4e);
            bVar4 = *(byte *)((&unk_40C6DF4)[(int)puVar6] + 0x53);
            if (bVar4 == 5) {
              puVar14 = (uint *)(uVar11 * 2);
            }
            else {
              puVar14 = (uint *)(uVar11 * bVar4);
            }
            if (puVar14 != puVar12) goto loc_4086AC0;
          }
        }
        if (!bVar7) {
          ppuStack_98 = &puStack_18;
          ppuStack_9c = &puStack_14;
          puStack_a0 = __NXAudioSndoutDevice;
          if (uVar15 == 1) {
            puStack_a0 = __NXAudioSndinDevice;
          }
          puStack_a4 = (uint *)0x4086af2;
          (*___NXAudioGetBufferOptions)();
          puStack_a4 = puStack_18;
          puStack_a8 = puVar12;
joined_r0x04086b6e:
          puVar14 = __NXAudioSndoutDevice;
          if (uVar15 == 1) {
            puVar14 = __NXAudioSndinDevice;
          }
          puStack_ac = (uint *)0x0;
          (*___NXAudioSetBufferOptions)(puVar14);
        }
        break;
      case :
        iVar9 = iVar9 + -0x10;
        uStack_44 = *(uint *)(iStack_10 + 0xc) | uStack_44;
        iStack_10 = iStack_10 + 0x10;
        break;
      case :
        iVar5 = iStack_10 + 0x10;
        iVar9 = iVar9 + -0x10;
        if (!bVar7) {
          puVar14 = *(uint **)(iStack_10 + 0xc);
          if (puVar14 == (uint *)0x0) {
            puVar14 = (uint *)0x4;
          }
          ppuStack_98 = &puStack_20;
          ppuStack_9c = &puStack_1c;
          puStack_a0 = __NXAudioSndoutDevice;
          if (uVar15 == 1) {
            puStack_a0 = __NXAudioSndinDevice;
          }
          puStack_a4 = (uint *)0x4086b62;
          iStack_10 = iVar5;
          (*___NXAudioGetBufferOptions)();
          puStack_a4 = puVar14;
          puStack_a8 = puStack_1c;
          goto joined_r0x04086b6e;
        }
        if (*(int *)(iStack_10 + 0xc) == 0) {
          *(undefined4 *)(iStack_4c + 0x2e) = 4;
          iStack_10 = iVar5;
        }
        else {
          *(int *)(iStack_4c + 0x2e) = *(int *)(iStack_10 + 0xc);
          iStack_10 = iVar5;
        }
        break;
      case :
        iVar9 = iVar9 + -0x18;
        puStack_54 = *(uint **)(iStack_10 + 0xc);
        puStack_58 = *(uint **)(iStack_10 + 0x10);
        puStack_5c = *(uint **)(iStack_10 + 0x14);
        bVar8 = true;
        iStack_10 = iStack_10 + 0x18;
        break;
      :
        iVar16 = 0x66;
        iVar9 = 0;
      }
    } while (0 < iVar9);
  }
  if (iVar16 != 0) goto loc_4086BA0;
  if (((bVar7) && (uVar13 == 0)) && (puVar12 != (uint *)0x0)) {
    *(uint **)(iStack_4c + 0x2a) = puVar12;
    *(uint **)(iStack_4c + 0x32) = puStack_30;
    *(uint **)(iStack_4c + 0x36) = puStack_6a;
  }
  uStack_24 = 0;
  uStack_28 = 0;
  if ((uStack_44 & 2) != 0) {
    if (bVar7) {
      ppuStack_98 = (uint **)0x4086c82;
      _snd_link_abort();
      ppuStack_9c = (uint **)iStack_4c;
      puStack_a0 = (uint *)0x4086c90;
      ppuStack_98 = (uint **)puVar2;
      _snd_stream_abort();
    }
    else {
      ppuStack_98 = (uint **)0x0;
      ppuStack_9c = (uint **)0x0;
      puStack_a0 = (uint *)0x2;
      puStack_a4 = puStack_3c;
      puStack_a8 = (uint *)0x4086cac;
      (*___NXAudioStreamControl)();
    }
  }
  if ((uStack_44 & 1) == 0) {
loc_4086CFE:
    if ((uStack_44 & 4) != 0) {
      if (bVar7) {
        ppuStack_98 = (uint **)iStack_4c;
        ppuStack_9c = (uint **)0x4086d16;
        _snd_stream_pause();
      }
      else {
        ppuStack_98 = (uint **)uStack_24;
        ppuStack_9c = (uint **)uStack_28;
        puStack_a0 = (uint *)0x0;
        puStack_a4 = puStack_3c;
        puStack_a8 = (uint *)0x4086d30;
        (*___NXAudioStreamControl)();
      }
    }
    iVar16 = *(int *)(param_1 + 4) + -0x28;
    iStack_10 = param_1 + 0x28;
    while (iVar9 = iStack_10, 0 < iVar16) {
      puVar14 = (uint *)0x0;
      switch(*(undefined4 *)(iStack_10 + 4)) {
      case :
        iVar5 = iStack_10 + 0x28;
        iVar16 = iVar16 + -0x28;
        unaff_D6 = *(uint *)(iStack_10 + 0xc);
        uStack_2c = *(uint *)(iStack_10 + 0x24);
        puVar14 = *(uint **)(iStack_10 + 0x20);
        iStack_10 = iVar5;
        if (bVar7) {
          ppuStack_98 = (uint **)0x0;
          ppuStack_9c = (uint **)0x1;
          puStack_a0 = (uint *)(~_page_mask & (int)puVar14 + _page_mask + uStack_2c);
          puStack_a4 = (uint *)(~_page_mask & uStack_2c);
          puStack_a8 = dword_40C6EBC;
          puStack_ac = (uint *)0x4086dd4;
          _vm_map_protect();
        }
        uStack_50 = *(uint *)(iVar9 + 0x14);
        break;
      case :
        iVar5 = iStack_10 + 0x20;
        iVar16 = iVar16 + -0x20;
        unaff_D6 = *(uint *)(iStack_10 + 0xc);
        puVar14 = *(uint **)(iStack_10 + 0x10);
        iStack_10 = iVar5;
        if (bVar7) {
          ppuStack_98 = (uint **)0x1;
          puStack_a0 = &uStack_2c;
          puStack_a4 = dword_40C6EBC;
          puStack_a8 = (uint *)0x4086e14;
          ppuStack_9c = (uint **)puVar14;
          _vm_allocate();
        }
        uStack_50 = *(uint *)(iVar9 + 0x18);
        break;
      case :
      case :
        iStack_10 = iStack_10 + 0x18;
        iVar16 = iVar16 + -0x18;
        break;
      case :
      case :
        iStack_10 = iStack_10 + 0x10;
        iVar16 = iVar16 + -0x10;
      }
      if (puVar14 != (uint *)0x0) {
        if (bVar7) {
          ppuStack_98 = (uint **)0x3e;
          ppuStack_9c = (uint **)0x4086e50;
          puStack_a4 = (uint *)_kalloc();
          *puStack_a4 = uStack_2c;
          puStack_a4[1] = (uint)puVar14;
          puStack_a4[6] = uStack_50;
          *(uint **)((int)puStack_a4 + 0x2e) = puVar2;
          *(byte *)(puStack_a4 + 0xb) =
               *(byte *)(puStack_a4 + 0xb) & 0x7f | (byte)(((unaff_D6 & 3) >> 1) << 7);
          *(byte *)(puStack_a4 + 0xb) =
               *(byte *)(puStack_a4 + 0xb) & 0xbf | (byte)((unaff_D6 & 1) << 6);
          *(byte *)(puStack_a4 + 0xb) =
               *(byte *)(puStack_a4 + 0xb) & 0xdf | (byte)(((unaff_D6 & 7) >> 2) << 5);
          *(byte *)(puStack_a4 + 0xb) =
               *(byte *)(puStack_a4 + 0xb) & 0xef | (byte)(((unaff_D6 & 0xf) >> 3) << 4);
          *(byte *)(puStack_a4 + 0xb) =
               *(byte *)(puStack_a4 + 0xb) & 0xf7 | (byte)(((unaff_D6 & 0x1f) >> 4) << 3);
          *(byte *)(puStack_a4 + 0xb) =
               *(byte *)(puStack_a4 + 0xb) & 0xfb | (byte)(((unaff_D6 & 0x3f) >> 5) << 2);
          puStack_a4[9] = (uint)puStack_30;
          puStack_a4[10] = (uint)puStack_6a;
          puStack_a4[5] = (uint)puVar12;
          *(int *)((int)puStack_a4 + 0x3a) = iStack_4c;
          *(byte *)((int)puStack_a4 + 0x2d) =
               *(byte *)((int)puStack_a4 + 0x2d) & 0xbf | (byte)((uVar15 & 1) << 6);
          *(byte *)((int)puStack_a4 + 0x2d) = *(byte *)((int)puStack_a4 + 0x2d) & 0xfe | bStack_45;
          *(word *)(puStack_a4 + 0xb) =
               *(word *)(puStack_a4 + 0xb) & 0xfe7f | (-(sword)-(uVar1 == 0x10080) & 3U) << 7;
          ppuStack_98 = (uint **)(unaff_D6 & 0x40);
          ppuStack_9c = (uint **)(uVar1 & 0x80);
          puStack_a8 = (uint *)0x4086f30;
          puStack_a0 = puVar6;
          _snd_stream_enqueue_region();
        }
        else {
          uVar13 = (uint)((unaff_D6 & 1) != 0);
          if ((unaff_D6 & 2) != 0) {
            uVar13 = uVar13 | 2;
          }
          if ((unaff_D6 & 8) != 0) {
            uVar13 = uVar13 | 4;
          }
          if ((unaff_D6 & 0x10) != 0) {
            uVar13 = uVar13 | 8;
          }
          if ((unaff_D6 & 4) != 0) {
            uVar13 = uVar13 | 0x10;
          }
          if ((unaff_D6 & 0x20) != 0) {
            uVar13 = uVar13 | 0x20;
          }
          ppuStack_98 = (uint **)uVar13;
          if (uVar15 == 0) {
            if (bVar8) {
              ppuStack_98 = (uint **)puStack_30;
              ppuStack_9c = (uint **)puStack_6a;
              puStack_a0 = puStack_5c;
              puStack_a4 = puStack_58;
              puStack_a8 = puStack_54;
              puStack_ac = puStack_3c;
              sub_40865FC(0);
              (*___NXAudioPlayStreamData)(puStack_3c,uStack_2c,puVar14,puVar2,uStack_50,uVar13);
            }
            else {
              uVar10 = 1;
              if (uVar1 == 0x10080) {
                uVar10 = 2;
              }
              ppuStack_9c = (uint **)uStack_50;
              puStack_a0 = puStack_30;
              puStack_a4 = puStack_6a;
              puStack_a8 = (uint *)0x8000;
              puStack_ac = (uint *)0x8000;
              (*___NXAudioPlayStream)(puStack_3c,uStack_2c,puVar14,puVar2,2,uVar10);
            }
          }
          else if (bVar8) {
            ppuStack_98 = (uint **)puStack_30;
            ppuStack_9c = (uint **)puStack_6a;
            puStack_a0 = puStack_5c;
            puStack_a4 = puStack_58;
            puStack_a8 = puStack_54;
            puStack_ac = puStack_3c;
            sub_40865FC(uVar15);
            (*___NXAudioRecordStreamData)(puStack_3c,puVar14,puVar2,uStack_50,uVar13);
          }
          else {
            ppuStack_9c = (uint **)uStack_50;
            puStack_a0 = puStack_30;
            puStack_a4 = puStack_6a;
            puStack_ac = puVar14;
            puStack_a8 = puVar2;
            (*___NXAudioRecordStream)(puStack_3c);
          }
        }
      }
    }
    if ((uStack_44 & 8) != 0) {
      if (bVar7) {
        ppuStack_98 = (uint **)iStack_4c;
        ppuStack_9c = (uint **)0x4087094;
        _snd_stream_resume();
      }
      else {
        ppuStack_98 = (uint **)uStack_24;
        ppuStack_9c = (uint **)uStack_28;
        puStack_a0 = (uint *)0x1;
        puStack_a4 = puStack_3c;
        puStack_a8 = (uint *)0x40870ae;
        (*___NXAudioStreamControl)();
      }
    }
    iVar16 = 100;
  }
  else {
    if (bVar7) {
      ppuStack_9c = (uint **)iStack_4c;
      puStack_a0 = (uint *)0x4086cf4;
      ppuStack_98 = (uint **)puVar2;
      iVar16 = _snd_stream_await();
      if (iVar16 == 0) goto loc_4086CFE;
    }
    else {
      ppuStack_98 = (uint **)uStack_24;
      ppuStack_9c = (uint **)uStack_28;
      puStack_a0 = (uint *)0x3;
      puStack_a4 = puStack_3c;
      puStack_a8 = (uint *)0x4086cd6;
      iVar16 = (*___NXAudioStreamControl)();
      if (iVar16 == 0) goto loc_4086CFE;
      iVar16 = 0x6c;
    }
loc_4086BA0:
    iVar9 = *(int *)(param_1 + 4) + -0x28;
    iStack_10 = param_1 + 0x28;
    while (0 < iVar9) {
      switch(*(undefined4 *)(iStack_10 + 4)) {
      case :
        iVar9 = iVar9 + -0x28;
        ppuStack_98 = *(uint ***)(iStack_10 + 0x20);
        ppuStack_9c = *(uint ***)(iStack_10 + 0x24);
        puStack_a0 = dword_40C6EBC;
        puStack_a4 = (uint *)0x4086c12;
        iStack_10 = iStack_10 + 0x28;
        _vm_deallocate();
        break;
      case :
        iStack_10 = iStack_10 + 0x20;
        iVar9 = iVar9 + -0x20;
        break;
      case :
      case :
        iStack_10 = iStack_10 + 0x18;
        iVar9 = iVar9 + -0x18;
        break;
      case :
      case :
        iStack_10 = iStack_10 + 0x10;
        iVar9 = iVar9 + -0x10;
      }
    }
  }
  return iVar16;
}
