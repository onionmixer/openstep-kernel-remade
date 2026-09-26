/* GHIDRADEC_FUNCTION index=3100 start=0x40826e6 */

undefined4 sub_40826E6(int param_1)

{
  word wVar1;
  uint in_D0;
  uint uVar2;
  char cVar3;
  bool bVar4;
  bool bVar5;
  
  wVar1 = _dma_chip;
  uVar2 = in_D0 & 0xffff0000;
  if (param_1 == 0) {
    if (_dma_chip == 0x139) {
      uVar2 = *_scr2 | 0x40;
      *_scr2 = uVar2;
    }
    bVar4 = _bmap_chip < 0;
    bVar5 = true;
    if (_bmap_chip == 0) goto loc_4082756;
    uVar2 = CONCAT31((int3)(uVar2 >> 8),*(undefined *)(_bmap_chip + 0xc)) | 0x20;
  }
  else {
    if (_dma_chip == 0x139) {
      uVar2 = *_scr2 & 0xffffffbf;
      *_scr2 = uVar2;
    }
    bVar4 = _bmap_chip < 0;
    bVar5 = true;
    if (_bmap_chip == 0) goto loc_4082756;
    uVar2 = CONCAT31((int3)(uVar2 >> 8),*(undefined *)(_bmap_chip + 0xc)) & 0xffffffdf;
  }
  cVar3 = (char)uVar2;
  *(char *)(_bmap_chip + 0xc) = cVar3;
  bVar4 = cVar3 < '\0';
  bVar5 = cVar3 == '\0';
loc_4082756:
  return CONCAT22((sword)(uVar2 >> 0x10),
                  (word)(byte)((wVar1 < 0x139) << 4 | bVar4 << 3 | bVar5 << 2));
}
/* GHIDRADEC_FUNCTION index=3101 start=0x408288e */

undefined4 * sub_408288E(undefined4 param_1)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  
  puVar2 = dword_40B5090;
  puVar1 = (undefined4 *)dword_40B5090[6];
  if ((undefined4 **)puVar1 == &dword_40B5090) {
    dword_40B5094 = &dword_40B5090;
  }
  else {
    puVar1[7] = &dword_40B5090;
  }
  *dword_40B5090 = 7;
  dword_40B5090 = puVar1;
  puVar2[1] = param_1;
  *(undefined *)(puVar2 + 8) = 0;
  *(undefined *)(puVar2 + 9) = 1;
  *(undefined *)((int)puVar2 + 0x23) = 0;
  *(undefined *)((int)puVar2 + 0x22) = 1;
  return puVar2;
}
/* GHIDRADEC_FUNCTION index=3102 start=0x40828de */

undefined4 * sub_40828DE(void)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  
  puVar2 = dword_40B5090;
  puVar1 = (undefined4 *)dword_40B5090[6];
  if ((undefined4 **)puVar1 == &dword_40B5090) {
    dword_40B5094 = &dword_40B5090;
  }
  else {
    puVar1[7] = &dword_40B5090;
  }
  *dword_40B5090 = 4;
  dword_40B5090 = puVar1;
  puVar2[1] = (int)puVar2 + 0x26;
  puVar2[3] = (int)puVar2 + 0x26;
  *(undefined *)(puVar2 + 8) = 0;
  *(undefined *)(puVar2 + 9) = 1;
  *(undefined *)((int)puVar2 + 0x23) = 1;
  *(undefined *)((int)puVar2 + 0x22) = 1;
  return puVar2;
}
/* GHIDRADEC_FUNCTION index=3103 start=0x4082936 */

undefined4 * sub_4082936(undefined4 param_1,undefined4 param_2)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  
  puVar2 = dword_40B5090;
  puVar1 = (undefined4 *)dword_40B5090[6];
  if ((undefined4 **)puVar1 == &dword_40B5090) {
    dword_40B5094 = &dword_40B5090;
  }
  else {
    puVar1[7] = &dword_40B5090;
  }
  *dword_40B5090 = 0;
  dword_40B5090 = puVar1;
  puVar2[1] = param_1;
  puVar2[2] = param_2;
  puVar2[3] = 0;
  *(undefined *)(puVar2 + 8) = 0;
  *(undefined *)(puVar2 + 9) = 1;
  *(undefined *)((int)puVar2 + 0x23) = 0;
  *(undefined *)((int)puVar2 + 0x22) = 1;
  return puVar2;
}
/* GHIDRADEC_FUNCTION index=3104 start=0x408298e */

undefined4 * sub_408298E(undefined4 param_1,undefined4 param_2)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  
  puVar2 = dword_40B5090;
  puVar1 = (undefined4 *)dword_40B5090[6];
  if ((undefined4 **)puVar1 == &dword_40B5090) {
    dword_40B5094 = &dword_40B5090;
  }
  else {
    puVar1[7] = &dword_40B5090;
  }
  *dword_40B5090 = 8;
  dword_40B5090 = puVar1;
  puVar2[1] = param_1;
  puVar2[2] = param_2;
  *(undefined *)(puVar2 + 8) = 0;
  *(undefined *)(puVar2 + 9) = 1;
  *(undefined *)((int)puVar2 + 0x23) = 0;
  *(undefined *)((int)puVar2 + 0x22) = 1;
  return puVar2;
}
/* GHIDRADEC_FUNCTION index=3105 start=0x4083a7a */

undefined4 sub_4083A7A(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 uStack_8;
  
  if (dword_40C6EB8 == *(int *)(_active_threads + 0xc)) {
    uStack_8 = *(undefined4 *)(param_1 + 0x10);
  }
  else {
    iVar1 = _object_copyin(dword_40C6EB8,*(undefined4 *)(param_1 + 0x10),6,0,&uStack_8);
    if (iVar1 == 0) {
      return 5;
    }
  }
  uVar2 = _snd_reply_recorded_data
                    (uStack_8,0,*(undefined4 *)(param_1 + 4),*(undefined4 *)(param_1 + 8),1);
  _dspq_free_msg(param_1);
  return uVar2;
}
/* GHIDRADEC_FUNCTION index=3106 start=0x4083cca */

void sub_4083CCA(int param_1)

{
  _object_copyin(dword_40C6EB8,*(undefined4 *)(*(int *)(param_1 + 4) + 0x10),6,0,
                 *(int *)(param_1 + 4) + 0x10);
  _msg_send_from_kernel(*(undefined4 *)(param_1 + 4),0,0);
  _port_release(*(undefined4 *)(*(int *)(param_1 + 4) + 0x10));
  _dspq_free_msg(param_1);
  return;
}
/* GHIDRADEC_FUNCTION index=3107 start=0x4084026 */

int sub_4084026(int param_1)

