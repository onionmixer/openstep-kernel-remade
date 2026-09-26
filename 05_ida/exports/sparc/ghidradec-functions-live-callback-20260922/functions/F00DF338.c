
/* WARNING: Removing unreachable block (ram,0xf00df3a4) */
/* WARNING: Removing unreachable block (ram,0xf00df5d8) */
/* WARNING: Removing unreachable block (ram,0xf00df830) */
/* WARNING: Removing unreachable block (ram,0xf00df890) */
/* WARNING: Removing unreachable block (ram,0xf00df8d8) */
/* WARNING: Removing unreachable block (ram,0xf00df900) */
/* WARNING: Removing unreachable block (ram,0xf00df694) */
/* WARNING: Removing unreachable block (ram,0xf00df544) */
/* WARNING: Removing unreachable block (ram,0xf00df4e4) */
/* WARNING: Removing unreachable block (ram,0xf00df530) */
/* WARNING: Removing unreachable block (ram,0xf00df518) */
/* WARNING: Removing unreachable block (ram,0xf00df524) */
/* WARNING: Removing unreachable block (ram,0xf00df4d8) */
/* WARNING: Removing unreachable block (ram,0xf00df4f0) */
/* WARNING: Removing unreachable block (ram,0xf00df66c) */
/* WARNING: Removing unreachable block (ram,0xf00df6bc) */
/* WARNING: Removing unreachable block (ram,0xf00df8c0) */
/* WARNING: Removing unreachable block (ram,0xf00df84c) */
/* WARNING: Removing unreachable block (ram,0xf00df814) */
/* WARNING: Removing unreachable block (ram,0xf00df934) */
/* WARNING: Removing unreachable block (ram,0xf00df5e8) */
/* WARNING: Removing unreachable block (ram,0xf00df3b8) */
/* WARNING: Removing unreachable block (ram,0xf00df384) */

undefined8 sub_F00DF338(undefined4 param_1,int param_2)

