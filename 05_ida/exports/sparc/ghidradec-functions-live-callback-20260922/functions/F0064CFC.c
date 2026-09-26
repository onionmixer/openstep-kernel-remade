
/* WARNING: Removing unreachable block (ram,0xf0064e68) */
/* WARNING: Removing unreachable block (ram,0xf0064e7c) */
/* WARNING: Removing unreachable block (ram,0xf0064e34) */

undefined8 _host_info(int param_1,int param_2,int *param_3,uint *param_4)

{
  uint uVar1;
  int *piVar2;
  int iVar3;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  undefined4 uVar4;
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
  if (param_1 != 0) {
    if (param_2 != 2) {
      if (param_2 < 3) {
        if (param_2 != 1) {
          uVar4 = 4;
          goto locret_F0064E98;
        }
        if (4 < *param_4) {
          *param_3 = dword_F013C048;
          param_3[1] = DAT_f013c04c;
          param_3[2] = dword_F013C050;
          iVar3 = _master_processor;
          param_3[3] = (&dword_F0134764)[*(int *)(_master_processor + 0x144) * 8];
          uVar4 = 0;
          param_3[4] = (&dword_F0134768)[*(int *)(iVar3 + 0x144) * 8];
          *param_4 = 5;
          goto locret_F0064E98;
        }
      }
      else if (param_2 == 3) {
        if (1 < *param_4) {
          iVar3 = _tick;
          div(_tick,1000);
          *param_3 = iVar3;
          param_3[1] = iVar3;
          uVar1 = 2;
loc_F0064E88:
          *param_4 = uVar1;
          uVar4 = 0;
          goto locret_F0064E98;
        }
      }
      else {
        if (param_2 != 4) {
          uVar4 = 4;
          goto locret_F0064E98;
        }
        if (5 < *param_4) {
          _bcopy(_avenrun,param_3,0xc);
          _bcopy(_mach_factor,param_3 + 3,0xc);
          uVar1 = 6;
          goto loc_F0064E88;
        }
      }
      uVar4 = 5;
      goto locret_F0064E98;
    }
    if (*param_4 != 0) {
      *param_4 = 0;
      iVar3 = 0;
      piVar2 = &_machine_slot;
      do {
        if ((*piVar2 != 0) && (piVar2[3] != 0)) {
          *param_3 = iVar3;
          param_3 = param_3 + 1;
          *param_4 = *param_4 + 1;
        }
        iVar3 = iVar3 + 1;
        piVar2 = piVar2 + 8;
      } while (iVar3 < 1);
      uVar4 = 0;
      goto locret_F0064E98;
    }
  }
  uVar4 = 4;
locret_F0064E98:
  return CONCAT44(param_2,uVar4);
}

