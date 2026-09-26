/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0011d558 */

off_t _lseek(int param_1,off_t param_2,int param_3)

{
  char cVar1;
  undefined4 *puVar2;
  int iVar3;
  undefined1 uVar4;
  int iVar5;
  int iVar6;
  undefined1 local_48 [24];
  int local_30;
  int local_8;
  
  puVar2 = *(undefined4 **)(DAT_001e875c + 0x24);
  uVar4 = _getvnodefp(*puVar2,&local_8);
  iVar5 = DAT_001e875c;
  *(undefined1 *)(DAT_001e875c + 0x68) = uVar4;
  iVar6 = DAT_001e875c;
  cVar1 = *(char *)(DAT_001e875c + 0x68);
  iVar5 = CONCAT31((int3)((uint)iVar5 >> 8),cVar1);
  if (cVar1 == '\0') {
    iVar3 = *(int *)(local_8 + 0x18);
    if (*(int *)(iVar3 + 0x28) != 8) {
      iVar5 = puVar2[2];
      if (iVar5 == 1) {
        if (((*(byte *)(*_active_u + 0x16) & 2) != 0) &&
           (iVar5 = *(int *)(local_8 + 0x1c) + puVar2[1], iVar5 < 0)) {
LAB_0011d657:
          iVar6 = DAT_001e875c;
          *(undefined1 *)(DAT_001e875c + 0x68) = 0x16;
          goto LAB_0011d684;
        }
        *(int *)(local_8 + 0x1c) = *(int *)(local_8 + 0x1c) + puVar2[1];
      }
      else if (iVar5 < 2) {
        if (iVar5 == 0) {
          iVar5 = *_active_u;
          if (((*(byte *)(iVar5 + 0x16) & 2) != 0) && ((int)puVar2[1] < 0)) goto LAB_0011d657;
          *(undefined4 *)(local_8 + 0x1c) = puVar2[1];
        }
        else {
LAB_0011d66c:
          *(undefined1 *)(DAT_001e875c + 0x68) = 0x16;
        }
      }
      else {
        if (iVar5 != 2) goto LAB_0011d66c;
        uVar4 = (**(code **)(*(int *)(iVar3 + 0x1c) + 0x14))(iVar3,local_48,_active_u[7]);
        iVar5 = DAT_001e875c;
        *(undefined1 *)(DAT_001e875c + 0x68) = uVar4;
        iVar6 = DAT_001e875c;
        if (*(char *)(DAT_001e875c + 0x68) != '\0') goto LAB_0011d684;
        if (((*(byte *)(*_active_u + 0x16) & 2) != 0) && (iVar5 = puVar2[1] + local_30, iVar5 < 0))
        goto LAB_0011d657;
        *(int *)(local_8 + 0x1c) = puVar2[1] + local_30;
      }
      iVar6 = DAT_001e875c;
      iVar5 = *(int *)(local_8 + 0x1c);
      *(int *)(DAT_001e875c + 0x60) = iVar5;
      goto LAB_0011d684;
    }
  }
  else if (cVar1 != '\x16') goto LAB_0011d684;
  *(undefined1 *)(DAT_001e875c + 0x68) = 0x1d;
LAB_0011d684:
  return CONCAT44(iVar6,iVar5);
}

