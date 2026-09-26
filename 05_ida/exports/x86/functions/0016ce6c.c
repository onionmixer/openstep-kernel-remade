/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x16ce6c. */
void __cdecl kern_serv_log(int *a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8)
{
  int v8; // ebx
  int v9; // edx
  _DWORD *v10; // esi
  int v11; // eax

  v8 = *a1; /*0x16ce78*/
  if ( *(_DWORD *)(*a1 + 48) >= a2 && *(_DWORD *)(v8 + 36) ) /*0x16ce83*/
  {
    v9 = splhigh(); /*0x16ce92*/
    do /*0x16cea6*/
    {
      while ( *(_DWORD *)v8 ) /*0x16ce94*/
        ; /*0x16ce96*/
    }
    while ( _InterlockedExchange((volatile __int32 *)v8, 1) == 1 ); /*0x16cea6*/
    v10 = *(_DWORD **)(v8 + 40); /*0x16cea8*/
    *(_DWORD *)(v8 + 40) = v10 + 8; /*0x16ceab*/
    v11 = *(_DWORD *)(v8 + 40); /*0x16ceaf*/
    if ( *(_DWORD *)(v8 + 44) == v11 ) /*0x16ceb5*/
    {
      *(_DWORD *)(v8 + 40) = v11 - 32; /*0x16ceba*/
      _InterlockedExchange((volatile __int32 *)v8, 0); /*0x16cebf*/
      splx(v9); /*0x16cec2*/
    }
    else
    {
      _InterlockedExchange((volatile __int32 *)v8, 0); /*0x16cece*/
      splx(v9); /*0x16ced1*/
      *v10 = a3; /*0x16ced9*/
      v10[1] = a4; /*0x16cede*/
      v10[2] = a5; /*0x16cee4*/
      v10[3] = a6; /*0x16ceea*/
      v10[4] = a7; /*0x16cef0*/
      v10[5] = a8; /*0x16cef6*/
      v10[6] = event_get(); /*0x16cefe*/
      v10[7] = a2; /*0x16cf01*/
      if ( *(_DWORD *)(v8 + 24) ) /*0x16cf07*/
        kern_serv_callout(a1, (void (__cdecl *)(int))sub_16CF28, (void (__cdecl *)(int))v8); /*0x16cf17*/
    }
  }
}
