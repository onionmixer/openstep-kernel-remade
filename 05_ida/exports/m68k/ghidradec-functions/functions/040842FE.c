
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
