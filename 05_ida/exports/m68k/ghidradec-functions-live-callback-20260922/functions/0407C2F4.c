
void sub_407C2F4(void)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  byte bVar4;
  int iVar5;
  bool bVar6;
  uint unaff_D2;
  undefined4 *puVar7;
  
  puVar7 = dword_40B4FD2;
  if ((undefined4 **)dword_40B4FD2 != &dword_40B4FD2) {
    do {
      bVar4 = *(byte *)((int)puVar7 + 0x5a);
      if (bVar4 != 1) {
        if (bVar4 < 2) {
          if (bVar4 != 0) {
loc_407C44C:
                    /* WARNING: Subroutine does not return */
            _panic(aScsiTimerScAct);
          }
          bVar6 = false;
          for (puVar1 = (undefined4 *)*puVar7; puVar1 != puVar7; puVar1 = (undefined4 *)puVar1[2]) {
            if ((*(char *)(puVar1 + 9) < '\0') &&
               (iVar5 = puVar1[8] - dword_40B4FCE, puVar1[8] = iVar5, iVar5 < 0)) {
              puVar2 = (undefined4 *)puVar1[2];
              puVar3 = (undefined4 *)puVar1[3];
              if (puVar2 == puVar7) {
                puVar7[1] = puVar3;
              }
              else {
                puVar2[3] = puVar3;
              }
              if (puVar3 == puVar7) {
                *puVar7 = puVar2;
              }
              else {
                puVar3[2] = puVar2;
              }
              *(undefined *)((int)puVar1 + 0x4f) = 6;
              *(byte *)(puVar1 + 9) = *(byte *)(puVar1 + 9) & 0x5f;
              *(undefined *)((int)puVar7 + 0x5a) = 3;
              (**(code **)(puVar1[5] + 0x16))(puVar1);
              bVar6 = true;
              unaff_D2 = (uint)*(byte *)(puVar1 + 7);
            }
          }
          if (bVar6) {
            _printf(aReselectTimeou,unaff_D2);
            (**(code **)(puVar7[5] + 8))(puVar7,1,aReselectTimeou_0);
            *(undefined *)((int)puVar7 + 0x5a) = 0;
            if ((int *)(puVar7[4] + 0x18) != *(int **)(puVar7[4] + 0x18)) {
              sub_407C04A(puVar7);
            }
          }
        }
        else {
          if (bVar4 != 2) goto loc_407C44C;
          if ((*(char *)((int)puVar7 + 0x5b) != '\0') &&
             (iVar5 = puVar7[0x17] - dword_40B4FCE, puVar7[0x17] = iVar5, iVar5 < 0)) {
            *(undefined *)((int)puVar7 + 0x5b) = 0;
            iVar5 = *(int *)(puVar7[4] + 0x18);
            (**(code **)(puVar7[5] + 8))(puVar7,0,aLostInterrupt);
            _scsi_msg(iVar5,*(undefined *)(iVar5 + 0x26),aScsiTimerTimeo);
          }
        }
      }
      puVar1 = puVar7 + 2;
      puVar7 = (undefined4 *)*puVar1;
    } while ((undefined4 **)*puVar1 != &dword_40B4FD2);
  }
  _timeout(sub_407C2F4,0,dword_40B4FCE);
  return;
}

