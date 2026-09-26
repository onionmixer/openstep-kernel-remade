
void _en_arp_input(int param_1)

{
  if (((*(sword *)(param_1 + 0x14) == 1) && (*(int *)(param_1 + 0xe) == 0x10800)) &&
     (*(int *)(param_1 + 0x26) == dword_40C8F3E)) {
    _bcopy(param_1 + 0x16,param_1 + 0x20,6);
    _bcopy((int *)(param_1 + 0x1c),param_1 + 0x26,4);
    _bcopy(&unk_40C8F38,param_1 + 0x16,6);
    *(int *)(param_1 + 0x1c) = dword_40C8F3E;
    *(undefined2 *)(param_1 + 0x14) = 2;
    _bcopy(param_1 + 0x20,param_1,6);
    _bcopy(&unk_40C8F38,param_1 + 6,6);
    _en_xmit(param_1,0x2a);
  }
  return;
}
