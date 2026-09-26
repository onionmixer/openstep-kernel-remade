/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x169cb0. */
int sub_169CB0()
{
  int *v0; // edx
  int *v1; // ebx
  void (__cdecl *v2)(int, int *); // edi
  int v3; // esi
  int *v4; // eax
  int *v5; // ebx
  thread_act_t target_act; // [esp+Ch] [ebp-4h]

  target_act = active_threads; /*0x169cbf*/
  splsched(); /*0x169cc2*/
  do /*0x169ce1*/
  {
    while ( dword_1E7244 ) /*0x169ccf*/
      ; /*0x169ccd*/
  }
  while ( _InterlockedExchange(&dword_1E7244, 1) == 1 ); /*0x169ce1*/
  for ( ; dword_1E7260 > 0; --dword_1E7264 ) /*0x169cea*/
  {
    v0 = (int *)dword_1E7250; /*0x169cf0*/
    if ( (int *)dword_1E7250 == &dword_1E7250 ) /*0x169cfc*/
    {
      v1 = nullptr; /*0x169cfe*/
    }
    else
    {
      *(_DWORD *)(*(_DWORD *)dword_1E7250 + 4) = &dword_1E7250; /*0x169d06*/
      dword_1E7250 = *v0; /*0x169d0f*/
      v1 = v0; /*0x169d15*/
    }
    --dword_1E7260; /*0x169d17*/
    v2 = (void (__cdecl *)(int, int *))v1[2]; /*0x169d1d*/
    v3 = v1[3]; /*0x169d20*/
    v1[7] = 0; /*0x169d23*/
    v4 = v1; /*0x169d2a*/
    if ( v1 >= &dword_1E6A44 && v1 < &dword_1E7244 ) /*0x169d3a*/
    {
      *v1 = (int)&dword_1E7248; /*0x169d3c*/
      v1[1] = dword_1E724C; /*0x169d48*/
      *(_DWORD *)v1[1] = v1; /*0x169d4e*/
      dword_1E724C = (int)v1; /*0x169d50*/
      v4 = nullptr; /*0x169d56*/
    }
    v5 = v4; /*0x169d58*/
    ++dword_1E7264; /*0x169d5a*/
    _InterlockedExchange(&dword_1E7244, 0); /*0x169d62*/
    spl0(); /*0x169d68*/
    v2(v3, v5); /*0x169d6f*/
    splsched(); /*0x169d71*/
    do /*0x169d95*/
    {
      while ( dword_1E7244 ) /*0x169d83*/
        ; /*0x169d81*/
    }
    while ( _InterlockedExchange(&dword_1E7244, 1) == 1 ); /*0x169d95*/
  }
  if ( dword_1E7268 - dword_1E7264 <= 4 ) /*0x169db8*/
  {
    assert_wait((int)&dword_1E7260, 0); /*0x169dc1*/
    _InterlockedExchange(&dword_1E7244, 0); /*0x169dcb*/
    thread_block_with_continuation((int)sub_169CB0); /*0x169dd6*/
  }
  --dword_1E7268; /*0x169dde*/
  _InterlockedExchange(&dword_1E7244, 0); /*0x169de6*/
  spl0(); /*0x169dec*/
  thread_terminate(target_act); /*0x169df5*/
  return thread_halt_self(); /*0x169e02*/
}