{
  int *piVar1;
  int *piVar2;
  byte bVar3;
  byte bVar4;
  int *piVar5;
  int iVar6;
  undefined2 uVar7;
  undefined2 extraout_D0u;
  undefined2 extraout_D0u_00;
  int iVar8;
  byte *pbVar9;
  int iVar10;
  int iVar11;
  word wVar12;
  int iVar13;
  sword sVar14;
  byte *pbVar15;
  byte *pbVar16;
  word *pwVar17;
  word *pwVar18;
  bool bVar19;
  
  piVar5 = (int *)(param_1 + 0x3e);
  iVar8 = _curipl();
  iVar6 = dword_40B21CC;
  if (iVar8 != dword_40B21CC) {
    dword_40B21CC = _curipl();
    uVar7 = (undefined2)((uint)dword_40B21CC >> 0x10);
    if (*(char *)(param_1 + 0x53) == '\x01') {
      piVar1 = (int *)*piVar5;
      while (bVar19 = piVar5 < piVar1, piVar5 != piVar1) {
        iVar8 = *piVar5;
        pbVar9 = *(byte **)(iVar8 + 0x10);
        if (*(byte **)(iVar8 + 0x14) == pbVar9) {
          piVar1 = *(int **)(iVar8 + 0x2c);
          piVar2 = *(int **)(iVar8 + 0x30);
          if (piVar1 == piVar5) {
            *(int **)(param_1 + 0x42) = piVar2;
          }
          else {
            piVar1[0xc] = (int)piVar2;
          }
          if (piVar2 == piVar5) {
            *piVar5 = (int)piVar1;
          }
          else {
            piVar2[0xb] = (int)piVar1;
          }
          *(int *)(param_1 + 0x26) = *(int *)(iVar8 + 4) + *(int *)(param_1 + 0x26);
          if (piVar5 == (int *)*piVar5) {
            *(uint *)(iVar8 + 0x34) = *(uint *)(iVar8 + 0x34) | 1;
          }
          (**(code **)(iVar8 + 0x28))(iVar8);
          uVar7 = extraout_D0u;
        }
        else {
          iVar13 = (int)*(byte **)(iVar8 + 0x14) - (int)pbVar9;
          if (0x100 < iVar13) {
            iVar13 = 0x100;
          }
          iVar13 = iVar13 + -1;
          pbVar16 = pbVar9;
          if (iVar13 != -1) {
            do {
              pbVar15 = pbVar16 + 1;
              bVar3 = *pbVar16;
              iVar10 = 0x32;
              bVar4 = *(byte *)(_slot_id_bmap + 0x2008002);
              pbVar9 = (byte *)CONCAT31((int3)((uint)pbVar9 >> 8),bVar4);
              while ((bVar4 & 2) == 0) {
                pbVar9 = (byte *)_delay(2);
                iVar10 = iVar10 + -1;
                if (iVar10 == 0) goto loc_4084176;
                bVar4 = *(byte *)(_slot_id_bmap + 0x2008002);
                pbVar9 = (byte *)CONCAT31((int3)((uint)pbVar9 >> 8),bVar4);
              }
              if (iVar10 != 0) {
                if (_cpu_type == '\0') {
                  *(uint *)(_slot_id_bmap + 0x2008004) = (uint)bVar3;
                }
                else {
                  *(undefined *)(_slot_id_bmap + 0x2008005) = 0;
                  pbVar9 = (byte *)0x0;
                  *(undefined *)(_slot_id_bmap + 0x2008006) = 0;
                  *(byte *)(_slot_id_bmap + 0x2008007) = bVar3;
                }
              }
loc_4084176:
              if (iVar10 == 0) break;
              wVar12 = (word)((uint)iVar13 >> 0x10);
              sVar14 = (sword)iVar13 + -1;
              iVar13 = CONCAT22(wVar12,sVar14);
              pbVar16 = pbVar15;
            } while ((sVar14 != -1) || (iVar13 = (uint)wVar12 * 0x10000 + -1, wVar12 != 0));
          }
          uVar7 = (undefined2)((uint)pbVar9 >> 0x10);
          bVar19 = pbVar16 < *(byte **)(iVar8 + 0x10);
          if (pbVar16 == *(byte **)(iVar8 + 0x10)) break;
          *(byte **)(iVar8 + 0x10) = pbVar16;
        }
        piVar1 = (int *)*piVar5;
      }
    }
    else {
      piVar1 = (int *)*piVar5;
      while (bVar19 = piVar5 < piVar1, piVar5 != piVar1) {
        iVar8 = *piVar5;
        pwVar18 = *(word **)(iVar8 + 0x10);
        if (*(word **)(iVar8 + 0x14) == pwVar18) {
          piVar1 = *(int **)(iVar8 + 0x2c);
          piVar2 = *(int **)(iVar8 + 0x30);
          if (piVar1 == piVar5) {
            *(int **)(param_1 + 0x42) = piVar2;
          }
          else {
            piVar1[0xc] = (int)piVar2;
          }
          if (piVar2 == piVar5) {
            *piVar5 = (int)piVar1;
          }
          else {
            piVar2[0xb] = (int)piVar1;
          }
          *(int *)(param_1 + 0x26) = *(int *)(iVar8 + 4) + *(int *)(param_1 + 0x26);
          if (piVar5 == (int *)*piVar5) {
            *(uint *)(iVar8 + 0x34) = *(uint *)(iVar8 + 0x34) | 1;
          }
          (**(code **)(iVar8 + 0x28))(iVar8);
          uVar7 = extraout_D0u_00;
        }
        else {
          iVar13 = (int)*(word **)(iVar8 + 0x14) - (int)pwVar18;
          iVar10 = iVar13 >> 1;
          if (0x40 < iVar10) {
            iVar10 = 0x40;
          }
          iVar10 = iVar10 + -1;
          if (iVar10 != -1) {
            do {
              pwVar17 = pwVar18 + 1;
              wVar12 = *pwVar18;
              iVar11 = 0x32;
              bVar3 = *(byte *)(_slot_id_bmap + 0x2008002);
              iVar13 = CONCAT31((int3)((uint)iVar13 >> 8),bVar3);
              while ((bVar3 & 2) == 0) {
                iVar13 = _delay(2);
                iVar11 = iVar11 + -1;
                if (iVar11 == 0) goto loc_40842B2;
                bVar3 = *(byte *)(_slot_id_bmap + 0x2008002);
                iVar13 = CONCAT31((int3)((uint)iVar13 >> 8),bVar3);
              }
              if (iVar11 != 0) {
                if (_cpu_type == '\0') {
                  *(uint *)(_slot_id_bmap + 0x2008004) = (uint)wVar12;
                }
                else {
                  *(undefined *)(_slot_id_bmap + 0x2008005) = 0;
                  iVar13 = 0;
                  *(char *)(_slot_id_bmap + 0x2008006) = (char)(wVar12 >> 8);
                  *(char *)(_slot_id_bmap + 0x2008007) = (char)wVar12;
                }
              }
loc_40842B2:
              if (iVar11 == 0) break;
              wVar12 = (word)((uint)iVar10 >> 0x10);
              sVar14 = (sword)iVar10 + -1;
              iVar10 = CONCAT22(wVar12,sVar14);
              pwVar18 = pwVar17;
            } while ((sVar14 != -1) || (iVar10 = (uint)wVar12 * 0x10000 + -1, wVar12 != 0));
          }
          uVar7 = (undefined2)((uint)iVar13 >> 0x10);
          bVar19 = pwVar18 < *(word **)(iVar8 + 0x10);
          if (pwVar18 == *(word **)(iVar8 + 0x10)) break;
          *(word **)(iVar8 + 0x10) = pwVar18;
        }
        piVar1 = (int *)*piVar5;
      }
    }
    iVar8 = CONCAT22(uVar7,(word)(byte)(bVar19 << 4 | (iVar6 < 0) << 3 | (iVar6 == 0) << 2));
  }
  dword_40B21CC = iVar6;
  return iVar8;
}
/* GHIDRADEC_FUNCTION index=3108 start=0x408462a */

void sub_408462A(uint *param_1,uint param_2,int param_3,uint param_4,uint param_5,uint param_6,
                undefined4 *param_7)

{
  undefined4 *puVar1;
  uint uVar2;
  undefined4 uVar3;
  int iVar4;
  word wVar5;
  sword sVar6;
  
  uVar3 = _pmap_kernel();
  param_3 = param_3 + -1;
  if (param_3 != -1) {
    do {
      *param_1 = param_2;
      param_1[1] = param_4;
      param_1[2] = param_6;
      param_1[10] = param_5;
      iVar4 = _pmap_resident_extract(uVar3,param_2 & ~_page_mask);
      uVar2 = param_2 % _page_size + iVar4;
      param_1[4] = uVar2;
      param_1[5] = param_4 + uVar2;
      param_1[9] = (uint)param_1;
      puVar1 = (undefined4 *)param_7[1];
      if (puVar1 == param_7) {
        *param_7 = param_1;
      }
      else {
        puVar1[0xb] = param_1;
      }
      param_1[0xc] = (uint)puVar1;
      param_1[0xb] = (uint)param_7;
      param_7[1] = param_1;
      param_1 = param_1 + 0xe;
      param_2 = param_4 + param_2;
      wVar5 = (word)((uint)param_3 >> 0x10);
      sVar6 = (sword)param_3 + -1;
      param_3 = CONCAT22(wVar5,sVar6);
    } while ((sVar6 != -1) || (param_3 = (uint)wVar5 * 0x10000 + -1, wVar5 != 0));
  }
  return;
}
/* GHIDRADEC_FUNCTION index=3109 start=0x40846d2 */

void sub_40846D2(int param_1)

