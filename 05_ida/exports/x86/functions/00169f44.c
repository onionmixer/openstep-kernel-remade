/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x169f44. */
int sub_169F44()
{
  int *v0; // ebx
  unsigned __int64 v1; // rax
  unsigned __int64 v2; // kr08_8
  unsigned __int64 v3; // kr00_8
  int v4; // ecx
  _BOOL4 v5; // ebx
  unsigned __int64 v7; // [esp+10h] [ebp-1Ch]
  unsigned __int64 v8; // [esp+10h] [ebp-1Ch]
  int v9; // [esp+20h] [ebp-Ch]
  _DWORD *v10; // [esp+24h] [ebp-8h] BYREF
  int *v11; // [esp+28h] [ebp-4h]

  v7 = clock_value(1); /*0x169f54*/
  v11 = (int *)&v10; /*0x169f5d*/
  v10 = &v10; /*0x169f60*/
  v9 = splsched(); /*0x169f68*/
  do /*0x169f8a*/
  {
    while ( dword_1E7244 ) /*0x169f78*/
      ; /*0x169f76*/
  }
  while ( _InterlockedExchange(&dword_1E7244, 1) == 1 ); /*0x169f8a*/
  v0 = (int *)dword_1E7258; /*0x169f8c*/
  if ( (int *)dword_1E7258 != &dword_1E7258 ) /*0x169f98*/
  {
    do /*0x169fe7*/
    {
      if ( *(_QWORD *)(v0 + 5) > v7 ) /*0x169fb0*/
        break; /*0x169fb0*/
      *(_DWORD *)(*v0 + 4) = v0[1]; /*0x169fb7*/
      *(_DWORD *)v0[1] = *v0; /*0x169fbf*/
      v0[7] = 0; /*0x169fc1*/
      *v0 = (int)&v10; /*0x169fcb*/
      v0[1] = (int)v11; /*0x169fd0*/
      *(_DWORD *)v0[1] = v0; /*0x169fd6*/
      v11 = v0; /*0x169fd8*/
      v0 = (int *)dword_1E7258; /*0x169fdb*/
    }
    while ( (int *)dword_1E7258 != &dword_1E7258 ); /*0x169fe7*/
    if ( v0 != &dword_1E7258 ) /*0x169fef*/
    {
      v1 = clock_value(1); /*0x169ff3*/
      if ( *(_QWORD *)(v0 + 5) >= v1 ) /*0x16a00b*/
      {
        v3 = v1; /*0x16a021*/
        v8 = *(_QWORD *)timer_attributes(0); /*0x16a02b*/
        v2 = *(_QWORD *)(v0 + 5) - v3; /*0x16a044*/
        if ( v8 < v2 ) /*0x16a055*/
          v2 = v8; /*0x16a05a*/
      }
      else
      {
        v2 = 0; /*0x16a017*/
      }
      set_timer(0, v2, HIDWORD(v2)); /*0x16a061*/
    }
  }
  while ( 1 ) /*0x16a070*/
  {
    v4 = (int)v10; /*0x16a070*/
    if ( &v10 == v10 ) /*0x16a076*/
      break; /*0x16a076*/
    *(_DWORD *)(*v10 + 4) = &v10; /*0x16a081*/
    v10 = *(_DWORD **)v4; /*0x16a086*/
    if ( !v4 ) /*0x16a08d*/
      break; /*0x16a08d*/
    *(_DWORD *)v4 = &dword_1E7250; /*0x16a093*/
    *(_DWORD *)(v4 + 4) = dword_1E7254; /*0x16a09f*/
    **(_DWORD **)(v4 + 4) = v4; /*0x16a0a5*/
    dword_1E7254 = v4; /*0x16a0a7*/
    ++dword_1E7260; /*0x16a0ad*/
    *(_DWORD *)(v4 + 28) = 1; /*0x16a0b3*/
    v5 = dword_1E7268 < dword_1E7260 + dword_1E7264; /*0x16a0d0*/
    _InterlockedExchange(&dword_1E7244, 0); /*0x16a0d3*/
    thread_wakeup_prim((int)&dword_1E7260, 1, 0); /*0x16a0e2*/
    if ( v5 ) /*0x16a0ec*/
      thread_wakeup_prim((int)&dword_1E7268, 1, 0); /*0x16a0f7*/
    do /*0x16a11a*/
    {
      while ( dword_1E7244 ) /*0x16a108*/
        ; /*0x16a106*/
    }
    while ( _InterlockedExchange(&dword_1E7244, 1) == 1 ); /*0x16a11a*/
  }
  _InterlockedExchange(&dword_1E7244, 0); /*0x16a126*/
  return splx(v9); /*0x16a138*/
}
