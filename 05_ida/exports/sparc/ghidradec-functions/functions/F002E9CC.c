
/* WARNING: Removing unreachable block (ram,0xf002ee5c) */
/* WARNING: Removing unreachable block (ram,0xf002ef2c) */
/* WARNING: Removing unreachable block (ram,0xf002eef0) */
/* WARNING: Removing unreachable block (ram,0xf002eacc) */
/* WARNING: Removing unreachable block (ram,0xf002ea94) */
/* WARNING: Removing unreachable block (ram,0xf002eab4) */
/* WARNING: Removing unreachable block (ram,0xf002ef78) */
/* WARNING: Removing unreachable block (ram,0xf002efcc) */
/* WARNING: Removing unreachable block (ram,0xf002ede8) */
/* WARNING: Removing unreachable block (ram,0xf002ee74) */
/* WARNING: Removing unreachable block (ram,0xf002eb90) */

undefined8 _in_control(undefined4 param_1,int param_2,int param_3,int param_4)

{
  word wVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  undefined4 unaff_l0;
  undefined2 *puVar6;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  undefined4 unaff_i1;
  undefined4 unaff_i2;
  undefined4 unaff_i3;
  undefined4 unaff_i4;
  undefined4 unaff_i5;
  undefined4 unaff_fp;
  undefined4 unaff_i7;
  bool bVar7;
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
  puVar6 = (undefined2 *)0x0;
  if ((param_4 != 0) && (puVar6 = _in_ifaddr, _in_ifaddr != (undefined2 *)0x0)) {
    iVar2 = *(int *)(_in_ifaddr + 0x10);
    while ((iVar2 != param_4 &&
           (puVar6 = *(undefined2 **)(puVar6 + 0x20), puVar6 != (undefined2 *)0x0))) {
      iVar2 = *(int *)(puVar6 + 0x10);
    }
  }
  iVar2 = -0x7fdf96ed;
  if (param_2 == -0x7fdf96ed) {
    _suser();
    if (iVar2 == 0) goto loc_F002EBA4;
loc_F002EBB4:
    if (puVar6 == (undefined2 *)0x0) {
      iVar2 = 0x31;
      goto locret_F002EFE0;
    }
  }
  else {
    if (param_2 < -0x7fdf96ec) {
      iVar2 = -0x7fdf9800;
      if (param_2 != -0x7fdf96f4) {
        iVar2 = -0x7fdf96f2;
loc_F002EA6C:
        if (param_2 != iVar2) goto loc_F002EBB4;
      }
    }
    else {
      iVar2 = -0x7fdf96de;
      if (param_2 != -0x7fdf96de) {
        if (param_2 < -0x7fdf96dd) {
          iVar2 = -0x7fdf96ea;
          goto loc_F002EA6C;
        }
        if (param_2 != -0x3fdf96df) goto loc_F002EBB4;
        goto loc_F002EBC8;
      }
    }
    _suser();
    if (iVar2 == 0) {
loc_F002EBA4:
      iVar2 = (int)*(char *)(dword_F0133DDC + 0x38);
      goto locret_F002EFE0;
    }
    if (param_4 == 0) {
      _panic(aInControl);
    }
    if (puVar6 == (undefined2 *)0x0) {
      iVar2 = 1;
      _m_getclr(1,0xd);
      if (iVar2 == 0) {
        iVar2 = 0x37;
        goto locret_F002EFE0;
      }
      if (_in_ifaddr == (undefined2 *)0x0) {
        _in_ifaddr = (undefined2 *)(iVar2 + *(int *)(iVar2 + 4));
      }
      else {
        iVar4 = *(int *)(_in_ifaddr + 0x20);
        puVar6 = _in_ifaddr;
        while (iVar4 != 0) {
          puVar6 = *(undefined2 **)(puVar6 + 0x20);
          iVar4 = *(int *)(puVar6 + 0x20);
        }
        *(int *)(puVar6 + 0x20) = iVar2 + *(int *)(iVar2 + 4);
      }
      iVar4 = *(int *)(param_4 + 0x18);
      puVar6 = (undefined2 *)(iVar2 + *(int *)(iVar2 + 4));
      if (iVar4 == 0) {
        *(undefined2 **)(param_4 + 0x18) = puVar6;
      }
      else {
        iVar2 = *(int *)(iVar4 + 0x24);
        while (iVar2 != 0) {
          iVar4 = *(int *)(iVar4 + 0x24);
          iVar2 = *(int *)(iVar4 + 0x24);
        }
        *(undefined2 **)(iVar4 + 0x24) = puVar6;
      }
      *(int *)(puVar6 + 0x10) = param_4;
      *puVar6 = 2;
      if ((*(word *)(param_4 + 0xc) & 8) == 0) {
        _in_interfaces = _in_interfaces + 1;
      }
    }
  }
loc_F002EBC8:
  if (param_2 == -0x7fdf96de) {
    uVar3 = *(uint *)(puVar6 + 0x1e);
    *(uint *)(puVar6 + 0x1e) = uVar3 & 0xfffffffd;
    if ((*(word *)(param_4 + 0xc) & 1) != 0) {
      *(uint *)(puVar6 + 0x1e) = uVar3 & 0xfffffffd | 4;
      param_2 = 1;
      bVar7 = false;
      iVar2 = -5;
      iVar4 = 0;
      do {
        iVar5 = 0x20;
        if (iVar2 == 0 || iVar2 < 0 != bVar7) {
          iVar5 = (1 << ((byte)iVar4 & 0x1f)) >> 1;
        }
        iVar2 = param_4;
        _icmp_sendMaskPacket(param_4,0x11,iVar5);
        if (iVar2 != 0) goto locret_F002EFE0;
        iVar5 = iVar4 + 1;
        if ((*(uint *)(puVar6 + 0x1e) & 4) == 0) goto loc_F002EFDC;
        bVar7 = SBORROW4(iVar5,5);
        iVar2 = iVar4 + -4;
        iVar4 = iVar5;
      } while (iVar5 < 5);
    }
    iVar2 = 0x32;
    goto locret_F002EFE0;
  }
  if (param_2 < -0x7fdf96dd) {
    if (param_2 == -0x7fdf96f2) {
      if ((*(word *)(param_4 + 0xc) & 0x10) == 0) {
        iVar2 = 0x16;
        goto locret_F002EFE0;
      }
      *(undefined2 *)((int)register0x00000038 + -0x18) = puVar6[8];
      *(undefined2 *)((int)register0x00000038 + -0x16) = puVar6[9];
      *(undefined2 *)((int)register0x00000038 + -0x14) = puVar6[10];
      *(undefined2 *)((int)register0x00000038 + -0x12) = puVar6[0xb];
      *(undefined2 *)((int)register0x00000038 + -0x10) = puVar6[0xc];
      *(undefined2 *)((int)register0x00000038 + -0xe) = puVar6[0xd];
      *(undefined2 *)((int)register0x00000038 + -0xc) = puVar6[0xe];
      *(undefined2 *)((int)register0x00000038 + -10) = puVar6[0xf];
      puVar6[8] = *(undefined2 *)(param_3 + 0x10);
      puVar6[9] = *(undefined2 *)(param_3 + 0x12);
      puVar6[10] = *(undefined2 *)(param_3 + 0x14);
      puVar6[0xb] = *(undefined2 *)(param_3 + 0x16);
      puVar6[0xc] = *(undefined2 *)(param_3 + 0x18);
      puVar6[0xd] = *(undefined2 *)(param_3 + 0x1a);
      puVar6[0xe] = *(undefined2 *)(param_3 + 0x1c);
      puVar6[0xf] = *(undefined2 *)(param_3 + 0x1e);
      if (*(int *)(param_4 + 0x38) != 0) {
        _if_ioctl(param_4,0x8020690e,puVar6);
        if (param_4 != 0) {
          puVar6[8] = *(undefined2 *)((int)register0x00000038 + -0x18);
          puVar6[9] = *(undefined2 *)((int)register0x00000038 + -0x16);
          puVar6[10] = *(undefined2 *)((int)register0x00000038 + -0x14);
          puVar6[0xb] = *(undefined2 *)((int)register0x00000038 + -0x12);
          puVar6[0xc] = *(undefined2 *)((int)register0x00000038 + -0x10);
          puVar6[0xd] = *(undefined2 *)((int)register0x00000038 + -0xe);
          puVar6[0xe] = *(undefined2 *)((int)register0x00000038 + -0xc);
          puVar6[0xf] = *(undefined2 *)((int)register0x00000038 + -10);
          iVar2 = param_4;
          goto locret_F002EFE0;
        }
      }
      if ((*(uint *)(puVar6 + 0x1e) & 1) != 0) {
        _rtinit((undefined *)((int)register0x00000038 + -0x18),puVar6,0x8030720b,4);
        _rtinit(puVar6 + 8,puVar6,0x8030720a,5);
        iVar2 = 0;
        goto locret_F002EFE0;
      }
    }
    else {
      if (param_2 < -0x7fdf96f1) {
        if (param_2 == -0x7fdf96f4) {
          *(word *)(param_4 + 0xc) = *(word *)(param_4 + 0xc) & 0x7fff;
          _in_ifinit(param_4,puVar6,param_3 + 0x10);
          iVar2 = param_4;
          goto locret_F002EFE0;
        }
loc_F002EFB0:
        iVar2 = 0x2d;
        if ((param_4 != 0) && (*(int *)(param_4 + 0x38) != 0)) {
          _if_ioctl(param_4,param_2,param_3);
          iVar2 = param_4;
        }
        goto locret_F002EFE0;
      }
      if (param_2 == -0x7fdf96ed) {
        if ((*(word *)(param_4 + 0xc) & 2) == 0) {
          iVar2 = 0x16;
          goto locret_F002EFE0;
        }
        puVar6[8] = *(undefined2 *)(param_3 + 0x10);
        puVar6[9] = *(undefined2 *)(param_3 + 0x12);
        puVar6[10] = *(undefined2 *)(param_3 + 0x14);
        puVar6[0xb] = *(undefined2 *)(param_3 + 0x16);
        puVar6[0xc] = *(undefined2 *)(param_3 + 0x18);
        puVar6[0xd] = *(undefined2 *)(param_3 + 0x1a);
        puVar6[0xe] = *(undefined2 *)(param_3 + 0x1c);
        puVar6[0xf] = *(undefined2 *)(param_3 + 0x1e);
      }
      else {
        if (param_2 != -0x7fdf96ea) goto loc_F002EFB0;
        *(uint *)(puVar6 + 0x1e) = *(uint *)(puVar6 + 0x1e) & 0xfffffff9;
        iVar2 = *(int *)(param_3 + 0x14);
        *(int *)(puVar6 + 0x1a) = iVar2;
        if (iVar2 != 0) {
          *(uint *)(puVar6 + 0x1e) = *(uint *)(puVar6 + 0x1e) | 2;
          _icmp_sendMaskPacket(param_4,0x12,0);
          iVar2 = 0;
          goto locret_F002EFE0;
        }
      }
    }
  }
  else if (param_2 == -0x3fdf96f1) {
    wVar1 = *(word *)(param_4 + 0xc) & 0x10;
loc_F002ECEC:
    if (wVar1 == 0) {
      iVar2 = 0x16;
      goto locret_F002EFE0;
    }
    *(undefined2 *)(param_3 + 0x10) = puVar6[8];
    *(undefined2 *)(param_3 + 0x12) = puVar6[9];
    *(undefined2 *)(param_3 + 0x14) = puVar6[10];
    *(undefined2 *)(param_3 + 0x16) = puVar6[0xb];
    *(undefined2 *)(param_3 + 0x18) = puVar6[0xc];
    *(undefined2 *)(param_3 + 0x1a) = puVar6[0xd];
    *(undefined2 *)(param_3 + 0x1c) = puVar6[0xe];
    *(undefined2 *)(param_3 + 0x1e) = puVar6[0xf];
  }
  else if (param_2 < -0x3fdf96f0) {
    if (param_2 != -0x3fdf96f3) goto loc_F002EFB0;
    *(undefined2 *)(param_3 + 0x10) = *puVar6;
    *(undefined2 *)(param_3 + 0x12) = puVar6[1];
    *(undefined2 *)(param_3 + 0x14) = puVar6[2];
    *(undefined2 *)(param_3 + 0x16) = puVar6[3];
    *(undefined2 *)(param_3 + 0x18) = puVar6[4];
    *(undefined2 *)(param_3 + 0x1a) = puVar6[5];
    *(undefined2 *)(param_3 + 0x1c) = puVar6[6];
    *(undefined2 *)(param_3 + 0x1e) = puVar6[7];
  }
  else {
    if (param_2 == -0x3fdf96ee) {
      wVar1 = *(word *)(param_4 + 0xc) & 2;
      goto loc_F002ECEC;
    }
    if (param_2 != -0x3fdf96eb) goto loc_F002EFB0;
    *(undefined2 *)(param_3 + 0x10) = 2;
    *(undefined4 *)(param_3 + 0x14) = *(undefined4 *)(puVar6 + 0x1a);
  }
loc_F002EFDC:
  iVar2 = 0;
locret_F002EFE0:
  return CONCAT44(param_2,iVar2);
}