{
  int iVar1;
  undefined4 *puVar2;
  int iVar3;
  byte *pbVar4;
  int iVar5;
  undefined4 *puVar6;
  int *piVar7;
  
  piVar7 = &dword_40C6DFC;
  if (param_1 == 0) {
    piVar7 = &dword_40C6DF8;
  }
  iVar1 = *piVar7;
  iVar5 = 0;
  puVar2 = (undefined4 *)(&unk_40B50B0)[param_1 * 2];
  puVar6 = puVar2;
  for (; puVar2 != &unk_40B50B0 + param_1 * 2; puVar2 = (undefined4 *)puVar2[0xb]) {
    if (puVar2 < puVar6) {
      puVar6 = puVar2;
    }
    iVar5 = iVar5 + 1;
  }
  if ((iVar5 != 0) && (iVar5 == *(int *)((int)&unk_40B517C + param_1 * 4))) {
    _kfree(puVar6,iVar5 * 0x38);
    (&dword_40B50B4)[param_1 * 2] = &unk_40B50B0 + param_1 * 2;
    (&unk_40B50B0)[param_1 * 2] = &unk_40B50B0 + param_1 * 2;
    *(undefined4 *)((int)&unk_40B517C + param_1 * 4) = 0;
  }
  iVar5 = 0;
  puVar2 = (undefined4 *)(&unk_40B50A0)[param_1 * 2];
  puVar6 = puVar2;
  for (; puVar2 != &unk_40B50A0 + param_1 * 2; puVar2 = (undefined4 *)puVar2[0xb]) {
    if (puVar2 < puVar6) {
      puVar6 = puVar2;
    }
    iVar5 = iVar5 + 1;
  }
  if ((iVar5 != 0) && (iVar5 == *(int *)((int)&unk_40B5174 + param_1 * 4))) {
    _kfree(puVar6,iVar5 * 0x38);
    (&dword_40B50A4)[param_1 * 2] = &unk_40B50A0 + param_1 * 2;
    (&unk_40B50A0)[param_1 * 2] = &unk_40B50A0 + param_1 * 2;
    *(undefined4 *)((int)&unk_40B5174 + param_1 * 4) = 0;
  }
  if ((((*(int *)((int)&unk_40B5174 + param_1 * 4) == 0) &&
       (*(int *)((int)&unk_40B517C + param_1 * 4) == 0)) &&
      (iVar5 = *(int *)((int)&unk_40B5164 + param_1 * 4), iVar5 != 0)) &&
     (iVar3 = *(int *)((int)&unk_40B516C + param_1 * 4), iVar3 != 0)) {
    _kfree(iVar5,~_page_mask & _page_mask + iVar3);
    *(undefined4 *)((int)&unk_40B5164 + param_1 * 4) = 0;
    *(undefined4 *)((int)&unk_40B516C + param_1 * 4) = 0;
    if (iVar1 != 0) {
      pbVar4 = (byte *)(iVar1 + 0x24);
      *pbVar4 = *pbVar4 & 0xf7;
    }
  }
  return;
}
/* GHIDRADEC_FUNCTION index=3110 start=0x4084afe */

undefined4 sub_4084AFE(int param_1)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  undefined4 uVar3;
  int iVar4;
  int iVar5;
  uint uVar6;
  undefined4 *puVar7;
  
  uVar6 = (uint)(*(undefined **)(param_1 + 8) != unk_40B50E0);
  puVar2 = (undefined4 *)(&dword_40B50B4)[uVar6 * 2];
  if (puVar2 == &unk_40B50B0 + uVar6 * 2) {
    (&unk_40B50B0)[uVar6 * 2] = param_1;
  }
  else {
    puVar2[0xb] = param_1;
  }
  *(undefined4 **)(param_1 + 0x30) = puVar2;
  *(undefined4 **)(param_1 + 0x2c) = &unk_40B50B0 + uVar6 * 2;
  (&dword_40B50B4)[uVar6 * 2] = param_1;
  if (((uVar6 == 0) && ((dword_40C6E84 & 0x10) == 0)) ||
     ((uVar6 == 1 && ((dword_40C6E84 & 0x20) == 0)))) {
    _callout_dispatch(4,sub_40846D2,uVar6);
    uVar3 = 0;
  }
  else {
    puVar2 = &unk_40B50A0 + uVar6 * 2;
    puVar7 = (undefined4 *)(&unk_40B50A0)[uVar6 * 2];
    if (puVar7 == puVar2) {
      uVar3 = 0;
    }
    else {
      if ((uint)puVar7[1] < *(uint *)(param_1 + 4)) {
        do {
          iVar5 = (&unk_40B50A0)[uVar6 * 2];
          puVar7 = *(undefined4 **)(iVar5 + 0x2c);
          if (puVar7 == puVar2) {
            (&dword_40B50A4)[uVar6 * 2] = puVar2;
          }
          else {
            puVar7[0xc] = puVar2;
          }
          (&unk_40B50A0)[uVar6 * 2] = puVar7;
          if ((*(uint *)(iVar5 + 0x10) < *(uint *)(param_1 + 0x10)) ||
             (*(uint *)(param_1 + 0x14) < *(uint *)(iVar5 + 0x14))) {
            if (puVar7 != puVar2) goto loc_4084C6C;
loc_4084C66:
            (&dword_40B50A4)[uVar6 * 2] = iVar5;
loc_4084C70:
            *(undefined4 **)(iVar5 + 0x2c) = puVar7;
            *(undefined4 **)(iVar5 + 0x30) = &unk_40B50A0 + uVar6 * 2;
            (&unk_40B50A0)[uVar6 * 2] = iVar5;
            break;
          }
          uVar3 = 1;
          if ((dword_40C6E84 & 0x4000) != 0) {
            uVar3 = 2;
          }
          iVar4 = (*___NXAudioPlayStream)
                            (dword_40B21D0,*(int *)(iVar5 + 0x10),
                             *(int *)(iVar5 + 0x14) - *(int *)(iVar5 + 0x10),iVar5,2,uVar3,0x8000,
                             0x8000,0,0,0,0);
          if (iVar4 != 0) {
            puVar7 = (undefined4 *)(&unk_40B50A0)[uVar6 * 2];
            if (puVar7 == puVar2) goto loc_4084C66;
loc_4084C6C:
            puVar7[0xc] = iVar5;
            goto loc_4084C70;
          }
        } while (puVar2 != (undefined4 *)(&unk_40B50A0)[uVar6 * 2]);
      }
      else {
        puVar1 = (undefined4 *)puVar7[0xb];
        if (puVar1 == puVar2) {
          (&dword_40B50A4)[uVar6 * 2] = puVar1;
        }
        else {
          puVar1[0xc] = puVar2;
        }
        (&unk_40B50A0)[uVar6 * 2] = puVar1;
        if (puVar7[5] == *(int *)(param_1 + 0x14)) {
          uVar3 = 1;
          if ((dword_40C6E84 & 0x4000) != 0) {
            uVar3 = 2;
          }
          iVar5 = (*___NXAudioPlayStream)
                            (dword_40B21D0,puVar7[4],puVar7[5] - puVar7[4],puVar7,2,uVar3,0x8000,
                             0x8000,0,0,0,0);
          if (iVar5 != 0) {
            puVar2 = (undefined4 *)(&unk_40B50A0)[uVar6 * 2];
            if (puVar2 == &unk_40B50A0 + uVar6 * 2) {
              (&dword_40B50A4)[uVar6 * 2] = puVar7;
            }
            else {
              puVar2[0xc] = puVar7;
            }
            puVar7[0xb] = puVar2;
            puVar7[0xc] = &unk_40B50A0 + uVar6 * 2;
            (&unk_40B50A0)[uVar6 * 2] = puVar7;
          }
        }
        else {
          if (puVar1 == &unk_40B50A0 + uVar6 * 2) {
            (&dword_40B50A4)[uVar6 * 2] = puVar7;
          }
          else {
            puVar1[0xc] = puVar7;
          }
          puVar7[0xb] = puVar1;
          puVar7[0xc] = &unk_40B50A0 + uVar6 * 2;
          (&unk_40B50A0)[uVar6 * 2] = puVar7;
        }
      }
      uVar3 = 1;
    }
  }
  return uVar3;
}
/* GHIDRADEC_FUNCTION index=3111 start=0x408510e */

void sub_408510E(undefined4 param_1,undefined4 param_2,undefined4 param_3)

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
  uStack_10 = param_3;
  uStack_20 = 0x20;
  uStack_14 = param_1;
  uStack_c = dword_40B21FC;
  uStack_8 = param_2;
  _msg_send(&uStack_24,0x21,0);
  return;
}
/* GHIDRADEC_FUNCTION index=3112 start=0x4085946 */

void sub_4085946(int param_1)

{
  int iVar1;
  int iStack_8;
  
  iVar1 = _port_allocate(dword_40C6EC0,&iStack_8);
  if (iVar1 != 0) {
                    /* WARNING: Subroutine does not return */
    _panic(aSoundCanTAlloc);
  }
  if (param_1 != iStack_8) {
    iVar1 = _port_rename(dword_40C6EC0,iStack_8,param_1);
    if (iVar1 != 0) {
                    /* WARNING: Subroutine does not return */
      _panic(aSoundCanTRenam);
    }
  }
  iVar1 = _port_set_add(dword_40C6EC0,dword_40C6EA8,param_1);
  if (iVar1 != 0) {
                    /* WARNING: Subroutine does not return */
    _panic(aSoundCanTAddPo);
  }
  return;
}
/* GHIDRADEC_FUNCTION index=3113 start=0x4085c76 */

