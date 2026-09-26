
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
  undefined (*pauVar1) [13];
  undefined (*pauVar2) [13];
  undefined4 uVar3;
  undefined4 unaff_l0;
  uint uVar4;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  uint uVar5;
  undefined4 unaff_l4;
  int iVar6;
  undefined4 unaff_l5;
  undefined4 uVar7;
  undefined4 unaff_l6;
  undefined4 uVar8;
  undefined4 unaff_l7;
  undefined4 uVar9;
  undefined4 unaff_i0;
  int iVar10;
  int iVar11;
  undefined4 unaff_i1;
  int iVar12;
  undefined4 unaff_i2;
  int iVar13;
  undefined4 unaff_i3;
  undefined4 uVar14;
  undefined4 unaff_i4;
  uint uVar15;
  undefined4 unaff_i5;
  int iVar16;
  undefined4 unaff_fp;
  undefined4 unaff_i7;
  bool bVar17;
  bool bVar18;
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
  uVar15 = 0;
  uVar5 = 0;
  iVar16 = 0;
  iVar13 = -1;
  iVar10 = 0;
  uVar9 = 0;
  uVar7 = 0;
  iVar6 = *(int *)((int)register0x00000038 + -0x34);
  uVar8 = 0;
  uVar3 = *(undefined4 *)(iVar6 + 0xc);
  *(undefined4 *)((int)register0x00000038 + -0x44) = 0;
  uVar14 = *(undefined4 *)(iVar6 + 0x1c);
  *(undefined4 *)((int)register0x00000038 + -0x4c) = 0;
  pauVar1 = paAudiochannel;
  _objc_msgSend(paAudiochannel,paStreamforuserp,uVar3);
  uVar3 = paChannel;
  *(undefined4 *)((int)register0x00000038 + -0x54) = 0;
  if (*(int *)(iVar6 + 0x14) == 1) {
    __NXAudioStreamInfo();
    _audio_snd_reply_ret_samples
              (param_2,*(undefined4 *)(iVar6 + 0x10),
               *(undefined4 *)((int)register0x00000038 + -0x14),
               *(undefined4 *)((int)register0x00000038 + -0x18));
  }
  else {
    iVar12 = *(int *)(iVar6 + 4) + -0x28;
    *(int *)((int)register0x00000038 + -0x1c) = iVar6 + 0x28;
    iVar11 = iVar10;
    if (0 < iVar12) {
      iVar10 = *(int *)((int)register0x00000038 + -0x1c);
      do {
        switch(*(undefined4 *)(iVar10 + 4)) {
        case :
          iVar12 = iVar12 + -0x28;
          *(int *)((int)register0x00000038 + -0x1c) =
               *(int *)((int)register0x00000038 + -0x1c) + 0x28;
          if ((iVar16 == 0) && (iVar13 == 1)) {
            iVar16 = 0x67;
          }
          iVar13 = 0;
          break;
        case :
          iVar10 = (*(uint *)(*(int *)((int)register0x00000038 + -0x1c) + 0x1c) >> 4 & 0xfff) + 0x20
          ;
          *(int *)((int)register0x00000038 + -0x1c) =
               *(int *)((int)register0x00000038 + -0x1c) + iVar10;
          iVar12 = iVar12 - iVar10;
          break;
        case :
          iVar10 = *(int *)((int)register0x00000038 + -0x1c);
          iVar11 = *(int *)(iVar10 + 0xc);
          uVar9 = *(undefined4 *)(iVar10 + 0x10);
          *(int *)((int)register0x00000038 + -0x1c) = iVar10 + 0x18;
          _objc_msgSend(pauVar1,uVar3);
          __NXAudioGetBufferOptions();
          _objc_msgSend(pauVar1,uVar3);
          iVar12 = iVar12 + -0x18;
          goto loc_F00DF544;
        case :
          iVar12 = iVar12 + -0x10;
          uVar4 = *(uint *)(*(int *)((int)register0x00000038 + -0x1c) + 0xc);
          *(int *)((int)register0x00000038 + -0x1c) =
               *(int *)((int)register0x00000038 + -0x1c) + 0x10;
          uVar15 = uVar15 | uVar4;
          break;
        case :
          *(int *)((int)register0x00000038 + -0x1c) =
               *(int *)((int)register0x00000038 + -0x1c) + 0x10;
          _objc_msgSend(pauVar1,uVar3);
          __NXAudioGetBufferOptions();
          _objc_msgSend(pauVar1,uVar3);
          iVar12 = iVar12 + -0x10;
loc_F00DF544:
          __NXAudioSetBufferOptions();
          break;
        case :
          iVar10 = *(int *)((int)register0x00000038 + -0x1c);
          *(undefined4 *)((int)register0x00000038 + -0x44) = *(undefined4 *)(iVar10 + 0x10);
          *(undefined4 *)((int)register0x00000038 + -0x54) = 1;
          iVar12 = iVar12 + -0x18;
          uVar8 = *(undefined4 *)(iVar10 + 0xc);
          *(undefined4 *)((int)register0x00000038 + -0x4c) = *(undefined4 *)(iVar10 + 0x14);
          *(int *)((int)register0x00000038 + -0x1c) = iVar10 + 0x18;
          break;
        :
          iVar16 = 0x66;
          iVar12 = 0;
        }
        iVar10 = *(int *)((int)register0x00000038 + -0x1c);
      } while (0 < iVar12);
    }
    iVar10 = iVar16;
    if (iVar10 == 0) {
      *(undefined4 *)((int)register0x00000038 + -0xc) = 0;
      *(undefined4 *)((int)register0x00000038 + -0x10) = 0;
      if ((uVar15 & 2) != 0) {
        *(undefined4 *)((int)register0x00000038 + -0x30) = 0;
        *(undefined4 *)((int)register0x00000038 + -0x2c) = 0;
        __NXAudioStreamControl(pauVar1,2,(undefined *)((int)register0x00000038 + -0x30));
      }
      if ((uVar15 & 1) != 0) {
        *(undefined4 *)((int)register0x00000038 + -0x30) =
             *(undefined4 *)((int)register0x00000038 + -0x10);
        *(undefined4 *)((int)register0x00000038 + -0x2c) =
             *(undefined4 *)((int)register0x00000038 + -0xc);
        __NXAudioStreamControl(pauVar1,3,(undefined *)((int)register0x00000038 + -0x30));
      }
      if ((uVar15 & 4) != 0) {
        *(undefined4 *)((int)register0x00000038 + -0x30) =
             *(undefined4 *)((int)register0x00000038 + -0x10);
        *(undefined4 *)((int)register0x00000038 + -0x2c) =
             *(undefined4 *)((int)register0x00000038 + -0xc);
        __NXAudioStreamControl(pauVar1,0,(undefined *)((int)register0x00000038 + -0x30));
      }
      param_2 = *(int *)(*(int *)((int)register0x00000038 + -0x34) + 4) + -0x28;
      *(int *)((int)register0x00000038 + -0x1c) = iVar6 + 0x28;
      if (0 < param_2) {
        iVar16 = *(int *)((int)register0x00000038 + -0x1c);
        do {
          iVar6 = 0;
          switch(*(undefined4 *)(iVar16 + 4)) {
          case :
            iVar16 = *(int *)((int)register0x00000038 + -0x1c);
            uVar5 = *(uint *)(iVar16 + 0xc);
            iVar6 = *(int *)(iVar16 + 0x20);
            param_2 = param_2 + -0x28;
            uVar7 = *(undefined4 *)(iVar16 + 0x14);
            *(undefined4 *)((int)register0x00000038 + -0x3c) = *(undefined4 *)(iVar16 + 0x24);
            iVar16 = iVar16 + 0x28;
            break;
          case :
            iVar16 = *(int *)((int)register0x00000038 + -0x1c);
            uVar5 = *(uint *)(iVar16 + 0xc);
            iVar6 = *(int *)(iVar16 + 0x10);
            uVar7 = *(undefined4 *)(iVar16 + 0x18);
            param_2 = param_2 + -0x20;
            iVar16 = iVar16 + 0x20;
            break;
          case :
            param_2 = param_2 + -0x18;
            iVar16 = *(int *)((int)register0x00000038 + -0x1c) + 0x18;
            break;
          case :
          case :
            param_2 = param_2 + -0x10;
            iVar16 = *(int *)((int)register0x00000038 + -0x1c) + 0x10;
            break;
          case :
            param_2 = param_2 + -0x18;
            iVar16 = *(int *)((int)register0x00000038 + -0x1c) + 0x18;
            break;
          :
            goto def_F00DF704;
          }
          *(int *)((int)register0x00000038 + -0x1c) = iVar16;
def_F00DF704:
          if (iVar6 != 0) {
            uVar4 = uVar5 & 1;
            if ((iVar13 == 0) && ((uVar5 & 2) != 0)) {
              uVar4 = uVar4 | 2;
            }
            if ((uVar5 & 8) != 0) {
              uVar4 = uVar4 | 4;
            }
            if ((uVar5 & 0x10) != 0) {
              uVar4 = uVar4 | 8;
            }
            if ((uVar5 & 4) != 0) {
              uVar4 = uVar4 | 0x10;
            }
            if ((uVar5 & 0x20) != 0) {
              uVar4 = uVar4 | 0x20;
            }
            if (iVar13 == 0) {
              if (*(int *)((int)register0x00000038 + -0x54) == 0) {
                uVar8 = 2;
                pauVar2 = pauVar1;
                _objc_msgSend(pauVar1,paType);
                if (pauVar2 == (undefined (*) [13])0x3) {
                  uVar8 = 1;
                }
                __NXAudioPlayStream(pauVar1,*(undefined4 *)((int)register0x00000038 + -0x3c),iVar6,
                                    uVar14,2,uVar8,0x8000,0x8000,uVar9,iVar11,uVar7,uVar4);
              }
              else {
                sub_F00DF2A4(0,pauVar1,uVar8,*(undefined4 *)((int)register0x00000038 + -0x44),
                             *(undefined4 *)((int)register0x00000038 + -0x4c),uVar9,iVar11);
                __NXAudioPlayStreamData
                          (pauVar1,*(undefined4 *)((int)register0x00000038 + -0x3c),iVar6,uVar14,
                           uVar7,uVar4);
              }
            }
            else if (*(int *)((int)register0x00000038 + -0x54) == 0) {
              __NXAudioRecordStream(pauVar1,iVar6,uVar14,uVar9,iVar11,uVar7,uVar4);
            }
            else {
              sub_F00DF2A4(iVar13,pauVar1,uVar8,*(undefined4 *)((int)register0x00000038 + -0x44),
                           *(undefined4 *)((int)register0x00000038 + -0x4c),uVar9,iVar11);
              __NXAudioRecordStreamData(pauVar1,iVar6,uVar14,uVar7,uVar4);
            }
          }
          iVar16 = *(int *)((int)register0x00000038 + -0x1c);
        } while (0 < param_2);
      }
      if ((uVar15 & 8) != 0) {
        *(undefined4 *)((int)register0x00000038 + -0x30) =
             *(undefined4 *)((int)register0x00000038 + -0x10);
        *(undefined4 *)((int)register0x00000038 + -0x2c) =
             *(undefined4 *)((int)register0x00000038 + -0xc);
        __NXAudioStreamControl(pauVar1,1,(undefined *)((int)register0x00000038 + -0x30));
      }
      iVar10 = 100;
    }
    else {
      param_2 = *(int *)(*(int *)((int)register0x00000038 + -0x34) + 4) + -0x28;
      *(int *)((int)register0x00000038 + -0x1c) = iVar6 + 0x28;
      if (0 < param_2) {
        iVar16 = *(int *)((int)register0x00000038 + -0x1c);
        do {
          switch(*(undefined4 *)(iVar16 + 4)) {
          case :
            *(int *)((int)register0x00000038 + -0x1c) =
                 *(int *)((int)register0x00000038 + -0x1c) + 0x28;
            _IOVmTaskSelf();
            param_2 = param_2 + -0x28;
            _vm_deallocate_EXTERNAL();
            bVar18 = param_2 == 0;
            bVar17 = param_2 < 0;
            goto def_F00DF5B0;
          case :
            param_2 = param_2 + -0x20;
            iVar16 = *(int *)((int)register0x00000038 + -0x1c) + 0x20;
            break;
          case :
            param_2 = param_2 + -0x18;
            iVar16 = *(int *)((int)register0x00000038 + -0x1c) + 0x18;
            break;
          case :
          case :
            param_2 = param_2 + -0x10;
            iVar16 = *(int *)((int)register0x00000038 + -0x1c) + 0x10;
            break;
          case :
            param_2 = param_2 + -0x18;
            iVar16 = *(int *)((int)register0x00000038 + -0x1c) + 0x18;
            break;
          :
            bVar18 = param_2 == 0;
            bVar17 = param_2 < 0;
            goto def_F00DF5B0;
          }
          *(int *)((int)register0x00000038 + -0x1c) = iVar16;
          bVar18 = param_2 == 0;
          bVar17 = param_2 < 0;
def_F00DF5B0:
          iVar16 = *(int *)((int)register0x00000038 + -0x1c);
        } while (!bVar18 && !bVar17);
      }
    }
  }
  return CONCAT44(param_2,iVar10);
}
