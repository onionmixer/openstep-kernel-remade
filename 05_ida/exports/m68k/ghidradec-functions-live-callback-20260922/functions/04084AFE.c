
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

