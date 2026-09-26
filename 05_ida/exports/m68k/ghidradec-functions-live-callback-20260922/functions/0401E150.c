
void _arpinput(int param_1,undefined4 param_2,undefined4 param_3,int param_4)

{
  sword sStack_c;
  sword sStack_a;
  
  if ((((-1 < *(char *)(param_1 + 0xd)) && (7 < *(word *)(param_4 + 8))) &&
      (_bcopy(*(int *)(param_4 + 4) + param_4,&sStack_c,8), sStack_c == 1)) &&
     ((((uint)(byte)word_40AE906 + (uint)word_40AE906._0_1_) * 2 + 8 <=
       (uint)(int)*(sword *)(param_4 + 8) && ((sStack_a == 0x800 || (sStack_a == 0x1000)))))) {
    _in_arpinput(param_1,param_2,param_3,param_4);
    return;
  }
  _m_freem(param_4);
  return;
}

