/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x17a4f0. */
void __cdecl sub_17A4F0(int a1, unsigned int a2, unsigned int a3, int a4)
{
  volatile __int32 *v4; // edx
  int i; // ebx
  unsigned int v6; // eax
  unsigned int v7; // edx
  unsigned int v8; // eax

  if ( a1 ) /*0x17a501*/
  {
    v4 = (volatile __int32 *)(a1 + 16); /*0x17a507*/
    do /*0x17a51e*/
    {
      while ( *v4 ) /*0x17a50c*/
        ; /*0x17a50e*/
    }
    while ( _InterlockedExchange(v4, 1) == 1 ); /*0x17a51e*/
    for ( i = *(_DWORD *)a1; a1 != i; i = *(_DWORD *)(i + 8) ) /*0x17a524*/
    {
      v6 = *(_DWORD *)(i + 24); /*0x17a528*/
      if ( v6 >= a2 && a3 > v6 ) /*0x17a532*/
        vm_policy_apply(a1, i, a4); /*0x17a53a*/
    }
    v7 = a3 - a2; /*0x17a54c*/
    v8 = *(_DWORD *)(a1 + 20); /*0x17a54e*/
    if ( v8 ) /*0x17a553*/
    {
      if ( v7 > v8 ) /*0x17a557*/
        v7 = *(_DWORD *)(a1 + 20); /*0x17a559*/
    }
    sub_17A4F0(*(_DWORD *)(a1 + 32), *(_DWORD *)(a1 + 36) + a2, *(_DWORD *)(a1 + 36) + a2 + v7, a4); /*0x17a570*/
    _InterlockedExchange((volatile __int32 *)(a1 + 16), 0); /*0x17a57a*/
    thread_wakeup_prim(a1, 0, 0); /*0x17a582*/
  }
}
