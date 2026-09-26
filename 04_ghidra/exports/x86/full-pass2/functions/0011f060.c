/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0011f060 */

int _ifioctl(int param_1,int param_2,char *param_3)

{
  char cVar1;
  undefined4 *puVar2;
  sockaddr *psVar3;
  int iVar4;
  undefined4 uVar5;
  char *pcVar6;
  
  if (param_2 == -0x7fdb96e0) {
LAB_0011f0a8:
    iVar4 = _suser();
    if (iVar4 != 0) {
LAB_0011f0b5:
      iVar4 = _arpioctl(param_2,param_3);
      return iVar4;
    }
    goto LAB_0011f2b9;
  }
  if (param_2 < -0x7fdb96df) {
    if (param_2 == -0x7fdb96e2) goto LAB_0011f0a8;
  }
  else {
    if (param_2 == -0x3ff796ec) {
      iVar4 = _ifconf(0xc0086914,param_3);
      return iVar4;
    }
    if (param_2 == -0x3fdb96e1) goto LAB_0011f0b5;
  }
  for (pcVar6 = param_3; pcVar6 < param_3 + 0x10; pcVar6 = pcVar6 + 1) {
    if (*pcVar6 == '\0') {
      return 6;
    }
    if ((byte)(*pcVar6 - 0x30U) < 10) break;
  }
  cVar1 = *pcVar6;
  if ((cVar1 == '\0') || (pcVar6 == param_3 + 0x10)) {
    return 6;
  }
  for (puVar2 = _ifnet;
      (puVar2 != (undefined4 *)0x0 &&
      (((iVar4 = _bcmp((void *)*puVar2,param_3,(int)pcVar6 - (int)param_3), iVar4 != 0 ||
        (puVar2[5] != 0x1000)) || (cVar1 + -0x30 != (int)*(short *)(puVar2 + 2)))));
      puVar2 = (undefined4 *)puVar2[0x17]) {
  }
  if (puVar2 == (undefined4 *)0x0) {
    return 6;
  }
  if (param_2 == -0x7fdf9683) goto LAB_0011f29c;
  if (param_2 < -0x7fdf9682) {
    if (param_2 == -0x7fdf96e8) {
      iVar4 = _suser();
      if (iVar4 != 0) {
        puVar2[4] = *(undefined4 *)(param_3 + 0x10);
        return 0;
      }
LAB_0011f2b9:
      return (int)*(char *)(DAT_001e875c + 0x68);
    }
    if (param_2 < -0x7fdf96e7) {
      if (param_2 == -0x7fdf96f0) {
        iVar4 = _suser();
        if (iVar4 != 0) {
          if (((*(byte *)(puVar2 + 3) & 1) != 0) && ((param_3[0x10] & 1U) == 0)) {
            uVar5 = _splimp();
            *(byte *)(puVar2 + 3) = *(byte *)(puVar2 + 3) & 0xbe;
            for (psVar3 = (sockaddr *)puVar2[6]; psVar3 != (sockaddr *)0x0;
                psVar3 = *(sockaddr **)(psVar3[2].sa_data + 2)) {
              _pfctlinput(0,psVar3);
            }
            _if_qflush(puVar2 + 7);
            _splx(uVar5);
          }
          *(ushort *)(puVar2 + 3) =
               *(ushort *)(param_3 + 0x10) & 0x37ad | *(ushort *)(puVar2 + 3) & 0xc852;
          _if_ioctl(puVar2,0x80206910,param_3);
          return 0;
        }
        goto LAB_0011f2b9;
      }
    }
    else if ((param_2 < -0x7fdf96cd) && (-0x7fdf96d0 < param_2)) {
      iVar4 = _suser();
      if (iVar4 != 0) {
        if (puVar2[0xe] == 0) {
          return 0x2d;
        }
        iVar4 = _if_ioctl(puVar2,param_2,param_3);
        return iVar4;
      }
      goto LAB_0011f2b9;
    }
  }
  else {
    if (param_2 == -0x3fdf96e9) {
      *(undefined4 *)(param_3 + 0x10) = puVar2[4];
      return 0;
    }
    if (param_2 < -0x3fdf96e8) {
      if (param_2 == -0x7fdf9681) {
LAB_0011f29c:
        if (puVar2[0xe] == 0) {
          return 0x2d;
        }
        iVar4 = _if_ioctl(puVar2,param_2,param_3);
        return iVar4;
      }
      if (param_2 == -0x3fdf96ef) {
        *(undefined2 *)(param_3 + 0x10) = *(undefined2 *)(puVar2 + 3);
        return 0;
      }
    }
    else if ((param_2 == -0x3fdf9684) || (param_2 == -0x3fdf9682)) goto LAB_0011f29c;
  }
  if (*(int *)(param_1 + 0xc) == 0) {
    return 0x2d;
  }
  iVar4 = (**(code **)(*(int *)(param_1 + 0xc) + 0x1c))(param_1,0xb,param_2,param_3,puVar2);
  return iVar4;
}