void sub_4085C76(int *param_1,undefined4 param_2)

{
  int *piVar1;
  undefined4 *puVar2;
  
  puVar2 = (undefined4 *)_kalloc(0x10);
  *puVar2 = param_2;
  puVar2[1] = 0;
  piVar1 = (int *)param_1[1];
  if (piVar1 == param_1) {
    *param_1 = (int)puVar2;
  }
  else {
    piVar1[2] = (int)puVar2;
  }
  puVar2[3] = piVar1;
  puVar2[2] = param_1;
  param_1[1] = (int)puVar2;
  return;
}
/* GHIDRADEC_FUNCTION index=3114 start=0x4085cea */

void sub_4085CEA(int *param_1,int param_2)

{
  int *piVar1;
  int *piVar2;
  
  piVar1 = *(int **)(param_2 + 8);
  piVar2 = *(int **)(param_2 + 0xc);
  if (piVar1 == param_1) {
    piVar1[1] = (int)piVar2;
  }
  else {
    piVar1[3] = (int)piVar2;
  }
  if (piVar2 == param_1) {
    *piVar2 = (int)piVar1;
  }
  else {
    piVar2[2] = (int)piVar1;
  }
  _kfree(param_2,0x10);
  return;
}
/* GHIDRADEC_FUNCTION index=3115 start=0x4085d2e */

void sub_4085D2E(undefined4 param_1,uint *param_2,undefined4 param_3,undefined4 param_4,
                uint *param_5,undefined4 param_6)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  undefined *puVar4;
  undefined *puVar5;
  int iStack_40c;
  int iStack_408;
  undefined auStack_404 [1024];
  
  puVar5 = &stack0xfffffffc;
  puVar4 = &stack0xfffffffc;
  (*___NXAudioGetSamplingRates)(param_1,&iStack_408,param_3,param_4,auStack_404,&iStack_40c);
  *param_2 = 0;
  if (iStack_408 != 0) {
    *param_2 = 1;
  }
  iVar2 = 0;
  if (0 < iStack_40c) {
    do {
      iVar1 = *(int *)(puVar5 + -0x400);
      if (iVar1 - 8000U < 0xe) {
        *param_2 = *param_2 | 2;
      }
      else if (iVar1 == 0x5622) {
        *param_2 = *param_2 | 0x10;
      }
      else if (iVar1 < 0x5623) {
        if (iVar1 == 0x2b11) {
          *param_2 = *param_2 | 4;
        }
        else if (iVar1 == 16000) {
          *param_2 = *param_2 | 8;
        }
      }
      else if (iVar1 == 0xac44) {
        *param_2 = *param_2 | 0x40;
      }
      else if (iVar1 < 0xac45) {
        if (iVar1 == 32000) {
          *param_2 = *param_2 | 0x20;
        }
      }
      else if (iVar1 == 48000) {
        *(word *)((int)param_2 + 2) = *(word *)((int)param_2 + 2) | 0x80;
      }
      puVar5 = puVar5 + 4;
      iVar2 = iVar2 + 1;
    } while (iVar2 < iStack_40c);
  }
  (*___NXAudioGetDataEncodings)(param_1,auStack_404,&iStack_40c);
  *param_5 = 0;
  iVar2 = 0;
  if (0 < iStack_40c) {
    do {
      iVar1 = *(int *)(puVar4 + -0x400);
      if (iVar1 == 0x259) {
        uVar3 = 2;
loc_4085E42:
        *param_5 = uVar3 | *param_5;
      }
      else if (iVar1 < 0x25a) {
        if (iVar1 == 600) {
          uVar3 = 4;
          goto loc_4085E42;
        }
      }
      else if (iVar1 == 0x25a) {
        uVar3 = 1;
        goto loc_4085E42;
      }
      puVar4 = puVar4 + 4;
      iVar2 = iVar2 + 1;
    } while (iVar2 < iStack_40c);
  }
  (*___NXAudioGetChannelCountLimit)(param_1,param_6);
  return;
}
/* GHIDRADEC_FUNCTION index=3116 start=0x4085e66 */

/* WARNING: Type propagation algorithm not settling */

