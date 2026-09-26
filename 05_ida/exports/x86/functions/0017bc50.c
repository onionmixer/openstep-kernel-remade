/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x17bc50. */
int __cdecl sub_17BC50(int a1, unsigned int a2, unsigned int a3)
{
  volatile __int32 *v3; // edx
  int i; // ebx
  unsigned int v5; // eax
  int v6; // eax
  unsigned int v7; // edx
  unsigned int v8; // eax
  int v10; // [esp+10h] [ebp-8h]
  int v11; // [esp+14h] [ebp-4h]

  v11 = 1; /*0x17bc5f*/
  v10 = 0; /*0x17bc66*/
  if ( !a1 ) /*0x17bc6f*/
    return 0; /*0x17bc6f*/
  v3 = (volatile __int32 *)(a1 + 16); /*0x17bc75*/
  do /*0x17bc8a*/
  {
    while ( *v3 ) /*0x17bc78*/
      ; /*0x17bc7a*/
  }
  while ( _InterlockedExchange(v3, 1) == 1 ); /*0x17bc8a*/
LABEL_5:
  for ( i = *(_DWORD *)a1; a1 != i; i = *(_DWORD *)(i + 8) ) /*0x17bc90*/
  {
    v5 = *(_DWORD *)(i + 24); /*0x17bc94*/
    if ( v5 >= a2 && a3 > v5 ) /*0x17bc9e*/
    {
      v6 = sub_17BACC(a1, i); /*0x17bca2*/
      if ( v6 == 1 ) /*0x17bcad*/
      {
        v11 = 0; /*0x17bcb8*/
      }
      else if ( v6 == 2 ) /*0x17bcaf*/
      {
        goto LABEL_5; /*0x17bcaf*/
      }
    }
  }
  v7 = a3 - a2; /*0x17bcc9*/
  v8 = *(_DWORD *)(a1 + 20); /*0x17bccb*/
  if ( v8 && v7 > v8 ) /*0x17bcd4*/
    v7 = *(_DWORD *)(a1 + 20); /*0x17bcd6*/
  if ( sub_17BC50(*(_DWORD *)(a1 + 32), *(_DWORD *)(a1 + 36) + a2, *(_DWORD *)(a1 + 36) + a2 + v7) ) /*0x17bce6*/
    v10 = 5; /*0x17bcf2*/
  _InterlockedExchange((volatile __int32 *)(a1 + 16), 0); /*0x17bcfb*/
  thread_wakeup_prim(a1, 0, 0); /*0x17bd03*/
  if ( v10 == 5 || !v11 ) /*0x17bd12*/
    return 5; /*0x17bd14*/
  else
    return 0; /*0x17bd1c*/
}
