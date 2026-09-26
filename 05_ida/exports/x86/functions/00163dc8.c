/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x163dc8. */
int __cdecl update_priority(_DWORD *a1)
{
  int v1; // edx
  int v2; // ebx
  int v3; // edx
  int v4; // ebx
  int result; // eax
  int v6; // ebx
  int v7; // edx
  unsigned int v8; // [esp+Ch] [ebp-8h]
  int *v9; // [esp+Ch] [ebp-8h]
  int v10; // [esp+10h] [ebp-4h]

  v8 = sched_tick - a1[28]; /*0x163ddd*/
  a1[28] = sched_tick; /*0x163de6*/
  v1 = a1[60]; /*0x163de9*/
  if ( a1[67] == a1[62] ) /*0x163dfb*/
  {
    v2 = v1 - a1[66]; /*0x163e1a*/
    a1[66] = v1; /*0x163e20*/
  }
  else
  {
    v2 = timer_delta(a1 + 60, a1 + 66); /*0x163e10*/
  }
  v3 = a1[56]; /*0x163e26*/
  if ( a1[65] == a1[58] ) /*0x163e38*/
  {
    v4 = v3 - a1[64] + v2; /*0x163e5c*/
    a1[64] = v3; /*0x163e5e*/
  }
  else
  {
    v4 = timer_delta(a1 + 56, a1 + 64) + v2; /*0x163e4d*/
  }
  a1[68] += v4; /*0x163e64*/
  result = *(_DWORD *)(a1[96] + 376) * v4; /*0x163e77*/
  a1[69] += result; /*0x163e79*/
  if ( v8 <= 0x1E ) /*0x163e83*/
  {
    a1[26] += a1[68]; /*0x163e9e*/
    a1[27] += a1[69]; /*0x163ea7*/
    v6 = 2 * v8; /*0x163ead*/
    v9 = &wait_shift[2 * v8]; /*0x163eba*/
    v10 = v9[1]; /*0x163ec0*/
    if ( v10 <= 0 ) /*0x163ec5*/
    {
      a1[26] = (a1[26] >> wait_shift[v6]) - (a1[26] >> -(char)v10); /*0x163f1e*/
      result = a1[27] >> -*((_BYTE *)v9 + 4); /*0x163f3c*/
      v7 = (a1[27] >> wait_shift[v6]) - result; /*0x163f3e*/
    }
    else
    {
      a1[26] = (a1[26] >> v10) + (a1[26] >> wait_shift[v6]); /*0x163edf*/
      result = a1[27] >> v9[1]; /*0x163efb*/
      v7 = result + (a1[27] >> wait_shift[v6]); /*0x163efd*/
    }
    a1[27] = v7; /*0x163f40*/
  }
  else
  {
    a1[26] = 0; /*0x163e85*/
    a1[27] = 0; /*0x163e8c*/
  }
  a1[68] = 0; /*0x163f43*/
  a1[69] = 0; /*0x163f4d*/
  if ( a1[24] != 2 && (int)a1[25] < 0 ) /*0x163f61*/
  {
    result = a1[20] - (a1[27] >> 25); /*0x163f6e*/
    if ( result < 0 ) /*0x163f72*/
      result = 0; /*0x163f74*/
    a1[22] = result; /*0x163f76*/
  }
  return result; /*0x163f7c*/
}