undefined4 sub_4085E66(int param_1)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  int iVar3;
  undefined4 *puVar4;
  word wVar5;
  uint ***pppuVar6;
  uint uVar7;
  sword sVar8;
  uint ****ppppuVar9;
  undefined4 ****ppppuVar10;
  undefined4 ***pppuVar11;
  undefined4 uVar12;
  uint ***pppuStack_6c;
  undefined4 ****ppppuStack_68;
  uint ***pppuStack_3c;
  uint **ppuStack_38;
  undefined4 **ppuStack_34;
  undefined4 uStack_30;
  undefined4 uStack_2c;
  undefined4 uStack_28;
  uint **ppuStack_24;
  undefined4 **ppuStack_20;
  undefined4 uStack_1c;
  undefined4 uStack_18;
  undefined4 uStack_14;
  uint **ppuStack_10;
  uint ***pppuStack_c;
  undefined4 uStack_8;
  
  puVar4 = dword_40C6E94;
  switch(*(undefined4 *)(param_1 + 0x14)) {
  case :
    if (*(int *)(param_1 + 4) != 0x28) {
      return 0x67;
    }
    uVar7 = *(uint *)(param_1 + 0x1c);
    if ((uVar7 & 0xffffff00) != 0) {
      return 0x67;
    }
    if (((uVar7 & 0x80) != 0) && (2 < (uVar7 & 0x7f))) {
      return 0x67;
    }
    if ((char)uVar7 == '\0') {
      return 0x67;
    }
    if (uVar7 == 0x82) {
      ppppuStack_68 = *(undefined4 *****)(param_1 + 0x24);
      pppuStack_6c = (uint ***)&dword_40C6E8C;
      puVar4 = (undefined4 *)_snd_get_owner();
      if (puVar4 == (undefined4 *)0x0) {
        return 0x6a;
      }
      if (puVar4[1] != 0) goto loc_4085FBC;
      uVar2 = *puVar4;
      pppuVar11 = __NXAudioSndinDevice;
    }
    else {
      if ((uVar7 & 0x80) == 0) {
        if (*(uint ****)(param_1 + 0x24) != _snd_var) {
          return 0x6a;
        }
        if ((&unk_40C6DF4)[uVar7 & 0x7f] == 0) {
          return 0x6b;
        }
        goto loc_4085FBC;
      }
      ppppuStack_68 = *(undefined4 *****)(param_1 + 0x24);
      pppuStack_6c = (uint ***)&dword_40C6E94;
      puVar4 = (undefined4 *)_snd_get_owner();
      if (puVar4 == (undefined4 *)0x0) {
        return 0x6a;
      }
      if (puVar4[1] != 0) goto loc_4085FBC;
      uVar2 = *puVar4;
      pppuVar11 = __NXAudioSndoutDevice;
    }
    ppppuStack_68 = (undefined4 ****)0x1;
    pppuStack_6c = (undefined4 ***)0x0;
    (*___NXAudioAddStream)(pppuVar11,&uStack_8,uVar2);
    uVar2 = (*___NXAudioPortToStream)(uStack_8);
    puVar4[1] = uVar2;
loc_4085FBC:
    ppppuStack_68 = (undefined4 ****)(*(uint *)(param_1 + 0x1c) | 0x10000);
    pppuStack_6c = *(uint ****)(param_1 + 0x10);
    _snd_reply_ret_stream();
    return 0;
  case :
    pppuStack_c = (undefined4 ***)0x0;
    if (*(int *)(param_1 + 4) == 0x20) {
      ppppuStack_68 = &pppuStack_c;
      pppuStack_6c = __NXAudioSndoutDevice;
      (*___NXAudioGetSndoutOptions)();
      if ((*(byte *)(param_1 + 0x1f) & 4) == 0) {
        pppuStack_c = (uint ***)((uint)pppuStack_c & 0xfffffffe);
      }
      else {
        pppuStack_c = (uint ***)((uint)pppuStack_c | 1);
      }
      if ((*(byte *)(param_1 + 0x1f) & 2) == 0) {
        pppuStack_c = (uint ***)((uint)pppuStack_c & 0xffffffef);
      }
      else {
        pppuStack_c = (uint ***)((uint)pppuStack_c | 0x10);
      }
      if ((*(byte *)(param_1 + 0x1f) & 1) == 0) {
        pppuStack_c = (uint ***)((uint)pppuStack_c & 0xfffffff7);
      }
      else {
        pppuStack_c = (uint ***)((uint)pppuStack_c | 8);
      }
      ppppuStack_68 = (undefined4 ****)pppuStack_c;
loc_40861B2:
      pppuStack_6c = (undefined4 ***)0x0;
      (*___NXAudioSetSndoutOptions)(__NXAudioSndoutDevice);
      return 100;
    }
    break;
  case :
    pppuVar6 = (uint ***)0x0;
    if (*(int *)(param_1 + 4) == 0x18) {
      ppppuStack_68 = (undefined4 ****)&ppuStack_10;
      pppuStack_6c = __NXAudioSndoutDevice;
      (*___NXAudioGetSndoutOptions)();
      if (((uint)ppuStack_10 & 1) != 0) {
        pppuVar6 = (uint ***)0x4;
      }
      if (((uint)ppuStack_10 & 0x10) != 0) {
        pppuVar6 = (uint ***)((uint)pppuVar6 | 2);
      }
      if (((uint)ppuStack_10 & 8) != 0) {
        pppuVar6 = (uint ***)((uint)pppuVar6 | 1);
      }
      pppuStack_6c = *(uint ****)(param_1 + 0x10);
      ppppuStack_68 = (undefined4 ****)pppuVar6;
      _snd_reply_ret_parms();
      return 0;
    }
    break;
  case :
    if (*(int *)(param_1 + 4) == 0x20) {
      ppppuStack_68 = *(undefined4 *****)(param_1 + 0x1c);
      pppuStack_6c = (undefined4 ***)0x40860aa;
      _snd_device_set_volume();
      return 100;
    }
    break;
  case :
    if (*(int *)(param_1 + 4) == 0x18) {
      ppppuStack_68 = (undefined4 ****)0x40860be;
      ppppuStack_68 = (undefined4 ****)_snd_device_get_volume();
      pppuStack_6c = *(uint ****)(param_1 + 0x10);
      _snd_reply_ret_volume();
      return 0;
    }
    break;
  case :
    if (*(int *)(param_1 + 4) != 0x28) {
      return 0x67;
    }
    if (_snd_var == *(uint ****)(param_1 + 0x24)) {
      ppppuStack_68 = (undefined4 ****)0x40861e4;
      _dsp_dev_reset_hard();
loc_4086248:
      _snd_var = *(uint ****)(param_1 + 0x24);
      dword_40C6E9C = *(undefined4 *)(param_1 + 0x1c);
      ppppuStack_68 = (undefined4 ****)0x408625e;
      _dsp_dev_init();
      dword_40C6E5A = dword_40C6E52;
      return 100;
    }
    if (_snd_var == (uint ***)0x0) {
      ppppuStack_68 = (undefined4 ****)0x800;
      pppuStack_6c = (undefined4 ***)0x408620a;
      dword_40C6E52 = _kalloc();
      dword_40C6E56 = dword_40C6E52 + 0x800;
      uVar7 = 0x12;
      do {
        do {
          ppppuStack_68 = (undefined4 ****)(uVar7 | 0x10000);
          pppuStack_6c = (undefined4 ***)0x408622e;
          sub_4085946();
          wVar5 = (word)(uVar7 >> 0x10);
          sVar8 = (sword)uVar7 + -1;
          uVar7 = CONCAT22(wVar5,sVar8);
        } while (sVar8 != -1);
        uVar7 = (uint)wVar5 * 0x10000 - 1;
      } while (wVar5 != 0);
      ppppuStack_68 = (undefined4 ****)0x10013;
      pppuStack_6c = (undefined4 ***)0x4086246;
      sub_4085946();
      goto loc_4086248;
    }
    pppuStack_6c = *(uint ****)(param_1 + 0x14);
    uVar2 = *(undefined4 *)(param_1 + 0x10);
    uVar12 = dword_40C6E9C;
    goto loc_40862EE;
  case :
    if (*(int *)(param_1 + 4) != 0x28) {
      return 0x67;
    }
    if (__NXAudioSndinDevice != (undefined4 ***)0x0) {
      if ((undefined4 **)dword_40C6E8C == &dword_40C6E8C) {
        ppppuVar9 = (uint ****)&ppppuStack_68;
        ppppuStack_68 = (undefined4 ****)0x10082;
        pppuStack_6c = (undefined4 ***)0x4086294;
        sub_4085946();
      }
      else {
        ppppuStack_68 = *(undefined4 *****)(param_1 + 0x24);
        pppuStack_6c = (uint ***)&dword_40C6E8C;
        iVar3 = _snd_get_owner();
        ppppuVar9 = (uint ****)&stack0xffffff9c;
        if (iVar3 != 0) {
loc_4086350:
          ppppuStack_68 = (undefined4 ****)0x0;
          pppuStack_6c = (undefined4 ***)0x0;
          (*___NXAudioStreamControl)(*(undefined4 *)(iVar3 + 4),2);
          return 100;
        }
      }
      *(undefined4 *)((int)ppppuVar9 + -4) = *(undefined4 *)(param_1 + 0x24);
      *(undefined4 ***)((int)ppppuVar9 + -8) = &dword_40C6E8C;
      *(undefined4 *)((int)ppppuVar9 + -0xc) = 0x40862b6;
      sub_4085C76();
      return 100;
    }
    goto loc_40862E0;
  case :
    if (*(int *)(param_1 + 4) != 0x28) {
      return 0x67;
    }
    if (__NXAudioSndoutDevice != (undefined4 ***)0x0) {
      if ((undefined4 **)dword_40C6E94 == &dword_40C6E94) {
        ppppuStack_68 = (undefined4 ****)0x10080;
        pppuStack_6c = (undefined4 ***)0x4086312;
        sub_4085946();
        ppppuVar10 = &pppuStack_6c;
        pppuStack_6c = (undefined4 ***)0x10081;
        sub_4085946();
      }
      else {
        ppppuStack_68 = *(undefined4 *****)(param_1 + 0x24);
        pppuStack_6c = (uint ***)&dword_40C6E94;
        iVar3 = _snd_get_owner();
        ppppuVar10 = (undefined4 ****)&stack0xffffff9c;
        if (iVar3 != 0) goto loc_4086350;
      }
      *(undefined4 *)((int)ppppuVar10 + -4) = *(undefined4 *)(param_1 + 0x24);
      *(undefined4 ***)((int)ppppuVar10 + -8) = &dword_40C6E94;
      *(undefined4 *)((int)ppppuVar10 + -0xc) = 0x408633c;
      sub_4085C76();
      return 100;
    }
loc_40862E0:
    pppuStack_6c = *(uint ****)(param_1 + 0x14);
    uVar2 = *(undefined4 *)(param_1 + 0x10);
    uVar12 = 0;
loc_40862EE:
    ppppuStack_68 = (undefined4 ****)0x69;
    _snd_reply_illegal_msg(uVar12,uVar2);
    return 0;
  case :
    if (*(int *)(param_1 + 4) != 0x28) {
      return 0x67;
    }
    ppppuStack_68 = *(undefined4 *****)(param_1 + 0x24);
    if (ppppuStack_68 != (undefined4 ****)_snd_var) {
      return 0x6a;
    }
    if ((*(byte *)(param_1 + 0x1f) & 8) != 0) {
      pppuStack_6c = (uint ***)&dword_40C6E94;
      iVar3 = _snd_get_owner();
      if (iVar3 == 0) {
        return 0x6a;
      }
      if (dword_40C6DF8 == 0) {
        return 0x6b;
      }
    }
    if ((*(byte *)(param_1 + 0x1f) & 0x10) != 0) {
      ppppuStack_68 = (undefined4 ****)_snd_var;
      pppuStack_6c = (uint ***)&dword_40C6E8C;
      iVar3 = _snd_get_owner();
      if (iVar3 == 0) {
        return 0x6a;
      }
      if (dword_40C6DFC == 0) {
        return 0x6b;
      }
    }
    if ((((dword_40C6E84 & 0x2000) != 0) && ((*(byte *)(param_1 + 0x1f) & 4) != 0)) ||
       (((dword_40C6E84 & 0x1000) != 0 && ((*(byte *)(param_1 + 0x1f) & 2) != 0)))) {
      ppppuStack_68 = (undefined4 ****)0x0;
      pppuStack_6c = (undefined4 ***)0x4086402;
      _dsp_dev_new_proto();
    }
    ppppuStack_68 = *(undefined4 *****)(param_1 + 0x1c);
    pppuStack_6c = (undefined4 ***)0x408640e;
    _dsp_dev_new_proto();
    return 100;
  case :
    if (*(int *)(param_1 + 4) != 0x20) {
      return 0x67;
    }
    if (*(uint ****)(param_1 + 0x1c) != _snd_var) {
      return 0x6a;
    }
    ppppuStack_68 = *(undefined4 *****)(param_1 + 0x10);
    pppuStack_6c = (undefined4 ***)0x10013;
    _snd_reply_dsp_cmd_port();
    return 0;
  case :
    if (*(int *)(param_1 + 4) == 0x20) {
      puVar1 = dword_40C6E8C;
      if (*(int *)(param_1 + 0x1c) != dword_40C6EC8) {
        return 0x70;
      }
      while (dword_40C6E8C = puVar1, (undefined4 **)puVar4 != &dword_40C6E94) {
        ppppuStack_68 = (undefined4 ****)*puVar4;
        pppuStack_6c = (undefined4 ***)0x4086472;
        sub_40870BA();
        pppuStack_6c = (uint ***)*puVar4;
        _port_deallocate(dword_40C6EC0);
        puVar1 = dword_40C6E8C;
      }
      while ((undefined4 **)puVar1 != &dword_40C6E8C) {
        ppppuStack_68 = (undefined4 ****)*puVar1;
        pppuStack_6c = (undefined4 ***)0x408649e;
        sub_40870BA();
        pppuStack_6c = (uint ***)*puVar1;
        _port_deallocate(dword_40C6EC0);
      }
      if (_snd_var != (uint ***)0x0) {
        pppuStack_6c = (undefined4 ***)0x40864c6;
        ppppuStack_68 = (undefined4 ****)_snd_var;
        sub_40870BA();
        pppuStack_6c = _snd_var;
        _port_deallocate(dword_40C6EC0);
        _snd_var = (uint ***)0x0;
      }
      ppppuStack_68 = (undefined4 ****)dword_40C6EB4;
      pppuStack_6c = dword_40C6EC0;
      _port_deallocate();
      _port_allocate(dword_40C6EC0,&dword_40C6EB4);
      _port_set_add(dword_40C6EC0,dword_40C6EA8,dword_40C6EB4);
      _snd_reply_ret_device(*(undefined4 *)(param_1 + 0x10),dword_40C6EB4);
      return 0;
    }
    break;
  case :
    if (*(int *)(param_1 + 4) == 0x30) {
      ppppuStack_68 = *(undefined4 *****)(param_1 + 0x1c);
      if (ppppuStack_68 != (undefined4 ****)_snd_var) {
        return 0x6a;
      }
      pppuStack_6c = dword_40C6EC0;
      _port_deallocate();
      _snd_var = *(uint ****)(param_1 + 0x24);
      _port_deallocate(dword_40C6EC0,dword_40C6E9C);
      dword_40C6E9C = *(undefined4 *)(param_1 + 0x2c);
      return 0;
    }
    break;
  case :
    if (*(int *)(param_1 + 4) != 0x30) {
      return 0x67;
    }
    ppppuStack_68 = *(undefined4 *****)(param_1 + 0x1c);
    pppuStack_6c = (uint ***)&dword_40C6E8C;
    puVar4 = (undefined4 *)_snd_get_owner();
    goto joined_r0x040865a0;
  case :
    if (*(int *)(param_1 + 4) != 0x30) {
      return 0x67;
    }
    ppppuStack_68 = *(undefined4 *****)(param_1 + 0x1c);
    pppuStack_6c = (uint ***)&dword_40C6E94;
    puVar4 = (undefined4 *)_snd_get_owner();
joined_r0x040865a0:
    if (puVar4 == (undefined4 *)0x0) {
      return 0x6a;
    }
    ppppuStack_68 = (undefined4 ****)*puVar4;
    pppuStack_6c = dword_40C6EC0;
    _port_deallocate();
    *puVar4 = *(undefined4 *)(param_1 + 0x24);
    return 0;
  case :
    pppuStack_3c = (undefined4 ***)0x0;
    if (*(int *)(param_1 + 4) == 0x20) {
      ppppuStack_68 = &pppuStack_3c;
      pppuStack_6c = __NXAudioSndoutDevice;
      (*___NXAudioGetSndoutOptions)();
      if ((*(byte *)(param_1 + 0x1f) & 1) == 0) {
        pppuStack_3c = (uint ***)((uint)pppuStack_3c & 0xfffffffd);
      }
      else {
        pppuStack_3c = (uint ***)((uint)pppuStack_3c | 2);
      }
      if ((*(byte *)(param_1 + 0x1f) & 2) == 0) {
        pppuStack_3c = (uint ***)((uint)pppuStack_3c & 0xfffffffb);
      }
      else {
        pppuStack_3c = (uint ***)((uint)pppuStack_3c | 4);
      }
      ppppuStack_68 = (undefined4 ****)pppuStack_3c;
      goto loc_40861B2;
    }
    break;
  case :
    if (*(int *)(param_1 + 4) == 0x18) {
      ppppuStack_68 = (undefined4 ****)&ppuStack_24;
      pppuStack_6c = &ppuStack_20;
      sub_4085D2E(__NXAudioSndoutDevice,&uStack_14,&uStack_18,&uStack_1c);
      uStack_28 = uStack_14;
      uStack_2c = uStack_18;
      uStack_30 = uStack_1c;
      ppuStack_34 = ppuStack_20;
      ppuStack_38 = ppuStack_24;
loc_408614E:
      _snd_reply_ret_formats
                (*(undefined4 *)(param_1 + 0x10),uStack_28,uStack_2c,uStack_30,ppuStack_34,
                 ppuStack_38);
      return 0;
    }
    break;
  case :
    if (*(int *)(param_1 + 4) == 0x18) {
      ppppuStack_68 = (undefined4 ****)&ppuStack_38;
      pppuStack_6c = &ppuStack_34;
      sub_4085D2E(__NXAudioSndinDevice,&uStack_28,&uStack_2c,&uStack_30);
      goto loc_408614E;
    }
    break;
  :
    return 0x66;
  }
  return 0x67;
}
/* GHIDRADEC_FUNCTION index=3117 start=0x40865cc */

