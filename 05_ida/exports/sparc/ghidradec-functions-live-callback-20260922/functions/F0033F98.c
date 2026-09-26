
/* WARNING: Removing unreachable block (ram,0xf00340d4) */
/* WARNING: Removing unreachable block (ram,0xf00340f8) */
/* WARNING: Removing unreachable block (ram,0xf0034024) */
/* WARNING: Removing unreachable block (ram,0xf0034034) */
/* WARNING: Removing unreachable block (ram,0xf00340c4) */
/* WARNING: Removing unreachable block (ram,0xf0033fdc) */
/* WARNING: Removing unreachable block (ram,0xf0033fac) */

undefined8 _ip_pcbopts(int *param_1,int param_2)

{
  char cVar1;
  int iVar2;
  uint uVar3;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  uint uVar4;
  char *pcVar5;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  undefined4 uVar6;
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
  if (*param_1 != 0) {
    _m_free();
  }
  *param_1 = 0;
  if (param_2 != 0) {
    uVar3 = (uint)*(sword *)(param_2 + 8);
    if (uVar3 != 0) {
      if (((uVar3 & 3) == 0) && (*(int *)(param_2 + 4) + uVar3 + 4 < 0x7d)) {
        *(sword *)(param_2 + 8) = *(sword *)(param_2 + 8) + 4;
        iVar2 = param_2 + *(int *)(param_2 + 4);
        pcVar5 = (char *)(iVar2 + 4);
        _ovbcopy(iVar2,pcVar5);
        _bzero(param_2 + *(int *)(param_2 + 4),4);
        if ((int)uVar3 < 1) {
          *param_1 = param_2;
        }
        else {
          do {
            cVar1 = *pcVar5;
            if (cVar1 == '\0') break;
            if (cVar1 == '\x01') {
              uVar4 = 1;
            }
            else {
              uVar4 = (uint)(byte)pcVar5[1];
              if ((uVar4 < 2) || ((int)uVar3 < (int)uVar4)) goto loc_F00340F8;
            }
            if ((cVar1 == -0x7d) || (cVar1 == -0x77)) {
              if (uVar4 < 7) goto loc_F00340F8;
              uVar4 = uVar4 - 4;
              *(sword *)(param_2 + 8) = *(sword *)(param_2 + 8) + -4;
              pcVar5[1] = (char)uVar4;
              _bcopy(pcVar5 + 3,param_2 + *(int *)(param_2 + 4),4);
              _ovbcopy(pcVar5 + 7,pcVar5 + 3,uVar3);
              uVar3 = (uVar3 - 4) - uVar4;
            }
            else {
              uVar3 = uVar3 - uVar4;
            }
            pcVar5 = pcVar5 + uVar4;
          } while (0 < (int)uVar3);
          *param_1 = param_2;
        }
        uVar6 = 0;
      }
      else {
loc_F00340F8:
        _m_free(param_2);
        uVar6 = 0x16;
      }
      goto locret_F0034104;
    }
  }
  uVar6 = 0;
  if (param_2 != 0) {
    _m_free(param_2);
    uVar6 = 0;
  }
locret_F0034104:
  return CONCAT44(param_2,uVar6);
}

