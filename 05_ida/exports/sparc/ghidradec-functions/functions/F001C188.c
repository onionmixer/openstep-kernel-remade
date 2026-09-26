
/* WARNING: Removing unreachable block (ram,0xf001c1e8) */
/* WARNING: Removing unreachable block (ram,0xf001c620) */
/* WARNING: Removing unreachable block (ram,0xf001c49c) */
/* WARNING: Removing unreachable block (ram,0xf001c408) */
/* WARNING: Removing unreachable block (ram,0xf001c448) */
/* WARNING: Removing unreachable block (ram,0xf001c3d8) */
/* WARNING: Removing unreachable block (ram,0xf001c530) */
/* WARNING: Removing unreachable block (ram,0xf001c6b8) */
/* WARNING: Removing unreachable block (ram,0xf001c228) */
/* WARNING: Removing unreachable block (ram,0xf001c43c) */

undefined8 _ptyioctl(uint param_1,uint param_2,uint *param_3,undefined4 param_4)

{
  int iVar1;
  byte bVar2;
  uint uVar3;
  int iVar4;
  undefined4 unaff_l0;
  uint *puVar5;
  undefined4 unaff_l1;
  int iVar6;
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
  bool in_DECOMPILE_MODE;
  int in_CWP;
  
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
  iVar1 = (param_1 & 0xff) * 0x10;
  iVar6 = *(int *)(DAT_f012f20c + iVar1);
  puVar5 = *(uint **)(DAT_f012f20c + iVar1 + 4);
  if (param_2 == 0x80047461) {
    if (*param_3 == 0) {
      if ((*(uint *)(iVar6 + 0x40) & 0x400000) == 0) {
        uVar3 = *(uint *)(iVar6 + 0x40);
      }
      else {
        if ((*puVar5 & 8) != 0) {
          *(byte *)(puVar5 + 3) = *(byte *)(puVar5 + 3) | 0x40;
          _ptcwakeup(iVar6);
        }
        uVar3 = *(uint *)(iVar6 + 0x40);
      }
      uVar3 = uVar3 & 0xffbfffff;
    }
    else {
      if ((*puVar5 & 8) == 0) {
        uVar3 = *(uint *)(iVar6 + 0x40);
      }
      else {
        *(byte *)(puVar5 + 3) = *(byte *)(puVar5 + 3) | 0x40;
        _ptcwakeup(iVar6);
        uVar3 = *(uint *)(iVar6 + 0x40);
      }
      uVar3 = uVar3 | 0x400000;
    }
    *(uint *)(iVar6 + 0x40) = uVar3;
loc_F001C240:
    iVar1 = 0;
    goto locret_F001C6C0;
  }
  if (*(code **)(_cdevsw + ((param_1 & 0xffff) >> 8) * 0x2c) == _ptcopen) {
    if (param_2 == 0x80047470) {
      uVar3 = *puVar5;
      if (*param_3 == 0) {
        uVar3 = uVar3 & 0xfffffff7;
      }
      else {
        iVar1 = 0x16;
        if ((uVar3 & 0x80) != 0) goto locret_F001C6C0;
        uVar3 = uVar3 | 8;
      }
      goto loc_F001C400;
    }
    if ((int)param_2 < -0x7ffb8b8f) {
      if (param_2 == 0x80047401) {
loc_F001C408:
        do {
          iVar1 = iVar6 + 0x18;
          _getc();
        } while (-1 < iVar1);
      }
      else if ((int)param_2 < -0x7ffb8bfe) {
        if (param_2 == 0x8004667e) {
          if (*param_3 == 0) {
            uVar3 = *puVar5 & 0xfffffffb;
          }
          else {
            uVar3 = *puVar5 | 4;
          }
loc_F001C400:
          *puVar5 = uVar3;
          goto loc_F001C240;
        }
      }
      else {
        if (param_2 == 0x80047466) {
          uVar3 = *puVar5;
          if (*param_3 == 0) {
            uVar3 = uVar3 & 0xffffff7f;
          }
          else {
            iVar1 = 0x16;
            if ((uVar3 & 8) != 0) goto locret_F001C6C0;
            uVar3 = uVar3 | 0x80;
          }
          goto loc_F001C400;
        }
        if (param_2 == 0x80047469) {
          if (*param_3 == 0) {
            uVar3 = *puVar5 & 0xffffffdf;
          }
          else {
            uVar3 = *puVar5 | 0x20;
          }
          *puVar5 = uVar3;
          _ttyflush(iVar6,3);
          iVar1 = 0;
          goto locret_F001C6C0;
        }
      }
    }
    else if ((int)param_2 < -0x7fdb8be9) {
      if ((-0x7fdb8bed < (int)param_2) ||
         (((int)param_2 < -0x7ff98bf5 && (-0x7ff98bf8 < (int)param_2)))) goto loc_F001C408;
    }
    else if (param_2 == 0x2000745f) {
      iVar1 = 0x16;
      if (*param_3 < 0x20) {
        if (-1 < *(int *)(iVar6 + 0x3c)) {
          _ttyflush(iVar6,3);
        }
        _gsignal((int)*(sword *)(iVar6 + 0x44),*param_3);
        iVar1 = 0;
      }
      goto locret_F001C6C0;
    }
  }
  iVar1 = iVar6;
  (**(code **)(_linesw + *(char *)(iVar6 + 0x47) * 0x30 + 0x10))(iVar6,param_2,param_3,param_4);
  if (-1 < iVar1) goto locret_F001C6C0;
  iVar1 = iVar6;
  _ttioctl(iVar6,param_2,param_3,param_4);
  iVar4 = *(char *)(iVar6 + 0x47) * 0x30;
  if (*(int *)(_linesw + iVar4 + 0x2c) != 0) {
    iVar1 = 0x19;
    (**(code **)(_linesw + iVar4 + 4))(iVar6);
    *(undefined *)(iVar6 + 0x47) = 0;
    (*(code *)_linesw._0_4_)((int)(sword)param_1,iVar6);
  }
  if (iVar1 < 0) {
    if (((*puVar5 & 0x80) != 0) && ((param_2 & 0xffffff00) == 0x20007500)) {
      if ((param_2 & 0xff) != 0) {
        *(char *)((int)puVar5 + 0xd) = (char)param_2;
        _ptcwakeup(iVar6,1);
        iVar1 = 0;
        goto locret_F001C6C0;
      }
      goto loc_F001C240;
    }
    iVar1 = 0x19;
    uVar3 = *(uint *)(iVar6 + 0x40);
  }
  else {
    uVar3 = *(uint *)(iVar6 + 0x40);
  }
  if ((uVar3 & 0x400000) == 0) {
    uVar3 = *(uint *)(iVar6 + 0x3c);
    goto loc_F001C614;
  }
  if ((*puVar5 & 8) == 0) {
loc_F001C610:
    uVar3 = *(uint *)(iVar6 + 0x3c);
  }
  else {
    if (-0x7ff98bf6 < (int)param_2) {
      if (param_2 != 0x80067475) {
        if ((int)param_2 < -0x7ff98b8a) {
          if (param_2 == 0x80067411) {
            bVar2 = *(byte *)(puVar5 + 3);
            goto loc_F001C608;
          }
          uVar3 = *(uint *)(iVar6 + 0x3c);
        }
        else {
          if ((int)param_2 < -0x7fdb8be9) {
            iVar4 = -0x7fdb8bec;
            goto loc_F001C5F8;
          }
          uVar3 = *(uint *)(iVar6 + 0x3c);
        }
        goto loc_F001C614;
      }
      bVar2 = *(byte *)(puVar5 + 3);
loc_F001C608:
      *(byte *)(puVar5 + 3) = bVar2 | 0x40;
      goto loc_F001C610;
    }
    if (-0x7ff98bf8 < (int)param_2) {
      bVar2 = *(byte *)(puVar5 + 3);
      goto loc_F001C608;
    }
    if ((int)param_2 < -0x7ffb8b80) {
      iVar4 = -0x7ffb8b83;
loc_F001C5F8:
      if (iVar4 <= (int)param_2) {
        bVar2 = *(byte *)(puVar5 + 3);
        goto loc_F001C608;
      }
      uVar3 = *(uint *)(iVar6 + 0x3c);
    }
    else {
      uVar3 = *(uint *)(iVar6 + 0x3c);
    }
  }
loc_F001C614:
  param_2 = 0;
  if (((uVar3 & 0x20) == 0) &&
     (iVar4 = iVar6, _ttynty(), (*(uint *)(iVar4 + 0x10) & 0x4000000) != 0)) {
    param_2 = (uint)((*(uint *)(iVar6 + 0x50) & 0xffff00) == 0x111300);
  }
  if ((*puVar5 & 0x40) == 0) {
    if (param_2 != 0) goto locret_F001C6C0;
    *(byte *)(puVar5 + 3) = *(byte *)(puVar5 + 3) & 0xdf | 0x10;
    uVar3 = *puVar5 | 0x40;
  }
  else {
    if (param_2 == 0) goto locret_F001C6C0;
    *(byte *)(puVar5 + 3) = *(byte *)(puVar5 + 3) & 0xef | 0x20;
    uVar3 = *puVar5 & 0xffffffbf;
  }
  *puVar5 = uVar3;
  _ptcwakeup(iVar6,1);
locret_F001C6C0:
  return CONCAT44(param_2,iVar1);
}
