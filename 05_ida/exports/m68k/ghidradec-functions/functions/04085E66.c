
/* WARNING: Type propagation algorithm not settling */

undefined4 sub_4085E66(int param_1)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  int iVar3;
  undefined4 *puVar4;
  word wVar5;
  uint ***pppuVar6;
  uint uVar7;
  sword sVar8;
  uint ****ppppuVar9;
  undefined4 ****ppppuVar10;
  undefined4 ***pppuVar11;
  undefined4 uVar12;
  uint ***pppuStack_6c;
  undefined4 ****ppppuStack_68;
  uint ***pppuStack_3c;
  uint **ppuStack_38;
  undefined4 **ppuStack_34;
  undefined4 uStack_30;
  undefined4 uStack_2c;
  undefined4 uStack_28;
  uint **ppuStack_24;
  undefined4 **ppuStack_20;
  undefined4 uStack_1c;
  undefined4 uStack_18;
  undefined4 uStack_14;
  uint **ppuStack_10;
  uint ***pppuStack_c;
  undefined4 uStack_8;
  
  puVar4 = dword_40C6E94;
  switch(*(undefined4 *)(param_1 + 0x14)) {
  case :
    if (*(int *)(param_1 + 4) != 0x28) {
      return 0x67;
    }
    uVar7 = *(uint *)(param_1 + 0x1c);
    if ((uVar7 & 0xffffff00) != 0) {
      return 0x67;
    }
    if (((uVar7 & 0x80) != 0) && (2 < (uVar7 & 0x7f))) {
      return 0x67;
    }
    if ((char)uVar7 == '\0') {
      return 0x67;
    }
    if (uVar7 == 0x82) {
      ppppuStack_68 = *(undefined4 *****)(param_1 + 0x24);
      pppuStack_6c = (uint ***)&dword_40C6E8C;
      puVar4 = (undefined4 *)_snd_get_owner();
      if (puVar4 == (undefined4 *)0x0) {
        return 0x6a;
      }
      if (puVar4[1] != 0) goto loc_4085FBC;
      uVar2 = *puVar4;
      pppuVar11 = __NXAudioSndinDevice;
    }
    else {
      if ((uVar7 & 0x80) == 0) {
        if (*(uint ****)(param_1 + 0x24) != _snd_var) {
          return 0x6a;
        }
        if ((&unk_40C6DF4)[uVar7 & 0x7f] == 0) {
          return 0x6b;
        }
        goto loc_4085FBC;
      }
      ppppuStack_68 = *(undefined4 *****)(param_1 + 0x24);
      pppuStack_6c = (uint ***)&dword_40C6E94;
      puVar4 = (undefined4 *)_snd_get_owner();
      if (puVar4 == (undefined4 *)0x0) {
        return 0x6a;
      }
      if (puVar4[1] != 0) goto loc_4085FBC;
      uVar2 = *puVar4;
      pppuVar11 = __NXAudioSndoutDevice;
    }
    ppppuStack_68 = (undefined4 ****)0x1;
    pppuStack_6c = (undefined4 ***)0x0;
    (*___NXAudioAddStream)(pppuVar11,&uStack_8,uVar2);
    uVar2 = (*___NXAudioPortToStream)(uStack_8);
    puVar4[1] = uVar2;
loc_4085FBC:
    ppppuStack_68 = (undefined4 ****)(*(uint *)(param_1 + 0x1c) | 0x10000);
    pppuStack_6c = *(uint ****)(param_1 + 0x10);
    _snd_reply_ret_stream();
    return 0;
  case :
    pppuStack_c = (undefined4 ***)0x0;
    if (*(int *)(param_1 + 4) == 0x20) {
      ppppuStack_68 = &pppuStack_c;
      pppuStack_6c = __NXAudioSndoutDevice;
      (*___NXAudioGetSndoutOptions)();
      if ((*(byte *)(param_1 + 0x1f) & 4) == 0) {
        pppuStack_c = (uint ***)((uint)pppuStack_c & 0xfffffffe);
      }
      else {
        pppuStack_c = (uint ***)((uint)pppuStack_c | 1);
      }
      if ((*(byte *)(param_1 + 0x1f) & 2) == 0) {
        pppuStack_c = (uint ***)((uint)pppuStack_c & 0xffffffef);
      }
      else {
        pppuStack_c = (uint ***)((uint)pppuStack_c | 0x10);
      }
      if ((*(byte *)(param_1 + 0x1f) & 1) == 0) {
        pppuStack_c = (uint ***)((uint)pppuStack_c & 0xfffffff7);
      }
      else {
        pppuStack_c = (uint ***)((uint)pppuStack_c | 8);
      }
      ppppuStack_68 = (undefined4 ****)pppuStack_c;
loc_40861B2:
      pppuStack_6c = (undefined4 ***)0x0;
      (*___NXAudioSetSndoutOptions)(__NXAudioSndoutDevice);
      return 100;
    }
    break;
  case :
    pppuVar6 = (uint ***)0x0;
    if (*(int *)(param_1 + 4) == 0x18) {
      ppppuStack_68 = (undefined4 ****)&ppuStack_10;
      pppuStack_6c = __NXAudioSndoutDevice;
      (*___NXAudioGetSndoutOptions)();
      if (((uint)ppuStack_10 & 1) != 0) {
        pppuVar6 = (uint ***)0x4;
      }
      if (((uint)ppuStack_10 & 0x10) != 0) {
        pppuVar6 = (uint ***)((uint)pppuVar6 | 2);
      }
      if (((uint)ppuStack_10 & 8) != 0) {
        pppuVar6 = (uint ***)((uint)pppuVar6 | 1);
      }
      pppuStack_6c = *(uint ****)(param_1 + 0x10);
      ppppuStack_68 = (undefined4 ****)pppuVar6;
      _snd_reply_ret_parms();
      return 0;
    }
    break;
  case :
    if (*(int *)(param_1 + 4) == 0x20) {
      ppppuStack_68 = *(undefined4 *****)(param_1 + 0x1c);
      pppuStack_6c = (undefined4 ***)0x40860aa;
      _snd_device_set_volume();
      return 100;
    }
    break;
  case :
    if (*(int *)(param_1 + 4) == 0x18) {
      ppppuStack_68 = (undefined4 ****)0x40860be;
      ppppuStack_68 = (undefined4 ****)_snd_device_get_volume();
      pppuStack_6c = *(uint ****)(param_1 + 0x10);
      _snd_reply_ret_volume();
      return 0;
    }
    break;
  case :
    if (*(int *)(param_1 + 4) != 0x28) {
      return 0x67;
    }
    if (_snd_var == *(uint ****)(param_1 + 0x24)) {
      ppppuStack_68 = (undefined4 ****)0x40861e4;
      _dsp_dev_reset_hard();
loc_4086248:
      _snd_var = *(uint ****)(param_1 + 0x24);
      dword_40C6E9C = *(undefined4 *)(param_1 + 0x1c);
      ppppuStack_68 = (undefined4 ****)0x408625e;
      _dsp_dev_init();
      dword_40C6E5A = dword_40C6E52;
      return 100;
    }
    if (_snd_var == (uint ***)0x0) {
      ppppuStack_68 = (undefined4 ****)0x800;
      pppuStack_6c = (undefined4 ***)0x408620a;
      dword_40C6E52 = _kalloc();
      dword_40C6E56 = dword_40C6E52 + 0x800;
      uVar7 = 0x12;
      do {
        do {
          ppppuStack_68 = (undefined4 ****)(uVar7 | 0x10000);
          pppuStack_6c = (undefined4 ***)0x408622e;
          sub_4085946();
          wVar5 = (word)(uVar7 >> 0x10);
          sVar8 = (sword)uVar7 + -1;
          uVar7 = CONCAT22(wVar5,sVar8);
        } while (sVar8 != -1);
        uVar7 = (uint)wVar5 * 0x10000 - 1;
      } while (wVar5 != 0);
      ppppuStack_68 = (undefined4 ****)0x10013;
      pppuStack_6c = (undefined4 ***)0x4086246;
      sub_4085946();
      goto loc_4086248;
    }
    pppuStack_6c = *(uint ****)(param_1 + 0x14);
    uVar2 = *(undefined4 *)(param_1 + 0x10);
    uVar12 = dword_40C6E9C;
    goto loc_40862EE;
  case :
    if (*(int *)(param_1 + 4) != 0x28) {
      return 0x67;
    }
    if (__NXAudioSndinDevice != (undefined4 ***)0x0) {
      if ((undefined4 **)dword_40C6E8C == &dword_40C6E8C) {
        ppppuVar9 = (uint ****)&ppppuStack_68;
        ppppuStack_68 = (undefined4 ****)0x10082;
        pppuStack_6c = (undefined4 ***)0x4086294;
        sub_4085946();
      }
      else {
        ppppuStack_68 = *(undefined4 *****)(param_1 + 0x24);
        pppuStack_6c = (uint ***)&dword_40C6E8C;
        iVar3 = _snd_get_owner();
        ppppuVar9 = (uint ****)&stack0xffffff9c;
        if (iVar3 != 0) {
loc_4086350:
          ppppuStack_68 = (undefined4 ****)0x0;
          pppuStack_6c = (undefined4 ***)0x0;
          (*___NXAudioStreamControl)(*(undefined4 *)(iVar3 + 4),2);
          return 100;
        }
      }
      *(undefined4 *)((int)ppppuVar9 + -4) = *(undefined4 *)(param_1 + 0x24);
      *(undefined4 ***)((int)ppppuVar9 + -8) = &dword_40C6E8C;
      *(undefined4 *)((int)ppppuVar9 + -0xc) = 0x40862b6;
      sub_4085C76();
      return 100;
    }
    goto loc_40862E0;
  case :
    if (*(int *)(param_1 + 4) != 0x28) {
      return 0x67;
    }
    if (__NXAudioSndoutDevice != (undefined4 ***)0x0) {
      if ((undefined4 **)dword_40C6E94 == &dword_40C6E94) {
        ppppuStack_68 = (undefined4 ****)0x10080;
        pppuStack_6c = (undefined4 ***)0x4086312;
        sub_4085946();
        ppppuVar10 = &pppuStack_6c;
        pppuStack_6c = (undefined4 ***)0x10081;
        sub_4085946();
      }
      else {
        ppppuStack_68 = *(undefined4 *****)(param_1 + 0x24);
        pppuStack_6c = (uint ***)&dword_40C6E94;
        iVar3 = _snd_get_owner();
        ppppuVar10 = (undefined4 ****)&stack0xffffff9c;
        if (iVar3 != 0) goto loc_4086350;
      }
      *(undefined4 *)((int)ppppuVar10 + -4) = *(undefined4 *)(param_1 + 0x24);
      *(undefined4 ***)((int)ppppuVar10 + -8) = &dword_40C6E94;
      *(undefined4 *)((int)ppppuVar10 + -0xc) = 0x408633c;
      sub_4085C76();
      return 100;
    }
loc_40862E0:
    pppuStack_6c = *(uint ****)(param_1 + 0x14);
    uVar2 = *(undefined4 *)(param_1 + 0x10);
    uVar12 = 0;
loc_40862EE:
    ppppuStack_68 = (undefined4 ****)0x69;
    _snd_reply_illegal_msg(uVar12,uVar2);
    return 0;
  case :
    if (*(int *)(param_1 + 4) != 0x28) {
      return 0x67;
    }
    ppppuStack_68 = *(undefined4 *****)(param_1 + 0x24);
    if (ppppuStack_68 != (undefined4 ****)_snd_var) {
      return 0x6a;
    }
    if ((*(byte *)(param_1 + 0x1f) & 8) != 0) {
      pppuStack_6c = (uint ***)&dword_40C6E94;
      iVar3 = _snd_get_owner();
      if (iVar3 == 0) {
        return 0x6a;
      }
      if (dword_40C6DF8 == 0) {
        return 0x6b;
      }
    }
    if ((*(byte *)(param_1 + 0x1f) & 0x10) != 0) {
      ppppuStack_68 = (undefined4 ****)_snd_var;
      pppuStack_6c = (uint ***)&dword_40C6E8C;
      iVar3 = _snd_get_owner();
      if (iVar3 == 0) {
        return 0x6a;
      }
      if (dword_40C6DFC == 0) {
        return 0x6b;
      }
    }
    if ((((dword_40C6E84 & 0x2000) != 0) && ((*(byte *)(param_1 + 0x1f) & 4) != 0)) ||
       (((dword_40C6E84 & 0x1000) != 0 && ((*(byte *)(param_1 + 0x1f) & 2) != 0)))) {
      ppppuStack_68 = (undefined4 ****)0x0;
      pppuStack_6c = (undefined4 ***)0x4086402;
      _dsp_dev_new_proto();
    }
    ppppuStack_68 = *(undefined4 *****)(param_1 + 0x1c);
    pppuStack_6c = (undefined4 ***)0x408640e;
    _dsp_dev_new_proto();
    return 100;
  case :
    if (*(int *)(param_1 + 4) != 0x20) {
      return 0x67;
    }
    if (*(uint ****)(param_1 + 0x1c) != _snd_var) {
      return 0x6a;
    }
    ppppuStack_68 = *(undefined4 *****)(param_1 + 0x10);
    pppuStack_6c = (undefined4 ***)0x10013;
    _snd_reply_dsp_cmd_port();
    return 0;
  case :
    if (*(int *)(param_1 + 4) == 0x20) {
      puVar1 = dword_40C6E8C;
      if (*(int *)(param_1 + 0x1c) != dword_40C6EC8) {
        return 0x70;
      }
      while (dword_40C6E8C = puVar1, (undefined4 **)puVar4 != &dword_40C6E94) {
        ppppuStack_68 = (undefined4 ****)*puVar4;
        pppuStack_6c = (undefined4 ***)0x4086472;
        sub_40870BA();
        pppuStack_6c = (uint ***)*puVar4;
        _port_deallocate(dword_40C6EC0);
        puVar1 = dword_40C6E8C;
      }
      while ((undefined4 **)puVar1 != &dword_40C6E8C) {
        ppppuStack_68 = (undefined4 ****)*puVar1;
        pppuStack_6c = (undefined4 ***)0x408649e;
        sub_40870BA();
        pppuStack_6c = (uint ***)*puVar1;
        _port_deallocate(dword_40C6EC0);
      }
      if (_snd_var != (uint ***)0x0) {
        pppuStack_6c = (undefined4 ***)0x40864c6;
        ppppuStack_68 = (undefined4 ****)_snd_var;
        sub_40870BA();
        pppuStack_6c = _snd_var;
        _port_deallocate(dword_40C6EC0);
        _snd_var = (uint ***)0x0;
      }
      ppppuStack_68 = (undefined4 ****)dword_40C6EB4;
      pppuStack_6c = dword_40C6EC0;
      _port_deallocate();
      _port_allocate(dword_40C6EC0,&dword_40C6EB4);
      _port_set_add(dword_40C6EC0,dword_40C6EA8,dword_40C6EB4);
      _snd_reply_ret_device(*(undefined4 *)(param_1 + 0x10),dword_40C6EB4);
      return 0;
    }
    break;
  case :
    if (*(int *)(param_1 + 4) == 0x30) {
      ppppuStack_68 = *(undefined4 *****)(param_1 + 0x1c);
      if (ppppuStack_68 != (undefined4 ****)_snd_var) {
        return 0x6a;
      }
      pppuStack_6c = dword_40C6EC0;
      _port_deallocate();
      _snd_var = *(uint ****)(param_1 + 0x24);
      _port_deallocate(dword_40C6EC0,dword_40C6E9C);
      dword_40C6E9C = *(undefined4 *)(param_1 + 0x2c);
      return 0;
    }
    break;
  case :
    if (*(int *)(param_1 + 4) != 0x30) {
      return 0x67;
    }
    ppppuStack_68 = *(undefined4 *****)(param_1 + 0x1c);
    pppuStack_6c = (uint ***)&dword_40C6E8C;
    puVar4 = (undefined4 *)_snd_get_owner();
    goto joined_r0x040865a0;
  case :
    if (*(int *)(param_1 + 4) != 0x30) {
      return 0x67;
    }
    ppppuStack_68 = *(undefined4 *****)(param_1 + 0x1c);
    pppuStack_6c = (uint ***)&dword_40C6E94;
    puVar4 = (undefined4 *)_snd_get_owner();
joined_r0x040865a0:
    if (puVar4 == (undefined4 *)0x0) {
      return 0x6a;
    }
    ppppuStack_68 = (undefined4 ****)*puVar4;
    pppuStack_6c = dword_40C6EC0;
    _port_deallocate();
    *puVar4 = *(undefined4 *)(param_1 + 0x24);
    return 0;
  case :
    pppuStack_3c = (undefined4 ***)0x0;
    if (*(int *)(param_1 + 4) == 0x20) {
      ppppuStack_68 = &pppuStack_3c;
      pppuStack_6c = __NXAudioSndoutDevice;
      (*___NXAudioGetSndoutOptions)();
      if ((*(byte *)(param_1 + 0x1f) & 1) == 0) {
        pppuStack_3c = (uint ***)((uint)pppuStack_3c & 0xfffffffd);
      }
      else {
        pppuStack_3c = (uint ***)((uint)pppuStack_3c | 2);
      }
      if ((*(byte *)(param_1 + 0x1f) & 2) == 0) {
        pppuStack_3c = (uint ***)((uint)pppuStack_3c & 0xfffffffb);
      }
      else {
        pppuStack_3c = (uint ***)((uint)pppuStack_3c | 4);
      }
      ppppuStack_68 = (undefined4 ****)pppuStack_3c;
      goto loc_40861B2;
    }
    break;
  case :
    if (*(int *)(param_1 + 4) == 0x18) {
      ppppuStack_68 = (undefined4 ****)&ppuStack_24;
      pppuStack_6c = &ppuStack_20;
      sub_4085D2E(__NXAudioSndoutDevice,&uStack_14,&uStack_18,&uStack_1c);
      uStack_28 = uStack_14;
      uStack_2c = uStack_18;
      uStack_30 = uStack_1c;
      ppuStack_34 = ppuStack_20;
      ppuStack_38 = ppuStack_24;
loc_408614E:
      _snd_reply_ret_formats
                (*(undefined4 *)(param_1 + 0x10),uStack_28,uStack_2c,uStack_30,ppuStack_34,
                 ppuStack_38);
      return 0;
    }
    break;
  case :
    if (*(int *)(param_1 + 4) == 0x18) {
      ppppuStack_68 = (undefined4 ****)&ppuStack_38;
      pppuStack_6c = &ppuStack_34;
      sub_4085D2E(__NXAudioSndinDevice,&uStack_28,&uStack_2c,&uStack_30);
      goto loc_408614E;
    }
    break;
  :
    return 0x66;
  }
  return 0x67;
}