undefined4 sub_40865CC(int param_1)

{
  undefined4 uVar1;
  
  if (param_1 == 2) {
    uVar1 = 0x259;
  }
  else if ((param_1 < 3) || (param_1 != 4)) {
    uVar1 = 0x25a;
  }
  else {
    uVar1 = 600;
  }
  return uVar1;
}
/* GHIDRADEC_FUNCTION index=3118 start=0x40865fc */

void sub_40865FC(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                undefined4 param_5,undefined4 param_6,undefined4 param_7)

{
  undefined4 uStack_38;
  undefined4 uStack_34;
  undefined4 uStack_30;
  undefined4 uStack_2c;
  undefined4 uStack_28;
  undefined4 uStack_18;
  undefined4 uStack_14;
  undefined4 uStack_10;
  undefined4 uStack_c;
  undefined4 uStack_8;
  
  uStack_18 = 0x194;
  uStack_14 = 0x193;
  uStack_10 = 0x191;
  uStack_c = 400;
  uStack_8 = 0x192;
  uStack_38 = param_6;
  uStack_34 = param_7;
  uStack_30 = param_3;
  uStack_2c = sub_40865CC(param_4);
  uStack_28 = param_5;
  (*___NXAudioSetStreamParameters)(param_2,&uStack_18,5,&uStack_38);
  return;
}
/* GHIDRADEC_FUNCTION index=3119 start=0x408667a */

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
/* GHIDRADEC_FUNCTION index=3120 start=0x40870ba */

void sub_40870BA(int param_1)

