/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001afbdc */

/* WARNING: Type propagation algorithm not settling */

int FUN_001afbdc(undefined ****param_1,undefined4 param_2,ushort ***param_3,ushort ***param_4,
                undefined ***param_5)

{
  undefined ****ppppuVar1;
  int iVar2;
  uint uVar3;
  undefined ***pppuVar4;
  int iVar5;
  undefined *****pppppuVar6;
  ushort ****ppppuVar7;
  ushort ****ppppuVar8;
  ushort ***pppuVar9;
  char *pcVar10;
  char *pcVar11;
  bool bVar12;
  undefined ***pppuStack_68;
  undefined ****ppppuStack_64;
  ushort ****ppppuStack_60;
  undefined ***pppuStack_5c;
  undefined ****ppppuStack_58;
  undefined ****ppppuStack_54;
  ushort ***pppuStack_50;
  ushort local_38;
  int local_30;
  undefined ****local_2c;
  undefined *local_28;
  undefined ***local_24 [4];
  undefined4 local_14;
  ushort **local_10;
  ushort **local_c;
  ushort **local_8;
  
  local_30 = -0x2c2;
  iVar2 = 0xd;
  bVar12 = true;
  pppuVar9 = param_4;
  pcVar10 = "Ev_SetScreen";
  do {
    if (iVar2 == 0) break;
    iVar2 = iVar2 + -1;
    bVar12 = *(char *)pppuVar9 == *pcVar10;
    pppuVar9 = (ushort ***)((int)pppuVar9 + 1);
    pcVar10 = pcVar10 + 1;
  } while (bVar12);
  if (bVar12) {
    if (param_5 != (undefined ***)0x7) {
      return -0x2c2;
    }
    pppuStack_50 = param_3;
    ppppuStack_54 = (undefined ****)PTR_s_evSetScreen__001f9a20;
    ppppuStack_58 = param_1;
    pppuStack_5c = (undefined ***)0x1afc22;
    iVar2 = _objc_msgSend();
    return iVar2;
  }
  iVar2 = 0xf;
  bVar12 = true;
  pppuVar9 = param_4;
  pcVar10 = "Ev_StartCursor";
  do {
    if (iVar2 == 0) break;
    iVar2 = iVar2 + -1;
    bVar12 = *(char *)pppuVar9 == *pcVar10;
    pppuVar9 = (ushort ***)((int)pppuVar9 + 1);
    pcVar10 = pcVar10 + 1;
  } while (bVar12);
  if (bVar12) {
    pppuStack_50 = (ushort ***)PTR_s_startCursor_001f9a1c;
    ppppuStack_54 = param_1;
    ppppuStack_58 = (undefined ****)0x1afc4c;
    _objc_msgSend();
    return 0;
  }
  iVar2 = 0x11;
  bVar12 = true;
  pppuVar9 = param_4;
  pcVar10 = "Ev_MousePosition";
  do {
    if (iVar2 == 0) break;
    iVar2 = iVar2 + -1;
    bVar12 = *(char *)pppuVar9 == *pcVar10;
    pppuVar9 = (ushort ***)((int)pppuVar9 + 1);
    pcVar10 = pcVar10 + 1;
  } while (bVar12);
  if (bVar12) {
    if (param_5 != (undefined ***)0x2) {
      return -0x2c2;
    }
    local_14 = (ushort **)
               ((uint)*(ushort *)param_3 | CONCAT22(0x1d,*(ushort *)(param_3 + 1)) << 0x10);
    pppuStack_50 = (ushort ***)PTR_s_lock_001f9220;
    ppppuStack_54 = (undefined ****)param_1[0x44];
    ppppuStack_58 = (undefined ****)0x1afca8;
    _objc_msgSend();
    ppppuStack_58 = (undefined ****)&local_14;
    pppuStack_5c = (undefined ***)PTR_s_setCursorPosition__001f9a18;
    pppppuVar6 = (undefined *****)&ppppuStack_60;
    ppppuStack_60 = (ushort ****)param_1;
    ppppuStack_64 = (undefined ****)0x1afcbc;
    _objc_msgSend();
    goto LAB_001b01e6;
  }
  iVar2 = 0x15;
  bVar12 = true;
  pppuVar9 = param_4;
  pcVar10 = "Evs_SetWaitThreshold";
  do {
    if (iVar2 == 0) break;
    iVar2 = iVar2 + -1;
    bVar12 = *(char *)pppuVar9 == *pcVar10;
    pppuVar9 = (ushort ***)((int)pppuVar9 + 1);
    pcVar10 = pcVar10 + 1;
  } while (bVar12);
  if (bVar12) {
    uVar3 = 0;
    do {
      local_24[uVar3] = (undefined ***)param_3[uVar3];
      uVar3 = uVar3 + 1;
    } while (uVar3 < 2);
    local_24[2] = local_24[0];
    local_24[3] = local_24[1];
    pppuStack_50 = (ushort ***)PTR_s_lock_001f9220;
    ppppuStack_54 = (undefined ****)param_1[0x44];
    ppppuStack_58 = (undefined ****)0x1afd0e;
    _objc_msgSend();
    if (*(char *)((int)param_1 + 0x1d2) != '\0') {
      local_38 = (ushort)(byte)((uint)local_24[2] >> 0x18) | (ushort)((int)local_24[3] << 8);
      *(ushort *)(param_1[0x5a] + 0x13) = local_38;
    }
    pppuStack_50 = (ushort ***)PTR_s_unlock_001f9474;
    ppppuStack_54 = (undefined ****)param_1[0x44];
    ppppuVar8 = (ushort ****)&ppppuStack_54;
    goto LAB_001b01f4;
  }
  iVar2 = 0x13;
  bVar12 = true;
  pppuVar9 = param_4;
  pcVar10 = "Evs_SetWaitSustain";
  do {
    if (iVar2 == 0) break;
    iVar2 = iVar2 + -1;
    bVar12 = *(char *)pppuVar9 == *pcVar10;
    pppuVar9 = (ushort ***)((int)pppuVar9 + 1);
    pcVar10 = pcVar10 + 1;
  } while (bVar12);
  if (bVar12) {
    pppuStack_50 = (ushort ***)PTR_s_lock_001f9220;
    ppppuStack_54 = (undefined ****)param_1[0x44];
    ppppuStack_58 = (undefined ****)0x1afd7e;
    _objc_msgSend();
    uVar3 = 0;
    do {
      local_24[uVar3] = (undefined ***)param_3[uVar3];
      uVar3 = uVar3 + 1;
    } while (uVar3 < 2);
    param_1[0x75] = local_24[0];
    param_1[0x76] = local_24[1];
    ppppuVar7 = &pppuStack_50;
    pppuStack_50 = (ushort ***)PTR_s_unlock_001f9474;
LAB_001b01ed:
    param_1 = (undefined ****)param_1[0x44];
  }
  else {
    iVar2 = 0x19;
    bVar12 = true;
    pppuVar9 = param_4;
    pcVar10 = "Evs_SetWaitFrameInterval";
    do {
      if (iVar2 == 0) break;
      iVar2 = iVar2 + -1;
      bVar12 = *(char *)pppuVar9 == *pcVar10;
      pppuVar9 = (ushort ***)((int)pppuVar9 + 1);
      pcVar10 = pcVar10 + 1;
    } while (bVar12);
    if (bVar12) {
      pppuStack_50 = (ushort ***)PTR_s_lock_001f9220;
      ppppuStack_54 = (undefined ****)param_1[0x44];
      ppppuStack_58 = (undefined ****)0x1afde2;
      _objc_msgSend();
      uVar3 = 0;
      do {
        local_24[uVar3] = (undefined ***)param_3[uVar3];
        uVar3 = uVar3 + 1;
      } while (uVar3 < 2);
      param_1[0x79] = local_24[0];
      param_1[0x7a] = local_24[1];
      pppuStack_50 = (ushort ***)PTR_s_unlock_001f9474;
      ppppuStack_54 = (undefined ****)param_1[0x44];
      ppppuVar8 = (ushort ****)&ppppuStack_54;
      goto LAB_001b01f4;
    }
    iVar2 = 0x12;
    bVar12 = true;
    pppuVar9 = param_4;
    pcVar10 = "Evs_SetBrightness";
    do {
      if (iVar2 == 0) break;
      iVar2 = iVar2 + -1;
      bVar12 = *(char *)pppuVar9 == *pcVar10;
      pppuVar9 = (ushort ***)((int)pppuVar9 + 1);
      pcVar10 = pcVar10 + 1;
    } while (bVar12);
    if (bVar12) {
      pppuStack_50 = (ushort ***)PTR_s_lock_001f9220;
      ppppuStack_54 = (undefined ****)param_1[0x44];
      ppppuStack_58 = (undefined ****)0x1afe4e;
      _objc_msgSend();
      ppppuStack_58 = (undefined ****)*param_3;
      pppuStack_5c = (undefined ***)PTR_s_setBrightness__001f9a14;
      pppppuVar6 = (undefined *****)&ppppuStack_60;
      ppppuStack_60 = (ushort ****)param_1;
      ppppuStack_64 = (undefined ****)0x1afe64;
      _objc_msgSend();
      goto LAB_001b01e6;
    }
    iVar2 = 0x13;
    bVar12 = true;
    pppuVar9 = param_4;
    pcVar10 = "Evs_SetAttenuation";
    do {
      if (iVar2 == 0) break;
      iVar2 = iVar2 + -1;
      bVar12 = *(char *)pppuVar9 == *pcVar10;
      pppuVar9 = (ushort ***)((int)pppuVar9 + 1);
      pcVar10 = pcVar10 + 1;
    } while (bVar12);
    if (bVar12) {
      pppuStack_50 = (ushort ***)PTR_s_lock_001f9220;
      ppppuStack_54 = (undefined ****)param_1[0x44];
      ppppuStack_58 = (undefined ****)0x1afe96;
      _objc_msgSend();
      ppppuStack_58 = (undefined ****)*param_3;
      pppuStack_5c = (undefined ***)PTR_s_setUserAudioVolume__001f9a10;
      ppppuStack_60 = (ushort ****)param_1;
      ppppuStack_64 = (undefined ****)0x1afeac;
      _objc_msgSend();
      ppppuStack_64 = (undefined ****)PTR_s_unlock_001f9474;
      pppuStack_68 = param_1[0x44];
      ppppuVar8 = (ushort ****)&pppuStack_68;
      goto LAB_001b01f4;
    }
    iVar2 = 0x19;
    bVar12 = true;
    pppuVar9 = param_4;
    pcVar10 = "Evs_SetAutoDimBrightness";
    do {
      if (iVar2 == 0) break;
      iVar2 = iVar2 + -1;
      bVar12 = *(char *)pppuVar9 == *pcVar10;
      pppuVar9 = (ushort ***)((int)pppuVar9 + 1);
      pcVar10 = pcVar10 + 1;
    } while (bVar12);
    if (bVar12) {
      pppuStack_50 = (ushort ***)PTR_s_lock_001f9220;
      ppppuStack_54 = (undefined ****)param_1[0x44];
      ppppuStack_58 = (undefined ****)0x1afeea;
      _objc_msgSend();
      ppppuStack_58 = (undefined ****)*param_3;
      pppuStack_5c = (undefined ***)PTR_s_setAutoDimBrightness__001f9a0c;
      pppppuVar6 = (undefined *****)&ppppuStack_60;
      ppppuStack_60 = (ushort ****)param_1;
      ppppuStack_64 = (undefined ****)0x1aff00;
      _objc_msgSend();
LAB_001b01e6:
      ppppuVar7 = (ushort ****)((int)pppppuVar6 + -4);
      *(undefined **)((int)pppppuVar6 + -4) = PTR_s_unlock_001f9474;
      goto LAB_001b01ed;
    }
    iVar2 = 0x11;
    bVar12 = true;
    pppuVar9 = param_4;
    pcVar10 = "Evs_SetClickTime";
    do {
      if (iVar2 == 0) break;
      iVar2 = iVar2 + -1;
      bVar12 = *(char *)pppuVar9 == *pcVar10;
      pppuVar9 = (ushort ***)((int)pppuVar9 + 1);
      pcVar10 = pcVar10 + 1;
    } while (bVar12);
    if (bVar12) {
      uVar3 = 0;
      do {
        local_24[uVar3] = (undefined ***)param_3[uVar3];
        uVar3 = uVar3 + 1;
      } while (uVar3 < 2);
      local_24[2] = local_24[0];
      local_24[3] = local_24[1];
      pppuStack_50 = (ushort ***)PTR_s_lock_001f9220;
      ppppuStack_54 = (undefined ****)param_1[0x44];
      pppppuVar6 = &ppppuStack_54;
      ppppuStack_58 = (undefined ****)0x1aff52;
      _objc_msgSend();
      param_1[0x6f] = (undefined ***)((uint)local_24[2] >> 0x18 | (int)local_24[3] << 8);
      goto LAB_001b01e6;
    }
    iVar2 = 0x12;
    bVar12 = true;
    pppuVar9 = param_4;
    pcVar10 = "Evs_SetClickSpace";
    do {
      if (iVar2 == 0) break;
      iVar2 = iVar2 + -1;
      bVar12 = *(char *)pppuVar9 == *pcVar10;
      pppuVar9 = (ushort ***)((int)pppuVar9 + 1);
      pcVar10 = pcVar10 + 1;
    } while (bVar12);
    if (bVar12) {
      pppuStack_50 = (ushort ***)PTR_s_lock_001f9220;
      ppppuStack_54 = (undefined ****)param_1[0x44];
      ppppuStack_58 = (undefined ****)0x1aff9a;
      _objc_msgSend();
      *(ushort *)(param_1 + 0x6c) = *(ushort *)param_3;
      *(ushort *)((int)param_1 + 0x1b2) = *(ushort *)(param_3 + 1);
      ppppuVar7 = (ushort ****)&ppppuStack_58;
      ppppuStack_58 = (undefined ****)PTR_s_unlock_001f9474;
      goto LAB_001b01ed;
    }
    iVar2 = 0x13;
    bVar12 = true;
    pppuVar9 = param_4;
    pcVar10 = "Evs_SetAutoDimTime";
    do {
      if (iVar2 == 0) break;
      iVar2 = iVar2 + -1;
      bVar12 = *(char *)pppuVar9 == *pcVar10;
      pppuVar9 = (ushort ***)((int)pppuVar9 + 1);
      pcVar10 = pcVar10 + 1;
    } while (bVar12);
    if (bVar12) {
      uVar3 = 0;
      do {
        local_24[uVar3] = (undefined ***)param_3[uVar3];
        uVar3 = uVar3 + 1;
      } while (uVar3 < 2);
      local_24[2] = local_24[0];
      local_24[3] = local_24[1];
      pppuStack_50 = (ushort ***)PTR_s_lock_001f9220;
      ppppuStack_54 = (undefined ****)param_1[0x44];
      ppppuStack_58 = (undefined ****)0x1b0016;
      _objc_msgSend();
      pppuVar4 = (undefined ***)((uint)local_24[2] >> 0x18 | (int)local_24[3] << 8);
      param_1[0x69] = (undefined ***)((int)pppuVar4 + ((int)param_1[0x69] - (int)param_1[0x68]));
      param_1[0x68] = pppuVar4;
      ppppuStack_58 = (undefined ****)PTR_s_unlock_001f9474;
      pppuStack_5c = param_1[0x44];
      ppppuVar8 = (ushort ****)&pppuStack_5c;
      goto LAB_001b01f4;
    }
    iVar2 = 0x14;
    bVar12 = true;
    pppuVar9 = param_4;
    pcVar10 = "Evs_SetAutoDimState";
    do {
      if (iVar2 == 0) break;
      iVar2 = iVar2 + -1;
      bVar12 = *(char *)pppuVar9 == *pcVar10;
      pppuVar9 = (ushort ***)((int)pppuVar9 + 1);
      pcVar10 = pcVar10 + 1;
    } while (bVar12);
    if (bVar12) {
      pppuStack_50 = (ushort ***)PTR_s_lock_001f9220;
      ppppuStack_54 = (undefined ****)param_1[0x44];
      ppppuStack_58 = (undefined ****)0x1b0082;
      _objc_msgSend();
      ppppuStack_58 = (undefined ****)(int)*(char *)param_3;
      pppuStack_5c = (undefined ***)PTR_s_forceAutoDimState__001f9a3c;
      pppppuVar6 = (undefined *****)&ppppuStack_60;
      ppppuStack_60 = (ushort ****)param_1;
      ppppuStack_64 = (undefined ****)0x1b0099;
      _objc_msgSend();
      goto LAB_001b01e6;
    }
    iVar2 = 0xf;
    bVar12 = true;
    pppuVar9 = param_4;
    pcVar10 = "Evs_ResetMouse";
    do {
      if (iVar2 == 0) break;
      iVar2 = iVar2 + -1;
      bVar12 = *(char *)pppuVar9 == *pcVar10;
      pppuVar9 = (ushort ***)((int)pppuVar9 + 1);
      pcVar10 = pcVar10 + 1;
    } while (bVar12);
    if (bVar12) {
      ppppuVar7 = &pppuStack_50;
      pppuStack_50 = (ushort ***)PTR_s__resetMouseParameters_001f9a08;
    }
    else {
      iVar2 = 0x12;
      bVar12 = true;
      pppuVar9 = param_4;
      pcVar10 = "Evs_ResetKeyboard";
      do {
        if (iVar2 == 0) break;
        iVar2 = iVar2 + -1;
        bVar12 = *(char *)pppuVar9 == *pcVar10;
        pppuVar9 = (ushort ***)((int)pppuVar9 + 1);
        pcVar10 = pcVar10 + 1;
      } while (bVar12);
      if (!bVar12) {
        iVar2 = 0xf;
        bVar12 = true;
        pppuVar9 = param_4;
        pcVar10 = "Ev_LLPostEvent";
        do {
          if (iVar2 == 0) break;
          iVar2 = iVar2 + -1;
          bVar12 = *(char *)pppuVar9 == *pcVar10;
          pppuVar9 = (ushort ***)((int)pppuVar9 + 1);
          pcVar10 = pcVar10 + 1;
        } while (bVar12);
        if (!bVar12) {
          iVar2 = 0x16;
          bVar12 = true;
          pppuVar9 = param_4;
          pcVar10 = "Ev_PointerLLPostEvent";
          do {
            if (iVar2 == 0) break;
            iVar2 = iVar2 + -1;
            bVar12 = *(char *)pppuVar9 == *pcVar10;
            pppuVar9 = (ushort ***)((int)pppuVar9 + 1);
            pcVar10 = pcVar10 + 1;
          } while (bVar12);
          if (!bVar12) {
            pppuStack_50 = (ushort ***)PTR_s_lock_001f9220;
            ppppuStack_54 = (undefined ****)param_1[0x5c];
            ppppuStack_58 = (undefined ****)0x1b021e;
            _objc_msgSend();
            ppppuVar1 = (undefined ****)param_1[0x5d];
            while (param_1 + 0x5d != ppppuVar1) {
              ppppuStack_60 = (ushort ****)*ppppuVar1;
              ppppuVar1 = (undefined ****)ppppuVar1[1];
              pppuStack_50 = (ushort ***)param_5;
              ppppuStack_54 = (undefined ****)param_4;
              ppppuStack_58 = (undefined ****)param_3;
              ppppuStack_64 = (undefined ****)0x1b025d;
              pppuStack_5c = (undefined ***)PTR_s_setIntValues_forParameter_count__001f94bc;
              iVar2 = _objc_msgSend();
              if (iVar2 != -0x2c2) {
                local_30 = iVar2;
              }
            }
            ppppuStack_54 = (undefined ****)param_1[0x5c];
            ppppuStack_58 = (undefined ****)0x1b0288;
            pppuStack_50 = (ushort ***)PTR_s_unlock_001f9474;
            _objc_msgSend();
            if (local_30 != -0x2c2) {
              return local_30;
            }
            pppuStack_50 = (ushort ***)param_5;
            ppppuStack_54 = (undefined ****)param_4;
            ppppuStack_58 = (undefined ****)param_3;
            pppuStack_5c = (undefined ***)PTR_s_setIntValues_forParameter_count__001f94bc;
            local_2c = param_1;
            local_28 = PTR_s_IODevice_001fa400;
            ppppuStack_60 = (ushort ****)&local_2c;
            ppppuStack_64 = (undefined ****)0x1b02bf;
            iVar2 = _objc_msgSendSuper();
            return iVar2;
          }
        }
        if (param_5 != (undefined ***)0x6) {
          return -0x2c2;
        }
        local_14 = (ushort **)CONCAT22(*(ushort *)(param_3 + 2),*(ushort *)(param_3 + 1));
        local_10 = param_3[3];
        local_c = param_3[4];
        local_8 = param_3[5];
        pppuStack_50 = (ushort ***)PTR_s_lock_001f9220;
        ppppuStack_54 = (undefined ****)param_1[0x44];
        ppppuStack_58 = (undefined ****)0x1b0165;
        _objc_msgSend();
        iVar2 = 0x16;
        iVar5 = 0;
        bVar12 = true;
        pcVar10 = "Ev_PointerLLPostEvent";
        do {
          pppuVar9 = param_4;
          pcVar11 = pcVar10;
          if (iVar2 == 0) break;
          iVar2 = iVar2 + -1;
          pcVar11 = pcVar10 + 1;
          pppuVar9 = (ushort ***)((int)param_4 + 1);
          bVar12 = *(char *)param_4 == *pcVar10;
          param_4 = pppuVar9;
          pcVar10 = pcVar11;
        } while (bVar12);
        if (!bVar12) {
          iVar5 = (uint)*(byte *)((int)pppuVar9 + -1) - (uint)(byte)pcVar11[-1];
        }
        if (iVar5 == 0) {
          pppuStack_50 = (ushort ***)&local_14;
          ppppuStack_54 = (undefined ****)PTR_s_setCursorPosition__001f9a18;
          ppppuStack_58 = param_1;
          pppuStack_5c = (undefined ***)0x1b01a2;
          _objc_msgSend();
        }
        pppuStack_50 = &local_10;
        ppppuStack_54 = local_24;
        ppppuStack_58 = (undefined ****)0x1b01b2;
        _IOGetTimestamp();
        ppppuStack_54 = (undefined ****)((uint)local_24[0] >> 0x18 | (int)local_24[1] << 8);
        if (ppppuStack_54 == (undefined ****)0x0) {
          ppppuStack_54 = (undefined ****)0x1;
        }
        ppppuStack_58 = (undefined ****)&local_14;
        pppuStack_5c = (undefined ***)*param_3;
        ppppuStack_60 = (ushort ****)PTR_s_postEvent_at_atTime_withData__001f9a00;
        pppppuVar6 = &ppppuStack_64;
        ppppuStack_64 = param_1;
        pppuStack_68 = (undefined ***)0x1b01e6;
        _objc_msgSend();
        goto LAB_001b01e6;
      }
      ppppuVar7 = &pppuStack_50;
      pppuStack_50 = (ushort ***)PTR_s__resetKeyboardParameters_001f9a04;
    }
  }
  ppppuVar8 = (ushort ****)((int)ppppuVar7 + -4);
  *(undefined *****)((int)ppppuVar7 + -4) = param_1;
LAB_001b01f4:
  *(undefined4 *)((int)ppppuVar8 + -4) = 0x1b01f9;
  _objc_msgSend();
  return 0;
}

