
int _stioctl(word param_1,int param_2,undefined4 *param_3)

{
  int iVar1;
  word wVar3;
  int iVar2;
  int iVar4;
  int *piVar5;
  undefined4 uVar6;
  undefined4 uStack_8;
  
  iVar4 = 0;
  wVar3 = (word)(((uint)param_1 << 0x18) >> 0x1b);
  iVar2 = (sword)wVar3 * 0x166;
  piVar5 = (int *)(_st_std + iVar2);
  if (1 < wVar3) {
    return 6;
  }
  if (param_2 != -0x3fad92f5) {
    if (param_2 < -0x3fad92f4) {
      if (param_2 == -0x7ff992ff) {
        iVar4 = sub_408935A((int)(sword)param_1,param_3);
        goto loc_4089344;
      }
      if (param_2 < -0x7ff992fe) {
        if (param_2 == -0x7ffb92fb) {
          uVar6 = *param_3;
loc_4089238:
          iVar4 = sub_4089510(piVar5,uVar6,0);
          goto loc_4089344;
        }
      }
      else {
        if (param_2 == -0x7fbf92f9) {
          iVar4 = sub_4088958(piVar5,param_3,0);
          goto loc_4089344;
        }
        if (param_2 == -0x3fbf92f8) {
          iVar4 = sub_40889C2(piVar5,param_3,0);
          goto loc_4089344;
        }
      }
    }
    else {
      if (param_2 == 0x20006d09) {
        *(word *)(_st_std + iVar2 + 0x66) = *(word *)(_st_std + iVar2 + 0x66) | 0x20;
        goto loc_4089344;
      }
      if (param_2 < 0x20006d0a) {
        if (param_2 == 0x20006d06) {
          uVar6 = 0;
          goto loc_4089238;
        }
      }
      else {
        if (param_2 == 0x20006d0a) {
          *(word *)(_st_std + iVar2 + 0x66) = *(word *)(_st_std + iVar2 + 0x66) & 0xffdf;
          goto loc_4089344;
        }
        if (param_2 == 0x40166d02) {
          if (((_st_std[iVar2 + 0x67] & 2) != 0) || (iVar4 = sub_40888F0(piVar5,0), iVar4 == 0)) {
            iVar1 = *(int *)(_st_std + iVar2 + 0x10);
            if ((param_1 & 2) == 0) {
              *(undefined2 *)param_3 = 9;
            }
            else {
              *(undefined2 *)param_3 = 10;
            }
            *(word *)((int)param_3 + 2) = (word)*(byte *)(iVar1 + 2);
            *(word *)(param_3 + 1) = (word)*(byte *)(iVar1 + 0xc);
            *(undefined2 *)((int)param_3 + 6) = *(undefined2 *)(iVar1 + 0x13);
            *(undefined2 *)(param_3 + 2) = *(undefined2 *)(iVar1 + 0x15);
            *(uint *)((int)param_3 + 10) =
                 *(uint *)(iVar1 + 4) >> 8 | (uint)*(byte *)(iVar1 + 3) << 0x18;
            *(word *)(_st_std + iVar2 + 0x66) = *(word *)(_st_std + iVar2 + 0x66) & 0xfffd;
          }
          goto loc_4089344;
        }
      }
    }
    iVar4 = 0x16;
    goto loc_4089344;
  }
  if (param_3[5] == 0) {
    uStack_8 = 0;
loc_40892D8:
    uVar6 = param_3[4];
    param_3[4] = uStack_8;
    *(uint *)((int)param_3 + 1) =
         *(uint *)((int)param_3 + 1) & 0x1fffffff | (uint)*(byte *)(*piVar5 + 0x1d) << 0x1d;
    iVar4 = sub_4089628(piVar5,param_3,0);
    param_3[4] = uVar6;
    if ((param_3[3] == 0) && (param_3[0xf] != 0)) {
      iVar4 = _copyoutmsg(uStack_8,uVar6,param_3[0xf]);
    }
  }
  else {
    iVar2 = _kmem_alloc_wired(_kernel_map,&uStack_8,param_3[5]);
    if (iVar2 != 0) {
      param_3[7] = 8;
      return 0xc;
    }
    if ((param_3[3] != 1) || (iVar4 = _copyinmsg(param_3[4],uStack_8,param_3[5]), iVar4 == 0))
    goto loc_40892D8;
    param_3[7] = 9;
  }
  if (param_3[5] != 0) {
    _kmem_free(_kernel_map,uStack_8,param_3[5]);
  }
loc_4089344:
  *(char *)(dword_40B57D4 + 100) = (char)iVar4;
  return iVar4;
}

