
/* WARNING: Removing unreachable block (ram,0xf0029eec) */
/* WARNING: Removing unreachable block (ram,0xf0029e4c) */
/* WARNING: Removing unreachable block (ram,0xf0029e38) */
/* WARNING: Removing unreachable block (ram,0xf0029eb4) */
/* WARNING: Removing unreachable block (ram,0xf0029cf0) */
/* WARNING: Removing unreachable block (ram,0xf0029e94) */
/* WARNING: Removing unreachable block (ram,0xf0029e04) */
/* WARNING: Removing unreachable block (ram,0xf0029e44) */
/* WARNING: Removing unreachable block (ram,0xf0029e84) */
/* WARNING: Removing unreachable block (ram,0xf0029ce0) */
/* WARNING: Removing unreachable block (ram,0xf0029cbc) */
/* WARNING: Removing unreachable block (ram,0xf0029ccc) */

undefined8 _ifioctl(int param_1,int param_2,int param_3)

{
  int iVar1;
  int iVar2;
  undefined4 unaff_l0;
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
  iVar1 = -0x7fdb96e0;
  if (param_2 == -0x7fdb96e0) {
loc_F0029CCC:
    _suser();
    if (iVar1 == 0) {
loc_F0029ECC:
      param_1 = (int)*(char *)(dword_F0133DDC + 0x38);
      goto locret_F0029F34;
    }
  }
  else {
    if (param_2 < -0x7fdb96df) {
      iVar1 = -0x7fdb96e2;
      if (param_2 == -0x7fdb96e2) goto loc_F0029CCC;
loc_F0029CF0:
      iVar1 = param_3;
      _ifunit();
      if (iVar1 == 0) {
        param_1 = 6;
        goto locret_F0029F34;
      }
      if (param_2 == -0x7fdf9683) {
        iVar2 = *(int *)(iVar1 + 0x38);
loc_F0029EDC:
        if (iVar2 != 0) {
          _if_ioctl(iVar1,param_2,param_3);
          param_1 = iVar1;
          goto locret_F0029F34;
        }
      }
      else {
        if (param_2 < -0x7fdf9682) {
          iVar2 = -0x7fdf96e8;
          if (param_2 != -0x7fdf96e8) {
            if (param_2 < -0x7fdf96e7) {
              iVar2 = -0x7fdf96f0;
              if (param_2 == -0x7fdf96f0) {
                _suser();
                if (iVar2 != 0) {
                  if (((*(word *)(iVar1 + 0xc) & 1) != 0) && ((*(word *)(param_3 + 0x10) & 1) == 0))
                  {
                    iVar2 = iVar1;
                    _spltty();
                    _if_down(iVar1);
                    _splx(iVar2);
                  }
                  *(word *)(iVar1 + 0xc) =
                       *(word *)(iVar1 + 0xc) & 0xc852 | *(word *)(param_3 + 0x10) & 0x37ad;
                  _if_ioctl(iVar1,0x80206910,param_3);
                  param_1 = 0;
                  goto locret_F0029F34;
                }
                goto loc_F0029ECC;
              }
              iVar2 = *(int *)(param_1 + 0xc);
            }
            else if (param_2 < -0x7fdf96cd) {
              iVar2 = -0x7fdf96cf;
              if (-0x7fdf96d0 < param_2) {
                _suser();
                if (iVar2 != 0) {
                  iVar2 = *(int *)(iVar1 + 0x38);
                  goto loc_F0029EDC;
                }
                goto loc_F0029ECC;
              }
              iVar2 = *(int *)(param_1 + 0xc);
            }
            else {
              iVar2 = *(int *)(param_1 + 0xc);
            }
            goto loc_F0029EFC;
          }
          _suser();
          if (iVar2 != 0) {
            *(undefined4 *)(iVar1 + 0x10) = *(undefined4 *)(param_3 + 0x10);
            goto loc_F0029F30;
          }
          goto loc_F0029ECC;
        }
        if (param_2 == -0x3fdf96e9) {
          *(undefined4 *)(param_3 + 0x10) = *(undefined4 *)(iVar1 + 0x10);
loc_F0029F30:
          param_1 = 0;
          goto locret_F0029F34;
        }
        if (param_2 < -0x3fdf96e8) {
          if (param_2 == -0x7fdf9681) {
loc_F0029ED8:
            iVar2 = *(int *)(iVar1 + 0x38);
            goto loc_F0029EDC;
          }
          if (param_2 == -0x3fdf96ef) {
            *(undefined2 *)(param_3 + 0x10) = *(undefined2 *)(iVar1 + 0xc);
            goto loc_F0029F30;
          }
          iVar2 = *(int *)(param_1 + 0xc);
        }
        else {
          if (param_2 == -0x3fdf9684) goto loc_F0029ED8;
          if (param_2 == -0x3fdf9682) {
            iVar2 = *(int *)(iVar1 + 0x38);
            goto loc_F0029EDC;
          }
          iVar2 = *(int *)(param_1 + 0xc);
        }
loc_F0029EFC:
        if (iVar2 != 0) {
          (**(code **)(iVar2 + 0x1c))(param_1,0xb,param_2,param_3,iVar1);
          goto locret_F0029F34;
        }
      }
      param_1 = 0x2d;
      goto locret_F0029F34;
    }
    if (param_2 == -0x3ff796ec) {
      param_1 = param_2;
      _ifconf(0xc0086914,param_3);
      goto locret_F0029F34;
    }
    if (param_2 != -0x3fdb96e1) goto loc_F0029CF0;
  }
  param_1 = param_2;
  _arpioctl(param_2,param_3);
locret_F0029F34:
  return CONCAT44(param_2,param_1);
}

