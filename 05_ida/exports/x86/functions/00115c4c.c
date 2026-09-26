/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x115c4c. */
int __cdecl sorflush(int a1)
{
  _BYTE *v1; // edx
  int v2; // ebx
  void *v3; // edx
  __int16 v4; // ax
  void (__cdecl *v5)(_DWORD); // eax
  _BYTE *v7; // [esp+Ch] [ebp-20h]
  void *v8; // [esp+Ch] [ebp-20h]
  int v9; // [esp+10h] [ebp-1Ch]
  _DWORD v10[6]; // [esp+14h] [ebp-18h] BYREF

  v1 = (_BYTE *)(a1 + 36); /*0x115c58*/
  v9 = *(_DWORD *)(a1 + 12); /*0x115c5e*/
  if ( (*(_BYTE *)(a1 + 56) & 1) != 0 ) /*0x115c65*/
  {
    do /*0x115c85*/
    {
      v1[20] |= 2u; /*0x115c6c*/
      v7 = v1; /*0x115c73*/
      sleep(a1 + 56); /*0x115c76*/
      v1 = v7; /*0x115c7e*/
    }
    while ( (v7[20] & 1) != 0 ); /*0x115c85*/
  }
  v1[20] |= 1u; /*0x115c87*/
  v8 = v1; /*0x115c8b*/
  v2 = splimp(); /*0x115c93*/
  socantrcvmore(a1); /*0x115c96*/
  v3 = v8; /*0x115c9e*/
  v4 = *((_WORD *)v8 + 10); /*0x115ca1*/
  *((_WORD *)v8 + 10) = v4 & 0xFFFE; /*0x115cac*/
  if ( (v4 & 2) != 0 ) /*0x115cb2*/
  {
    LOBYTE(v4) = v4 & 0xFC; /*0x115cb4*/
    *((_WORD *)v8 + 10) = v4; /*0x115cb6*/
    wakeup((int)v8 + 20); /*0x115cc1*/
    v3 = v8; /*0x115cc9*/
  }
  qmemcpy(v10, v3, sizeof(v10)); /*0x115cd9*/
  bzero(v3, 0x18u); /*0x115cde*/
  splx(v2); /*0x115ce4*/
  if ( (*(_BYTE *)(v9 + 10) & 0x10) != 0 ) /*0x115cf3*/
  {
    v5 = *(void (__cdecl **)(_DWORD))(*(_DWORD *)(v9 + 4) + 16); /*0x115cf8*/
    if ( v5 ) /*0x115cfd*/
      v5(v10[3]); /*0x115d03*/
  }
  return sbrelease(v10); /*0x115d14*/
}
