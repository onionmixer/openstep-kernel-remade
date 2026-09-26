
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