{
  int iVar1;
  word wVar2;
  uint uVar3;
  sword sVar4;
  
  if (param_1 == _snd_var) {
    _snd_var = 0;
    uVar3 = 0x12;
    do {
      do {
        _port_deallocate(dword_40C6EC0,uVar3 | 0x10000);
        wVar2 = (word)(uVar3 >> 0x10);
        sVar4 = (sword)uVar3 + -1;
        uVar3 = CONCAT22(wVar2,sVar4);
      } while (sVar4 != -1);
      uVar3 = (uint)wVar2 * 0x10000 - 1;
    } while (wVar2 != 0);
    _port_deallocate(dword_40C6EC0,0x10013);
    _dsp_dev_reset_hard();
    if (dword_40C6E52 != 0) {
      _kfree(dword_40C6E52,dword_40C6E56 - dword_40C6E52 & 0xfffffffc);
      dword_40C6E5A = 0;
      dword_40C6E56 = 0;
      dword_40C6E52 = 0;
    }
    if (dword_40C6E5E != 0) {
      _kfree(dword_40C6E5E,dword_40C6E62 - dword_40C6E5E & 0xfffffffc);
      dword_40C6E66 = 0;
      dword_40C6E62 = 0;
      dword_40C6E5E = 0;
    }
  }
  iVar1 = _snd_get_owner(&dword_40C6E8C,param_1);
  if (iVar1 != 0) {
    if (*(int *)(iVar1 + 4) != 0) {
      (*___NXAudioRemoveStream)(*(int *)(iVar1 + 4));
    }
    sub_4085CEA(&dword_40C6E8C,iVar1);
    if ((undefined4 **)dword_40C6E8C == &dword_40C6E8C) {
      _port_deallocate(dword_40C6EC0,0x10082);
    }
  }
  iVar1 = _snd_get_owner(&dword_40C6E94,param_1);
  if (iVar1 != 0) {
    if (*(int *)(iVar1 + 4) != 0) {
      (*___NXAudioRemoveStream)(*(int *)(iVar1 + 4));
    }
    sub_4085CEA(&dword_40C6E94,iVar1);
    if ((undefined4 **)dword_40C6E94 == &dword_40C6E94) {
      _port_deallocate(dword_40C6EC0,0x10080);
      _port_deallocate(dword_40C6EC0,0x10081);
    }
  }
  if (((((undefined4 **)dword_40C6E8C == &dword_40C6E8C) &&
       ((undefined4 **)dword_40C6E94 == &dword_40C6E94)) && (_snd_var == 0)) &&
     (*(int *)(dword_40C6EBC + 0x24) != 0)) {
    _vm_deallocate(dword_40C6EBC,*(undefined4 *)(dword_40C6EBC + 0x10),
                   *(undefined4 *)(dword_40C6EBC + 0x14));
  }
  return;
}
/* GHIDRADEC_FUNCTION index=3121 start=0x408771e */

void sub_408771E(void)

{
  undefined4 *puVar1;
  uint uVar2;
  int *piVar3;
  int *piVar4;
  undefined4 *puVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  int *piVar9;
  undefined4 uVar10;
  word wVar11;
  sword sVar13;
  int *piVar14;
  int iVar12;
  
  iVar7 = (int)dword_40C6EAC;
  puVar1 = *(undefined4 **)((int)dword_40C6EAC + 0x14);
  if ((undefined4 **)puVar1 == &dword_40C6EAC) {
    dword_40C6EB0 = &dword_40C6EAC;
  }
  else {
    puVar1[6] = &dword_40C6EAC;
  }
  piVar9 = (int *)((int)dword_40C6EAC + 0x14);
  piVar3 = (int *)((int)dword_40C6EAC + 0x18);
  dword_40C6EAC = puVar1;
  *piVar3 = (int)piVar9;
  *piVar9 = (int)piVar9;
  iVar12 = *(int *)(iVar7 + 0x2e) + -1;
  if (-1 < iVar12) {
    do {
      iVar8 = _kalloc(0x38);
      *(int *)(iVar8 + 0x24) = iVar8;
      piVar3 = *(int **)(iVar7 + 0x18);
      if (piVar3 == piVar9) {
        *piVar3 = iVar8;
      }
      else {
        piVar3[0xb] = iVar8;
      }
      *(int **)(iVar8 + 0x30) = piVar3;
      *(int *)(iVar8 + 0x2c) = iVar7 + 0x14;
      *(int *)(iVar7 + 0x18) = iVar8;
      *(undefined4 *)(iVar8 + 0x28) = 0x4087ba2;
      wVar11 = (word)((uint)iVar12 >> 0x10);
      sVar13 = (sword)iVar12 + -1;
      iVar12 = CONCAT22(wVar11,sVar13);
    } while ((sVar13 != -1) || (iVar12 = (uint)wVar11 * 0x10000 + -1, wVar11 != 0));
  }
  iVar12 = iVar7 + 4;
  _lock_write(iVar12);
  piVar9 = *(int **)(iVar7 + 0xc);
  piVar4 = (int *)(iVar7 + 0xc);
  piVar3 = (int *)*piVar4;
  piVar14 = piVar9;
  while (piVar4 != piVar3) {
    *(byte *)(iVar7 + 0x24) = *(byte *)(iVar7 + 0x24) & 0xfd;
    iVar8 = piVar9[7];
    if (_page_size <= piVar9[4] - iVar8) {
      iVar6 = (~_page_mask & piVar9[4]) - iVar8;
      uVar10 = 2;
      if ((*(byte *)((int)piVar9 + 0x2d) & 0x40) != 0) {
        uVar10 = 1;
      }
      sub_4087F1E(iVar8,iVar6,uVar10,*(byte *)((int)piVar9 + 0x2d) & 1);
      piVar9[7] = iVar6 + piVar9[7];
      *(int *)(iVar7 + 0x20) = *(int *)(iVar7 + 0x20) - iVar6;
    }
    if (((*(byte *)((int)piVar9 + 0x2d) & 2) != 0) &&
       (*(byte *)((int)piVar9 + 0x2d) = *(byte *)((int)piVar9 + 0x2d) & 0xfd,
       (*(byte *)(piVar9 + 0xb) & 4) != 0)) {
      _snd_reply_overflow(piVar9[6],*(undefined4 *)((int)piVar9 + 0x2e));
    }
    if (((*(byte *)((int)piVar9 + 0x2d) & 0x10) != 0) && ((*(byte *)(piVar9 + 0xb) & 0x40) != 0)) {
      *(byte *)(piVar9 + 0xb) = *(byte *)(piVar9 + 0xb) & 0xbf;
      _snd_reply_started(piVar9[6],*(undefined4 *)((int)piVar9 + 0x2e));
    }
    if (((*(byte *)((int)piVar9 + 0x2d) & 0x10) != 0) && ((*(byte *)(piVar9 + 0xb) & 2) != 0)) {
      piVar9 = (int *)sub_408815A(piVar9,iVar7);
      piVar14 = piVar9;
    }
    if ((*(byte *)((int)piVar9 + 0x2d) & 0x20) == 0) {
      if (((*(byte *)((int)piVar9 + 0x2d) & 8) == 0) ||
         ((uint)piVar9[7] < (piVar9[2] & ~_page_mask))) {
        if ((((*(byte *)(iVar7 + 0x24) & 0x34) == 0) &&
            ((int *)(iVar7 + 0x14) != *(int **)(iVar7 + 0x14))) &&
           (((uint)piVar9[10] <= piVar9[8] - (~_page_mask & piVar9[3]) ||
            ((uint)piVar9[2] <= (uint)piVar9[8])))) {
          *(byte *)((int)piVar9 + 0x2d) = *(byte *)((int)piVar9 + 0x2d) & 0xfb;
          sub_4087D98(iVar7,piVar9);
        }
        if ((((uint)piVar14[2] <= (uint)piVar14[8]) ||
            ((*(byte *)((int)piVar14 + 0x2d) & 0x20) != 0)) &&
           (*(int **)((int)piVar14 + 0x32) != piVar4)) {
          piVar14 = *(int **)((int)piVar14 + 0x32);
        }
        if ((((*(byte *)((int)piVar14 + 0x2d) & 0x20) == 0) && ((uint)piVar14[8] < (uint)piVar14[2])
            ) && (*(uint *)(iVar7 + 0x20) < (uint)piVar14[9])) {
          sub_4087FDE(piVar14[8]);
          iVar6 = _page_size;
          iVar8 = _page_size + piVar14[8];
          piVar14[8] = iVar8;
          if ((uint)piVar14[2] < (uint)(piVar14[10] + iVar8)) {
            piVar14[10] = piVar14[10] - iVar6;
          }
          *(int *)(iVar7 + 0x20) = _page_size + *(int *)(iVar7 + 0x20);
          _lock_done(iVar12);
          _lock_write(iVar12);
        }
        else {
          _lock_done(iVar12);
          if ((*(byte *)(iVar7 + 0x24) & 2) == 0) {
            _assert_wait(iVar7,1);
            _thread_block();
          }
          _lock_write(iVar12);
        }
      }
      else {
        piVar9 = (int *)sub_4088078(piVar9,iVar7);
        _lock_done(iVar12);
        _lock_write(iVar12);
        piVar14 = piVar9;
      }
    }
    else {
      *(byte *)((int)piVar9 + 0x2d) = *(byte *)((int)piVar9 + 0x2d) | 4;
      iVar8 = piVar9[8] - (~_page_mask & _page_mask + piVar9[3]);
      if (0 < iVar8) {
        uVar10 = 0;
        if ((*(byte *)((int)piVar9 + 0x2d) & 0x40) == 0) {
          uVar10 = 2;
        }
        sub_4087F1E(~_page_mask & _page_mask + piVar9[3],iVar8,uVar10,1);
        *(int *)(iVar7 + 0x20) = *(int *)(iVar7 + 0x20) - iVar8;
        piVar9[8] = ~_page_mask & _page_mask + piVar9[3];
      }
      uVar2 = piVar9[8];
      if (uVar2 < (uint)piVar9[2]) {
        _vm_deallocate(dword_40C6EBC,uVar2,piVar9[2] - uVar2);
        piVar9[2] = piVar9[8];
      }
      piVar9[7] = piVar9[8];
      if (piVar9[3] == piVar9[4]) {
        *(byte *)((int)piVar9 + 0x2d) = *(byte *)((int)piVar9 + 0x2d) | 8;
      }
      piVar9[2] = piVar9[3];
      piVar9[1] = piVar9[2] - *piVar9;
      *(byte *)(piVar9 + 0xb) = *(byte *)(piVar9 + 0xb) & 0x7f;
      *(byte *)((int)piVar9 + 0x2d) = *(byte *)((int)piVar9 + 0x2d) & 0xdf;
      *(byte *)((int)piVar9 + 0x2d) = *(byte *)((int)piVar9 + 0x2d) | 4;
      piVar3 = *(int **)((int)piVar9 + 0x32);
      if ((piVar3 != piVar4) && ((*(byte *)(piVar3 + 0xb) & 0x40) == 0)) {
        *(byte *)((int)piVar3 + 0x2d) = *(byte *)((int)piVar3 + 0x2d) | 4;
      }
      if ((*(byte *)(piVar9 + 0xb) & 0x20) != 0) {
        _snd_reply_aborted(piVar9[6],*(undefined4 *)((int)piVar9 + 0x2e));
      }
    }
    piVar3 = (int *)*piVar4;
  }
  puVar5 = (undefined4 *)(iVar7 + 0x14);
  puVar1 = (undefined4 *)*puVar5;
  while (puVar5 != puVar1) {
    iVar12 = *(int *)(iVar7 + 0x14);
    puVar1 = *(undefined4 **)(iVar12 + 0x2c);
    if (puVar1 == puVar5) {
      *(undefined4 **)(iVar7 + 0x18) = puVar5;
    }
    else {
      puVar1[0xc] = puVar5;
    }
    *(undefined4 **)(iVar7 + 0x14) = puVar1;
    _kfree(iVar12,0x38);
    puVar1 = (undefined4 *)*puVar5;
  }
  *(undefined4 *)(iVar7 + 0x1c) = 0;
  _lock_done(iVar7 + 4);
  _thread_wakeup_prim(iVar7,0,0);
  _thread_terminate(_active_threads);
  _thread_halt_self();
  return;
}
/* GHIDRADEC_FUNCTION index=3122 start=0x4087d98 */