{
  undefined8 *puVar1;
  undefined (*pauVar2) [13];
  undefined (*pauVar3) [13];
  undefined4 uVar4;
  undefined4 unaff_l0;
  uint uVar5;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  uint uVar6;
  undefined4 unaff_l4;
  int iVar7;
  undefined4 unaff_l5;
  undefined4 uVar8;
  undefined4 unaff_l6;
  undefined4 uVar9;
  undefined4 unaff_l7;
  undefined4 uVar10;
  undefined4 unaff_i0;
  int iVar11;
  int iVar12;
  undefined4 unaff_i1;
  int iVar13;
  undefined4 unaff_i2;
  int iVar14;
  undefined4 unaff_i3;
  undefined4 uVar15;
  undefined4 unaff_i4;
  uint uVar16;
  undefined4 unaff_i5;
  int iVar17;
  undefined4 unaff_fp;
  undefined4 unaff_i7;
  bool bVar18;
  bool bVar19;
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
  *(undefined4 *)((int)register0x00000038 + -0x34) = param_1;
  *(undefined4 *)((int)register0x00000038 + -0x3c) = 0;
  uVar16 = 0;
  uVar6 = 0;
  iVar17 = 0;
  iVar14 = -1;
  iVar11 = 0;
  uVar10 = 0;
  uVar8 = 0;
  iVar7 = *(int *)((int)register0x00000038 + -0x34);
  uVar9 = 0;
  uVar4 = *(undefined4 *)(iVar7 + 0xc);
  *(undefined4 *)((int)register0x00000038 + -0x44) = 0;
  uVar15 = *(undefined4 *)(iVar7 + 0x1c);
  *(undefined4 *)((int)register0x00000038 + -0x4c) = 0;
  pauVar2 = paAudiochannel;
  _objc_msgSend(paAudiochannel,paStreamforuserp,uVar4);
  puVar1 = paChannel;
  *(undefined4 *)((int)register0x00000038 + -0x54) = 0;
  if (*(int *)(iVar7 + 0x14) == 1) {
    __NXAudioStreamInfo();
    _audio_snd_reply_ret_samples
              (param_2,*(undefined4 *)(iVar7 + 0x10),
               *(undefined4 *)((int)register0x00000038 + -0x14),
               *(undefined4 *)((int)register0x00000038 + -0x18));
  }
  else {
    iVar13 = *(int *)(iVar7 + 4) + -0x28;
    *(int *)((int)register0x00000038 + -0x1c) = iVar7 + 0x28;
    iVar12 = iVar11;
    if (0 < iVar13) {
      iVar11 = *(int *)((int)register0x00000038 + -0x1c);
      do {
        switch(*(undefined4 *)(iVar11 + 4)) {
        case :
          iVar13 = iVar13 + -0x28;
          *(int *)((int)register0x00000038 + -0x1c) =
               *(int *)((int)register0x00000038 + -0x1c) + 0x28;
          if ((iVar17 == 0) && (iVar14 == 1)) {
            iVar17 = 0x67;
          }
          iVar14 = 0;
          break;
        case :
          iVar11 = (*(uint *)(*(int *)((int)register0x00000038 + -0x1c) + 0x1c) >> 4 & 0xfff) + 0x20
          ;
          *(int *)((int)register0x00000038 + -0x1c) =
               *(int *)((int)register0x00000038 + -0x1c) + iVar11;
          iVar13 = iVar13 - iVar11;
          break;
        case :
          iVar11 = *(int *)((int)register0x00000038 + -0x1c);
          iVar12 = *(int *)(iVar11 + 0xc);
          uVar10 = *(undefined4 *)(iVar11 + 0x10);
          *(int *)((int)register0x00000038 + -0x1c) = iVar11 + 0x18;
          _objc_msgSend(pauVar2,puVar1);
          __NXAudioGetBufferOptions();
          _objc_msgSend(pauVar2,puVar1);
          iVar13 = iVar13 + -0x18;
          goto loc_F00DF544;
        case :
          iVar13 = iVar13 + -0x10;
          uVar5 = *(uint *)(*(int *)((int)register0x00000038 + -0x1c) + 0xc);
          *(int *)((int)register0x00000038 + -0x1c) =
               *(int *)((int)register0x00000038 + -0x1c) + 0x10;
          uVar16 = uVar16 | uVar5;
          break;
        case :
          *(int *)((int)register0x00000038 + -0x1c) =
               *(int *)((int)register0x00000038 + -0x1c) + 0x10;
          _objc_msgSend(pauVar2,puVar1);
          __NXAudioGetBufferOptions();
          _objc_msgSend(pauVar2,puVar1);
          iVar13 = iVar13 + -0x10;
loc_F00DF544:
          __NXAudioSetBufferOptions();
          break;
        case :
          iVar11 = *(int *)((int)register0x00000038 + -0x1c);
          *(undefined4 *)((int)register0x00000038 + -0x44) = *(undefined4 *)(iVar11 + 0x10);
          *(undefined4 *)((int)register0x00000038 + -0x54) = 1;
          iVar13 = iVar13 + -0x18;
          uVar9 = *(undefined4 *)(iVar11 + 0xc);
          *(undefined4 *)((int)register0x00000038 + -0x4c) = *(undefined4 *)(iVar11 + 0x14);
          *(int *)((int)register0x00000038 + -0x1c) = iVar11 + 0x18;
          break;
        :
          iVar17 = 0x66;
          iVar13 = 0;
        }
        iVar11 = *(int *)((int)register0x00000038 + -0x1c);
      } while (0 < iVar13);
    }
    iVar11 = iVar17;
    if (iVar11 == 0) {
      *(undefined4 *)((int)register0x00000038 + -0xc) = 0;
      *(undefined4 *)((int)register0x00000038 + -0x10) = 0;
      if ((uVar16 & 2) != 0) {
        *(undefined4 *)((int)register0x00000038 + -0x30) = 0;
        *(undefined4 *)((int)register0x00000038 + -0x2c) = 0;
        __NXAudioStreamControl(pauVar2,2,(undefined *)((int)register0x00000038 + -0x30));
      }
      if ((uVar16 & 1) != 0) {
        *(undefined4 *)((int)register0x00000038 + -0x30) =
             *(undefined4 *)((int)register0x00000038 + -0x10);
        *(undefined4 *)((int)register0x00000038 + -0x2c) =
             *(undefined4 *)((int)register0x00000038 + -0xc);
        __NXAudioStreamControl(pauVar2,3,(undefined *)((int)register0x00000038 + -0x30));
      }
      if ((uVar16 & 4) != 0) {
        *(undefined4 *)((int)register0x00000038 + -0x30) =
             *(undefined4 *)((int)register0x00000038 + -0x10);
        *(undefined4 *)((int)register0x00000038 + -0x2c) =
             *(undefined4 *)((int)register0x00000038 + -0xc);
        __NXAudioStreamControl(pauVar2,0,(undefined *)((int)register0x00000038 + -0x30));
      }
      param_2 = *(int *)(*(int *)((int)register0x00000038 + -0x34) + 4) + -0x28;
      *(int *)((int)register0x00000038 + -0x1c) = iVar7 + 0x28;
      if (0 < param_2) {
        iVar17 = *(int *)((int)register0x00000038 + -0x1c);
        do {
          iVar7 = 0;
          switch(*(undefined4 *)(iVar17 + 4)) {
          case :
            iVar17 = *(int *)((int)register0x00000038 + -0x1c);
            uVar6 = *(uint *)(iVar17 + 0xc);
            iVar7 = *(int *)(iVar17 + 0x20);
            param_2 = param_2 + -0x28;
            uVar8 = *(undefined4 *)(iVar17 + 0x14);
            *(undefined4 *)((int)register0x00000038 + -0x3c) = *(undefined4 *)(iVar17 + 0x24);
            iVar17 = iVar17 + 0x28;
            break;
          case :
            iVar17 = *(int *)((int)register0x00000038 + -0x1c);
            uVar6 = *(uint *)(iVar17 + 0xc);
            iVar7 = *(int *)(iVar17 + 0x10);
            uVar8 = *(undefined4 *)(iVar17 + 0x18);
            param_2 = param_2 + -0x20;
            iVar17 = iVar17 + 0x20;
            break;
          case :
            param_2 = param_2 + -0x18;
            iVar17 = *(int *)((int)register0x00000038 + -0x1c) + 0x18;
            break;
          case :
          case :
            param_2 = param_2 + -0x10;
            iVar17 = *(int *)((int)register0x00000038 + -0x1c) + 0x10;
            break;
          case :
            param_2 = param_2 + -0x18;
            iVar17 = *(int *)((int)register0x00000038 + -0x1c) + 0x18;
            break;
          :
            goto def_F00DF704;
          }
          *(int *)((int)register0x00000038 + -0x1c) = iVar17;
def_F00DF704:
          if (iVar7 != 0) {
            uVar5 = uVar6 & 1;
            if ((iVar14 == 0) && ((uVar6 & 2) != 0)) {
              uVar5 = uVar5 | 2;
            }
            if ((uVar6 & 8) != 0) {
              uVar5 = uVar5 | 4;
            }
            if ((uVar6 & 0x10) != 0) {
              uVar5 = uVar5 | 8;
            }
            if ((uVar6 & 4) != 0) {
              uVar5 = uVar5 | 0x10;
            }
            if ((uVar6 & 0x20) != 0) {
              uVar5 = uVar5 | 0x20;
            }
            if (iVar14 == 0) {
              if (*(int *)((int)register0x00000038 + -0x54) == 0) {
                uVar9 = 2;
                pauVar3 = pauVar2;
                _objc_msgSend(pauVar2,paType);
                if (pauVar3 == (undefined (*) [13])0x3) {
                  uVar9 = 1;
                }
                __NXAudioPlayStream(pauVar2,*(undefined4 *)((int)register0x00000038 + -0x3c),iVar7,
                                    uVar15,2,uVar9,0x8000,0x8000,uVar10,iVar12,uVar8,uVar5);
              }
              else {
                sub_F00DF2A4(0,pauVar2,uVar9,*(undefined4 *)((int)register0x00000038 + -0x44),
                             *(undefined4 *)((int)register0x00000038 + -0x4c),uVar10,iVar12);
                __NXAudioPlayStreamData
                          (pauVar2,*(undefined4 *)((int)register0x00000038 + -0x3c),iVar7,uVar15,
                           uVar8,uVar5);
              }
            }
            else if (*(int *)((int)register0x00000038 + -0x54) == 0) {
              __NXAudioRecordStream(pauVar2,iVar7,uVar15,uVar10,iVar12,uVar8,uVar5);
            }
            else {
              sub_F00DF2A4(iVar14,pauVar2,uVar9,*(undefined4 *)((int)register0x00000038 + -0x44),
                           *(undefined4 *)((int)register0x00000038 + -0x4c),uVar10,iVar12);
              __NXAudioRecordStreamData(pauVar2,iVar7,uVar15,uVar8,uVar5);
            }
          }
          iVar17 = *(int *)((int)register0x00000038 + -0x1c);
        } while (0 < param_2);
      }
      if ((uVar16 & 8) != 0) {
        *(undefined4 *)((int)register0x00000038 + -0x30) =
             *(undefined4 *)((int)register0x00000038 + -0x10);
        *(undefined4 *)((int)register0x00000038 + -0x2c) =
             *(undefined4 *)((int)register0x00000038 + -0xc);
        __NXAudioStreamControl(pauVar2,1,(undefined *)((int)register0x00000038 + -0x30));
      }
      iVar11 = 100;
    }
    else {
      param_2 = *(int *)(*(int *)((int)register0x00000038 + -0x34) + 4) + -0x28;
      *(int *)((int)register0x00000038 + -0x1c) = iVar7 + 0x28;
      if (0 < param_2) {
        iVar17 = *(int *)((int)register0x00000038 + -0x1c);
        do {
          switch(*(undefined4 *)(iVar17 + 4)) {
          case :
            *(int *)((int)register0x00000038 + -0x1c) =
                 *(int *)((int)register0x00000038 + -0x1c) + 0x28;
            _IOVmTaskSelf();
            param_2 = param_2 + -0x28;
            _vm_deallocate_EXTERNAL();
            bVar19 = param_2 == 0;
            bVar18 = param_2 < 0;
            goto def_F00DF5B0;
          case :
            param_2 = param_2 + -0x20;
            iVar17 = *(int *)((int)register0x00000038 + -0x1c) + 0x20;
            break;
          case :
            param_2 = param_2 + -0x18;
            iVar17 = *(int *)((int)register0x00000038 + -0x1c) + 0x18;
            break;
          case :
          case :
            param_2 = param_2 + -0x10;
            iVar17 = *(int *)((int)register0x00000038 + -0x1c) + 0x10;
            break;
          case :
            param_2 = param_2 + -0x18;
            iVar17 = *(int *)((int)register0x00000038 + -0x1c) + 0x18;
            break;
          :
            bVar19 = param_2 == 0;
            bVar18 = param_2 < 0;
            goto def_F00DF5B0;
          }
          *(int *)((int)register0x00000038 + -0x1c) = iVar17;
          bVar19 = param_2 == 0;
          bVar18 = param_2 < 0;
def_F00DF5B0:
          iVar17 = *(int *)((int)register0x00000038 + -0x1c);
        } while (!bVar19 && !bVar18);
      }
    }
  }
  return CONCAT44(param_2,iVar11);
}

