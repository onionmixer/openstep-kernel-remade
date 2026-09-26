/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0011f704 */

undefined4 FUN_0011f704(undefined4 param_1,int param_2,undefined4 param_3)

{
  ushort uVar1;
  ushort uVar2;
  int iVar3;
  char cVar6;
  uint uVar4;
  undefined4 uVar5;
  size_t sVar7;
  ushort uVar8;
  short sVar9;
  short sVar10;
  size_t sVar11;
  void *pvVar12;
  undefined1 local_20c [512];
  ushort local_c;
  ushort local_a;
  ushort local_6;
  
  iVar3 = _if_private(param_1);
  if (*(int *)(iVar3 + 0xc) != param_2) {
    return 0x2f;
  }
  _nb_read(param_3,0xc,2,&local_6);
  uVar2 = local_6 >> 8;
  uVar8 = uVar2 | local_6 << 8;
  cVar6 = (char)local_6;
  uVar1 = local_6 >> 8;
  local_6 = uVar8;
  if (CONCAT11(cVar6 + -0x10,(char)uVar1) < 0x10) {
    sVar9 = uVar2 << 9;
    if (sVar9 == 0) {
      return 0x2f;
    }
    uVar4 = _nb_size(param_3);
    if (uVar4 <= (int)sVar9 + 0x12U) {
      return 0x2f;
    }
    _nb_read(param_3,sVar9 + 0xe,4,&local_c);
    local_6 = local_c >> 8 | local_c << 8;
    if ((local_6 != 0x800) && (local_6 != 0x806)) {
      return 0x2f;
    }
    uVar2 = local_a >> 8 | local_a << 8;
    sVar7 = (size_t)sVar9;
    uVar4 = _nb_size(param_3);
    if (uVar4 < sVar7 + 0xe + (int)(short)uVar2) {
      return 0x2f;
    }
    sVar10 = uVar2 - 4;
    iVar3 = _nb_map(param_3);
    if (sVar9 < 0x201) {
      _nb_read(param_3,0xe,sVar7,local_20c);
      _bcopy((void *)(sVar7 + 0x12 + iVar3),(void *)(iVar3 + 0xe),(int)sVar10);
      pvVar12 = (void *)(iVar3 + 0xe + (int)sVar10);
    }
    else {
      sVar11 = (size_t)sVar10;
      _nb_read(param_3,sVar7 + 0x12,sVar11,local_20c);
      pvVar12 = (void *)(iVar3 + 0xe);
      _bcopy(pvVar12,(void *)(iVar3 + 0xe + sVar11),sVar7);
      sVar7 = sVar11;
    }
    _bcopy(local_20c,pvVar12,sVar7);
    _nb_shrink_bot(param_3,4);
  }
  if (local_6 == 0x800) {
    _nb_shrink_top(param_3,0xe);
    iVar3 = _if_ipackets(param_1);
    _if_ipackets_set(param_1,iVar3 + 1);
    _inet_queue(param_1,param_3);
  }
  else {
    if (local_6 != 0x806) {
      return 0x2f;
    }
    iVar3 = _if_ipackets(param_1);
    _if_ipackets_set(param_1,iVar3 + 1);
    uVar4 = _if_flags(param_1);
    if ((uVar4 & 0x4000) == 0) {
      _nb_shrink_top(param_3,0xe);
      iVar3 = _if_private(param_1,param_3);
      uVar5 = _if_private(param_1,*(undefined4 *)(iVar3 + 8));
      _arpinput(param_1,uVar5);
    }
    else {
      _nb_free(param_3);
    }
  }
  return 0;
}