undefined4 sub_4087D98(int param_1,int param_2)

{
  int *piVar1;
  int *piVar2;
  int iVar3;
  uint uVar4;
  undefined4 uVar5;
  int *piVar6;
  
  uVar5 = 0;
  if ((*(uint *)(param_2 + 0xc) < *(uint *)(param_2 + 0x20)) &&
     (*(uint *)(param_2 + 0xc) < *(uint *)(param_2 + 8))) {
    piVar2 = (int *)(param_1 + 0x14);
    while (piVar1 = (int *)*piVar2, piVar1 != piVar2) {
      uVar5 = 1;
      piVar6 = (int *)piVar1[0xb];
      if (piVar6 == piVar2) {
        *(int **)(param_1 + 0x18) = piVar2;
      }
      else {
        piVar6[0xc] = (int)piVar2;
      }
      *(int **)(param_1 + 0x14) = piVar6;
      uVar4 = (~_page_mask & *(int *)(param_2 + 0xc) + 1 + _page_mask) - *(int *)(param_2 + 0xc);
      if (*(uint *)(param_2 + 0x14) < uVar4) {
        uVar4 = *(uint *)(param_2 + 0x14);
      }
      if (*(uint *)(param_2 + 8) < uVar4 + *(int *)(param_2 + 0xc)) {
        uVar4 = *(uint *)(param_2 + 8) - *(int *)(param_2 + 0xc);
      }
      *piVar1 = *(undefined4 *)(param_2 + 0xc);
      piVar1[1] = uVar4;
      piVar1[0xd] = 0;
      piVar1[2] = param_2;
      *(uint *)(param_2 + 0xc) = uVar4 + *(int *)(param_2 + 0xc);
      iVar3 = _pmap_resident_extract(*(undefined4 *)(dword_40C6EBC + 0x20),*piVar1);
      piVar1[4] = iVar3;
      if (iVar3 == 0) {
        *(byte *)(param_2 + 0x2d) = *(byte *)(param_2 + 0x2d) | 0x20;
        *(byte *)(param_1 + 0x24) = *(byte *)(param_1 + 0x24) & 0xdf;
        *(uint *)(param_2 + 0xc) = *(int *)(param_2 + 0xc) - uVar4;
        piVar6 = *(int **)(param_1 + 0x18);
        if (piVar6 == piVar2) {
          *piVar2 = (int)piVar1;
          goto loc_4087ED0;
        }
loc_4087ECC:
        piVar6[0xb] = (int)piVar1;
loc_4087ED0:
        piVar1[0xc] = (int)piVar6;
        piVar1[0xb] = param_1 + 0x14;
        *(int **)(param_1 + 0x18) = piVar1;
        *(byte *)(param_1 + 0x24) = *(byte *)(param_1 + 0x24) | 4;
        return 0;
      }
      piVar1[5] = piVar1[1] + iVar3;
      iVar3 = (**(code **)(param_1 + 0x3a))
                        (piVar1,(*(byte *)(param_2 + 0x2d) & 0x7f) >> 6,
                         (*(word *)(param_2 + 0x2c) & 0x1ff) >> 7);
      if (iVar3 == 0) {
        *(uint *)(param_2 + 0xc) = *(int *)(param_2 + 0xc) - uVar4;
        piVar6 = *(int **)(param_1 + 0x18);
        if (piVar6 == piVar2) {
          *piVar6 = (int)piVar1;
          goto loc_4087ED0;
        }
        goto loc_4087ECC;
      }
      if (*(uint *)(param_2 + 0x20) <= *(uint *)(param_2 + 0xc)) {
        return 1;
      }
      if (*(uint *)(param_2 + 8) <= *(uint *)(param_2 + 0xc)) {
        return 1;
      }
    }
  }
  return uVar5;
}
/* GHIDRADEC_FUNCTION index=3123 start=0x4087f1e */

void sub_4087F1E(int param_1,int param_2,int param_3,int param_4)

{
  undefined4 uVar1;
  int iVar2;
  
  for (; param_2 != 0; param_2 = param_2 - _page_size) {
    uVar1 = _pmap_resident_extract(*(undefined4 *)(dword_40C6EBC + 0x20),param_1);
    iVar2 = _vm_phys_to_vm_page(uVar1);
    if (iVar2 != 0) {
      if (param_3 != 2) {
        *(byte *)(iVar2 + 0x1e) = *(byte *)(iVar2 + 0x1e) & 0xfb | (param_3 == 0) << 2;
      }
      _vm_fault(dword_40C6EBC,param_1,0,1,0);
      if (param_4 != 0) {
        uVar1 = _pmap_extract(*(undefined4 *)(dword_40C6EBC + 0x20),param_1);
        iVar2 = _vm_phys_to_vm_page(uVar1);
        if (iVar2 != 0) {
          _vm_page_deactivate(iVar2);
        }
      }
    }
    param_1 = _page_size + param_1;
  }
  return;
}
/* GHIDRADEC_FUNCTION index=3124 start=0x4087fde */

void sub_4087FDE(undefined4 param_1)

{
  int iVar1;
  int iStack_8;
  
  _lock_write(dword_40C6EBC);
  *(int *)(dword_40C6EBC + 0x40) = *(int *)(dword_40C6EBC + 0x40) + 1;
  iVar1 = _vm_map_lookup_entry(dword_40C6EBC,param_1,&iStack_8);
  if (iVar1 == 0) {
                    /* WARNING: Subroutine does not return */
    _panic(aSndWirePageAdd);
  }
  *(sword *)(iStack_8 + 0x26) = *(sword *)(iStack_8 + 0x26) + 1;
  _lock_done(dword_40C6EBC);
  _vm_fault(dword_40C6EBC,param_1,0,1,0);
  _lock_write(dword_40C6EBC);
  *(int *)(dword_40C6EBC + 0x40) = *(int *)(dword_40C6EBC + 0x40) + 1;
  *(sword *)(iStack_8 + 0x26) = *(sword *)(iStack_8 + 0x26) + -1;
  _lock_done(dword_40C6EBC);
  return;
}

