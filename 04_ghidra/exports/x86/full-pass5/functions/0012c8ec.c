/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0012c8ec */

void _exportfs(void)

{
  ushort uVar1;
  undefined4 *puVar2;
  undefined1 uVar3;
  int iVar4;
  uint *puVar5;
  int *piVar6;
  uint *local_c;
  int local_8;
  
  puVar2 = *(undefined4 **)(DAT_001e875c + 0x24);
  iVar4 = _suser();
  if (iVar4 == 0) {
    *(undefined1 *)(DAT_001e875c + 0x68) = 1;
    return;
  }
  uVar3 = _lookupname(*puVar2,0,1,0,&local_8);
  *(undefined1 *)(DAT_001e875c + 0x68) = uVar3;
  if (*(char *)(DAT_001e875c + 0x68) != '\0') {
    return;
  }
  uVar3 = (**(code **)(*(int *)(local_8 + 0x1c) + 100))(local_8,&local_c);
  *(undefined1 *)(DAT_001e875c + 0x68) = uVar3;
  iVar4 = *(int *)(local_8 + 0x24);
  _vn_rele(local_8);
  if (*(char *)(DAT_001e875c + 0x68) != '\0') {
    return;
  }
  if (puVar2[1] == 0) {
    uVar3 = _unexport(iVar4 + 0x14,local_c);
    *(undefined1 *)(DAT_001e875c + 0x68) = uVar3;
    iVar4 = (ushort)*local_c + 2;
    puVar5 = local_c;
    goto LAB_0012cb07;
  }
  puVar5 = (uint *)_kalloc(0x30);
  puVar5[8] = *(uint *)(iVar4 + 0x14);
  puVar5[9] = *(uint *)(iVar4 + 0x18);
  puVar5[10] = (uint)local_c;
  uVar3 = _copyin(puVar2[1],puVar5,0x20);
  *(undefined1 *)(DAT_001e875c + 0x68) = uVar3;
  if (*(char *)(DAT_001e875c + 0x68) == '\0') {
    if ((*puVar5 & 0xfffffffc) == 0) {
      if ((*puVar5 & 2) != 0) {
        uVar3 = _loadaddrs(puVar5 + 6);
        *(undefined1 *)(DAT_001e875c + 0x68) = uVar3;
        if (*(char *)(DAT_001e875c + 0x68) != '\0') goto LAB_0012caf4;
      }
      if (puVar5[2] == 1) {
        uVar3 = _loadaddrs(puVar5 + 3);
        *(undefined1 *)(DAT_001e875c + 0x68) = uVar3;
      }
      else {
        *(undefined1 *)(DAT_001e875c + 0x68) = 0x16;
      }
      if (*(char *)(DAT_001e875c + 0x68) == '\0') {
        piVar6 = &_exported;
        iVar4 = _exported;
        do {
          if (iVar4 == 0) {
            puVar5[0xb] = 0;
            *piVar6 = (int)puVar5;
            return;
          }
          iVar4 = _bcmp((void *)(*piVar6 + 0x20),puVar5 + 8,8);
          if (iVar4 == 0) {
            uVar1 = **(ushort **)(*piVar6 + 0x28);
            if ((*(ushort *)puVar5[10] != uVar1) ||
               (iVar4 = _bcmp(*(ushort **)(*piVar6 + 0x28) + 1,(ushort *)puVar5[10] + 1,(uint)uVar1)
               , iVar4 != 0)) goto LAB_0012cadc;
            iVar4 = *piVar6;
            *piVar6 = *(int *)(iVar4 + 0x2c);
            _exportfree(iVar4);
          }
          else {
LAB_0012cadc:
            piVar6 = (int *)(*piVar6 + 0x2c);
          }
          iVar4 = *piVar6;
        } while( true );
      }
    }
    else {
      *(undefined1 *)(DAT_001e875c + 0x68) = 0x16;
    }
  }
LAB_0012caf4:
  _kfree((ushort *)puVar5[10],*(ushort *)puVar5[10] + 2);
  iVar4 = 0x30;
LAB_0012cb07:
  _kfree(puVar5,iVar4);
  return;
}

