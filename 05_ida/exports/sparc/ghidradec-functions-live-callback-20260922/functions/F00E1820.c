
/* WARNING: Removing unreachable block (ram,0xf00e1934) */
/* WARNING: Removing unreachable block (ram,0xf00e18ac) */
/* WARNING: Removing unreachable block (ram,0xf00e1a08) */
/* WARNING: Removing unreachable block (ram,0xf00e1c24) */
/* WARNING: Removing unreachable block (ram,0xf00e1bcc) */
/* WARNING: Removing unreachable block (ram,0xf00e1b3c) */
/* WARNING: Removing unreachable block (ram,0xf00e1b94) */
/* WARNING: Removing unreachable block (ram,0xf00e1bec) */
/* WARNING: Removing unreachable block (ram,0xf00e199c) */
/* WARNING: Removing unreachable block (ram,0xf00e1a4c) */
/* WARNING: Removing unreachable block (ram,0xf00e1918) */
/* WARNING: Removing unreachable block (ram,0xf00e1c48) */
/* WARNING: Removing unreachable block (ram,0xf00e1b04) */

undefined8
_audio_scaleSamples(byte *param_1,undefined2 *param_2,uint param_3,int param_4,int param_5,
                   int param_6)

{
  byte bVar1;
  sword sVar2;
  int iVar3;
  uint uVar4;
  int iVar5;
  undefined uVar6;
  undefined4 unaff_l0;
  int iVar7;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  undefined4 unaff_i1;
  undefined *puVar8;
  undefined4 unaff_i2;
  int iVar9;
  undefined4 unaff_i3;
  int iVar10;
  undefined4 unaff_i4;
  undefined4 unaff_i5;
  undefined4 unaff_fp;
  undefined4 unaff_i7;
  bool in_DECOMPILE_MODE;
  int in_CWP;
  undefined auStackX_0 [92];
  
  if (!in_DECOMPILE_MODE) {
    *(undefined4 *)(in_CWP * 0x40 + 0x8000) = unaff_i0;
    *(undefined4 *)((in_CWP * 0x10 + 1) * 4 + 0x8000) = unaff_i1;
    *(undefined4 *)((in_CWP * 0x10 + 2) * 4 + 0x8000) = unaff_i2;
    *(undefined4 *)((in_CWP * 0x10 + 3) * 4 + 0x8000) = unaff_i3;
    *(undefined4 *)((in_CWP * 0x10 + 4) * 4 + 0x8000) = unaff_i4;
    *(undefined4 *)((in_CWP * 0x10 + 5) * 4 + 0x8000) = unaff_i5;
    *(undefined4 *)((in_CWP * 0x10 + 6) * 4 + 0x8000) = unaff_fp;
    *(undefined4 *)((in_CWP * 0x10 + 7) * 4 + 0x8000) = unaff_i7;
    *(undefined4 *)((in_CWP * 0x10 + 8) * 4 + 0x8000) = unaff_l0;
    *(undefined4 *)((in_CWP * 0x10 + 9) * 4 + 0x8000) = unaff_l1;
    *(undefined4 *)((in_CWP * 0x10 + 10) * 4 + 0x8000) = unaff_l3;
    *(undefined4 *)((in_CWP * 0x10 + 0xb) * 4 + 0x8000) = unaff_l3;
    *(undefined4 *)((in_CWP * 0x10 + 0xc) * 4 + 0x8000) = unaff_l4;
    *(undefined4 *)((in_CWP * 0x10 + 0xd) * 4 + 0x8000) = unaff_l5;
    *(undefined4 *)((in_CWP * 0x10 + 0xe) * 4 + 0x8000) = unaff_l6;
    *(undefined4 *)((in_CWP * 0x10 + 0xf) * 4 + 0x8000) = unaff_l7;
  }
  iVar7 = 0;
  iVar10 = *(int *)((int)register0x00000038 + 0x5c);
  iVar3 = param_6 >> 8;
  iVar9 = iVar10 >> 8;
  if (param_4 == 1) {
    if (param_5 == 1) {
      iVar10 = param_3 - 1;
      if (iVar10 != -1) {
        bVar1 = *param_1;
        do {
          iVar5 = (int)*(sword *)(_audio_muLaw + (uint)bVar1 * 2);
          param_1 = param_1 + 1;
          umul(iVar5,(iVar3 + iVar9) / 2);
          iVar5 = iVar5 >> 7;
          if (iVar5 < 0x8000) {
            if (iVar5 < -0x8000) {
              *(undefined *)param_2 = 0;
              goto loc_F00E1B30;
            }
            uVar6 = (undefined)iVar5;
            _audio_shortToMulaw();
            *(undefined *)param_2 = uVar6;
          }
          else {
            *(undefined *)param_2 = 0x80;
loc_F00E1B30:
            iVar7 = iVar7 + 1;
          }
          param_2 = (undefined2 *)((int)param_2 + 1);
          iVar10 = iVar10 + -1;
          if (iVar10 == -1) break;
          bVar1 = *param_1;
        } while( true );
      }
    }
    else if ((param_5 == 2) && (iVar10 = (param_3 >> 1) - 1, iVar10 != -1)) {
      bVar1 = *param_1;
      do {
        iVar5 = (int)*(sword *)(_audio_muLaw + (uint)bVar1 * 2);
        umul(iVar5,iVar3);
        iVar5 = iVar5 >> 7;
        if (iVar5 < 0x8000) {
          if (iVar5 < -0x8000) {
            *(undefined *)param_2 = 0;
            goto loc_F00E1BC0;
          }
          uVar6 = (undefined)iVar5;
          _audio_shortToMulaw();
          *(undefined *)param_2 = uVar6;
        }
        else {
          *(undefined *)param_2 = 0x80;
loc_F00E1BC0:
          iVar7 = iVar7 + 1;
        }
        puVar8 = (undefined *)((int)param_2 + 1);
        iVar5 = (int)*(sword *)(_audio_muLaw + (uint)param_1[1] * 2);
        param_1 = param_1 + 2;
        umul(iVar5,iVar9);
        iVar5 = iVar5 >> 7;
        if (iVar5 < 0x8000) {
          if (iVar5 < -0x8000) {
            *puVar8 = 0;
            goto loc_F00E1C18;
          }
          uVar6 = (undefined)iVar5;
          _audio_shortToMulaw();
          *puVar8 = uVar6;
        }
        else {
          *puVar8 = 0x80;
loc_F00E1C18:
          iVar7 = iVar7 + 1;
        }
        param_2 = param_2 + 1;
        iVar10 = iVar10 + -1;
        if (iVar10 == -1) break;
        bVar1 = *param_1;
      } while( true );
    }
  }
  else {
    if (param_4 < 2) {
      if (param_4 == 0) {
        if (param_5 == 1) {
          iVar9 = (param_3 >> 1) - 1;
          if (iVar9 != -1) {
            sVar2 = *(sword *)param_1;
            do {
              iVar3 = (int)sVar2;
              umul(iVar3,(param_6 + iVar10) / 2);
              iVar3 = iVar3 >> 0xf;
              param_1 = param_1 + 2;
              if (iVar3 < 0x8000) {
                if (iVar3 < -0x8000) {
                  *param_2 = 0x8000;
                  goto loc_F00E18DC;
                }
                *param_2 = (sword)iVar3;
              }
              else {
                *param_2 = 0x7fff;
loc_F00E18DC:
                iVar7 = iVar7 + 1;
              }
              param_2 = param_2 + 1;
              iVar9 = iVar9 + -1;
              if (iVar9 == -1) break;
              sVar2 = *(sword *)param_1;
            } while( true );
          }
        }
        else {
          param_3 = param_3 >> 2;
          if (param_5 == 2) {
            while (param_3 = param_3 - 1, param_3 != 0xffffffff) {
              uVar4 = (uint)*(sword *)param_1;
              umul(uVar4,param_6);
              *param_2 = (sword)(uVar4 >> 0xf);
              uVar4 = (uint)*(sword *)(param_1 + 2);
              umul(uVar4,iVar10);
              param_1 = param_1 + 4;
              param_2[1] = (sword)(uVar4 >> 0xf);
              param_2 = param_2 + 2;
            }
          }
        }
        goto locret_F00E1C50;
      }
    }
    else if (param_4 == 3) {
      if (param_5 == 1) {
        iVar10 = param_3 - 1;
        if (iVar10 != -1) {
          bVar1 = *param_1;
          do {
            iVar5 = (int)(char)bVar1;
            umul(iVar5,(iVar3 + iVar9) / 2);
            iVar5 = iVar5 >> 7;
            param_1 = param_1 + 1;
            if (iVar5 < 0x80) {
              if (iVar5 < -0x80) {
                *(undefined *)param_2 = 0x80;
                goto loc_F00E19CC;
              }
              *(char *)param_2 = (char)iVar5;
            }
            else {
              *(undefined *)param_2 = 0x7f;
loc_F00E19CC:
              iVar7 = iVar7 + 1;
            }
            param_2 = (undefined2 *)((int)param_2 + 1);
            iVar10 = iVar10 + -1;
            if (iVar10 == -1) break;
            bVar1 = *param_1;
          } while( true );
        }
      }
      else if ((param_5 == 2) && (iVar10 = (param_3 >> 1) - 1, iVar10 != -1)) {
        bVar1 = *param_1;
        do {
          iVar5 = (int)(char)bVar1;
          umul(iVar5,iVar3);
          iVar5 = iVar5 >> 7;
          if (iVar5 < 0x80) {
            if (iVar5 < -0x80) {
              *(undefined *)param_2 = 0x80;
              goto loc_F00E1A38;
            }
            *(char *)param_2 = (char)iVar5;
          }
          else {
            *(undefined *)param_2 = 0x7f;
loc_F00E1A38:
            iVar7 = iVar7 + 1;
          }
          puVar8 = (undefined *)((int)param_2 + 1);
          iVar5 = (int)(char)param_1[1];
          umul(iVar5,iVar9);
          iVar5 = iVar5 >> 7;
          param_1 = param_1 + 2;
          if (iVar5 < 0x80) {
            if (iVar5 < -0x80) {
              *puVar8 = 0x80;
              goto loc_F00E1A7C;
            }
            *puVar8 = (char)iVar5;
          }
          else {
            *puVar8 = 0x7f;
loc_F00E1A7C:
            iVar7 = iVar7 + 1;
          }
          param_2 = param_2 + 1;
          iVar10 = iVar10 + -1;
          if (iVar10 == -1) break;
          bVar1 = *param_1;
        } while( true );
      }
      goto locret_F00E1C50;
    }
    _IOLog(aAudioUnrecogni_4);
  }
locret_F00E1C50:
  return CONCAT44(param_2,iVar7);
}

