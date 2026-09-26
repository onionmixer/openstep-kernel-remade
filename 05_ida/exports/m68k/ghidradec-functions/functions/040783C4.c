
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
