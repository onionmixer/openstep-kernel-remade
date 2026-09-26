
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
