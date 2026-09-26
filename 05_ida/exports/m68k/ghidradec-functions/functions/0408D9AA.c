
byte sub_408D9AA(undefined4 *param_1)

{
  char in_XF;
  char in_NF;
  char in_ZF;
  char in_VF;
  byte in_CF;
  
  *param_1 = dword_40B244A;
  dword_40B244A = param_1;
  dword_40B2452 = dword_40B2452 + 1;
  return in_XF << 4 | in_NF << 3 | in_ZF << 2 | in_VF << 1 | in_CF;
}
